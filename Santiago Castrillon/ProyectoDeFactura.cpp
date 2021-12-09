#include <iostream>
#include <fstream>
#include <ctime>

// Tamanos
#define MAX_LENGTH 100
#define MAX_PRODUCTS 10
#define IVA 0.19

// Archivos
#define FILE_NAME "productos.csv"
/*
productos.csv

CODIGO;PRODUCTO;PRECIO UNITARIO;CANTIDAD
1001;Producto 1;574.00;197
1002;Producto 2;944.00;93
1003;Producto 3;631.00;86
1004;Producto 4;932.00;90
1005;Producto 5;466.00;57
1006;Producto 6;902.00;122
1007;Producto 7;519.00;43
1008;Producto 8;359.00;122
1009;Producto 9;101.00;101
1010;Producto 10;102.00;2
1011;Producto 11;99.00;101
1012;Producto 12;98.00;3
1013;Producto 13;100.00;102
1014;Producto 14;10.00;110
1015;Producto 15;101.00;150

*/

using namespace std;

struct Cliente{
    string nombre;
    string nif;
    string domicilio;
    string pago;
};

struct Producto{
    int codigo;
    int cantidad;
    string concepto;
    float precio;
};

struct Inventario{
    Producto productos[MAX_LENGTH];
    int numeroProductos;
};

struct Factura {
    int numero;
    Cliente cliente;
    Producto productos[MAX_PRODUCTS];
    int numeroProductos;
    // Descuento es un porcentaje
    float descuento;
    string fecha;
};

struct Sistema{
    Inventario inventario;

    Factura facturas[MAX_LENGTH];
    int numeroFacturas;

    Cliente clientes[MAX_LENGTH];
    int numeroClientes;
};

// Funciones auxiliares 
// String a entero
int stringToInt(string str){
    int numero = 0;
    for (int i = 0; i < str.length(); i++)
    {
        numero = numero * 10 + (str[i] - '0');
    }
    return numero;
}

// String a float
float stringToFloat(string str){
    float numero = 0;
    int i = 0;
    while (str[i] != '.')
    {
        numero = numero * 10 + (str[i] - '0');
        i++;
    }
    i++;
    float decimal = 0;
    while (i < str.length())
    {
        decimal = decimal * 10 + (str[i] - '0');
        i++;
    }
    return numero + decimal / 100;
}

// Funciones del proyecto

// Cargar y Guardar inventario
void cargarInventario(Sistema &sistema);
// void guardarInventario(Inventario inventario);

// Ventas
void generarFactura(Sistema &sistema);
void agregarProductosFactura(Factura &factura, Inventario &inventario);

void mostrarFactura(Factura factura);
void mostrarInventario(Inventario inventario);

void modificarFactura(Sistema &sistema);
void modificarInventario(Sistema &sistema);

void eliminarFactura(Sistema &sistema);
void eliminarInventario(Sistema &sistema);

// Clientes
void agregarCliente(Sistema &sistema);
void mostrarCliente(Cliente cliente);
void modificarCliente(Sistema &sistema);
void eliminarCliente(Sistema &sistema);

// Prodcutos
void listarProductos(Inventario inventario);
int buscarProducto(Inventario inventario, int codigo);

// Facturas
void visualizarFactura(Factura factura);

// Devuelve el indice del cliente
int buscarCliente(Sistema &sistema, string nif);

// Consultas

// Buscar factura por numero
int buscarFacturaInt(Sistema sistema, int numero);
void buscarFactura(Sistema &sistema);

// Listar Clientes
void listarClientes(Sistema &sistema);

// Mostrar factura por codigo de producto
void mostrarFacturaPorProducto(Sistema &sistema);

// Visualizar facturas de menor a mayor precio
void visualizarFacturas(Sistema &sistema);

// Agregar producto al la factura, si no existe, lo agrega, si existe indica que no se puede agregar
// void agregarProducto(Sistema &sistema, int numeroFactura);

// Cambiar informacion de un producto
void cambiarProducto(Sistema &sistema, int numeroFactura, int numeroProducto);

// Listar facturas
void listarFacturas(Sistema &sistema);

