#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <time.h>

using namespace std;
int main(void)
{
    // algoritmo que sea un temporizador
    int horas, minutos, segundos;
    cout << "Ingrese la hora: ";
    cin >> horas;
    cout << "Ingrese el minuto: ";
    cin >> minutos;
    cout << "Ingrese el segundo: ";
    cin >> segundos;

    // hh:mm:ss hasta que llegue a 00:00:00
    while (horas != 0 || minutos != 0 || segundos != 0) {
        // mostrar la hora
        printf("%02d:%02d:%02d \r", horas, minutos, segundos);
        fflush(stdout);
        sleep(1);
        // decrementar el tiempo
        segundos--;
        if (segundos < 0) {
            segundos = 59;
            minutos--;
            if (minutos < 0) {
                minutos = 59;
                horas--;
            }
        }
    }
    return 0;
}