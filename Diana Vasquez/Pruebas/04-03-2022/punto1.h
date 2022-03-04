/*
Abundante: Si el numero n cuando la suma de sus divisores propios es mayor que n.
Perfecto: Si el numero n cuando la suma de sus divisores propios es igual a n.
Deficiente: Si el numero n cuando la suma de sus divisores propios es menor que n.
*/

#ifndef PUNTO1_H
#define PUNTO1_H

// Numeros Propios
int sumaDivisoresPropios(int n)
{
    int suma = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            suma += i;
        }
    }
    return suma;
}

// Abundante
bool esAbundante(int n)
{
    return sumaDivisoresPropios(n) > n;
}

// Perfecto
bool esPerfecto(int n)
{
    return sumaDivisoresPropios(n) == n;
}

// Deficiente
bool esDeficiente(int n)
{
    return sumaDivisoresPropios(n) < n;
}

// Clase de numero
char claseNumero(int n)
{
    if (esAbundante(n))
    {
        return 'A';
    }
    else if (esPerfecto(n))
    {
        return 'P';
    }
    else if (esDeficiente(n))
    {
        return 'D';
    }
    else
    {
        return 'N';
    }
}

#endif // PUNTO1_H
