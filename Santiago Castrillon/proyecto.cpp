#include <iostream>
#include <fstream>
#include <string>
// Tamaño de arreglos
#define MAX_PRODUCTOS_FACTURA 10
#define MAX_PRODUCTOS_INVENTARIO 100
#define MAX_CLIENTES 100
#define MAX_FACTURAS 100
// Nombres de archivos
#define ARCHIVO_INVENTARIO "Productos.csv"
#define ARCHIVO_CLIENTES "Clientes.csv"
#define ARCHIVO_FACTURAS "Facturas.csv"
// El nombre de un folio es el "F"+número de factura+"-"+número de cliente+".csv", se guarda en la ruta "./folios/"
#define ARCHIVO_FOLIOS "./folios/"
// Constantes
#define IVA 0.19

using namespace std;

/*

1.	Solo se puede vender productos que estén en el inventario.
2.	Si vendo 1 unidad  del  “producto 9” en el inventario la cantidad queda en 100.
3.	Del “producto 10” no se puede vender 3 artículos.
4.	Sistema de menú
5.	llenar y mostrar factura
6.	Generar factura de venta (verificar, esta seguro)
7.	Buscar factura por número
8.	Posibilidad de 100 facturas  (ingresar 5 mínimo)
9.	Listado de clientes
10.	ingresar cliente domicilio cedula nombre
11.	Eliminar Cliente 
12.	Visualizar las facturas por código 
13.	Visualizar la factura de mayor valor 
14.	Modificar el inventario
15.	Agregar producto (verificar que no este repetido por código) 
16.	Eliminar producto
17.	Cambiar información de un producto
18.	Listar 
19.	Buscar producto por su ID o Nombre (mostrar todos sus campos)
20.	Por cada factura que sea generada, se actualice directamente el inventario

*/


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
    Factura facturas[MAX_FACTURAS];
    int numero_facturas;
};


/*

ARCHIVO_INVENTARIO

CODIGO;DESCRIPCION;PRECIO UNITARIO;CANTIDAD
1001;Arroz;574;197
1002;Leche;680;123
1003;Carne;1250;100
1004;Pollo;1450;100
1005;Papa;100;300
1006;Tomate;50;500
1007;Cebolla;60;500
1008;Aceite;750;100
1009;Sal;50;500
1010;Azucar;100;200
1011;Manteca;100;200
1012;Harina;100;200
1013;Aceite de oliva;1100;200
1014;Aceite de maiz;700;200
1015;Aceite de girasol;600;200
1016;Aceite de coco;800;200
1017;Aceitunas;100;200
1018;Mix de frutas;1200;200
1019;Mix de verduras;800;200

*/


/*

ARCHIVO_CLIENTES

NOMBRE;NIF;DOMICILIO;PAGO
Juan;99001;Calle falsa 123;Efectivo
Pedro;99002;Calle falsa 123;Tarjeta
Maria;99003;Calle falsa 123;Efectivo

*/

/*

ARCHIVO_FACTURAS

// Descuento es un porcentaje
NUMERO;FECHA;CLIENTE_CODIGO;FOLIO_FACTURA;DESCUENTO

*/

/*

FOLIOS

CODIGO;CONCEPTO;PRECIO;CANTIDAD

*/

//Variable global del sistema
Sistema sistema;

// Funciones de cargado y guardado de archivos
void cargar_inventario();
void cargar_clientes();
void cargar_facturas();
void cargar_folios();
void guardar_inventario();
void guardar_clientes();
void guardar_facturas();
void guardar_folios();

// Funciones de manejo de inventario
void agregar_producto_inventario(Producto producto);
void eliminar_producto_inventario(int codigo);
void modificar_producto_inventario(Producto producto);
void listar_productos_inventario();
void ordenar_productos_inventario();
void buscar_producto_inventario(int codigo);

// Funciones de manejo de clientes
void agregar_cliente(Cliente cliente);
void eliminar_cliente(int codigo);
void modificar_cliente(Cliente cliente);
void listar_clientes();
void buscar_cliente(int codigo);

// Funciones de manejo de facturas
void agregar_factura(Factura factura);
void eliminar_factura(int numero);
void modificar_factura(Factura factura);
void listar_facturas();
void buscar_factura(int numero);

