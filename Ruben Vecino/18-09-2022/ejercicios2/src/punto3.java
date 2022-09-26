import java.util.Scanner;

public class punto3 {
    /*
     * 3. Primos menores
     * Escriba un programa que reciba como entrada un número entero, n, e imprima la
     * cantidad de
     * números primos menores o iguales que n.
     * Desarrolle uno de los siguientes ejercicios propuestos. El ejercicio que debe
     * resolver cada
     * equipo será asignado por el tutor del módulo.
     * La entrega debe consistir en un archivo java con la solución del ejercicio.
     */
    public static void main(String[] args) { // Función principal
        Scanner sc = new Scanner(System.in); // Creación del objeto Scanner para leer datos desde el teclado
        int n = 0; // Variable para almacenar el número ingresado por el usuario
        System.out.print("Ingrese un número entero: "); // Se solicita el número al usuario
        n = sc.nextInt(); // Se lee el número ingresado por el usuario
        int contador = 0; // Contador de números primos
        for (int i = 1; i <= n; i++) { // Ciclo para recorrer los números
            if (esPrimo(i)) { // Si el número es primo
                contador++; // Incrementa el contador
            } // Fin del if
        } // Fin del for
        System.out.println("La cantidad de números primos menores o iguales que " + n + " es: " + contador); // Imprime
                                                                                                             // el
                                                                                                             // resultado
    } // Fin de la función principal

    public static boolean esPrimo(int n) { // Función para determinar si un número es primo
        if (n == 1) { // Si el número es 1
            return false; // No es primo
        } // Fin del if
        for (int i = 2; i < n; i++) { // Ciclo para recorrer los números
            if (n % i == 0) { // Si el número es divisible
                return false; // No es primo
            } // Fin del if
        } // Fin del for
        return true; // Es primo
    } // Fin de la función esPrimo
} // Fin de la clase punto3
