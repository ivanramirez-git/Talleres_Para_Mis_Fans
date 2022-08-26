
package proyecto;

import javax.swing.JOptionPane;

public class Vendedor {

    private String nombre;
    private String apellidos;
    private Integer codigo;

    // Constructor

    public Vendedor(String nombre, String apellidos, Integer codigo) {
        this.nombre = nombre;
        this.apellidos = apellidos;
        this.codigo = codigo;
    }

    public Vendedor() {
        this.setNombre(JOptionPane.showInputDialog("(VENDEDOR) Ingrese su nombre:"));
        this.setApellidos(JOptionPane.showInputDialog("(VENDEDOR) Ingrese sus apellidos:"));
        this.setCodigo(Integer.parseInt(JOptionPane.showInputDialog("(VENDEDOR) Ingrese su código de vendedor:")));
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellidos() {
        return apellidos;
    }

    public void setApellidos(String apellidos) {
        this.apellidos = apellidos;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public void imprimirVendedor() {
        System.out.println("Atendido Por: ");
        System.out.println("Nombre:" + this.getNombre());
        System.out.println("Apellidos:" + this.getApellidos());
        System.out.println("Código de empleado:" + this.getCodigo());
        System.out.println("\n");
    }
}
