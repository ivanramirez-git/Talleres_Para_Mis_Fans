package com.example;

import java.io.Serializable;

public class Motocicleta extends Bicicleta implements Serializable {

    private float velocidad; // km/h
    private float cilindrada; // cc

    public Motocicleta(String color, boolean tipo, float velocidad, float cilindrada) {
        super(color, tipo);
        this.velocidad = velocidad;
        this.cilindrada = cilindrada;
    }

    public Motocicleta() { super(); }

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
        return super.toString() + " Motocicleta{" +
                "velocidad=" + velocidad +
                ", cilindrada=" + cilindrada +
                '}';
    }
}
