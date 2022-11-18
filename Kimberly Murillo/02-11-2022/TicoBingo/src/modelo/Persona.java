package modelo;

import java.io.Serializable;

public class Persona implements Serializable {
    // (nombre, apellidos, cédula, teléfono y número de cartón que
    // adquiere)
    private String nombre;
    private String apellidos;
    private String cedula;
    private String telefono;
    private int numeroCarton;

    public Persona() {
    }

    public Persona(String nombre, String apellidos, String cedula, String telefono, int numeroCarton) {
        this.nombre = nombre;
        this.apellidos = apellidos;
        this.cedula = cedula;
        this.telefono = telefono;
        this.numeroCarton = numeroCarton;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellidos() {
        return apellidos;
    }

    public void setApellidos(String apellidos) {
        this.apellidos = apellidos;
    }

    public String getCedula() {
        return cedula;
    }

    public void setCedula(String cedula) {
        this.cedula = cedula;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public int getNumeroCarton() {
        return numeroCarton;
    }

    public void setNumeroCarton(int numeroCarton) {
        this.numeroCarton = numeroCarton;
    }

    @Override
    public String toString() {
        return "Persona [apellidos=" + apellidos + ", cedula=" + cedula + ", nombre=" + nombre + ", numeroCarton="
                + numeroCarton + ", telefono=" + telefono + "]";
    }

}

/*

-- SQL Script for table persona
-- Create Database: CREATE DATABASE `historial`;

DROP DATABASE IF EXISTS `historial`;
CREATE DATABASE `historial`;
USE `historial`;

DROP TABLE IF EXISTS `persona`;
CREATE TABLE `persona` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(45) DEFAULT NULL,
  `apellidos` varchar(45) DEFAULT NULL,
  `cedula` varchar(45) DEFAULT NULL,
  `telefono` varchar(45) DEFAULT NULL,
  `numeroCarton` int(11) DEFAULT NULL,
  `fechahora` datetime DEFAULT NULL,
    PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

 */
