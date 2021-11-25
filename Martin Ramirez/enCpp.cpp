// Este codigo ha sido generado por el modulo psexport 20180802-l64 de PSeInt.
// Es posible que el codigo generado no sea completamente correcto. Si encuentra
// errores por favor reportelos en el foro (http://pseint.sourceforge.net).

#include<iostream>
using namespace std;

// En C++ no se puede dimensionar un arreglo estático con una dimensión no constante.
// PSeInt sobredimensionará el arreglo utilizando un valor simbólico ARREGLO_MAX.
// Sería posible crear un arreglo dinámicamente con los operadores new y delete, pero
// este mecanismo aún no está soportado en las traducciones automáticas de PSeInt.
#define ARREGLO_MAX 100

// Para las variables que no se pudo determinar el tipo se utiliza la constante
// SIN_TIPO. El usuario debe reemplazar sus ocurrencias por el tipo adecuado
// (usualmente int,float,string o bool).
#define SIN_TIPO string

// Para leer variables de texto se utiliza el operador << del objeto cin, que
// lee solo una palabra. Para leer una linea completa (es decir, incluyendo los
// espacios en blanco) se debe utilzar getline (ej, reemplazar cin>>x por
// getline(cin,x)), pero obliga a agregar un cin.ignore() si antes del getline
// se leyó otra variable con >>.

int main() {
	SIN_TIPO arreglo[ARREGLO_MAX];
	SIN_TIPO dato;
	int i;
	int n;
	// Ingrese el numero de datos
	cout << "Ingrese el numero de datos: " << endl;
	cin >> n;
	n = n+1;
	// Iniciar ciclo
	i = 1;
	while (i!=n) {
		// Ingrese el dato
		cout << "Ingrese el dato: " << endl;
		cin >> dato;
		// Agregar el dato al arreglo
		arreglo[i-1] = dato;
		i = i+1;
	}
	// Imprimir arreglo
	cout << "El arreglo es: " << endl;
	i = 1;
	cout << "[";
	while (i!=n) {
		cout << arreglo[i-1] << " ";
		i = i+1;
	}
	cout << "]" << endl;
	return 0;
}

