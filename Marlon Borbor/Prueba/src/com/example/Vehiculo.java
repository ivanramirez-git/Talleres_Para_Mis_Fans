package com.example;

import java.io.Serializable;

// Clase serializable para guardar en archivo binario
public class Vehiculo implements Serializable {
    private String color;
    private int ruedas;

    public Vehiculo(String color, int ruedas) {
        this.color = color;
        this.ruedas = ruedas;
    }

    public Vehiculo() { }

    public String getColor() {
        return color;
    }

    public int getRuedas() {
        return ruedas;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setRuedas(int ruedas) {
        this.ruedas = ruedas;
    }

    @Override
    public String toString() {
        return "Vehiculo{" + "color=" + color + ", ruedas=" + ruedas + '}';
    }
}
