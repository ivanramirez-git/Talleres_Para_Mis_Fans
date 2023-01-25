import java.util.Scanner;

public class App {

    // Método main para mostrar el menu y llamar a los metodos
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int opcion;
        int iteraciones;
        do {
            System.out.println("Menu:");
            System.out.println("1. Calcular e");
            System.out.println("2. Calcular PI");
            System.out.println("3. Salir");
            System.out.print("Ingrese una opcion: ");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:
                    System.out.print("Ingrese el numero de iteraciones: ");
                    iteraciones = sc.nextInt();
                    System.out.println("e = " + ConstantesMatematicas.calcularE(iteraciones));
                    break;
                case 2:
                    System.out.print("Ingrese el numero de iteraciones: ");
                    iteraciones = sc.nextInt();
                    System.out.println("PI = " + ConstantesMatematicas.calcularPI(iteraciones));
                    break;
                case 3:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opcion no valida.");
                    break;
            }
        } while (opcion != 3);
    }
}
