import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        // Ingreso de datos
        int tipo; // (1-5)
        boolean deuda;
        double tarjeta = 0;
        // si es 1 o 2 se aumenta 25 o 35 % respectivamente, si tiene deuda solo se
        // aumenta la mitad
        // si es 3 o 4 se aumenta 40 , si tiene deuda no se aumenta
        // si es 5 se aumenta 50, si tiene deuda no se aumenta

        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese el tipo de tarjeta: ");
        tipo = sc.nextInt();
        System.out.println("Tiene deuda? (s/n)");
        deuda = sc.next().equals("s");
        System.out.println("Ingrese el monto de la tarjeta: ");
        tarjeta = sc.nextDouble();

        // Calculo de la tarjeta
        double tarjeta_nueva = tarjeta;
        if (tipo == 1) {
            if (deuda) {
                tarjeta_nueva = tarjeta * (1.25/2);
            } else {
                tarjeta_nueva = tarjeta * 1.25;
            }
        } else if (tipo == 2) {
            if (deuda) {
                tarjeta_nueva = tarjeta * (1.35/2);
            } else {
                tarjeta_nueva = tarjeta * 1.35;
            }
        } else if (tipo == 3) {
            if (deuda) {
                tarjeta_nueva = tarjeta * 1.4;
            } else {
                tarjeta_nueva = tarjeta * 1.4;
            }
        } else if (tipo == 4) {
            if (deuda) {
                tarjeta_nueva = tarjeta * 1.5;
            } else {
                tarjeta_nueva = tarjeta * 1.5;
            }
        } else if (tipo == 5) {
            if (deuda) {
                tarjeta_nueva = tarjeta * 1.5;
            } else {
                tarjeta_nueva = tarjeta * 1.5;
            }
        }

        // Imprimir resultado
        System.out.println("El nuevo monto de la tarjeta es: " + tarjeta_nueva);
    }
}
