// Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
// Es posible que el codigo generado no sea completamente correcto. Si encuentra
// errores por favor reportelos en el foro (http://pseint.sourceforge.net).

#include<iostream>
#include<cmath>
using namespace std;

// Para leer variables de texto se utiliza el operador << del objeto cin, que
// lee solo una palabra. Para leer una linea completa (es decir, incluyendo los
// espacios en blanco) se debe utilzar getline (ej, reemplazar cin>>x por
// getline(cin,x)), pero obliga a agregar un cin.ignore() si antes del getline
// se leyó otra variable con >>.

int main() {
	float a;
	float b;
	float c;
	float x;
	float x1;
	float x2;
	cout << "Ingrese los coeficientes A, B y C:" << endl;
	cin >> a >> b >> c;
	if (pow(b,2)<4*a*c) {
		cout << "La ecuacion no tiene raices reales" << endl;
	} else {
		x = -sqrtf(pow(b,2)-4*a*c);
		x1 = (-b+x)/(2*a);
		x2 = (-b-x)/(2*a);
		cout << "X1: " << x1 << endl;
		cout << "X2: " << x2 << endl;
	}
	return 0;
}

