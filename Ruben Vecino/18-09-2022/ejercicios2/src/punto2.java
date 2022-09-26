import java.util.Scanner;

public class punto2 {
    /*
     * 2. Caballos
     * a. Escriba un método java que reciba como entrada cuatro valores enteros,
     * fila_cab,
     * col_cab, fila_rey y col_rey; y decida si, en un tablero de ajedrez, un
     * caballo en la posición
     * (fila_cab, col_cab) ataca a un rey en la posición (fila_rey, col_rey).
     * b. Escriba un programa que pida al usuario las posiciones de un caballo y un
     * rey en
     * un tablero de ajedrez, y muestre en consola si el rey es atacado por el
     * caballo. El
     * programa debe usar el método creado en el literal a.
     */
    public static void main(String[] args) { // Función principal
        Scanner sc = new Scanner(System.in); // Creación del objeto Scanner para leer datos desde el teclado
        int fila_cab = 0; // Variable para almacenar la fila del caballo
        int col_cab = 0; // Variable para almacenar la columna del caballo
        int fila_rey = 0; // Variable para almacenar la fila del rey
        int col_rey = 0; // Variable para almacenar la columna del rey
        System.out.println("Ingrese la fila del caballo"); // Se solicita la fila del caballo
        fila_cab = sc.nextInt(); // Se lee la fila del caballo
        System.out.println("Ingrese la columna del caballo"); // Se solicita la columna del caballo
        col_cab = sc.nextInt(); // Se lee la columna del caballo 
        System.out.println("Ingrese la fila del rey"); // Se solicita la fila del rey
        fila_rey = sc.nextInt(); // Se lee la fila del rey 
        System.out.println("Ingrese la columna del rey"); // Se solicita la columna del rey
        col_rey = sc.nextInt(); // Se lee la columna del rey
        if (atacaCaballo(fila_cab, col_cab, fila_rey, col_rey)) { // Se verifica si el caballo ataca al rey
            System.out.println("El rey es atacado por el caballo"); // Se muestra el mensaje de que el rey es atacado
        } else { // Si el caballo no ataca al rey
            System.out.println("El rey no es atacado por el caballo"); // Se muestra el mensaje de que el rey no es atacado
        } // Fin del if
    } // Fin de la función principal

    public static boolean atacaCaballo(int fila_cab, int col_cab, int fila_rey, int col_rey) { // Función que verifica si el caballo ataca al rey
        if (fila_cab == fila_rey + 1 && col_cab == col_rey + 2) { // Se verifica si el caballo ataca al rey en la posición (fila_rey + 1, col_rey + 2)
            return true; // Se retorna verdadero
        } else if (fila_cab == fila_rey + 1 && col_cab == col_rey - 2) { // Se verifica si el caballo ataca al rey en la posición (fila_rey + 1, col_rey - 2)
            return true; // Se retorna verdadero
        } else if (fila_cab == fila_rey - 1 && col_cab == col_rey + 2) { // Se verifica si el caballo ataca al rey en la posición (fila_rey - 1, col_rey + 2)
            return true; // Se retorna verdadero
        } else if (fila_cab == fila_rey - 1 && col_cab == col_rey - 2) { // Se verifica si el caballo ataca al rey en la posición (fila_rey - 1, col_rey - 2)
            return true; // Se retorna verdadero
        } else if (fila_cab == fila_rey + 2 && col_cab == col_rey + 1) { // Se verifica si el caballo ataca al rey en la posición (fila_rey + 2, col_rey + 1)
            return true; // Se retorna verdadero
        } else if (fila_cab == fila_rey + 2 && col_cab == col_rey - 1) { // Se verifica si el caballo ataca al rey en la posición (fila_rey + 2, col_rey - 1)
            return true; // Se retorna verdadero
        } else if (fila_cab == fila_rey - 2 && col_cab == col_rey + 1) { // Se verifica si el caballo ataca al rey en la posición (fila_rey - 2, col_rey + 1)
            return true; // Se retorna verdadero
        } else if (fila_cab == fila_rey - 2 && col_cab == col_rey - 1) { // Se verifica si el caballo ataca al rey en la posición (fila_rey - 2, col_rey - 1)
            return true; // Se retorna verdadero
        } else { // Si el caballo no ataca al rey
            return false; // Se retorna falso
        } // Fin del if
    } // Fin de la función atacaCaballo
} // Fin de la clase punto2
