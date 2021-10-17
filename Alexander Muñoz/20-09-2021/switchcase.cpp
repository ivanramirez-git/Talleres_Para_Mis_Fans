/******************************************************************************
Este programa explica el uso de switch case

Autor
Fecha
Grupo

*******************************************************************************/

#include <iostream>

using namespace std;

int num1=0;
int num2=0;
int opcion =0;
char opcion2;
float respuesta=0;
bool error = false;



int main()
{
    cout<<"Bienvenido....."<<endl<<endl;
    cout<<"Digite el primer numero ";
    cin>>num1;
    cout<<"Digite el segundo numero ";
    cin>>num2;
    
    //cout<<endl<<"Digite una opcion:"<<endl<<endl;
    //cout<<"1........ suma"<<endl;
    //cout<<"2.........resta"<<endl;
    //cout<<"3.........multiplicacion"<<endl<<endl;
    
    
    cout<<endl<<"Digite una opcion:"<<endl<<endl;
    cout<<"a........ suma"<<endl;
    cout<<"b.........resta"<<endl;
    cout<<"c.........multiplicacion"<<endl;
    cout<<"d.........division"<<endl;
    cout<<"e.........modulo"<<endl;    
    
    cin>>opcion2;
    
    switch(opcion2){
        case 'a':
            respuesta=num1+num2;
            //cout<<"La respuesta es: "<<respuesta;
            break;
        case 'b':
            respuesta=num1-num2;
            //cout<<"La respuesta es: "<<respuesta;
            break;
        case 'c':
            respuesta=num1*num2;
            //cout<<"La respuesta es: "<<respuesta;
            break;
        case 'd':
        	if(num2){
            	respuesta=(num1+0.0)/(num2+0.0);
			}else{
				cout<<"No se puede dividir por cero!!!!!!";
			}
            //cout<<"La respuesta es: "<<respuesta;
            break;
        case 'e':
			if(num2){
            	respuesta=num1%num2;
			}else{
				cout<<"No se puede hacer modulo cero!!!!!!";
			}
            //cout<<"La respuesta es: "<<respuesta;
            break;
        default:
            error = true;
            cout<<"Digito una opcion que no existe!!!!!!";
    }
    
    
    if(!error){
        cout<<"La respuesta es: "<<respuesta<<endl;
        if(respuesta==0){
        	cout<<"Cero"<<endl;
		}else if(respuesta>0){
			cout<<"Positivo"<<endl;
		}else{
			cout<<"Negativo"<<endl;
		}
    }
    //cout<<"La respuesta es: "<<respuesta;

    return 0;
}
