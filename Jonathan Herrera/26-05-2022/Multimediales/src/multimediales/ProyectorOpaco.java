package multimediales;

public class ProyectorOpaco extends Multimedial {
    /*
     * Los Proyectores de Opacos tienen como
     * características el numero de lámparas que contiene;en cuantoala devolución
     * los proyectores
     * de opacos tienen un periodo de préstamo de1díayse cobra sanción por cada día
     * adicional de
     * uso.
     */
    private int numeroDeLamparas;

    public ProyectorOpaco(String codigo, String nombre, String lugarDeUso, String nombreDeQuienPresta, boolean prestado,
            String fechaDePrestamo, String fechaDeDevolucion, int tiempoDePrestamo, int unidadDeMedidaDeSancion,
            int valorDeSancion, int numeroDeLamparas) {
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
        this.numeroDeLamparas = numeroDeLamparas;
    }

    public int getNumeroDeLamparas() {
        return numeroDeLamparas;
    }

    public void setNumeroDeLamparas(int numeroDeLamparas) {
        this.numeroDeLamparas = numeroDeLamparas;
    }

    @Override
    public String toString() {
        return "ProyectorOpaco{" + "numeroDeLamparas=" + numeroDeLamparas + '}';
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
