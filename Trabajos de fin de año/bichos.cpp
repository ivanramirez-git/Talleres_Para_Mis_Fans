#include<iostream>

using namespace std;

int main(){
    
    int A=0; // Bichos tipo A
    int B=0; // Bichos tipo B
    int C=0; // Bichos tipo C
    int D=0; // Dias de simulación

    // Ingrese el numero de bichos tipo A iniciales.
    cout << "Ingrese el numero de bichos tipo A iniciales: ";
    cin >> A;

    // Ingrese el numero de dias que se quiere simular.
    cout << "Ingrese el numero de dias que se quiere simular: ";
    cin >> D;

    // Variables auxiliares
    int A_aux=0;
    int B_aux=0;
    int C_aux=0;
    int aux=0;

    // Datos iniciales
    cout<< "Dia " << 0 << endl;
    cout<< "Bichos tipo A: " << A << endl;
    cout<< "Bichos tipo B: " << B << endl;
    cout<< "Bichos tipo C: " << C << endl;
    cout << endl;

    // Simulacion
    for(int i=0; i<D; i++){
        

        A_aux = A;
        B_aux = B;
        C_aux = C;

        // Produccion de A
        if(A_aux > 0){
            A += A_aux;
            B += 3* A_aux;
            C += A_aux;
        }

        // Produccion de B
        if(B_aux > 0){
            B +=  2* B_aux;
            C +=  2* B_aux;
        }

        // Produccion de C
        if(C_aux > 0){
            A +=  C_aux;
            C +=  4* C_aux;
        }

        cout<< "Dia " << i+1 << endl;
        cout<< "Bichos tipo A: " << A << endl;
        cout<< "Bichos tipo B: " << B << endl;
        cout<< "Bichos tipo C: " << C << endl;
        cout << endl;
    }

    // Suma de bichos tipo A, B y C
    aux = A + B + C;
    cout << "La cantidad total de bichos es: " << aux << endl;

    return 0;
}