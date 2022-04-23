
public class Estudiante {
    
    // Atributos
    private String nombre;
    private String apellido;
    private int edad;
    private int cedula;
    private boolean calificacion;
    private int calificacionNota;
    
    // Constructor
    public Estudiante(String nombre, String apellido, int edad, int cedula) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.edad = edad;
        this.cedula = cedula;
    }

    public boolean isCalificacion() {
        return calificacion;
    }

    public int getCalificacion() {
        return calificacionNota;
    }

    public String getNombre() {
        return nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public int getEdad() {
        return edad;
    }

    public int getCedula() {
        return cedula;
    }

    public void setCalificacion(boolean b) {
        this.calificacion = b;
    }

    public void setCalificacionNota(int calificacion) {
        this.calificacionNota = calificacion;
    }

    public int getCalificacionNota() {
        return calificacionNota;
    }

}
