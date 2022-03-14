#include <iostream>

using namespace std;

/*
Cuando digite el número 0, salir. 
Ingresar a cada opción, solicitar el número de hamburguesas que desea, solicitar cuantas adicionan combo ($1.50), 
presentar el total a pagar por cada pedido.
Menú
a. simple ($2.00)
b. completa ($2.25)
c. doble (2.75)
0.  Salir
*/

int main()
{
    int hamburguesa;
    float total;
    char opcion = 's';
    while (opcion != '0')
    {
        
        cout << "a. simple ($2.00)\nb. completa ($2.25)\nc. doble (2.75)\n0.  Salir\n";
        cout << "Ingrese el tipo de hamburguesa: ";
        cin >> opcion;
        
        cout << "Ingrese el numero de hamburguesas que desea: ";
        cin >> hamburguesa;

        switch (opcion)
        {
        case 'a':
            total = hamburguesa * 2.00;
            break;
        case 'b':
            total = hamburguesa * 2.25;
            break;
        case 'c':
            total = hamburguesa * 2.75;
            break;
        case '0':
            break;
        default:
            cout << "Opcion no valida\n";
            break;
        }
        if (opcion != '0')
        {
            cout << "El total a pagar por cada pedido es: $" << total << endl;
        }
    }
    return 0;
}


