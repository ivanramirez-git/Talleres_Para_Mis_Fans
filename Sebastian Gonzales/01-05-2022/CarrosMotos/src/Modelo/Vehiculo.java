package Modelo;

public class Vehiculo {
    
    // Placa
    private String placa;
    // Modelo
    private String modelo;
    public Vehiculo(String placa, String modelo) {
        this.placa = placa;
        this.modelo = modelo;
    }
    public Vehiculo() {
    }
    public String getPlaca() {
        return placa;
    }
    public void setPlaca(String placa) {
        this.placa = placa;
    }
    public String getModelo() {
        return modelo;
    }
    public void setModelo(String modelo) {
        this.modelo = modelo;
    }
    @Override
    public String toString() {
        return "Vehiculo [modelo=" + modelo + ", placa=" + placa + "]";
    }
}
