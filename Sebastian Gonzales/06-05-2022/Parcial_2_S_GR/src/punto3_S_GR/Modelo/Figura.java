/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package punto3_S_GR.Modelo;

/**
 *
 * @author User
 */
public class Figura {

    private String nombre;

    public Figura(String nombre) {
        this.nombre = nombre;
    }

    public Figura() {
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    // Calcula el area de la figura
    public double calcularArea() {
        return 0;
    }

    @Override
    public String toString() {
        return "Figura:" + "nombre=" + nombre;
    }

}
