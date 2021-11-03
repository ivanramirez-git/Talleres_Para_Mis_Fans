#include <iostream>       // std::cout
#include <stdlib.h>       /* srand, rand */
#include <time.h>         // time

using namespace std;



// funcion que espera una cantidas de ms
int esperar(int ms) {
    clock_t t;
    t = clock() + ms;
    while (clock() < t) {
    	
    }
    return time(NULL);
}

// Funcion que retorna numero aleatorio_entre_min y aleatorio_entre_max
int aleatorio_entre(int min, int max) {
    srand(esperar(time(NULL)%10));
    return rand() % (max - min + 1) + min;
}

// Funcion que recibe pablabra en *char[50] y la convierte con la primera letra mayuscula
void mayuscula(char *palabra) {
    // Convierte la primera letra de la palabra en mayuscula
    palabra[0] = toupper(palabra[0]);
    // Imprimir
    cout << palabra << " ";

}

int main() {
    // 4 Vectores, articulos, verbos, preposiciones y sustantivos, punteros char[50]
    
    
    char *articulos[50] = {"el", "un", "algun", "ningun"};
    char *verbos[50] = {"manejo", "salto", "corrio", "camino", "paso"};
    char *preposiciones[50] = {"a", "desde", "encima de", "debajo de", "sobre"};
    char *sustantivos[50] = {"ninio", "senior", "perro", "ciudad", "auto"};

    // Numero de palabras de los vectores
    int num_articulos = 4;
    int num_verbos = 5;
    int num_preposiciones = 5;
    int num_sustantivos = 5;
    
    cout << articulos[aleatorio_entre(0, num_articulos - 1)] << " " <<
    sustantivos[aleatorio_entre(0, num_sustantivos - 1)] << " " <<
    verbos[aleatorio_entre(0, num_verbos - 1)] << " " <<
    preposiciones[aleatorio_entre(0, num_preposiciones - 1)] << " " <<
    articulos[aleatorio_entre(0, num_articulos - 1)] << " " <<
    sustantivos[aleatorio_entre(0, num_sustantivos - 1)] <<
    "." << endl;

    return 0;
}
