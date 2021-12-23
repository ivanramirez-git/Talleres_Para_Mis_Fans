#include <iostream>

using namespace std;

class polinomio2{
private:
    double a;
    double b;
    double c;
public:
    // Consrtuctor
    polinomio2(double a, double b, double c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    // Consrtuctor vacio
    polinomio2(){
        this->a = 0;
        this->b = 0;
        this->c = 0;
    }
    // Destructor
    ~polinomio2(){
    }
    // f(x) = ax^2 + bx + c
    double f(double x){
        return a*x*x + b*x + c;
    }
    // Sobrecargar operadores <<
    friend ostream& operator<<(ostream& os, const polinomio2& p){
        os << p.a << "x^2 + " << p.b << "x + " << p.c;
        return os;
    }
    // Sobrecargar operadores >>
    friend istream& operator>>(istream& is, polinomio2& p){
        // Ingreso de a, validar que sea numero
        cout << "Ingrese a: ";
        is >> p.a;
        cout << "Ingrese b: ";
        is >> p.b;
        cout << "Ingrese c: ";
        is >> p.c;
        return is;
    }
};

int main(){

    polinomio2 p1(1,2,3);
    cout << p1 << endl;
    polinomio2 p2;
    cin>>p2;
    cout << p2 << endl;

    return 0;
}
