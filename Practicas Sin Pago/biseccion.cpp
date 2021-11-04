#include <iostream>
#include <iomanip> // setprecision
#include <cmath>

#define PRECISION 6

using namespace std;

double f(double x);
void imprimePuntos(double a, double b);

int main()
{
   cout << setprecision(PRECISION); // Establecemos la precisión
   
   double a, b, tolerancia;
   
   cout << "\nCalculo de las raices de una funcion aplicando el metodo de la biseccion" << endl;
   cout << "\nIngrese el intervalo inicial [a, b]" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;
   
   imprimePuntos(a, b);
   
   cout << "\nEscoja el intervalo adecuado" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;
   
   // [a, b]
   float xr; // raiz de la función
   
   /*
   cout << "\nf(" << a << ") = " << f(a) << endl;
   cout << "f(" << b << ") = " << f(b) << endl;
   */
   
   if (f(a) * f(b) > 0) {
      
      cout << "\nNo se puede aplicar el metodo de la biseccion\n";
      cout << "porque f(" << a << ") y f(" << b << ") tienes el mismo signo" << endl;
      
   } else {
      cout << "Tolerancia = ";
      cin >> tolerancia;
      cout << "\na\tb\tx\tf(a)\t\tf(b)\t\tf(x)\n" << endl;
      do {
         xr = (a + b) / 2.0;
         cout << a << "\t" << b << "\t" << xr << "\t";
         cout << f(a) << "\t" << f(b) << "\t" << f(xr) << endl;

         // Vemos si cumple o no cumple
         if (abs(f(xr)) <= tolerancia) { // xr sería la raiz de f
         
            cout << "\n\nPara una tolerancia " << tolerancia << " la raiz de f es " << xr << endl;
         
            break;
            
         } else {
            if (f(xr) * f(a) > 0) {
               a = xr;
            } else if (f(xr) * f(b) > 0) {
               b = xr;
            }
         }
         
      } while (1);
   }
   
   cin.get();
   cin.get();
   return 0;
}


double f(double x) 
{
   return exp(-1 * x) - cos(3 * x) - 0.5;
}

#define INTERVALOS 10
void imprimePuntos(double a, double b)
{
   int puntos = INTERVALOS + 1;
   
   double ancho = (b - a) / INTERVALOS;
   
   cout << "\n";
   cout << "\tx\tf(x)\n" << endl;
   for (int i = 0; i < puntos; i++) {
      cout << "\t" << a << "\t" << f(a) << endl;
      a = a + ancho;
   }
}
