#include <iostream>

using namespace std;

int main() {
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    
    string orden;
    cin >> orden;

    int A, B, C;

    if (num1 < num2 && num1 < num3) {
        A = num1;
        if (num2 < num3) {
            B = num2;
            C = num3;
        } else {
            B = num3;
            C = num2;
        }
    } else if (num2 < num1 && num2 < num3) {
        A = num2;
        if (num1 < num3) {
            B = num1;
            C = num3;
        } else {
            B = num3;
            C = num1;
        }
    } else {
        A = num3;
        if (num1 < num2) {
            B = num1;
            C = num2;
        } else {
            B = num2;
            C = num1;
        }
    }
    
    // imprimir
    if (orden == "ABC") 
        cout << A << " " << B << " " << C << endl;

    if (orden == "ACB") 
        cout << A << " " << C << " " << B << endl;

    if (orden == "BAC") 
        cout << B << " " << A << " " << C << endl;

    if (orden == "BCA") 
        cout << B << " " << C << " " << A << endl;

    if (orden == "CAB") 
        cout << C << " " << A << " " << B << endl;

    if (orden == "CBA") 
        cout << C << " " << B << " " << A << endl;
            
    return 0;
}