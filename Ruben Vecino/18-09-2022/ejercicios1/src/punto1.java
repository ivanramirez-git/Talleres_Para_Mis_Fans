import java.util.Scanner;

public class punto1 {
    /*
     * 1. Siglo
     * En la clase de historia de Juan con frecuencia se habla de los siglos en que
     * ocurrieron ciertos
     * hechos. Esto hace que a Juan se le dificulte un poco ubicar los hechos en una
     * línea de tiempo.
     * Su tarea es escribir un programa java que ayude a Juan.
     * A. Escriba un método java llamado siglo, el cual recibe como entrada el
     * número de un año
     * (positivo), y retorna el número del siglo al que pertenece el año.
     * B. Escriba un método java llamado primer_anho, el cual recibe como entrada el
     * número de
     * un siglo (positivo), y retorna el número del primer año de dicho siglo.
     * C. Complete el programa de forma que lea del teclado un valor n
     * correspondiente a un año,
     * e imprima en pantalla el número del siglo al que pertenece el año n y el
     * primer año de
     * dicho siglo. El programa debe usar los métodos creados en los literales a y
     * b.
     */
    public static void main(String[] args) { // Metodo principal
        int n = 0; // Variable para almacenar el año ingresado por el usuario
        int siglo = 0; // Variable para almacenar el siglo al que pertenece el año
        int primer_anho = 0; // Variable para almacenar el primer año del siglo
        Scanner teclado = new Scanner(System.in); // Objeto para leer datos del teclado
        System.out.println("Ingrese un año: "); // Imprime en pantalla el mensaje
        n = teclado.nextInt(); // Lee el año ingresado por el usuario
        siglo = siglo(n); // Llama al método siglo y le pasa como parámetro el año
        primer_anho = primer_anho(siglo); // Llama al método primer_anho y le pasa como parámetro el siglo
        System.out.println("El año " + n + " pertenece al siglo " + siglo); // Imprime en pantalla el año y el siglo
        System.out.println("El primer año del siglo " + siglo + " es " + primer_anho); // Imprime en pantalla el primer año del siglo
        teclado.close(); // Cierra el objeto teclado
    }  // Fin del método principal

    public static int siglo(int n) { // Método para calcular el siglo al que pertenece el año
        int siglo = 0; // Variable para almacenar el siglo al que pertenece el año
        if (n % 100 == 0) { // Si el año es múltiplo de 100
            siglo = n / 100; // Calcula el siglo
        } else { // Si el año no es múltiplo de 100
            siglo = (n / 100) + 1; // Calcula el siglo
        } // Fin si
        return siglo; // Retorna el siglo
    } // Fin método siglo

    public static int primer_anho(int siglo) { // Método para calcular el primer año del siglo
        int primer_anho = 0; // Variable para almacenar el primer año del siglo
        primer_anho = (siglo - 1) * 100 + 1; // Calcula el primer año del siglo
        return primer_anho; // Retorna el primer año del siglo
    } // Fin método primer_anho
}