// Datos de prueba
void datosDePrueba(Sistema &sistema){
    // Cargar inventario
    cargarInventario(sistema);

    // Cargar clientes
    sistema.numeroClientes = 0;
    Cliente cliente;
    cliente.nombre = "Juan Perez";
    cliente.nif = "12345678A";
    cliente.domicilio = "Calle falsa 123";
    cliente.pago = "Efectivo";
    sistema.clientes[sistema.numeroClientes] = cliente;
    sistema.numeroClientes++;

    cliente.nombre = "Pedro Perez";
    cliente.nif = "87654321A";
    cliente.domicilio = "Calle falsa 123";
    cliente.pago = "Tarjeta";
    sistema.clientes[sistema.numeroClientes] = cliente;
    sistema.numeroClientes++;

    cliente.nombre = "Maria Lopez";
    cliente.nif = "98765432A";
    cliente.domicilio = "Calle falsa 123";
    cliente.pago = "Efectivo";
    sistema.clientes[sistema.numeroClientes] = cliente;
    sistema.numeroClientes++;
}

// Programa principal
int main() {
    // Declaracion de variables
    Sistema sistema;
    // Inicializacion de variables
    sistema.numeroFacturas = 0;
    sistema.numeroClientes = 0;
    
    // Cargar inventario
    cargarInventario(sistema);

    // Datos de prueba
    datosDePrueba(sistema);

    // Mostrar inventario
    printf("Indice\tCodigo Concepto Precio Cantidad\n");
    for (int i = 0; i < sistema.inventario.numeroProductos; i++)
        printf("%d.\t{ %d, %s, %.2f, %d }\n", i+1, sistema.inventario.productos[i].codigo, sistema.inventario.productos[i].concepto.c_str(), sistema.inventario.productos[i].precio, sistema.inventario.productos[i].cantidad);

    cout << ".:: Sistema de facturacion ::." << endl;
    // Menu
    int opcion;
    do {
        cout << "1. Ventas." << endl;
        cout << "2. Clientes." << endl;
        cout << "3. Consultas." << endl;
        cout << "4. Salir." << endl;
        cout << "Opcion: ";
        while (true) {
            cin >> opcion;
            if (opcion >= 1 && opcion <= 4)
                break;
            cout << "Opcion invalida, intente de nuevo: ";
        }
        if (opcion == 1) {
            int opcion1;
            do {
                cout << "1. Generar factura." << endl;
                cout << "2. Regresar." << endl;
                cout << "Opcion: ";
                while (true) {
                    cin >> opcion1;
                    if (opcion1 >= 1 && opcion1 <= 6)
                        break;
                    cout << "Opcion invalida, intente de nuevo: ";
                }
                if (opcion1 == 1) {
                    generarFactura(sistema);
                } else if (opcion1 == 2) {
                    break;
                }
            } while (opcion1 != 2);
        } else if (opcion == 2) {
            int opcion2;
            do {
                cout << "1. Agregar cliente." << endl;
                cout << "2. Modificar cliente." << endl;
                cout << "3. Eliminar cliente." << endl;
                cout << "4. Listar clientes." << endl;
                cout << "5. Regresar." << endl;
                cout << "Opcion: ";
                while (true) {
                    cin >> opcion2;
                    if (opcion2 >= 1 && opcion2 <= 5)
                        break;
                    cout << "Opcion invalida, intente de nuevo: ";
                }
                if (opcion2 == 1) {
                    agregarCliente(sistema);
                } else if (opcion2 == 2) {
                    modificarCliente(sistema);
                } else if (opcion2 == 3) {
                    eliminarCliente(sistema);
                } else if (opcion2 == 4) {
                    listarClientes(sistema);
                } else if (opcion2 == 5) {
                    break;
                }
            } while (true);
        } else if (opcion == 3) {
            int opcion3;
            do {
                cout << "1. Buscar factura." << endl;
                cout << "2. Listar facturas." << endl;
                cout << "3. Mostrar factura por producto." << endl;
                cout << "4. Visualizar facturas." << endl;
                cout << "5. Regresar." << endl;
                cout << "Opcion: ";
                while (true) {
                    cin >> opcion3;
                    if (opcion3 >= 1 && opcion3 <= 5)
                        break;
                    cout << "Opcion invalida, intente de nuevo: ";
                }
                if (opcion3 == 1) {
                    int numeroFactura;
                    cout << "Numero de factura: ";
                    while (true) {
                        cin >> numeroFactura;
                        if (numeroFactura >= 1 && numeroFactura <= sistema.numeroFacturas)
                            break;
                        cout << "Numero de factura invalido, intente de nuevo: ";
                    }
                    buscarFactura(sistema);
                } else if (opcion3 == 2) {
                    listarFacturas(sistema);
                } else if (opcion3 == 3) {
                    int codigoProducto;
                    cout << "Codigo de producto: ";
                    while (true) {
                        cin >> codigoProducto;
                        if (codigoProducto >= 1 && codigoProducto <= sistema.inventario.numeroProductos)
                            break;
                        cout << "Codigo de producto invalido, intente de nuevo: ";
                    }
                    mostrarFacturaPorProducto(sistema);
                } else if (opcion3 == 4) {
                    visualizarFacturas(sistema);
                } else if (opcion3 == 5) {
                    break;
                }
            } while (true);
        } else if (opcion == 5) {
            break;
        }
    } while (true);
    return 0;
}

