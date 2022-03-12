#include <stdio.h>
#define MAX 100

int lecturacadena(char c[]){
    int i=0;
    printf("Ingrese cadena: ");
    while((c[i]=getchar())!='\n'){
        i++;
    }
    c[i]='\0';
    return i;
}

int lecturacaracteres(char c[]){
    int i=0;
    while(i<3){
        printf("Caracter a suprimir %d: ",i+1);        
        c[i]=getchar();
        fflush(stdin);
        i++;
    }
    c[i]='\0';
    return i;
}

void eliminacaracteres(char cadena[], int n_cadena, char caracteres[], int n_caracteres){
    // Elimina todos los caracteres de la cadena, asi sea mayuscula o minuscula
    int i,j,k;
    for(i=0;i<n_cadena;i++){
        for(j=0;j<n_caracteres;j++){
            if(cadena[i]==caracteres[j] || cadena[i]==caracteres[j]+32 || cadena[i]==caracteres[j]-32){
                for(k=i;k<n_cadena-1;k++){
                    cadena[k]=cadena[k+1];
                }
                cadena[n_cadena-1]='\0';
                n_cadena--;
                i--;
            }
        }
    }
}

void imprimircadena(char c[], int n){
    int i;
    printf("Resultado: ");
    for(i=0;i<n;i++){
        printf("%c",c[i]);
    }
}

int main(){
    printf("Prueba 4: Nombre [num unico]\n");
    printf("Supresion de caracteres\n");
    char cadena[MAX];
    int n_cadena;
    char caracteres[MAX];
    int n_caracteres;
    n_cadena=lecturacadena(cadena);
    n_caracteres=lecturacaracteres(caracteres);
    eliminacaracteres(cadena,n_cadena,caracteres,n_caracteres);
    imprimircadena(cadena,n_cadena);
    return 0;
}