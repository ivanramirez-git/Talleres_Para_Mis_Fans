#include <iostream>

using namespace std;

int main()
{
    // Uso del while
    int n = 5;
    int s = 0;
    int next = 1;
    int i = 1;
    while (i <= n)
    {
        s = s + i*next;
        next = -next;
        i = i + 1;
    }
    cout << "El resultado es: " << s << endl;

    return 0;
}
