/* 2) Realiza un programa que defina una matriz de 2x2 y escriba un ciclo para que muestre la diagonal principal de la matriz.*/
// C Sharp

using System;

public class Ejercicio_2
{
    public static void Main()
    {
        int[,] matriz = new int[2, 2];
        int i, j;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                Console.Write("Ingrese el valor de la posicion [{0},{1}]: ", i, j);
                matriz[i, j] = int.Parse(Console.ReadLine());
            }
        }
        Console.WriteLine("\nLa diagonal principal de la matriz es: ");
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (i == j)
                {
                    Console.Write("{0} ", matriz[i, j]);
                }
            }
        }
        Console.WriteLine("\n");
        Console.WriteLine("La diagonal secundaria de la matriz es: ");
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (i + j == 1)
                {
                    Console.Write("{0} ", matriz[i, j]);
                }
            }
        }
        Console.ReadKey();
    }
}