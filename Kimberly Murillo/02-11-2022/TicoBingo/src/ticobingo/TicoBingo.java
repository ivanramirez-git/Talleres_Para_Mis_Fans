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
        int numero;
        Home frame = new Home();
        // Ciclo para enviar numeros a el estado

        List<Tablero> tableros = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            tableros.add(new Tablero(i, estado));
            tableros.get(i).getPanel().setBounds(10, (i+1) * 105 + 10, 400, 100);
            // frame.add(tableros.get(i).getPanel());
            System.out.println("Tablero " + i + " agregado");
        }

        frame.setVisible(true);
        do {
            // imprimir estado
            System.out.println(estado);
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            System.out.print("Ingrese un numero: ");
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
            // esperar 1 segundo
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } while (true);

        System.exit(0);
    }

}
