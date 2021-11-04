#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
float fun (float x);
int main() {
 float a,b,n,dx,suma,i,xi,c;
 
 printf ("Digite el punto inferior ");
 scanf ("%f",&a);
 printf ("Digite el punto superior ");
 scanf ("%f",&b);
 printf ("Digite el numero de sub-areas ");
 scanf ("%f",&n);
 dx=(b-a)/n;
 suma=0;
 i=1;
 while (i<=n-1)
 {
 xi=a+i*dx;
 suma=suma+fun(xi);
 i=i+1;
 }
 c=(b-a)*((fun(a)+2*suma+fun(b))/(2*n));
 printf ("El area es:%f \n",c);
 return 0;
}
float fun(float x)
{float f;
f=x*x-4;
return f;
}
