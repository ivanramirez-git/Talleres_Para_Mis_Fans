// Your C++ Program

#include <iostream>

using namespace std;

int main() {
    float p=100;
    cout << "Dinero ganado: "<<p;
    p=p*0.84;
    cout << "\nDinero despues de la DIAN: "<<p;
    p=p*0.91;
    cout << "\nDinero despues de Hacienda: "<<p;
    cout << "\nTotal dinero recibido: "<<p;
    cout <<endl;
    return 0;
}
