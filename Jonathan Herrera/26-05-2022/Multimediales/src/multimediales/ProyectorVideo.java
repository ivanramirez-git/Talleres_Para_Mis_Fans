package multimediales;

public class ProyectorVideo extends Multimedial {
    /*
     * Los proyectores de video tienen como característica el color
     * yla marca;en cuantoala devolución los proyectores tienen un periodo de
     * préstamo de4horas
     * yse cobra sanción por cada hora adicional de uso.
     */
    private String color;
    private String marca;

    public ProyectorVideo(String codigo, String nombre, String lugarDeUso, String nombreDeQuienPresta, boolean prestado,
            String fechaDePrestamo, String fechaDeDevolucion, int tiempoDePrestamo, int unidadDeMedidaDeSancion,
            int valorDeSancion, String color, String marca) {
        super.codigo = codigo;
        super.nombre = nombre;
        super.lugarDeUso = lugarDeUso;
        super.nombreDeQuienPresta = nombreDeQuienPresta;
        super.prestado = prestado;
        super.fechaDePrestamo = fechaDePrestamo;
        super.fechaDeDevolucion = fechaDeDevolucion;
        super.tiempoDePrestamo = tiempoDePrestamo;
        super.unidadDeMedidaDeSancion = unidadDeMedidaDeSancion;
        super.valorDeSancion = valorDeSancion;
        this.color = color;
        this.marca = marca;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    @Override
    public String toString() {
        return "ProyectorVideo{" + "color=" + color + ", marca=" + marca + '}';
    }

    @Override
    public void prestar() {
        super.prestar();
    }

    @Override
    public void devolver() {
        super.devolver();
    }

}