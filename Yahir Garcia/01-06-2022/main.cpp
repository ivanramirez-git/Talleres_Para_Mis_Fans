#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct alumno
{
    string nombre;
    int semestre;
};

int aleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    srand(time(NULL));
    // generar matriz bidimencional NxM ramgo de 1 a 50
    int N, M;
    do{
        cout << "Ingrese el numero de filas: ";
        cin >> N;
    }while(N < 1 || N > 50);
    do{
        cout << "Ingrese el numero de columnas: ";
        cin >> M;
    }while(M < 1 || M > 50);
    int matriz[N][M];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            matriz[i][j] = aleatorio(1, 50);
        }
    }

    // Imprimir matriz
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // si la suma de la diagonal principal es par entonces genera una estructura alumno, si no, genera un archivo de texto "archivo.txt" con la palabra "Hola"
    int suma = 0;
    int min = N < M ? N : M;
    cout << "La suma de la diagonal principal es: ";
    for(int i = 0; i < min; i++)
    {
        if(i < min-1)
        {
            cout << matriz[i][i] << " + ";
        }
        suma += matriz[i][i];
    }
    cout << matriz[min-1][min-1] << " = " << suma << endl;

    if(suma % 2 == 0)
    {
        cout << "La suma de la diagonal principal es par" << endl;
        alumno estudiante;
        estudiante.nombre = "Fernando Yahir Garcia Davila";
        estudiante.semestre = 2;
        cout << "{\n\tNombre: " << estudiante.nombre << "\n\tSemestre: " << estudiante.semestre << "\n}" << endl;
    }
    else
    {
        cout << "La suma de la diagonal principal es impar" << endl;
        ofstream archivo;
        archivo.open("archivo.txt");
        if(archivo.is_open())
        {
            archivo << "Hola";
            archivo.close();
        }
        else
        {
            cout << "No se pudo generar el archivo" << endl;
        }

        // Leer el archivo "archivo.txt" y mostrar su contenido
        ifstream leer;
        leer.open("archivo.txt");
        if(leer.is_open())
        {
            cout << "archivo.txt: " << endl;
            string contenido;
            while(getline(leer, contenido))
            {
                cout << "\t" << contenido << endl;
            }
            leer.close();
        }
        else
        {
            cout << "No se pudo leer el archivo" << endl;
        }
        
    }
}