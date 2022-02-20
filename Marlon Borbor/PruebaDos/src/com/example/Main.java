package com.example;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner sc = new Scanner(System.in);
        String s[] = {"Mazda","Toyota","Nissan","Kia    "};
        float precios[] = {15000,20000,25000,30000};
        int tabla[][] = new int[4][2];
        // Pedir codigo de Auto y Cantidad vendida
        int salir = -1;
        while(salir != 0){
            // Menu
            System.out.println("1. "+ s[0] + ": $ " + precios[0]);
            System.out.println("2. "+ s[1] + ": $ " + precios[1]);
            System.out.println("3. "+ s[2] + ": $ " + precios[2]);
            System.out.println("4. "+ s[3] + ": $ " + precios[3]);
            System.out.println("0. Salir");

            System.out.println("Ingrese codigo de auto: ");
            int codigo = Integer.parseInt(sc.nextLine());
            int cantidad = 0;
            if(codigo == 0){
                salir = 0;
            } else {
                System.out.println("Ingrese cantidad vendida: ");
                cantidad = Integer.parseInt(sc.nextLine());
            }

            switch(codigo){
                case 1:
                    tabla[0][0] = codigo;
                    tabla[0][1] = cantidad;
                    break;
                case 2:
                    tabla[1][0] = codigo;
                    tabla[1][1] = cantidad;
                    break;
                case 3:
                    tabla[2][0] = codigo;
                    tabla[2][1] = cantidad;
                    break;
                case 4:
                    tabla[3][0] = codigo;
                    tabla[3][1] = cantidad;
                    break;
                case 0:
                    salir = 0;
                    break;
                default:
                    System.out.println("Codigo no valido");
                    break;
            }
            // Limpiar pantalla
            System.out.print("\033[H\033[2J");

            // Mostrar tabla, Automovil, Cantidad, Total
            System.out.println("Automovil\tCantidad\tTotal");
            for(int i = 0; i < 4; i++){
                System.out.println(s[i]+"\t\t"+tabla[i][1]+"\t\t\t"+precios[i]*tabla[i][1]);
            }
        }
    }
}
