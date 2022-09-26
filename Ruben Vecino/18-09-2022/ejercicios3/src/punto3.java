import java.util.Scanner;

public class punto3 {
    /*
     * 3. Cadenas amigas
     * Se dice que dos cadenas S y T son amigas si existen dos cadenas no vacías u y
     * v tales que
     * S = uv y T = vu. Por ejemplo, “tokyo” y “kyoto” son amigas, siendo u = “to” y
     * v = “kyo”.
     * Escriba un programa java que reciba como entrada dos cadenas S y T, e imprima
     * si S y T son
     * amigas.
     */
    public static void main(String[] args) { // Función principal
        Scanner sc = new Scanner(System.in); // Creación del objeto Scanner
        System.out.println("Ingrese la primera cadena"); // Se pide la primera cadena
        String S = sc.nextLine(); // Se lee la primera cadena
        System.out.println("Ingrese la segunda cadena"); // Se pide la segunda cadena
        String T = sc.nextLine(); // Se lee la segunda cadena
        boolean sonAmigas = sonAmigas(S, T); // Se calcula si las cadenas son amigas
        if (sonAmigas) { // Si las cadenas son amigas
            System.out.println("Las cadenas son amigas"); // Se imprime que las cadenas son amigas
        } else { // Si las cadenas no son amigas
            System.out.println("Las cadenas no son amigas"); // Se imprime que las cadenas no son amigas
        } // Fin del if
    } // Fin de la función principal

    public static boolean sonAmigas(String S, String T) { // Función que calcula si las cadenas son amigas
        boolean sonAmigas = false; // Variable que almacena si las cadenas son amigas
        for (int i = 1; i < S.length(); i++) { // Se recorre la primera cadena
            for (int j = 1; j < T.length(); j++) { // Se recorre la segunda cadena
                String u = S.substring(0, i); // Se obtiene la primera parte de la primera cadena
                String v = S.substring(i); // Se obtiene la segunda parte de la primera cadena
                String u2 = T.substring(0, j); // Se obtiene la primera parte de la segunda cadena
                String v2 = T.substring(j); // Se obtiene la segunda parte de la segunda cadena
                if (u.equals(v2) && v.equals(u2)) { // Si las partes de las cadenas son iguales
                    sonAmigas = true; // Se actualiza la variable
                } // Fin del if
            } // Fin del for
        } // Fin del for
        return sonAmigas; // Se retorna si las cadenas son amigas
    } // Fin de la función que calcula si las cadenas son amigas

}
