// Your C++ Program
#include <iostream>
using namespace std;
int main() {
    float p;
    cout << "Ingrese la longitud en PULGADAS para convertir a PIES y a MILLAS: ";
    cin>>p;
    cout << "\nPulgadas: "<<p<<endl;
    p=p/12;
    cout << "\nPies: "<<p<<endl;
    p=p/5280;
    cout << "\nMillas: "<<p<<endl;
    return 0;
}
