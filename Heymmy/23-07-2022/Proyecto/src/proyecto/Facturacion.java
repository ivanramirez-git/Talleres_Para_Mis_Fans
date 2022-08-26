
package proyecto;

import java.time.LocalDateTime;

public class Facturacion {

    String fecha;
    String hora;
    Articulo[] articulos;
    Integer[] cantidades;
    int cantidadArticulos;

    public Facturacion(Articulo[] articulos, Integer[] cantidades, int cantidadArticulos) {
        this.articulos = articulos;
        this.cantidades = cantidades;
        this.fecha = LocalDateTime.now().toString().substring(0, 10);
        this.hora = LocalDateTime.now().toString().substring(11, 19);
        this.cantidadArticulos = cantidadArticulos;
    }

    // setters and getters
    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    public String getHora() {
        return hora;
    }

    public void setHora(String hora) {
        this.hora = hora;
    }

    public Articulo[] getArticulos() {
        return articulos;
    }

    public void setArticulos(Articulo[] articulos) {
        this.articulos = articulos;
    }

    public Integer[] getCantidades() {
        return cantidades;
    }

    public void setCantidades(Integer[] cantidades) {
        this.cantidades = cantidades;
    }

    // dar precio total de la factura
    public int precioTotal() {
        int total = 0;
        for (int i = 0; i < cantidadArticulos; i++) {
            total += articulos[i].getPrecio() * cantidades[i];
        }
        return total;
    }

    // imprimir factura
    public void imprimirFactura() {
        System.out.println("Fecha: " + this.getFecha());
        System.out.println("Hora: " + this.getHora());
        System.out.println("------ARTÍCULOS-----");
        System.out.println("No. \t Nombre \t Código \t Precio \t Cantidad \t Subtotal");
        for (int i = 0; i < cantidadArticulos; i++) {
            System.out.println((i + 1) + "\t" + articulos[i].getNombre() + "\t" + articulos[i].getCodigo() + "\t"
                    + articulos[i].getPrecio() + "\t" + cantidades[i] + "\t"
                    + (articulos[i].getPrecio() * cantidades[i]));
        }
        System.out.println("\n");
        System.out.println("Total: " + precioTotal());
    }

}
