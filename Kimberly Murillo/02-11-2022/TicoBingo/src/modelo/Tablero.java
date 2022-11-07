package modelo;

import java.io.Serializable;
// aleatorio
import java.util.Random;

import javax.swing.JPanel;
import javax.swing.JTable;

import ticobingo.Estado;

// serializable, hilo
public class Tablero extends Thread implements Serializable {

    private int[][] tablero;
    private int[] numeros;
    private int id;
    private Estado estado;

    public JPanel getPanel() {
        JTable tabla = new JTable();
        tabla.setModel(new javax.swing.table.DefaultTableModel(
                new Object[][] {
                        { tablero[0][0], tablero[0][1], tablero[0][2], tablero[0][3], tablero[0][4] },
                        { tablero[1][0], tablero[1][1], tablero[1][2], tablero[1][3], tablero[1][4] },
                        { tablero[2][0], tablero[2][1], tablero[2][2], tablero[2][3], tablero[2][4] },
                        { tablero[3][0], tablero[3][1], tablero[3][2], tablero[3][3], tablero[3][4] },
                        { tablero[4][0], tablero[4][1], tablero[4][2], tablero[4][3], tablero[4][4] }
                },
                new String[] {
                        "B", "I", "N", "G", "O"
                }));
        // imprimir lista de numeros
        System.out.print("[");
        for (int i = 0; i < numeros.length - 1; i++) {
            System.out.print(numeros[i] + ", ");
        }
        System.out.println(numeros[numeros.length - 1] + "]");

        // si un numero esta en la lista de numeros, cambiarlo a rojo
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < numeros.length; k++) {
                    if (tablero[i][j] == numeros[k]) {
                        tabla.setValueAt("<html><font color='red'>" + tablero[i][j] + "</font></html>", i, j);
                    }
                }
            }
        }

        JPanel panel = new JPanel();
        panel.add(tabla);
        panel.setVisible(true);

        return panel;
    }

    public Tablero(int id, Estado estado) {
        tablero = new int[5][5];
        numeros = new int[25];
        this.id = id;
        this.estado = estado;
        generarTableroAleatorio();
    }

    // Metodo privado para generar un numero aleatorio
    private int generarNumeroAleatorio(int minimo, int maximo) {
        Random random = new Random();
        return random.nextInt(maximo - minimo + 1) + minimo;
    }

    // Metodo privado para generar un tablero aleatorio
    private void generarTableroAleatorio() {
        /*
         * o En la primera columna solo se pueden asignar números del 1 al 15.
         * o En la segunda, números del 16 al 30.
         * o En la tercera, números del 31 al 45.
         * o En la cuarta, números del 46 al 60.
         * o En la quinta, números del 61 al 75.
         * Nota: Un número X solo puede aparecer una única vez en cada cartón y la
         * casilla
         * central debe quedar vacía
         */
        int numero;
        int columna;
        int fila;
        int[] numeros = new int[25];
        // Genera los numeros aleatorios
        for (int i = 0; i < 25; i++) {
            // Genera un numero aleatorio
            numero = generarNumeroAleatorio(1, 75);
            // Verifica que el numero no este repetido
            while (estaRepetido(numero)) {
                numero = generarNumeroAleatorio(1, 75);
            }
            // Agrega el numero al arreglo
            numeros[i] = numero;
        }
        // Asigna los numeros al tablero
        for (int i = 0; i < 25; i++) {
            // Obtiene el numero
            numero = numeros[i];
            // Obtiene la columna
            columna = i % 5;
            // Obtiene la fila
            fila = i / 5;
            // Asigna el numero al tablero
            tablero[fila][columna] = numero;
        }

        // Asigna los numeros a las columnas
        for (int i = 0; i < 5; i++) {
            // Obtiene la columna
            columna = i;
            // Obtiene el numero minimo
            int minimo = (columna * 15) + 1;
            // Obtiene el numero maximo
            int maximo = minimo + 14;
            // Asigna los numeros a la columna
            for (int j = 0; j < 5; j++) {
                // Obtiene el numero
                numero = tablero[j][columna];
                // Verifica que el numero este en el rango
                if (numero < minimo || numero > maximo) {
                    // Genera un numero aleatorio
                    numero = generarNumeroAleatorio(minimo, maximo);
                    // Verifica que el numero no este repetido
                    while (estaRepetido(numero)) {
                        numero = generarNumeroAleatorio(minimo, maximo);
                    }
                    // Asigna el numero al tablero
                    tablero[j][columna] = numero;
                }
            }
        }

        // Asigna el numero 0 a la casilla central
        tablero[2][2] = 0;
        this.imprimirTablero();
    }

    // Metodo privado para verificar si un numero esta repetido en el tablero
    private boolean estaRepetido(int numero) {
        // Recorre el arreglo de numeros
        for (int i = 0; i < 5; i++) {
            // Recorre el arreglo de numeros
            for (int j = 0; j < 5; j++) {
                // Verifica si el numero esta repetido
                if (tablero[i][j] == numero) {
                    return true;
                }
            }
        }
        return false;
    }

    // Metodo para obtener el tablero
    public int[][] getTablero() {
        return tablero;
    }

    // Metodo para imprimir el tablero en consola, con titulo y con separadores
    private void imprimirTablero() {

        System.out.println("|---------------------------------------------------------------------------------|");
        if (id > 9) {
            System.out.println("|B\t\tI\t\tN\t\tG\t\tO\t\t" + id + "|");
        } else {
            System.out.println("|B\t\tI\t\tN\t\tG\t\tO\t\t" + id + " |");
        }
        System.out.println("|---------------------------------------------------------------------------------|");

        for (int i = 0; i < 5; i++) {
            System.out.println("| \t\t\t\t\t\t\t\t\t\t  |");
            System.out.print("|\t");
            for (int j = 0; j < 5; j++) {
                System.out.print(tablero[i][j] + "\t");
                if (j == 4) {
                    System.out.println("  |");
                } else {
                    System.out.print("|\t");
                }
            }
            System.out.println("| \t\t\t\t\t\t\t\t\t\t  |");
            if (i != 4) {
                System.out
                        .println("|---------------------------------------------------------------------------------|");
            }

        }
        System.out.println("|---------------------------------------------------------------------------------|");
    }
}