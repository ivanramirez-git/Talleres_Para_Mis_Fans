#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

class GaussJ
{
	private:
		int n;	
	public:
		void lectura(int n, float **m);	
		void paso(int n, float **m);
};


void GaussJ::lectura(int n, float **m)
{
	for(int i=0;i<n;i++)
	{
	    cout<<"\n";
	    for(int j=0;j<=n;j++)
		{
	    	cout<<"\t"<<m[i][j];			
	    }
	}			
}

void GaussJ::paso(int n, float **m)
{
	int in=1;
	double uno=0,cero=0;
		  	
	for(int z=0;z<n;z++)
	{ 
		uno=m[z][z];
		for(int i=0;i<n;i++)
		{
			cero=-m[i][z];
	    	for(int j=0;j<=n;j++)
			{
	    		if(in==1)
				{
	    		    m[z][j]/=uno;
					i=-1; 
	    		}
				else if(i!=z)
				{
					m[i][j]+=(m[z][j]*cero);
				}	
	        }
	        in=0;	
		}
		in=1;	
	}
	
	cout<<"\n\nMatriz aplicando Gauss Jordan";
	lectura(n,m);
	
	cout<<endl<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"    x"<<i+1<<"= "<<m[i][n]<<endl;
	}
}


int main()
{
	int n;
	cout<<"\n\tIngrese el nuemro de filas de su matriz: "; cin>>n;
	float** m = new float*[n];
    for( int i = 0; i < n; i++ )
        m[i] = new float[n+1];
        
	for(int i=0;i<n;i++)
	{
	    cout<<"\n";
	    for(int j=0;j<=n;j++)
		{
	    	cout<<"\n\t\tIngrese el nuemro de las coordenadas ( "<<i+1<<" , "<<j+1<<" ) :  "; cin>>m[i][j];			
	    }
	}
	GaussJ A;
	cout<<"\nMatriz:";
	A.lectura(n,m);
	A.paso(n,m);
}
