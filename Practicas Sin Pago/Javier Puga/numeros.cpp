#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n_inicial=-1;
    // no avanzar hasta que se introduzca un numero entre 0 y 9
    while (cin >> n_inicial && n_inicial < 0 || n_inicial > 9);    
    int nS[n_inicial];
    nS[0]=n_inicial;
    for (int i=1; i<n_inicial; i++)
    {
        cin >> nS[i];
    }
    // matrices de numeros
    for (int i=0; i<n_inicial; i++)
    {
        for (int j=0; j<nS[i]; j++)
        {
            for (int k=0; k<nS[i]; k++)
            {
                cout << rand()%10;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}