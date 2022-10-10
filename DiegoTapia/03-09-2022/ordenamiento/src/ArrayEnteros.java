import java.util.Scanner;

public class ArrayEnteros {

    public static void iniciar() {
        // Dado un array de enteros que contiene duplicados, devuelve el elemento
        // predominante si esta presente.
        // Un elemento predominante aparece mas que n/2 veces, donde n es el tamaño del
        // array.
        int[] array = null;
        // menu
        // 1. cargar array
        // 2. mostrar array
        // 3. buscar elemento predominante
        // 0. salir
        int opcion = 0;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("1. Cargar array");
            System.out.println("2. Mostrar array");
            System.out.println("3. Buscar elemento predominante");
            System.out.println("0. Salir");
            System.out.print("Opcion: ");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:
                    array = cargarArray(array);
                    break;
                case 2:
                    mostrarArray(array);
                    break;
                case 3:
                    buscarElementoPredominante(array);
                    break;
                case 0:
                    System.out.println("Hasta luego!");
                    break;
                default:
                    System.out.println("Opcion incorrecta!");
            }
        } while (opcion != 0);

    }

    private static int[] cargarArray(int[] array) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese la cantidad de elementos: ");
        int cantidad = sc.nextInt();
        array = new int[cantidad];
        for (int i = 0; i < cantidad; i++) {
            System.out.print("Ingrese el elemento " + (i + 1) + ": ");
            array[i] = sc.nextInt();
        }
        return array;
    }

    private static void mostrarArray(int[] array) {
        if (array == null) {
            System.out.println("El array no ha sido cargado!");
        } else {
            for (int i = 0; i < array.length; i++) {
                System.out.println("Elemento " + (i + 1) + ": " + array[i]);
            }
        }
    }

    // calculo de la complejidad algoritmica
    private static void buscarElementoPredominante(int[] array) { // O(n*n)
        if (array == null) { // O(1)
            System.out.println("El array no ha sido cargado!"); // O(1)
        } else { // O(1)
            int elementoPredominante = 0; // O(1)
            int contador = 0; // O(1)
            for (int i = 0; i < array.length; i++) { // O(n)
                for (int j = 0; j < array.length; j++) { // O(n)
                    if (array[i] == array[j]) { // O(1)
                        contador++; // O(1)
                    } // O(1)
                } // O(n)
                if (contador > array.length / 2) { // O(1)
                    elementoPredominante = array[i]; // O(1)
                } // O(1)
                contador = 0; // O(1)
            } // O(n)
            if (elementoPredominante != 0) { // O(1)
                System.out.println("El elemento predominante es: " + elementoPredominante); // O(1)
            } else { // O(1)
                System.out.println("No hay elemento predominante!"); // O(1)
            } // O(1)
        } // O(1)
    } // O(n*n)

    // Conclusiones de la complejidad algoritmica
    /*
     * El algoritmo es de complejidad O(n*n) porque tiene dos bucles anidados.
     */

}
