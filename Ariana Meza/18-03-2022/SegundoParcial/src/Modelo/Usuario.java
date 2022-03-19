package Modelo;

public class Usuario {

    // id, usuario, nombre, email, password
    private int id;
    private String usuario;
    private String nombre;
    private String email;
    private String password;

    public Usuario(int id, String usuario, String nombre, String email, String password) {
        this.id = id;
        this.usuario = usuario;
        this.nombre = nombre;
        this.email = email;
        this.password = password;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getUsuario() {
        return usuario;
    }

    public void setUsuario(String usuario) {
        this.usuario = usuario;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public boolean validarPassword(String password) {
        return this.password.equals(password);
    }

    public String setPassword(String password) {
        this.password = password;
        return password;
    }

    @Override
    public String toString() {
        return "Usuario{" + "id=" + id + ", usuario=" + usuario + ", nombre=" + nombre + ", email=" + email + '}';
    }
    
}
