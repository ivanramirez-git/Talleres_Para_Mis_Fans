

public class Prestamo {

    private String nombre; // Nombre del cliente
    private String descripcion; // Descripción del prestamo
    private int diasEntrega; // Días de entrega
    private double valor; // Valor del prestamo
    private int diasDevolucion; // Días de devolución
    private double promocion; // Porcentaje de descuento
    private int lavadoras; // Número de lavadoras
    private double tiempo; // Tiempo de entrega

    public Prestamo(String nombre, String descripcion, int diasEntrega, double valor, int diasDevolucion, double promocion, int lavadoras, double tiempo) {
        this.nombre = nombre;
        this.descripcion = descripcion;
        this.diasEntrega = diasEntrega;
        this.valor = valor;
        this.diasDevolucion = diasDevolucion;
        this.promocion = promocion;
        this.lavadoras = lavadoras;
        this.tiempo = tiempo;
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

    public int getDiasEntrega() {
        return diasEntrega;
    }

    public void setDiasEntrega(int diasEntrega) {
        this.diasEntrega = diasEntrega;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public int getDiasDevolucion() {
        return diasDevolucion;
    }

    public void setDiasDevolucion(int diasDevolucion) {
        this.diasDevolucion = diasDevolucion;
    }

    public double getPromocion() {
        return promocion;
    }

    public void setPromocion(double promocion) {
        this.promocion = promocion;
    }

    public double getValorConDescuento() {
        return valor - (valor * promocion / 100);
    }

    public int getLavadoras() {
        return lavadoras;
    }

    public void setLavadoras(int lavadoras) {
        this.lavadoras = lavadoras;
    }

    public double getTiempo() {
        return tiempo;
    }

    public void setTiempo(double tiempo) {
        this.tiempo = tiempo;
    }

    public double getTotalTiempo() {
        return tiempo * lavadoras;
    }

    public String toString() {
        return "Prestamo{" + "nombre=" + nombre + ", descripcion=" + descripcion + ", diasEntrega=" + diasEntrega + ", valor=" + valor + ", diasDevolucion=" + diasDevolucion + ", promocion=" + promocion + ", valorConDescuento=" + getValorConDescuento() + ", lavadoras=" + lavadoras + ", tiempo=" + tiempo + ", totalTiempo=" + getTotalTiempo() + '}';
    }
    

}
