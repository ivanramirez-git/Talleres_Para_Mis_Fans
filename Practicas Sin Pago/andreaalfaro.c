#include <stdio.h>

int main(){
    // Dado 4 enteros: n,a,b,c
    // Donde 10 <= n <= 100000
    // Donde 2 <= a,b,c <= 9
    printf("Ingrese n: ");
    int n;
    // Validar n
    while(scanf("%d", &n) != 1 || n < 10 || n > 100000){
        printf("Error: n debe ser un numero entre 10 y 100000\n");
        printf("Ingrese n: ");
        while(getchar() != '\n');
    }
    printf("Ingrese a: ");
    int a;
    // Validar a
    while(scanf("%d", &a) != 1 || a < 2 || a > 9){
        printf("Error: a debe ser un numero entre 2 y 9\n");
        printf("Ingrese a: ");
        while(getchar() != '\n');
    }
    printf("Ingrese b: ");
    int b;
    // Validar b
    while(scanf("%d", &b) != 1 || b < 2 || b > 9){
        printf("Error: b debe ser un numero entre 2 y 9\n");
        printf("Ingrese b: ");
        while(getchar() != '\n');
    }
    printf("Ingrese c: ");
    int c;
    // Validar c
    while(scanf("%d", &c) != 1 || c < 2 || c > 9){
        printf("Error: c debe ser un numero entre 2 y 9\n");
        printf("Ingrese c: ");
        while(getchar() != '\n');
    }
    // Sumar los multiplos de a entre 1 y n
    int a_multiplos = 0;
    for(int i = 1; i <= n; i++){
        if(i % a == 0){
            a_multiplos += i;
        }
    }
    // Sumar los multiplos de b entre 1 y n
    int b_multiplos = 0;
    for(int i = 1; i <= n; i++){
        if(i % b == 0){
            b_multiplos += i;
        }
    }
    // Sumar los multiplos de c entre 1 y n
    int c_multiplos = 0;
    for(int i = 1; i <= n; i++){
        if(i % c == 0){
            c_multiplos += i;
        }
    }
    // Imprimir la suma de los multiplos de a, b y c entre 1 y n
    printf("La suma de los multiplos de a, b y c entre 1 y n es: %d\n", a_multiplos + b_multiplos + c_multiplos);
    
    return 0;
}