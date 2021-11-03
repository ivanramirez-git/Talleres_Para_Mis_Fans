#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

// Funcion f(x)=f(x) = e^x-x^2-x-1
double f(double x)
{
    return exp(x)-pow(x,2)-x-1;
}

// Crear una funcion que permita leer 10 numeros enteris, almacenarlos en un vector y determinar e informar si el promedio de datos esta almacenado en el vector.
int promedio()
{
    int n,i,j,k,l,m,numeros[10],promedio;
    cout<<"Ingrese 10 numeros enteros: ";
    for(i=0;i<10;i++)
    {
        cin>>numeros[i];
    }
    promedio=0;
    for(j=0;j<10;j++)
    {
        promedio=promedio+numeros[j];
    }
    promedio=promedio/10;
    cout<<"El promedio de los numeros ingresados es: "<<promedio<<endl;
    // Verificar si el promedio esta almacenado en el vector
    for(k=0;k<10;k++)
    {
        if(promedio==numeros[k])
        {
            cout<<"El promedio esta almacenado en el vector"<<endl;
            break;
        }
        else
        {
            //cout<<"El promedio no esta almacenado en el vector"<<endl;
        }
    }
    return 0;
}

//Funcion que recibe un string y devuelve invertido
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

//Funcion que captura una cadena string y mediante una funcion determinar si esta vacia o no. Si lo esta, debe informarlo al usuario con un mensaje especial o si no debe mostrar la cadena al contrario ejemplo: "casa" -> "casa", mostrar "asac"
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

//Funcion que recibe una cadena y devuelve la cadena al contrario
/*char *invertir(char *cad)
{
    int i,j,k,l,m,n,tam;
    char *cad2;
    tam=strlen(cad);
    cad2=new char[tam];
    for(i=0;i<tam;i++)
    {
        cad2[i]=cad[tam-1-i];
    }
    return cad2;
}*/

//Funcion que captura una cadena y mediante una funcion determinar si esta vacia o no. Si lo esta, debe informarlo al usuario con un mensaje especial o si no debe mostrar la cadena al contrario ejemplo: "casa" -> "casa", mostrar "asac"
/*void cadena()
{
    char cadena[100];
    cout<<"Ingrese una cadena: ";
    cin>>cadena;
    if(strlen(cadena)==0)
    {
        cout<<"La cadena esta vacia"<<endl;
    }
    else
    {
        cout<<"La cadena invertida es: "<<invertir(cadena)<<endl;

    }
}
*/


int main(){

    //promedio();
    //cadena();
    //vacio("Ivan");
    //vacio("");

    // Regla falsa

    // a = a + h
    // se detiene cuando |h| < 0.001
    // f(x) = e^x-2x-1
    // h = -(b-a)/(f(b)-f(a))*f(a)
    // a = 1
    // b = 2
    // tol = 0.001

    //Implementacion de la regla falsa mostrando a, b y h en cada iteracion
    double a=1;
    double b=2;
    double tol=0.001;

    while(true){
        double h = -(b-a)/(f(b)-f(a))*f(a);
        cout << "a: " << a << " b: " << b << " h: " << h << endl;
        if(abs(h) < tol){
            break;
        }
        a = a + h;
    }
    
    return 0;
}