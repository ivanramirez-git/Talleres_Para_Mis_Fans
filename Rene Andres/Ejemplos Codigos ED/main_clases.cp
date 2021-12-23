
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
private:
    double x;
    double y;
public:
    double z;
    //CONSTRUCTORES Y DESTRUCTORES
    tripleta()
    {
        x=y=z=0;
    }
    tripleta(double _x,double _y)
    {
        x=_x;
        y=z=_y;
    }
    ~tripleta()
    {

    }
//FUNCIONES MIEMBRO
double Obt_x()
{
    return x;
}

double norma()
{
    double w=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    return w;
}

void Modificar_y(double _y)
{
    y=_y;
}

//FUNCIONES AMIGAS
friend double norma_amiga(tripleta t);
//SOBRECARGA DE OPERADORES
friend ostream& operator<<(ostream& os, tripleta t)
{
    os<<"("<<t.x<<" , "<<t.y<<" , "<<t.z<<" )";
    return os;
}

friend istream& operator>>(istream& is,tripleta& t)
{
    is>>t.x>>t.y>>t.z;
    return is;
}

friend tripleta operator+(tripleta t1, tripleta t2)
{
    tripleta ts;
    ts.x=(t1.x+t2.x);
    ts.y=(t1.y+t2.y);
    ts.z=(t1.z-t2.z);
    return ts;
}

friend tripleta operator*(tripleta t1, tripleta t2)
{
    tripleta tm;
    tm.x=(t1.x*t2.x);
    tm.y=(t1.y*t2.y);
    tm.z=-(t1.z*t2.z);
    return tm;
}

friend tripleta operator*(double a, tripleta t2)
{
    tripleta tm;
    tm.x=(a*t2.x);
    tm.y=(a*t2.y);
    tm.z=(a*t2.z);
    return tm;
}

friend bool operator==(tripleta t1,tripleta t2)
{
    if(t1.x+t1.y+t1.z==t2.x+t2.y+t2.z)
        return true;
    else
        return false;
}

};//fin tripleta


double norma_amiga(tripleta t)
{
    double _x=(t.x);
    double w=sqrt(pow(_x,2)+pow(t.y,2)+pow(t.z,2));
    return w;
}



int main()
{
    cout<<"CLASES"<<endl;
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

    return 0;
}


