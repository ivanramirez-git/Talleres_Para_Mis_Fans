#include <stdio.h>
#define LMAX 50

//Funciones que debe implementar

int validar(int f, int f2, int df){
	
	if(f>df){
		printf("Las filas solicitadas No existen en la matriz!!!");
		return 0;
	}if(f2>df){
		printf("Las filas solicitadas No existen en la matriz!!!");
		return 0;
	}
	return 1;
}
void ingresar(int df,int dc,int m[][dc]){
	int i, j;
	for(i=0; i<df;i++){
		for(j=0;j<dc;j++){
			printf("m[%d][%d]= ",i,j);
			scanf("%d",&m[i][j]);
		}
	}
}
void sumarFilas(int f,int c,int m[][c],int a,int b){
	int suma[f],i;
	for(i=0;i<c;i++){
		suma[i]=m[a][i]+m[b][i];
	}
	printf("La suma de las dos filas es:\n");
	for(i=0; i<f; i++){
		printf("suma[%d]=%d\n",i,suma[i]);
	}
}

int main()
{

	int df,dc,fila1,fila2, m1[LMAX][LMAX];
	printf("SUMA DE 2 FILAS DE UNA MATRIZ");
	printf("\nIngrese la dimension de filas y columnas: ");
	scanf("%d %d",&df,&dc);
	printf("Ingrese la matriz\n");
	ingresar(df,dc,m1);
	printf("Ingrese el numero de las 2 filas para la suma:");
	scanf("%d %d",&fila1,&fila2);
   
	//Complete el codigo de acuerdo a lo solicitado
	if(validar(fila1,fila2,df) == 1){
		sumarFilas(df,dc,m1,fila1,fila2);
	}
   return 0;
}

//Implemente las funciones solicitadasEste es el codigo
