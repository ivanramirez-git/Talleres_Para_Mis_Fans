/*****************************************************
 * 
 * main.c
 *     
 * Programmer: Yasna Hormazábal, Felipe Silva
 *
 * Santiago de Chile, 27/04/2022
 *
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Complejos.h"

void Menu();

int main(){
    int Option;
    float v1, v2;

    struct Complex c;
    struct ComplexList *L1, *L2, *L3;

    c = InitComplex(0, 0);
    L1 = InitList(L1);
    L2 = InitList(L2);
    L3 = InitList(L3);

    do{
        printf("Complejo en memoria = ");
        ShowComplex(c);
        printf("\n");

        printf("f(x) = ");
        ShowComplexList(L1);

        printf("g(x) = ");
        ShowComplexList(L2);

        printf("h(x) = ");
        ShowComplexList(L3);

        Menu();
        printf("Ingrese la opcion: ");
        scanf("%i", &Option);

        switch (Option){
            case 1:
                printf("Ingrese el valor real: ");
                scanf("%f", &v1);
                printf("Ingrese el valor imaginario: ");
                scanf("%f", &v2);
                c = InitComplex(v1, v2);
                break;
            case 2:
                printf("Ingrese la potencia: ");
                scanf("%f", &v1);
                L1 = AddList(L1, c, v1);
                break;
            case 3:
                printf("Ingrese la potencia: ");
                scanf("%f", &v1);
                L2 = AddList(L2, c, v1);
                break;
            case 4:
                L3 = SumList(L1, L2);
                printf("f(x)+g(x) = ");
                ShowComplexList(L3);
                break;
            case 5:
                L3 = SubList(L1, L2);
                printf("f(x)-g(x) = ");
                ShowComplexList(L3);
                break;
            case 6:
                L3 = MultList(L1, L2);
                printf("f(x)*g(x) = ");
                ShowComplexList(L3);
                break;
            case 7:
                L3 = DivList(L1, L2);
                printf("f(x)/g(x) = ");
                ShowComplexList(L3);
                break;
            case 8:
                L1 = CopyList(L3);
                break;
            case 9:
                L2 = CopyList(L3);
                break;
        }
    }while(Option > 0);


    return 0;
}

void Menu(){
    printf("0. Salir\n");
    printf("1. Guardar complejo en memoria\n");
    printf("2. Sumar complejo en memoria al primer polinomio f(x)\n");
    printf("3. Sumar complejo en memoria al segundo polinomio g(x)\n");
    printf("4. Sumar polinomios\n");
    printf("5. Restar polinomios\n");
    printf("6. Multiplicar polinomios\n");
    printf("7. Dividir polinomios\n");
    printf("8. f(x) = h(x)\n");
    printf("9. g(x) = h(x)\n");
}
