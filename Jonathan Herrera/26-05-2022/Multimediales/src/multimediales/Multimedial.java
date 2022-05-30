package multimediales;

// localdatetime
import java.time.LocalDateTime;

public abstract class Multimedial {
    /*
     * un código,un nombre,yun lugar de uso,nombre de quien realiza el
     * préstamo,además
     * se debe permitir el préstamo,registrando la fecha de préstamoyla
     * devolución.Cada elemento
     * específico define los tiempos de préstamo,la unidad de medida de
     * sanción(horaodía)yel valor
     * de la sanción por unidad de medida
     */
    protected String codigo;
    protected String nombre;
    protected String lugarDeUso;
    protected String nombreDeQuienPresta;
    protected boolean prestado;
    protected String fechaDePrestamo;
    protected String fechaDeDevolucion;
    protected int tiempoDePrestamo;
    protected int unidadDeMedidaDeSancion;
    protected int valorDeSancion;

    // prestamo
    public void prestar() {
        this.prestado = true;
        // formato de fecha: dd/MM/yyyy HH:mm:ss
        this.fechaDePrestamo = LocalDateTime.now().toString();
    }

    // devolucion
    public void devolver() {
        this.prestado = false;
        // formato de fecha: dd/MM/yyyy HH:mm:ss
        this.fechaDeDevolucion = LocalDateTime.now().toString();
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getLugarDeUso() {
        return lugarDeUso;
    }

    public void setLugarDeUso(String lugarDeUso) {
        this.lugarDeUso = lugarDeUso;
    }

    public String getNombreDeQuienPresta() {
        return nombreDeQuienPresta;
    }

    public void setNombreDeQuienPresta(String nombreDeQuienPresta) {
        this.nombreDeQuienPresta = nombreDeQuienPresta;
    }

    public boolean isPrestado() {
        return prestado;
    }

    public void setPrestado(boolean prestado) {
        this.prestado = prestado;
    }

    public String getFechaDePrestamo() {
        return fechaDePrestamo;
    }

    public void setFechaDePrestamo(String fechaDePrestamo) {
        this.fechaDePrestamo = fechaDePrestamo;
    }

    public String getFechaDeDevolucion() {
        return fechaDeDevolucion;
    }

    public void setFechaDeDevolucion(String fechaDeDevolucion) {
        this.fechaDeDevolucion = fechaDeDevolucion;
    }

    public int getTiempoDePrestamo() {
        return tiempoDePrestamo;
    }

    public void setTiempoDePrestamo(int tiempoDePrestamo) {
        this.tiempoDePrestamo = tiempoDePrestamo;
    }

    public int getUnidadDeMedidaDeSancion() {
        return unidadDeMedidaDeSancion;
    }

    public void setUnidadDeMedidaDeSancion(int unidadDeMedidaDeSancion) {
        this.unidadDeMedidaDeSancion = unidadDeMedidaDeSancion;
    }

    public int getValorDeSancion() {
        return valorDeSancion;
    }

    public void setValorDeSancion(int valorDeSancion) {
        this.valorDeSancion = valorDeSancion;
    }

}
