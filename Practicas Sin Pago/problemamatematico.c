// programa que muestre la cantidad de numeros pares que hay en una matriz e indique cuantos de ellos son multiplos de un numero X
// sumar las columnas y guardar en otro arreglos
// sumar las filas
// Muestre el valor maximo y su ubicacion dentro de la tabala
// Muestre la suma total de los valores de la tabla
// Cual es el maximo valor de la sumatoria

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fil, col, suma = 0, max, multiplo, sT = 0, X;
	int tabla[5][4] = {{25, 32, 62, 45}, {15, 24, 98, 67}, {21, 37, 24, 62}, {14, 26, 48, 35}, {21, 20, 48, 56}};
	int sF[] = {0, 0, 0, 0, 0}, sC[] = {0, 0, 0, 0, 0};

	// indique cuantos de ellos son multiplos de un numero X
	printf("Ingrese un numero: ");
	scanf("%d", &X);
	
	// multiplos de X
	for (fil = 0; fil < 5; fil++)
	{
		for (col = 0; col < 4; col++)
		{
			if (tabla[fil][col] % X == 0)
			{
				printf("%d es multiplo de %d\n", tabla[fil][col], X);
			}
		}
	}



	for (fil = 0; fil < 5; fil++)
		printf("%d\t", sF[fil]);
	printf("\n");

	for (fil = 0; fil < 5; fil++)
	{
		for (col = 0; col < 4; col++)
		{
			printf("%d\t", tabla[fil][col]);
		}
		printf("\n");
	}
	// hallar el maximo
	for (fil = 0; fil < 5; fil++)
	{

		for (col = 0; col < 4; col++)
		{
			if (tabla[fil][col] > max)
			{
				max = tabla[fil][col];
			}
		}
	}
	printf("\nEl MAXIMO DE LA TABLA ES: %d ", max);

	// HALLAR LA SUMA
	for (fil = 0; fil < 5; fil++)
	{
		for (col = 0; col < 4; col++)
		{
			suma = suma + tabla[fil][col];
		}
	}
	printf("\nEL VALOR DE LA SUMA TOTAL DE LA TABLA ES: %d\n ", suma);

	for (fil = 0; fil < 5; fil++)
	{
		for (col = 0; col < 4; col++)
		{
			sF[fil] = sF[fil] + tabla[fil][col];
		}
	}
	printf("\n suma de filas \n");
	for (col = 0; col < 4; col++)
	{
		printf("\n%d", sF[col]);
	}
	for (col = 0; col < 4; col++)
	{
		for (fil = 0; fil < 5; fil++)
		{
			sC[col] = sC[col] + tabla[fil][col];
		}
	}
	printf("\n\n suma de columnas \n");
	for (col = 0; col < 4; col++)
	{
		printf("\n%d", sC[col]);
	}
	// pares
	printf("\n\n LOS NUMEROS PARES SON: \n");
	for (col = 0; col < 4; col++)
	{
		for (fil = 0; fil < 5; fil++)
		{
			if (tabla[fil][col] % 2 == 0)
				printf("\nEl numero en %d es par.\n", tabla[fil][col]);
		}
	}
	// MULTIPLOS DE UN NUMERO X
	for (col = 0; col < 4; col++)
	{
		for (fil = 0; fil < 5; fil++)
		{
			printf("Digita un numero que esté en la matriz ", X);
			scanf("%d", X);

			if (tabla[fil][col] % multiplo == 0)
				printf("\nEl multiplo del numero es: %d ", multiplo);
		}
	}

	// me falta calular el multiplo de un numero X en base a la matriz
	

	return 0;
}