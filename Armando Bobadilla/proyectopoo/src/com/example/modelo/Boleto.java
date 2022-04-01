package com.example.modelo;

import java.io.Serializable;

// Clase Boleto, padre y serializable para poder guardar en fichero binario
public class Boleto implements Serializable {
    private String fechaVuelo;
    private String destino;
    private String origen;
    private String vuelo;
    private String folioFactura;
    private double Precio;

    public Boleto(String fechaVuelo, String destino, String origen, String vuelo, String folioFactura, double precio) {
        this.fechaVuelo = fechaVuelo;
        this.destino = destino;
        this.origen = origen;
        this.vuelo = vuelo;
        this.folioFactura = folioFactura;
        Precio = precio;
    }

    public String getFechaVuelo() {
        return fechaVuelo;
    }

    public void setFechaVuelo(String fechaVuelo) {
        this.fechaVuelo = fechaVuelo;
    }

    public String getDestino() {
        return destino;
    }

    public void setDestino(String destino) {
        this.destino = destino;
    }

    public String getOrigen() {
        return origen;
    }

    public void setOrigen(String origen) {
        this.origen = origen;
    }

    public String getVuelo() {
        return vuelo;
    }

    public void setVuelo(String vuelo) {
        this.vuelo = vuelo;
    }

    public String getFolioFactura() {
        return folioFactura;
    }

    public void setFolioFactura(String folioFactura) {
        this.folioFactura = folioFactura;
    }

    @Override
    public String toString() {
        return "Boleto{" +
                "fechaVuelo='" + fechaVuelo + '\'' +
                ", destino='" + destino + '\'' +
                ", origen='" + origen + '\'' +
                ", vuelo='" + vuelo + '\'' +
                ", folioFactura='" + folioFactura + '\'' +
                ", Precio=" + Precio +
                '}';
    }

    public double getPrecio() {
        return Precio;
    }

    public void setPrecio(double precio) {
        Precio = precio;
    }
}
