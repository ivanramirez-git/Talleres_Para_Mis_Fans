// Dado un rango de valores, establecidos por un límite inferior y límite superior, ambos ingresados desde el teclado. Escribir un programa utilizando la estructura repetitiva FOR que permita generar los números impares, comprendidos en ese rango de valores

using System;

class Examen
{
    static void Main()
    {
        int limiteInferior, limiteSuperior, contador, auxiliar;

        // Ramdom semilla time
        Random random = new Random();

        Console.Write("Ingrese el limite inferior: ");
        limiteInferior = Convert.ToInt32(Console.ReadLine());
        Console.Write("Ingrese el limite superior: ");
        limiteSuperior = Convert.ToInt32(Console.ReadLine());
        contador = limiteInferior;
        for (contador = limiteInferior; contador <= limiteSuperior; contador++)
        {
            auxiliar = random.Next(limiteInferior, limiteSuperior);
            while (auxiliar % 2 == 0)
            {
                auxiliar = random.Next(limiteInferior, limiteSuperior);
            }
            Console.WriteLine(auxiliar);
        }
    }
}
