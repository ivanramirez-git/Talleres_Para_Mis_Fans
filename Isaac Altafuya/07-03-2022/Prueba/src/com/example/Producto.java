package com.example;

public class Producto {

    private String codigo;
    private String descripcion;
    private int stock;
    private double precioUnitario;

    public Producto(String codigo, String descripcion, int stock, double precioUnitario) {
        this.codigo = codigo;
        this.descripcion = descripcion;
        this.stock = stock;
        this.precioUnitario = precioUnitario;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    public double getPrecioUnitario() {
        return precioUnitario;
    }

    public void setPrecioUnitario(double precioUnitario) {
        this.precioUnitario = precioUnitario;
    }

    @Override
    public String toString() {
        return "Producto{" + "codigo=" + codigo + ", descripcion=" + descripcion + ", stock=" + stock + ", precioUnitario=" + precioUnitario + '}';
    }

}
