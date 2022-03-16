#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num, c, x, i, j;
    vector<int> V;
    while (cin >> num)
        V.push_back(num);
    for (x = 0; x < V.size(); x++)
    {
        for (i = 0; i < V[x]; i++)
        {
            for (j = 0; j < V[x]; j++)
            {
                cout << c;
                c += 1;
                if (c > 9)
                    c = 0;
                cout << endl;
            }
            if (x + 1 != V.size())
                cout << endl;
        }
    }
    return 0;
}