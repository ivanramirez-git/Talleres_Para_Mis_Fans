<?php

namespace App\Http\Controllers;

use App\Models\Category;
use Illuminate\Http\Request;

class CategoryController extends Controller
{
    public function __construct()
    {
        // Inyectar meddleware
        $this->middleware('api.auth',['except'=>['index','show']]);
    }
    //index -->devuelve todos los elementos  GET
   public function index(){
        $data=Category::all();
        $response=array(
            'status'=>'success',
            'code'=>200,
            'data'=>$data
        );
        return response()->json($response,200);
    }
    //show--> devuelve un elemento por su id GET
    public function show($id){
        $data=Category::find($id);
        if(is_object($data)){
            $data=$data->load('posts');
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
    //store --> agrega o guarda un elemnto  POST
    /**
     * Endpoint Metodo POST para categoria, recibe un json denominado 'json', retorna una respuesta http
     */
    public function store(Request $request){
        $json =$request->input('json',null);
        $data=json_decode($json,true);
        if(!empty($data)){
            $data=array_map('trim',$data);
            $rules=[
                'name'=>'required|alpha'
            ];
            $validate=\validator($data,$rules);
            if($validate->fails()){
                $response=array(
                    'status'=>'error',
                    'code'=>406,
                    'message'=>'Los datos enviados son incorrectos',
                    'errors'=>$validate->errors()
                );
            }else{
                $category=new Category();
                $category->name=$data['name'];
                $category->save();
                $response=array(
                    'status'=>'success',
                    'code'=>201,
                    'message'=>'Datos almacenados satisfactoriamente'
                );
            }
        }
        else{
            $response=array(
                'status'=>'error',
                'code'=>400,
                'message'=>'Faltan parametros'
            );
        }
        return response()->json($response,$response['code']);
    }
    //update --> modifica un elemento    PUT
    public function update(Request $request){
        $json=$request->input('json',null);
        $data=json_decode($json,true);
        if(!empty($data)){
            $data=array_map('trim',$data);
            $rules=[
                'id'=>'required',
                'name'=>'required|alpha'
            ];
            $validate=\validator($data,$rules);
            if($validate->fails()){
                $response=array(
                    'status'=>'error',
                    'code'=>406,
                    'message'=>'Los datos enviados son incorrectos',
                    'errors'=>$validate->errors()
                );
            }else{
                $id=$data['id'];
                unset($data['id']);        //[name,updated_at]
                unset($data['created_at']);
                $updated=Category::where('id',$id)->update($data);
                if($updated>0){
                    $response=array(
                        'status'=>'success',
                        'code'=>200,
                        'message'=>'Datos actualizados exitosamente'
                    );
                }else{
                    $response=array(
                        'status'=>'error',
                        'code'=>400,
                        'message'=>'No se pudo actualizar los datos'
                    );
                }
            }
        }else{
            $response=array(
                'status'=>'error',
                'code'=>400,
                'message'=>'Faltan parametros'
            );
        }
        return response()->json($response,$response['code']);
    }
    //destroy --> Elimina un elemento   DELETE
    public function destroy($id){
        if(isset($id)){
            $deleted=Category::where('id',$id)->delete();
            if($deleted){
                $response=array(
                    'status'=>'success',
                    'code'=>200,
                    'message'=>'Eliminado correctamente'
                );
            }else{
                $response=array(
                    'status'=>'error',
                    'code'=>400,
                    'message'=>'Problemas al eleminar el recurso, puede ser que el recurso no exista'
                );
            }
        }else{
            $response=array(
                'status'=>'error',
                'code'=>400,
                'message'=>'Falta el identificador del recurso'
            );
        }
        return response()->json($response,$response['code']);
    }
}
