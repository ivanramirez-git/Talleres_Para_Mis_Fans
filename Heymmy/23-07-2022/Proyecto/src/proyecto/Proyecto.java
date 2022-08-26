
//Andrés Jimenez Solís
// Heymmy López Juárez
package proyecto;

import javax.swing.JOptionPane;

public class Proyecto {

    public static void main(String[] args) {

        Vendedor vendedor = new Vendedor();
        Cliente cliente = new Cliente();

        Articulo[] articulos = new Articulo[10];
        Integer[] cantidades = new Integer[10];

        int indicador = 0;
        Boolean salida = false;

        Integer seleccion = Integer.parseInt(JOptionPane.showInputDialog(
                "Seleccione el tipo de producto que desea comprar ( 1: Hogar, 2: Abarrotes )"));

        if (seleccion == 1) {
            do {

                String vector[][] = { { "Alfombras", "1200", "07654433" },
                        { "Sombrilla", "2000", "07554412" },
                        { "Cortina ", "1200", "07321455" } };

                System.out.println("Indice\tArticulo\tPrecio\tCantidad");

                for (int i = 0; i < vector.length; i++) {
                    System.out.print((i + 1) + ".");
                    for (int j = 0; j < vector.length; j++) {
                        System.out.print("\t" + vector[i][j]);
                    }
                    System.out.println();
                }

                Integer indice = Integer.parseInt(JOptionPane.showInputDialog(
                        "Según los mostrado en pantalla \n  Ingrese el numero que corresponda al articulo que desea:"));

                Integer compra1 = Integer.parseInt(JOptionPane.showInputDialog("Cuantos productos desea comprar? : "));

                switch (indice) {
                    case 1:
                        System.out.println("Alfombras facturadas correctamente");
                        break;
                    case 2:
                        System.out.println("Sombrilla facturada correctamente");
                        break;
                    case 3:
                        System.out.println("Cortina facturada correctamente");
                        break;
                    default:
                        System.out.println("--Este numero no corresponde a ningún articulo--");
                        break;
                }
                // agregar listas
                Articulo articulo = new Articulo(vector[indice - 1][0],
                        Integer.parseInt(vector[indice - 1][2]),
                        Integer.parseInt(vector[indice - 1][1]));

                articulos[indicador] = articulo;
                cantidades[indicador] = compra1;

                // Decir si sale
                String salida1 = JOptionPane.showInputDialog("¿Desea agregar otro producto? (S/N)");
                salida = (salida1.equals("S") || salida1.equals("s"));
                indicador = indicador + 1;
            } while (salida);

        } else {

            do {
                String Abarrotes[][] = { { "Pan", "600", "07654422" },
                        { "Queso", "1350", "07554457" },
                        { "Huevos", "2100", "07324390" } };
                System.out.println("Indice\tArticulo\tPrecio\tCantidad");
                for (int i = 0; i < Abarrotes.length; i++) {
                    System.out.print((i + 1) + ".");
                    for (int j = 0; j < Abarrotes.length; j++) {
                        System.out.print("\t" + Abarrotes[i][j]);
                    }
                    System.out.println();
                }
                Integer indice = Integer.parseInt(JOptionPane.showInputDialog(
                        "Según los mostrado en pantalla \n  Ingrese el numero que corresponda al articulo que desea:"));

                Integer compra2 = Integer.parseInt(JOptionPane.showInputDialog("Cuantos productos desea comprar? : "));
                switch (indice) {
                    case 1:
                        System.out.println("Pan facturado correctamente");
                        break;
                    case 2:
                        System.out.println("Queso facturado correctamente");
                        break;
                    case 3:
                        System.out.println("Huevos facturado correctamente");
                        break;
                    default:
                        System.out.println("--Este numero no corresponde a ningún articulo--");
                        break;
                }
                Articulo articulo = new Articulo(Abarrotes[indice - 1][0],
                        Integer.parseInt(Abarrotes[indice - 1][2]),
                        Integer.parseInt(Abarrotes[indice - 1][1]));
                articulos[indicador] = articulo;
                cantidades[indicador] = compra2;
                String salida1 = JOptionPane.showInputDialog("¿Desea agregar otro producto? (S/N)");
                salida = (salida1.equals("S") || salida1.equals("s"));
                indicador = indicador + 1;
            } while (salida);
        }

        System.out.println("------VENDEDOR-----");
        vendedor.imprimirVendedor();
        System.out.println("------CLIENTE-----");
        cliente.imprimirCliente();
        System.out.println("------FACTURA-----");
        Facturacion facturacion = new Facturacion(articulos, cantidades, indicador);
        facturacion.imprimirFactura();
    }

}
