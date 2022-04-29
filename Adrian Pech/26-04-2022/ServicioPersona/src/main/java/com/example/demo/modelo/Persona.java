package com.example.demo.modelo;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "persona")
public class Persona {
    
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    @Column(name = "nombre", length = 50)
    private String nombre;
    @Column(name = "apellido", length = 50)
    private String apellido;
    @Column(name = "edad")
    private int edad;
    @Column(name = "sexo", length = 1)
    private String sexo;
    @Column(name = "estatura")
    private double estatura;
    @Column(name = "peso")
    private double peso;
    @Column(name = "imc")
    private double imc;
    @Column(name = "fecha")
    private String fecha;

    public Persona() {
    }

    public Persona(int id, String nombre, String apellido, int edad, String sexo, double estatura, double peso, double imc, String fecha) {
        this.id = id;
        this.nombre = nombre;
        this.apellido = apellido;
        this.edad = edad;
        this.sexo = sexo;
        this.estatura = estatura;
        this.peso = peso;
        this.imc = imc;
        this.fecha = fecha;     
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public double getEstatura() {
        return estatura;
    }

    public void setEstatura(double estatura) {
        this.estatura = estatura;
    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public double getImc() {
        return imc;
    }

    public void setImc(double imc) {
        this.imc = imc;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    @Override
    public String toString() {
        return "Persona{" + "id=" + id + ", nombre=" + nombre + ", apellido=" + apellido + ", edad=" + edad + ", sexo=" + sexo + ", estatura=" + estatura + ", peso=" + peso + ", imc=" + imc + ", fecha=" + fecha + '}';
    }

    // Calculo de IMC
    public void calcularIMC() {
        // estatura en cm
        imc = peso / (estatura * estatura / 10000);
    }

    // Fecha actual, dd/MM/yyyy
    public void fechaActual() {
        fecha = java.time.LocalDate.now().toString();
    }

    // Llenar campos
    public void llenarCampos(){
        calcularIMC();
        fechaActual();
    }

}
