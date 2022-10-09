import java.util.Scanner;

public class MetodosBusqueda {

    public static void iniciar() {
        int[] vector = null;
        // menu
        // 1. cargar vector
        // 2. mostrar vector
        // 3. buscar elemento
        // 0. salir
        int opcion = 0;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("1. Cargar vector");
            System.out.println("2. Mostrar vector");
            System.out.println("3. Buscar elemento");
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
                    buscarElemento(vector);
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
                System.out.println("Elemento " + (i + 1) + ": " + vector[i]);
            }
        }
    }

    // busqueda binaria
    private static void buscarElemento(int[] vector) {
        if (vector == null) {
            System.out.println("El vector no ha sido cargado!");
        } else {
            Scanner sc = new Scanner(System.in);
            System.out.print("Ingrese el elemento a buscar: ");
            int elemento = sc.nextInt();
            int posicion = busquedaBinaria(vector, elemento);
            if (posicion == -1) {
                System.out.println("El elemento no se encuentra en el vector!");
            } else {
                System.out.println("El elemento se encuentra en la posicion " + (posicion + 1));
            }
        }
    }

    private static int busquedaBinaria(int[] vector, int elemento) {
        int inicio = 0;
        int fin = vector.length - 1;
        int medio = 0;
        while (inicio <= fin) {
            medio = (inicio + fin) / 2;
            if (vector[medio] == elemento) {
                return medio;
            } else if (vector[medio] < elemento) {
                inicio = medio + 1;
            } else {
                fin = medio - 1;
            }
        }
        return -1;
    }

}
