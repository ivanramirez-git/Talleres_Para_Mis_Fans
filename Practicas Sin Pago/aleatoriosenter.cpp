#include <iostream>

using namespace std;

// funcion que genera un numero aleatorio entre 1 y 8
int aleatorio(){
    int num;
    num = rand() % 8 + 1;
    return num;
}


int main(){

    int sumando1[5];
    int sumando2[5];

    // generamos los numeros aleatorios
    for(int i = 0; i < 5; i++){
        sumando1[i] = aleatorio();
        sumando2[i] = aleatorio();
    }

    // mostramos los numeros aleatorios
    cout << "Los numeros aleatorios son: " << endl;
    for(int i = 0; i < 5; i++){
        cout << sumando1[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 5; i++){
        cout << sumando2[i] << " ";
    }
    
    return 0;
}