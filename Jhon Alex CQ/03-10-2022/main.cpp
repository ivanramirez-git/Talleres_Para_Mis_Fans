#include <iostream>

using namespace std;

// contar vocales
int contarVocales(char *cadena) {
    int contador = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' || cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U') {
            contador++;
        }
    }
    return contador;
}

// contar consonantes
int contarConsonantes(char *cadena) {
    int contador = 0;
    char consonantes[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    for (int i = 0; cadena[i] != '\0'; i++) {
        for (int j = 0; consonantes[j] != '\0'; j++) {
            if (cadena[i] == consonantes[j]) {
                contador++;
            }
        }
    }
    return contador;
}

// contar letras
int contarLetras(char *cadena) {
    return contarVocales(cadena) + contarConsonantes(cadena);
}

// main
int main() {
    char cadena[100];
    cout << "Ingrese una cadena: ";
    cin.getline(cadena, 100);
    cout << "La cadena tiene " << contarVocales(cadena) << " vocales" << endl;
    cout << "La cadena tiene " << contarConsonantes(cadena) << " consonantes" << endl;
    cout << "La cadena tiene " << contarLetras(cadena) << " letras" << endl;
    return 0;
}