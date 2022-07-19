using System;

namespace Program
{
    class Program
    {
        static void Main(string[] args)
        {
            // Mensaje de bienvenida
            Console.WriteLine("Bienvenido al convertidor de valores");
            // 1 dolar : 3.73 soles
            // 1 euro : 4.2 soles
            int opcion;

            do
            {
                Console.WriteLine("1. Convertir dolares a soles");
                Console.WriteLine("2. Convertir euros a soles");
                Console.WriteLine("3. Convertir soles a dolares");
                Console.WriteLine("4. Convertir soles a euros");
                Console.WriteLine("0. Salir");
                Console.WriteLine("Ingrese una opcion: ");
                try
                {
                    opcion = Convert.ToInt32(Console.ReadLine());
                }
                catch (Exception)
                {
                    Console.WriteLine("Opcion no valida");
                    opcion = -1;
                }

                switch (opcion)
                {
                    case 1:
                        Console.WriteLine("Ingrese la cantidad de dolares a convertir: ");
                        try
                        {
                            double dolares = Convert.ToDouble(Console.ReadLine());
                            double soles = dolares * 3.73;
                            Console.WriteLine("{0} dolares son {1} soles", dolares, soles);
                        }
                        catch (Exception)
                        {
                            Console.WriteLine("Cantidad no valida");
                        }
                        break;
                    case 2:
                        Console.WriteLine("Ingrese la cantidad de euros a convertir: ");
                        try
                        {
                            double euros = Convert.ToDouble(Console.ReadLine());
                            double soles = euros * 4.2;
                            Console.WriteLine("{0} euros son {1} soles", euros, soles);
                        }
                        catch (Exception)
                        {
                            Console.WriteLine("Cantidad no valida");
                        }
                        break;
                    case 3:
                        Console.WriteLine("Ingrese la cantidad de soles a convertir: ");
                        try
                        {
                            double soles = Convert.ToDouble(Console.ReadLine());
                            double dolares = soles / 3.73;
                            Console.WriteLine("{0} soles son {1} dolares", soles, dolares);
                        }
                        catch (Exception)
                        {
                            Console.WriteLine("Cantidad no valida");
                        }
                        break;
                    case 4:
                        Console.WriteLine("Ingrese la cantidad de soles a convertir: ");
                        try
                        {
                            double soles = Convert.ToDouble(Console.ReadLine());
                            double euros = soles / 4.2;
                            Console.WriteLine("{0} soles son {1} euros", soles, euros);
                        }
                        catch (Exception)
                        {
                            Console.WriteLine("Cantidad no valida");
                        }
                        break;
                    case 0:
                        Console.WriteLine("Gracias por usar el convertidor");
                        break;

                }

            } while (opcion != 0);

        }
    }
}