#include <iostream>

using namespace std;

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
	cout << "Ingrese un numero: ";
	cin >> n;
	cout << "La sumatoria de los numeros del 1 al " << n << " es: " << sumatoria(n) << endl;
	
	
	return 0;
}
