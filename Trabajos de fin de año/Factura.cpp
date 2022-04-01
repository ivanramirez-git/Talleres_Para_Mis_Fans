#include <iostream>
#define IVA 0.19
#define NUM_MAX_PRODUCTOS 10

using namespace std;

struct Producto {
    int cantidad;
    string concepto;
    float precio;
};

struct Factura {
    int numero;
    string fecha;
    string cliente;
    string nif_cliente;
    string domicilio;
    string pago;
    Producto productos[NUM_MAX_PRODUCTOS];
    int numero_productos;
    float porcentaje_descuento;
};

float importeProducto(Producto producto) {
    return producto.cantidad * producto.precio;
}

float totalBruto(Factura factura) {
    float total = 0;
    for (int i = 0; i < factura.numero_productos; i++) {
        total += importeProducto(factura.productos[i]);
    }
    return total;
}

float totalIva(Factura factura) {
    return totalBruto(factura) * IVA;
}

float totalDescuento(Factura factura) {
    return totalBruto(factura) * factura.porcentaje_descuento;
}

float totalFactura(Factura factura) {
    return totalBruto(factura) + totalIva(factura) - totalDescuento(factura);
}

void cargarProducto(Producto &producto) {
    cout << "Cantidad: ";
    cin >> producto.cantidad;
    cout << "Concepto: ";
    cin >> producto.concepto;
    cout << "Precio: ";
    cin >> producto.precio;
}

void cargarFactura(Factura &factura) {
    cout << "Numero: ";
    cin >> factura.numero;
    cout << "Fecha: ";
    cin >> factura.fecha;
    cout << "Cliente: ";
    cin >> factura.cliente;
    cout << "NIF: ";
    cin >> factura.nif_cliente;
    cout << "Domicilio: ";
    cin >> factura.domicilio;
    cout << "Pago: ";
    cin >> factura.pago;
    cout << "Numero de productos: ";
    cin >> factura.numero_productos;
    for (int i = 0; i < factura.numero_productos; i++) {
        cargarProducto(factura.productos[i]);
    }
    cout << "Porcentaje de descuento: ";
    cin >> factura.porcentaje_descuento;
}

int main() {
    Factura factura;
    factura.numero = 1;
    factura.fecha = "01/01/2020";
    factura.cliente = "Juan";
    factura.nif_cliente = "12345678A";
    factura.domicilio = "Calle falsa 123";
    factura.pago = "Efectivo";
    factura.numero_productos = 3;
    factura.porcentaje_descuento = 0.1;
    factura.productos[0].cantidad = 2;
    factura.productos[0].concepto = "Coca";
    factura.productos[0].precio = 1.5;
    factura.productos[1].cantidad = 1;
    factura.productos[1].concepto = "Pepsi";
    factura.productos[1].precio = 2.5;
    factura.productos[2].cantidad = 1;
    factura.productos[2].concepto = "Fanta";
    factura.productos[2].precio = 2.5;


    /*

    Factura                         Numero 1
    Fecha: 01/01/2020

    Cliente: Juan                   NIF: 12345678A
    Domicilio: Calle falsa 123      Pago: Efectivo

    Cantidad      Concepto      Precio      Importe
    2             Coca-Cola     1.5         3.0
    1             Pepsi          2.5         2.5
    ------------------------------------------------
    Total bruto:  5.5         Descuento: 0.0    IVA: 0.95   Total: 5.95


    IVA = 0.19*TotalBruto
    Total = TotalBruto + IVA - Descuento

    */
    cout << "Factura                         Numero " << factura.numero << endl;
    cout << "\t\t\t\tFecha: " << factura.fecha << endl;
    cout << "Cliente: " << factura.cliente << "                   NIF: " << factura.nif_cliente << endl;
    cout << "Domicilio: " << factura.domicilio << "      Pago: " << factura.pago << endl;
    cout << "Cantidad\t\tConcepto\tPrecio\t\tImporte" << endl;
    for (int i = 0; i < factura.numero_productos; i++) {
        cout << factura.productos[i].cantidad << "\t\t\t" << factura.productos[i].concepto << "\t\t" << factura.productos[i].precio << "\t\t" << importeProducto(factura.productos[i]) << endl;
    }
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Total bruto:  " << totalBruto(factura) << "         Descuento: " << totalDescuento(factura) << "    IVA: " << totalIva(factura) << "   Total: " << totalFactura(factura) << endl;
    return 0;
}
/*

    Producto productos[10];
    productos[0] = Producto(1, "Papel", 1.5);
    productos[1] = Producto(2, "Lapices", 1.5);
    productos[2] = Producto(3, "Grapas", 1.5);
    productos[3] = Producto(4, "Cinta", 1.5);
    productos[4] = Producto(5, "Tijeras", 1.5);
    productos[5] = Producto(6, "Caja", 1.5);
    productos[6] = Producto(7, "Lapicero", 1.5);
    productos[7] = Producto(8, "Borrador", 1.5);
    productos[8] = Producto(9, "Cuaderno", 1.5);
    productos[9] = Producto(10, "Borrador", 1.5);

    Factura factura(1, "01/01/2019", "Cliente 1", "NIF 1", "Domicilio 1", "Efectivo", productos, 10, 0);
    return 0;


    float totalBruto() {
        float total = 0;
        for (int i = 0; i < numero_productos; i++) {
            total += productos[i].importe();
        }
        return total;
    }

    float iva() {
        return totalBruto() * 0.19;
    }

    float totalNeto() {
        return totalBruto() - descuento + iva();
    }

    void mostrar() {
        cout << "\t\t\t\tFactura " << numero << endl;
        cout << "\t\t\tFecha: " << fecha << endl;
        cout << "\tCliente: " << cliente;
        cout << "\t\tNIF: " << nif_cliente << endl;
        cout << "\tDomicilio: " << domicilio;
        cout << "\t\tPago: " << pago << endl;
        cout << endl;
        cout << "Cantidad\t\tConcepto\t\tPrecio\t\tImporte" << endl;
        for (int i = 0; i < numero_productos; i++) {
            productos[i].mnostrar();
        }
        cout<<endl;
        cout << "Total bruto: " << totalBruto();
        cout << "\tDescuento: " << descuento;
        cout << "\tIVA: " << iva();
        cout << "\tTotal: " << totalNeto() << endl;
    }

    // Constructor
    Factura(int numero, string fecha, string cliente, string nif_cliente, string domicilio, string pago, Producto productos[10], int numero_productos, float descuento) {
        this->numero = numero;
        this->fecha = fecha;
        this->cliente = cliente;
        this->nif_cliente = nif_cliente;
        this->domicilio = domicilio;
        this->pago = pago;
        this->productos = productos;
        this->numero_productos = numero_productos;
        this->descuento = descuento;
    }

    // Destructor
    ~Factura() {
        cout << "Destruyendo factura " << numero << endl;
    }



    

    // Constructor
    Producto(int cantidad, string concepto, float precio) {
        this->cantidad = cantidad;
        this->concepto = concepto;
        this->precio = precio;
    }

    // Destructor
    ~Producto() {
        cout << "Destruyendo producto" << endl;
    }

    float importe() {
        return cantidad * precio;
    }

    void mnostrar() {
        cout << cantidad << "\t\t" << concepto << "\t\t" << precio << "\t\t" << importe() << endl;
    }

*/