/*
El dueño de un mínimarket  tiene n proveedores para un mismo producto  y  cada proveedor le  brinda precios distinto usar la estrategia de  divide y  vencerás  para  buscar  darle el precio menor y el proveedor del cual le va convenir adquirir   cierto producto y de esta manera poder  obtener  mayor  ingreso en el respectivo producto.  
Se debe tener en cuenta que el programa debe pedirte  el producto a evaluar.  Y luego la cantidad de proveedores de dicho producto con su respectivo precio y te debe arrojar como resultado el nombre del proveedor , nombre de producto y el precio
*/
#include <iostream>

using namespace std;

// Funciones
int divideyvenceras(float arreglo[], int n)
{
    int i, menor;
    menor=0;
    for (i = 0; i < n; i++)
    {
        if(arreglo[menor]>arreglo[i])
        {
            menor=i;
        }
    }
    return menor;
}

int main()
{
    // Variables
    int n, i;
    float precio, arreglo[100];

    string producto, proveedor[100];

    // Entrada
    cout << "Ingrese el nombre del producto: ";
    cin >> producto;
    cout << "Ingrese la cantidad de proveedores: ";
    cin >> n;
    cout << endl;
    
    for (i = 0; i < n; i++)
    {
        cout << "Ingrese el nombre del proveedor: ";
        cin >> proveedor[i];
        cout << "Ingrese el precio del producto: ";
        cin >> precio;
        arreglo[i] = precio;
        cout << endl;
    }

    // Proceso
    int indice = divideyvenceras(arreglo, n);

    // Salida
    cout << "El proveedor " << proveedor[indice] << " le da el precio mas bajo y le da el producto " << producto << " con un precio de " << arreglo[indice] << endl;

    return 0;
}