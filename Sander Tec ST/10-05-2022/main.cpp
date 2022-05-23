// Tienda de electrodomesticos "LINEA BLANCA"
#include <iostream>
#include "./listaEnlazada.h"

using namespace std;

class Provedor
{
private:
    string ruc; // empezar con 10 o 20 y es de solo 11 caracteres, si no no se puede guardar
    string razonsocial;
    string direccion;
    string numero; // empezar con 9 y tiene 9 digitos, si no no se puede guardar

public:
    Provedor(string ruc, string razonsocial, string direccion, string numero)
    {
        this->ruc = ruc;
        this->razonsocial = razonsocial;
        this->direccion = direccion;
        this->numero = numero;
    }
    Provedor()
    {
        this->ruc = "";
        this->razonsocial = "";
        this->direccion = "";
        this->numero = "";
    }
    string getRuc()
    {
        return this->ruc;
    }
    string getRazonSocial()
    {
        return this->razonsocial;
    }
    string getDireccion()
    {
        return this->direccion;
    }
    string getNumero()
    {
        return this->numero;
    }
    void setRuc(string ruc)
    {
        this->ruc = ruc;
    }
    void setRazonSocial(string razonSocial)
    {
        this->razonsocial = razonSocial;
    }
    void setDireccion(string direccion)
    {
        this->direccion = direccion;
    }
    void setNumero(string numero)
    {
        this->numero = numero;
    }
    // <<
    friend ostream &operator<<(ostream &os, Provedor &p)
    {
        os << "{ " << p.ruc << ", " << p.razonsocial << ", " << p.direccion << ", " << p.numero << " }";
        return os;
    }
    // ==
    friend bool operator==(Provedor &p1, Provedor &p2)
    {
        return p1.ruc == p2.ruc && p1.razonsocial == p2.razonsocial && p1.direccion == p2.direccion && p1.numero == p2.numero;
    }
};

class Tienda
{
private:
    string nombre;
    // Lista enlazada de proveedores
    Lista<Provedor> listaProvedores;

public:
    // agregar, mostrar, actualizar por ruc, eliminar por ruc
    Tienda(string nombre)
    {
        this->nombre = nombre;
    }

    string getNombre()
    {
        return this->nombre;
    }

    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }

    void agregarProvedor(Provedor provedor)
    {
        listaProvedores.insertarPrincipio(provedor);
    }

    void mostrarProvedores()
    {
        listaProvedores.imprimir();
    }

    void actualizarProvedor(string ruc)
    {

        for (int i = 0; i < listaProvedores.getTamano(); i++)
        {
            Provedor actual = listaProvedores.getPosicion(i);
            if (actual.getRuc() == ruc)
            {
                cout << "Ingrese la nueva razon social: ";
                string razonSocial;
                cin >> razonSocial;
                actual.setRazonSocial(razonSocial);
                cout << "Ingrese la nueva direccion: ";
                string direccion;
                cin >> direccion;
                actual.setDireccion(direccion);
                cout << "Ingrese el nuevo numero: ";
                string numero;
                do
                {
                    cin >> numero;
                } while (numero.size() != 9);
                actual.setNumero(numero);
                cout << "Provedor actualizado" << endl;
                return;
            }

            actual = listaProvedores.getPosicion(i);
        }
    }

    void eliminarProvedor(string ruc)
    {
        for (int i = 0; i < listaProvedores.getTamano(); i++)
        {
            Provedor actual = listaProvedores.getPosicion(i);
            if (actual.getRuc() == ruc)
            {
                listaProvedores.eliminar(actual);
                cout << "Provedor eliminado" << endl;
                return;
            }

            actual = listaProvedores.getPosicion(i);
        }
    }
};

// Menu
void menu()
{
    Tienda *tienda = new Tienda("LINEA BLANCA");
    cout << "1. Agregar provedor" << endl;
    cout << "2. Mostrar provedores" << endl;
    cout << "3. Actualizar provedor" << endl;
    cout << "4. Eliminar provedor" << endl;
    cout << "0. Salir" << endl;
    string opcion;
    cin >> opcion;
    if (opcion == "1")
    {
        cout << "Ingrese el ruc: ";
        string ruc;
        do
        {
            cin >> ruc;
        } while (ruc.size() != 11 || ruc[0] != '1' && ruc[0] != '2' || ruc[1] != '0');
        cout << "Ingrese la razon social: ";
        string razonSocial;
        cin >> razonSocial;
        cout << "Ingrese la direccion: ";
        string direccion;
        cin >> direccion;
        cout << "Ingrese el numero de telefono: ";
        string numero;
        do
        {
            cin >> numero;
        } while (numero.size() != 9 || numero[0] != '9');
        Provedor provedor(ruc, razonSocial, direccion, numero);
        tienda->agregarProvedor(provedor);
        cout << "Provedor agregado correctamente" << endl;
        menu();
    }
    else if (opcion == "2")
    {
        tienda->mostrarProvedores();
        menu();
    }
    else if (opcion == "3")
    {
        cout << "Ingrese el ruc: ";
        string ruc;
        do
        {
            cin >> ruc;
        } while (ruc.size() != 11 || ruc[0] != '1' && ruc[0] != '2' || ruc[1] != '0');
        tienda->actualizarProvedor(ruc);
        menu();
    }
    else if (opcion == "4")
    {
        cout << "Ingrese el ruc: ";
        string ruc;
        do
        {
            cin >> ruc;
        } while (ruc.size() != 11 || ruc[0] != '1' && ruc[0] != '2' || ruc[1] != '0');
        tienda->eliminarProvedor(ruc);
        menu();
    }
    else if (opcion == "0")
    {
        cout << "Saliendo..." << endl;
    }
    else
    {
        cout << "Opcion no valida" << endl;
        menu();
    }
}

// Main
int main()
{
    menu();
    return 0;
}
