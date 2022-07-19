package main.java.proyecto.HDA;

public class Cliente {

    private int idCliente;

    private String nombre;

    private String apellido;

    private String numeroTelefono;

    private String email;

    public Cliente() {
    }

    public int getId() {
        return idCliente;
    }

    public void setId(int id) {
        this.idCliente= id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    public String getNumeroTelefono() {
        return numeroTelefono;
    }

    public void setNumeroTelefono(String numeroTelefono) {
        this.numeroTelefono = numeroTelefono;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "Cliente{" + "id=" + idCliente + ", nombre=" + nombre + ", apellido=" + apellido + ", numeroTelefono=" + numeroTelefono + ", email=" + email + '}';
    }

}
