#include <iostream>
#include <cstring>

#define TAMANIO 100
#define PALABRA_MAXIMA 20
#define LUGARES_MATERIAS 2

using namespace std;

int buscarMateria(char materias[TAMANIO][LUGARES_MATERIAS][PALABRA_MAXIMA], int tam)
{
    int i;
    char materia[PALABRA_MAXIMA];
    cout << "Ingrese la materia a buscar: ";
    cin >> materia;
    int tamano = strlen(materia);
    for (i = 0; i < tam; i++)
    {

        bool valido = true;
        for (int j = 0; j < tamano && valido; j++)
        {
            if (materia[j] != materias[i][0][j])
            {
                valido = false;
            }
        }
        if (valido)
        {
            return i;
        }
    }
    return -1;
}

int buscarMateria(char materias[TAMANIO][LUGARES_MATERIAS][PALABRA_MAXIMA], int tam, char materia[PALABRA_MAXIMA])
{
    int i;
    for (i = 0; i < tam; i++)
    {
        if (strcmp(materias[i][0], materia) == 0)
        {
            return i;
        }
    }
    return -1;
}

void imprimirMateria(char materias[TAMANIO][LUGARES_MATERIAS][PALABRA_MAXIMA], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        cout << "Materia: " << materias[i][0] << endl;
        cout << "Requisito: " << materias[i][1] << endl;
    }
}

int main()
{

    /*
    1004 Fisica 2
        Requisito
            1003 Fisica 1
                Requisito
                    1002 Matematica 1
                        Requisito
                            1001 Fundamentos
                                Requisito
                                    -
    */
    char materias[TAMANIO][LUGARES_MATERIAS][PALABRA_MAXIMA];
    int tam = 0;

    strcpy(materias[0][0], "1001 Fundamentos");
    strcpy(materias[0][1], "-");
    tam++;

    strcpy(materias[1][0], "1002 Matematica 1");
    strcpy(materias[1][1], "1001 Fundamentos");
    tam++;

    strcpy(materias[2][0], "1003 Fisica 1");
    strcpy(materias[2][1], "1002 Matematica 1");
    tam++;

    strcpy(materias[3][0], "1004 Fisica 2");
    strcpy(materias[3][1], "1003 Fisica 1");
    tam++;

    // Buscar en materias por codigo e imprimir la lista de requisitos
    // Buscar si existe una materia con el codigo 1001
    // Si existe, imprimir la lista de requisitos
    // Si no existe, imprimir que no existe

    int posicion = buscarMateria(materias, tam);
    if (posicion != -1)
    {
        char palabraSiguiente[PALABRA_MAXIMA];
        int tabs = 0;
        cout << "La materia " << materias[posicion][0] << " tiene los siguientes requisitos: " << endl;
        while (strcmp(materias[posicion][1], "-") != 0)
        {
            cout << endl;
            strcpy(palabraSiguiente, materias[posicion][1]);
            for (int i = 0; i < tabs; i++)
            {
                cout << "\t";
            }
            cout << palabraSiguiente;
            posicion = buscarMateria(materias, tam, palabraSiguiente);
            tabs++;
        }
        cout << "\nFin de la lista de requisitos" << endl;
    }
    else
    {
        cout << "La materia no existe" << endl;
    }

    // Imprimir todas las materias
    cout << endl;
    cout << "Lista de materias: " << endl;
    imprimirMateria(materias, tam);

    return 0;
}
