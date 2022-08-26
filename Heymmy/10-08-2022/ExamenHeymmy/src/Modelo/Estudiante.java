package Modelo;

public class Estudiante {
    private String nombre;
    private String cedula;
    private double notaFinal;

    public Estudiante(String nombre, String cedula, double notaFinal) {
        this.nombre = nombre;
        this.cedula = cedula;
        this.notaFinal = notaFinal;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getCedula() {
        return cedula;
    }

    public void setCedula(String cedula) {
        this.cedula = cedula;
    }

    public double getNotaFinal() {
        return notaFinal;
    }

    public void setNotaFinal(double notaFinal) {
        this.notaFinal = notaFinal;
    }

    public boolean isAprobado() {
        return notaFinal >= 70;
    }

    @Override
    public String toString() {
        return "Estudiante{" + "Nombre=" + nombre + ", Cedula=" + cedula + ", Nota Final=" + notaFinal + ", Aprobado="
                + (isAprobado() ? "SI" : "NO") + '}';
    }
}
