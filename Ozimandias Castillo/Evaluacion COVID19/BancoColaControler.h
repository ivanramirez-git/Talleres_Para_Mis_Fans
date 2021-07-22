#pragma once
#include <queue>

#include "Cliente.h"
class BancoColaControler
{
private:
	queue<Cliente> colaClientes;
	int NroCliente;
public:
	void AgregarCola(Cliente c);
	Cliente AtenderrCola();
};

