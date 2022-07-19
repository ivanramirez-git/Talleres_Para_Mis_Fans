import { Component, OnInit } from '@angular/core';
import {ActivatedRoute,Router} from '@angular/router';

import {PostService} from '../../services/post.service';
import { UserService } from 'src/app/services/user.service';
import { CategoryService } from 'src/app/services/category.service';
import { global } from 'src/app/services/configuration';
import { Post } from 'src/app/models/post';


@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css'],
  providers:[PostService,UserService,CategoryService]
})
export class HomeComponent implements OnInit {
  public url:string;
  public identity:any;
  public posts:Array<Post>;
  private checkAutorization;
  private checkPosts;
  constructor(
    private _postService:PostService,
    private _userService:UserService,
    private _categoryService:CategoryService,
    private _route:ActivatedRoute,
    private _router:Router
  ) {
    this.url=global.url;
    this.posts=[];
    this.checkAutorization=setInterval(()=>{
      this.identity=this._userService.getIdentity();
    },1000);
    this.checkPosts=setInterval(()=>{
      this.loadComponents();
    },10000);
   }

  ngOnInit(): void {
    this.loadComponents();
  }

  loadComponents(){
    let idCat;
    this._route.params.subscribe(
      params=>{
        idCat=params['id'];
      }
    );
    if(idCat){
      this.getPostsByCategory(idCat);
    }else{
      this.getPosts();
    }
  }
  getPosts(){
    this._postService.getPosts().subscribe({
      next: (response)=>{
        if(response.status=="success"){
          this.posts=response.data;
          console.log(this.posts);
        }
      },
      error:(error:Error)=>{

      }
    });
  }
  getPostsByCategory(id:number){
    this._categoryService.getCategory(id).subscribe(
      {
        next: (response:any)=>{
          if(response.status=="success"){
            //console.log(response);
            this.posts=response.data.posts;
          }else{
            this._router.navigate(['']);
          }
        },
        error:(error:Error)=>{

        }
      }
    );
  }
  delete(id:number){
    console.log("Eliminando el post "+id);
  }

}
