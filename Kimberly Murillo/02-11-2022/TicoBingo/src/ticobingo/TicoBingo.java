/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ticobingo;

import java.util.ArrayList;
import java.util.List;

import javax.swing.JFrame;

import modelo.Tablero;
import vista.Home;

/**
 *
 * @author nitro5
 */
public class TicoBingo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Estado global
        Estado estado = new Estado();
        Home frame = new Home(estado);
        // Ciclo para enviar numeros a el estado

        // List<Tablero> tableros = new ArrayList<>();
        // for (int i = 0; i < 10; i++) {
        // tableros.add(new Tablero(i, estado));
        // tableros.get(i).getPanel().setBounds(10, (i+1) * 105 + 10, 400, 100);
        // // frame.add(tableros.get(i).getPanel());
        // System.out.println("Tablero " + i + " agregado");
        // }

        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

}
