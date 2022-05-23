package punto3_S_GR.Modelo;

public class Circulo extends Figura{
    private double radio;
    
    public Circulo(String nombre, double radio) {
        super(nombre);
        this.radio = radio;
    }
    
    public Circulo() {
        super();
    }
    
    public double getRadio() {
        return radio;
    }
    
    public void setRadio(double radio) {
        this.radio = radio;
    }

    // Calcula el area del circulo
    public double calcularArea() {
        return Math.PI * Math.pow(radio, 2);
    }
    
    @Override
    public String toString() {
        return super.toString() + ", Circulo:" + "radio=" + radio;
    }  

}
