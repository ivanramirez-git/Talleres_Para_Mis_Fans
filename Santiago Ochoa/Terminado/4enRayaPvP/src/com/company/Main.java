package com.company;

import java.util.Scanner;
import java.util.Vector;

public class Main {

    public static void main(String[] args) {
	// write your code here
        boolean salir=false;
        Vector<Juego> partidas = new Vector<>();
        System.out.println(".:: BIENVENIDOS ::.");
        do{

            switch (menu()){
                case 1:
                    System.out.println("Nuevo juego. ");

                    Juego partida = new Juego();
                    partidas.add(partida);
                    partida=null;

                    break;
                case 0:
                    System.out.println("Caso 0");
                    salir=true;
                    break;
                default:
                    System.out.println("Defecto");
                    break;
            }

        }while(!salir);
    }

    private static int menu() {
        Scanner sc = new Scanner(System.in);

        System.out.println("\n1. Iniciar nueva partida. ");
        System.out.println("0. Salir");

        return Integer.parseInt(sc.nextLine());
    }
}
