package com.example;

import java.io.Serializable;

public class Coche extends Vehiculo implements Serializable {
    private float velocidad; //km/h
    private float cilindrada; //cc

    public Coche(String color, float velocidad, float cilindrada) {
        super(color, 4);
        this.velocidad = velocidad;
        this.cilindrada = cilindrada;
    }

    public Coche() { super(); }

    public float getVelocidad() {
        return velocidad;
    }

    public void setVelocidad(float velocidad) {
        this.velocidad = velocidad;
    }

    public float getCilindrada() {
        return cilindrada;
    }

    public void setCilindrada(float cilindrada) {
        this.cilindrada = cilindrada;
    }

    @Override
    public String toString() {
        return super.toString() + " Coche{" + "velocidad=" + velocidad + ", cilindrada=" + cilindrada + '}';
    }
}
