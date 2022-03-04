#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TAM 100

int tope = -1, max = MAX_TAM - 1, dato, band, pila[MAX_TAM];
char cadena[MAX_TAM][MAX_TAM], datoChar[MAX_TAM];
int topeC = -1, maxC = MAX_TAM - 1, datoC, bandC;

// consola Int
void PilaVacia();
void PilaLLena();
void Pone();
void Quita();
void Visualizar();
int Buscar();

// parametros Int
void PilaVaciaInt();
void PilaLLenaInt();
void PoneInt(int);
void QuitaInt(int);
void VisualizarInt();
int BuscarInt(int);

// parametros Char
void PilaVaciaChar();
void PilaLLenaChar();
void PoneChar(char[]);
void QuitaChar(char[]);
void VisualizarChar();
int BuscarChar(char[]);
void ImprimirChar(int);

// consola Int
void PilaVacia()
{
	if (tope == -1)
	{
		band = 1;
	}
	else
	{
		band = 0;
	}
}

void PilaLLena()
{
	if (tope == max)
	{
		band = 1;
	}
	else
	{
		band = 0;
	}
}

void Pone()
{
	PilaLLena();
	if (band == 1)
	{
		printf("\nPila LLena, no hay elementos a vaciar de la pila\n");
	}
	else
	{
		printf("\nIngrese el dato:  ");
		scanf("%d", &dato);
		tope = tope + 1;
		pila[tope] = dato;
	}
}

void Quita()
{
	PilaVacia();
	if (band == 1)
	{
		printf("Pila Vacia\n");
	}
	else
	{
		printf("El elemento en la posicion %d fue eliminado!!!\n", tope);
		dato = pila[tope];
		tope = tope - 1;
	}
}

void Visualizar()
{
	if (tope >= 0)
	{
		printf("\nLos datos de pila son: \n");
		for (int i = 0; i <= tope; i++)
		{
			printf("| %d |\n", pila[i]);
		}
	}
	else
	{
		printf("\nPila Vacia\n");
	}
}

int Buscar()
{
	int buscar, i;
	printf("\nIngrese el dato a buscar:  ");
	scanf("%d", &buscar);
	for (i = 0; i <= tope; i++)
	{
		if (pila[i] == buscar)
		{
			return i;
		}
	}
	if (i > tope)
	{
		printf("\nEl dato %d no se encuentra en la pila\n", buscar);
	}

	return -1;
}

// parametros Int
void PilaVaciaInt()
{
	if (tope == -1)
	{
		band = 1;
	}
	else
	{
		band = 0;
	}
}

void PilaLLenaInt()
{
	if (tope == max)
	{
		band = 1;
	}
	else
	{
		band = 0;
	}
}

void PoneInt(int dato)
{
	PilaLLenaInt();
	if (band == 1)
	{
		printf("\nPila LLena, no hay elementos a vaciar de la pila\n");
	}
	else
	{
		tope = tope + 1;
		pila[tope] = dato;
	}
}

void QuitaInt(int dato)
{
	PilaVaciaInt();
	if (band == 1)
	{
		printf("Pila Vacia\n");
	}
	else
	{
		printf("El elemento en la posicion %d fue eliminado!!!\n", tope);
		dato = pila[tope];
		tope = tope - 1;
	}
}

void VisualizarInt()
{
	if (tope >= 0)
	{
		printf("\nLos datos de pila son: \n");
		for (int i = 0; i <= tope; i++)
		{
			printf("| %d |\n", pila[i]);
		}
	}
	else
	{
		printf("\nPila Vacia\n");
	}
}

int BuscarInt(int buscar)
{
	int i;
	for (i = 0; i <= tope; i++)
	{
		if (pila[i] == buscar)
		{
			printf("\nEl dato %d se encuentra en la posicion %d\n", buscar, i);
			return i;
		}
	}
	if (i > tope)
	{
		printf("\nEl dato %d no se encuentra en la pila\n", buscar);
	}
}

// parametros Char
void PilaVaciaChar()
{
	if (topeC == -1)
	{
		bandC = 1;
	}
	else
	{
		bandC = 0;
	}
}

void PilaLLenaChar()
{
	if (topeC == maxC)
	{
		bandC = 1;
	}
	else
	{
		bandC = 0;
	}
}

void PoneChar(char dato[])
{
	PilaLLenaChar();
	if (bandC == 1)
	{
		printf("\nPila LLena, no hay elementos a vaciar de la pila\n");
	}
	else
	{
		topeC = topeC + 1;
		strcpy(cadena[topeC], dato);
	}
}

void QuitaChar(char dato[])
{
	PilaVaciaChar();
	if (bandC == 1)
	{
		printf("Pila Vacia\n");
	}
	else
	{
		printf("El elemento en la posicion %d fue eliminado!!!\n", topeC);
		strcpy(dato, cadena[topeC]);
		topeC = topeC - 1;
	}
}

void VisualizarChar()
{
	if (topeC >= 0)
	{
		printf("\nLos datos de pila son: \n");
		for (int i = 0; i <= topeC; i++)
		{
			printf("| %s |\n", cadena[i]);
		}
	}
	else
	{
		printf("\nPila Vacia\n");
	}
}

int BuscarChar(char buscar[])
{
	int i;
	for (i = 0; i <= topeC; i++)
	{
		if (strcmp(cadena[i], buscar) == 0)
		{
			printf("\nEl dato %s se encuentra en la posicion %d\n", buscar, i);
			return i;
		}
	}
	if (i > topeC)
	{
		printf("\nEl dato %s no se encuentra en la pila\n", buscar);
	}
}

void ImprimirChar(int posicion)
{
	printf("\n %s\n", cadena[posicion]);
}
