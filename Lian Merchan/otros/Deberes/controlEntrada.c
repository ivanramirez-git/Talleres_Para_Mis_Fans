#include<stdio.h>

int main(){
	int n=0, entrada;
	do{
		printf("Ingrese cantidad de personas entran-salen: \n");
		scanf("%d",&entrada);
		if((n+entrada)<0){
			printf("No existe la posibilidad de que salgan mas personas de las que hay en el bar.\n");
		}else if((n+entrada)<100){
			n=n+entrada;
			printf("Hay %d personas en el bar.\n",n);
		}else if(n+entrada != 100){
			printf("El bar no tiene capacidad para este grupo de personas\n");
		}else{
			n=n+entrada;
		}
	}while(n!=100);
	
	printf("El bar está lleno, gracias!!\n");

	return 0;
}
