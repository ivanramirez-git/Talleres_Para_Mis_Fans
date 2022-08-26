
package proyecto;

import javax.swing.JOptionPane;

public class Articulo {

    private String nombre;
    private int codigo;
    private int precio;

    // Constructor
    public Articulo(String nombre, int codigo, int precio) {
        this.nombre = nombre;
        this.codigo = codigo;
        this.precio = precio;
    }

    public Articulo() {
        this.setNombre(JOptionPane.showInputDialog("(ARTICULO) Ingrese el nombre del articulo:"));
        this.setCodigo(Integer.parseInt(JOptionPane.showInputDialog("(ARTICULO) Ingrese el codigo del articulo:")));
        this.setPrecio(Integer.parseInt(JOptionPane.showInputDialog("(ARTICULO) Ingrese el precio del articulo:")));
    }
    // Getter and setter

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getCodigo() {
        return this.codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public int getPrecio() {
        return precio;
    }

    public void setPrecio(int precio) {
        this.precio = precio;
    }

    public void imprimirArticulo() {
        System.out.println("Nombre: " + this.getNombre());
        System.out.println("Código: " + this.getCodigo());
        System.out.println("Precio: " + this.getPrecio());
        System.out.println("\n");
    }
}
