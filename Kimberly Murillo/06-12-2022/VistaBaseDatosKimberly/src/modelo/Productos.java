/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package modelo;

/**
 *
 * @author nitro5
 */
public class Productos {
    /*
     * -- Creando la tabla Productos
     * CREATE TABLE IF NOT EXISTS `Productos` (
     * `idProd` int(11) NOT NULL,
     * `nomProd` varchar(30) NOT NULL,
     * `idCat` int NOT NULL,
     * `precCosto` int NOT NULL,
     * `precVenta` int NOT NULL,
     * `existencias` int NOT NULL,
     * PRIMARY KEY (`idProd`),
     * FOREIGN KEY (`idCat`) REFERENCES `Categoria`(`idCat`)
     * );
     */
    private int idProd;
    private String nomProd;
    private int idCat;
    private int precCosto;
    private int precVenta;

    public Productos() {
    }

    public Productos(int idProd, String nomProd, int idCat, int precCosto, int precVenta) {
        this.idProd = idProd;
        this.nomProd = nomProd;
        this.idCat = idCat;
        this.precCosto = precCosto;
        this.precVenta = precVenta;
    }

    public int getIdProd() {
        return idProd;
    }

    public void setIdProd(int idProd) {
        this.idProd = idProd;
    }

    public String getNomProd() {
        return nomProd;
    }

    public void setNomProd(String nomProd) {
        this.nomProd = nomProd;
    }

    public int getIdCat() {
        return idCat;
    }

    public void setIdCat(int idCat) {
        this.idCat = idCat;
    }

    public int getPrecCosto() {
        return precCosto;
    }

    public void setPrecCosto(int precCosto) {
        this.precCosto = precCosto;
    }

    public int getPrecVenta() {
        return precVenta;
    }

    public void setPrecVenta(int precVenta) {
        this.precVenta = precVenta;
    }

    @Override
    public String toString() {
        return "{" + "idProd=" + idProd + ", nomProd=" + nomProd + ", idCat=" + idCat + ", precCosto=" + precCosto + ", precVenta=" + precVenta + '}';
    }

}