// Funciones
void cargarInventario(Sistema &sistema){
    // Abrir archivo
    ifstream file;
    file.open(FILE_NAME);

    // Leer archivo
    string linea;
    int i = 0;
    
    // Validar la primera linea
    getline(file, linea);
    /*cout<<linea<<endl;

    if (linea != "CODIGO;PRODUCTO;PRECIO UNITARIO;CANTIDAD\n")
    {
        printf("Error 1 en el archivo de productos\n");
        return;
    }
    */
    // Leer archivo
    while (!file.eof())
    {
        getline(file, linea);
        // Separar linea por ;
        string codigo = linea.substr(0, linea.find(";"));
        linea = linea.substr(linea.find(";") + 1);
        string concepto = linea.substr(0, linea.find(";"));
        linea = linea.substr(linea.find(";") + 1);
        string precio = linea.substr(0, linea.find(";"));
        linea = linea.substr(linea.find(";") + 1);
        string cantidad = linea.substr(0, linea.length()-1);

        // Convertir
        int codigoProducto = stringToInt(codigo);
        float precioProducto = stringToFloat(precio);
        int cantidadProducto = stringToInt(cantidad);
        
        if (codigoProducto == 0)
        {
            break;
        }
        // Agregar producto al inventario
        sistema.inventario.productos[i].codigo = codigoProducto;
        sistema.inventario.productos[i].concepto = concepto;
        sistema.inventario.productos[i].precio = precioProducto;
        sistema.inventario.productos[i].cantidad = cantidadProducto;
        i++;

    }
    sistema.inventario.numeroProductos = i;
    file.close();
}

// Clientes
void agregarCliente(Sistema &sistema) {
    // Declaracion de variables
    Cliente cliente;

    if (sistema.numeroClientes == MAX_LENGTH)
    {
        printf("No se pueden agregar mas clientes\n");
        return;
    }

    int numeroCliente = sistema.numeroClientes;
    
    // Variables
    string nombre;
    string nif;
    string domicilio;
    string pago;

    // Pedir datos
    cout << "Nombre: ";
    cin >> nombre;
    cout << "NIF: ";
    cin >> nif;
    cout << "Domicilio: ";
    cin >> domicilio;
    cout << "Forma de pago: ";
    cin >> pago;

    // Validar datos
    if (nombre == "") {
        cout << "Error: El nombre no puede estar vacio." << endl;
        return;
    }
    if (nif == "") {
        cout << "Error: El NIF no puede estar vacio." << endl;
        return;
    }
    if (domicilio == "") {
        cout << "Error: El domicilio no puede estar vacio." << endl;
        return;
    }
    if (pago == "") {
        cout << "Error: La forma de pago no puede estar vacia." << endl;
        return;
    }

    // Validar que el NIF no exista
    for (int i = 0; i < sistema.numeroClientes; i++) {
        if (sistema.clientes[i].nif == nif) {
            cout << "Error: El NIF ya existe." << endl;
            return;
        }
    }

    // Agregar cliente
    cliente.nombre = nombre;
    cliente.nif = nif;
    cliente.domicilio = domicilio;
    cliente.pago = pago;
    sistema.clientes[sistema.numeroClientes] = cliente;
    sistema.numeroClientes++;
}

