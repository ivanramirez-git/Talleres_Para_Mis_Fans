
// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.math.RoundingMode;
import java.math.BigDecimal;
import java.util.Scanner;

public class ConstantesMatematicas {

    // Método para calcular el valor de "e" utilizando la fórmula dada
    public static BigDecimal calcularE(int iteraciones) {
        BigDecimal e = new BigDecimal(1);
        BigDecimal factorial = new BigDecimal(1);

        for (int i = 1; i <= iteraciones; i++) {
            factorial = factorial.multiply(new BigDecimal(i));
            e = e.add(new BigDecimal(1).divide(factorial, 10, RoundingMode.HALF_UP));
        }

        return e;
    }

    // Método para calcular el valor de "PI" utilizando la fórmula dada
    public static BigDecimal calcularPI(int iteraciones) {
        BigDecimal pi = new BigDecimal(0);
        int signo = 1;

        for (int i = 1; i <= iteraciones; i++) {
            pi = pi.add(new BigDecimal(4 * signo).divide(new BigDecimal(2 * i - 1), 10, RoundingMode.HALF_UP));
            signo *= -1;
        }

        return pi;
    }

    // Método para calcular un término específico de la serie de Fibonacci
    public static int calcularFibonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return calcularFibonacci(n - 1) + calcularFibonacci(n - 2);
        }
    }

    // Método main para mostrar el menú y llamar a los métodos
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int opcion;
        int iteraciones;
        int termino;
        do {
            System.out.println("Menu:");
            System.out.println("1. Calcular e");
            System.out.println("2. Calcular PI");
            System.out.println("3. Calcular un término de Fibonacci");
            System.out.println("4. Salir");
            System.out.print("Ingrese una opcion: ");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:
                    System.out.print("Ingrese el numero de iteraciones: ");
                    iteraciones = sc.nextInt();
                    System.out.println("e = " + calcularE(iteraciones));
                    break;
                case 2:
                    System.out.print("Ingrese el numero de iteraciones: ");
                    iteraciones = sc.nextInt();
                    System.out.println("PI = " + calcularPI(iteraciones));
                    break;
                case 3:
                    System.out.print("Ingrese el termino de Fibonacci a calcular: ");
                    termino = sc.nextInt();
                    System.out.println("Fibonacci de " + termino + " es: " + calcularFibonacci(termino));
                    break;
                case 4:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opcion no valida.");
                    break;
            }
        } while (opcion != 4);
    }
}
