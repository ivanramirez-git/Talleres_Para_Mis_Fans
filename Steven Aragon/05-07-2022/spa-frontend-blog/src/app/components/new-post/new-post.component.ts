import { Component, OnInit } from '@angular/core';

import { Post } from 'src/app/models/post';
import { UserService } from 'src/app/services/user.service';
import { CategoryService } from 'src/app/services/category.service';
import { PostService } from 'src/app/services/post.service';
import { global } from 'src/app/services/configuration';

@Component({
  selector: 'app-new-post',
  templateUrl: './new-post.component.html',
  styleUrls: ['./new-post.component.css'],
  providers:[UserService, CategoryService,PostService]
})
export class NewPostComponent implements OnInit {
  public status:number;
  public post:Post;
  public identity;
  public categories:any;
  private token;
  public resetVar=false;

  public options:Object={
    toolbarButtonsXS:['bold','italic','underline','paragraphFormat']
  }

  public afuConfig={
    multiple:false,
    formatsAllowed:".jpg,.png",
    method:"POST",
    maxSize:5,
    uploadAPI:{
      url: global.url+'post/upload',
      headers:{
        "token": `${localStorage.getItem('token')}`
      }
    },
    theme:"attachPin",
    replaceTexts:{
      attachPinBtn:'Subir imagen'
    }
  };

  constructor(
    private _userService:UserService,
    private _categoryService:CategoryService,
    private _postService:PostService
    ) {
    this.status=-1;
    this.identity=_userService.getIdentity();
    this.post=new Post(1,this.identity.sub,1,"","","",null);
    this.token=_userService.getToken();

  }

  ngOnInit(): void {
    this.getCategories();
    console.log(this.categories);
  }
  onSubmit(form:any){
    //console.log(this.post);
    this._postService.create(this.post,this.token).subscribe({
      next:(response:any)=>{
        if(response.status="success"){
          this.status=0;
          form.reset();
          this.resetVar=true;
        }else{
          this.status=1;
        }
      },
      error:(error:Error)=>{
        this.status=1;
      }
    });
  }
  getCategories():void{
    this._categoryService.getCategories().subscribe({
      next:(response:any)=>{
        if(response.status=='success'){
          this.categories=response.data;
        }
      },
      error:(error:Error)=>{
        this.categories=null;
      }
    });
  }
  imageUpload(response:any){
    let data=response.body;
    this.post.image=data.image;
  }

}
