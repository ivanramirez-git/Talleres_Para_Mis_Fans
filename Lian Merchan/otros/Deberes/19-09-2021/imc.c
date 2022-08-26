#include <stdio.h>
#include <stdlib.h>
#define MAX 40
//Aqui su codigo

struct paciente{
    char nombre[MAX];
    float peso;
    float altura;
};

void leer(struct paciente pacientes[MAX], int n);
void inferior(struct paciente pacientes[], int n);
void normal (struct paciente pacientes[], int n);
void superior (struct paciente pacientes[], int n);
void obesidad (struct paciente pacientes[], int n);

int main()
{
    //Aqui su codigo
    struct paciente pacientes[MAX];
    int n;
    char selec;
    printf("Salud Estudiantil EPN\n");
    printf("Ingrese el numero de pacientes:");
    //Aqui su codigo
    scanf("%d",&n);
    leer(pacientes,n);
    printf("Seleccione el tipo de estado de pacientes a listar:\n");
    printf("a: pacientes con peso inferior al normal\n");
    printf("b: pacientes con peso normal\n");
    printf("c: pacientes con peso superior al normal\n");
    printf("d: pacientes con obesidad\n");
    scanf("\n%c",&selec);

    switch(selec){
        case 'a':
            inferior(pacientes,n);
            break;
        case 'b':
            normal(pacientes,n);
            break;
        case 'c':
            superior(pacientes,n);
            break;
        case'd':
            obesidad(pacientes,n);
            break;
        default:
            printf("\nSeleccion Invalida!");
    }

    return 0;
}
//Aqui su codigo

void leer(struct paciente pacientes[MAX], int n){
    int i;
    for(i=0;i<n;i++){

        printf("nombre[%d]:",i);
        scanf("%s",pacientes[i].nombre);
        printf("peso-KG[%d]:",i);
        scanf("%f",&pacientes[i].peso);        
        printf("Altura[%d]:",i);
        scanf("%f",&pacientes[i].altura);
        printf("\n");  
    }
}

void inferior(struct paciente pacientes[], int n){
    printf("\n");
    int i, c=0;
    float IMC;
    for(i=0;i<n;i++){
        IMC=pacientes[i].peso/(pacientes[i].altura*pacientes[i].altura);
        if(IMC<18.5){
            printf("%s: Peso inferior al normal\n",pacientes[i].nombre);
            c++;
        }
    }
    if(!(c>0)){
        printf("No existen pacientes con peso inferior al normal\n");
    }
}

void normal (struct paciente pacientes[], int n){
    printf("\n");
    int i, c=0;
    float IMC;
    for(i=0;i<n;i++){
        IMC=pacientes[i].peso/(pacientes[i].altura*pacientes[i].altura);
        if(IMC>18.5 && IMC<24.9){
            printf("%s: Peso normal\n",pacientes[i].nombre);
            c++;
        }
    }
    if(!(c>0)){
        printf("No existen pacientes con peso normal\n");
    }
}

void superior (struct paciente pacientes[], int n){
    printf("\n");
    int i, c=0;
    float IMC;
    for(i=0;i<n;i++){
        IMC=pacientes[i].peso/(pacientes[i].altura*pacientes[i].altura);
        if(IMC>25.0 && IMC<29.9){
            printf("%s: Peso superior al normal\n",pacientes[i].nombre);
            c++;
        }
    }
    if(!(c>0)){
        printf("No existen pacientes con peso superior al normal\n");
    }
}

void obesidad (struct paciente pacientes[], int n){
    printf("\n");
    int i, c=0;
    float IMC;
    for(i=0;i<n;i++){
        IMC=pacientes[i].peso/(pacientes[i].altura*pacientes[i].altura);
        if(IMC>30.0){
            printf("%s: Obesidad\n",pacientes[i].nombre);
            c++;
        }
    }
    if(!(c>0)){
        printf("No existen pacientes con Obesidad\n");
    }
}
