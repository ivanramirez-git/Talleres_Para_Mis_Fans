import { Component } from '@angular/core';
import { Category } from './models/category';
import { ActivatedRoute, Router,Event,NavigationEnd } from '@angular/router';
import{CategoryService} from './services/category.service';
import{UserService} from './services/user.service';
import{global} from './services/configuration';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
  providers:[
    CategoryService,
    UserService
  ]
})
export class AppComponent {
  public categories:any;
  private checkCategories;
  private checkAutorization;
  public identity:any;
  public url:string;

  constructor(
    public _categoryService:CategoryService,
    public _userService:UserService,
    private _routes:ActivatedRoute,
    private _router:Router
  ){

    this.url=global.url+'user/getimage/';
    this.loadCategories();
    this.loadAutorization();
    this.checkCategories= setInterval(() => {
      this.loadCategories();
    }, 10000);
    this.checkAutorization=setInterval(()=>{
      this.loadAutorization();
    },1000);
    this._router.events.subscribe(
      (event:Event)=>{
        if(event instanceof NavigationEnd){
         // console.log(event.url);
          if(!this.identity){
            let routerUrl=event.url;
            if(routerUrl!="login"){
              this._router.navigate(['/login']);
            }
          }
        }
      }
    );
  }
  public loadAutorization(){
    this.identity=this._userService.getIdentity();
  }

  public loadCategories(){
    this._categoryService.getCategories().subscribe({
      next: (response:any) => {
        console.log(response);
        if(response.status=="success"){
          this.categories=response.data;
          console.log(this.categories);
        }else{
          this.categories=null;
        console.log(response);
        }
      },
      error: (err: Error) => {
        this.categories=null;
        console.error('Error de la petición: ' + err);
      }
    }
    );
  }
}
