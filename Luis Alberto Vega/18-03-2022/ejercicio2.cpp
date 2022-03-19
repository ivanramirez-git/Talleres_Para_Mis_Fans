#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

#define MAX 100
#define IVA 0.13

using namespace std;

// stoi
int stoint(string s) {
    int i = 0;
    int n = 0;
    while (s[i] != '\0') {
        n = n * 10 + (s[i] - '0');
        i++;
    }
    return n;
}

// stof
float stofloat(string s) {
    int i = 0;
    float n = 0;
    while (s[i] != '\0') {
        n = n * 10 + (s[i] - '0');
        i++;
    }
    return n;
}

struct Venta
{
    // Para cada venta que se realice o se ejecute el ciclo deberá leer los siguientes datos: cedula y nombre del comprador, localidad (es un campo donde deberá indicar la localidad deseada, según lo siguiente:  1- Sol Norte/Sur   2- Sombra Este/Oeste   3-Plateas Este/Oeste), cantidad de entradas (el campo debe estar validado, 1 cliente solo puede comprar como máximo cuatro entradas).
    int cedula;          // cedula del cliente
    string nombre;       // Nombre del cliente
    int localidad;       // 1- Sol Norte/Sur   2- Sombra Este/Oeste   3-Plateas Este/Oeste
    int cantidad;        // el campo debe estar validado, 1 cliente solo puede comprar como máximo cuatro entradas.
    void imprimir();     // imprime los datos de la venta
    string ventaTexto(); // devuelve un string con los datos de la venta
};

// Funciones
// imprime los datos de la venta
void Venta::imprimir()
{
    cout << "Venta = { " << cedula << ", " << nombre << ", " << localidad << ", " << cantidad << " }";
}

// devuelve un string con los datos de la venta
string Venta::ventaTexto()
{
    string texto = "Venta = { " + to_string(cedula) + ", " + nombre + ", " + to_string(localidad) + ", " + to_string(cantidad) + " }";
    return texto;
}

struct Factura
{
    // El sistema deberá procesar el número de factura (auto numérico), el precio por entrada y el nombre de la localidad, en base a lo siguiente:
    /*
        •	Si la localidad es 1 (Sol Norte/Sur) el precio por entrada será de 3000 colones y el nombre de la localidad será “Sol Norte/Sur”.

        •	Si la localidad es 2 (Sombra Este/Oeste) el precio por entrada será de 5000 colones y el nombre de la localidad será “Sombra Este/Oeste”.

        •	Si la localidad es 3  (3-Plateas Este/Oeste) el precio por entrada será de 9000 colones y el nombre de la localidad será “Plateas Este/Oeste”
    */
    int numeroFactura; // auto numérico de 4 digitos
    Venta venta;       // Para cada venta que se realice o se ejecute el ciclo deberá leer los siguientes datos: cedula y nombre del comprador, localidad (es un campo donde deberá indicar la localidad deseada, según lo siguiente:  1- Sol Norte/Sur   2- Sombra Este/Oeste   3-Plateas Este/Oeste), cantidad de entradas (el campo debe estar validado, 1 cliente solo puede comprar como máximo cuatro entradas).
    double precio();   // precio por entrada: 3000 colones, 5000 colones, 9000 colones
    double subtotal(); // subtotal
    double iva();      // iva
    double total();    // total
    void imprimir();   // imprime la factura

    // Sistema de control de ventas de entradas para un partido de futbol
    /*
        Datos:  Domingo 1 de mayo de del 2021 a las 5:00 p.m., frente al equipo de Liga Deportiva Alajuelense, juego valido por el torneo local de la Primera División de Fútbol de C.R. organizado por la Unafut, a realizar en el Estadio Ricardo Saprissa.
    */
    void imprimirFacturaBonita();
};

// Funciones
// precio por entrada: 3000 colones, 5000 colones, 9000 colones
double Factura::precio()
{
    if (venta.localidad == 1)
    {
        return 3000;
    }
    else if (venta.localidad == 2)
    {
        return 5000;
    }
    else
    {
        return 9000;
    }
}

// subtotal
double Factura::subtotal()
{
    return venta.cantidad * precio();
}

// iva
double Factura::iva()
{
    return subtotal() * IVA;
}

