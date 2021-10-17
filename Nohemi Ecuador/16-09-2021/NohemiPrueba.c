#include<stdio.h>

void menu(){
	printf("1. Suma\n");
	printf("2. Resta\n");
	printf("3. Multiplicacion\n");
	printf("4. Division\n");
	printf("5. Salir\n");
	printf("Ingrese opcion: ");
}

char validar(int n){
    if(n==0)
        return 'n';
    return 's';
}

int suma(int n1, int n2){
	return n1+n2;
}
int resta(int n1, int n2){
	return n1-n2;
}
int multiplicacion(int n1, int n2){
	return n1*n2;
}
int division(int n1, int n2){
	return n1/n2;
}

int main(){
	int n1, n2;
	int opcion;
	do{
		menu();
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				printf("Suma\n");
				printf("Ingrese dos numeros: ");
			    scanf("%d %d", &n1, &n2);
			    printf("%d + %d = %d\n", n1, n2, suma(n1,n2));
			break;
			case 2:
				printf("Resta\n");
				printf("Ingrese dos numeros: ");
			    scanf("%d %d", &n1, &n2);
			    printf("%d - %d = %d\n", n1, n2, resta(n1,n2));
			break;
			case 3:
				printf("Multiplicacion\n");
				printf("Ingrese dos numeros: ");
			    scanf("%d %d", &n1, &n2);
			    printf("%d * %d = %d\n", n1, n2, multiplicacion(n1,n2));
				
			break;			
			case 4:
				printf("Division\n");
				printf("Ingrese dos numeros: ");
			    scanf("%d %d", &n1, &n2);
			    if(validar(n2)=='n'){
			        printf("No se puede dividir por 0\n");
			    }else{
			    	printf("%d / %d = %d\n", n1, n2, division(n1,n2));
				}
			break;			
			case 5:
				return 0;
			break;
			default:
				printf("Opcion no valida.");
			break;
		}
	}while(1);

}
