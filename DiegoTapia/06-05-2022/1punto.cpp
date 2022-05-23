// Crear un programa que maneje vectores dinamicos
#include <iostream>
#include <fstream>
#define MAX 100

using namespace std;

// Estructura trabajador
struct trabajador
{
    char nombre_trabaj[15];
    char apellido_trabaj[15];
    char direccion_trabaj[15];
    char telefono_trabaj[15];
};

// Funcion que lee un arreglo de trabajadores de archivo binario
int leer_trabajadores(trabajador *trabajadores)
{
    int cantidad = 0;
    ifstream archivo;
    archivo.open("trabajador.dat", ios::in | ios::binary);
    if (archivo.is_open())
    {
        archivo.seekg(0, ios::end);
        cantidad = archivo.tellg() / sizeof(trabajador);
        archivo.seekg(0, ios::beg);
        archivo.read((char *)trabajadores, sizeof(trabajador) * cantidad);
        archivo.close();
    } else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
    return cantidad;
}

// Funcion que escribe un arreglo de trabajadores en archivo binario
void escribir_trabajadores(trabajador *trabajadores, int cantidad)
{
    ofstream archivo;
    archivo.open("trabajador.dat", ios::out | ios::binary);
    if (archivo.is_open())
    {
        archivo.write((char *)trabajadores, sizeof(trabajador) * cantidad);
        archivo.close();
    } else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

// Funcion que agrega un trabajador al arreglo
int agregar_trabajador(trabajador *trabajadores, int cantidad)
{
    trabajador trabajador_nuevo;
    cout << "Ingrese el nombre del trabajador: ";
    cin >> trabajador_nuevo.nombre_trabaj;
    cout << "Ingrese el apellido del trabajador: ";
    cin >> trabajador_nuevo.apellido_trabaj;
    cout << "Ingrese la direccion del trabajador: ";
    cin >> trabajador_nuevo.direccion_trabaj;
    cout << "Ingrese el telefono del trabajador: ";
    cin >> trabajador_nuevo.telefono_trabaj;
    trabajadores[cantidad] = trabajador_nuevo;
    return cantidad + 1;
}

// Funcion que modifica un trabajador del arreglo
int modificar_trabajador(trabajador *trabajadores, int cantidad)
{
    int posicion;
    cout << "Ingrese la posicion del trabajador a modificar: ";
    cin >> posicion;
    if (posicion > cantidad)
    {
        cout << "Posicion no valida" << endl;
        return cantidad;
    }
    cout << "Ingrese el nombre del trabajador: ";
    cin >> trabajadores[posicion].nombre_trabaj;
    cout << "Ingrese el apellido del trabajador: ";
    cin >> trabajadores[posicion].apellido_trabaj;
    cout << "Ingrese la direccion del trabajador: ";
    cin >> trabajadores[posicion].direccion_trabaj;
    cout << "Ingrese el telefono del trabajador: ";
    cin >> trabajadores[posicion].telefono_trabaj;
    return cantidad;
}

// Funcion que elimina un trabajador del arreglo
int eliminar_trabajador(trabajador *trabajadores, int cantidad)
{
    int posicion;
    cout << "Ingrese la posicion del trabajador a eliminar: ";
    cin >> posicion;
    if (posicion > cantidad)
    {
        cout << "Posicion no valida" << endl;
        return cantidad;
    }
    for (int i = posicion; i < cantidad; i++)
    {
        trabajadores[i] = trabajadores[i + 1];
    }
    return cantidad - 1;
}

// Funcion que muestra los trabajadores del arreglo con indice
void mostrar_trabajadores(trabajador *trabajadores, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Trabajador " << i << endl;
        cout << "Nombre: " << trabajadores[i].nombre_trabaj << endl;
        cout << "Apellido: " << trabajadores[i].apellido_trabaj << endl;
        cout << "Direccion: " << trabajadores[i].direccion_trabaj << endl;
        cout << "Telefono: " << trabajadores[i].telefono_trabaj << endl;
    }
}

// Menu
void menu()
{
    cout << "1. Agregar trabajador" << endl;
    cout << "2. Modificar trabajador" << endl;
    cout << "3. Eliminar trabajador" << endl;
    cout << "4. Mostrar trabajadores" << endl;
    cout << "5. Salir" << endl;
}

// Funcion principal
int main()
{
    trabajador trabajadores[MAX];
    int cantidad = 0;

    // Cargar trabajadores
    cantidad = leer_trabajadores(trabajadores);   

    int opcion;
    for (;;)
    {
        menu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cantidad = agregar_trabajador(trabajadores, cantidad);
            break;
        case 2:
            cantidad = modificar_trabajador(trabajadores, cantidad);
            break;
        case 3:
            cantidad = eliminar_trabajador(trabajadores, cantidad);
            break;
        case 4:
            mostrar_trabajadores(trabajadores, cantidad);
            break;
        case 5:
            escribir_trabajadores(trabajadores, cantidad);
            return 0;
        default:
            cout << "Opcion no valida" << endl;
        }
    }
}
    



