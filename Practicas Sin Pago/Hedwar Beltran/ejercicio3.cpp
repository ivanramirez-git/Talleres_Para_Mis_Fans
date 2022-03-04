/*

    En una tienda efectúan un descuento a los clientes dependiendo el monto de la compra.
    El descuento se efectúa con base en el siguiente criterio:
        • Si el monto es menor que $500, No hay descuento.
        • Si el monto está comprendido entre $500 y $1000, Inclusive el 5% de descuento.
        • Si el monto está comprendido entre $1000 y $7000, Inclusive el 11% de descuento.
        • Si el monto está comprendido entre $7000 y $15000, Inclusive el 18% de descuento.
        • Si el monto es mayor a $15000, 25% de descuento.
    Construya un algoritmo tal que, dado el monto de la compra de un cliente, determine lo que el mismo debe pagar.

*/

#include <iostream>

using namespace std;

int main()
{
    float monto;
    cout << "Ingrese el monto de la compra: ";
    cin >> monto;

    if (monto < 500)
    {
        cout << "No hay descuento: " << monto << endl;
    }
    else if (monto >= 500 && monto <= 1000)
    {
        cout << "Descuento: 5%: " << monto * 0.05 << " $, Total: " << monto - (monto * 0.05) << " $" << endl;
    }
    else if (monto >= 1000 && monto <= 7000)
    {
        cout << "Descuento: 11%: " << monto * 0.11 << " $, Total: " << monto - (monto * 0.11) << " $" << endl;
    }
    else if (monto >= 7000 && monto <= 15000)
    {
        cout << "Descuento: 18%: " << monto * 0.18 << " $, Total: " << monto - (monto * 0.18) << " $" << endl;
    }
    else if (monto > 15000)
    {
        cout << "Descuento: 25%: " << monto * 0.25 << " $, Total: " << monto - (monto * 0.25) << " $" << endl;
    }

    return 0;
}