import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        /*
        escriba un programa que lee un archivo de texto e imprime en pantalla las primeras n lineas. si n es mayor que el numero de lineas presentes de un archivo de entrada, imprime hasta la ultima que encuentre.
        */
        
        Scanner sc = new Scanner(System.in);
        
        // Pedir el nombre del archivo
        System.out.println("Ingrese el nombre del archivo: ");
        String nombreArchivo = sc.nextLine();

        // Pedir el numero de lineas a imprimir
        System.out.println("Ingrese el numero de lineas a imprimir: ");
        int numeroLineas = sc.nextInt();

        // Leer el archivo
        // Ruta: data/nombreArchivo.txt
        String linea = "";
        int contadorLineas = 0;
        int contadorLineasImprimir = 0;
        try {
            Scanner scArchivo = new Scanner(new java.io.File("data/" + nombreArchivo));
            while (scArchivo.hasNextLine()) {
                linea = scArchivo.nextLine();
                contadorLineas++;
                if (contadorLineasImprimir < numeroLineas) {
                    System.out.println(linea);
                    contadorLineasImprimir++;
                }
            }
        } catch (Exception e) {
            System.out.println("Error al leer el archivo");
        }

    }
}
