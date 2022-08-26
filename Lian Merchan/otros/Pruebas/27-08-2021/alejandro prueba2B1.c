#include<stdio.h>

void llenarDatos(int datos[], int tamano){
	int i;
	for(i=0;i<tamano;i++){
		printf("[%d] = ",i);
		scanf("%d",&datos[i]);
	}
}

int MCD(int a, int b) {
	int i=1,j=1;
	if(a>b){
		while(i<=a/2){
			i++;
			if(a%i==0)
				if(b%i==0)
						j=i;
		}
			return j;
	}
	else if(a==b)
		return a;
	else{
		while(i<=b/2){
			i++;
			if(b%i==0)
				if(a%i==0)
					j=i;
		}/*fin while*/
	return j;
	}
	
}

void parejas(int datos[],int tamano){
	int i;
	for(i=tamano; i>tamano/2 ;i--){
		printf( "El MCD de %d y %d es: %d\n", datos[tamano-i],datos[i-1],MCD(datos[tamano-i],datos[i-1]));
	}
}

int main(){

	int datos[10], tamano=0;
	while(!(tamano<10 && tamano>0 && tamano%2==0)){
			printf("Cuantos datos desea guardar?: ");
			scanf("%d", &tamano);
	}
	printf("Ingrese datos: \n")
	llenarDatos(datos, tamano);

	parejas(datos, tamano);


}