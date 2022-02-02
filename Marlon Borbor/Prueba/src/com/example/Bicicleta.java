package com.example;

import java.io.Serializable;

public class Bicicleta extends Vehiculo implements Serializable {
    private boolean tipo; // true = urbana, false = deportiva

    public Bicicleta(String color, boolean tipo) {
        super(color, 2);
        this.tipo = tipo;
    }

    public Bicicleta() {
        super();
    }

    public boolean isTipo() {
        return tipo;
    }

    public void setTipo(boolean tipo) {
        this.tipo = tipo;
    }

    @Override
    public String toString() {
        return super.toString() + " Bicicleta{" + "tipo=" + (tipo ? "urbana" : "deportiva") + '}';
    }
}
