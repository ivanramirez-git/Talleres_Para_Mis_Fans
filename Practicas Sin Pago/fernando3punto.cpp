#include <iostream>

using namespace std;

int main(){
    int k;
    cout << "Ingrese un numero k: ";
    cin >> k;

    // Serie fibonacci, cuya suma no puede ser mayor a k
    int a = 0;
    int b = 1;
    int c;
    while (true){
        c = a + b;
        if (c > k){
            break;
        }
        a = b;
        b = c;
        cout << c << endl;
    }
    return 0;
}