// Modificar cliente
void modificarCliente(Sistema &sistema) {
    // Declaracion de variables
    Cliente cliente;
    string nombre;
    string nif;
    string domicilio;
    string pago;

    // Pedir datos
    cout << "NIF: ";
    cin >> nif;

    // Validar datos
    if (nif == "") {
        cout << "Error: El NIF no puede estar vacio." << endl;
        return;
    }

    // Buscar cliente
    int posicion = buscarCliente(sistema, nif);
    if (posicion == -1) {
        cout << "Error: El NIF no existe." << endl;
        return;
    }

    // Pedir datos
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Domicilio: ";
    cin >> domicilio;
    cout << "Forma de pago: ";
    cin >> pago;

    // Validar datos
    if (nombre == "") {
        cout << "Error: El nombre no puede estar vacio." << endl;
        return;
    }
    if (domicilio == "") {
        cout << "Error: El domicilio no puede estar vacio." << endl;
        return;
    }
    if (pago == "") {
        cout << "Error: La forma de pago no puede estar vacia." << endl;
        return;
    }

    // Modificar cliente
    cliente.nombre = nombre;
    cliente.nif = nif;
    cliente.domicilio = domicilio;
    cliente.pago = pago;
    sistema.clientes[posicion] = cliente;
}

// Buscar cliente
int buscarCliente(Sistema &sistema, string nif) {
    for (int i = 0; i < sistema.numeroClientes; i++) {
        if (sistema.clientes[i].nif == nif) {
            return i;
        }
    }
    return -1;
}

// Eliminar cliente
void eliminarCliente(Sistema &sistema) {
    // Declaracion de variables
    Cliente cliente;
    string nif;

    // Pedir datos
    cout << "NIF: ";
    cin >> nif;

    // Validar datos
    if (nif == "") {
        cout << "Error: El NIF no puede estar vacio." << endl;
        return;
    }

    // Buscar cliente
    int posicion = buscarCliente(sistema, nif);
    if (posicion == -1) {
        cout << "Error: El NIF no existe." << endl;
        return;
    }

    // Eliminar cliente
    for (int i = posicion; i < sistema.numeroClientes - 1; i++) {
        sistema.clientes[i] = sistema.clientes[i + 1];
    }
    sistema.numeroClientes--;
}

// Listar clientes
void listarClientes(Sistema &sistema) {
    // Declaracion de variables
    Cliente cliente;

    // Listar clientes
    cout << "Listado de clientes" << endl;
    cout << "-------------------" << endl;
    cout <<"Indice\tNombre\t\tNIF\tDomicilio\tForma de pago" << endl;
    for (int i = 0; i < sistema.numeroClientes; i++) {
        cout << i << "\t" << sistema.clientes[i].nombre << "\t" << sistema.clientes[i].nif << "\t" << sistema.clientes[i].domicilio << "\t" << sistema.clientes[i].pago << endl;
    }
}

// Listar productos
void listarProductos(Inventario inventario) {
    // Declaracion de variables
    Producto producto;

    // Listar productos
    cout << "Listado de productos" << endl;
    cout << "-------------------" << endl;
    cout <<"Indice\tNombre\t\tPrecio\tStock" << endl;
    for (int i = 0; i < inventario.numeroProductos; i++) {
        cout << i << "\t" << inventario.productos[i].concepto << "\t" << inventario.productos[i].precio << "\t" << inventario.productos[i].cantidad << endl;
    }
}

// Agregar productos a una factura
void agregarProductosFactura(Factura &factura, Inventario &inventario) {
    // do / while
    char opcion;
    do{
        // Declaracion de variables
        int indice;
        int cantidad;
        int posicion;
        Producto producto;

        // Agregar productos
        cout << "Agregar productos" << endl;
        cout << "-----------------" << endl;
        listarProductos(inventario);
        cout << "Indice: ";
        cin >> indice;
        cout << "Cantidad: ";
        cin >> cantidad;

        // Validar datos
        if (indice < 0 || indice >= inventario.numeroProductos) {
            cout << "Error: El indice no existe." << endl;
            // saltar al la siguiente iteracion
            continue;
        }
        if (cantidad <= 0) {
            cout << "Error: La cantidad debe ser mayor a 0." << endl;
            // saltar al la siguiente iteracion
            continue;
        }
        if (cantidad > inventario.productos[indice].cantidad) {
            cout << "Error: No hay suficiente stock." << endl;
            // saltar al la siguiente iteracion
            continue;
        }

        // Agregar productos
        producto = inventario.productos[indice];
        cout<<1<<endl;
        producto.cantidad = cantidad;
        cout<<2 << " numero productos: "<< factura.numeroProductos <<endl;
        factura.productos[factura.numeroProductos] = producto;    
        cout<<3<<endl;
        factura.numeroProductos++;
        cout<<4<<endl;
        inventario.productos[indice].cantidad -= cantidad;
        cout<<5<<endl;

        // Desea agregar mas productos
        cout << "Desea agregar mas productos? (s/n): ";
        cin >> opcion;
    }while(opcion == 's');
}

