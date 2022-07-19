import { HttpClient, HttpHeaders } from '@angular/common/http';
import {Injectable} from '@angular/core';
import {global} from './configuration';
import {Observable} from 'rxjs';
import {Category} from '../models/category';

@Injectable() export class CategoryService{
  public url:string;
  constructor(public _http:HttpClient){
    this.url=global.url;
  }
  getCategories():Observable<any>{
    let headers=new HttpHeaders().set('Content-Type','application/x-www-form-urlencoded');
    return this._http.get(this.url+'category',{headers:headers});
  }
  getCategory(id:number):Observable<any>{
    return this._http.get(this.url+'category/'+id);
  }
}
