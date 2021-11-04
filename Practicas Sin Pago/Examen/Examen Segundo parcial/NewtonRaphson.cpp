#include <iostream>
#include <iomanip> // setprecision
#include <cmath>

#define PRECISION 10
#define MAX_ITERACIONES 100
#define INTERVALOS 6

using namespace std;

void tabula(double a, double b, int intervalos);	// Muestra un # tabulado de intervalos
double f_derivada(double x); // Retorna la derivada de la funci�n evaluada en x

double fnewton(double x)
{
	return x * exp(cos(x)) / 1.5 - 1;
	//return exp(-x) + 3 * x - 3;
}


int newtonRaphson()
{
	double a;
	double b;
	double tolerancia;	// Tolerancia
	double x0; // Primera aproximaci�n
	double x1; // Siguiente aproximaci�n
	double error;	// Diferencia entre dos aproximaciones sucesivas: x1 - x0
	int iteracion; // # de iteraciones
	bool converge = true;
	
	cout << setprecision(PRECISION);	// Se establece la precisi�n
	cout << "\nCalculo de las raices de una funcion aplicando el metodo de Newton - Raphson\n";
	cout << "\nIngrese el intervalo inicial [a,b]:" << endl;
	
	// Se ingresa el intervalo
	cout << "\na = ";
	cin >> a;
	
	cout << "b = ";
	cin >> b;
	
	// Se tabulan los valores de f para INTERVALOS intervalos
	tabula(a, b, INTERVALOS);
	
	// Se pide elegir una aproximaci�n inicial
	cout << "\nEscoja el punto inicial adecuado:   x0 = ";
	cin >> x0;
	
	// Se pide ingresar la tolerancia
	cout << "Tolerancia = ";
	cin >> tolerancia;
	
	// Iteraciones
	
	// Se imprimen los valores de la primera aproximaci�n
	cout << "\nAproximacion inicial:\n";
	cout << "x0 = " << x0 << "\n"
		<< "f(x0) = " << f(x0) << "\n"
		<< "f'(x0) = " << f_derivada(x0) << endl;
	
	iteracion = 1;
	do {
	
		if (iteracion > MAX_ITERACIONES) {
			converge = false;	// Se sobrepas� la m�xima cantidad de iteraciones permitidas
			break;
		
		} else {
			x1 = x0 - fnewton(x0) / f_derivada(x0); // C�lculo de la siguiente aproximaci�n
			error = fabs(x1 - x0);	// El error es la diferencia entre dos aproximaciones sucesivas
			
			// Se imprimen los valores de la siguiente aproximaci�n x1, f(x1), f_derivada(x1), error
			cout << "\nIteracion #" << iteracion << endl;
			cout << "x" << iteracion << " = " << x1 << "\n"
			  << "f(x" << iteracion << ") = " << f(x1) << "\n"
			  << "f'(x" << iteracion << ") = " << f_derivada(x1) << "\n"
			  << "error = " << error << endl;
			
			// La diferencia entre dos aproximaciones sucesivas es tambi�n conocida como error.
			// La condici�n de terminaci�n consiste en que que el error debe ser <= que la tolerancia dada
			// Si se cumple la condici�n de terminaci�n, se ha encontrado la raiz aproximada buscada.
			if (error <= tolerancia) { // Condici�n de terminaci�n
				converge = true;
				break;
				
				// Si no se cumple el criterio de terminaci�n, se pasa a la siguiente iteraci�n
			} else {
				x0 = x1;
				iteracion++;
			}
		}
	
	} while (1);
	
	// Respuesta final
	if (converge) {
		cout << "\n\nPara una tolerancia de " << tolerancia << " la raiz de f es: " << x1 << endl;
	
	} else {
		cout << "\n\nSe sobrepas� la m�xima cantidad de iteraciones permitidas" << endl;
	}
	
	cin.get();
	cin.get();
	return 0;
}

void tabula(double a, double b, int intervalos)
{
	int puntos = intervalos + 1;
	
	double ancho = (b - a) / intervalos;
	
	cout << "\n\tx\t\tf(x) " << endl;
	for (int i = 0; i < puntos; i++) {
		cout << "\t" << a << "\t\t" << fnewton(a) << endl;
		a = a + ancho;
	}
}

double f_derivada(double x)
{
	return exp(cos(x)) * (1 - x * sin(x)) / 1.5;
	//return -1 * exp(-x) + 3;
}
void pausa()
{
    cout << "Pulsa una tecla para continuar...";
    getwchar();
    getwchar();
}
