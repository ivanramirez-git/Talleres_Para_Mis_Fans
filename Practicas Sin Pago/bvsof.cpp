#include <iostream>

using namespace std;

// Funcion que calcula el area de un triangulo
float areaTriangulo(float base, float altura)
{
    return (base * altura) / 2;
}

// Funcion que calcula el area de un cuadrado
float areaCuadrado(float lado)
{
    return lado * lado;
}

// Funcion que calcula el area de un pentagono
float areaPentagono(float apotema, float lado)
{
    return (apotema * lado * 5) / 2;
}

// Funcion que calcula el area de un hexagono
float areaHexagono(float apotema, float lado)
{
    return (apotema * lado * 6) / 2;
}

// Funcion que calcula el area de un circulo
float areaCirculo(float radio)
{
    return 3.1416 * radio * radio;
}

int main(){
    // Bienvenida
    cout << "Bienvenido al programa de calculo de areas" << endl;

    // Menu repetitivo, area triangulo, area cuadrado, area pentagono, area hexagono, area circulo
    int opcion;
    do{
        cout << "Seleccione una opcion: " << endl;
        cout << "1. Area de un triangulo" << endl;
        cout << "2. Area de un cuadrado" << endl;
        cout << "3. Area de un pentagono" << endl;
        cout << "4. Area de un hexagono" << endl;
        cout << "5. Area de un circulo" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;

        // Segun la opcion seleccionada se llama a la funcion correspondiente
        switch(opcion){
            case 1:
                float base, altura;
                cout << "Ingrese la base del triangulo: ";
                cin >> base;
                cout << "Ingrese la altura del triangulo: ";
                cin >> altura;
                cout << "El area del triangulo es: " << areaTriangulo(base, altura) << endl;
                break;
            case 2:
                float lado;
                cout << "Ingrese el lado del cuadrado: ";
                cin >> lado;
                cout << "El area del cuadrado es: " << areaCuadrado(lado) << endl;
                break;
            case 3:
                float apotema, lado1;
                cout << "Ingrese el apotema del pentagono: ";
                cin >> apotema;
                cout << "Ingrese el lado del pentagono: ";
                cin >> lado1;
                cout << "El area del pentagono es: " << areaPentagono(apotema, lado1) << endl;
                break;
            case 4:
                float apotema1, lado2;
                cout << "Ingrese el apotema del hexagono: ";
                cin >> apotema1;
                cout << "Ingrese el lado del hexagono: ";
                cin >> lado2;
                cout << "El area del hexagono es: " << areaHexagono(apotema1, lado2) << endl;
                break;
            case 5:
                float radio;
                cout << "Ingrese el radio del circulo: ";
                cin >> radio;
                cout << "El area del circulo es: " << areaCirculo(radio) << endl;
                break;
            case 6:
                cout << "Gracias por usar el programa" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    }while(opcion != 6);

    return 0;
}