package vista;

import java.util.Scanner;
import volumen.ControladorVolumen;

public class Menu {
    private int opcion;

    public void Menu() {
        //SE INSTANCIA LA CLASE SCANNER PARA RECIBIR LOS DATOS
        Scanner entrada = new Scanner(System.in);

        //INICIA EL CICLO PARA EJECUTAR UN MENU MIENTRAS SE CUMPLA LA CONDICION
        do {
            System.out.println("---------------------------MENU PRINCIPAL -----------------------------------");
            //ESTAS SON LAS OPCIONES QUE SE MUESTRAN EN LA PANTALLA
            System.out.println("1. EJERCICIO 1");
            System.out.println("2. EJERCICIO 2");
            System.out.println("3. EJERCICIO 3");
            System.out.println("4. EJERCICIO 4");
            System.out.println("5. EJERCICIO 5");
            System.out.println("6. EJERCICIO 6");
            System.out.println("7. SALIR");
            System.out.println("------------------------------------------------------------------------------");

            //SE PIDE AL USUARIO QUE INGRESE LA OPCION
            System.out.print("POR FAVOR SEÑOR USUARIO DIGITE LA OPCION DESEADA---->");
            opcion = entrada.nextInt();//SE CAPTURA LA OPCION

            //AQUI SE REALIZA LA EJECUCION DE CADA PROGRAMA DE ACUERDO A LA OPCION DIGITADA.
            switch (this.opcion) {
                case 1:
                    double alt,rad;
                    System.out.println("BIENVENIDO AL EJERCICIO 1.");
                    ControladorVolumen t=new ControladorVolumen();
                    System.out.println("DIGITE LA 1ALTURA");
                    alt=entrada.nextDouble();
                    System.out.println("DIGITE EL RADIO");
                    rad=entrada.nextDouble();
                    t.guardarDatos(alt, rad);
                    System.out.println("EL VOLUMEN ES:"+t.mostrarVolumen());
                    break;
                case 2:
                    System.out.println("BIENVENIDO AL EJERCICIO 2.");
                    //AQUÍ VA EL CODIGO DEL EJERCICIO2
                    break;
                case 3:
                    System.out.println("BIENVENIDO AL EJERCICIO 3.");
                    //AQUÍ VA EL CODIGO DEL EJERCICIO3
                    break;
                case 4:
                    System.out.println("BIENVENIDO AL EJERCICIO 4.");
                    //AQUÍ VA EL CODIGO DEL EJERCICIO4
                    break;
                case 5:
                    System.out.println("BIENVENIDO AL EJERCICIO 5.");
                    //AQUÍ VA EL CODIGO DEL EJERCICIO5
                    break;
                case 6:
                    System.out.println("BIENVENIDO AL EJERCICIO 6.");
                    
                    //AQUÍ VA EL CODIGO DEL EJERCICIO6
                    break;
                default:
                    System.out.println("FUE UN GUSTO ATENDERLO");
                    System.exit(0);
            }
        } while (opcion <= 6);//ESTA ES LA CONDICION QUE SE DEBE CUMPLIR. CUANDO NO SE CUMPLE SE ACABA EL PROGRAMA.
    }//MÉTODO MENÚ    
}
