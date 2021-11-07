/*Crear un programa para calcular las áreas y perímetros de algunas figuras geométricas
Los datos para el cálculo de las áreas y los perímetros (datos de entrada) se pedirán al usuario antes de entrar al menú principal
Se programará un menú principal que contenga las siguientes opciones:
1. Áreas
2. Perímetros
3. Salir
En la primera opción tendrá un submenú con las opciones: 1. Cuadrilátero 2. Trapecio 3. Esfera 4. salir
En la segunda opción tendrá un submenú con las opciones: 1. Rectángulo 2. Triangulo 3. Circulo 4. Salir
Realizar el cálculo de cada área y perímetro en una función con paso de parámetros.
Todas las opciones de salir deberán preguntar primero si realmente desea salir del programa o no. Mientras el usuario no elija salir del programa regresar al menú.*/
#include <iostream>

using namespace std;

int main()
{
    // Valiable para el menú principal
    int opcion;

    // Variables para operaciones
    float area, perimetro;    

    // Ciclo do while para el menú principal
    do
    {
        // Mensajes para el menu principal
        cout << "1. Areas" << endl;
        cout << "2. Perimetros" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        // switch para el menú principal
        switch (opcion)
        {
        case 1:
            // Mensajes para el submenú de áreas
            cout << "1. Cuadrilatero" << endl;
            cout << "2. Trapecio" << endl;
            cout << "3. Esfera" << endl;
            cout << "4. Salir" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion;
            // switch para el submenú de áreas
            switch (opcion)
            {
            case 1:
                // Mensajes para el submenú de áreas
                cout << "Ingrese el valor de los lados: ";
                cin >> opcion;
                // Aqui tu codigo para el area del cuadrilatero
                area = 0;
                cout << "El area del cuadrilatero es: " << area << endl;
                break;
            case 2:
                cout << "Ingrese el valor de los lados: ";
                cin >> opcion;
                // Aqui tu codigo para el area del trapecio
                area = 0;
                cout << "El area del trapecio es: " << opcion << endl;
                break;
            case 3:
                cout << "Ingrese el valor de la altura: ";
                cin >> opcion;
                // Aqui tu codigo para el area de la esfera
                area = 0;
                cout << "El area de la esfera es: " << opcion << endl;
                break;
            case 4:
                cout << "Gracias por usar el programa" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
            break;

        case 2:
            // Mensajes para el submenú de perímetros
            cout << "1. Rectangulo" << endl;
            cout << "2. Triangulo" << endl;
            cout << "3. Circulo" << endl;
            cout << "4. Salir" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion;

            // switch para el submenú de perímetros
            switch (opcion)
            {
            case 1:
                cout << "Ingrese el valor de los lados: ";
                cin >> opcion;
                // Aqui tu codigo para el perimetro del rectangulo
                perimetro = 0;
                cout << "El perimetro del rectangulo es: " << opcion << endl;
                break;
            case 2:
                cout << "Ingrese el valor de los lados: ";
                cin >> opcion;
                // Aqui tu codigo para el perimetro del triangulo
                perimetro = 0;
                cout << "El perimetro del triangulo es: " << opcion << endl;
                break;
            case 3:
                cout << "Ingrese el valor de la altura: ";
                cin >> opcion;
                // Aqui tu codigo para el perimetro del circulo
                perimetro = 0;
                cout << "El perimetro del circulo es: " << opcion << endl;
                break;
            case 4:
                cout << "Gracias por usar el programa" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
            break;
        case 3:
            cout << "Gracias por usar el programa" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 3);

    return 0;
}