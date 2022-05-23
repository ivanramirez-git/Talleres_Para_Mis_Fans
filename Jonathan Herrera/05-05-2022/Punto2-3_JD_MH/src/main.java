

import java.util.Scanner;

import Punto2_JD_MH.Tabla;
import Punto3_JD_MH.Controlador.Controlador;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author aulasingenieria
 */
public class main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Menu de opciones
        int opcion = 0;
        Scanner sc = new Scanner(System.in);

        do{
            System.out.println("1. Punto 2");
            System.out.println("2. Punto 3");
            System.out.println("0. Salir");
            System.out.println("Ingrese una opcion: ");
            opcion = sc.nextInt();
            switch(opcion){
                case 1:
                    Tabla t = new Tabla();
                    t.setVisible(true);
                    break;
                case 2:
                    Controlador c = new Controlador();
                    c.iniciar();
                    break;
                case 0:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opcion invalida");
                    break;
            }
        }while(opcion != 0);
    }

}
