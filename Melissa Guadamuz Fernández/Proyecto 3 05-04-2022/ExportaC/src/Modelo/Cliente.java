/*
Universidad Estatal a Distancia
Estudiante:Melissa Guadamuz Fernández
Cedula:113870559
Centro Universitario San José
Grupo # 1
Tutor JOSE MANUEL SALAZAR HERRERA
Tarea#1
Primer Cuatrimestre 2022
 */
package Modelo;

import java.io.Serializable;

/**
 *
 * @author melig
 */

public class Cliente implements Serializable{
    private String nombre;
    private String identificacion;
    private int edad;
    private String direccion;

    public Cliente() {
    }
    
    @Override
    public String toString() {
        return "Usuario{" + "Nombre=" + nombre + ", Identificacion=" + identificacion + ", Edad=" + edad + ", Direccion=" + direccion + ", Cotizacion=" + '}';
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getIdentificacion() {
        return identificacion;
    }

    public void setIdentificacion(String identificacion) {
        this.identificacion = identificacion;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public String datosCliente() {
        return "Nombre: " + nombre + ", Identificacion: " + identificacion + ", Edad: " + edad + ", Direccion: " + direccion + ".";
    }
}
