import {Injectable} from '@angular/core';
import { HttpClient,HttpHeaders } from '@angular/common/http';
import { Observable } from 'rxjs';

import { global } from './configuration';
import { Post } from '../models/post';


@Injectable() export class PostService{
  public url:string;

  constructor(private _http:HttpClient){
    this.url=global.url;
  }
  getPosts():Observable<any>{
    let httpHeaders=new HttpHeaders().set('Content-Type','application/x-www-form-urlencoded');
    return this._http.get(this.url+'post',{headers:httpHeaders});
  }
  getPost(id:number):Observable<any>{
    return this._http.get(this.url+"post/"+id);
  }
  create(post:Post,token:any):Observable<any>{
    let httpHeaders=new HttpHeaders().set('Content-Type','application/x-www-form-urlencoded').set('token',token);
    let json=JSON.stringify(post);
    let data='json='+json;
    return this._http.post(this.url+'post',data,{headers:httpHeaders});
  }
}
