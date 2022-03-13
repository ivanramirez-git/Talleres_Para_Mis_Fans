#include <iostream>

using namespace std;

struct dato
{
    string nombre;
    string cedula;
    double pago_realizado;
    string tipo_pago;
};

// cola
struct nodo
{
    dato info;
    nodo *sig;
};

// ingresar cliente a la cola FIFO
void ingresar_cliente(nodo **cab, dato cliente)
{
    nodo *nuevo = new nodo;
    nuevo->info = cliente;
    nuevo->sig = NULL;
    if (*cab == NULL)
    {
        *cab = nuevo;
    }
    else
    {
        nodo *aux = *cab;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    cout << "Cliente ingresado: " << cliente.nombre << endl;
}

// atender cliente de la cola FIFO, e imprimir datos
void atender_cliente(nodo **cab)
{
    if (*cab == NULL)
    {
        cout << "No hay clientes en la cola" << endl;
    }
    else
    {
        nodo *aux = *cab;
        cout << "Nombre: " << aux->info.nombre << endl;
        cout << "Cedula: " << aux->info.cedula << endl;
        cout << "Pago realizado: " << aux->info.pago_realizado << endl;
        cout << "Tipo de pago: " << aux->info.tipo_pago << endl;
        *cab = (*cab)->sig;
        delete aux;
    }
}

// imprimir todos los clientes FIFO
void imprimir_clientes(nodo *cab)
{
    int i = 1;
    if (cab == NULL)
    {
        cout << "No hay clientes en la cola" << endl;
    }
    else
    {
        while (cab != NULL)
        {
            cout << "Cliente " << i << endl;
            cout << "Nombre: " << cab->info.nombre << endl;
            cout << "Cedula: " << cab->info.cedula << endl;
            cout << "Pago realizado: " << cab->info.pago_realizado << endl;
            cout << "Tipo de pago: " << cab->info.tipo_pago << endl;
            cab = cab->sig;
            i++;
        }
    }
}

// Pruebas
void prueba1(){
    // Crear cola
    nodo *cab = NULL;
    // Ingresar clientes
    dato x;
    x.nombre = "Juan";
    x.cedula = "123456789";
    x.pago_realizado = 100;
    x.tipo_pago = "Efectivo";
    ingresar_cliente(&cab, x);
    x.nombre = "Pedro";
    x.cedula = "987654321";
    x.pago_realizado = 200;
    x.tipo_pago = "Tarjeta";
    ingresar_cliente(&cab, x);
    x.nombre = "Maria";
    x.cedula = "987654321";
    x.pago_realizado = 300;
    x.tipo_pago = "Efectivo";
    ingresar_cliente(&cab, x);
    cout << endl;
    // Imprimir todos los clientes
    cout << "Clientes en la cola: " << endl;
    imprimir_clientes(cab);
    // Atender clientes
    cout << endl;
    cout << "Atencion de clientes: " << endl;
    cout << endl;
    cout << "1 Atencion: " << endl;
    atender_cliente(&cab);
    cout << endl;
    cout << "2 Atencion: " << endl;
    atender_cliente(&cab);
    cout << endl;
    cout << "3 Atencion: " << endl;
    atender_cliente(&cab);
    cout << endl;
    cout << "4 Atencion: " << endl;
    atender_cliente(&cab);
    cout << endl;
}

void prueba2(){
    // Pedir datos
    int opcion = -1;
    nodo *cab = NULL;
    while (opcion != 0)
    {
        cout << "Ingrese una opcion: " << endl;
        cout << "1. Ingresar cliente" << endl;
        cout << "2. Atender cliente" << endl;
        cout << "3. Imprimir clientes" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case 1:
            {
                dato x;
                cout << "Ingrese nombre: " << endl;
                cin >> x.nombre;
                cout << "Ingrese cedula: " << endl;
                cin >> x.cedula;
                cout << "Ingrese pago realizado: " << endl;
                cin >> x.pago_realizado;
                cout << "Ingrese tipo de pago: " << endl;
                cin >> x.tipo_pago;
                ingresar_cliente(&cab, x);
                break;
            }
        case 2:
            {
                atender_cliente(&cab);
                break;
            }
        case 3:
            {
                imprimir_clientes(cab);
                break;
            }
        case 0:
            {
                break;
            }
        default:
            {
                cout << "Opcion invalida" << endl;
                break;
            }
        }
        cout << endl;
    }
}

// Main
int main()
{
    prueba2();
    return 0;
}