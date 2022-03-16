/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg20151578099_20191578005;

/**
 *
 * @author aulasingenieria
 */
public class ProcesosUsuario extends Usuario {
    
    private String genero;
    private String deporte;

    public ProcesosUsuario(String genero, String deporte, String identificacion, String nombre, int edad) {
        super(identificacion, nombre, edad);
        this.genero = genero;
        this.deporte = deporte;
    }

    public ProcesosUsuario(String genero, String deporte) {
        this.genero = genero;
        this.deporte = deporte;
    }

    public ProcesosUsuario(String identificacion, String nombre, int edad) {
        super(identificacion, nombre, edad);
    }

    public ProcesosUsuario() {
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public String getDeporte() {
        return deporte;
    }

    public void setDeporte(String deporte) {
        this.deporte = deporte;
    }
    
    
    
}
