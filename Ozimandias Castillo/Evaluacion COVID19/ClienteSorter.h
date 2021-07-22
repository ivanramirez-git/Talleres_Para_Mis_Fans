#pragma once
#include <list>
#include <vector>
#include "Cliente.h"
class ClienteSorter
{
private:
	list<Cliente> listaClientes;
public:
	void OrdenarPorApellidos(char tipo);
	void OrdenarPorCI();
	void OrdenarPorTemperatura();
	list<Cliente> ObtenerTemperaturasElevadas(int cantidad);
	int ObtenerCantidadClientes();
	void VectorToListCliente(vector<Cliente> vector);

};

