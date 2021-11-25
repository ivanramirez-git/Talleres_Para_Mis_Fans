#include <iostream>

using namespace std;

class Vivienda
{
protected:
    float precio;
    // Variable tipo para indicar si la vivienda es de tipo Obra negra o Acabados
    char tipo;
public:

    Vivienda()
    {
        precio = 0;
        tipo = 'v';
    }

    Vivienda(float precio, char tipo)
    {
        this->precio = precio;
        this->tipo = tipo;
        
    }

    virtual float getPrecio()
    {
        return precio;
    }

    virtual void setPrecio(float precio)
    {
        this->precio = precio;
    }

    virtual char getTipo()
    {
        return tipo;
    }

    virtual void setTipo(char tipo)
    {
        this->tipo = tipo;
    }

};

class ObraNegra : public Vivienda
{
private:
    int metrosCuadrados;
public:

    ObraNegra(): Vivienda()
    {
        metrosCuadrados = 0;
    }

    ObraNegra(float precio, int metrosCuadrados): Vivienda(precio,'o')
    {
        this->metrosCuadrados = metrosCuadrados;
    }

    int getMetrosCuadrados()
    {
        return metrosCuadrados;
    }

    void setMetrosCuadrados(int metrosCuadrados)
    {
        this->metrosCuadrados = metrosCuadrados;
    }

    float getPrecio()
    {
        if(metrosCuadrados <= 60)
        {
            return precio * 0.9;
        }
        return precio;
    }
    
};

class Acabados : public Vivienda
{
private:
    int estrato;
public:
    
    Acabados(): Vivienda()
    {
        estrato = 0;
    }

    Acabados(float precio, int estrato): Vivienda(precio,'a')
    {
        this->estrato = estrato;
    }

    int getEstrato()
    {
        return estrato;
    }

    void setEstrato(int estrato)
    {
        this->estrato = estrato;
    }

    float getPrecio()
    {
        if(estrato >= 4 )
        {
            return precio * 1.2;
        }
        return precio;
    }

};

int main()
{
    float precioBase;
    cout << "Ingrese el precio base de las viviendas: ";
    cin >> precioBase;

    int cantidadClientes;
    cout << "Ingrese la cantidad de clientes a evaluar: ";
    cin >> cantidadClientes;



    Vivienda viviendas[cantidadClientes];
    ObraNegra obraNegras[cantidadClientes];
    Acabados acabados[cantidadClientes];


    for(int i = 0; i < cantidadClientes; i++)
    {
        int opcion;
        cout << "Ingrese el tipo de vivienda a crear: " << endl;
        cout << "1. Obra Negra" << endl;
        cout << "2. Acabados" << endl;
        cin >> opcion;

        if(opcion == 1)
        {
            float precio;
            int metrosCuadrados;
            precio = precioBase;
            // Bandera precio
            cout << "Ingrese los metros cuadrados de la vivienda: ";
            cin >> metrosCuadrados;
            obraNegras[i] = ObraNegra(precio, metrosCuadrados);
            viviendas[i] = obraNegras[i];
        }
        else if(opcion == 2)
        {
            float precio;
            int estrato;
            precio = precioBase;
            cout << "Ingrese el estrato de la vivienda: ";
            cin >> estrato;
            acabados[i] = Acabados(precio, estrato);
            viviendas[i] = acabados[i];
        }
    }

    for(int i = 0; i < cantidadClientes; i++)
    {
        cout << "Vivienda " << i+1 << endl;
        if(viviendas[i].getTipo() == 'o')
        {
            cout << "Tipo: Obra Negra" << endl;
            cout << "Precio: " << obraNegras[i].getPrecio() << endl;
            cout << "Metros cuadrados: " << obraNegras[i].getMetrosCuadrados() << endl;
        }
        else if(viviendas[i].getTipo() == 'a')
        {
            cout << "Tipo: Acabados" << endl;
            cout << "Precio: " << acabados[i].getPrecio() << endl;
            cout << "Estrato: " << acabados[i].getEstrato() << endl;
        }
        else
        {
            cout << "Tipo: Vivienda" << endl;
            cout << "Precio: " << viviendas[i].getPrecio() << endl;
        }
    }

    return 0;
}