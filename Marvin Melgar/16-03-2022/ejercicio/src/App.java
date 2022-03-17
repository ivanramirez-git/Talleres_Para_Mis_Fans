import java.io.BufferedReader;
import java.io.InputStreamReader;

public class App {
    public static void main(String[] args) throws Exception {
        int autos[] = {0, 0, 0, 0};

        double precios[] = {10000, 20000, 30000, 50000};

        String marcas[] = {"Mazda    ", "Toyota   ", "Nissan   ", "Kia      "};

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Ingreso de cantidades
        while (true) {
            // listar
            for (int i = 0; i < autos.length; i++) {
                System.out.println((i + 1) + ". " + marcas[i] + " precio: " + precios[i] + " L");
            }
            System.out.println("0. Salir");
            System.out.print("Ingrese el codigo del auto: ");
            int codigo = Integer.parseInt(br.readLine());
            
            if (codigo == 0) {
                break;
            }

            System.out.print("Ingrese la cantidad vendida: ");
            int cantidad = Integer.parseInt(br.readLine());

            autos[codigo - 1] += cantidad;
        }

        // Total vendido
        totalVendido(autos, precios, marcas);
    }

    public static void totalVendido(int autos[], double precios[], String marcas[]) {
        // Automovil\tCantidad\tTotal
        System.out.println("Automovil\tCantidad\tTotal");
        for (int i = 0; i < autos.length; i++) {
            System.out.println(marcas[i] + "\t" + autos[i] + "\t\t" + (autos[i] * precios[i]));
        }
    }
}
