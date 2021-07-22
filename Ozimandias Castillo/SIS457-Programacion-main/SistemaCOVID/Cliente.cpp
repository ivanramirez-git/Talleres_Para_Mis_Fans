#include "Cliente.h"
Cliente::Cliente()
{
	ci = 5680547;
	temperatura = 37.1f;
	nombres = "Alejandro";
	apellidos = "Arando";
}
Cliente::Cliente(int c, float t, string n, string ap) {
	ci = c;
	temperatura = t;
	nombres = n;
	apellidos = ap;
}
string Cliente::getNombreCompleto()
{
	return nombres + " " + apellidos;
}