// total
double Factura::total()
{
    return subtotal() + iva();
}

// imprime la factura
void Factura::imprimir()
{
    cout << "Factura = { " << numeroFactura << ", " << venta.ventaTexto() << ", precio = " << precio() << ", subtotal = " << subtotal() << ", iva = " << iva() << ", total = " << total() << " }";
}

// imprime la factura bonita
void Factura::imprimirFacturaBonita()
{
    cout << endl;
    cout << ".:: FACTURA DE VENTA DE ENTRADAS ::." << endl;
    cout << "Fecha del evento: "
         << "Domingo 1 de mayo de del 2021 a las 5:00 p.m." << endl;
    cout << "Lugar del evento: "
         << "Estadio Ricardo Saprissa." << endl;
    cout << "Evento: "
         << "Partido de Futbol para Deportivo Saprissa vs Liga Deportiva Alajuelense." << endl;
    cout << "Descripcion: "
         << "Juego valido por el torneo local de la Primera División de Futbol de C.R." << endl;
    cout << "Organizador: "
         << "Unafut." << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << endl;
    cout << "Numero de factura: " << numeroFactura << endl;
    cout << "Cedula del cliente: " << venta.cedula << endl;
    cout << "Nombre del cliente: " << venta.nombre << endl;
    if (venta.localidad == 1)
    {
        cout << "Localidad: "
             << "Sol Norte/Sur" << endl;
    }
    else if (venta.localidad == 2)
    {
        cout << "Localidad: "
             << "Sombra Este/Oeste" << endl;
    }
    else
    {
        cout << "Localidad: "
             << "Plateas Este/Oeste" << endl;
    }
    cout << "Cantidad de entradas: " << venta.cantidad << endl;
    cout << "Precio por entrada: " << precio() << endl;
    cout << "Subtotal: " << subtotal() << endl;
    cout << "Iva: " << iva() << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "Total: " << total() << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << endl;
}

// Sistema de control de ventas de entradas para un partido de futbol
void bienvenida()
{
    cout << ".:: Bienvenido al sistema de control de ventas de entradas para un partido de futbol ::." << endl;
}

// aleatorio
int aleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Funciones para validaciones
// leer un entero
int leerEntero(int min, int max)
{
    string linea;
    int numeroIntentos = 0;
    int numero;
    bool error = true;
    while (error)
    {
        cin >> linea;
        error = false;
        try
        {
            numero = stoint(linea);
            if (numero < min || numero > max)
            {
                error = true;
            }
        }
        catch (exception)
        {
            error = true;
        }

        if (numeroIntentos > 1 && error)
        {
            cout << "Error: El numero debe estar entre " << min << " y " << max << ". Intente de nuevo: ";
        }
        numeroIntentos++;
    }
    return numero;
}

// leer un flotante
float leerFlotante(float min, float max)
{
    string linea;
    int numeroIntentos = 0;
    float numero;
    bool error = true;
    while (error)
    {
        cin >> linea;
        error = false;
        try
        {
            numero = stofloat(linea);
            if (numero < min || numero > max)
            {
                error = true;
            }
        }
        catch (exception)
        {
            error = true;
        }
        if (numeroIntentos > 1 && error)
        {
            cout << "Error: El numero debe estar entre " << min << " y " << max << ". Intente de nuevo: ";
        }
        numeroIntentos++;
    }
    return numero;
}

// leer cadena
string leerCadena()
{
    string linea;
    cin >> linea;
    return linea;
}

// generar numero de factura
int generarNumeroFactura(vector<Factura> facturas)
{
    while (true)
    {
        int numero = aleatorio(1, 100000);
        bool existe = false;
        for (int i = 0; i < facturas.size(); i++)
        {
            if (facturas[i].numeroFactura == numero)
            {
                existe = true;
            }
        }
        if (!existe)
        {
            return numero;
        }
    }
}

