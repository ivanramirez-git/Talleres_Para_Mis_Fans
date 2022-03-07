package com.example;

import java.io.Serializable;

public class Venta implements Serializable {
    private String codigo;
    private int cantidad;

    public Venta(String codigo, int cantidad) {
        this.codigo = codigo;
        this.cantidad = cantidad;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public int getCantidad() {
        return cantidad;
    }

    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }

    @Override
    public String toString() {
        return "Venta{" + "codigo=" + codigo + ", cantidad=" + cantidad + '}';
    }
}