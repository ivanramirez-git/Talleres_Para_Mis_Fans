
package proyecto;

import javax.swing.JOptionPane;

public class Cliente {

    private String nombre;
    private String apellidos;
    private Integer edad;
    private Integer cedula;
    private String correo;

    // Constructor

    public Cliente(String nombre, String apellidos, Integer edad, Integer cedula, String correo) {
        this.nombre = nombre;
        this.apellidos = apellidos;
        this.edad = edad;
        this.cedula = cedula;
        this.correo = correo;
    }

    public Cliente() {
        this.setNombre(JOptionPane
                .showInputDialog(
                        "(CLIENTE) Para generar su factura debe ingresar los siguientets datos \n Ingrese su nombre:"));
        this.setApellidos(JOptionPane.showInputDialog("(CLIENTE) Ingrese sus apellidos:"));
        this.setEdad(Integer.parseInt(JOptionPane.showInputDialog("(CLIENTE) Ingrese su edad:")));
        this.setCedula(Integer.parseInt(JOptionPane.showInputDialog("(CLIENTE) Ahora ingrese su numero de cédula:")));
        this.setCorreo(JOptionPane.showInputDialog("(CLIENTE) Por ultimo, ingrese su correo electrónico:"));
    }

    // SETANDGET
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

    public Integer getEdad() {
        return edad;
    }

    public void setEdad(Integer edad) {
        this.edad = edad;
    }

    public Integer getCedula() {
        return cedula;
    }

    public void setCedula(Integer cedula) {
        this.cedula = cedula;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public void imprimirCliente() {
        System.out.println("Cliente: ");
        System.out.println("Nombre:" + this.getNombre());
        System.out.println("Apellidos:" + this.getApellidos());
        System.out.println("Edad:" + this.getEdad());
        System.out.println("Cédula:" + this.getCedula());
        System.out.println("Correo electrónico:" + this.getCorreo());
        System.out.println("\n");
    }
}
