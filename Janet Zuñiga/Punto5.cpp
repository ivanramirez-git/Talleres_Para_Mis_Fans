#include <iostream>

using namespace std;

int main(){
    // Indica si uno de los dos numeros divide al otro exactamente
    // Ingresa el valor de A y B
    int A, B;
    cout << "Ingresa el valor de A: ";
    cin >> A;
    cout << "Ingresa el valor de B: ";
    cin >> B;
    // Si A es divisible por B
    if (A % B == 0) {
        cout << B << " divide exactamente a " << A << endl;
    } else if (B % A == 0) {
        cout << A << " divide exactamente a " << B << endl;
    } else {
        cout << "No se dividen exactamente"<< endl;
    }

    return 0;
}