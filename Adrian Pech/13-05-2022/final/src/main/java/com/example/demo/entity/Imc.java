package com.example.demo.entity;

import java.io.Serializable;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;

@Entity
@Table(name = "imc")
public class Imc implements Serializable {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id_imc")
    private Long id;
    @Column(name = "estatura") // centimetros
    private float estatura;
    @Column(name = "peso") // kilogramos
    private float peso;
    @Column(name = "imc")
    private float imc;
    @Column(name = "fecha")
    private String fecha;
    @ManyToOne(cascade = { CascadeType.PERSIST, CascadeType.MERGE, CascadeType.DETACH, CascadeType.REFRESH })
    @JoinColumn(name = "id_usuario")
    private Usuario usuario;

    public Imc() {
    }

    private void fechaActual() {
        this.fecha = java.time.LocalDate.now().toString();
    }

    public Imc(float estatura, float peso) {
        this.estatura = estatura;
        this.peso = peso;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public float getEstatura() {
        return estatura;
    }

    public void setEstatura(float estatura) {
        this.estatura = estatura;
    }

    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        this.peso = peso;
    }

    public float getImc() {
        return imc;
    }

    public void setImc(float imc) {
        this.imc = imc;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }

    @Override
    public String toString() {
        return "Imc [id=" + id + ", estatura=" + estatura + ", peso=" + peso + ", usuario=" + usuario + "]";
    }

    public void calcularIMC() {
        this.imc = this.peso / ((this.estatura * this.estatura) / 10000);        
        this.fechaActual();
    }

}
