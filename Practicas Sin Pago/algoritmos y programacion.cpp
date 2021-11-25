// Programa que crea un vector de 5 enteros y pide numero hasta que se llena el vector

#include <iostream>

using namespace std;

int main()
{   
    cout << "Tamano del arreglo ";
    int tamano;
    cin >> tamano;
    string arreglo[tamano];
    // llenar de ""
    for (int i = 0; i < tamano; i++)
    {
        arreglo[i] = "";
    }
    for (int i = 0; i < tamano; i++){
        cout << "Dato ";
        cin >> arreglo[i];
        // Imprime el vector
        cout << "[";
        for (int j = 0; j < tamano; j++){
            
            if (j == tamano - 1){
                cout << arreglo[j] << "]";
            }else{
                cout << arreglo[j] << " | ";
            }

        }
        cout << endl;
    }
    cout<<"Arreglo lleno"<<endl;
    return 0;
}
        
        