// registrar venta
void registrarVenta(vector<Factura> &facturas)
{
    Venta venta;
    cout << "Registrar Venta" << endl;
    cout << "Cedula: ";
    venta.cedula = leerEntero(1, 1000000);
    cout << "Nombre: ";
    venta.nombre = leerCadena();
    cout << "Localidad: ";
    venta.localidad = leerEntero(1, 3);
    cout << "Cantidad: ";
    venta.cantidad = leerEntero(1, 4);
    Factura factura;
    factura.venta = venta;
    factura.numeroFactura = generarNumeroFactura(facturas);
    facturas.push_back(factura);
    cout << "Factura registrada con exito" << endl;
}

// Listar ventas
void listarVentas(vector<Factura> facturas)
{
    cout << "Listar Ventas" << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    for (int i = 0; i < facturas.size(); i++)
    {
        facturas[i].imprimir();
        cout << endl;
    }
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
}

// Indice de facturas
void indiceFacturas(vector<Factura> facturas)
{
    cout << "Indice de facturas" << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    for (int i = 0; i < facturas.size(); i++)
    {
        cout << i << ". Factura " << facturas[i].numeroFactura << ": " << facturas[i].venta.nombre << endl;
    }
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
}

// Estadisticas
void estadisticas(vector<Factura> facturas)
{
    int solNorte = 0;
    float solNorteDinero = 0;

    int sombraEste = 0;
    float sombraEsteDinero = 0;

    int plateaEste = 0;
    float plateaEsteDinero = 0;

    int totalEntradas = 0;
    float totalDinero = 0;
    float promedioDinero = 0;

    for (int i = 0; i < facturas.size(); i++)
    {
        if (facturas[i].venta.localidad == 1)
        {
            solNorte += facturas[i].venta.cantidad;
            solNorteDinero += facturas[i].venta.cantidad * facturas[i].total();
        }
        else if (facturas[i].venta.localidad == 2)
        {
            sombraEste += facturas[i].venta.cantidad;
            sombraEsteDinero += facturas[i].venta.cantidad * facturas[i].total();
        }
        else
        {
            plateaEste += facturas[i].venta.cantidad;
            plateaEsteDinero += facturas[i].venta.cantidad * facturas[i].total();
        }
        totalEntradas += facturas[i].venta.cantidad;
        totalDinero += facturas[i].total();
    }
    promedioDinero = totalDinero / facturas.size();
    cout << "Estadisticas" << endl;
    cout << "Cantidad Entradas Localidad Sol Norte/Sur: " << solNorte << endl;
    cout << "Acumulado Dinero Localidad Sol Norte/Sur: " << solNorteDinero << endl;
    cout << endl;
    cout << "Cantidad Entradas Localidad Sombra Este/Oeste: " << sombraEste << endl;
    cout << "Acumulado Dinero Localidad Sombra Este/Oeste: " << sombraEsteDinero << endl;
    cout << endl;
    cout << "Cantidad Entradas Localidad Platea Este/Oeste: " << plateaEste << endl;
    cout << "Acumulado Dinero Localidad Platea Este/Oeste: " << plateaEsteDinero << endl;
    cout << endl;
    cout << "Cantidad Total de entradas vendidas: " << totalEntradas << endl;
    cout << "Acumulado Dinero del total de entradas vendidas: " << totalDinero << endl;
    cout << "Promedio de dinero del total de entradas vendidas: " << promedioDinero << endl;
    cout << endl;
}

// menu
void menu()
{
    cout << "1. Registrar venta" << endl;
    cout << "2. Listar ventas" << endl;
    cout << "3. Buscar factura" << endl;
    cout << "4. Ver estadisticas" << endl;
    cout << "0. Salir" << endl;
}

// Pruebas
void prueba1()
{
    cout << endl;
    bienvenida();
    cout << endl;
    int opcion = -1;
    vector<Factura> facturas;
    while (opcion != 0)
    {
        menu();
        opcion = leerEntero(0, 4);
        switch (opcion)
        {
        case 1:
            registrarVenta(facturas);
            break;
        case 2:
            listarVentas(facturas);
            break;
        case 3:
            indiceFacturas(facturas);
            cout << "Ingrese el numero de factura a buscar: ";
            opcion = leerEntero(0, facturas.size() - 1);
            facturas[opcion].imprimirFacturaBonita();
            opcion = 3;
            break;
        case 4:
            estadisticas(facturas);
            break;
        case 0:
            break;
        }
    }
}

// Main
int main()
{
    prueba1();
    return 0;
}