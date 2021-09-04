
package com.company;

public class Tablero {

    private int columnas;
    private int filas;
    private int[][] matriz;
    private int ganador;

    public Tablero(int cols, int fils) { // Constructor
        this.columnas = cols;
        this.filas = fils;
        this.matriz = new int[cols][fils];
    }

    public int getColumnas() {
        return columnas;
    }


    public int getFilas() {
        return filas;
    }

    public void imprimirTablero() { //Pinta el estado actual del tablero
        for (int fils = filas - 1; fils >= 0; fils--) {
            System.out.println();
            for (int col = 0; col < columnas; col++) {
                if (matriz[col][fils] == 1) {
                    System.out.print("X ");
                } else if (matriz[col][fils] == 2) {
                    System.out.print("O ");
                } else {
                    System.out.print("- ");
                }
            }
        }
        System.out.println();
    }

    public boolean marcarIntento(int cols, int turnoJugador) {
        for (int fils = 0; fils < filas; fils++) { //Mira si hay sitio en la columna elegida
            if (matriz[cols][fils] == 0) {
                matriz[cols][fils] = turnoJugador; //Se asigna a la posicion de la tirada, el número del jugador que ha tirado

                if (turnoJugador == 1) {
                    turnoJugador = 2;
                } else if (turnoJugador == 2) {
                    turnoJugador = 1;
                }
                return true;
            }
        }
        return false;
    }

    public int chequearTablero() { //Comprueba si ha habido ganador
        boolean encontrarGanador = vertical();
        if (!encontrarGanador) {
            encontrarGanador = horizontal();
        }
        if (!encontrarGanador) {
            encontrarGanador = diagonalDerecha();
        }
        if (!encontrarGanador) {
            diagonalIzquierda();
        }
        return ganador;
    }

    private boolean vertical() {
        for (int col = 0; col < columnas; col++) {
            if (chequearVector(matriz[col])) {
                return true;
            }
        }
        return false;
    }

    private boolean horizontal() {
        int[] cols = new int[columnas];
        for (int fils = 0; fils < filas; fils++) {
            for (int col = 0; col < columnas; col++) {
                cols[col] = matriz[col][fils];
            }
            if (chequearVector(cols)) {
                return true;
            }

            cerosVector(cols);
        }
        return false;
    }

    private boolean diagonalDerecha() { //La comprobación se hace en forma de L
        //comenzando desde una esquina y recorriendo todas las columnas
        //Y luego recorriendo todas las filas
        int[] diag = new int[Math.min(columnas, filas)]; //la diagonal máxima es el max entre columnas y filas
        int filaInicial = 3; // Se inicia en la 3ra fila ya que las primeras 3( 0,1,2 ) no vale la pena revisarlas
        int columnaInicial = 0;
        int fils = filaInicial;
        int cols = columnaInicial;
        int aux = 0;
        while (columnaInicial < columnas - 3) {
            diag[aux] = matriz[cols][fils];
            aux++;
            fils--;
            cols++;
            if (fils < 0 || cols > columnas - 1) {
                if (chequearVector(diag)) { // envia el pequeño vector con los datos de la diagonal a ver si tiene 4 casillas iguales consecutivas
                    return true;
                }
                if (filaInicial < filas - 1) {
                    filaInicial++;
                } else {
                    columnaInicial++;
                }
                fils = filaInicial;
                cols = columnaInicial;

                cerosVector(diag);
                aux = 0;
            }
        }
        return false;
    }

    private boolean diagonalIzquierda() {
        int[] diag = new int[Math.min(columnas, filas)];
        int filaInicial = filas - 3;
        int columnaInicial = 0;
        int fils = filaInicial;
        int cols = columnaInicial;
        int aux = 0;
        while (columnaInicial < columnas - 3) {
            diag[aux] = matriz[cols][fils];
            aux++;
            fils++;
            cols++;
            if (fils > filas - 1 || cols > columnas - 1) {
                if (chequearVector(diag)) {
                    return true;
                }

                if (filaInicial > 0) {
                    filaInicial--;
                } else {
                    columnaInicial++;
                }
                fils = filaInicial;
                cols = columnaInicial;

                cerosVector(diag);
                aux = 0;
            }
        }
        return false;
    }

    public boolean chequearVector(int[] linea) { //Función que comprueba si en un vector hay 4 numeros iguales consecutivos
        int contador = 0;
        if (linea[0] != 0) {
            contador = 1;
        }
        for (int it = 1; it < linea.length; it++) {
            if (linea[it] != 0 && linea[it] == linea[it - 1]) {
                contador++;
                if (contador == 4) {
                    ganador = linea[it];
                    return true;
                }
            } else if (linea[it] != 0) {
                contador = 1;
            } else {
                contador = 0;
            }
        }
        return false;
    }

    private void cerosVector(int[] vector) {
        for (int it = 0; it < vector.length; it++) //Resetea vector llenandolo de ceros para la siguiente busqueda
        {
            vector[it] = 0;
        }
    }

}