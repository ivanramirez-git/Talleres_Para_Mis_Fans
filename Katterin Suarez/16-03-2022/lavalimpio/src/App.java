import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Bienvenido a LAVALIMPIO");
        Vector<Object> prestamos = new Vector<Object>();
        Scanner sc = new Scanner(System.in);

        // Menu
        int opcion = 0;
        do {

            System.out.println("1. Agregar prestamo");
            System.out.println("2. Mostrar prestamos");
            System.out.println("3. Consultas");
            System.out.println("0. Salir");
            System.out.print("Ingrese una opcion: ");
            opcion = Integer.parseInt(sc.nextLine());

            switch (opcion) {
                case 1:
                    System.out.print("Ingrese el nombre: ");
                    String nombre = sc.nextLine();
                    System.out.print("Ingrese la descripcion: ");
                    String descripcion = sc.nextLine();
                    System.out.print("Ingrese los dias de entrega: ");
                    int diasEntrega = Integer.parseInt(sc.nextLine());
                    System.out.print("Ingrese el valor: ");
                    double valor = Double.parseDouble(sc.nextLine());
                    System.out.print("Ingrese los dias de devolucion: ");
                    int diasDevolucion = Integer.parseInt(sc.nextLine());
                    System.out.print("Ingrese la promocion (En porcentaje, Sin promo = 0): ");
                    double promocion = Double.parseDouble(sc.nextLine());
                    System.out.print("Ingrese la cantidad de lavadoras: ");
                    int lavadoras = Integer.parseInt(sc.nextLine());
                    System.out.print("Ingrese el tiempo: ");
                    double tiempo = Double.parseDouble(sc.nextLine());
                    ArrayList<Object> prestamo = new ArrayList<Object>();
                    prestamo.add(nombre);
                    prestamo.add(descripcion);
                    prestamo.add(diasEntrega);
                    prestamo.add(valor);
                    prestamo.add(diasDevolucion);
                    prestamo.add(promocion);
                    double valorConDescuento = valor - (valor * (promocion / 100));
                    prestamo.add(valorConDescuento);
                    prestamo.add(lavadoras);
                    prestamo.add(tiempo);
                    double tiempoTotal = tiempo * lavadoras;
                    prestamo.add(tiempoTotal);

                    prestamos.add(prestamo);
                    
                    break;
                case 2:
                    System.out.println("\nPrestamos");
                    System.out.println("Nombre\tDescripcion\tDias de entrega\tValor\tDias de devolucion\tPromocion\tValor con descuento\tCantidad de lavadoras\tTiempo total");
                    for (int i = 0; i < prestamos.size(); i++) {
                        ArrayList<Object> prestamo2 = (ArrayList<Object>) prestamos.get(i);
                        System.out.println(prestamo2.get(0) + "\t" + prestamo2.get(1) + "\t" + prestamo2.get(2) + "\t" + prestamo2.get(3) + "\t" + prestamo2.get(4) + "\t" + prestamo2.get(5) + "\t" + prestamo2.get(6) + "\t" + prestamo2.get(7) + "\t" + prestamo2.get(8));
                    }
                    break;
                case 3:
                    int opcion2 = 0;
                    do {
                        System.out.println("1. Numero de promociones");
                        System.out.println("2. Total horas trabajas");
                        System.out.println("3. Total lavadoras empleadas");
                        System.out.println("0. Atras");
                        System.out.print("Ingrese una opcion: ");
                        opcion2 = Integer.parseInt(sc.nextLine());

                        switch (opcion2) {
                            case 1:
                                int promociones = 0;
                                for (int i = 0; i < prestamos.size(); i++) {
                                    ArrayList<Object> prestamo2 = (ArrayList<Object>) prestamos.get(i);
                                    if (prestamo2.size() > 5) {
                                        if ((double) prestamo2.get(5) != 0) {
                                            promociones++;
                                        }
                                    }
                                }
                                System.out.println("El numero de promociones es: " + promociones);
                                break;
                            case 2:
                                double horas = 0;
                                for (int i = 0; i < prestamos.size(); i++) {
                                    ArrayList<Object> prestamo2 = (ArrayList<Object>) prestamos.get(i);
                                    if (prestamo2.size() > 8) {
                                        horas += (double) prestamo2.get(8);
                                    }
                                }
                                System.out.println("El total de horas trabajadas es: " + horas);
                                break;
                            case 3:
                                int lavadorasE = 0;
                                for (int i = 0; i < prestamos.size(); i++) {
                                    ArrayList<Object> prestamo2 = (ArrayList<Object>) prestamos.get(i);
                                    if (prestamo2.size() > 9) {
                                        lavadorasE += (int) prestamo2.get(9);
                                    }
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


