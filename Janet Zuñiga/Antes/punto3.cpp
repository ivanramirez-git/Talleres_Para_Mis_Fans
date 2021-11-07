#include <iostream>

using namespace std;

int main()
{
    //Variables
    int opc, i, chicas, medianas, grandes, total;
    float venta, promedio;

    opc = 0;
    i = 1;
    venta = -1;
    chicas = 0;
    medianas = 0;
    grandes = 0;
    total = 0;
    
    while(opc != -1){
        while(venta<0){
            cout << "Ingrese venta #: "<< i << endl;
            cin >> venta;
        }
        if(venta<=200){
            chicas=chicas+1;
        }else if(venta<400){
            medianas=medianas+1;
        }else{
            grandes=grandes+1;
        }
        cout << "Para finalizar presione -1 | Para continuar cualquier otro numero: ";
        cin >> opc;
        i=i+1;
        venta = -1;
    }

    cout << endl;

    total = chicas + medianas + grandes;

    cout << "Ventas totales: " << total << endl;
    cout << "Ventas chicas: " << chicas << endl;
    cout << "Ventas medianas: " << medianas << endl;
    cout << "Ventas grandes: " << grandes << endl;
    
    return 0;
}