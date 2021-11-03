#include <iostream>

using namespace std;

string invertir(string cadena)
{
    int i,j,tam;
    string invertida;
    tam=cadena.length();
    for(i=tam-1;i>=0;i--)
    {
        invertida=invertida+cadena[i];
    }
    return invertida;
}

string vacio(string cadena)
{
    int i,tam;
    tam=cadena.length();
    if(tam==0)
    {
        cout<<"La cadena esta vacia"<<endl;
    }
    else
    {
        cout<<"La cadena invertida es: "<< invertir(cadena) <<endl;
    }
    return cadena;
}

int main(){

    vacio("casa");
    vacio("cadenas");
    vacio("");

    
    return 0;
}