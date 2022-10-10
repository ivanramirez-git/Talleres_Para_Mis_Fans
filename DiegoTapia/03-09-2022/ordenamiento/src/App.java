import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        // menu
        // 1. ordenamiento
        // 2. busqueda
        // 3. array de enteros
        // 0. salir
        int opcion = 0;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("1. Ordenamiento");
            System.out.println("2. Busqueda");
            System.out.println("3. Array de enteros");
            System.out.println("0. Salir");
            System.out.print("Opcion: ");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:
                    MetodosOrdenamiento.iniciar();
                    break;
                case 2:
                    MetodosBusqueda.iniciar();
                    break;
                case 3:
                    ArrayEnteros.iniciar();
                    break;
                case 0:
                    System.out.println("Hasta luego!");
                    break;
                default:
                    System.out.println("Opcion incorrecta!");
            }
        } while (opcion != 0);
    }
}
