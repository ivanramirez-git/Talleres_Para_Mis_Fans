// C# - Algoritmos

// Importamos libreria Math

using System;


public class Program
{
    public static void Main()
    {
        
        // Borrar el ultimo caracter de una cadena String
        string cadena = "Hola Mundo";
        Console.WriteLine(cadena.Remove(cadena.Length - 1));

        // Raiz cuadrada de un numero
        Console.WriteLine(Math.Sqrt(9));



// C++ - Algoritmos

#include <iostream>

using namespace std;

int main()
{
    /*

    <8 - Insufiiciente
    <9 - Bueno
    <=10 - Excelente

    */
    int nota;
    cout << "Ingrese su nota: ";
    cin >> nota;

    if (nota < 8)
    {
        cout << "Insuficiente";
    }
    else if (nota < 9)
    {
        cout << "Bueno";
    }
    else if (nota <= 10)
    {
        cout << "Excelente";
    }
    else
    {
        cout << "Nota fuera de rango";
    }

    return 0;

}