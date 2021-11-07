#include <iostream>

using namespace std;

int main()
{
    // Calcular aumento de plaga
    int cant_inicial = 10000;
    int cant_final = cant_inicial + ((cant_inicial * 120)/100);
    cout << "Al final de la temporada habran: " << cant_final << " Ratones" <<endl;
    return 0;
}