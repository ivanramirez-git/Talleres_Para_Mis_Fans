/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */


/**
 *
 * @author aulasingenieria
 */
public class Revision extends Cliente{
    
    private String placa;
    private int modelo;
    private String estado;

    public Revision(String placa, int modelo, String estado, String identificacion, String nombre) {
        super(identificacion, nombre);
        this.placa = placa;
        this.modelo = modelo;
        this.estado = estado;
    }

    public Revision() {
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public int getModelo() {
        return modelo;
    }

    public void setModelo(int modelo) {
        this.modelo = modelo;
    }

    public String getEstado() {
        return estado;
    }

    public void setEstado(String estado) {
        this.estado = estado;
    }

    @Override
    public String toString() {
        return "Revision{" + "placa=" + placa + ", modelo=" + modelo + ", estado=" + estado + '}';
    }
    
}
