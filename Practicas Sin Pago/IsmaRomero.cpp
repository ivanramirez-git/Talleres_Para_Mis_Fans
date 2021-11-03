#include <iostream>
#include <string>
 
using namespace std;

// Funcion que busca un string dentro de un vector de strings
int buscar(string palabra, string vector[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(vector[i] == palabra)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
	//"alumnxs Grupo seis MaruOreskovic,IsmaelRomero, ArielMontano, AndresFloccari
	
    string alumnxs[50]={"MaruOreskovic","IsmaelRomero","ArielMontano","AndresFloccari"};
    string nombre;
    string apellido;
    string nombreApellido = "Alumno ";
    int numNombres=4;

    while(true){
        cout << "\n Ingrese Nombre: "; cin >> nombre;
        cout << "  Ingrese Apellido: "; cin >> apellido;
    
        nombreApellido = nombre + apellido;

        if(buscar(nombreApellido, alumnxs, numNombres) != -1)
        {
            cout << "  " << nombreApellido << " ya esta registrado en el grupo 6" << endl;
        }
        else
        {
            alumnxs[4] = nombreApellido;
            cout << "  " << nombreApellido << " registrado en el grupo 6" << endl;
            numNombres++;
        }
    
        // Preguntar si desea ver los nombres de todos
        cout << "  Desea ver los nombres de todos los alumnos? (s/n): ";
        char respuesta;
        cin >> respuesta;
        if(respuesta == 's')
        {
            for(int i=0; i<numNombres; i++)
            {
                cout << "  " << alumnxs[i] << endl;
            }
        }
        
    }
 
    return 0;
}
