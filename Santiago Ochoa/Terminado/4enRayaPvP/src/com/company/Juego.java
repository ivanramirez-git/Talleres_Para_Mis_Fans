package com.company;

import java.util.Scanner;

public class Juego {

    private String jugador1;
    private String jugador2;
    private char tabla[][]={
        {'_','_','_','_','_','_','_'},
        {'_','_','_','_','_','_','_'},
        {'_','_','_','_','_','_','_'},
        {'_','_','_','_','_','_','_'},
        {'_','_','_','_','_','_','_'},
        {'_','_','_','_','_','_','_'}
    };
    private String texto;
    private int num1, num2;
    private  boolean booleano;
    Scanner sc = new Scanner(System.in);

    Juego(){

        System.out.print("Ingrese el nombre del primer jugador: ");
        jugador1 = sc.nextLine();

        System.out.print("Ingrese el nombre del segundo jugador: ");
        jugador2 = sc.nextLine();

        for(int i=0; i<46;i++){
            siguienteTurno(i);
           // i=revisarTabla(i); // Si hay ganador i = 46 y muere el ciclo
        }
        imprimirJuego();
      //  revisarJuego();

    }

/*
        private int revisarTabla(int i) {

            revisarColumnas();
            revisarFilas();
            revisarDiagonales();
            return i;
        }

 */
/*
    private void revisarColumnas() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0, k = 0; j < 7; j++) {
                if
            }
        }
    }
*/
    private void siguienteTurno(int i) {
        if(i%2 == 0){
            imprimirTabla();
            System.out.println("Es turno "+ ((i/2)+1) + " de " + jugador1+" con la X");
            while (coordenadasAnumero());
            tabla[num1][num2]='X';

        }else {
            imprimirTabla();
            System.out.println("Es turno "+ ((i/2)+1) + " de " + jugador2+" con la O");
            while (coordenadasAnumero());
            tabla[num1][num2]='O';
        }
    }
    private boolean coordenadasAnumero() {


        System.out.print("Ingrese las coordenadas: ");
        texto = sc.nextLine();

        switch (texto.charAt(0)){

            case 'a':
                num2=0;
                break;
            case 'b':
                num2=1;
                break;
            case 'c':
                num2=2;
                break;
            case 'd':
                num2=3;
                break;
            case 'e':
                num2=4;
                break;
            case 'f':
                num2=5;
                break;
            case 'g':
                num2=6;
                break;
            default:
                System.out.println("Ingrese una coordenada correcta");
                    return true;
        }
        num1 = Character.getNumericValue(texto.charAt(1))-1;
        if(0 <= num1 && num1 <= 5 ){
            if(tabla[num1][num2]=='_') {
                return false;
            }else {
                System.out.println("La casilla ya esta marcada. ");
            }
        }
        System.out.println("Ingrese una coordenada correcta.");
        return true;

    }
    public void imprimirJuego(){
        System.out.println("Jugador 1: "+jugador1+"   Jugador 2: "+jugador2);
        System.out.println("         X               O");

        imprimirTabla();
    }
    public void imprimirTabla(){
        for(int i = 0; i < 6; i++) {
            if (i==0){
                System.out.println("   a b c d e f g");
            }
            System.out.print(i+1 + "| ");
            for (int j = 0; j < 7; j++) {
                System.out.print(tabla[i][j]+" ");
            }
            System.out.println("|");
        }
    }
}
