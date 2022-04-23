#include <iostream>
#include <ctime>
using namespace std;

// Funciones

void Sleep(int milisegundos){
    clock_t tiempo_inicial = clock();
    while(clock() < tiempo_inicial + milisegundos);
}
// Funcion que al precionar en treclado la a Muestra en el borde de la consola una letra O mayuscula de color Azul
void A()
{
    // Escuchador de teclado
    char tecla;
    // Se lee la tecla
    cin >> tecla;
    // Limpia la consola
    system("cls");
    // Muestra la letra en el borde de la consola
    cout << "O" << endl;
    // while para que la O avance hasta el final de la consola
    int espacio = 0, aux = 80;
    while (espacio < aux)
    {
        Sleep(100);
        cout << "O" << endl;
        espacio++;
    }
}


// Prueba
int main()
{
    // Se llama a la funcion A
    A();
    // Se espera a que se presione una tecla
    cin.get();
    // Se regresa un 0
    return 0;
}
