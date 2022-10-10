// Elaborar una factura electronica que solicite los datos del cluente como nombre RUC y direccion; luego los datos de los articulos a comprar tanto cantidad, la descripcion del articulo o producto y el precio unitario puede ingresar hasta 10 articulos, al final calcular el total, el IGV(18%) y el total a pagar.
//
// Pintar el texto de la consola en verde
#include <iostream>
#include <cstring>
#include <time.h>
#define VERDE "\033[32m"
#define RESET "\033[0m"
using namespace std;

// cliente
void pedirDatosCliente(char *nombre, char *ruc, char *direccion);

// articulos
void pedirDatosArticulos(int &cantidad, char *descripcion, float &precio);

// mostrar datos
/*
FACTURA Nro 000-1
===============================================================
EMPRESA: www.cisco-cursos.com S.A.C          FECHA : 30/03/2022
CLIENTE: Juan Perez                          RUC : 123456789123
DIRECCION: Av. Los Incas 123
===============================================================
CANTIDAD    DESCRIPCION                PRE. UNIT.    PRE. TOTAL
===============================================================

20         Mouse                    $  20.00          $   400.00
10         Teclado                  $  30.00          $   300.00
5          Monitor                  $  500.00         $  2500.00
2          CPU                      $  1000.00        $  2000.00
================================================================
                                                        $  5200.00
                                    IMPUESTO IGV. 18%  $   936.00
                                    -----------------------------
                                    TOTAL A PAGAR      $  6136.00
*/
void mostrarDatosCliente(char *nombre, char *ruc, char *direccion, int cantidades[], char descripciones[][100], float precios[], float total, float igv, float totalPagar, int nrofactura, int cantidadArticulos);
int main()
{

    // datps del cliente
    char nombre[100];
    char ruc[100];
    char direccion[100];

    // datos de los articulos pedir hasta que llegue a 10 o hasta que el usuario diga que no quiere ingresar mas
    int cantidad;
    char descripcion[100];
    float precio;
    int cantidades[10];
    char descripciones[10][100];
    float precios[10];
    int nroArticulos = 0;
    char respuesta;
    pedirDatosCliente(nombre, ruc, direccion);
    do
    {
        pedirDatosArticulos(cantidad, descripcion, precio);
        cantidades[nroArticulos] = cantidad;
        strcpy(descripciones[nroArticulos], descripcion);
        precios[nroArticulos] = precio;
        nroArticulos++;
        cout << "Desea ingresar otro articulo? (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's' && nroArticulos < 10);

    // calcular el total, el IGV y el total a pagar
    float total = 0;
    for (int i = 0; i < nroArticulos; i++)
    {
        total += cantidades[i] * precios[i];
    }
    float igv = total * 0.18;
    float totalPagar = total + igv;

    // mostrar los datos
    mostrarDatosCliente(nombre, ruc, direccion, cantidades, descripciones, precios, total, igv, totalPagar, 1, nroArticulos);

    return 0;
}

void pedirDatosCliente(char *nombre, char *ruc, char *direccion)
{
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombre;
    cout << "Ingrese el RUC del cliente: ";
    cin >> ruc;
    cout << "Ingrese la direccion del cliente: ";
    cin >> direccion;
}

void pedirDatosArticulos(int &cantidad, char *descripcion, float &precio)
{
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;
    cout << "Ingrese la descripcion: ";
    cin >> descripcion;
    cout << "Ingrese el precio: ";
    cin >> precio;
}

void mostrarDatosCliente(char *nombre, char *ruc, char *direccion, int cantidades[], char descripciones[][100], float precios[], float total, float igv, float totalPagar, int nrofactura, int cantidadArticulos)
{
    cout << VERDE << "FACTURA Nro " << nrofactura << RESET << endl;
    cout << "==============================================================" << endl;
    cout << "EMPRESA: www.cisco-cursos.com S.A.C          FECHA : ";
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    cout << tm.tm_mday << "/" << tm.tm_mon + 1 << "/" << tm.tm_year + 1900 << endl;
    cout << "CLIENTE: " << nombre << "                          RUC : " << ruc << endl;
    cout << "DIRECCION: " << direccion << endl;
    cout << "==============================================================" << endl;
    cout << "CANTIDAD    DESCRIPCION                PRE. UNIT.    PRE. TOTAL" << endl;
    cout << "==============================================================" << endl;
    for (int i = 0; i < cantidadArticulos; i++)
    {
        cout << cantidades[i] << "         " << descripciones[i] << "                    $  " << precios[i] << "          $   " << cantidades[i] * precios[i] << endl;
    }
    cout << "================================================================" << endl;
    cout << "                                                        $  " << total << endl;
    cout << "                                    IMPUESTO IGV. 18%  $   " << igv << endl;
    cout << "                                    -----------------------------" << endl;
    cout << "                                    TOTAL A PAGAR      $  " << totalPagar << endl;
}
