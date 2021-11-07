using System;
class funciones {
    public static void Main() {
        
        // Declaracion de variables y arreglos        
        double[] x = new double[15];
        double[] fcos = new double[15];
        double[] fexp = new double[15];
        double mayorfcos = 0;
        double menorfcos = 0;
        double promediofcos = 0;
        double mayorfexp = 0;
        double menorfexp = 0;
        double promediofexp = 0;
        double sumafcos = 0;
        double sumafexp = 0;


        // Inicializacion de arreglos
        for (int i = 0; i < 15; i++) {
            x[i] = i + 1;
            fcos[i] = FCos(x[i]);
            fexp[i] = FExp(x[i]);
        }

        // Imprimir X 1 a 15 con dos decimales
        Console.WriteLine("X    FCOS(X)    FEXP(X)");
        for (int i = 0; i < 15; i++) {
            Console.WriteLine("{0,3} {1,10:0.00} {2,10:0.00}", x[i], fcos[i], fexp[i]);
        }

        // Buscar el mayor y el menor
        mayorfcos = fcos[0];
        menorfcos = fcos[0];
        mayorfexp = fexp[0];
        menorfexp = fexp[0];
        for (int i = 0; i < 15; i++) {
            if (fcos[i] > mayorfcos) {
                mayorfcos = fcos[i];
            }
            if (fcos[i] < menorfcos) {
                menorfcos = fcos[i];
            }
            if (fexp[i] > mayorfexp) {
                mayorfexp = fexp[i];
            }
            if (fexp[i] < menorfexp) {
                menorfexp = fexp[i];
            }
        }

        // Calcular el promedio
        for (int i = 0; i < 15; i++) {
            sumafcos += fcos[i];
            sumafexp += fexp[i];
        }
        promediofcos = sumafcos / 15;
        promediofexp = sumafexp / 15;

        // Imprimir el mayor, menor y promedio
        Console.WriteLine("\nMayor: {0,10:0.00} {1,10:0.00}", mayorfcos, mayorfexp);
        Console.WriteLine("Menor: {0,10:0.00} {1,10:0.00}", menorfcos, menorfexp);
        Console.WriteLine("Promedio: {0,10:0.00} {1,10:0.00}", promediofcos, promediofexp);
        
        Console.ReadKey();

    }

    // Funcion factorial
    public static double factorial(double x) {
        double fact = 1;
        for (int i = 1; i <= x; i++) {
            fact = fact * i;
        }
        return fact;
    }

    // Funcion retorna potencia x^n
    public static double potencia(double x, int n) {
        double pot = 1;
        for (int i = 1; i <= n; i++) {
            pot = pot * x;
        }
        return pot;
    }

    // Funcion FCos(X)=1 -X^2/2! + X^4/4! + X^6/6! + X^8/8! +...+ X^n/^n!
    public static double FCos(double x) {
        double fcos = 0;
        for (int n = 4; n <= 8; n=n+2) {
            fcos += potencia(x, n) / factorial(n);
        }
        fcos = 1 - (potencia(x, 2) / factorial(2)) + fcos; 
        return fcos;
    }


    // Funcion FExpo(X)=1+X+X^2/2!+X^3/3!+X^4/4!+...+X^n/n!
    public static double FExp(double x) {
        double fexp = 0;
        for (int n = 2; n <= 4; n++) {
            fexp += potencia(x, n) / factorial(n);
        }
        fexp = 1 + x + fexp;
        return fexp;
    }
}