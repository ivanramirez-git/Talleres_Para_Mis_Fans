#include <stdio.h>

int main()
{
    // Pedir N al usuario
    int N; // N = es el tamanio de los sumandos
    while(1){ // bucle infinito para validar que N sea mayor a 0
        printf("Ingrese el tamanio de los sumandos: "); // pedir N
        // Leer N
        scanf("%d", &N); // leer N
        if(N > 0){ // si N es mayor a 0
            break; // rompe el bucle
        }
    }

    //Crear vectores sumando1 y sumando2
    int sumando1[N]; // sumando1 = vector de N sumandos
    int sumando2[N]; // sumando2 = vector de N sumandos
    int resultado[N+1]; // resultado = vector de N+1 sumandos

    // Colocar en 0 el resultado
    for(int i = 0; i < N+1; i++){ // bucle para recorrer el vector resultado
        resultado[i] = 0; // resultado[i] = 0
    }

    // Pedir los valores de los vectores
    for(int i = 0; i < N; i++){ // bucle para recorrer el vector sumando1
        printf("Ingrese digito %d del primer sumando: ", i+1); // pedir digito del primer sumando
        // validar que el valor ingresado sea un numero y de un digito valido
        while(1){ // bucle infinito para validar que el valor ingresado sea un numero y de un digito valido
            scanf("%d", &sumando1[i]); // i = indice, guardamos en sumando1
            if(sumando1[i] >= 0 && sumando1[i] <= 9){ // si el valor ingresado es un numero y de un digito valido
                break; // numero valido
            } else { // si el valor ingresado no es un numero o no es de un digito valido
                printf("Ingrese un digito valido: "); // pedir digito valido
            }
        }
    }
    for(int i = 0; i < N; i++){ // bucle para recorrer el vector sumando2
        printf("Ingrese digito %d del segundo sumando: ", i+1); // pedir digito del segundo sumando
        // validar que el valor ingresado sea un numero y de un digito valido
        while(1){ // bucle infinito para validar que el valor ingresado sea un numero y de un digito valido
            scanf("%d", &sumando2[i]); // i = indice, guardamos en sumando2
            if(sumando2[i] >= 0 && sumando2[i] <= 9){ // si el valor ingresado es un numero y de un digito valido
                break; // numero valido
            } else { // si el valor ingresado no es un numero o no es de un digito valido
                printf("Ingrese un digito valido: "); // pedir digito valido
            }
        }
    }

    // Sumar los sumandos
    int sum1 = 0; // sum1 = sumando1
    int sum2 = 0; // sum2 = sumando2
    int res = 0; // res = resultado

    // Sacar el numero del vector y guardarlo en una variable sum
    for(int i = 0; i < N; i++){ // bucle para recorrer el vector sumando1
        // se saca cada digito del vector y se guarda en sum y se multiplica por 10 para que se sume con el siguiente digito
        sum1 = sum1 * 10 + sumando1[i]; // operacion para sacar el numero del vector y guardarlo en sum1 hasta que el numero del vector este guardado en sum1
        sum2 = sum2 * 10 + sumando2[i]; // operacion para sacar el numero del vector y guardarlo en sum2 hasta que el numero del vector este guardado en sum2
    }
    
    // Sumar los dos numeros
    res = sum1 + sum2; // Sumar los dos numeros

    // Guardar el resultado en el vector resultado digito a digito de atras para adelante
    for(int i = N; i >= 0; i--){ // bucle para recorrer el vector resultado
        resultado[i] = res % 10; // resultado[i] = res % 10
        res = res / 10; // res = res / 10
    }

    // Se deben mostrar los vectores de la misma manera que se suman dos cantidades, por ejemplo:
    /*

        7 5 4 2
    +   1 9 8 4
    ___________
        9 5 2 6
    */

    // Impresion de la suma
    printf("\n"); // salto de linea
    printf("Suma: "); // imprimir Suma:
    printf("\n"); // salto de linea

    // tabulacion
    printf("\t  "); // tabulacion
    for(int i = 0; i < N; i++){ // bucle para recorrer el vector sumando1
        printf("%d ", sumando1[i]); // imprimir sumando1
    }
    printf("\n"); // salto de linea
    // tabulacion
    printf("\t+ "); // tabulacion y + de suma
    for(int i = 0; i < N; i++){ // bucle para recorrer el vector sumando2
        printf("%d ", sumando2[i]); // imprimir sumando2
    }
    // linea de resultado
    printf("\n"); // salto de linea
    printf("\t"); // linea de resultado
    for(int i = 0; i < N+1; i++){ // bucle para recorrer el vector resultado
        printf("--"); // imprimir linea de resultado
    }
    printf("\n"); // salto de linea
    // tabulacion
    printf("\t"); // tabulacion
    for(int i = 0; i < N+1; i++){ // bucle para recorrer el vector resultado
        printf("%d ", resultado[i]); // imprimir resultado
    }
    printf("\n"); // salto de linea
    printf("\n"); // salto de linea

    // Fin
    return 0;
}

