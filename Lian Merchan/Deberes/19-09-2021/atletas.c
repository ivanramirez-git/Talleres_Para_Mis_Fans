#include<stdio.h>
#define MAX_ATLETAS 10
#define NUMERO_PODIO 3

struct Atleta{
  char nombre[80];
  int tiempo_inicial;
  int tiempo_final;  
};

char validarNumero(int n){
    if(n>MAX_ATLETAS)
        return 'n';
    return 's';
}

void ingresarAtletas(struct Atleta competencia[MAX_ATLETAS], int n){
    int i;
    for(i=0;i<n;i++){
        printf("Nombre[%d]:",i);
        scanf("%s", competencia[i].nombre);

        printf("Tiempo inicial[%d]:",i);
        scanf("%d", &competencia[i].tiempo_inicial);
        

        printf("Tiempo final[%d]:",i);
        scanf("%d", &competencia[i].tiempo_final);
    }
}

void ordenarAtletas(struct Atleta competencia[], int n){
    struct Atleta temporal;

    int i,j;
    for(i=0;i<n;i++){
        for(j=0; j<(n-1); j++){
            if((competencia[i].tiempo_final-competencia[i].tiempo_inicial)<(competencia[j].tiempo_final-competencia[j].tiempo_inicial)){
                temporal=competencia[j];
                competencia[j]=competencia[i];
                competencia[i]=temporal;
            }
        }
    }
}

void imprimirAtletas(struct Atleta competencia[], int podio){
    int i;
    printf("Nombre\tT. Inicial\tT.Final\tT.Total\n");
    for(i=0;i<podio;i++){
        printf("%s\t%d\t%d\t%d\n",competencia[i].nombre,competencia[i].tiempo_inicial,competencia[i].tiempo_final,(competencia[i].tiempo_final-competencia[i].tiempo_inicial));
    }
}

//Complete aquí su código
int main(){
    struct Atleta competencia[MAX_ATLETAS];
    int n;
    printf("Competencia atletica\n");
    printf("Ingrese el numero de atletas: ");
    scanf("%d", &n);
    if(validarNumero(n) == 'n'){
        printf("Numero invalido!");
        return -1;
    }
    ingresarAtletas(competencia, n);
    ordenarAtletas(competencia, n);
    printf("Podio\n");
    imprimirAtletas(competencia, NUMERO_PODIO);
}
//Complete aquí su código