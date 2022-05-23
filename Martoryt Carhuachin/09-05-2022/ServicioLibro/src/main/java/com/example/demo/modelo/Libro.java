package com.example.demo.modelo;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "libro")
public class Libro {
    
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    @Column(name = "libro", length = 50)
    private String libro;
    @Column(name = "autor", length = 50)
    private String autor;
    @Column(name = "prestamo", length = 50)
    private String prestamo;
    @Column(name = "devolucion", length = 50)
    private String devulucion;
    @Column(name = "lector", length = 50)
    private String lector;

    public Libro() {
    }

    public Libro(int id, String libro, String autor, String prestamo, String devulucion, String lector) {
        this.id = id;
        this.libro = libro;
        this.autor = autor;
        this.prestamo = prestamo;
        this.devulucion = devulucion;
        this.lector = lector;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    
    public String getLibro() {
        return libro;
    }

    public void setLibro(String libro) {
        this.libro = libro;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public String getPrestamo() {
        return prestamo;
    }

    public void setPrestamo(String prestamo) {
        this.prestamo = prestamo;
    }

    public String getDevulucion() {
        return devulucion;
    }

    public void setDevulucion(String devulucion) {
        this.devulucion = devulucion;
    }

    public String getLector() {
        return lector;
    }

    public void setLector(String lector) {
        this.lector = lector;
    }

    @Override
    public String toString() {
        return "Persona{" + "id=" + id + ", libro=" + libro + ", autor=" + autor + ", prestamo=" + prestamo + ", devulucion=" + devulucion + ", lector=" + lector + '}';
    }

}
