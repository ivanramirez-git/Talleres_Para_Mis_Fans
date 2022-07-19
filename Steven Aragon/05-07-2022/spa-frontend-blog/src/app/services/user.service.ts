import{Observable} from 'rxjs';
import{Injectable} from '@angular/core';
import{HttpClient,HttpHeaders} from '@angular/common/http';
import{User} from '../models/user';
import { global } from './configuration';

@Injectable() export class UserService{
  public url:string;
  public token:any;
  public identity:any;
  constructor(public _http:HttpClient){
    this.url=global.url;
    this.token=null;
  }
  register(user:User):Observable<any>{
    let data=JSON.stringify(user);
    let params='json='+data;
    let httpHeaders=new HttpHeaders().set('Content-Type','application/x-www-form-urlencoded');
    let options={
      headers:httpHeaders
    };
    return this._http.post(this.url+'user',params,options);
  }
  login(user:User):Observable<any>{
    let data=JSON.stringify(user);
    let params='json='+data;
    let httpHeaders=new HttpHeaders().set('Content-Type','application/x-www-form-urlencoded');
    let options={
      headers:httpHeaders
    };
    return this._http.post(this.url+'user/login',params,options);
  }
  getToken(){
    let tk=localStorage.getItem('token');
    if(tk&& tk!='undefined'){
      this.token=tk.trim();
    }else{
      this.token=null;
    }
    return this.token;
  }

  getIdentity(){
    let ident=localStorage.getItem('identity');
    if(ident && ident!='undefined'){
        this.identity= JSON.parse(ident);
    }else{
        this.identity=null;
    }
    return this.identity;
  }

  loadIdentity():Observable<any>{
    let httpHeaders=new HttpHeaders().append('Content-Type','application/x-www-form-urlencoded').append('token',this.token);
    return this._http.get(this.url+'user/getidentity',{headers:httpHeaders});
  }
}
