#include <stdio.h>
#define BITS 8

void intToBin(int num, int len, char *bin) {
    for (int i = 0; i < len; i++) {
        bin[i] = '0';
    }    
    if (num == 0) {
        return;
    }
    intToBin(num / 2, len - 1, bin);
    bin[len - 1] = num % 2 + '0';
}

void printBin(char *bin) {
    int i;
    for (i = 0; i < BITS; i++) {
        printf("%c", bin[i]);
    }
}

int main() {
    int num;
    char bin[BITS];
    printf("Ingrese un entero: ");
    scanf("%d", &num);
    intToBin(num, BITS, bin);
    printf("\nEl binario es: ");
    printBin(bin);
    printf("\n");
    return 0;
}