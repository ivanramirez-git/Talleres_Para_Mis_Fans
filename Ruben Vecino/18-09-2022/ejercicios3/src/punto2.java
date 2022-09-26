import java.util.Scanner;

public class punto2 {
    /*
     * 2. Contraseña segura
     * Una contraseña se considera segura si su longitud es mayor o igual a 10,
     * tiene al menos una
     * letra (A-Z, a-z), tiene al menos un dígito (0-9), y tiene al menos un símbolo
     * diferente a letras
     * o dígitos.
     * Escriba un programa que reciba como entrada una cadena y decida si esta
     * corresponde a una
     * contraseña segura.
     */
    public static void main(String[] args) { // Función principal
        Scanner sc = new Scanner(System.in); // Creación del objeto Scanner
        System.out.println("Ingrese la contraseña"); // Se pide la contraseña
        String password = sc.nextLine(); // Se lee la contraseña
        boolean esSegura = esSegura(password); // Se verifica si la contraseña es segura
        if (esSegura) { // Si la contraseña es segura
            System.out.println("La contraseña es segura"); // Se imprime que la contraseña es segura
        } else { // Si la contraseña no es segura
            System.out.println("La contraseña no es segura"); // Se imprime que la contraseña no es segura
        } // Fin del if
    } // Fin de la función principal

    public static boolean esSegura(String password) { // Función que verifica si la contraseña es segura
        boolean esSegura = false; // Variable que almacena si la contraseña es segura
        if (password.length() >= 10) { // Si la contraseña tiene una longitud mayor o igual a 10
            boolean tieneLetra = false; // Variable que almacena si la contraseña tiene una letra
            boolean tieneDigito = false; // Variable que almacena si la contraseña tiene un dígito
            boolean tieneSimbolo = false; // Variable que almacena si la contraseña tiene un símbolo
            for (int i = 0; i < password.length(); i++) { // Se recorre la contraseña
                char caracter = password.charAt(i); // Se obtiene el caracter
                if (Character.isLetter(caracter)) { // Si el caracter es una letra
                    tieneLetra = true; // Se actualiza la variable
                } else if (Character.isDigit(caracter)) { // Si el caracter es un dígito
                    tieneDigito = true; // Se actualiza la variable
                } else { // Si el caracter es un símbolo
                    tieneSimbolo = true; // Se actualiza la variable
                } // Fin del if
            } // Fin del for
            if (tieneLetra && tieneDigito && tieneSimbolo) { // Si la contraseña tiene una letra, un dígito y un símbolo
                esSegura = true; // Se actualiza la variable
            } // Fin del if
        } // Fin del if
        return esSegura; // Se retorna si la contraseña es segura
    } // Fin de la función que verifica si la contraseña es segura

}
