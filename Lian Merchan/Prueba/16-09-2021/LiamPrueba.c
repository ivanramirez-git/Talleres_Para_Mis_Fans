#include<stdio.h>
#include <stdbool.h>

void menu();
bool validacion(int numero);
void suma(int num1, int num2);
void resta(int num1, int num2);
void multiplicacion(int num1, int num2);
void division(int num1, int num2);


int main(){
	int caso=0,num1,num2;
	while(caso!=5){
		menu();
		scanf("%d", &caso);
		switch(caso){
			case 1:		    
				printf("num1: ");
				scanf("%d",&num1);
				printf("num2: ");				
				scanf("%d",&num2);
				suma(num1,num2);
			break;
			case 2:
				printf("num1: ");
				scanf("%d",&num1);
				printf("num2: ");				
				scanf("%d",&num2);
				resta(num1,num2);
			break;
			case 3:
				printf("num1: ");
				scanf("%d",&num1);
				printf("num2: ");				
				scanf("%d",&num2);
				multiplicacion(num1,num2);
				
			break;			
			case 4:				
				printf("num1: ");
				scanf("%d",&num1);
				printf("num2: ");				
				scanf("%d",&num2);
				if(validacion(num2))
				{					
					division(num1,num2);
				}
				else
				{
					printf("No se puede dividir en 0\n");
				}
			break;
		}
	}
}

void menu(){
	
	printf("**************Menu************\n");
	printf("Programa realizado por: Sebas Pazmino \n");
	printf("1. Suma\n");
	printf("2. Resta\n");
	printf("3. Multiplicacion\n");
	printf("4. Division\n");
	printf("5. Salir\n");
}
bool validacion(int numero){
    if(numero==0){
        return false;
	}else{
    	return true;
	}
}
void suma(int num1, int num2){
	num2=num1+num2;
	printf("%d\n", num2);
}
void resta(int num1, int num2){
	num2=num1-num2;
	printf("%d\n", num2);
}
void multiplicacion(int num1, int num2){
	num2=num1*num2;
	printf("%d\n", num2);
}
void division(int num1, int num2){
	num2=num1/num2;
	printf("%d\n", num2);
}
