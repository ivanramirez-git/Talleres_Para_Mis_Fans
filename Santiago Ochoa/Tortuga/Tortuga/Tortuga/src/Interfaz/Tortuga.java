/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Interfaz;
import java.util.Scanner;
import Juego.Tablero;

/**
 *
 * @author HP
 */
public class Tortuga {
    
 private Tablero Tablero;
    private int Tortuga;
   Scanner sc = new Scanner(System.in);

    public Tortuga(){
        Tablero = new Tablero();
        Tortuga=0;
    }
    /**
     * @param args the command line arguments
     */
   public static void main(String[] args) {
       Tortuga ttOO= new Tortuga();
       int llamarInstrucciones;
        //Llenar instrucciones
        while(true){
        
        System.out.println("\n*********************************************************************\n"
                           + "* Finalizo los comandos, ¿desea continuar con su dibujo?, cualquier *\n"
                           + "*      cosa que no sea NO se asumira como que desea continuar       *\n"
                           + "*********************************************************************");
        //ttOO.sc.nextLine();
        String again = ttOO.sc.nextLine();
        if(again.equalsIgnoreCase("no"))
            break;
        ttOO.getTablero().llenarInstrucciones();
        }
        
    }

    public Tablero getTablero() {
        return Tablero;
    }

    public void setTablero(Tablero Tablero) {
        this.Tablero = Tablero;
    }

    public int getTortuga() {
        return Tortuga;
    }

    public void setTortuga(int Tortuga) {
        this.Tortuga = Tortuga;
    }
   
 }
