using System;

class Program
{
    static void Main(string[] args)
    {
        int anioActual = DateTime.Now.Year;
        Console.WriteLine("Ingrese su edad: ");
        int edad = int.Parse(Console.ReadLine());
        Console.WriteLine("Ya fue su cumpleaños? (s/n)");
        string respuesta = Console.ReadLine();
        if (respuesta == "s")
        {
            Console.WriteLine("Su anio de nacimiento es: " + (anioActual - edad));
        } 
        else
        {
            Console.WriteLine("Su anio de nacimiento es: " + (anioActual - edad - 1));
        }

    }
}