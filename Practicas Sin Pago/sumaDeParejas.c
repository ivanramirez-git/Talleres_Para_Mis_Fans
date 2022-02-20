// Autor: Ivan Ramirez
#include <stdio.h>
int main() {
    // N
    int n;
    printf("N = ");
    scanf("%d", &n);
    // Pedimos los valores
    int valores[n];
    int parejas[n/2];
    for (int i = 0; i < n; i++) {
        printf("valores[%d] = ", i);
        scanf("%d", &valores[i]);
    }
    // Suma de parejas, i0 + in, i1 + in-1, i2 + in-2, ..., in/2-1 + in/2+1, si es impar ignoramos el ultimo
    for (int i = 0; i < n/2; i++) {
        parejas[i] = valores[i] + valores[n-1-i];
    }
    // Mostramos la suma de parejas
    printf("Suma de parejas: ");
    for (int i = 0; i < n/2; i++) {
        printf("%d ", parejas[i]);
    }
    printf("\n");
    return 0;
}
// GitHub: https://github.com/ivanramirez-git/Talleres_Para_Mis_Fans