// Funciones de manejo de folios
void agregar_folio(Factura factura);
void eliminar_folio(int numero);
void modificar_folio(Factura factura);
void listar_folios();
void buscar_folio(int numero);

// Generador de codigos y nombres
int generar_codigo_factura();
string generar_nombre_folio(int numero_factura);

// Funciones de menu

/*cout << "1. Agregar producto al inventario" << endl;
        cout << "2. Eliminar producto del inventario" << endl;
        cout << "3. Modificar producto del inventario" << endl;
        cout << "4. Listar productos del inventario" << endl;
        cout << "5. Ordenar productos del inventario" << endl;
        cout << "6. Buscar producto del inventario" << endl;
        cout << "7. Agregar cliente" << endl;
        cout << "8. Eliminar cliente" << endl;
        cout << "9. Modificar cliente" << endl;
        cout << "10. Listar clientes" << endl;
        cout << "11. Buscar cliente" << endl;
        cout << "12. Agregar factura" << endl;
        cout << "13. Eliminar factura" << endl;
        cout << "14. Modificar factura" << endl;
        cout << "15. Listar facturas" << endl;
        cout << "16. Buscar factura" << endl;
        cout << "17. Agregar folio" << endl;
        cout << "18. Eliminar folio" << endl;
        cout << "19. Modificar folio" << endl;
        cout << "20. Listar folios" << endl;
        cout << "21. Buscar folio" << endl;*/

void agre_prod_inv();
void elim_prod_inv();
void mod_prod_inv();
void list_prod_inv();
void ordenar_prod_inv();
void buscar_prod_inv();
void agre_cli();
void elim_cli();
void mod_cli();
void list_cli();
void buscar_cli();
void agre_fact();
void elim_fact();
void mod_fact();
void list_fact();
void buscar_fact();
void agre_folio();
void elim_folio();
void mod_folio();
void list_folio();
void buscar_folio();


// Programa principal
int main() {
    // Cargar los archivos
    cargar_inventario();
    cargar_clientes();
    cargar_facturas();

    // Menu
    int opcion;
    do {
        cout << "1. Agregar producto al inventario" << endl;
        cout << "2. Eliminar producto del inventario" << endl;
        cout << "3. Modificar producto del inventario" << endl;
        cout << "4. Listar productos del inventario" << endl;
        cout << "5. Ordenar productos del inventario" << endl;
        cout << "6. Buscar producto del inventario" << endl;
        cout << "7. Agregar cliente" << endl;
        cout << "8. Eliminar cliente" << endl;
        cout << "9. Modificar cliente" << endl;
        cout << "10. Listar clientes" << endl;
        cout << "11. Buscar cliente" << endl;
        cout << "12. Agregar factura" << endl;
        cout << "13. Eliminar factura" << endl;
        cout << "14. Modificar factura" << endl;
        cout << "15. Listar facturas" << endl;
        cout << "16. Buscar factura" << endl;
        cout << "17. Agregar folio" << endl;
        cout << "18. Eliminar folio" << endl;
        cout << "19. Modificar folio" << endl;
        cout << "20. Listar folios" << endl;
        cout << "21. Buscar folio" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1:
                agre_prod_inv();
                break;
            case 2:
                elim_prod_inv();
                break;
            case 3:
                mod_prod_inv();
                break;
            case 4:
                list_prod_inv();
                break;
            case 5:
                ordenar_prod_inv();
                break;
            case 6:
                buscar_prod_inv();
                break;
            case 7:
                agre_cli();
                break;
            case 8:
                elim_cli();
                break;
            case 9:
                mod_cli();
                break;
            case 10:
                list_cli();
                break;
            case 11:
                buscar_cli();
                break;
            case 12:
                agre_fact();
                break;
            case 13:
                elim_fact();
                break;
            case 14:
                mod_fact();
                break;
            case 15:
                list_fact();
                break;
            case 16:
                buscar_fact();
                break;
            case 17:
                agre_folio();
                break;
            case 18:
                elim_folio();
                break;
            case 19:
                mod_folio();
                break;
            case 20:
                list_folio();
                break;
            case 21:
                buscar_folio();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        cout << endl;
    } while (opcion != 0);

    // Guardar los archivos
    guardar_inventario();
    guardar_clientes();
    guardar_facturas();

    return 0;
}