import java.util.ArrayList;
import java.util.Scanner;

public class App2 {
    public static void main(String[] args) throws Exception {
        /*
        Una forma de encriptamiento muy utilizada es sustituir cada caracter por otro. El programador puede definir una tabla que contenga el caracter original y otra tablaque contrnga el caracter por el cual se va a sustituir.
        Escriba un programa permita encriptar y desencriptar un archivo de texto por sustitucion con una tabla de equivalencias definida por el programador.
        */
        
        Scanner sc = new Scanner(System.in);
        
        // Pedir el nombre del archivo
        System.out.println("Ingrese el nombre del archivo original: ");
        String nombreArchivo = sc.nextLine();

        // Pedir el nombre del archivo para guardar el resultado
        System.out.println("Ingrese el nombre del archivo para guardar el archivo encriptado: ");
        String nombreArchivoEncriptado = sc.nextLine();

        // Pedir el nombre del archivo para guardar el resultado
        System.out.println("Ingrese el nombre del archivo para guardar el resultado: ");
        String nombreArchivoDesencriptado = sc.nextLine();
        String nombreArchivoLeer = new String();

        // Tabla de equivalencias
        String[] tabla = new String[2];

        tabla[0]= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,;: "; // Caracteres originales
        tabla[1]= "xyzabcdefghijklmnopqrstuvwXYZABCDEFGHIJKLMNOPQRSTUVW9876543210.:,; "; // Caracteres por los cuales se sustituyen

        
        int opcion;

        // Menu
        do {
            System.out.println("1. Encriptar archivo original");
            System.out.println("2. Desencriptar archivo encriptado");
            System.out.println("3. Leer un archivo de texto");
            System.out.println("4. Salir");
            System.out.println("Ingrese una opcion: ");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:
                    // Encriptar
                    // Ruta: data/nombreArchivo.txt
                    // Guardar en: data/nombreArchivoEncriptado.txt
                    try {
                        Scanner scArchivo = new Scanner(new java.io.File("data/" + nombreArchivo));
                        java.io.PrintWriter pw = new java.io.PrintWriter("data/" + nombreArchivoEncriptado);
                        while (scArchivo.hasNextLine()) {
                            ArrayList<String> linea = new ArrayList<String>();
                            String lineaOriginal = scArchivo.nextLine();
                            for (int i = 0; i < lineaOriginal.length(); i++) {
                                for (int j = 0; j < tabla[0].length(); j++) {
                                    if (lineaOriginal.charAt(i) == tabla[0].charAt(j)) {
                                        linea.add(tabla[1].charAt(j) + "");
                                    }
                                }
                            }
                            for (int i = 0; i < linea.size(); i++) {
                                pw.print(linea.get(i));
                            }
                            pw.println();
                        }
                        pw.close();
                        scArchivo.close();
                    } catch (Exception e) {
                        System.out.println("Error al encriptar el archivo");
                    }
                    break;
                case 2:
                    // Desencriptar
                    // Ruta: data/nombreArchivoEncriptado.txt
                    // Guardar en: data/nombreArchivoResultado.txt
                    try {
                        Scanner scArchivo = new Scanner(new java.io.File("data/" + nombreArchivoEncriptado));
                        java.io.PrintWriter pw = new java.io.PrintWriter("data/" + nombreArchivoDesencriptado);
                        while (scArchivo.hasNextLine()) {
                            ArrayList<String> linea = new ArrayList<String>();
                            String lineaOriginal = scArchivo.nextLine();
                            for (int i = 0; i < lineaOriginal.length(); i++) {
                                for (int j = 0; j < tabla[1].length(); j++) {
                                    if (lineaOriginal.charAt(i) == tabla[1].charAt(j)) {
                                        linea.add(tabla[0].charAt(j) + "");
                                    }
                                }
                            }
                            for (int i = 0; i < linea.size(); i++) {
                                pw.print(linea.get(i));
                            }
                            pw.println();
                        }
                        pw.close();
                        scArchivo.close();
                    } catch (Exception e) {
                        System.out.println("Error al desencriptar el archivo");
                    }
                case 3:
                    // Leer un archivo de texto
                    // Pedir el nombre del archivo
                    System.out.println("Ingrese el nombre del archivo a leer: ");
                    // Lipiar el buffer
                    sc.nextLine();
                    nombreArchivoLeer = sc.nextLine();
                            
                    try {
                        Scanner scArchivo = new Scanner(new java.io.File("data/" + nombreArchivoLeer));
                        while (scArchivo.hasNextLine()) {
                            System.out.println(scArchivo.nextLine());
                        }
                        scArchivo.close();
                    } catch (Exception e) {
                        System.out.println("Error al leer el archivo");
                    }
                    break;
                case 4:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opcion invalida");
                    break;
            }
        } while (opcion != 4);

    }
}
