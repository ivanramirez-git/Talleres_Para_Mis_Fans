package Punto3_JD_MH.Modelo;

public class Cuadrado extends Figura{
    private double lado;
    
    public Cuadrado(String nombre, double lado) {
        super(nombre);
        this.lado = lado;
    }
    
    public Cuadrado() {
        super();
    }
    
    public double getLado() {
        return lado;
    }
    
    public void setLado(double lado) {
        this.lado = lado;
    }
    
    // Calcula el area del cuadrado
    public double calcularArea() {
        return Math.pow(lado, 2);
    }

    @Override
    public String toString() {
        return super.toString() + ", Cuadrado:" + "lado=" + lado;
    }
    

}
