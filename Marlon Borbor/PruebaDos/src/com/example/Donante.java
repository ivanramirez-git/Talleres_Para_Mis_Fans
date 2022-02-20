package com.example;

import java.io.Serializable;

public class Donante implements Serializable {

    // Atributos
    private String cedula;
    private String apellidos;
    private String nombres;
    private String fechaNacimiento;
    private String direccion;
    private String telefono;
    private String correo;

    // Constructor
    public Donante(String cedula, String apellidos, String nombres, String fechaNacimiento, String direccion, String telefono, String correo) {
        this.cedula = cedula;
        this.apellidos = apellidos;
        this.nombres = nombres;
        this.fechaNacimiento = fechaNacimiento;
        this.direccion = direccion;
        this.telefono = telefono;
        this.correo = correo;
    }

    // Getters
    public String getCedula() {
        return cedula;
    }

    // To String
    @Override
    public String toString() {
        return "Donante{" + "cedula=" + cedula + '\'' +
                ", apellidos=" + apellidos + '\'' +
                ", nombres=" + nombres + '\'' +
                ", fechaNacimiento=" + fechaNacimiento + '\'' +
                ", direccion=" + direccion + '\'' +
                ", telefono=" + telefono + '\'' +
                ", correo=" + correo + '\'' +
                '}';
    }

}
