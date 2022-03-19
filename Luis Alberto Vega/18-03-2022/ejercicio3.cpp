#include <iostream>

#define N_VENTAS 100
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

struct venta
{
    int codigo;
    string nombre;
    int tipo; // 1 = contado, 2=crédito
    float precioUnitario;
    int cantidad;
    float montoVenta(); // precioUnitario * cantidad
    // descuento (si el monto de la venta es mayor o igual a ¢50.000 y menor que ¢100.000 el descuento aplicar es 6% sobre el monto de la venta; si el monto de la venta es mayor o igual a ¢100.000 y menor que ¢250.000 el descuento aplicar es 7.5% sobre el monto de la venta; si el monto de la venta es mayor o igual que ¢250.000 el descuento aplicar es un 10% sobre el monto de la venta)
    float descuento();
    // subtotal (monto de la venta – descuento),
    float subtotal();
    // impuesto al valor agregado (iva) correspondiente al 13% sobre el subtotal
    float iva();
    // total a pagar (subtotal más el impuesto iva)
    float total();
    // método que imprime los datos de la venta
    void imprimir();
    // texto
    string texto();
};

// Funciones
// Funcion que calcula el monto de la venta
float venta::montoVenta()
{
    return precioUnitario * cantidad;
}

// Funcion que calcula el descuento
float venta::descuento()
{
    float monto = montoVenta();
    if (monto >= 50000 && monto < 100000)
    {
        return monto * 0.06;
    }
    else if (monto >= 100000 && monto < 250000)
    {
        return monto * 0.075;
    }
    else if (monto >= 250000)
    {
        return monto * 0.1;
    }
    else
    {
        return 0;
    }
}

// Funcion que calcula el subtotal
float venta::subtotal()
{
    return montoVenta() - descuento();
}

// Funcion que calcula el iva
float venta::iva()
{
    return subtotal() * IVA;
}

// Funcion que calcula el total
float venta::total()
{
    return subtotal() + iva();
}

// Funcion que imprime los datos de la venta
void venta::imprimir()
{
    cout << "Venta = { "
         << "Codigo: " << codigo << ", Nombre: " << nombre << ", Tipo: ";
    if (tipo == 1)
    {
        cout << "Contado";
    }
    else
    {
        cout << "Credito";
    }
    cout << ", Precio Unitario: " << precioUnitario << ", Cantidad: " << cantidad << ", Monto: " << montoVenta() << ", Descuento: " << descuento() << ", Subtotal: " << subtotal() << ", IVA: " << iva() << ", Total: " << total() << " }" << endl;
}

// Funcion que devuelve el texto de la venta
string venta::texto()
{
    string texto = "Venta = { ";
    texto += "Codigo: " + to_string(codigo) + ", Nombre: " + nombre + ", Tipo: ";
    if (tipo == 1)
    {
        texto += "Contado";
    }
    else
    {
        texto += "Credito";
    }
    texto += ", Precio Unitario: " + to_string(precioUnitario) + ", Cantidad: " + to_string(cantidad) + ", Monto: " + to_string(montoVenta()) + ", Descuento: " + to_string(descuento()) + ", Subtotal: " + to_string(subtotal()) + ", IVA: " + to_string(iva()) + ", Total: " + to_string(total()) + " }";
    return texto;
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

// leerVenta()
venta leerVenta()
{
    cout << "Ingresar venta: " << endl;
    venta v;
    cout << "Codigo: ";
    v.codigo = leerEntero(0, 99999);
    cout << "Nombre: ";
    v.nombre = leerCadena();
    cout << "Tipo: ";
    v.tipo = leerEntero(1, 2);
    cout << "Precio Unitario: ";
    v.precioUnitario = leerFlotante(0, 99999);
    cout << "Cantidad: ";
    v.cantidad = leerEntero(0, 99999);
    return v;
}

// Estadisticas
void estadisticas(venta ventas[], int nVentas)
{
    int contadorCredito = 0;
    float acumuladoCredito = 0;
    float promedioCredito = 0;
    int contadorContado = 0;
    float acumuladoContado = 0;
    float promedioContado = 0;
    int contadorTotal = 0;
    float acumuladoTotal = 0;
    float promedioTotal = 0;
    for (int i = 0; i < nVentas; i++)
    {
        if (ventas[i].tipo == 1)
        {
            contadorContado++;
            acumuladoContado += ventas[i].total();
        }
        else
        {
            contadorCredito++;
            acumuladoCredito += ventas[i].total();
        }
        contadorTotal++;
        acumuladoTotal += ventas[i].total();
    }
    promedioCredito = acumuladoCredito / contadorCredito;
    promedioContado = acumuladoContado / contadorContado;
    promedioTotal = acumuladoTotal / contadorTotal;
    cout << endl;
    cout << "Estadisticas:" << endl;
    cout << "Cantidad de Ventas Tipo Credito: " << contadorCredito << endl;
    cout << "Acumulado Ventas Tipo Credito: " << acumuladoCredito << endl;
    cout << "Promedio Ventas Tipo Credito: " << promedioCredito << endl;
    cout << "Cantidad de Ventas Tipo Contado: " << contadorContado << endl;
    cout << "Acumulado Ventas Tipo Contado: " << acumuladoContado << endl;
    cout << "Promedio Ventas Tipo Contado: " << promedioContado << endl;
    cout << "Cantidad de todas las ventas realizadas: " << contadorTotal << endl;
    cout << "Acumulado de ventas de todas las ventas: " << acumuladoTotal << endl;
    cout << "Promedio de ventas de todas las ventas: " << promedioTotal << endl;
    cout << endl;
}

// menu
void menu()
{
    cout << "1. Agregar Venta" << endl;
    cout << "2. Imprimir Ventas" << endl;
    cout << "3. Estadisticas" << endl;
    cout << "0. Salir" << endl;
}

int main()
{
    int nVentas = 0;
    venta ventas[N_VENTAS];
    int opcion;
    do
    {
        menu();
        opcion = leerEntero(0, 3);
        switch (opcion)
        {
        case 1:
            ventas[nVentas++] = leerVenta();
            break;
        case 2:
            for (int i = 0; i < nVentas; i++)
            {
                ventas[i].imprimir();
            }
            break;
        case 3:
            estadisticas(ventas, nVentas);
            break;
        }
    } while (opcion != 0);
    return 0;
}
