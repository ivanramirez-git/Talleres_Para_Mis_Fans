/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg20151578099_20191578005;
/**
 *
 * @author aulasingenieria
 */
public class Usuario {

    /*
    
	identificacion: cadena.
	nombre: cadena.
	edad: entero 
    */

    private String identificacion;
    private String nombre;
    private int edad;

    public Usuario(String identificacion, String nombre, int edad) {
        this.identificacion = identificacion;
        this.nombre = nombre;
        this.edad = edad;
    }

    public Usuario() {
    }

    public String getIdentificacion() {
        return identificacion;
    }

    public void setIdentificacion(String identificacion) {
        this.identificacion = identificacion;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    
    
    
}
