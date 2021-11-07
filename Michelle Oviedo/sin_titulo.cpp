// Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
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
	string empresa;
	int i;
	int j;
	float k;
	int l;
	string nombreempresa;
	string personasdeducciones[;
	string personasedades[;
	string personasnombres[;
	string personassalarios[;
	string personassexo[;
	string seccionesnombres[;
	int seccionesnumeropersonas[;
	SIN_TIPO sedesnombres[ARREGLO_MAX];
	int sedesnumero;
	int sedesnumerosecciones[ARREGLO_MAX];
	empresa = "";
	// Definir variables
	cout << "Bienvenido al programa de empresas" << endl;
	cout << "Ingrese el nombre de la empresa: " << endl;
	cin >> nombreempresa;
	cout << "Ingrese el numero de sedes: " << endl;
	cin >> sedesnumero;
	// Definir dimensiones de sedes
	// Guardar datos empresa
	empresa = "{°nombre°:°"+nombreempresa+"°,°sedes°:[";
	i = 1;
	while (i<=sedesnumero) {
		cout << "Ingrese el nombre de la sede " << i << endl;
		cin >> sedesnombres[i-1];
		cout << "Cuantas secciones tiene la sede " << i << ". " << sedesnombres[i-1] << endl;
		cin >> sedesnumerosecciones[i-1];
		// Definir dimensiones de secciones
		j = 1;
		while (j<=sedesnumerosecciones[i-1]) {
			cout << "Ingrese el nombre de la seccion " << j << " de la sede " << i << endl;
			cin >> seccionesnombres[j-1];
			cout << "Cuantas personas tiene la seccion " << j << " de la sede " << i << endl;
			cin >> seccionesnumeropersonas[j-1];
			// Definir dimensiones de personas
			k = 1;
			while (k<=seccionesnumeropersonas[j-1]) {
				cout << "Ingrese el nombre de la persona " << k << " de la seccion " << j << " de la sede " << i << endl;
				cin >> personasnombres[k-1];
				cout << "Ingrese el sexo de la persona " << k << " de la seccion " << j << " de la sede " << i << endl;
				cin >> personassexo[k-1];
				cout << "Ingrese la edad de la persona " << k << " de la seccion " << j << " de la sede " << i << endl;
				cin >> personasedades[k-1];
				cout << "Ingrese el salario de la persona " << k << " de la seccion " << j << " de la sede " << i << endl;
				cin >> personassalarios[k-1];
				cout << "Ingrese las deducciones de la persona " << k << " de la seccion " << j << " de la sede " << i << endl;
				cin >> personasdeducciones[k-1];
				k = k+1;
			}
			// Guardar datos seccion
			empresa = empresa+"{°nombre°:°"+seccionesnombres[j-1]+"°,°personas°:[";
			l = 1;
			while (l<=seccionesnumeropersonas[j-1]) {
				empresa = empresa+"{°nombre°:"+personasnombres[l-1]+",°sexo°:"+personassexo[l-1]+",°edad°:"+personasedades[l-1]+",°salario°:"+personassalarios[l-1]+",°deducciones°:"+personasdeducciones[l-1]+"}";
				l = l+1;
			}
			empresa = empresa+"]}";
			j = j+1;
		}
		empresa = empresa+"]}";
		i = i+1;
	}
	empresa = empresa+"}";
	cout << empresa << endl;
	// Imprimir nombre de Empresa
	return 0;
}

