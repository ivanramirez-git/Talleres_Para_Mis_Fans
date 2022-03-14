#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int numero1 = 0;
    cin >> numero1;
    int numero2 = 0;
    cin >> numero2;
    int numero3 = 0;
    cin >> numero3;

    // matriz aleatoria de n1 x n1
    int matriz[numero1][numero1];
    for (int i = 0; i < numero1; i++)
    {
        for (int j = 0; j < numero1; j++)
        {
            matriz[i][j] = rand() % 10;
            cout << matriz[i][j];
        }
        cout << endl;
    }
    cout << endl;
    // matriz aleatoria de n2 x n2
    int matriz2[numero2][numero2];
    for (int i = 0; i < numero2; i++)
    {
        for (int j = 0; j < numero2; j++)
        {
            matriz2[i][j] = rand() % 10;
            cout << matriz2[i][j];
        }
        cout << endl;
    }
    cout << endl;
    // matriz aleatoria de n3 x n3
    int matriz3[numero3][numero3];
    for (int i = 0; i < numero3; i++)
    {
        for (int j = 0; j < numero3; j++)
        {
            matriz3[i][j] = rand() % 10;
            cout << matriz3[i][j];
        }
        cout << endl;
    }

    return 0;
}