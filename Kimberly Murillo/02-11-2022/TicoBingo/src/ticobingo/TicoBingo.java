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

        JFrame frame = new JFrame();
        // Lista de 10 tableros
        List<Tablero> tableros = new ArrayList<>();
        // Inicializar la lista de tableros
        for (int i = 0; i < 1; i++) {
            tableros.add(new Tablero(i + 5, estado));
            // mostrar los jpanels
            frame.add(tableros.get(i).getPanel());
            frame.pack();
            frame.setVisible(true);
        }
        // Ciclo para enviar numeros a el estado
        int numero;
        do {
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            System.out.println("Ingrese un numero: ");
            try {
                numero = scanner.nextInt();
                if (numero > 0 && numero < 76) {
                    estado.set("currentNumber", numero);
                } else {
                    // cerrar scanner
                    scanner.close();
                    break;
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
            // imprimir estado
            System.out.println(estado);
        } while (true);

        System.exit(0);
    }

}
