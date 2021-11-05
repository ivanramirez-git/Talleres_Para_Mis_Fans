#include <stdio.h>

int main(){
	// Imprimir menu con dos opciones, validar que se ingrese una de las dos opciones
	// 1. Leer un numero de dos digitos y restar ambos digitos
	// 2. Leer 8 numeros impares y calcular su promedio
	
	// Declaracion de variables
	int opcion;
	int num1, num2, num3, num4, num5, num6, num7, num8;
	int resta, promedio;

	// Inicio del programa

	// Pedir opcion
	printf("Ingrese una opcion:\n");
	printf("1. Restar dos digitos\n");
	printf("2. Calcular promedio de 8 numeros impares\n");
	scanf("%d", &opcion);

	// Validar opcion
	while(opcion != 1 && opcion != 2){
		printf("Opcion incorrecta, ingrese una opcion:\n");
		printf("1. Restar dos digitos\n");
		printf("2. Calcular promedio de 8 numeros impares\n");
		scanf("%d", &opcion);
	}

	// Ejecutar opcion

	if(opcion == 1){
		// Leer dos digitos
		printf("Ingrese dos digitos:\n");
		scanf("%d", &num1);


		// Separa los digitos
		num2=num1%10;
		num1=num1/10;

		// Restar digitos
		resta = num1 - num2;
		
		printf("La resta de los digitos es: %d\n", resta);
	}

	if(opcion == 2){
		// Leer 8 numeros y validar que sean impares
		printf("Ingrese 8 numeros impares:\n");
		scanf("%d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8);

		// Validar que sean impares
		while(num1 % 2 == 0 || num2 % 2 == 0 || num3 % 2 == 0 || num4 % 2 == 0 || num5 % 2 == 0 || num6 % 2 == 0 || num7 % 2 == 0 || num8 % 2 == 0){
			printf("Uno de los numeros ingresados es par, ingrese 8 numeros impares:\n");
			scanf("%d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8);
		}

		// Calcular promedio
		promedio = (num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8) / 8;
		printf("El promedio de los numeros ingresados es: %d\n", promedio);
	}

	// Fin del programa

	return 0;
}
