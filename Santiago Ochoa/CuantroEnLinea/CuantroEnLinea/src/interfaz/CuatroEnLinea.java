/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfaz;

import java.util.Scanner;
import juego.Tablero;

/**
 *
 * @author USUARIO
 */
public class CuatroEnLinea {
    
    private Tablero tablero;
    private int turno;
    
    public CuatroEnLinea(){
        tablero = new Tablero();
        turno=0;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {        
        CuatroEnLinea cel = new CuatroEnLinea();
        
        Scanner in = new Scanner (System.in);
        
        int columna;
        String jugador;
        String ganador;
        
        System.out.println("Bienvenido al juego 4 en Linea");
        System.out.println(cel.tablero.mostrarTablero());
        while(cel.turno < 42){
            if(cel.turno%2==0)
                jugador="X";
            else
                jugador="O";
            System.out.print("JUGADOR " + jugador + ". Ingrese su jugada [1-7]: ");
            columna = in.nextInt();            
            if(columna>=1 && columna<=7 && cel.tablero.getContadores(columna-1)<6){
                cel.tablero.setMatriz(columna-1, jugador);
                cel.turno++;
                System.out.println("\n" + cel.tablero.mostrarTablero());
                ganador = cel.tablero.horizontal();
                if(!ganador.equals("-")){
                    System.out.println("GANADOR JUGADOR " + ganador);
                    return;
                }
                else{
                    ganador = cel.tablero.vertical();
                    if(!ganador.equals("-")){
                        System.out.println("GANADOR JUGADOR " + ganador);
                        return;
                    }
                    else{
                        ganador = cel.tablero.diagonal1();
                        if(!ganador.equals("-")){
                            System.out.println("GANADOR JUGADOR " + ganador);
                            return;
                        }
                        else{
                            ganador = cel.tablero.diagonal2();
                            if(!ganador.equals("-")){
                                System.out.println("GANADOR JUGADOR " + ganador);
                                return;
                            }
                        }                        
                    }
                }                                        
            }
            else
                System.out.println("ERROR. Jugada no válida, ¡verifique el número de la columna seleccionada y que dicha columna tenga espacio!");        
        }
        System.out.println("¡EMPATE!");
    }    
}
