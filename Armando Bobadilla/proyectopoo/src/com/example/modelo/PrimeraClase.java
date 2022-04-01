package com.example.modelo;

import java.io.Serializable;

// PrimeraClase es una clase hija de Boleto, es serializable para poder guardarla en un fichero binario
public class PrimeraClase extends Boleto implements Serializable {
    // Atributos de la clase PrimeraClase
    private boolean dormitorio;
    private boolean ducha;
    private boolean bar;
    private String asiento;

    public PrimeraClase(String fechaVuelo, String destino, String origen, String vuelo, String folioFactura, double precio) {
        super(fechaVuelo, destino, origen, vuelo, folioFactura, precio);
    }
}