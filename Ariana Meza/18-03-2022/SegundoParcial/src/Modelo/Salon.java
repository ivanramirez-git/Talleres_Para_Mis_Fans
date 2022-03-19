package Modelo;

public class Salon {

    // id, nombre, descripcion, capacidad, precio
    private int id;
    private String nombre;
    private String descripcion;
    private int capacidad;
    private double precio;
    
    public Salon(int id, String nombre, String descripcion, int capacidad, double precio) {
        this.id = id;
        this.nombre = nombre;
        this.descripcion = descripcion;
        this.capacidad = capacidad;
        this.precio = precio;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public int getCapacidad() {
        return capacidad;
    }

    public void setCapacidad(int capacidad) {
        this.capacidad = capacidad;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    @Override
    public String toString() {
        return "Salon{" + "id=" + id + ", nombre=" + nombre + ", descripcion=" + descripcion + ", capacidad=" + capacidad + ", precio=" + precio + '}';
    }
    
}
