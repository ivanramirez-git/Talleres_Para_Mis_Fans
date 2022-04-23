#include <iostream>
#include <fstream>
#include <math.h>
#define MAX_LENGTH 100

using namespace std;

// Funcion que convierte un string en un int
int stringToInt(string s) {
    int i = 0;
    int num = 0;
    while (s[i] != '\0') {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return num;
}

// Funcion que lee de un archivo de texto con numeros enteros
/* Ejemplo de archivo: Datos.txt
    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
*/
int cargarDatos(int datos[], int &n, char nombreArchivo[]) {
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }
    int i = 0;
    while (!feof(archivo)) {
        fscanf(archivo, "%d", &datos[i]);
        i++;
    }
    n = i;
    fclose(archivo);
    // retorna el numero de datos leidos
    return n;    
}
        

void guardarDatos(int datos[], int n, char nombreArchivo[]) {
    FILE *archivo;
    archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(archivo, "%d", datos[i]);
        if (i != n - 1) {
            fprintf(archivo, "\n");
        }
    }
    fclose(archivo);
}

void crearArchivo(char nombreArchivo[]) {
    FILE *archivo;
    archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    fclose(archivo);
}

// Funcion que calcula el la media aritmetica de un arreglo de numeros enteros y muestra el resultado
float mediaAritmetica(int datos[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += datos[i];
    }
    cout << "La media aritmetica es: " << (suma+0.0) / (n+0.0) << endl;
    return (suma+0.0) / (n+0.0);
}

// Funcion que calcula el la media armonica de un arreglo de numeros enteros y muestra el resultado
void mediaArmonica(int datos[], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma = suma + (1.0 / (datos[i] + 0.0));
    }
    float media = (0.0+n) / (0.0+suma);
    cout << "La media armonica es: " << media << endl;
}

// Funcion que calcula el la media geometrica de un arreglo de numeros enteros y muestra el resultado
void mediaGeometrica(int datos[], int n) {
    int mult = 1;
    for (int i = 0; i < n; i++) {
        mult = mult * datos[i];
    }
    cout << "La media geometrica es: " << pow(mult, 1.0/n) << endl;
}

// Funcion que calcula la mediana y muestra el resultado
void mediana(int datos[], int n) {
    int mediana;
    if (n % 2 == 0) {
        mediana = (datos[n / 2] + datos[n / 2 - 1]) / 2;
    } else {
        mediana = datos[n / 2];
    }
    cout << "La mediana es: " << mediana << endl;
}

// Funcion que calcula la moda y muestra el resultado
void moda(int datos[], int n) {
    int moda = datos[0];
    int contador = 1;
    for (int i = 1; i < n; i++) {
        if (datos[i] == datos[i - 1]) {
            contador++;
        } else {
            if (contador > 1) {
                if (contador > contador) {
                    moda = datos[i - 1];
                    contador = 1;
                }
            } else {
                contador = 1;
            }
        }
    }
    cout << "La moda es: " << moda << endl;
}

// Funcion que calcula la varianza y muestra el resultado
void varianza(int datos[], int n) {
    float suma = 0;
    float media = mediaAritmetica(datos, n);
    for (int i = 0; i < n; i++) {
        suma += pow((datos[i] - media), 2);
    }
    cout << "La varianza es: " << (suma+0.0) / (n+0.0) << endl;

}

// Funcion que calcula la desviacion estandar y muestra el resultado
void desviacionEstandar(int datos[], int n) {
    float suma = 0;
    float media = mediaAritmetica(datos, n);
    for (int i = 0; i < n; i++) {
        suma += pow((datos[i] - media), 2);
    }
    cout << "La desviacion estandar es: " << sqrt((suma+0.0) / (n+0.0)) << endl;
}

// Menu principal
void menu() {
    cout << "1. Nuevo ( Crea un nuevo archivo )" << endl;
    cout << "2. Cargar ( para leer los datos del archivo y cargar el vector )" << endl;
    cout << "3. Agregar datos ( para Agregar datos al vector )" << endl;
    cout << "4. Guardar ( para guardar los datos del Vector al Archivo )" << endl;
    cout << "5. Mostrar Datos ( Muestra los Datos del Vector )" << endl;
    cout << "6. Mostrar Resultados ( Muestrar los calculos estadisticos )" << endl;
    cout << "7. Salir ( Finalizar el programa )" << endl;
}

// Funcion que muestra los datos del vector
void mostrarDatos(int datos[], int n) {
    for (int i = 0; i < n; i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
}

// Funcion que muestra los resultados de los calculos estadisticos
void mostrarResultados(int datos[], int n) {
    mediaAritmetica(datos, n);
    mediaArmonica(datos, n);
    mediaGeometrica(datos, n);
    mediana(datos, n);
    moda(datos, n);
    varianza(datos, n);
    desviacionEstandar(datos, n);
}

// Main
int main() {
    int datos[MAX_LENGTH];
    int n = 0;
    char nombreArchivo[MAX_LENGTH];
    int opcion;
    do {
        menu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del archivo: ";
                cin >> nombreArchivo;
                crearArchivo(nombreArchivo);
                break;
            case 2:
                cout << "Ingrese el nombre del archivo: ";
                cin >> nombreArchivo;
                n = cargarDatos(datos, n, nombreArchivo);
                cout << "Cantidad de datos: " << n << endl;
                break;
            case 3:
                cout << "Ingrese el dato a agregar: ";
                cin >> datos[n];
                n++;
                break;
            case 4:
                cout << "Ingrese el nombre del archivo: ";
                cin >> nombreArchivo;
                guardarDatos(datos, n, nombreArchivo);
                break;
            case 5:
                mostrarDatos(datos, n);
                break;
            case 6:
                mostrarResultados(datos, n);
                break;
            case 7:
                cout << "Gracias por usar el programa" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while (opcion != 7);
    return 0;
}

    