#include <iostream>
#include <cstring>

using namespace std;

// Programa principal
int main(){

    // Capturar arreglo
    char arreglo[5][30];

    // Capturar 5 palabras
    for(int i=0; i<5; i++){
        cout << "Ingrese una palabra: ";
        cin >> arreglo[i];
    }

    char arregloOrdenado[5][30];
    char aux[30];
    
    // Copiar arreglo
    for(int i=0; i<5; i++){
        strcpy(arregloOrdenado[i], arreglo[i]);
    }

    // Ordenar arreglo
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(strcmp(arregloOrdenado[i], arregloOrdenado[j]) < 0){
                strcpy(aux, arregloOrdenado[i]);
                strcpy(arregloOrdenado[i], arregloOrdenado[j]);
                strcpy(arregloOrdenado[j], aux);
            }
        }
    }

    // Mostrar arreglo original
    cout << "Arreglo original: " << endl;
    for(int i=0; i<5; i++){
        cout << arreglo[i] << endl;
    }

    // Mostrar arreglo ordenado
    cout << "Arreglo ordenado: " << endl;
    for(int i=0; i<5; i++){
        cout << arregloOrdenado[i] << endl;
    }

    return 0;
}