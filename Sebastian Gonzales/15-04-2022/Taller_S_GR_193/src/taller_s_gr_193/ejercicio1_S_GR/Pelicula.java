/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package taller_s_gr_193.ejercicio1_S_GR;

/**
 *
 * @author User
 */
public class Pelicula {
    // Titulo
    private String Titulo;
    // Categoria
    private String Categoria; // a (Acción, Terror, Comedia)
    // Duracion
    private Duracion duracion;
    // Hora inicial de proyeccion
    private Duracion horaInicial;
    // Hora final de proyeccion
    private Duracion horaFinal;

    // Constructor
    public Pelicula(String titulo, String categoria, Duracion duracion) {
        this.Titulo = titulo;
        this.Categoria = categoria;
        this.duracion = duracion;
        this.horaInicial = new Duracion();
        this.horaFinal = null;
    }

    public String getTitulo() {
        return Titulo;
    }

    public void setTitulo(String titulo) {
        this.Titulo = titulo;
    }

    public String getCategoria() {
        return Categoria;
    }

    public void setCategoria(String categoria) {
        this.Categoria = categoria;
    }

    public Duracion getDuracion() {
        return duracion;
    }

    public void setDuracion(Duracion duracion) {
        this.duracion = duracion;
    }

    public Duracion getHoraInicial() {
        return horaInicial;
    }

    public void setHoraInicial(Duracion horaInicial) {
        this.horaInicial = horaInicial;
    }

    public Duracion getHoraFinal() {
        return horaFinal;
    }

    public void setHoraFinal(Duracion horaFinal) {
        this.horaFinal = horaFinal;
    }

    @Override
    public String toString() {
        return "Pelicula{" + "Titulo=" + Titulo + ", Categoria=" + Categoria + ", duracion=" + duracion + '}';
    }
}
