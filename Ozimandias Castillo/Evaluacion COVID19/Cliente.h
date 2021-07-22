#pragma once
#include <string>
using namespace std;
class Cliente
{
public:
	int ci;
	float temperatura;
	
public:
	string nombres;
	string apellidos;
	string getNombreCompleto();
	Cliente();
	Cliente(int c, float t, string n, string ap);




};

