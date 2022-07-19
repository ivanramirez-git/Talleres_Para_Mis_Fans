// in out stream library
#include <iostream>
// ramdom library
#include <cstdlib>
// time library
#include <ctime>

using namespace std;
void generar_clientes(int clientes[])
{
    for (int i = 0; i < 150; i++)
    {
        clientes[i] = rand() % 5;
    }
}

void mostrar_clientes_planes(int clientes[], string planes[])
{
    cout << "Clientes y planes:" << endl;
    for (int i = 0; i < 150; i++)
    {
        cout << "Cliente " << i + 1 << " : " << planes[clientes[i]] << endl;
    }
}

void calcular_recaudacion(int clientes[], int valor[], string planes[])
{
    int recaudacion[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 150; i++)
    {
        recaudacion[clientes[i]] += valor[clientes[i]];
    }
    cout << "Recaudacion por categoria:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Categoria " << planes[i] << " : " << recaudacion[i] << endl;
    }
}

void plan_mas_vendido(int clientes[], int valor[], string planes[])
{
    int mayor = 0;
    int posicion = 0;
    int cantidades[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 150; i++)
    {
        cantidades[clientes[i]]++;
    }
    for (int i = 0; i < 5; i++)
    {
        if (cantidades[i] > mayor)
        {
            mayor = cantidades[i];
            posicion = i;
        }
    }
    cout << "Plan mas vendido: " << planes[posicion] << endl;
    cout << "Cantidad de ventas: " << mayor << endl;
}

void plan_menos_vendido(int clientes[], int valor[], string planes[])
{
    int menor = 150;
    int posicion = 0;
    int cantidades[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 150; i++)
    {
        cantidades[clientes[i]]++;
    }
    for (int i = 0; i < 5; i++)
    {
        if (cantidades[i] < menor)
        {
            menor = cantidades[i];
            posicion = i;
        }
    }
    cout << "Plan menos vendido: " << planes[posicion] << endl;
    cout << "Cantidad de ventas: " << menor << endl;
}

int main()
{
    srand(time(NULL));
    int valor[] = {700, 950, 1050, 1250, 1500};
    string planes[] = {"A", "B", "C", "D", "E"};
    // Ingresar 150 clientes a los cuales se les colocara los planes de maera aleatoria a,b,c,d,e
    int clientes[150];
    generar_clientes(clientes);
    // mostrar los datos ingresados
    mostrar_clientes_planes(clientes, planes);
    // calcular la cantidad recaudada por cada categoria
    calcular_recaudacion(clientes, valor, planes);
    // mostrar la recaudacion por cada categoria
    plan_mas_vendido(clientes, valor, planes);
    // el menos vendido y la cantidad de ventas
    plan_menos_vendido(clientes, valor, planes);
    return 0;
}
