package vista;

public class Vista {


    public Vista() {
    }

    public int menu() {
        System.out.println(".:: BIENVENIDX::. ");
        System.out.println();
        System.out.println("Por favor escoja una opción");
        System.out.println("1. Crear un libro.");
        System.out.println("2. Listar libros por autor.");
        System.out.println("3. Detallar un libro.");
        System.out.println("0. Salir.");

        return 0;
    }
    public void mensajeendl(String mensaje){
        System.out.println(mensaje);
    }
    public void mensaje(String mensaje){
        System.out.print(mensaje);
    }
}
