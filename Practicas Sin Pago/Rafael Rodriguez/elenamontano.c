#include <stdio.h>

int main(){
    // a) Pedir un arreglo Bidimencional, leyendo primero las columnas y luego las filas.
    printf("a) Pedir un arreglo Bidimencional, leyendo primero las columnas y luego las filas: \n");
    int col, fil;
    printf("Ingreses el numero de columnas: ");
    scanf("%d", &col);
    printf("Ingreses el numero de filas: ");
    scanf("%d", &fil);
    int A[col][fil];
    int i, j;
    for(i=0; i<col; i++){
        for(j=0; j<fil; j++){
            printf("Ingreses el valor de la posicion [%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");
    // b) Mostrar el arreglo
    printf("b) Mostrar el arreglo: \n");
    for(i=0; i<col; i++){
        for(j=0; j<fil; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    // c) Encontrar el numero mayor de la diagonal invertida
    printf("c) Encontrar el numero mayor de la diagonal invertida: \n");
    int mayor = A[0][0];
    for(i=0; i<col; i++){
        for(j=0; j<fil; j++){
            // Diagonal invertida
            int pos = (col-1)-i;
            if(pos == j){
                if(A[i][j] > mayor){
                    mayor = A[i][j];
                }
            }
        }
    }
    printf("El numero mayor de la diagonal invertida es: %d\n", mayor);
    // d) Encontrar cuantos numero pares existen en el arreglo
    printf("d) Encontrar cuantos numero pares existen en el arreglo: \n");
    int cont = 0;
    for(i=0; i<col; i++){
        for(j=0; j<fil; j++){
            if(A[i][j]%2==0){
                cont++;
            }
        }
    }
    printf("El numero de pares en el arreglo es: %d\n", cont);
    // e) Sumar los numeros que se encuentren en la diagonal
    printf("e) Sumar los numeros que se encuentren en la diagonal: \n");
    int suma = 0;
    for(i=0; i<col; i++){
        for(j=0; j<fil; j++){
            if(i==j){
                suma += A[i][j];
            }
        }
    }
    printf("La suma de los numeros que se encuentren en la diagonal es: %d\n", suma);
    // f) Encontrar el numero mayor de toda la matriz
    printf("f) Encontrar el numero mayor de toda la matriz: \n");
    int mayor2 = A[0][0];
    for(i=0; i<col; i++){
        for(j=0; j<fil; j++){
            if(A[i][j] > mayor2){
                mayor2 = A[i][j];
            }
        }
    }
    printf("El numero mayor de toda la matriz es: %d\n", mayor2);
    // g) Encontrar el numero menor de toda la matriz
    printf("g) Encontrar el numero menor de toda la matriz: \n");
    int menor2 = A[0][0];
    for(i=0; i<col; i++){
        for(j=0; j<fil; j++){
            if(A[i][j] < menor2){
                menor2 = A[i][j];
            }
        }
    }
    printf("El numero menor de toda la matriz es: %d\n", menor2);
    // h) Ordenar los elementos de la diagonal de mayor a menor
    printf("h) Ordenar los elementos de la diagonal de mayor a menor: \n");
    int aux;
    int mayor3 = 0;
    if (col < fil){
        mayor3 = col;
    } else {
        mayor3 = fil;
    }
    int A_aux[mayor3];
    for(i=0; i<col; i++){
        for(j=0; j<fil; j++){
            if(i==j){
                A_aux[i] = A[i][j];
            }
        }
    }
    for(i=0; i<mayor3; i++){
        for(j=0; j<mayor3-1; j++){
            if(A_aux[j] < A_aux[j+1]){
                aux = A_aux[j];
                A_aux[j] = A_aux[j+1];
                A_aux[j+1] = aux;
            }
        }
    }
    // Copiar A_aux en A
    for(i=0; i<mayor3; i++){
        A[i][i] = A_aux[i];
    }
    // Mostrar el arreglo
    for(i=0; i<col; i++){
        for(j=0; j<fil; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    // i) Encontrar cuantos numeros primos existen en la matriz
    printf("i) Encontrar cuantos numeros primos existen en la matriz: \n");
    int cont2 = 0;
    for(i=0; i<col; i++){
        for(j=0; j<fil; j++){
            // Primos
            int primo = 1;
            for(int k=2; k<A[i][j]; k++){
                if(A[i][j]%k==0){
                    primo = 0;
                }
            }
            if(primo==1){
                cont2++;
            }
        }
    }
    printf("El numero de primos en la matriz es: %d\n", cont2);

    return 0;
}