// Generar factura
void generarFactura(Sistema &sistema) {

    /*
    
    struct Factura {
        int numero;
        Cliente cliente;
        Producto producto[MAX_PRODUCTS];
        int numeroProductos;
        // Descuento es un porcentaje
        float descuento;
    };  

    */
    // Declaracion de variables
    Factura factura;
    string nif;
    float descuento;

    // Pedir datos
    cout << "Datos de la factura no " << sistema.numeroFacturas << endl;
    cout << "--------------------" << endl;
    // Listar clientes
    listarClientes(sistema);
    // Seleccionar cliente
    cout << "NIF: ";
    cin >> nif;
    // Buscar cliente
    int posicion = buscarCliente(sistema, nif);
    if (posicion == -1) {
        cout << "Error: El NIF no existe." << endl;
        return;
    }
    // Fecha actual formato dd/mm/aaaa
    time_t t = time(0);
    struct tm *now = localtime(&t);
    string fecha = to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
    // Asignar productos a factura
    factura.numeroProductos = 0;
    agregarProductosFactura(factura, sistema.inventario);

    // Pedir datos
    cout << "Descuento: ";
    cin >> descuento;

    // Asignar datos a factura
    factura.numero = sistema.numeroFacturas;
    factura.cliente = sistema.clientes[posicion];
    factura.descuento = descuento;
    factura.fecha = fecha;

    // Guardar factura
    sistema.facturas[sistema.numeroFacturas] = factura;
    sistema.numeroFacturas++;
}

// Listar facturas
void listarFacturas(Sistema &sistema) {
    // Declaracion de variables
    Factura factura;

    // Listar facturas
    cout << "Listado de facturas" << endl;
    cout << "-------------------" << endl;
    cout <<"Numero\tCliente\t\tFecha" << endl;
    for (int i = 0; i < sistema.numeroFacturas; i++) {
        factura = sistema.facturas[i];
        cout << factura.numero << "\t" << factura.cliente.nombre << "\t" << factura.fecha << endl;
    }
}

// Mostrar factura por producto
void mostrarFacturaPorProducto(Sistema &sistema) {
    // Declaracion de variables
    Factura factura;
    Producto producto;
    int codigo;
    int posicion;

    // Pedir datos
    cout << "Mostrar factura por producto" << endl;
    cout << "---------------------------" << endl;
    // Listar productos
    listarProductos(sistema.inventario);
    // Pedir codigo
    cout << "Codigo: ";
    cin >> codigo;

    // Buscar producto
    posicion = buscarProducto(sistema.inventario, codigo);
    if (posicion == -1) {
        cout << "Error: El codigo no existe." << endl;
        return;
    }
    producto = sistema.inventario.productos[posicion];

    // Listar facturas
    cout << "Listado de facturas" << endl;
    cout << "-------------------" << endl;
    cout <<"Numero\tCliente\t\tFecha" << endl;
    for (int i = 0; i < sistema.numeroFacturas; i++) {
        factura = sistema.facturas[i];
        for (int j = 0; j < factura.numeroProductos; j++) {
            if (factura.productos[j].codigo == producto.codigo) {
                cout << factura.numero << "\t" << factura.cliente.nombre << "\t" << factura.fecha << endl;
            }
        }
    }
}

// Buscar Factura Int
int buscarFacturaInt(Sistema sistema, int numero) {
    // Declaracion de variables
    Factura factura;
    int posicion = -1;

    // Buscar factura
    for (int i = 0; i < sistema.numeroFacturas; i++) {
        factura = sistema.facturas[i];
        if (factura.numero == numero) {
            posicion = i;
            break;
        }
    }
    return posicion;
}

// Buscar factura
void buscarFactura(Sistema &sistema) {
    // Declaracion de variables
    Factura factura;
    int numero;
    int posicion;

    // Pedir datos
    cout << "Buscar factura" << endl;
    cout << "-------------" << endl;
    // Pedir numero
    cout << "Numero: ";
    cin >> numero;

    // Buscar factura
    posicion = buscarFacturaInt(sistema, numero);
    if (posicion == -1) {
        cout << "Error: La factura no existe." << endl;
        return;
    }
    factura = sistema.facturas[posicion];

    // Mostrar factura
    visualizarFactura(factura);
}

