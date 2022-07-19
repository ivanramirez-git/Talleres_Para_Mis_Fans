package examen2luisvega;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author User
 */
public class Factura {
    // el numero de la factura, el código de servicio a facturar, el mes a facturar,
    // el monto, el descuento, el subtotal el IVA (13%) y el total.
    // cedula del cliente
    private int numeroFactura;
    private String codigoServicio;
    private int mes;
    private double monto;
    private double descuento;
    private double subtotal;
    private double iva;
    private double total;

    public Factura(int numeroFactura, String codigoServicio, int mes, double monto, double descuento, double subtotal,
            double iva, double total) {
        this.numeroFactura = numeroFactura;
        this.codigoServicio = codigoServicio;
        this.mes = mes;
        this.monto = monto;
        this.descuento = descuento;
        this.subtotal = subtotal;
        this.iva = iva;
        this.total = total;
    }

    // metodo que genera una factura aleatoria
    public Factura(int numeroFactura, String codigoServicio) {
        this.numeroFactura = numeroFactura;
        this.codigoServicio = codigoServicio;
        this.mes = (int) (Math.random() * 12 + 1);
        this.monto = 100 + Math.random() * 50;
        this.descuento = Math.random() * 10;
        this.subtotal = this.monto - this.descuento;
        this.iva = this.subtotal * 0.13;
        this.total = this.subtotal + this.iva;
    }

    public int getNumeroFactura() {
        return numeroFactura;
    }

    public void setNumeroFactura(int numeroFactura) {
        this.numeroFactura = numeroFactura;
    }

    public String getCodigoServicio() {
        return codigoServicio;
    }

    public void setCodigoServicio(String codigoServicio) {
        this.codigoServicio = codigoServicio;
    }

    public int getMes() {
        return mes;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public double getMonto() {
        return monto;
    }

    public void setMonto(double monto) {
        this.monto = monto;
        this.subtotal = this.monto - this.descuento;
        this.iva = this.subtotal * 0.13;
        this.total = this.subtotal + this.iva;
    }

    public double getDescuento() {
        return descuento;
    }

    public void setDescuento(double descuento) {
        this.descuento = descuento;
        this.subtotal = this.monto - this.descuento;
        this.iva = this.subtotal * 0.13;
        this.total = this.subtotal + this.iva;
    }

    public double getSubtotal() {
        return subtotal;
    }

    public void setSubtotal(double subtotal) {
        this.subtotal = subtotal;
        this.iva = this.subtotal * 0.13;
        this.total = this.subtotal + this.iva;
    }

    public double getIva() {
        return iva;
    }

    public void setIva(double iva) {
        this.iva = iva;
        this.total = this.subtotal + this.iva;
    }

    public double getTotal() {
        return total;
    }

    public void setTotal(double total) {
        this.total = total;
    }

    @Override
    public String toString() {
        return "Factura{" + "numeroFactura=" + numeroFactura + ", codigoServicio=" + codigoServicio + ", mes=" + mes
                + ", monto=" + monto + ", descuento=" + descuento + ", subtotal=" + subtotal + ", iva=" + iva
                + ", total=" + total + '}';
    }

}
