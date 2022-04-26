package com.example.demo.modelo;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "triangulo")
public class Triangulo {
    
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    private float lado1;
    private float lado2;
    private float lado3;
    private float perimetro;
    private float area;

    public Triangulo() {
    }

    public Triangulo(int id, float lado1, float lado2, float lado3, float perimetro, float area) {
        this.id = id;
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
        this.perimetro = perimetro;
        this.area = area;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public float getLado1() {
        return lado1;
    }

    public void setLado1(float lado1) {
        this.lado1 = lado1;
    }

    public float getLado2() {
        return lado2;
    }

    public void setLado2(float lado2) {
        this.lado2 = lado2;
    }

    public float getLado3() {
        return lado3;
    }

    public void setLado3(float lado3) {
        this.lado3 = lado3;
    }

    public float getPerimetro() {
        return perimetro;
    }

    public void setPerimetro(float perimetro) {
        this.perimetro = perimetro;
    }

    public float getArea() {
        return area;
    }

    public void setArea(float area) {
        this.area = area;
    }

    public float calcularPerimetro() {
        return lado1 + lado2 + lado3;
    }

    public float calcularArea() {
        float s = calcularPerimetro() / 2;
        return (float) Math.sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }

    // Calculos
    public void calcular() {
        this.perimetro = calcularPerimetro();
        this.area = calcularArea();
    }

    @Override
    public String toString() {
        return "Triangulo{" + "id=" + id + ", lado1=" + lado1 + ", lado2=" + lado2 + ", lado3=" + lado3 + ", perimetro=" + perimetro + ", area=" + area + '}';
    }

}
