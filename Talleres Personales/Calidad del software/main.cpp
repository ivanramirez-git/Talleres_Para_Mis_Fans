// Your C++ Program

#include <iostream>

/*
Una de las bodegas más grandes de una central de abastos (Bodega de Todos y para Todos)
tiene una gran variedad de productos de primera necesidad y sus principales clientes son
supermercados grandes y grandes almacenes.

Debido a la pandemia y como una medida de reactivación económica, el gerente general ha
decidido conceder un descuento del 8% a aquellos clientes recurrentes que compran
mensualmente.

El descuento se aplicará a aquellos clientes cuyas compras netas totales de los últimos 6
meses anteriores superen los 500 millones de pesos. El descuento será aplicado a la cuenta
del último mes (actual).

Adicionalmente, la gerencia impartió una restricción para aplicar a este beneficio y que consiste
en lo siguiente: el descuento no aplicará a aquellos clientes que realicen devoluciones de
productos por valor superior al 15% de sus compras netas durante los últimos 6 meses.
*/

using namespace std;

struct cliente
{
    string nombre;
    int compra;
    int devolucion;
};

struct ventasMes;
{
    string mes;
    vector<Cliente> clientes;  
};


int main() {

    vector<ventasMes> ventasMeses;
    Cliente cliente;    // Grupo 4
    for(int i=0;i<ventasMeses.darUltimoMes().clientes.size();i++){

        cliente=ventasMeses.darUltimoMes().clientes[i];   
        if(ventasMeses.sumarCompras(cliente, 6) > 500){
            if(ventasMeses.sumarDevoluciones(cliente, 6)< ventasMeses.sumarCompras(cliente, 6)*0.15 ){
                ventasMeses.aplicarDescuento(cliente,"mes_actual",8);
            }
        }
    }    

    //cout << "Hello World!";
    return 0;
}
