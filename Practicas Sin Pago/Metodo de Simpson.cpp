#include <cstdlib>
#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

class Simpson
{
   private:
   		float h,A13,A38;
            int i;
   public:
   		void lectura(int n,float **m);
   		float SA13(float **m,int n,int a,int b);
        float SA38(float **m,int n,int a);
        float sum_par(float **m,int n,int a);
        float sum_impar(float **m,int n,int a);
        float sum_multiplo(float **m,int n,int a);
        float sum_resto(float **m,int n,int a);
        void Calculos(int n,float **m);
};

void Simpson::lectura(int n, float **m)
{
	cout<<"\n\n\tx	y";
	for(int i=0;i<n;i++)
	{
	    cout<<"\n";
	    for(int j=0;j<=1;j++)
		{
	    	cout<<"\t"<<m[i][j];			
	    }
	}				
}

float Simpson::sum_par(float **m,int n,int a)
{
    float sumap=0;
    for(i=a;i<n-1;i++)
    {
		if((i%2)==0) 
		{
        	sumap+=m[i][1];
       	}
    }
    return(sumap);
}  

float Simpson::sum_impar(float **m,int n,int a)
{
    float sumaip=0;
    for(i=a;i<n-1;i++)
    {
      	if((i%2)!=0)
       	{
        	sumaip+=m[i][1];
       	} 	
    }
    return(sumaip);
}

float Simpson::sum_multiplo(float **m,int n,int a)
{
    float sumulti=0;
    for(i=a;i<n-1;i++)
    {
       if((i%3)==0)
       {
          sumulti+=m[i][1];
       }
    }
    return(sumulti);
}

float Simpson::sum_resto(float **m,int n,int a)
{
    float sumresto=0;
    for(i=a;i<n-1;i++)
    {
       if((i%3)!=0)
       {
          sumresto+=m[i][1];
       }
    }
    return(sumresto);
}

float Simpson::SA13(float **m,int n,int a,int b)
{ 
   h=((m[n-1][0])-(m[0][0]))/(n-1);
   if(a==(n-2))
   {
      A13=(h/3)*(m[b][1]+m[n-1][1]+(4*sum_par(m,n,a))+(2*sum_impar(m,n,a)));
   }
   else if(a!=(n-2))
   {         
      A13=(h/3)*(m[b][1]+m[n-1][1]+(2*sum_par(m,n,a))+(4*sum_impar(m,n,a)));
   }
   return(A13);
}

float Simpson::SA38(float **m,int n,int a)
{
   h=((m[n-1][0])-(m[0][0]))/(n-1);
   A38=((3*h)/8)*(m[0][1]+m[n-1][1]+(2*sum_multiplo(m,n,a))+(3*sum_resto(m,n,a)));
   return(A38);
}

void Simpson::Calculos(int n,float **m)
{
	float resultado;
	int a,b,c;
	if(((n-1)%2)==0)
    {
       a=1; b=0;            
       resultado=SA13(m,n,a,b);
       cout<<"\n\nUsando Simpson 1/3"<<endl;
       cout<<"A = "<<resultado<<" u^2"<<endl;
    }
    else if(((n-1)%3)==0)
    { 
       a=1;  
       resultado=SA38(m,n,a);
       cout<<"\n\nUsando Simpson 3/8"<<endl;
       cout<<"A = "<<resultado<<" u^2"<<endl;
    }
    else if((((n-1)%2)!=0)&&(((n-1)%3)!=0))
    {
       a=1; b=n-2; c=n-3;  
       resultado=(SA13(m,n,b,c))+(SA38(m,b,a));
       cout<<"\n\nA1/3= "<<SA13(m,n,b,c)<<endl;
       cout<<"A3/8= "<<SA38(m,b,a)<<endl;
       cout<<"\nLa Equivlencia es de: "<<endl;
       cout<<"A = "<<resultado<<" u^2"<<endl;
    }  
}    

int main()
{
    int n;
	cout<<"Ingrese el numero de x de la funcion: "; cin>>n;
	float**m=new float*[n];
    for( int i=0;i<n;i++)
        m[i] = new float[1];
	
	for(int i=0;i<n;i++)
	{
	    cout<<"\n\tIngrese el valor de X"<<i+1<<":  "; cin>>m[i][0];
		cout<<"\n\tIngrese el valor de Y"<<i+1<<":  "; cin>>m[i][1];
		cout<<endl;
	}
	
    Simpson A;
    A.lectura(n,m);
    A.Calculos(n,m);        
}
