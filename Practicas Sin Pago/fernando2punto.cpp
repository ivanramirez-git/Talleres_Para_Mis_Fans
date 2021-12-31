#include <iostream>

using namespace std;

int main()
{

    // Telefono
    char tablero[][3] = {{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};
    
    int fila, columna, numero;
    cout<<"Ingrese el numero de telefono: ";
    cin>>numero;
    while(numero != 0){
        // Sacar cada digito
        int aux = numero % 10;
        numero /= 10;
        // Buscar el digito en el tablero
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (tablero[i][j] == aux){
                    fila = i;
                    columna = j;
                }
            }
        }
        // Imprimir la ubicacion del digito en el tablero
        cout << "El numero: " << aux << " esta en la fila: " << fila + 1 << " y la columna: " << columna + 1 << endl;

    }

    return 0;
}