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
public class Categoria {
    /*
     * -- Creando la tabla Categoria
     * CREATE TABLE IF NOT EXISTS `Categoria` (
     * `idCat` int(2) NOT NULL,
     * `nomCat` varchar(20) NOT NULL,
     * PRIMARY KEY (`idCat`)
     * );
     */

    private int idCat;
    private String nomCat;

    public Categoria() {
    }

    public Categoria(int idCat, String nomCat) {
        this.idCat = idCat;
        this.nomCat = nomCat;
    }

    public int getIdCat() {
        return idCat;
    }

    public void setIdCat(int idCat) {
        this.idCat = idCat;
    }

    public String getNomCat() {
        return nomCat;
    }

    public void setNomCat(String nomCat) {
        this.nomCat = nomCat;
    }

    @Override
    public String toString() {
        return "{" + "idCat=" + idCat + ", nomCat=" + nomCat + '}';
    }

}
