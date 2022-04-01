package com.example.modelo;

import java.io.Serializable;

// Clase serializable Factura para guardar en fichero binario
public class Factura implements Serializable {
    //private static final long serialVersionUID = 1L;

    private String folioFactura;
    private String fechaFactura;
    private double monto;
    private double iva;
    private double total;

    // Constructor
    public Factura(String folioFactura, String fechaFactura, double monto, double iva, double total) {
        this.folioFactura = folioFactura;
        this.fechaFactura = fechaFactura;
        this.monto = monto;
        this.iva = iva;
        this.total = total;
    }

    public String getFolioFactura() {
        return folioFactura;
    }

    public void setFolioFactura(String folioFactura) {
        this.folioFactura = folioFactura;
    }

    public String getFechaFactura() {
        return fechaFactura;
    }

    public void setFechaFactura(String fechaFactura) {
        this.fechaFactura = fechaFactura;
    }

    public double getMonto() {
        return monto;
    }

    public void setMonto(double monto) {
        this.monto = monto;
    }

    public double getIva() {
        return iva;
    }

    public void setIva(double iva) {
        this.iva = iva;
    }

    public double getTotal() {
        return total;
    }

    public void setTotal(double total) {
        this.total = total;
    }

    @Override
    public String toString() {
        return "Factura{" +
                "folioFactura='" + folioFactura + '\'' +
                ", fechaFactura='" + fechaFactura + '\'' +
                ", monto=" + monto +
                ", iva=" + iva +
                ", total=" + total +
                '}';
    }
}
