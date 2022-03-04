#include <iostream>
#include <cstring>

#define num_O 100000 // 1 <= O <= 100000
#define num_I 400 // 1 <= I <= 400

using namespace std;

int main(){

    // Ingrese el numero de palabras
    int num_palabras;
    cin >> num_palabras;

    // Validar que el numero de palabras este en O
    while(num_palabras < 1 || num_palabras > num_O){
        cout << "Ingrese un numero de palabras valido" << endl;
        cin >> num_palabras;
    }

    // Ingrese las palabras
    char palabras[num_palabras][100];

    // Ingrese las palabras
    for(int i = 0; i < num_palabras; i++){
        cin >> palabras[i];
    }

    // Ingrese el numero de palabras a invocar
    int num_invocar;
    cin >> num_invocar;
    // Validar que el numero de palabras a invocar este en I
    while(num_invocar < 1 || num_invocar > num_I){
        cout << "Ingrese un numero de palabras a invocar valido" << endl;
        cin >> num_invocar;
    }

    // Ingrese la posicion de las palabras a invocar
    int posiciones[num_invocar];
    for(int i = 0; i < num_invocar; i++){
        cin >> posiciones[i];
    }
    
    // Imprimir las palabras invocadas
    for(int i = 0; i < num_invocar; i++){
        // Cada vez que se imprima una palabra se debe boorar la palabra
        cout << palabras[posiciones[i] - 1] << endl;

        // Quitar la palabra de la lista
        for(int j = posiciones[i] - 1; j < num_palabras - 1; j++){
            strcpy(palabras[j], palabras[j + 1]);
        }
        num_palabras--;
    }

    return 0;
}