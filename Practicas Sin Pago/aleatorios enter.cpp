#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// funcion que genera un numero aleatorio entre 1 y 8
int aleatorio(){
    int num;
    num = rand() % 8 + 1;
    return num;
}

// Funcion para pausar la ejecucion del programa
void pausa()
{
    cout << "Pulse <Intro> para continuar";
    cin.get();
}

int main(){

    // Inicializamos el generador de numeros aleatorios
    srand(time(NULL));

    int sumando1[5];
    int sumando2[5];

    // generamos los numeros aleatorios
    for(int i = 0; i < 5; i++){
        sumando1[i] = aleatorio();
        sumando2[i] = aleatorio();
    }

    cout << endl << "La suma de los numeros aleatorios es: " << endl;

    // Sumar los numeros
    int suma[6] = {0};
    int auxiliar[5] = {0};
    
    for(int i = 4; i >= 0; i--){
        suma[i+1] = sumando1[i] + sumando2[i];
        if(auxiliar[i]>0){
            auxiliar[i] = 0;
            suma[i+1] = suma[i+1] + 1;
        }
        if(i==0 && suma[i+1]>9){
            suma[i] = 1;
            suma[i+1] = suma[i+1] %10;
        }
        
        if(suma[i+1] >= 10){
            auxiliar[i-1] = suma[i+1] / 10;
            suma[i+1] = suma[i+1] % 10;
        }
        // Imprimir esquema
        cout << "\t  ";
        for(int i = 0; i < 5; i++){
            cout << auxiliar[i] << " ";
        }
        cout << endl;
        cout << "\t  ";
        for(int i = 0; i < 5; i++){
            cout << sumando1[i] << " ";
        }
        cout << endl;
        cout << "+\t  ";
        for(int i = 0; i < 5; i++){
            cout << sumando2[i] << " ";
        }
        cout << endl;
        cout << "\t  ";
        for(int i = 0; i < 5; i++){
            cout << "-" << " ";
        }
        cout << endl;
        cout << "\t";
        for(int i = 0; i < 6; i++){
            cout << suma[i] << " ";
        }
        cout << endl;
        pausa();        
    }
    return 0;
}