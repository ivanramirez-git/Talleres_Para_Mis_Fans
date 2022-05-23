
package VO;

import java.util.Date;

public class CuentaVO 
{
    
    private Integer cuentaId;
    private String pelicula;
    private Double precio;
    private String plataforma;
    private Date fvencimiento;
    private Integer cuentasdisponibles;

    public CuentaVO() {
    }

    public CuentaVO(Integer cuentaId, String pelicula, Double precio, String plataforma, Date fvencimiento, Integer cuentasdisponibles) {
        this.cuentaId = cuentaId;
        this.pelicula = pelicula;
        this.precio = precio;
        this.plataforma = plataforma;
        this.fvencimiento = fvencimiento;
        this.cuentasdisponibles = cuentasdisponibles;
    }

    public Integer getCuentaId() {
        return cuentaId;
    }

    public void setCuentaId(Integer cuentaId) {
        this.cuentaId = cuentaId;
    }

    public String getPelicula() {
        return pelicula;
    }

    public void setPelicula(String pelicula) {
        this.pelicula = pelicula;
    }

    public Double getPrecio() {
        return precio;
    }

    public void setPrecio(Double precio) {
        this.precio = precio;
    }

    public String getPlataforma() {
        return plataforma;
    }

    public void setPlataforma(String plataforma) {
        this.plataforma = plataforma;
    }

    public Date getFvencimiento() {
        return fvencimiento;
    }

    public void setFvencimiento(Date fvencimiento) {
        this.fvencimiento = fvencimiento;
    }

    public Integer getCuentasdisponibles() {
        return cuentasdisponibles;
    }

    public void setCuentasdisponibles(Integer cuentasdisponibles) {
        this.cuentasdisponibles = cuentasdisponibles;
    }

    
}
