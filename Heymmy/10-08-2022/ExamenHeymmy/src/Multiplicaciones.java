public class Multiplicaciones {
    // Funcion que recibe un n y retorna una matriz con las tablas de multiplicar
    // del 1 al n, cada fila es una tabla de multiplicar de 1 a 12
    public static int[][] tablas(int n) {
        int[][] tablas = new int[n][12];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 12; j++) {
                tablas[i][j] = (i + 1) * (j + 1);
            }
        }
        return tablas;
    }
}
