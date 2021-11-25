
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    for (int i = 1, j = 1; i <= n; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            cout << j << " ";
            j++;
            if (j > n){
                cout << endl;
                return 0;
            }                
        }
        cout << endl;
    }

}