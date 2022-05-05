package Modelo;

public class Moto extends Vehiculo {

    // Cilindraje
    private int cilindraje;
    // Casco
    private boolean casco;
    // Constructor
    public Moto(String placa, String modelo, int cilindraje, boolean casco) {
        super(placa, modelo);
        this.cilindraje = cilindraje;
        this.casco = casco;
    }
    public Moto(String placa, String modelo) {
        super(placa, modelo);
    }
    public Moto() {
        super();
    }
    // Getters y setters
    public int getCilindraje() {
        return cilindraje;
    }
    public void setCilindraje(int cilindraje) {
        this.cilindraje = cilindraje;
    }
    public boolean isCasco() {
        return casco;
    }
    public String getCasco() {
        if (casco) {
            return "Si";
        } else {
            return "No";
        }
    }
    public void setCasco(boolean casco) {
        this.casco = casco;
    }
    // toString
    @Override
    public String toString() {
        return super.toString()+" Moto [cilindraje=" + cilindraje + ", casco=" + casco + "]";
    }
    
}
