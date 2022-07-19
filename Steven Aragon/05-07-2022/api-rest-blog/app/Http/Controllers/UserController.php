<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Http\Response;
use App\Models\User;
use App\Helpers\JwtAuth;

class UserController extends Controller
{
    //
    public function __construct()
    {
        $this->middleware('api.auth',['except'=>['show','login','store','getImage']]);
    }
    public function __invoke()
    {

    }
    public function index(){
        $data=User::all();
        $response=array(
            'status'=>'success',
            'code'=>200,
            'data'=>$data
        );
        return response()->json($response,200);
    }
    public function show($id){
        $user=User::find($id);
        if(is_object($user)){
            $response=array(
                'status'=>'success',
                'code'=>200,
                'data'=>$user
            );
        }else{
            $response=array(
                'status'=>'error',
                'code'=>404,
                'message'=>'Usuario no encontrado'
            );
        }
        return response()->json($response,$response['code']);
    }
    public function store(Request $request){

        $json=$request->input('json',null);
        $data=json_decode($json,true);
        $data=array_map('trim',$data);
        $rules=[
            'name'=>'required|alpha',
            'last_name'=>'required',
            'email'=>'required|email|unique:users',
            'password'=>'required',
            'role'=>'required'
        ];
        $valid=\validator($data,$rules);
        if($valid->fails()){
            $response=array(
                'status'=>'error',
                'code'=>406,
                'message'=>'Datos enviados no cumplen con las reglas establecidas',
                'errors'=>$valid->errors()
            );
        }else{
            $user=new User();
            $user->name=$data['name'];
            $user->last_name=$data['last_name'];
            $user->email=$data['email'];
            $user->role=$data['role'];
            $user->password=hash('sha256',$data['password']);
            $user->save();
            $response=array(
                'status'=>'success',
                'code'=>200,
                'message'=>'Datos almacenados satisfactoriamente'
            );
        }
        return response()->json($response,$response['code']);
    }
    public function update(Request $request){
        $json=$request->input('json',null);
        $data=json_decode($json,true);
        //Error a solucionar
        $data=array_map('trim',$data);
        $rules=[
            'name'=>'required|alpha',
            'last_name'=>'required',
            'email'=>'required|email',
            'password'=>'required',
            'role'=>'required'
        ];
        $valid=\validator($data,$rules);
        if($valid->fails()){
            $response=array(
                'status'=>'error',
                'code'=>406,
                'message'=>'Datos enviados no cumplen con las reglas establecidas',
                'errors'=>$valid->errors()
            );
        }else{
            $email=$data['email'];
            unset($data['email']);
            unset($data['id']);
            unset($data['created_at']);
            unset($data['remember_token']);
            $updated=User::where('email',$email)->update($data);
            if($updated>0){
                $response=array(
                    'status'=>'success',
                    'code'=>200,
                    'message'=>'Datos actualizados satisfactoriamente'
                );
            }else{
                $response=array(
                    'status'=>'error',
                    'code'=>400,
                    'message'=>'No se pudo actualizar el usuario, puede ser que no exista'
                );
            }
        }
        return response()->json($response,$response['code']);

    }
    public function destroy($id){
        if(isset($id)){
            $deleted=User::where('id',$id)->delete();
            if($deleted){
                $response=array(
                    'status'=>'success',
                    'code'=>200,
                    'message'=>'Usuario eliminado correctamente'
                );
            }else{
                $response=array(
                    'status'=>'error',
                    'code'=>400,
                    'message'=>'No se pudo eliminar el recurso'
                );
            }
        }else{
            $response=array(
                'status'=>'error',
                'code'=>400,
                'message'=>'Falta el identificador del recurso a eliminar'
            );
        }
        return response()->json($response,$response['code']);
    }
    public function uploadImage(Request $request){
        $image=$request->file('file0');
        $valid=\Validator::make($request->all(),[
            'file0'=>'required|image|mimes:jpg,png'
        ]);
        if(!$image||$valid->fails()){
            $response=array(
                'status'=>'error',
                'code'=>406,
                'message'=>'Error al subir el archivo',
                'errors'=>$valid->errors()
            );
        }else{
            $filename=time().$image->getClientOriginalName();
            \Storage::disk('users')->put($filename,\File::get($image));
            $response=array(
                'status'=>'success',
                'code'=>200,
                'message'=>'Imagen guardada correctamente',
                'image_name'=>$filename
            );
        }
        return response()->json($response,$response['code']);
    }
    public function getImage($filename){
        $exist=\Storage::disk('users')->exists($filename);
        if($exist){
            $file=\Storage::disk('users')->get($filename);
            return new Response($file,200);
        }else{
            $response=array(
                'status'=>'error',
                'code'=>404,
                'message'=>'Imagen no existe'
            );
            return response()->json($response,404);
        }
    }
    /** Funciona a traves de metodo POST retornando un token */
    public function login(Request $request){
        $jwtAuth=new JwtAuth();
        $json=$request->input('json',null);
        $data=json_decode($json,true);
        $data=array_map('trim',$data);
        $rules=['email'=>'required|email','password'=>'required'];
        $valid=\validator($data,$rules);
        if($valid->fails()){
            $response=array(
                'status'=>'error',
                'code'=>406,
                'message'=>'Los datos enviados son incorrectos',
                'errors'=>$valid->errors()
            );
            return response()->json($response,406);
        }else{
            $response=$jwtAuth->getToken($data['email'],$data['password']);
            return response()->json($response);
        }
    }
    /** Funciona a traves de metodo POST retorna un json de datos del usuario autenticado */
    public function getIdentity(Request $request){
        $jwtAuth=new JwtAuth();
        $token=$request->header('token');
        if(isset($token)){
            $response=$jwtAuth->checkToken($token,true);
        }else{
            $response=array(
                'status'=>'error',
                'code'=>406,
                'message'=>'token no encontrado'
            );
        }
        return response()->json($response);
    }
}
