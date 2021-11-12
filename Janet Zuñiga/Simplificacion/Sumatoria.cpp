#include <iostream>

// funcion que realiza una sumatoria 1 + 2 + 3 + ... + n
int sumatoria(int n) {
	int suma = 0;
	for (int i = 1; i <= n; i++) {
		suma += i;
	}
	return suma;
}



int main(){

	int n;
	std::cout << "Ingrese un numero: ";
	std::cin >> n;
	std::cout << "La sumatoria de los numeros del 1 al " << n << " es: " << sumatoria(n) << std::endl;
	
	
	return 0;
}
