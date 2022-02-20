#include <stdio.h>

int main() {
    char nombres[5][30];
    char texto[15];

    printf("Ingrese nombre y apellido de 5 personas: \n");
    for (int i = 0; i < 5; i++) {
        printf("Nombre y apellido %d: ", i + 1);
        scanf("%s", nombres[i]);
        scanf("%s", texto);
    }
}