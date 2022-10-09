import java.util.Scanner;

public class MetodosOrdenamiento {

    /**
     * 
     */
    public static void iniciar() {

        // vector de enteros
        int[] vector = null;
        Scanner sc = new Scanner(System.in);
        // menu
        // 1. cargar vector
        // 2. mostrar vector
        // 3. ordenar vector
        // 0. salir
        int opcion = 0;
        do {
            System.out.println("1. Cargar vector");
            System.out.println("2. Mostrar vector");
            System.out.println("3. Ordenar vector");
            System.out.println("0. Salir");
            System.out.print("Opcion: ");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:
                    vector = cargarVector(vector);
                    break;
                case 2:
                    mostrarVector(vector);
                    break;
                case 3:
                    vector = ordenarVector(vector);
                    break;
                case 0:
                    System.out.println("Hasta luego!");
                    break;
                default:
                    System.out.println("Opcion incorrecta!");
            }
        } while (opcion != 0);

    }

    private static int[] cargarVector(int[] vector) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese la cantidad de elementos: ");
        int cantidad = sc.nextInt();
        vector = new int[cantidad];
        for (int i = 0; i < cantidad; i++) {
            System.out.print("Ingrese el elemento " + (i + 1) + ": ");
            vector[i] = sc.nextInt();
        }
        return vector;
    }

    private static void mostrarVector(int[] vector) {
        if (vector == null) {
            System.out.println("El vector no ha sido cargado!");
        } else {
            for (int i = 0; i < vector.length; i++) {
                System.out.print(vector[i] + " ");
            }
            System.out.println();
        }
    }

    // ordenar de forma descendente mediante el metodo merge sort
    private static int[] ordenarVector(int[] vector) {
        if (vector == null) {
            System.out.println("El vector no ha sido cargado!");
        } else {
            mergeSort(vector, 0, vector.length - 1);
        }
        return vector;
    }

    private static void mergeSort(int[] vector, int inicio, int fin) {
        if (inicio < fin) {
            int mitad = (inicio + fin) / 2;
            mergeSort(vector, inicio, mitad);
            mergeSort(vector, mitad + 1, fin);
            merge(vector, inicio, mitad, fin);
        }
    }

    private static void merge(int[] vector, int inicio, int mitad, int fin) {
        int[] aux = new int[vector.length];
        for (int i = inicio; i <= fin; i++) {
            aux[i] = vector[i];
        }
        int i = inicio;
        int j = mitad + 1;
        int k = inicio;
        while (i <= mitad && j <= fin) {
            if (aux[i] >= aux[j]) {
                vector[k] = aux[i];
                i++;
            } else {
                vector[k] = aux[j];
                j++;
            }
            k++;
        }
        while (i <= mitad) {
            vector[k] = aux[i];
            k++;
            i++;
        }
    }
}