// Visualizar factura
/*
void visualizarFactura(Factura factura) {
    // Declaracion de variables
    Producto producto;

    // Mostrar factura
    cout << "Factura no " << factura.numero << endl;
    cout << "------------" << endl;
    cout << "Cliente: " << factura.cliente.nombre << endl;
    cout << "Fecha: " << factura.fecha << endl;
    cout << "Descuento: " << factura.descuento << endl;
    cout << "Productos" << endl;
    cout << "---------" << endl;
    for (int i = 0; i < factura.numeroProductos; i++) {
        producto = factura.productos[i];
        cout << producto.concepto << " " << producto.cantidad << " " << producto.precio << endl;
    }
}*/

// Buscar producto
int buscarProducto(Inventario inventario, int codigo) {
    // Declaracion de variables
    Producto producto;
    int posicion = -1;

    // Buscar producto
    for (int i = 0; i < inventario.numeroProductos; i++) {
        producto = inventario.productos[i];
        if (producto.codigo == codigo) {
            posicion = i;
            break;
        }
    }
    return posicion;
}



/*

listarFacturas(sistema);
visualizarFacturas(sistema);
mostrarFacturaPorProducto(sistema);
buscarFactura(sistema);


struct Cliente{
    string nombre;
    string nif;
    string domicilio;
    string pago;
};

struct Producto{
    int codigo;
    int cantidad;
    string concepto;
    float precio;
};

struct Inventario{
    Producto productos[MAX_LENGTH];
    int numeroProductos;
};

struct Factura {
    int numero;
    Cliente cliente;
    Producto productos[MAX_PRODUCTS];
    int numeroProductos;
    // Descuento es un porcentaje
    float descuento;
    string fecha;
};

struct Sistema{
    Inventario inventario;

    Factura facturas[MAX_LENGTH];
    int numeroFacturas;

    Cliente clientes[MAX_LENGTH];
    int numeroClientes;
};


*/

// visualizarFactura(factura)
void visualizarFactura(Factura factura) {
    // Declaracion de variables
    Producto producto;

    // Mostrar factura
    cout << "Factura no " << factura.numero << endl;
    cout << "Fecha: " << factura.fecha << endl;
    cout << "------------" << endl;
    cout << "Cliente: " << factura.cliente.nombre << endl;
    cout << "N.I.F.: " << factura.cliente.nif << endl;
    cout << "Domicilio: " << factura.cliente.domicilio << endl;
    cout << "Pago: " << factura.cliente.pago << endl;
    cout << endl;
    // Listar Productos de la factura
    cout << "Productos" << endl;
    cout << "---------" << endl;
    cout << "Codigo\tCantidad\tConcepto\tPrecio\tImporte" << endl;
    for (int i = 0; i < factura.numeroProductos; i++) {
        producto = factura.productos[i];
        cout << producto.codigo << "\t" << producto.cantidad << "\t" << producto.concepto << "\t" << producto.precio << "\t" << producto.precio * producto.cantidad << endl;
    }
    cout << endl;
    // Totales
    float totalBruto = 0;
    float totalDescuento = 0;
    float totalIVA = 0;
    float totalNeto = 0;
    
    for (int i = 0; i < factura.numeroProductos; i++) {
        producto = factura.productos[i];
        totalBruto += producto.cantidad * producto.precio;
    }
    totalDescuento = totalBruto * factura.descuento;
    totalIVA = (totalBruto - totalDescuento) * IVA;
    totalNeto = totalBruto - totalDescuento + totalIVA;

    cout << "Total Bruto: " << totalBruto << endl;
    cout << "Descuento: " << totalDescuento << endl;
    cout << "IVA: " << totalIVA << endl;
    cout << "Total Neto: " << totalNeto << endl;
}


// Visualizar Facturas
void visualizarFacturas(Sistema &sistema) {
    // Declaracion de variables
    Factura factura;

    // Listar facturas
    cout << "Listado de facturas" << endl;
    cout << "-------------------" << endl;
    cout <<"Numero\tCliente\t\tFecha" << endl;
    for (int i = 0; i < sistema.numeroFacturas; i++) {
        factura = sistema.facturas[i];
        visualizarFactura(factura);
    }
}
