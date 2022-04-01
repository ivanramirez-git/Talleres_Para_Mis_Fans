#include <iostream>
#include <math.h>

using namespace std;

// Función soluciona una ecuación de segundo grado
void soluciona_ecuacion(){
    float a, b, c;
    cout << "Introduce el coeficiente de x^2: ";
    cin >> a;
    cout << "Introduce el coeficiente de x: ";
    cin >> b;
    cout << "Introduce el coeficiente de constante: ";
    cin >> c;

    float x1, x2;
    float discriminante = b*b - 4*a*c;
    if(discriminante < 0){
        cout << "No hay soluciones reales" << endl;
    }else if(discriminante == 0){
        x1 = x2 = -b/(2*a);
        cout << "x1 = x2 = " << x1 << endl;
    }else{
        x1 = (-b + sqrt(discriminante))/(2*a);
        x2 = (-b - sqrt(discriminante))/(2*a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
}

// Funcion que recibe una matriz de coeficientes 3x4 y devuelve el vector solución [x1, x2, x3]
void soluciona_sistema_3x4(float matriz[3][4], float solucion[3]){
    // Metodo de Gauss Jordan
    
    // paso 1: eliminación de Gauss
    for(int i = 0; i < 3; i++){
        // buscamos el mayor elemento de la fila i
        float mayor = fabs(matriz[i][i]);
        int fila_mayor = i;
        for(int j = i+1; j < 3; j++){
            if(fabs(matriz[j][i]) > mayor){
                mayor = fabs(matriz[j][i]);
                fila_mayor = j;
            }
        }
        // intercambiamos filas
        if(fila_mayor != i){
            for(int j = 0; j < 4; j++){
                float aux = matriz[i][j];
                matriz[i][j] = matriz[fila_mayor][j];
                matriz[fila_mayor][j] = aux;
            }
        }
        // paso 2: eliminación de Gauss
        for(int j = i+1; j < 3; j++){
            float factor = matriz[j][i]/matriz[i][i];
            for(int k = i; k < 4; k++){
                matriz[j][k] -= factor*matriz[i][k];
            }
        }
    }
    // paso 3: sustitución hacia atrás
    for(int i = 2; i >= 0; i--){
        float suma = 0;
        for(int j = i+1; j < 3; j++){
            suma += matriz[i][j]*solucion[j];
        }
        solucion[i] = (matriz[i][3] - suma)/matriz[i][i];
    }

    
}

void resuelve_3_ecuaciones(){
    float a1, b1, c1, a2, b2, c2, a3, b3, c3, d1, d2, d3;
    cout << "Introduce el coeficiente a en la ecuacion 1: ";
    cin >> a1;
    cout << "Introduce el coeficiente b en la ecuacion 1: ";
    cin >> b1;
    cout << "Introduce el coeficiente c en la ecuacion 1: ";
    cin >> c1;
    cout << "Introduce el resultado de la ecuacion 1: ";
    cin >> d1;

    cout << endl;

    cout << "Introduce el coeficiente a en la ecuacion 2: ";
    cin >> a2;
    cout << "Introduce el coeficiente b en la ecuacion 2: ";
    cin >> b2;
    cout << "Introduce el coeficiente c en la ecuacion 2: ";
    cin >> c2;
    cout << "Introduce el resultado de la ecuacion 2: ";
    cin >> d2;

    cout << endl;

    cout << "Introduce el coeficiente a en la ecuacion 3: ";
    cin >> a3;
    cout << "Introduce el coeficiente b en la ecuacion 3: ";
    cin >> b3;
    cout << "Introduce el coeficiente c en la ecuacion 3: ";
    cin >> c3;
    cout << "Introduce el resultado de la ecuacion 3: ";
    cin >> d3;

    // Imprime las ecuaciones
    cout << "Ecuacion 1: " << a1 << "*x + " << b1 << "*y + " << c1 << "*z = " << d1 << endl;
    cout << "Ecuacion 2: " << a2 << "*x + " << b2 << "*y + " << c2 << "*z = " << d2 << endl;
    cout << "Ecuacion 3: " << a3 << "*x + " << b3 << "*y + " << c3 << "*z = " << d3 << endl;

    // Matriz de coeficientes
    float matriz[3][4] = {
        {a1, b1, c1, d1},
        {a2, b2, c2, d2},
        {a3, b3, c3, d3}
    };

    // Vector solución
    float solucion[3];

    // Resuelve el sistema
    soluciona_sistema_3x4(matriz, solucion);

    // Imprime la solución
    cout << "Solucion: " << endl;
    cout << "x = " << solucion[0] << endl;
    cout << "y = " << solucion[1] << endl;
    cout << "z = " << solucion[2] << endl;

}

int main(){
    while(true){
        int opcion;
        cout << "1. Solucionar ecuacion de segundo grado" << endl;
        cout << "2. Resolver 3 ecuaciones 3 incognitas" << endl;
        cout << "3. Salir" << endl;
        cout << "Introduce una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                soluciona_ecuacion();
                break;
            case 2:
                resuelve_3_ecuaciones();
                break;
            case 3:
                return 0;
            default:
                cout << "Opcion no valida" << endl;
        }
    }
    return 0;
}