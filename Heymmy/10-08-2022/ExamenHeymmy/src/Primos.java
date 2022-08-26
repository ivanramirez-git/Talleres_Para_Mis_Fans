public class Primos {
    // Funcion que dice si un numero es primo o no
    public static boolean esPrimo(int numero) {
        boolean esPrimo = true;
        for (int i = 2; i < numero; i++) {
            if (numero % i == 0) {
                esPrimo = false;
                break;
            }
        }
        return esPrimo;
    }

    // Funcion que dado un rango de numeros devuelve un array con los primos
    public static int[] primos(int inicio, int fin) {
        int contador = 0;
        for (int i = inicio; i <= fin; i++) {
            if (esPrimo(i)) {
                contador++;
            }
        }
        int[] primos = new int[contador];
        contador = 0;
        for (int i = inicio; i <= fin; i++) {
            if (esPrimo(i)) {
                primos[contador] = i;
                contador++;
            }
        }
        return primos;
    }


}
