package com.example;

import java.io.Serializable;

public class Voluntario implements Serializable {

    // Atributos
    private String cedula;
    private String apellidos;
    private String nombres;
    private String fechaNacimiento;
    private String direccion;
    private String usuario;
    private String clave;
    private String nombreCampana;

    // Constructor
    public Voluntario(String cedula, String apellidos, String nombres, String fechaNacimiento, String direccion, String usuario, String clave, String nombreCampana) {
        this.cedula = cedula;
        this.apellidos = apellidos;
        this.nombres = nombres;
        this.fechaNacimiento = fechaNacimiento;
        this.direccion = direccion;
        this.usuario = usuario;
        this.clave = clave;
        this.nombreCampana = nombreCampana;
    }

    // To String
    @Override
    public String toString() {
        return "Voluntario{" +
                "cedula='" + cedula + '\'' +
                ", apellidos='" + apellidos + '\'' +
                ", nombres='" + nombres + '\'' +
                ", fechaNacimiento='" + fechaNacimiento + '\'' +
                ", direccion='" + direccion + '\'' +
                ", usuario='" + usuario + '\'' +
                ", clave='" + clave + '\'' +
                ", nombreCampana='" + nombreCampana + '\'' +
                '}';
    }

}
