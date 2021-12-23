
//  main.cpp
//  semestre_2021B
//  Ramiro Torres on 09/12/2021.

#include <iostream>
#include <vector>//vectores STL

using namespace std;

void leer_vector(double *x, int n);
void escribir_vector( const double* x, int n);

int main()
{
    cout<<"PUNTEROS Y ARREGLOS"<<endl;
    double x,z; 
    x=10.23; 
    int y=20;

    //punteros
    double * px=NULL;
    px=&x;//px apunta a x
    *px=100;
    z=(*px+12)/5;
    cout<<"x="<<x<<endl;
    cout<<"px="<<*px<<endl;

    px=new double;
    cout<<"Ingrese un real:";
    cin>>*px;
    x=x+(*px);
    cout<<"x="<<x<<endl;
    delete px;

int n=4;
    double vx[n];
    vx[0]=1.1;
    vx[4]=4.1;

    px=new double[n];
    leer_vector(px,n);
    cout<<endl<<"px="<<*px<<endl;
    px++;
    cout<<endl<<"px="<<*px<<endl;
    cout<<"El vector es"<<endl;
    escribir_vector(px,n-1);
    px--;
    delete[] px;

    vector<int> stl_x,stl_y(n);
    stl_x.resize(n,-2);

    stl_x[0]=12;
    stl_x[1]=10;

cout<<"vector stl=";
    for(int i=0;i<stl_x.size();i++)
        cout<<stl_x[i]<<" , ";

stl_x.resize(2*n,-5);
cout<<"vector stl=";
    for(int i=0;i<stl_x.size();i++)
        cout<<stl_x[i]<<" , ";
        
    return 0;
}


void leer_vector(double *x, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"x["<<i<<"]=";
        cin>>x[i];
    }
}

void escribir_vector( const double* x, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"x["<<i<<"]="<<x[i]<<endl;
    }

}