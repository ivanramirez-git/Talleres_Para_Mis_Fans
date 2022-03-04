using System;

class Program
{
    public void leerDatos(string[] nombre, double[] calidad, double[] entrega, double[] garantia, double[] costo, double[] colaboracion, int m)
    {

        for (int i = 0; i < m; i++)
        {
            Console.WriteLine("Ingrese la calidad del proveedor " + (i) + ": ");
            calidad[i] = double.Parse(Console.ReadLine());
            Console.WriteLine("Ingrese la entrega del proveedor " + (i) + ": ");
            entrega[i] = double.Parse(Console.ReadLine());
            Console.WriteLine("Ingrese la garantia del proveedor " + (i) + ": ");
            garantia[i] = double.Parse(Console.ReadLine());
            Console.WriteLine("Ingrese el costo del proveedor " + (i) + ": ");
            costo[i] = double.Parse(Console.ReadLine());
            Console.WriteLine("Ingrese la colaboracion del proveedor " + (i) + ": ");
            colaboracion[i] = double.Parse(Console.ReadLine());
            nombre[i] = "Proveedor " + (i);
        }
    }
    public double[] calificacionDatos(string[] nombre, double[] calidad, double[] entrega, double[] garantia, double[] costo, double[] colaboracion, int m)
    {
        // La calificacion para cada proveedor es el promedio de las calificaciones de todas las caracteristicas
        // Promedio por proveedor
        double[] calificacion = new double[m];
        for (int i = 0; i < m; i++)
        {
            calificacion[i] = (calidad[i] + entrega[i] + garantia[i] + costo[i] + colaboracion[i]) / 5;
        }
        return calificacion;
    }

    // Ordena los proveedores por calificacion
    public void ordenarDatos(string[] nombre, double[] calidad, double[] entrega, double[] garantia, double[] costo, double[] colaboracion, double[] calificacion, int m)
    {
        
        // Ordenar todo en orden ascendente
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (calificacion[i] < calificacion[j])
                {
                    double temp = calificacion[i];
                    calificacion[i] = calificacion[j];
                    calificacion[j] = temp;

                    double temp2 = calidad[i];
                    calidad[i] = calidad[j];
                    calidad[j] = temp2;

                    double temp3 = entrega[i];
                    entrega[i] = entrega[j];
                    entrega[j] = temp3;

                    double temp4 = garantia[i];
                    garantia[i] = garantia[j];
                    garantia[j] = temp4;

                    double temp5 = costo[i];
                    costo[i] = costo[j];
                    costo[j] = temp5;

                    double temp6 = colaboracion[i];
                    colaboracion[i] = colaboracion[j];
                    colaboracion[j] = temp6;
                    
                    string temp7 = nombre[i];
                    nombre[i] = nombre[j];
                    nombre[j] = temp7;

                }
            }
        }
    }

    public static void Main(string[] args)
    {// See https://aka.ms/new-console-template for more information
        Console.WriteLine("Ejercicio 1\n");

        // Ingresar proveedores
        Console.WriteLine("Ingrese el numero m de proveedores: ");
        int m = int.Parse(Console.ReadLine());

        // Arreglos de proveedores
        string[] nombre = new string[m];
        double[] calidad = new double[m];
        double[] entrega = new double[m];
        double[] garantia = new double[m];
        double[] costo = new double[m];
        double[] colaboracion = new double[m];

        // Ingreso de datos
        Program p = new Program();
        p.leerDatos(nombre, calidad, entrega, garantia, costo, colaboracion, m);

        // Califiacion de datos
        double[] calificacion = p.calificacionDatos(nombre, calidad, entrega, garantia, costo, colaboracion, m);

        // Ordenar datos
        p.ordenarDatos(nombre, calidad, entrega, garantia, costo, colaboracion, calificacion, m);

        // Cuales son los 2 proveedores con mejor calificacion
        Console.WriteLine("\nLos 2 proveedores con mejor calificacion son: ");
        for (int i = m - 1; i > m - 3; i--)
        {
            Console.WriteLine("\n" + nombre[i] + ": " + calificacion[i]);
        }

        // Imprimir ordenados
        Console.WriteLine("\n\nProveedor\tCalidad\tEntrega\tGarantia\tCosto\tColaboracion\tCalificacion");
        for (int i = 0; i < 5; i++)
        {
            Console.WriteLine(nombre[i] + "\t" + calidad[i] + "\t" + entrega[i] + "\t" + garantia[i] + "\t" + costo[i] + "\t" + colaboracion[i] + "\t" + calificacion[i]);
        }

    }

}