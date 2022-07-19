<?php

namespace App\Http\Middleware;

use Closure;
use Illuminate\Http\Request;
use App\Helpers\JwtAuth;

class ApiAuthMiddleware
{
    /**
     * Handle an incoming request.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  \Closure(\Illuminate\Http\Request): (\Illuminate\Http\Response|\Illuminate\Http\RedirectResponse)  $next
     * @return \Illuminate\Http\Response|\Illuminate\Http\RedirectResponse
     */
    public function handle(Request $request, Closure $next)
    {
        $jwtAuth = new JwtAuth();
        $token=$request->header('token');
        $logged=$jwtAuth->checkToken($token);
        if($logged){
            return $next($request);
        }else{
            $response=array(
                'status'=>'error',
                'code'=>401,
                'message'=>'No tiene privilegios para acceder a este recurso'
            );
            return response()->json($response,401);
        }
    }
}
