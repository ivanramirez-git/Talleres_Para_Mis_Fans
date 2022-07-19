import { Component, OnInit } from '@angular/core';
import { Router,ActivatedRoute } from '@angular/router';

import { global } from 'src/app/services/configuration';
import { Post } from 'src/app/models/post';
import { PostService } from 'src/app/services/post.service';

@Component({
  selector: 'app-post-detail',
  templateUrl: './post-detail.component.html',
  styleUrls: ['./post-detail.component.css'],
  providers:[PostService]
})
export class PostDetailComponent implements OnInit {
  public post:any;
  public url:string;
  constructor(
    private _postService:PostService,
    private _router:Router,
    private _route:ActivatedRoute
  ) {
    this.post=new Post(1,1,1,"","","",null);
    this.url=global.url;
   }

  ngOnInit(): void {
    this.getPost();
  }
  getPost():void{
    this._route.params.subscribe(
      (params)=>{
        let id=params['id'];
        this._postService.getPost(id).subscribe({
          next:(response:any)=>{
            if(response.status=="success"){
              this.post=response.data;
              console.log(this.post);
            }else{
              this._router.navigate(['']);
            }
          },
          error:(error:Error)=>{
              console.log(error.message);
              this._router.navigate(['']);
          }
        });
      }
    );
  }

}
