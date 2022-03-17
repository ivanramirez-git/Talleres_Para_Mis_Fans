import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Vector;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Bienvenido a LAVALIMPIO");
        Vector<Prestamo> prestamos = new Vector<Prestamo>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Menu
        int opcion = 0;
        do {
            /*
             * 
             * Prestamo(String nombre, String descripcion, int diasEntrega, double valor,
             * int diasDevolucion, double promocion, int lavadoras, double tiempo)
             * 
             */

            System.out.println("1. Agregar prestamo");
            System.out.println("2. Mostrar prestamos");
            System.out.println("3. Consultas");
            System.out.println("0. Salir");
            System.out.print("Ingrese una opcion: ");
            opcion = Integer.parseInt(br.readLine());

            switch (opcion) {
                case 1:
                    System.out.print("Ingrese el nombre: ");
                    String nombre = br.readLine();
                    System.out.print("Ingrese la descripcion: ");
                    String descripcion = br.readLine();
                    System.out.print("Ingrese los dias de entrega: ");
                    int diasEntrega = Integer.parseInt(br.readLine());
                    System.out.print("Ingrese el valor: ");
                    double valor = Double.parseDouble(br.readLine());
                    System.out.print("Ingrese los dias de devolucion: ");
                    int diasDevolucion = Integer.parseInt(br.readLine());
                    System.out.print("Ingrese la promocion (En porcentaje, Sin promo = 0): ");
                    double promocion = Double.parseDouble(br.readLine());
                    System.out.print("Ingrese la cantidad de lavadoras: ");
                    int lavadoras = Integer.parseInt(br.readLine());
                    System.out.print("Ingrese el tiempo: ");
                    double tiempo = Double.parseDouble(br.readLine());
                    Prestamo p = new Prestamo(nombre, descripcion, diasEntrega, valor, diasDevolucion, promocion,
                            lavadoras, tiempo);
                    prestamos.add(p);
                    break;
                case 2:
                    for (Prestamo p1 : prestamos) {
                        System.out.println(p1);
                    }
                    break;
                case 3:
                    /*
                     * Sub-Menu:
                     * 1. Numero de promociones
                     * 2. Total horas trabajas
                     * 3. Total lavadoras empleadas
                     * 0. Atras
                     */
                    int opcion2 = 0;
                    do {
                        System.out.println("1. Numero de promociones");
                        System.out.println("2. Total horas trabajas");
                        System.out.println("3. Total lavadoras empleadas");
                        System.out.println("0. Atras");
                        System.out.print("Ingrese una opcion: ");
                        opcion2 = Integer.parseInt(br.readLine());

                        switch (opcion2) {
                            case 1:
                                int promociones = 0;
                                for (Prestamo p1 : prestamos) {
                                    if (p1.getPromocion() > 0) {
                                        promociones++;
                                    }
                                }
                                System.out.println("El numero de promociones es: " + promociones);
                                break;
                            case 2:
                                double horas = 0;
                                for (Prestamo p1 : prestamos) {
                                    horas += p1.getTotalTiempo();
                                }
                                System.out.println("El total de horas trabajadas es: " + horas);
                                break;
                            case 3:
                                int lavadorasE = 0;
                                for (Prestamo p1 : prestamos) {
                                    lavadorasE += p1.getLavadoras();
                                }
                                System.out.println("El total de lavadoras empleadas es: " + lavadorasE);
                                break;
                            case 0:
                                break;
                            default:
                                System.out.println("Opcion invalida");
                                break;
                        }
                    } while (opcion2 != 0);
                    break;
                case 0:
                    break;
                default:
                    System.out.println("Opcion invalida");
                    break;

            }
        } while (opcion != 0);

    }

}


