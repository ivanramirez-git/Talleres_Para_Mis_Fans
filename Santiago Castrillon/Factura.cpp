#include <iostream> // cin, cout
#include <fstream> // ifstream, ofstream
#include <sstream> // stringstream
#include <string> // stoi
#define IVA 0.19
// Tamaño de arreglos
#define MAX_PRODUCTOS_FACTURA 10
#define MAX_PRODUCTOS_INVENTARIO 100
#define MAX_CLIENTES 100
#define MAX_FACTURAS 100
// Archivos
#define ARCHIVO_INVENTARIO "Productos.csv"
#define ARCHIVO_CLIENTES "Clientes.csv"

using namespace std;

struct Producto {
    int codigo;
    string concepto;
    float precio;
    int cantidad;
};

struct Cliente{
    string nombre;
    string nif;
    string domicilio;
    string pago;
};

struct Factura {
    int numero;
    string fecha;
    Cliente cliente;
    Producto productos[MAX_PRODUCTOS_FACTURA];
    int numero_productos;
    float porcentaje_descuento;
};

struct Sistema{
    Producto inventario[MAX_PRODUCTOS_INVENTARIO];
    int numero_productos_inventario;
    Cliente clientes[MAX_CLIENTES];
    int numero_clientes;
};

// Cargar Sistema

