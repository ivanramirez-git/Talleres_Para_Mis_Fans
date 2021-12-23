#include <stdio.h>

int main(){
    // Matrices

    // Pedir dimeniones n y m, numeros positivos y distintos de 0, n > m
    int n, m; // n = filas, m = columnas
    // Pedir n > 1
    while(1){ // bucle infinito para validar que n sea mayor a 1
        printf("Ingrese dimension n: "); // pedir n
        scanf("%d", &n); // leer n
        if(n > 1){ // si n es mayor a 1
            break; // rompe el bucle
        }
    }
    // Pedir m < n y m > 0
    while(1){ // bucle infinito para validar que m sea menor a n y mayor a 0
        printf("Ingrese dimension m: "); // pedir m
        scanf("%d", &m); // leer m
        if(m < n && m > 0){ // si m es menor a n y mayor a 0
            break; // rompe el bucle si el valor es valido
        }
    }
    // Matriz
    int matriz[n][m]; // matriz de n filas y m columnas
    // Pedir valores de la matriz
    // Las filas pares deben ser numeros impares
    // Las filas impares deben ser numeros pares
    for(int i = 0; i < n; i++){ // bucle para recorrer las filas
        for(int j = 0; j < m; j++){ // bucle para recorrer las columnas
            printf("Ingrese digito %d de la fila %d: ", j+1, i); // pedir digito de la fila i y columna j
            // validar que el valor ingresado sea un numero y de un digito valido, ciclo para validar que el valor ingresado sea un numero y de un digito valido
            while(1){ // bucle infinito para validar que el valor ingresado sea un numero y de un digito valido y cumpla con las condiciones
                scanf("%d", &matriz[i][j]); // i = fila, j = columna, guardamos en la matriz
                // validar que el valor ingresado sea un numero y de un digito valido
                if(matriz[i][j] >= 0 && matriz[i][j] <= 9){ // si el valor ingresado es un numero y de un digito valido
                    // validar que sea un numero impar si es una fila par o viceversa
                    if(i % 2 == 0){ // si la fila es par
                        if(matriz[i][j] % 2 == 0){ // Fila par, numero par
                            printf("Ingrese un digito valido: "); // pedir digito valido
                        } else { // Fila par, numero impar
                            break; // numero valido
                        }
                    } else { // si la fila es impar
                        if(matriz[i][j] % 2 == 1){ // Fila impar, numero impar
                            printf("Ingrese un digito valido: "); // pedir digito valido
                        } else { // Fila impar, numero par
                            break; // numero valido
                        }
                    }
                } else { // si el valor ingresado no es un numero o no es de un digito valido
                    printf("Ingrese un digito valido: "); // pedir digito valido
                }
            }
        }
    }
    // Imprimir la matriz
    printf("\n"); // salto de linea
    printf("Matriz:\n"); // imprimir matriz
    for(int i = 0; i < n; i++){ // bucle para recorrer las filas
        for(int j = 0; j < m; j++){ // bucle para recorrer las columnas
            printf("%d ", matriz[i][j]); // imprimir el valor de la matriz
        }
        printf("\n"); // salto de linea
    }
    // Sumamos cada elemento de las columnas de la matriz y guardamos cada resultado en un vector
    int suma_columna[m]; // vector de m elementos
    for(int i = 0; i < m; i++){ // bucle para recorrer las columnas
        int suma = 0; // inicializamos la suma en 0
        for(int j = 0; j < n; j++){ // bucle para recorrer las filas
            suma = suma + matriz[j][i]; // sumamos el valor de la matriz en la posicion j, i
        } // fin bucle para recorrer las filas
        suma_columna[i] = suma; // guardamos la suma en el vector
    }
    // Imprimir el vector
    printf("\n"); // salto de linea
    printf("Suma de cada columna:\n"); // imprimir suma de cada columna
    for(int i = 0; i < m; i++){ // bucle para recorrer las columnas
        printf("%d ", suma_columna[i]); // imprimir el valor del vector
    } 
    // Promedio del vector
    float promedio = 0.0; // inicializamos el promedio en 0
    for(int i = 0; i < m; i++){ // bucle para recorrer las columnas
        promedio = promedio + suma_columna[i]; // sumamos el valor del vector
    }
    promedio = promedio / m; // dividimos el valor de la suma de cada columna entre el numero de columnas
    // Imprimir el promedio
    printf("\n"); // salto de linea
    printf("El promedio de la suma de cada columna es: %.2f\n", promedio); // imprimir 2 decimales, el promedio de la suma de cada columna
    // Suma de todos los elementos de la matriz
    int suma_matriz = 0; // inicializamos la suma de la matriz en 0
    for(int i = 0; i < n; i++){ // bucle para recorrer las filas
        for(int j = 0; j < m; j++){ // bucle para recorrer las columnas
            suma_matriz = suma_matriz + matriz[i][j]; // sumamos el valor de la matriz en la posicion i, j
        }
    }
    // Imprimir la suma de todos los elementos de la matriz
    printf("\n"); // salto de linea
    printf("La suma de todos los elementos de la matriz es: %d\n", suma_matriz); // imprimir la suma de todos los elementos de la matriz
    // Promedio de la suma de todos los elementos de la matriz
    float promedio_matriz = 0.0; // inicializamos el promedio de la suma de la matriz en 0
    promedio_matriz = suma_matriz / (n * m); // dividimos la suma de todos los elementos de la matriz entre el numero de filas y columnas
    // Imprimir el promedio de la suma de todos los elementos de la matriz
    printf("\n"); // salto de linea
    printf("El promedio de la suma de todos los elementos de la matriz es: %.2f\n", promedio_matriz); // imprimir 2 decimales, el promedio de la suma de todos los elementos de la matriz
    
    // Fin

    return 0;
}