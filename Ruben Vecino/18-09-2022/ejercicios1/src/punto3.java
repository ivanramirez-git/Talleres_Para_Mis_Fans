import java.util.Scanner;

public class punto3 {
    /*
     * 3. Conversión de medidas de peso
     * Escriba un programa que pida al usuario el número de gramos de masa de un
     * objeto, y
     * muestre en pantalla las conversiones de dicha cantidad a kilogramos, libras y
     * onzas.
     * Desarrolle uno de los siguientes ejercicios propuestos. El ejercicio que debe
     * resolver cada
     * equipo será asignado por el tutor del módulo.
     * La entrega debe consistir en un archivo java con la solución del ejercicio.
     */
    public static void main(String[] args) { // Método principal
        double gramos = 0; // Variable para almacenar los gramos ingresados por el usuario
        double kilogramos = 0; // Variable para almacenar los kilogramos
        double libras = 0; // Variable para almacenar las libras
        double onzas = 0; // Variable para almacenar las onzas
        Scanner teclado = new Scanner(System.in); // Objeto para leer datos del teclado
        System.out.println("Ingrese la cantidad de gramos: "); // Imprime en pantalla el mensaje
        gramos = teclado.nextDouble(); // Lee los gramos ingresados por el usuario
        kilogramos = gramos / 1000; // Calcula los kilogramos
        libras = gramos / 453.592; // Calcula las libras
        onzas = gramos / 28.3495; // Calcula las onzas
        System.out.println("La cantidad de gramos ingresada equivale a: "); // Imprime en pantalla el mensaje
        System.out.println(kilogramos + " kilogramos"); // Imprime en pantalla los kilogramos
        System.out.println(libras + " libras"); // Imprime en pantalla las libras
        System.out.println(onzas + " onzas"); // Imprime en pantalla las onzas
        teclado.close(); // Cierra el objeto teclado
    }
}
