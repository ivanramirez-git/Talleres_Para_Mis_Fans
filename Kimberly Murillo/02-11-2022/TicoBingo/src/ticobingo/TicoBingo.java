/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ticobingo;

import java.util.ArrayList;
import java.util.List;

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
        // hilos
        HiloSeteador hiloSeteador = new HiloSeteador(estado);
        HiloSeteador hiloSeteador2 = new HiloSeteador(estado);
        hiloSeteador2.start();
        hiloSeteador.start();

        hiloSeteador.setState("nombre1", "Juan");
        hiloSeteador2.setState("apellido2", "Gomez");
        hiloSeteador2.setState("nombre2", "Maria");
        hiloSeteador.setState("apellido1", "Perez");
        hiloSeteador.setState("telefono1", 3123123);
        hiloSeteador2.setState("telefono2", 3123123);
        hiloSeteador2.setState("estdo1", true);
        hiloSeteador.setState("estdo2", false);
        hiloSeteador.setState("direcciones", new String[] { "calle 1", "calle 2", "calle 3" });

        // Esperar 10 segundos
        try {
            Thread.sleep(100);
        } catch (InterruptedException ex) {
            System.out.println("Error: " + ex.getMessage());
        }

        hiloSeteador.setState("nombre1", "Ivan");
        System.out.println(estado);

        // Lista de 10 tableros
        List<Tablero> tableros = new ArrayList<>();
        // Inicializar la lista de tableros
        for (int i = 0; i < 10; i++) {
            tableros.add(new Tablero(i + 5));
        }

        System.exit(0);
    }

}
