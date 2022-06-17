/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

/**
 *
 * @author Jorge Alberto
 */
public class Cliente {
    private int id;
    private int codigo;
 private String apellidop;
  private String apellidom;
   private String nombre;
   private int telefono;
    private String calle;
     private int numextint;
      private String colonia;
       private String ciudad;
       private int cp;
       private String estado;
       private String pais;
       private String correo;

    public Cliente() {
    }

    public Cliente(int id, int codigo, String apellidop, String apellidom, String nombre, int telefono, String calle, int numextint, String colonia, String ciudad, int cp, String estado, String pais, String corre) {
        this.id = id;
        this.codigo = codigo;
        this.apellidop = apellidop;
        this.apellidom = apellidom;
        this.nombre = nombre;
        this.telefono = telefono;
        this.calle = calle;
        this.numextint = numextint;
        this.colonia = colonia;
        this.ciudad = ciudad;
        this.cp = cp;
        this.estado = estado;
        this.pais = pais;
        this.correo = correo;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getApellidop() {
        return apellidop;
    }

    public void setApellidop(String apellidop) {
        this.apellidop = apellidop;
    }

    public String getApellidom() {
        return apellidom;
    }

    public void setApellidom(String apellidom) {
        this.apellidom = apellidom;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getTelefono() {
        return telefono;
    }

    public void setTelefono(int telefono) {
        this.telefono = telefono;
    }

    public String getCalle() {
        return calle;
    }

    public void setCalle(String calle) {
        this.calle = calle;
    }

    public int getNumextint() {
        return numextint;
    }

    public void setNumextint(int numextint) {
        this.numextint = numextint;
    }

    public String getColonia() {
        return colonia;
    }

    public void setColonia(String colonia) {
        this.colonia = colonia;
    }

    public String getCiudad() {
        return ciudad;
    }

    public void setCiudad(String ciudad) {
        this.ciudad = ciudad;
    }

    public int getCp() {
        return cp;
    }

    public void setCp(int cp) {
        this.cp = cp;
    }

    public String getEstado() {
        return estado;
    }

    public void setEstado(String estado) {
        this.estado = estado;
    }

    public String getPais() {
        return pais;
    }

    public void setPais(String pais) {
        this.pais = pais;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String corre) {
        this.correo = correo;
    }
       
}
