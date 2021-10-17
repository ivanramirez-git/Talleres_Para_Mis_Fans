#include<stdio.h>
#include <math.h>

int triangulo(int a, int b, int c){
	if(	(a<(b+c))	&&	(b<(a+c))	&&	(c<(b+a)) ){
		return 1;
	}
	return 0;
}

//formula de Heron
float area(int a, int b, int c){
	int af=a+0.00, bf=b+0.00, cf=c+0.00;

	float sp=(af+bf+cf)/2.00;

	return sqrt(sp*(sp-af)*(sp-bf)*(sp-cf));
}

int main(){
	int a,b,c;
	printf("Ingrese la longitud de los tres lados: ");
	scanf("%d %d %d",&a,&b,&c);
	
	if(triangulo(a,b,c)==1){
		printf("\nEl area del triangulo es: %0.2f\n", area(a,b,c));
	}else{
		printf("\nNo se puede formar un triangulo!!\n");
	}

	return 0;
}
