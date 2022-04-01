/*
Un programa que muestra en pantalla los recursos que usa RAM y Procesador, al ejecutar una funcion de ornato.
*/
#include <iostream> //Libreria de entrada y salida
#include <windows.h> //Para obtener el tiempo de ejecucion
#include <psapi.h> // Libreria para obtener el uso de memoria RAM y Procesador
// Incluir libreria para GetProcessMemoryInfo
//#pragma comment(lib, "psapi.lib")


using namespace std;

// Algoritmo de ordenamiento de burbuja
void burbuja(int *a, int n)
{
    int i, j, aux;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}
// Funcion que retorna aleatorios entre 1 y 30000
int aleatorio()
{
    return rand() % 30000 + 1;
}

// Funcion que muestra el uso de memoria RAM y Procesador
void recursos()
{
    // Declaracion de variables
    int i, j, n = 5000;
    int a[n];
    double tiempo;
    DWORD tiempo_inicial, tiempo_final;
    PROCESS_MEMORY_COUNTERS memoria;
    HANDLE hProceso = GetCurrentProcess();

    // Reserva de memoria
    a = new int[n];

    // Inicializacion de memoria con numeros aleatorios no repetidos
    for (i = 0; i < n; i++)
    {
        // Validar que no se repita el numero
        do
        {
            a[i] = aleatorio();
        } while (i > 0 && a[i] == a[i - 1]);
    }    

    // Obtencion de tiempo de ejecucion
    tiempo_inicial = GetTickCount();

    // Ordenamiento de memoria
    burbuja(a, n);

    // Obtencion de tiempo de ejecucion
    tiempo_final = GetTickCount();
    tiempo = (tiempo_final - tiempo_inicial);

    // Obtencion de uso de memoria RAM y Procesador final
    GetProcessMemoryInfo(hProceso, &memoria, sizeof(memoria));

    // Impresion de resultados
    cout << "Tiempo de ejecucion: " << tiempo << " milisegundos" << endl;
    cout << "Uso de memoria RAM: " << memoria.WorkingSetSize / 1024 << " Kb" << endl;
    cout << "Uso de memoria Procesador: " << memoria.PeakWorkingSetSize / 1024 << " Kb" << endl;
    

    // Cerrar el handle del proceso
    CloseHandle(hProceso);

    // Imprimir arreglo ordenado
    //for (i = 0; i < n; i++)
    //    cout << a[i] << " " <<endl;

    // Liberar memoria
    delete[] a;
}

// Funcion principal
int main()
{
    recursos();
    return 0;
}
