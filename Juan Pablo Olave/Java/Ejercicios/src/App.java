import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {

        // Variable para pedir datos al usuario
        Scanner sc = new Scanner(System.in);

        // Ejercicio Promedio
        System.out.println("Ejercicio Promedio");

        /* Programa que pida n numeros al usuario y luego muestre el promedio */

        // Variables
        int n, numeros[], suma;
        float promedio;

        // Pedir datos al usuario
        System.out.println("Ingrese la cantidad de numeros a ingresar: ");
        n = sc.nextInt();

        // Inicializar el arreglo
        numeros = new int[n];

        // Pedir los numeros al usuario
        for (int i = 0; i < n; i++) {
            System.out.println("Ingrese el numero " + (i + 1) + ": ");
            numeros[i] = sc.nextInt();
        }

        // Calcular el promedio
        suma = 0;
        for (int i = 0; i < n; i++) {
            suma += numeros[i];
        }
        promedio = (float) suma / n;

        // Mostrar el promedio
        System.out.println("El promedio es: " + promedio);
        
        // Fin Ejercicio Promedio


        // Ejercicio Sueldo
        System.out.println("Ejercicio Sueldo");

        /* Programa que calcula e imprime el sueldo de un empleado. Si el numero de horas trabajadas esmayor a 40, el excedente se paga al doble del pago por hora. */

        // Variables
        int horasTrabajadas;
        float pagoPorHora;

        // Pedir datos al usuario
        System.out.println("Ingrese la cantidad de horas trabajadas: ");
        horasTrabajadas = sc.nextInt();
        
        System.out.println("Ingrese el pago por hora: ");
        pagoPorHora = sc.nextFloat();

        // Calcular el sueldo
        float sueldo;
        if (horasTrabajadas > 40) {
            sueldo = (40 * pagoPorHora) + ((horasTrabajadas - 40) * (pagoPorHora * 2));
        } else {
            sueldo = horasTrabajadas * pagoPorHora;
        }

        // Mostrar el sueldo
        System.out.println("El sueldo es: " + sueldo);

        // Fin Ejercicio Sueldo
    }
}
