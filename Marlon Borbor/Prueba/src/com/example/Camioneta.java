package com.example;

import java.io.Serializable;

public class Camioneta extends Coche implements Serializable {
    private float carga; // kg

    public Camioneta(String color, float velocidad, float cilindrada, float carga) {
        super(color, velocidad, cilindrada);
        this.carga = carga;
    }

    public Camioneta() {
        super();
    }

    public float getCarga() {
        return carga;
    }

    public void setCarga(float carga) {
        this.carga = carga;
    }

    @Override
    public String toString() {
        return super.toString() + "Camioneta{" + "carga=" + carga + '}';
    }
}
