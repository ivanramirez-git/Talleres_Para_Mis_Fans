#pragma once
#include <string>
#include <vector>
#include <list>
#include "Cliente.h"
using namespace std;
class ClienteIO
{
private:
	string nombreArchivoCliente;
public:
	vector<Cliente> leerClientes();
	void escribirCliente(Cliente c);
	void clonarOrdenado(list<Cliente> lista, string nombre)
};

