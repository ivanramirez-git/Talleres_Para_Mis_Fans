package main.java.proyecto.HDA;

public class Producto {
    
    private int codigo;
    
    private String nombreProducto;
    
    private int precioProducto;
    
    
    private String cantidadProducto;

    public Producto() {
    }

    public int getId() {
        return codigo;
    }

    public void setId(int id) {
        this.codigo = id;
    }
    
    public String getNombreProducto() {
        return nombreProducto;
    }

    public void setNombreProducto(String nombreProducto) {
        this.nombreProducto = nombreProducto;
    }

    public int getPrecioProducto() {
        return precioProducto;
    }

    public void setPrecioProducto(int precioProducto) {
        this.precioProducto = precioProducto;
    }


    public String getCantidadProducto() {
        return cantidadProducto;
    }

    public void setCantidadProducto(String cantidadProducto) {
        this.cantidadProducto = cantidadProducto;
    }

    @Override
    public String toString() {
        return "Producto: " + "id= " + codigo + ", nombreProducto= " + nombreProducto + ", precioProducto= " + precioProducto +", cantidadProducto= " + cantidadProducto;
    }
    
}
