import { Component, OnInit } from '@angular/core';
import{User} from '../../models/user';
import{UserService} from '../../services/user.service';
import { Router,ActivatedRoute, Route } from '@angular/router';
import { timer } from 'rxjs';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css'],
  providers:[UserService]
})
export class LoginComponent implements OnInit {
  public user:User;
  public status:number;
  public token:any;
  public identity:any;
  constructor(
    private _userService:UserService,
    private _router:Router,
    private _routes:ActivatedRoute
  ) {
    this.user=new User(1,"","","user_role","","","","");
    this.status=-1;
   }

  ngOnInit(): void {
    this.logout();
  }
  logout(){
    this._routes.params.subscribe(
      params=>{
        let logout=+params['sure'];
        if(logout==1){
          localStorage.removeItem('identity');
          localStorage.removeItem('token');
          this.identity=null;
          this.token=null;
          this._router.navigate(['']);
        }
      }
    );
  }

  onSubmit(form:any){
    this._userService.login(this.user).subscribe(
      {
        next: (response:any) => {
          console.log(response);
          if(response.status!="error"){
            this.token=response;
            localStorage.setItem("token",this.token);
            this._userService.getToken();
            this._userService.loadIdentity().subscribe({
              next:(response:any)=>{
                this.identity=JSON.stringify(response);
                localStorage.setItem('identity',this.identity);
              },
              error:(error:Error)=>{
                console.error(error);
              }
            });
            form.reset();
            this._router.navigate(['']);

          }else{
            this.status=0;
            let counter=timer(5000);
            counter.subscribe(n=>{this.status=-1});

          }
        },
        error: (err: Error) => {
          console.error('Error de la petición: ' + err);
          this.status=0;
          let counter=timer(5000);
          counter.subscribe(n=>{this.status=-1});
        }
      }
    );
  }

}
