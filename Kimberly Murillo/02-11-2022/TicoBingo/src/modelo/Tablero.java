package modelo;

import java.io.Serializable;
import java.util.ArrayList;
// aleatorio
import java.util.Random;

import javax.swing.JPanel;
import javax.swing.JTable;

import ticobingo.Estado;

// serializable, hilo
public class Tablero extends Thread implements Serializable {

    private int[][] tablero;
    private int[] numeros;
    private int indexNumeros;
    private int id;
    private Estado estado;
    private JPanel panel;
    JTable tabla;

    // Si este tablero es ganador, agregar a la lista de ganadores del estado el id
    // de este tablero
    public void verificarGanador() {

        // Un jugador puede ganar llenando cualquier fila, columna, diagonales o cuatro
        // esquinas solamente, los numeros que se encuentran en el centro no cuentan
        // los numeros que han salido estan en la lista de numeros
        boolean ganador = false;
        // verificar filas
        for (int i = 0; i < 5; i++) {
            boolean[] numerosEncontradosFila = new boolean[5];
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < indexNumeros; k++) {
                    if (tablero[i][j] == numeros[k]) {
                        numerosEncontradosFila[j] = true;
                    }
                }
            }
            if (numerosEncontradosFila[0] && numerosEncontradosFila[1] && numerosEncontradosFila[2]
                    && numerosEncontradosFila[3] && numerosEncontradosFila[4]) {
                ganador = true;
                break;
            }
        }
        // verificar columnas
        if (!ganador) {

            for (int i = 0; i < 5; i++) {
                boolean[] numerosEncontradosColumna = new boolean[5];
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < indexNumeros; k++) {
                        if (tablero[j][i] == numeros[k]) {
                            numerosEncontradosColumna[j] = true;
                        }
                    }
                }
                if (numerosEncontradosColumna[0] && numerosEncontradosColumna[1] && numerosEncontradosColumna[2]
                        && numerosEncontradosColumna[3] && numerosEncontradosColumna[4]) {
                    ganador = true;
                    break;
                }
            }
        }
        // verificar diagonales
        if (!ganador) {
            boolean[] numerosEncontradosDiagonal1 = new boolean[5];
            boolean[] numerosEncontradosDiagonal2 = new boolean[5];
            for (int i = 0; i < 5; i++) {
                for (int k = 0; k < indexNumeros; k++) {
                    if (tablero[i][i] == numeros[k]) {
                        numerosEncontradosDiagonal1[i] = true;
                    }
                    if (tablero[i][4 - i] == numeros[k]) {
                        numerosEncontradosDiagonal2[i] = true;
                    }
                }
            }
            if (numerosEncontradosDiagonal1[0] && numerosEncontradosDiagonal1[1] && numerosEncontradosDiagonal1[2]
                    && numerosEncontradosDiagonal1[3] && numerosEncontradosDiagonal1[4]) {
                ganador = true;
            }
            if (numerosEncontradosDiagonal2[0] && numerosEncontradosDiagonal2[1] && numerosEncontradosDiagonal2[2]
                    && numerosEncontradosDiagonal2[3] && numerosEncontradosDiagonal2[4]) {
                ganador = true;
            }
        }
        // verificar esquinas
        if (!ganador) {
            boolean[] numerosEncontradosEsquinas = new boolean[4];
            for (int i = 0; i < 4; i++) {
                for (int k = 0; k < indexNumeros; k++) {
                    if (tablero[0][0] == numeros[k]) {
                        numerosEncontradosEsquinas[0] = true;
                    }
                    if (tablero[0][4] == numeros[k]) {
                        numerosEncontradosEsquinas[1] = true;
                    }
                    if (tablero[4][0] == numeros[k]) {
                        numerosEncontradosEsquinas[2] = true;
                    }
                    if (tablero[4][4] == numeros[k]) {
                        numerosEncontradosEsquinas[3] = true;
                    }
                }
            }
            if (numerosEncontradosEsquinas[0] && numerosEncontradosEsquinas[1] && numerosEncontradosEsquinas[2]
                    && numerosEncontradosEsquinas[3]) {
                ganador = true;
            }
        }

        if (ganador) {
            if (estado.get("ganadores") != null) {
                // Agregar a la lista de ganadores
                ArrayList<Integer> ganadores = (ArrayList<Integer>) estado.get("ganadores");
                // verificar que este tablero no este en la lista de ganadores
                if (!ganadores.contains(this.id)) {
                    ganadores.add(this.id);
                }
                estado.set("ganadores", ganadores);
            } else {
                // Crear la lista de ganadores
                ArrayList<Integer> ganadores = new ArrayList<Integer>();
                ganadores.add(id);
                estado.set("ganadores", ganadores);
            }
        }
    }

    public void refreshPanel() {
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
        // si un numero esta en la lista de numeros, cambiar el color de la celda a
        // rojo con bold
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < numeros.length; k++) {
                    if (tablero[i][j] == numeros[k]) {
                        // Cuadrado verde
                        tabla.setValueAt("<html><font color='red'><b>" + tablero[i][j] + "</b></font></html>", i, j);
                    }
                }
            }
        }
    }

    public JPanel getPanel() {
        return this.panel;
    }

    public Tablero(int id, Estado estado) {
        tablero = new int[5][5];
        numeros = new int[26];
        this.id = id;
        this.estado = estado;
        this.indexNumeros = 1;
        this.tabla = new JTable();
        this.panel = new JPanel();
        this.panel.add(tabla);
        this.panel.setVisible(true);
        generarTableroAleatorio();
        this.start();
    }

    @Override
    public void run() {
        // si en el estado el numero currentNumber es igual a un numero del tablero,
        // agregar a la lista de numeros
        while (true) {
            if (estado.get("currentNumber") != null) {
                int numero = (int) estado.get("currentNumber");
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        // validar que no este en la lista de numeros
                        if (tablero[i][j] == numero) {
                            boolean existe = false;
                            for (int k = 0; k < numeros.length; k++) {
                                if (numeros[k] == numero) {
                                    existe = true;
                                    break;
                                }
                            }
                            if (!existe) {
                                numeros[indexNumeros] = numero;
                                indexNumeros++;
                                // actualizar panel
                                refreshPanel();
                                // verificar si es ganador
                                verificarGanador();
                            }
                        }
                    }
                }
            }
            try {

                Thread.sleep(150);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
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
        // this.imprimirTablero();
        refreshPanel();
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