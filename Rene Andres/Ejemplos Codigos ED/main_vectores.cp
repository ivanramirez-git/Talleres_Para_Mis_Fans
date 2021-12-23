
//  main.cpp
//  semestre_2021B
//  Ramiro Torres on 13/12/2021.

#include <iostream> //cout cin endl
#include<fstream> //entrada-salida de archivos
#include <cstdlib> //números aleatorios
#include <vector> //vectores stl


using namespace std;

void aleatorio_void(vector<double> &x,int n, int k)
{
    x.resize(n);
    for(int i=0;i<x.size();i++)
        x[i]=-k+rand()%(2*k+1);

}

vector<double> aleatorio(int n, int k)
{
    vector<double> x(n);
    for(int i=0;i<x.size();i++)
        x[i]=-k+rand()%(2*k+1);
    return x;
}


ostream& operator<<(ostream& os, vector<double> x)//sobrecarga del operador <<
{
        for(int i=0;i<x.size();i++)
            os<<x[i]<<" , ";
        return os;
}

istream& operator>>(istream& is, vector<double> &x)
{
    int n;
    is>>n;
    x.resize(n);
    for(int i=0;i<x.size();i++)
        is>>x[i];
    return is;
}

int main()
{
    cout<<"ARREGLOS VECTORES"<<endl;

    vector<double> x,y;
    int n;
    cout<<"Ingrese n>0:";
    cin>>n;
    x=aleatorio(n,100);

    ifstream fo;
    fo.open("datos.txt");
    if(fo.is_open()==true)
        fo>>y;
    else
        cout<<"ERROR DE LECTURA"<<endl;
    fo.close();

    //cout<<"x="<<x<<endl;
    ofstream fa;
    fa.open("vector.txt");
    fa<<"x="<<x<<endl;
    fa.close();

    cout<<"último="<<x.back()<<endl;
    cout<<"y="<<y<<endl;
    x.clear();
    y.clear();
    return 0;
}


