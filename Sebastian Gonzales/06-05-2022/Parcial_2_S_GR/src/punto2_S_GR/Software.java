package punto2_S_GR;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author User
 */
public class Software {

    // Nombre
    private String nombre;
    // Categoria
    private String categoria;
    // RAM
    private double ram;

    /**
     * Constructor de la clase Persona
     * 
     * @param nombre Nombre de la persona
     * @param ram Altura de la persona
     * @param categoria Genero de la persona
     */
    public Software(String nombre, double ram, String categoria) {
        this.nombre = nombre;
        this.categoria = categoria;
        this.ram = ram;
    }

    /**
     * Devuelve el nombre del software
     * 
     * @return Nombre del software
     */
    public String getNombre() {
        return nombre;
    }

    /**
     * Devuelve la ram del software
     * 
     * @return Ram del software
     */
    public double getRam() {
        return ram;
    }

    /**
     * Devuelve la categoria del software
     * 
     * @return Categora del software
     */
    public String getCategoria() {
        return categoria;
    }

    /**
     * Cambia el nombre del software
     * 
     * @param nombre Nuevo nombre del software
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * Cambia la ram del software
     * 
     * @param ram Nueva ram del software
     */
    public void setRam(double ram) {
        this.ram = ram;
    }

    /**
     * Cambia la categoria del software
     * 
     * @param categoria Nueva categoria del software
     */
    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    /**
     * Devuelve una cadena con los datos de la persona
     * 
     * @return Cadena con los datos del software
     */
    @Override
    public String toString() {
        return "Persona{" + "nombre=" + nombre + ", ram=" + ram + ", categoria=" + categoria + '}';
    }

}
