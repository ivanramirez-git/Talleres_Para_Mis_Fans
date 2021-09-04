/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package juego;

/**
 *
 * @author USUARIO
 */
public class Tablero {
    private String matriz [][];
    private int contadores[];
    
    public Tablero(){
        matriz = new String [6][7];
        contadores = new int [7];
        inicializarMatriz();
    }
    
    /*
    public String[][] getMatriz(){
        return matriz;
    }
    */
    
    private void inicializarMatriz(){
        for(int i=0; i<matriz.length; i++){
            for(int j=0; j<matriz[i].length; j++)
                matriz[i][j] = "-";
        }
    }
    
    
    public void setMatriz(int columna, String jugador){
        if(columna>=0 && columna<matriz[0].length )
            if(contadores[columna]<matriz.length){
                matriz[matriz.length-contadores[columna]-1][columna]=jugador;
                contadores[columna]++;
            } 
    }
    
    public int getContadores(int columna){
        if (columna>=0 && columna<matriz[0].length)
            return contadores[columna];
        return -1;
    }
    
    public String mostrarTablero(){
        String salida = "1\t2\t3\t4\t5\t6\t7\n";
        for(int i=0; i<matriz.length; i++){
            for(int j=0; j<matriz[i].length; j++)
                salida += matriz[i][j] + "\t";
            salida += "\n";
        }
        return salida;
    }
    
    public String horizontal(){
        int conteo=0;
        for(int i=matriz.length-1; i>=0; i--){
            for(int j=0; j<=3; j++){
                if(!matriz[i][j].equals("-")){
                    conteo++;
                    for(int k=1; k<=3; k++)
                        if(matriz[i][j].equals(matriz[i][j+k]))
                            conteo++;
                        else{
                            conteo=0;
                            break;
                        }
                    if(conteo == 4)
                        return matriz[i][j];                            
                }
                else{
                    conteo=0;                    
                }                
            }
        }
        return "-";
    }
    
    public String vertical(){
        String columna[] = new String[6];
        for(int j=0;j<matriz[0].length;j++){
            for(int i=0; i<matriz.length ;i++){
                columna[i]=matriz[i][j];
            }
            if(!chequearVector(columna).equals("-"))
                return chequearVector(columna);
        }
        return "-";
    }

    public String diagonal1(){
        String[] diag = new String[6];
        cerosVector(diag);
        int filaInicial = 6 - 3;
        int columnaInicial = 0;
        int fils = filaInicial;
        int cols = columnaInicial;
        int aux = 0;
        while (columnaInicial < 7 - 3) {
            diag[aux] = matriz[cols][fils];
            aux++;
            fils++;
            cols++;
            if (fils > 6 - 1 || cols > 7 - 1) {
                System.out.println("Fila: "+fils+" Cols: "+cols);
                if (!chequearVector(diag).equals("-")) {
                    return chequearVector(diag);
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
        return "-";
    }
    
    public String diagonal2(){
        
        return "-";
    }
    
    private void cerosVector(String[] vector) {
        for (int it = 0; it < vector.length; it++) //Resetea vector llenandolo de ceros para la siguiente busqueda
        {
            vector[it] = "-";
        }
    }
    
    public String chequearVector(String[] linea) { //Función que comprueba si en un vector hay 4 numeros iguales consecutivos
        String ganador="-";
        int contador = 0;
        if (!linea[0].equals(ganador)) {
            contador = 1;
        }
        for (int it = 1; it < linea.length; it++) {
            if (!linea[it].equals(ganador) && linea[it].equals(linea[it - 1])) {
                contador++;
                if (contador == 4) {
                    ganador = linea[it];
                    return ganador;
                }
            } else if (!linea[it].equals(ganador)) {
                contador = 1;
            } else {
                contador = 0;
            }
        }
        return ganador;
    }
}
