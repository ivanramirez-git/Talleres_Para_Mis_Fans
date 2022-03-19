package Modelo;

public class Administrador extends Usuario {

    // fecha_de_creacion, creado_por_id_administrador
    private String fecha_de_creacion;
    private int creado_por_id_administrador;
    private boolean permisoSalones;
    private boolean permisoClientes;
    private boolean permisoReservaciones;
    private boolean permisoUsuarios;

    public Administrador(int id, String usuario, String nombre, String email, String password, String fecha_de_creacion, int creado_por_id_administrador) {
        super(id, usuario, nombre, email, password);
        this.fecha_de_creacion = fecha_de_creacion;
        this.creado_por_id_administrador = creado_por_id_administrador;
        this.permisoSalones = false;
        this.permisoClientes = false;
        this.permisoReservaciones = false;
        this.permisoUsuarios = false;
    }

    public String getFecha_de_creacion() {
        return fecha_de_creacion;
    }

    public void setFecha_de_creacion(String fecha_de_creacion) {
        this.fecha_de_creacion = fecha_de_creacion;
    }

    public int getCreado_por_id_administrador() {
        return creado_por_id_administrador;
    }

    public void setCreado_por_id_administrador(int creado_por_id_administrador) {
        this.creado_por_id_administrador = creado_por_id_administrador;
    }

    public boolean isPermisoSalones() {
        return permisoSalones;
    }

    public void setPermisoSalones(boolean permisoSalones) {
        this.permisoSalones = permisoSalones;
    }

    public boolean isPermisoClientes() {
        return permisoClientes;
    }

    public void setPermisoClientes(boolean permisoClientes) {
        this.permisoClientes = permisoClientes;
    }

    public boolean isPermisoReservaciones() {
        return permisoReservaciones;
    }

    public void setPermisoReservaciones(boolean permisoReservaciones) {
        this.permisoReservaciones = permisoReservaciones;
    }

    public boolean isPermisoUsuarios() {
        return permisoUsuarios;
    }

    public void setPermisoUsuarios(boolean permisoUsuarios) {
        this.permisoUsuarios = permisoUsuarios;
    }

    @Override
    public String toString() {
        return "Administrador{" + "fecha_de_creacion=" + fecha_de_creacion + ", creado_por_id_administrador=" + creado_por_id_administrador + '}';
    }
    
}
