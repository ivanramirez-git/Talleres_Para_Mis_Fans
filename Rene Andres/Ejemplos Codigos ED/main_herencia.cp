
//  main.cpp
//  semestre_2021B
//  Ramiro Torres on 15/12/2021.

#include <iostream> //cout cin endl
#include <cmath> //matemáticas
#include<fstream> //entrada-salida de archivos
#include <cstdlib> //números aleatorios
#include <vector> //vectores stl

using namespace std;

class tripleta //(x,y,z)
{
protected:
    double x;
    double y;
public:
    double z;
    //CONSTRUCTORES Y DESTRUCTORES
    tripleta();
    tripleta(double _x,double _y);
    ~tripleta()
    {}
//FUNCIONES MIEMBRO
    double Obt_x();
    double norma();
    void Modificar_y(double _y);
//FUNCIONES AMIGAS
friend double norma_amiga(tripleta t);
//SOBRECARGA DE OPERADORES
friend ostream& operator<<(ostream& os, tripleta t);
friend istream& operator>>(istream& is,tripleta& t);
friend tripleta operator+(tripleta t1, tripleta t2);
friend tripleta operator*(tripleta t1, tripleta t2);
friend tripleta operator*(double a, tripleta t2);
friend bool operator==(tripleta t1,tripleta t2);
};//fin tripleta


class cuarteto:public tripleta
{
protected:
    int id;
    string Nombre;
public:
    cuarteto()
    {
        x=y=0;
        z=0;
        id=0;
        Nombre="SN";
    }
    cuarteto(string s, int _id, double a)
    {
        Nombre=s;
        id=_id;
        x=y=z=a;
    }

    double norma2()
    {
        double t=sqrt(x+y+z+id);
        return t;
    }
};

class arreglo: protected vector<double>
{
protected:
    string Nombre;
    int id;
public:
    arreglo(){Nombre="S/N";};
    arreglo(string s,int n, int inicial);
    ~arreglo();
    int Obt_dim()
    {
        return size();
    }
    double ultimo()
    {
        return back();
    }
    double max();
    double min();

    //sobrecargas
    friend ostream& operator<<(ostream& os, arreglo v);
    friend istream& operator>>(istream& is, arreglo& v);
    friend arreglo operator+(arreglo v1,arreglo v2);
    friend bool operator<=(arreglo v1,arreglo v2);

};

double norma_amiga(tripleta t);


int main()
{
    cout<<"CLASES"<<endl;
    arreglo v("x",4,0);
    ifstream fo("datos.txt");
    fo>>v;
    fo.close();

    cout<<v<<endl;
    arreglo u;
    u=v+v;
    cout<<u<<endl;
    cout<<"max(v)="<<v.max()<<endl
        <<"min(u)="<<u.min()<<endl;

    cuarteto ct;
    cout<<ct.norma2()<<endl;
    cout<<"ct(x)="<<ct.Obt_x()<<endl;

/*
    tripleta t1,t2(2,3);
    cout<<"ingrese la tripleta:";
    cin>>t1;

    cout<<"x="<<t1.Obt_x()<<endl;
    cout<<"Norma="<<t2.norma()<<endl;

    double nr=norma_amiga(t2);
    cout<<"Norma="<<nr<<endl;
    cout<<"t2="<<t2<<endl
        <<"t1="<<t1<<endl;

    tripleta t3,t4;
    t3=t1+t2;
    t4=t1*t2;
    cout<<"suma="<<t3<<endl;
    cout<<"mult="<<t4<<endl;

    if(t1==t2)
        cout<<"son iguales"<<endl;
    else
        cout<<"son distintas"<<endl;

    tripleta *pt;
    pt=new tripleta;
    cout<<"Ingrese tripleta:";
    cin>>*pt;
    cout<<pt->norma()<<endl;
    delete pt;
*/
    return 0;
}
//ARREGLO
   arreglo::arreglo(string s,int n, int inicial=0)
   {
        Nombre=s;
        resize(n,inicial);
   }

    arreglo::~arreglo()
    {
        clear();
    }

    double arreglo::max()
    {
        double v_max=front();
        for(int i=1;i<size();i++)
        {
            if(at(i)>v_max)
                v_max= at(i);
        }
        return v_max;
    }


    double arreglo::min()
   {
        double v_min=front();
        for(int i=1;i<size();i++)
        {
            if(at(i)<v_min)
                v_min= at(i);
        }
        return v_min;
    }

    //sobrecargas
     ostream& operator<<(ostream& os, arreglo v)
     {
         os<<v.Nombre<<" = ";
         for(int i=0;i<v.size();i++)
            os<<v[i]<<" , ";
        return os;
     }

     istream& operator>>(istream& is, arreglo& v)
     {
         is>>v.Nombre;
         int n;
         is>>n;
         v.resize(n);
         for(int i=0;i<v.size();i++)
            is>>v[i];
        return is;

     }

     arreglo operator+(arreglo v1,arreglo v2)
     {
        if(v1.size()==v2.size())
        {
            arreglo suma("suma",v1.size(),0);
            for(int i=0;i<v1.size();i++)
                suma[i]=v1[i]+v2[i];
            
            return suma;
        }
        else
        {
            cout<<"Error de dimensión"<<endl;
            return arreglo("vacio", 0,0);
        }
     }


//TRIPLETA
double norma_amiga(tripleta t)
{
    double _x=(t.x);
    double w=sqrt(pow(_x,2)+pow(t.y,2)+pow(t.z,2));
    return w;
}

   tripleta::tripleta()
    {
        x=y=z=0;
    }

    tripleta::tripleta(double _x,double _y)
    {
        x=_x;
        y=z=_y;
    }

//FUNCIONES MIEMBRO
double tripleta::Obt_x()
{
    return x;
}

double tripleta::norma()
{
    double w=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    return w;
}

void tripleta::Modificar_y(double _y)
{
    y=_y;
}

//SOBRECARGA DE OPERADORES
ostream& operator<<(ostream& os, tripleta t)
{
    os<<"("<<t.x<<" , "<<t.y<<" , "<<t.z<<" )";
    return os;
}

istream& operator>>(istream& is,tripleta& t)
{
    is>>t.x>>t.y>>t.z;
    return is;
}

tripleta operator+(tripleta t1, tripleta t2)
{
    tripleta ts;
    ts.x=(t1.x+t2.x);
    ts.y=(t1.y+t2.y);
    ts.z=(t1.z-t2.z);
    return ts;
}

tripleta operator*(tripleta t1, tripleta t2)
{
    tripleta tm;
    tm.x=(t1.x*t2.x);
    tm.y=(t1.y*t2.y);
    tm.z=-(t1.z*t2.z);
    return tm;
}

tripleta operator*(double a, tripleta t2)
{
    tripleta tm;
    tm.x=(a*t2.x);
    tm.y=(a*t2.y);
    tm.z=(a*t2.z);
    return tm;
}

bool operator==(tripleta t1,tripleta t2)
{
    if(t1.x+t1.y+t1.z==t2.x+t2.y+t2.z)
        return true;
    else
        return false;
}
