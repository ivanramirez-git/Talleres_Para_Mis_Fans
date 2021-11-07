using System;

/* Una miscelánea necesita un programa que al comprar con un bono, muestre  su precio y un descuento del 15%. El usuario tiene que ingresar el nombre del producto y el precio (mínimo tres productos diferentes). 
Mostrar que productos compro, su precio (sin descuento) y precio total (con descuento 15%). */

class EjercicioEnCS
{
    static void Main()
    {
        // Preguntar cuantos productos va comprar
        Console.WriteLine("¿Cuantos productos va a comprar?");
        int cantidad = Convert.ToInt32(Console.ReadLine());

        // Declarar variables
        string[] producto = new string[cantidad];
        double[] precio = new double[cantidad];
        double precioTotal = 0;
        double precioTotalDescuento = 0;

        // Ingresar los productos y sus precios
        for (int i = 0; i < cantidad; i++)
        {
            Console.WriteLine("Ingrese el nombre del producto");
            producto[i] = Console.ReadLine();
            Console.WriteLine("Ingrese el precio del producto");
            precio[i] = Convert.ToDouble(Console.ReadLine());
        }

        // Mostrar los productos, precio y precio total
        for (int i = 0; i < cantidad; i++)
        {
            Console.WriteLine("Producto: " + producto[i]);
            Console.WriteLine("Precio: " + precio[i]);
            precioTotal += precio[i];
            precioTotalDescuento += precio[i] - (precio[i] * 0.15);
        }

        // Calcular descuento
        double descuento = precioTotal - precioTotalDescuento;        
        
        // Mostrar precio total con descuento
        Console.WriteLine("Precio total: " + precioTotal);
        Console.WriteLine("Descuento: " + descuento);
        Console.WriteLine("Precio total con descuento: " + precioTotalDescuento);

    }
}