<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Http\Response;
use App\Models\Post;
use App\Helpers\JwtAuth;

class PostController extends Controller
{
    //
    public function __construct(){
        $this->middleware('api.auth',['except'=>['index','show','getImage']]);
    }
    public function __invoke()
    {

    }
    public function index(){
        $data=Post::all()->load("user","category");
        $response=array(
            'status'=>'success',
            'code'=>200,
            'data'=>$data
        );
        return response()->json($response,200);

    }
    public function show($id){
        $data=Post::find($id);
        if(is_object($data)){
            $data=$data->load('category','user');
            $response=array(
                'status'=>'success',
                'code'=>200,
                'data'=>$data
            );
        }else{
            $response=array(
                'status'=>'error',
                'code'=>404,
                'message'=>'Recurso no encontrado'
            );
        }
        return response()->json($response,$response['code']);

    }
    public function store(Request $request){
        $json = $request->input('json',null);
        $data= json_decode($json,true);// el true es para pasar ese json a array
        if(!empty($data)){
            $data=array_map('trim',$data);
            $rules=[
                'title'=>'required',
                'content'=>'required',
                'category_id'=>'required',
                'image'=>'required'
            ];
            //validamos
            $validate = \validator($data, $rules);
            if($validate->fails()){
                $response=array(
                    'status'    =>'error',
                    'code'      =>406,
                    'message'   =>'Los datos enviados son incorrectos',
                    'errors'    => $validate->errors()
                );
            }else{
                /**Verificamos el usuario autenticado a traves
                 * del token para registrar la relación con el nuevo
                 * post creado
                 */
                $jwtAuth=new JwtAuth();
                $token=$request->header('token',null);
                $user=$jwtAuth->checkToken($token,true);

                $post=new Post();
                $post->user_id=$user->sub; //Aquí obtenemos el id del usuario
                $post->category_id=$data['category_id'];
                $post->title=$data['title'];
                $post->content=$data['content'];
                $post->image=$data['image'];
                $post->save();

                $response=array(
                    'status'    =>'success',
                    'code'      =>200,
                    'message'   =>'Datos almacenados satisfactoriamente'
                );
            }
        }else{
            $response=array(
                'status'    =>'error',
                'code'      =>400,
                'message'   =>'Faltan parametros'
            );
        }
        return response()->json($response,$response['code']);
    }
    public function update(Request $request){
        $json = $request->input('json',null);
        $data= json_decode($json,true);// el true es para pasar ese json a array
        if(!empty($data)){
            $data=array_map('trim',$data);
            $rules=[
                'id'=>'required',
                'title'=>'required',
                'content'=>'required',
                'image'=>'required',
                'category_id'=>'required'
            ];
            //validamos
            $validate = \validator($data, $rules);
            if($validate->fails()){
                $response=array(
                    'status'    =>'error',
                    'code'      =>406,
                    'message'   =>'Los datos enviados son incorrectos',
                    'errors'    => $validate->errors()
                );
            }
            else{
                $id=$data['id'];
                unset($data['id']);
                unset($data['user_id']);
                unset($data['created_at']);
                $updated=Post::where('id',$id)->update($data);
                if($updated>0){
                    $response=array(
                        'status'    =>'success',
                        'code'      =>200,
                        'message'   =>'Actualizado correctamente'
                    );
                }else{
                    $response=array(
                        'status'    =>'error',
                        'code'      =>400,
                        'message'   =>'No se pudo actualizar'
                    );
                }
            }
        }else{
            $response=array(
                'status'    =>'error',
                'code'      =>400,
                'message'   =>'Faltan parametros'
            );
        }

        return response()->json($response,$response['code']);
    }
    public function destroy($id){
        if(isset($id)){
            $deleted=Post::where('id',$id)->delete();
            if($deleted){
                $response=array(
                    'status'    =>'success',
                    'code'      =>200,
                    'message'   =>'Eliminado correctamente'
                );
            }else{
                $response=array(
                    'status'    =>'error',
                    'code'      =>400,
                    'message'   =>'No se pudo eliminar, puede que el registro ya no exista'
                );
            }
        }else{
            $response=array(
                'status'    =>'error',
                'code'      =>400,
                'message'   =>'Faltan parametros'
            );
        }
        return response()->json($response,$response['code']);
    }
    public function upload(Request $request){
        $image=$request->file('file0');
        $validate=\Validator::make($request->all(),[
            'file0'=>'required|image|mimes:jpg,jpeg,png'
        ]);
        if(!$image || $validate->fails()){
            $response=array(
                'status'    =>'error',
                'code'      =>406,
                'message'   =>'Error al subir la imagen'
            );
        }
        else{
            $image_name=time().$image->getClientOriginalName();
            \Storage::disk('posts')->put($image_name,\File::get($image));
            $response=array(
                'status'    =>'success',
                'code'      =>200,
                'image' =>$image_name,
                'message'   =>'Imagen cargada satisfactoriamente'
            );
        }
        return response()->json($response,$response['code']);
    }
    public function getImage($filename){
        $exist=\Storage::disk('posts')->exists($filename);
        if($exist){
            $file=\Storage::disk('posts')->get($filename);
            return new Response($file,200);
        }else{
            $response=array(
                'status'=>'error',
                'code'=>404,
                'message'=>'Imagen no existe'
            );
            return response()->json($response,$response['code']);
        }
    }

}
