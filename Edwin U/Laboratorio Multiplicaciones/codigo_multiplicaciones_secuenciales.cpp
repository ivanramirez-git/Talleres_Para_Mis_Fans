// Este codigo ha sido generado por el modulo psexport 20180802-l64 de PSeInt.
// Es posible que el codigo generado no sea completamente correcto. Si encuentra
// errores por favor reportelos en el foro (http://pseint.sourceforge.net).

#include<iostream>
#include<cmath>
using namespace std;

// En C++ no se puede dimensionar un arreglo estático con una dimensión no constante.
// PSeInt sobredimensionará el arreglo utilizando un valor simbólico ARREGLO_MAX.
// Sería posible crear un arreglo dinámicamente con los operadores new y delete, pero
// este mecanismo aún no está soportado en las traducciones automáticas de PSeInt.
#define ARREGLO_MAX 100

// Para leer variables de texto se utiliza el operador << del objeto cin, que
// lee solo una palabra. Para leer una linea completa (es decir, incluyendo los
// espacios en blanco) se debe utilzar getline (ej, reemplazar cin>>x por
// getline(cin,x)), pero obliga a agregar un cin.ignore() si antes del getline
// se leyó otra variable con >>.

int main() {
	float b;
	int cifra[ARREGLO_MAX];
	int i;
	int k;
	int num_entero;
	float num_real;
	float prod;
	float z;
	// Ingrese el numero real positivo menor que 1 validando que sea menor que 1
	cout << "Ingrese el numero real positivo menor que 1: " << endl;
	cin >> z;
	// Validar que sea menor que 1
	while (z>=1) {
		cout << "El numero ingresado no es menor que 1" << endl;
		// Ingrese el numero real positivo menor que 1 validando que sea menor que 1
		cout << "Ingrese el numero real positivo menor que 1: " << endl;
		cin >> z;
	}
	// Ingrese la base
	cout << "Ingrese la base esperada: " << endl;
	cin >> b;
	// Ingrese el numero de cifras
	cout << "Ingrese el numero de cifras: " << endl;
	cin >> k;
	k = k+1;
	i = 1;
	// Iniciar ciclo
	while (i!=k) {
		prod = z*b;
		num_entero = int(prod);
		z = prod-num_entero;
		cifra[i-1] = num_entero;
		if (z==0) {
			i = 1;
			cout << "El numero en base " << b << " es: " << endl;
			cout << "0.";
			while (i!=k) {
				cout << cifra[i-1];
				i = i+1;
			}
		} else {
			i = i+1;
		}
	}
	if (z!=0) {
		i = 1;
		cout << "El numero en base " << b << " es: " << endl;
		cout << "0.";
		while (i!=k) {
			cout << cifra[i-1];
			i = i+1;
		}
	}
	cout << "" << endl;
	// Fin del ciclo
	return 0;
}

