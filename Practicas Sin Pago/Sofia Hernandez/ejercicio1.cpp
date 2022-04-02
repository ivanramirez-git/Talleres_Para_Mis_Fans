#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    if (n % 7 == 0)
    {
        for (int i = 100; i <= 200; i += 2)
        {
            cout << i << endl;
        }
    }
    else
    {
        for (int i = 1000; i >= 400; i -= 5)
        {
            cout << i << endl;
        }
    }
    return 0;
}