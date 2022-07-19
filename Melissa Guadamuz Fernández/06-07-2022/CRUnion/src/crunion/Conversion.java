package crunion;

public class Conversion {
    private final Equivalencias equivalencias;

    public Conversion() {
        equivalencias = new Equivalencias();
    }

    public Conversion(int num_monedas) {
        equivalencias = new Equivalencias(num_monedas);
    }

    // Funciones

    // VentaDolares: función que recibe como parámetros moneda_origen y el monto de dinero a 
    // recibir, devuelve la cantidad de dólares que el banco va a entregar al cliente
    public float VentaDolares(String moneda_origen, float monto_dolares) {
        return monto_dolares / equivalencias.PrecioVenta(equivalencias.PosicionMoneda(moneda_origen));
    }
    
    // CompraDolares: función que recibe como parámetros moneda_destino y el monto de dólares a 
    // comprar, devuelve el mondo de dinero a entregar al cliente
    public float CompraDolares(String moneda_destino, float monto_dolares) {
        return equivalencias.PrecioCompra(equivalencias.PosicionMoneda(moneda_destino)) * monto_dolares;
    }

    // Conversion_moneda: función que recibe como parámetros la moneda_origen, la 
    // moneda_destino y el monto de dinero inicial. Su objetivo es tomar el monto de dinero que viene 
    // en la moneda origen y devolver el monto correspondiente en la moneda destino.
    public float Conversion_moneda(String moneda_origen, String moneda_destino, float monto_dinero) {
        return VentaDolares(moneda_origen, CompraDolares(moneda_destino, monto_dinero));
    }

    public Equivalencias getEquivalencias() {
        return equivalencias;
    }
}
