import java.util.Scanner;

class Main {
    public static void main(String[] args) {

        int n;
        double ac = 0;
        Scanner t = new Scanner(System.in);
        Scanner l = new Scanner(System.in);
        do {
            System.out.println("Ingrese n registros: ");
            n = t.nextInt();
        } while (n <= 0);
        // Ticket Cédulas Nombres Tiempo en hora Valor Total
        int tickets[] = new int[n];
        String cedulas[] = new String[n];
        String nombres[] = new String[n];
        int tiempo[] = new int[n];
        double valor[] = new double[n];
        double total[] = new double[n];

        for (int i = 0; i <= nombres.length - 1; i++) {

            System.out.println("Registro " + (i + 1));

            do {
                System.out.println("Ingrese el ticket: ");
                tickets[i] = t.nextInt();
            } while (tickets[i] <= 0);

            do {
                System.out.println("Ingrese la cédula: ");
                cedulas[i] = l.nextLine();
            } while (cedulas[i].equals(""));

            do {
                System.out.println("Ingrese el nombre: ");
                nombres[i] = l.nextLine();
            } while (nombres[i].equals(""));

            do {
                System.out.println("Ingrese el tiempo en hora: ");
                tiempo[i] = t.nextInt();
            } while (tiempo[i] <= 0);

            do {
                System.out.println("Ingrese el valor: ");
                valor[i] = t.nextDouble();
            } while (valor[i] <= 0);

            total[i] = tiempo[i] * valor[i];
            ac = ac + valor[i];
            
            System.out.println("\n");
        }
        System.out.println("Total Recolectado: " + ac);
        System.out.println("Ingrese un nombre: ");
        String nombre = l.nextLine();
        double ac3 = 0;
        for (int i = 0; i <= nombres.length - 1; i++) {
            if (nombres[i].equals(nombre)) {
                ac3 = ac3 + total[i];
            }
        }
        System.out.println("Total de Valores según el nombre ingresado: " + nombre + ": " + ac3);
        int ac4 = 0;
        for (int i = 0; i <= nombres.length - 1; i++) {
            if (nombres[i].equals(nombre)) {
                ac4 = ac4 + tiempo[i];
            }
        }
        System.out.println("Total Horas  según el nombre ingresado: " + nombre + ": " + ac4);
        int ac5 = 0;
        for (int i = 0; i <= nombres.length - 1; i++) {
            if (tiempo[i] > 2) {
                ac5 = ac5 + 1;
            }
        }
        System.out.println("Total de tiempo superiores 2: " + ac5);
        
    }
}