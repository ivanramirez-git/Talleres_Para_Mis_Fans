<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\CategoryController;
use App\Http\Controllers\PostController;
use App\Http\Controllers\UserController;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/


Route::prefix('api')->group(function () {
    //RUTAS ESPECIFICAS
    Route::post('/user/upload',[UserController::class,'uploadImage']);
    Route::get('/user/getimage/{filename}',[UserController::class,'getImage']);
    Route::post('/user/login',[UserController::class,'login']);
    Route::get('/user/getidentity',[UserController::class,'getIdentity']);
    Route::get('/post/image/{filename}',[PostController::class,'getImage']);
    Route::post('/post/upload',[PostController::class,'upload']);
    //RUTAS AUTOMATICAS RESTful
    Route::resource('/category', CategoryController::class,['except'=>['create','edit']]);
    Route::resource('/user', UserController::class,['except'=>['create','edit']]);
    Route::resource('/post',PostController::class,['except'=>['create','edit']]);
});



