import java.util.Scanner;

public class punto2 {
    /*
     * 2. Problema de los precios
     * Considere el siguiente problema:
     * Pedro abrió su carnicería a las 8 de la mañana. A las 10, viendo que la
     * demanda de carne era alta,
     * incrementó su precio un 10%. Desde las 10:00 am hasta el mediodía no vendió
     * nada, por lo que
     * decidió reducir el precio un 10% en la tarde. Si a las 11 a.m. el precio de
     * la carne era P, ¿cuál era el
     * precio de la carne a las 9:00 a.m.? ¿cuál era el precio de la carne a la 1:00
     * p.m.?
     * a. Escriba un método que reciba como entrada el valor de P y retorne el
     * precio de la
     * carne a las 9:00 a.m.
     * b. Escriba un método que reciba como entrada el valor de P y retorne el
     * precio de la
     * carne a la 1:00 p.m.
     * c. Complete el programa de forma que lea del teclado el valor de P, e imprima
     * en
     * pantalla el precio de la carne a las 9:00 a.m. y a la 1:00 p.m. El programa
     * debe usar
     * los métodos creados en los literales a y b.
     */
    public static void main(String[] args) { // Método principal
        double P = 0; // Variable para almacenar el precio de la carne
        double precio_9 = 0; // Variable para almacenar el precio de la carne a las 9:00 a.m.
        double precio_13 = 0; // Variable para almacenar el precio de la carne a las 1:00 p.m.
        Scanner teclado = new Scanner(System.in); // Objeto para leer datos del teclado
        System.out.println("Ingrese el precio de la carne: "); // Imprime en pantalla el mensaje
        P = teclado.nextDouble(); // Lee el precio de la carne ingresado por el usuario
        precio_9 = precio_9(P); // Llama al método precio_9 y le pasa como parámetro el precio de la carne
        precio_13 = precio_13(P); // Llama al método precio_13 y le pasa como parámetro el precio de la carne
        System.out.println("El precio de la carne a las 9:00 a.m. es: " + precio_9); // Imprime en pantalla el precio de la carne a las 9:00 a.m.
        System.out.println("El precio de la carne a las 1:00 p.m. es: " + precio_13); // Imprime en pantalla el precio de la carne a las 1:00 p.m.
        teclado.close(); // Cierra el objeto teclado
    }
    public static double precio_9(double P) { // Método para calcular el precio de la carne a las 9:00 a.m.
        double precio_9 = 0; // Variable para almacenar el precio de la carne a las 9:00 a.m.
        precio_9 = P * 0.9; // Calcula el precio de la carne a las 9:00 a.m.
        return precio_9; // Retorna el precio de la carne a las 9:00 a.m.
    }
    public static double precio_13(double P) { // Método para calcular el precio de la carne a las 1:00 p.m.
        double precio_13 = 0; // Variable para almacenar el precio de la carne a las 1:00 p.m.
        precio_13 = P * 0.9 * 0.9; // Calcula el precio de la carne a las 1:00 p.m.
        return precio_13; // Retorna el precio de la carne a las 1:00 p.m.
    }
}
