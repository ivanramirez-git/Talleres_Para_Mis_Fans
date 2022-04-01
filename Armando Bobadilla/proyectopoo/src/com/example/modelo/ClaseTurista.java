package com.example.modelo;

import java.io.Serializable;

// ClaseTurista es una clase hija de Boleto, es serializable para poder guardarla en un fichero binario
public class ClaseTurista extends Boleto implements Serializable {
//   Atributos de la clase padre Boleto
//    private String fechaVuelo;
//    private String destino;
//    private String origen;
//    private String vuelo;
//    private String folioFactura;
//    private double Precio;

    // Atributos de la clase ClaseTurista
    private int fila;
    private char asiento;

    // Constructor de la clase ClaseTurista
    public ClaseTurista(int fila, char asiento, String fechaVuelo, String destino, String origen, String vuelo, String folioFactura, double precio) {
        super(fechaVuelo, destino, origen, vuelo, folioFactura, precio);
        this.fila = fila;
        this.asiento = asiento;
    }

}