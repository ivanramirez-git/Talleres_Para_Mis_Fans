/*
Dadoncaracteres, imprima los caracteres en orden ascendente en
función a su frecuencia en el vector.

Por ejemplo:
Con las letras: a,a,b,a,c,c,c,d
Las letras no repetidas serian: c,a,b
Su orden original: a,a,a,b,c,c,d
La respuesta: a,c,b,d
Nota: puede emplear pair.
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string frase;
    vector<char> v;
    char c;
    int i = 0;
    cout << "Introduzca una frase: ";
    cin >> frase;
    while (i < frase.size())
    {
        v.push_back(frase[i]);
        i++;
    }
    cout << "Orden original: ";
    for (i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << endl;
    cout << "Respuesta: ";
    vector<pair<char, int>> v2;
    for (i = 0; i < v.size(); i++)
    {
        c = v[i];
        int j = 0;
        while (j < v2.size())
        {
            if (v2[j].first == c)
            {
                v2[j].second++;
                break;
            }
            j++;
        }
        if (j == v2.size())
        {
            v2.push_back(make_pair(c, 1));
        }
    }
    // ordenar por frecuencia
    for (i = 0; i < v2.size(); i++)
    {
        for (int j = i + 1; j < v2.size(); j++)
        {
            if (v2[i].second < v2[j].second)
            {
                pair<char, int> aux = v2[i];
                v2[i] = v2[j];
                v2[j] = aux;
            }
        }
    }
    for (i = 0; i < v2.size(); i++)
    {
        cout << v2[i].first;
    }
    cout << endl;
    return 0;
}
