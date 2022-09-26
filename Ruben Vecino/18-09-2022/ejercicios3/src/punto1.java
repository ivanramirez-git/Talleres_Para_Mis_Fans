import java.util.Scanner;

public class punto1 {
    /*
     * 1. Moda
     * Escriba un programa que reciba como entrada un arreglo de reales x e imprima
     * el elemento
     * moda de x. Suponga que x tiene una única moda.
     */
    public static void main(String[] args) { // Función principal
        Scanner sc = new Scanner(System.in); // Creación del objeto Scanner
        System.out.println("Ingrese el tamaño del arreglo"); // Se pide el tamaño del arreglo
        int n = sc.nextInt(); // Se lee el tamaño del arreglo
        double[] x = new double[n]; // Se crea el arreglo
        for (int i = 0; i < n; i++) { // Se llena el arreglo
            System.out.print("Ingrese el elemento " + i + ": "); // Se pide el elemento
            x[i] = sc.nextDouble(); // Se lee el elemento
        } // Fin del for
        double moda = moda(x); // Se calcula la moda
        System.out.println("La moda es: " + moda); // Se imprime la moda
    } // Fin de la función principal

    public static double moda(double[] x) { // Función que calcula la moda
        double moda = 0; // Variable que almacena la moda
        int contador = 0; // Variable que almacena el número de veces que se repite un elemento
        for (int i = 0; i < x.length; i++) { // Se recorre el arreglo
            int contador2 = 0; // Variable que almacena el número de veces que se repite un elemento
            for (int j = 0; j < x.length; j++) { // Se recorre el arreglo
                if (x[i] == x[j]) { // Si el elemento es igual a otro elemento
                    contador2++; // Se incrementa el contador para ese elemento
                } // Fin del if
            } // Fin del for
            if (contador2 > contador) { // Si el contador para ese elemento es mayor al contador actual
                moda = x[i]; // Se actualiza la moda
                contador = contador2; // Se actualiza el contador
            } // Fin del if
        } // Fin del for
        return moda; // Se retorna la moda
    } // Fin de la función que calcula la moda
} // Fin de la clase punto1