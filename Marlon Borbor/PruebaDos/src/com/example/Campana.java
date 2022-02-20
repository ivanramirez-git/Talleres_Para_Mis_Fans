package com.example;

import java.io.Serializable;
import java.util.Vector;

public class Campana implements Serializable {

    // Atributos
    private String nombre;
    private String lugar;
    private String fecha;
    private char estado;

    // Vectores
    private Vector<Donacion> donaciones;
    private Vector<Voluntario> voluntarios;

    // Constructor
    public Campana(String nombre, String lugar, String fecha, char estado) {
        this.nombre = nombre;
        this.lugar = lugar;
        this.fecha = fecha;
        this.estado = estado;
        donaciones = new Vector<Donacion>();
        voluntarios = new Vector<Voluntario>();
    }

    // Metodos
    public void agregarDonacion(Donacion donacion) {
        donaciones.add(donacion);
    }

    public void agregarVoluntario(Voluntario voluntario) {
        voluntarios.add(voluntario);
    }

    // Getters
    public Vector<Donacion> getDonaciones() {
        return donaciones;
    }

    public Vector<Voluntario> getVoluntarios() {
        return voluntarios;
    }

    public String getNombre() {
        return nombre;
    }

    // To String
    @Override
    public String toString() {
        return "Campana{" +
                "nombre='" + nombre + '\'' +
                ", lugar='" + lugar + '\'' +
                ", fecha='" + fecha + '\'' +
                ", estado=" + estado +
                ", donaciones=" + donaciones.toString() +
                ", voluntarios=" + voluntarios.toString() +
                '}';
    }
}
