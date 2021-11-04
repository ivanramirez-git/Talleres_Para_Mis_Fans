#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>
#include<iomanip>
void uno(float a);
void dos(float a,float b);
void tres(float a, float b, float c);
void cuatro(float a,float b, float c, float d);
void cinco(float a, float b, float c, float d, float e);
float bs(float f1,float f0,float x1, float x0);
float x[6],fx[6];
void main()
{
int opcion;
clrscr();
cout<<"\n INTERPOLACION DE NEWTON";
cout<<"\nCUANTOS PUNTOS";
cin>>opcion;
if(opcion<=5)
{
for(int d=0;d<opcion;d++)
{
cout<<"\nX"<<d<<":";cin>>x[d];
cout<<"\nf(x)"<<d<<":";cin>>fx[d];
}
switch(opcion)
{
case 1:{uno(fx[0]);}break;
case 2:{dos(x[0],x[1]);}break;
case 3:{tres(x[0],x[1],x[2]);}break;
case 4:{cuatro(x[0],x[1],x[2],x[3]);}break;
case 5:{cinco(x[0],x[1],x[2],x[3],x[4]);}break;
}
getch();
}
}
void uno(float a)
{
cout<<"\n";
cout<<"Y="<<a;
getch();
}
void dos(float a, float b)
{
cout<<"\n"<<setiosflags(ios::showpos);
cout<<setiosflags(ios::fixed);
cout<<"Y=";
cout<<bs(a,b,fx[0],fx[1])<<"X"<<bs(a,b,fx[0],fx[1])*(-a)+fx[0];
getch();
}
void tres(float a, float b, float c)
{
float t1,t2,t3;
t1=bs(a,b,fx[0],fx[1]);
t2=bs(b,c,fx[1],fx[2]);
t3=bs(a,c,t1,t2);
cout<<"\n"<<setiosflags(ios::showpos);
cout<<setiosflags(ios::fixed);

cout<<"Y="<<t3<<"X^2" <<((-a-b)*t3)+t1<<"X"<<-(t1*a)+(fx[0])+(t3*a*b);
getch();

}
void cuatro(float a, float b, float c, float d)
{
float t1,t2,t3,t4,t5,t6;
t1=bs(a,b,fx[0],fx[1]);
t2=bs(b,c,fx[1],fx[2]);
t3=bs(c,d,fx[2],fx[3]);
t4=bs(a,c,t1,t2);
t5=bs(b,d,t2,t3);
t6=bs(a,d,t4,t5);
cout<<setiosflags(ios::showpos);
cout<<setiosflags(ios::fixed);
cout<<"\nY="<<t6<<"X^3"<<(((-a-b-c)*t6)+t4)<<"X^2"<<((t6*((a*b)+(a*c)+(b*c)))+(t4*(-a-b))+t1)<<"X"<<((t6*(-a*b*c))+((a*b)*t4)-(t1*a)+fx[0]);
getch();
}
void cinco(float a, float b, float c, float d, float e)
{
//long
float t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
t1=bs(a,b,fx[0],fx[1]);
t2=bs(b,c,fx[1],fx[2]);
t3=bs(c,d,fx[2],fx[3]);
t4=bs(d,e,fx[3],fx[4]);
t5=bs(a,c,t1,t2);
t6=bs(b,d,t2,t3);
t7=bs(c,e,t3,t4);
t8=bs(a,d,t5,t6);
t9=bs(b,e,t6,t7);
t10=bs(a,e,t8,t9);

cout<<setiosflags(ios::showpos);
cout<<setiosflags(ios::fixed);
cout<<"\n"<<fx[0]<<t1<<"(x”<<-a<<“)”<<t5<<“(x”<<-a<<“)”<<“(x”<<-b<<“)”<<t8<<“(x”<<-a<<“)”<<“(x”<<-b<<“)”<<“(x”<<-c<<“)”<<t10<<“(x”<<-a<<“)”<<“(x”<<-b<<“)”<<“(x”<<-c<<“)”<<“(x”<<-d<<“)";

getch();
}

float bs(float x0,float x1,float f0, float f1)
{
return( (f1-f0)/(x1-x0));
}
