package com.example;

import java.io.Serializable;
import java.util.Vector;

public class Donacion implements Serializable {

    // Atributos
    private String nombreProducto;
    private int cantidad;
    private Donante donante;

    // Constructor
    public Donacion(String nombreProducto, int cantidad, Donante donante) {
        this.nombreProducto = nombreProducto;
        this.cantidad = cantidad;
        this.donante = donante;
    }

    // Metodos
    public Donante getDonante() {
        return donante;
    }

    // To String
    @Override
    public String toString() {
        return "Donacion{" + "nombreProducto=" + nombreProducto + '\'' +
                ", cantidad=" + cantidad +
                ", donante=" + donante.toString() + '}';
    }
}
