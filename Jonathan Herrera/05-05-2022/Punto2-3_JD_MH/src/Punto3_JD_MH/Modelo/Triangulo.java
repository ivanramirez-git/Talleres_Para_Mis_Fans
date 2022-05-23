package Punto3_JD_MH.Modelo;

public class Triangulo extends Figura {
    private double base;
    private double altura;

    public Triangulo(String nombre, double base, double altura) {
        super(nombre);
        this.base = base;
        this.altura = altura;
    }

    public Triangulo() {
        super();
    }

    public double getBase() {
        return base;
    }

    public void setBase(double base) {
        this.base = base;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    // Calcula el area del Triangulo
    public double calcularArea() {
        return (this.base * this.altura) / 2;
    }

    @Override
    public String toString() {
        return super.toString() + ", Triangulo:" + "base=" + base + ", altura=" + altura;
    }

}
