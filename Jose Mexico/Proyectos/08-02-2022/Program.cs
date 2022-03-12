using System;
namespace Jose_Mexico
{
    class Program
    {
        // funcion leer
        public static string leer()
        {
            string? linea = Console.ReadLine();
            if (linea == null || linea.Length == 0)
            {
                imprimir("Error: no se puede leer una cadena vacia\n");
                return leer();
            }
            return linea;
        }
        // funcion entero
        public static int entero()
        {
            int n = -1;
            while (n < 0)
            {
                string? s = leer();
                if (s != null)
                {
                    if (int.TryParse(s, out n))
                    {
                        if (n < 0)
                        {
                            imprimir("El numero debe ser positivo\n");
                        }
                    }
                    else
                    {
                        imprimir("El numero debe ser entero\n");
                    }
                }
            }
            return n;
        }

        // funcion real
        public static double real()
        {
            double n = -1;
            while (n < 0)
            {
                string? s = leer();
                if (s != null)
                {
                    if (double.TryParse(s, out n))
                    {
                        if (n < 0)
                        {
                            imprimir("El numero debe ser positivo\n");
                        }
                    }
                    else
                    {
                        imprimir("El numero debe ser real\n");
                    }
                }
            }
            return double.Parse(leer() ?? "0");
        }

        // funcion caracter
        public static char caracter()
        {
            char c = ' ';
            while (c == ' ')
            {
                string? s = leer();
                if (s != null)
                {
                    if (s.Length == 1)
                    {
                        c = s[0];
                    }
                    else
                    {
                        imprimir("El caracter debe ser una letra\n");
                    }
                }
            }
            return c;
        }

        // funcion digitoEntero
        public static int digitoEntero()
        {
            imprimir("Ingrese un digito: ");
            int min = 0;
            int max = 9;
            int n = -1;
            while (n < min || n > max)
            {
                string? s = leer();
                if (s != null)
                {
                    if (int.TryParse(s, out n))
                    {
                        if (n < min || n > max)
                        {
                            imprimir("El numero debe estar entre " + min + " y " + max + "\n");
                            return digitoEntero();
                        }
                    }
                    else
                    {
                        imprimir("El numero debe ser entero\n");
                        return digitoEntero();
                    }
                }
            }
            return n;
        }

        // funcion leer tarjeta
        public static int[] leerNumeroTarjeta()
        {
            // 16 digitos
            int[] numeroTarjeta = new int[16];
            for (int i = 0; i < 16; i++)
            {
                numeroTarjeta[i] = digitoEntero();
            }

            return numeroTarjeta;
        }

        // funcion leer pin
        public static int leerPin()
        {
            // 4 digitos
            int pin = -1;
            while (pin < 0)
            {
                string? s = leer();
                if (s != null)
                {
                    if (int.TryParse(s, out pin))
                    {
                        if (pin < 1000 || pin > 9999)
                        {
                            imprimir("El pin debe ser entre 1000 y 9999\n");
                            return leerPin();
                        }
                    }
                    else
                    {
                        imprimir("El pin no es un numero valido\n");
                        return leerPin();
                    }
                }
            }
            return pin;
        }

        // funcion leer monto
        public static double leerMonto()
        {
            // monto debe ser positivo
            double monto = -1;
            while (monto < 0)
            {
                string? s = leer();
                if (s != null)
                {
                    if (double.TryParse(s, out monto))
                    {
                        if (monto < 0)
                        {
                            imprimir("El monto debe ser positivo\n");
                            return leerMonto();
                        }
                    }
                    else
                    {
                        imprimir("El monto debe ser un numero valido\n");
                        return leerMonto();
                    }
                }
            }
            return monto;
        }

        // funcion entero aleatorio
        public static int aleatorio(int min, int max)
        {
            Random r = new Random();
            int n = r.Next(min, max);
            return n;
        }

        // funcion leerFecha MM/AA
        public static string leerFecha()
        {
            string fecha = "";
            int mes = -1;
            int anio = -1;
            while (mes < 1 || mes > 12 || anio < 0)
            {
                imprimir("Ingrese una fecha MM/AA: ");
                string? s = leer();
                if (s != null)
                {
                    if (s.Length == 5)
                    {
                        if (int.TryParse(s.Substring(0, 2), out mes))
                        {
                            if (int.TryParse(s.Substring(3, 2), out anio))
                            {
                                if (mes < 1 || mes > 12)
                                {
                                    imprimir("El mes debe estar entre 1 y 12\n");
                                }
                                else if (anio < 0)
                                {
                                    imprimir("El año debe ser positivo\n");
                                }
                            }
                            else
                            {
                                imprimir("El año debe ser entero\n");
                            }
                        }
                        else
                        {
                            imprimir("El mes debe ser entero\n");
                        }
                    }
                    else
                    {
                        imprimir("La fecha debe tener 5 digitos\n");
                    }
                }
            }
            fecha = mes + "/" + anio;
            return fecha;
        }

        // funcion que convierte un int[] a string
        public static string intArrayToString(int[] array)
        {

            // Validar que el array no sea nulo o vacio
            if (array == null || array.Length == 0)
            {
                return "[]";
            }

            string s = "[";
            for (int i = 0; i < array.Length - 1; i++)
            {
                s += array[i] + ",";
            }
            s += array[array.Length - 1] + "]";
            return s;
        }

        // funcion que convierte un doubleList a string
        public static string doubleListToString(List<double> list)
        {
            // Validar que la lista no este vacia
            if (list.Count == 0)
            {
                return "[]";
            }

            string s = "{";
            for (int i = 0; i < list.Count - 1; i++)
            {
                s += list[i] + ",";
            }
            s += list[list.Count - 1] + "}";
            return s;

        }

        // imprimir
        public static void imprimir(string s)
        {
            // imprimir sin salto de linea
            Console.Write(s);
        }

        public static void Main(string[] args)
        {
            imprimir("Bienvenido al sistema de bancos de Jose Mexico\n");

            // Numero de la suerte
            int numeroSuerte = aleatorio(0, 9);
            imprimir("Numero de suerte: " + numeroSuerte + "\n");

            Banco b = new Banco();

            // Menu
            Boolean salir = false;
            while (!salir)
            {
                imprimir("a. Cajero Automatico\n");
                imprimir("b. Sucursal Bancaria\n");
                imprimir("c. Salir\n");
                imprimir("Elija una opcion: ");
                char opcion = caracter();
                if (opcion == 'a')
                {
                    Cajero.iniciar(b);
                }
                else if (opcion == 'b')
                {
                    Sucursal.iniciar(b);
                }
                else if (opcion == 'c')
                {
                    salir = true;
                }
                else
                {
                    imprimir("Opcion invalida");
                }
            }
        }
    }
}