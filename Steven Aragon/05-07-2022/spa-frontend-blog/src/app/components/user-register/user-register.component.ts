import { Component, OnInit } from '@angular/core';
import {User} from '../../models/user';
import{UserService} from '../../services/user.service';
import { timer } from 'rxjs';

@Component({
  selector: 'app-user-register',
  templateUrl: './user-register.component.html',
  styleUrls: ['./user-register.component.css'],
  providers:[UserService]
})
export class UserRegisterComponent implements OnInit {
  public status:number;
  public user:User;
  constructor(private _userService:UserService) {
    this.status=-1;
    this.user=new User(1,"","","user_role","","","","");
  }

  ngOnInit(): void {
  }

  onSubmit(form:any){
    console.log(this.user);
    this._userService.register(this.user).subscribe({
      next: (response:any)=>{
        console.log(response);
        if(response.code==200){
          this.status=0;
          let counter=timer(5000);
          counter.subscribe(n=>{
            console.log(n);
            this.status=-1;
         });
          form.reset();
         }else{
          this.status=1;
         }
      },
      error:(er:Error)=>{
        console.log(er);
      }
    });
  }
}
