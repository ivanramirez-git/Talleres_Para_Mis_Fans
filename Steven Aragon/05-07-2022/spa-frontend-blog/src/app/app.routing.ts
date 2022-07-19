import {ModuleWithProviders} from '@angular/core';
import{Routes,RouterModule,Route} from '@angular/router';

import{HomeComponent} from './components/home/home.component';
import{UserRegisterComponent} from './components/user-register/user-register.component';
import{LoginComponent} from './components/login/login.component';
import { NewPostComponent } from './components/new-post/new-post.component';
import { PostDetailComponent } from './components/post-detail/post-detail.component';
import{ErrorComponent} from './components/error/error.component';

const appRoutes:Routes=[
  {path:'',component:HomeComponent},
  {path:'registro',component:UserRegisterComponent},
  {path:'login',component:LoginComponent},
  {path:'logout/:sure',component:LoginComponent},
  {path:'categoria/:id',component:HomeComponent},
  {path:'crear-post',component:NewPostComponent},
  {path:'post-detalle/:id',component:PostDetailComponent},
  {path:'**',component:ErrorComponent}
];

export const appRoutingProviders:any[]=[];
export const routing:ModuleWithProviders<Route>=RouterModule.forRoot(appRoutes);
