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

/**
 *
 * @author melig
 */

public class Usuario {  // Constructor 
    private String nombre;
    private String identificacion;
    private int edad;
    private String direccion;
    private Cotizacion cotizacion;

    public Usuario() {
        this.cotizacion = new Cotizacion();
    }
    
    

    @Override
    public String toString() {
        return "Usuario{" + "Nombre=" + nombre + ", Identificacion=" + identificacion + ", Edad=" + edad + ", Direccion=" + direccion + ", Cotizacion=" + cotizacion + "}";
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

    public Cotizacion getCotizacion() {
        return cotizacion;
    }

    public void setCotizacion(Cotizacion cotizacion) {
        this.cotizacion = cotizacion;
    }

    public String datosCliente() {
        return "Cliente: " + "Nombre: " + nombre + ", Identificacion: " + identificacion + ", Edad: " + edad + ", Direccion: " + direccion + ".";
    }
}
