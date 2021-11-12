//copyright Augusto Caballero
#include <iostream>

using namespace std;

int main() {
	long suma_cuadrados = 0;
	for(int i = 1; i <= 10; i++) {
		suma_cuadrados += i * i;
	}
	cout << "SUMA CUADRADOS 1 AL 10: " << suma_cuadrados << endl;
	return 0;
}
