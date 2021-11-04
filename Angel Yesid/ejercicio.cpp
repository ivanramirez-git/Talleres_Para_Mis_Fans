#include <iostream>

using namespace std;

/* Una miscelánea necesita un programa que al comprar con un bono, muestre  su precio y un descuento del 15%. El usuario tiene que ingresar el nombre del producto y el precio (mínimo tres productos diferentes). 
Mostrar que productos compro, su precio (sin descuento) y precio total (con descuento 15%). */


int main()
{
    // Preguntar cuantos productos va comprar
    int cantidad;
    cout << "Cuantos productos va a comprar: ";
    cin >> cantidad;

    // Declarar variables
    string productos[cantidad];
    double precio[cantidad];
    double precioTotal = 0;
    double descuento = 0;

    // Ingresar productos y precios
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Ingrese el nombre del producto: ";
        cin >> productos[i];
        cout << "Ingrese el precio del producto: ";
        cin >> precio[i];
    }

    // Mostrar productos, precio y precio total
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Producto: " << productos[i] << endl;
        cout << "Precio: " << precio[i] << endl;
        precioTotal += precio[i];
    }

    // Calcular descuento
    descuento = precioTotal * 0.15;

    // Mostrar precio total con descuento
    cout << "Precio total: " << precioTotal << endl;
    cout << "Descuento: " << descuento << endl;
    cout << "Precio total con descuento: " << precioTotal - descuento << endl;

    return 0;
}