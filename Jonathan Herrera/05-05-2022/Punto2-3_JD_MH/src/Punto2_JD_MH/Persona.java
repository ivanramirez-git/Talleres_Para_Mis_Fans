package Punto2_JD_MH;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author User
 */
public class Persona {

    // Nombre
    private String nombre;
    // Altura
    private double altura;
    // Genero
    private String genero;

    /**
     * Constructor de la clase Persona
     * 
     * @param nombre Nombre de la persona
     * @param altura Altura de la persona
     * @param genero Genero de la persona
     */
    public Persona(String nombre, double altura, String genero) {
        this.nombre = nombre;
        this.altura = altura;
        this.genero = genero;
    }

    /**
     * Devuelve el nombre de la persona
     * 
     * @return Nombre de la persona
     */
    public String getNombre() {
        return nombre;
    }

    /**
     * Devuelve la altura de la persona
     * 
     * @return Altura de la persona
     */
    public double getAltura() {
        return altura;
    }

    /**
     * Devuelve el genero de la persona
     * 
     * @return Genero de la persona
     */
    public String getGenero() {
        return genero;
    }

    /**
     * Cambia el nombre de la persona
     * 
     * @param nombre Nuevo nombre de la persona
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * Cambia la altura de la persona
     * 
     * @param altura Nueva altura de la persona
     */
    public void setAltura(double altura) {
        this.altura = altura;
    }

    /**
     * Cambia el genero de la persona
     * 
     * @param genero Nuevo genero de la persona
     */
    public void setGenero(String genero) {
        this.genero = genero;
    }

    /**
     * Devuelve una cadena con los datos de la persona
     * 
     * @return Cadena con los datos de la persona
     */
    @Override
    public String toString() {
        return "Persona{" + "nombre=" + nombre + ", altura=" + altura + ", genero=" + genero + '}';
    }

}
