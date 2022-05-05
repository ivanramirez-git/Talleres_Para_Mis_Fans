/*
 * Universidad Estatal a Distancia
Estudiante:Melissa Guadamuz Fernández
Cedula:113870559
Centro Universitario San José
Grupo # 1
Tutor JOSE MANUEL SALAZAR HERRERA
Tarea#1
Primer Cuatrimestre 2022
 */
package Modelo;

import java.io.Serializable;

/**
 *
 * @author melig
 */
public class CargaPesada extends Exportacion implements Serializable {
    private String tipoCarga; // Tipo de Carga: Contenedor Refrigerado, Contenedor no refrigerado y Carga
                              // embalada.
    private boolean piesContenedor; // Pies del contenedor: 20 o 40 pies.

    // Constructor
    public CargaPesada() {
        super();
    }

    public CargaPesada(Exportacion c) {
        this.id = c.id;
        this.fecha = c.fecha;
        this.kg = c.kg;
        this.direccion = c.direccion;
        this.tipoServicio = c.tipoServicio;        
        this.idCliente=c.idCliente;
    }

    public String getTipoCarga() {
        return tipoCarga;
    }

    public void setTipoCarga(String tipoCarga) {
        this.tipoCarga = tipoCarga;
    }

    public boolean getPiesContenedor() {
        return piesContenedor; // true: 20 pies, false: 40 pies.
    }

    public void setPiesContenedor(boolean piesContenedor) {
        this.piesContenedor = piesContenedor;
    }

    /*
     * calcularExportacion: Este cálculo se genera según lo siguiente:
     * • Un contenedor 40 pies vacío tiene un peso o tara de 3.750 kg y
     * admite una carga de alrededor de 29 toneladas (29.000 kg), lo
     * cual los primeros 3.750 kg se cobraran a $20 dólares, y a partir
     * del kilo 3751 se cobrara a $ 75 dólares. Servicio exclusivo por
     * barco.
     * • Un contenedor 20 pies vacío tiene un peso o tara de 1.500 kg y
     * admite una carga de alrededor de 28 toneladas (28.000 kg), lo
     * cual los primeros 1500 kg se cobraran a $20 dólares, y a partir
     * del kilo 1501 se cobrara a $ 85 dólares. Servicio exclusivo por
     * barco.
     * • La carga embalada se cobrara por Kilo en barco a $ 75 dólares o
     * en avión $125 el kilo. Esta modalidad es la única que permite a
     * nivel de carga pesada escoger si se envía por avión o por barco.
     * • Los contenedores no pueden superar las cargas máximas
     * indicadas.
     */

    @Override
    public String calcularExportacion() {
        double precio = 0;
        if ("Carga embalada".equals(this.getTipoCarga())) {
            if ("Avion".equals(this.getTipoServicio())) {
                return super.calcularExportacion() + " Costo: "+ "El costo de su envío es de $" + 125 * this.getKg() + " dólares.";
            } else {
                return super.calcularExportacion() + " Costo: "+ "El costo de su envío es de $" + 75 * this.getKg() + " dólares.";
            }
        } else {
            if (this.getPiesContenedor() == true) {

                if (this.getKg() < 28000) {
                    if (this.getKg() < 1500) {
                        precio = (20 * this.getKg());
                    } else {
                        precio = (20 * 1500) + (85 * (this.getKg() - 1500));
                    }
                } else {
                    return "Error el peso de la carga supera los 28 toneladas.";
                }
            } else {
                if (this.getKg() < 29000) {
                    if (this.getKg() < 3750) {
                        precio = (20 * this.getKg());
                    } else {
                        precio = (20 * 3750) + (75 * (this.getKg() - 3750));
                    }
                } else {
                    return "Error el peso de la carga supera los 29 toneladas.";
                }
            }
        }
        return super.calcularExportacion() + " Costo: "+ "El costo de su envío es de $" + precio + " dólares.";
    }
}