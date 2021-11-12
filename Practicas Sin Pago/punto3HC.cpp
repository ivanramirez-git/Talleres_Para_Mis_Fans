#include <iostream>

using namespace std;

struct alumno{
    string nombre;
    string apellido;
    long nro_documento;
    float notaPrimerParcial;
    float notaSegundoParcial;
};

int main()
{
    alumno registro[10];
    int i;
    
    cout << "Ingrese los datos de los alumnos" << endl;
    
    for(i=0;i<10;i++){
        cout<<"Ingrese el nombre del alumno: ";
        cin>>registro[i].nombre;
        cout<<"Ingrese el apellido del alumno: ";
        cin>>registro[i].apellido;
        cout<<"Ingrese el numero de documento del alumno: ";
        cin>>registro[i].nro_documento;
        cout<<"Ingrese la nota del primer parcial del alumno: ";
        cin>>registro[i].notaPrimerParcial;
        cout<<"Ingrese la nota del segundo parcial del alumno: ";
        cin>>registro[i].notaSegundoParcial;
    }

    cout << "Los datos ingresados son: " << endl;

    for(i=0;i<10;i++){
        cout<<"Nombre: "<<registro[i].nombre<<endl;
        cout<<"Apellido: "<<registro[i].apellido<<endl;
        cout<<"Numero de documento: "<<registro[i].nro_documento<<endl;
        cout<<"Nota del primer parcial: "<<registro[i].notaPrimerParcial<<endl;
        cout<<"Nota del segundo parcial: "<<registro[i].notaSegundoParcial<<endl;
    }
 
 
 return 0;
}