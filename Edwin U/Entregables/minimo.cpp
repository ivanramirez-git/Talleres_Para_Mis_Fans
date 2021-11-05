// Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
// Es posible que el codigo generado no sea completamente correcto. Si encuentra
// errores por favor reportelos en el foro (http://pseint.sourceforge.net).

#include<iostream>
using namespace std;

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
	SIN_TIPO a[50];
	int i;
	SIN_TIPO min;
	float n;
	cout << "Ingrese cantidad de datos: " << endl;
	cin >> n;
	for (i=1;i<=n;i++) {
		cout << "Ingrese el dato " << i << ":" << endl;
		cin >> a[i-1];
	}
	min = a[0];
	for (i=2;i<=n;i++) {
		if (a[i-1]<min) {
			min = a[i-1];
		}
	}
	cout << "El minimo de los " << n << " numeros es: " << min << endl;
	return 0;
}

