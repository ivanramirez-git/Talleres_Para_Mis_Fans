/*
Una empresa quiere sistematizar las existencias de sus productos para saber cuándo deben llamar a su proveedor. 
Para ello se requieren las siguientes operaciones: 
• Crear el producto con los campos como código, nombre, descripción, precio y existencias. 
• Comprar productos es la operación que permite ingresar determinadas existencias de un producto ya existente en el sistema. 
• Vender productos es verificar si la cantidad del producto a comprar por el cliente existe en el almacén. Si existe descontarlo del número de existencias o sino mostrar un mensaje "No tenemos el producto". 
• Listar productos es la operación que permite ver el código del producto, el nombre, el precio y las existencias de todos los productos. 
• Una función donde el usuario digite el nombre del producto y se presente el número de existencias de ese producto. 
Diseñe un programa en C++ que permita realizar las operaciones descritas. También se debe utilizar un menú que permita seleccionar la operación a realizar y el manejo de funciones Pasando parámetros para el buen funcionamiento del programa. La implementación debe funcionar para 5 productos inicialmente. 
*/

#include <iostream>
#include <vector>

using namespace std;

struct Producto{
    int codigo;
    string nombre;
    string descripcion;
    float precio;
    int existencias;
};

// Funciones
void agregarProducto(vector<Producto> &productos);
void comprar(vector<Producto> &productos, int codigo, int cantidad);
void vender(vector<Producto> &productos, int codigo, int cantidad);
void listar(vector<Producto> &productos);
void buscar(vector<Producto> &productos, string nombre);

// Main
int main(){
    vector<Producto> productos;
    Producto producto;
    int opcion;
    int codigo;
    int cantidad;
    string nombre;

    producto.codigo = 1;
    producto.nombre = "Laptop";
    producto.descripcion = "Laptop de ultima generacion";
    producto.precio = 20000;
    producto.existencias = 10;
    productos.push_back(producto);

    producto.codigo = 2;
    producto.nombre = "Mouse";
    producto.descripcion = "Mouse de ultima generacion";
    producto.precio = 1000;
    producto.existencias = 10;
    productos.push_back(producto);

    producto.codigo = 3;
    producto.nombre = "Teclado";
    producto.descripcion = "Teclado de ultima generacion";
    producto.precio = 2000;
    producto.existencias = 10;
    productos.push_back(producto);

    producto.codigo = 4;
    producto.nombre = "Monitor";
    producto.descripcion = "Monitor de ultima generacion";
    producto.precio = 5000;
    producto.existencias = 10;
    productos.push_back(producto);

    producto.codigo = 5;
    producto.nombre = "Impresora";
    producto.descripcion = "Impresora de ultima generacion";
    producto.precio = 10000;
    producto.existencias = 10;
    productos.push_back(producto);

    do{
        cout << "0. Agregar producto" << endl;
        cout << "1. Comprar" << endl;
        cout << "2. Vender" << endl;
        cout << "3. Listar" << endl;
        cout << "4. Buscar" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;

        switch(opcion){
            case 0:
                agregarProducto(productos);
                break;
            case 1:
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;
                cout << "Ingrese la cantidad: ";
                cin >> cantidad;
                comprar(productos, codigo, cantidad);
                break;
            case 2:
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;
                cout << "Ingrese la cantidad: ";
                cin >> cantidad;
                vender(productos, codigo, cantidad);
                break;
            case 3:
                listar(productos);
                break;
            case 4:
                cout << "Ingrese el nombre del producto: ";
                cin >> nombre;
                buscar(productos, nombre);
                break;
            case 5:
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
    }while(opcion != 5);

    return 0;
}

// Funciones
void agregarProducto(vector<Producto> &productos){
    Producto producto;
    int codigo;
    string nombre;
    string descripcion;
    float precio;
    int existencias;

    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;
    cout << "Ingrese el nombre del producto: ";
    cin >> nombre;
    cout << "Ingrese la descripcion del producto: ";
    cin >> descripcion;
    cout << "Ingrese el precio del producto: ";
    cin >> precio;
    cout << "Ingrese las existencias del producto: ";
    cin >> existencias;

    producto.codigo = codigo;
    producto.nombre = nombre;
    producto.descripcion = descripcion;
    producto.precio = precio;
    producto.existencias = existencias;

    productos.push_back(producto);
}

void comprar(vector<Producto> &productos, int codigo, int cantidad){
    for(int i = 0; i < productos.size(); i++){
        if(productos[i].codigo == codigo){
                cout << "Se ha comprado " << cantidad << " unidades del producto " << productos[i].nombre << endl;
                productos[i].existencias += cantidad;
                cout << "Existencias actuales: " << productos[i].existencias << endl;
        }
    }
}

void vender(vector<Producto> &productos, int codigo, int cantidad){
    for(int i = 0; i < productos.size(); i++){
        if(productos[i].codigo == codigo){
            if(productos[i].existencias >= cantidad){
                productos[i].existencias -= cantidad;
                cout << "Se ha vendido " << cantidad << " unidades del producto " << productos[i].nombre << endl;
            }else{
                cout << "No hay suficientes existencias" << endl;
            }
        }
    }
}

void listar(vector<Producto> &productos){
    for(int i = 0; i < productos.size(); i++){
        cout << "Codigo: " << productos[i].codigo << endl;
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Descripcion: " << productos[i].descripcion << endl;
        cout << "Precio: " << productos[i].precio << endl;
        cout << "Existencias: " << productos[i].existencias << endl;
        cout << endl;
    }
}

void buscar(vector<Producto> &productos, string nombre){
    for(int i = 0; i < productos.size(); i++){
        if(productos[i].nombre == nombre){
            cout << "Codigo: " << productos[i].codigo << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Descripcion: " << productos[i].descripcion << endl;
            cout << "Precio: " << productos[i].precio << endl;
            cout << "Existencias: " << productos[i].existencias << endl;
            cout << endl;
        }
    }
}



