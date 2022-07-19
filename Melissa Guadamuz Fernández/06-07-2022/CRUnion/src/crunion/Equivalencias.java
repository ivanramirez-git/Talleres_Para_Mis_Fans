package crunion;

public class Equivalencias {
    private final int max = 25; // Maxima cantidad de monedas
    /*
     * Dólar Estado Unidense
     * Euros
     * Colones
     * Pesos Mexicanos
     * Córdobas Oro
     * Pesos Argentinos
     * Libras Esterlina
     * Yen
     */
    private String[] Descripciones_monedas;
    /*
     * 1 1
     * 0.85 0.91
     * 660 670
     * 20 20.5
     * 33 36
     * 110 112.5
     * 0.70 0.76
     * 119 122.5
     */
    private float[][] Tabla_conversiones;
    private int num_monedas;

    Equivalencias() {
        num_monedas = 8;
        Descripciones_monedas = new String[num_monedas];
        Tabla_conversiones = new float[num_monedas][2];
        // Inicializar las descripciones de las monedas
        Descripciones_monedas[0] = "Dólar Estado Unidense";
        Descripciones_monedas[1] = "Euro";
        Descripciones_monedas[2] = "Colones";
        Descripciones_monedas[3] = "Pesos Mexicanos";
        Descripciones_monedas[4] = "Córdobas Oro";
        Descripciones_monedas[5] = "Pesos Argentinos";
        Descripciones_monedas[6] = "Libras Esterlina";
        Descripciones_monedas[7] = "Yen";

        // Inicializar las tablas de conversiones
        Tabla_conversiones[0][0] = 1f;
        Tabla_conversiones[0][1] = 1f;
        Tabla_conversiones[1][0] = 0.85f;
        Tabla_conversiones[1][1] = 0.91f;
        Tabla_conversiones[2][0] = 660f;
        Tabla_conversiones[2][1] = 670f;
        Tabla_conversiones[3][0] = 20f;
        Tabla_conversiones[3][1] = 20.5f;
        Tabla_conversiones[4][0] = 33f;
        Tabla_conversiones[4][1] = 36f;
        Tabla_conversiones[5][0] = 110f;
        Tabla_conversiones[5][1] = 112.5f;
        Tabla_conversiones[6][0] = 0.70f;
        Tabla_conversiones[6][1] = 0.76f;
        Tabla_conversiones[7][0] = 119f;
        Tabla_conversiones[7][1] = 122.5f;
    }

    Equivalencias(int num_monedas) {
        Descripciones_monedas = new String[num_monedas];
        Tabla_conversiones = new float[num_monedas][2];
        // Inicializar las descripciones de las monedas
        if (!(num_monedas > 0 && num_monedas <= max)) {
            // Error de entrada de datos
            System.out.println("Error de entrada de datos");
            return;
        }
        this.num_monedas = num_monedas;

        if (num_monedas > 0)
            Descripciones_monedas[0] = "Dólar Estado Unidense";
        if (num_monedas > 1)
            Descripciones_monedas[1] = "Euro";
        if (num_monedas > 2)
            Descripciones_monedas[2] = "Colones";
        if (num_monedas > 3)
            Descripciones_monedas[3] = "Pesos Mexicanos";
        if (num_monedas > 4)
            Descripciones_monedas[4] = "Córdobas Oro";
        if (num_monedas > 5)
            Descripciones_monedas[5] = "Pesos Argentinos";
        if (num_monedas > 6)
            Descripciones_monedas[6] = "Libras Esterlina";
        if (num_monedas > 7)
            Descripciones_monedas[7] = "Yen";
        if (num_monedas > 8)
            for (int i = 8; i < num_monedas; i++)
                Descripciones_monedas[i] = "Moneda " + (i + 1);

        // Inicializar las tablas de conversiones
        if (num_monedas > 0) {
            Tabla_conversiones[0][0] = 1f;
            Tabla_conversiones[0][1] = 1f;
        }
        if (num_monedas > 1) {
            Tabla_conversiones[1][0] = 0.85f;
            Tabla_conversiones[1][1] = 0.91f;
        }
        if (num_monedas > 2) {
            Tabla_conversiones[2][0] = 660f;
            Tabla_conversiones[2][1] = 670f;
        }
        if (num_monedas > 3) {
            Tabla_conversiones[3][0] = 20f;
            Tabla_conversiones[3][1] = 20.5f;
        }
        if (num_monedas > 4) {
            Tabla_conversiones[4][0] = 33f;
            Tabla_conversiones[4][1] = 36f;
        }
        if (num_monedas > 5) {
            Tabla_conversiones[5][0] = 110f;
            Tabla_conversiones[5][1] = 112.5f;
        }
        if (num_monedas > 6) {
            Tabla_conversiones[6][0] = 0.70f;
            Tabla_conversiones[6][1] = 0.76f;
        }
        if (num_monedas > 7) {
            Tabla_conversiones[7][0] = 119f;
            Tabla_conversiones[7][1] = 122.5f;
        }
        if (num_monedas > 8)
            for (int i = 8; i < num_monedas; i++) {
                Tabla_conversiones[i][0] = (float) (Math.random() * 100);
                Tabla_conversiones[i][1] = Tabla_conversiones[i][1] + (float) (Math.random() * 10);
            }
    }

    // Funciones

    // PrecioCompra(moneda_origen): recibe el tipo de moneda origen (por ejemplo
    // Euros) y
    // devuelve el valor del precio de compra según la tabla Tabla_conversiones
    public float PrecioCompra(int moneda_origen) {
        return Tabla_conversiones[moneda_origen][0];
    }

    // PrecioVenta(moneda_origen): recibe el tipo de moneda origen (por ejemplo
    // Euros) y devuelve el
    // valor del precio de venta según la tabla Tabla_conversiones
    public float PrecioVenta(int moneda_origen) {
        return Tabla_conversiones[moneda_origen][1];
    }

    // PosicionMoneda(moneda_origen): recibe el tipo de moneda origen y devuelve la
    // fila en la que
    // se encuentra la misma, esto para poder conocer la fila donde se encuentra el
    // valor de compra y
    // venta de la moneda en la tabla Tabla_conversiones.
    public int PosicionMoneda(String moneda_origen) {
        int pos = -1;
        for (int i = 0; i < max; i++) {
            if (Descripciones_monedas[i].equals(moneda_origen)) {
                pos = i;
                break;
            }
        }
        return pos;
    }

    public int getNum_monedas() {
        return num_monedas;
    }

    public String[] getMonedas() {
        return Descripciones_monedas;
    }
}
