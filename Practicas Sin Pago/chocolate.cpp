#include <iostream>

using namespace std;

int main(){

    int opcion;
    // Telefono
    char tablero[][3] = {{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};
    // Escribir numeros de tres cifras menores a 600, sin el digito 5, y sin digitos repetidos
    do{
        cout << "1. Numeros de tres cifras menores a 600, sin el digito 5, y sin digitos repetidos" << endl;
        cout << "2. Numero de telefono" << endl;
        cout << "0. Salir" << endl;
        cout << "Selecciona: ";
        cin >> opcion;
        switch (opcion)
        {
            case 0:
                break;
            case 1:
                // Ciclo
                while(true){
                    int numero;
                    cout << "Ingrese un numero: ";
                    cin >> numero;
                    // Validar que tenga 3 cifras
                    if (numero >= 100 && numero <= 600){
                        // Validar que no contenga 5
                        if (numero % 10 != 5 && (numero / 10) % 10 != 5 && (numero / 100) % 10 != 5){
                            // Validar que no contenga ningun digito repetido
                            if (numero / 100 != numero / 10 % 10 && numero / 10 % 10 != numero % 10 && numero % 10 != numero / 100){
                                cout << "El numero es valido" << endl;
                                break;
                            }
                            else{
                                cout << "El numero no es valido" << endl;
                            }
                        } else{
                            cout << "El numero no es valido" << endl;
                        }
                    } else{
                        cout << "El numero no es valido" << endl;
                    }
                }
                break;
            case 2:
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
                    cout << "El numero: " << aux << " esta en la fila: " << fila << " y la columna: " << columna << endl;

                }
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
    }while(opcion != 0);
    return 0;
}