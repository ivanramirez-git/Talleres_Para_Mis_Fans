package Modelo;

public class Carro extends Vehiculo {

    // Color
    private String color;
    // Numero de puertas
    private int numeroPuertas;
    // Constructor
    public Carro(String placa, String modelo, String color, int numeroPuertas) {
        super(placa, modelo);
        this.color = color;
        this.numeroPuertas = numeroPuertas;
    }
    public Carro(String placa, String modelo) {
        super(placa, modelo);
    }
    public Carro() {
        super();
    }
    // Getters y setters
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }
    public int getNumeroPuertas() {
        return numeroPuertas;
    }
    public void setNumeroPuertas(int numeroPuertas) {
        this.numeroPuertas = numeroPuertas;
    }
    // toString
    @Override
    public String toString() {
        return super.toString()+" Carro [color=" + color + ", numeroPuertas=" + numeroPuertas +"]";
    }

}
