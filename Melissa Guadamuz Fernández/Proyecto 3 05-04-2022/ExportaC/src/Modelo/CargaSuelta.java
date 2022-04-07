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

/**
 *
 * @author melig
 */
public class CargaSuelta extends Cotizacion {
    
    private double piesCarga;
    
    // Constructor
    public CargaSuelta() {
        super();
    }

    public CargaSuelta(Cotizacion c) {
        this.id=c.id;
        this.fecha=c.fecha;
        this.kg=c.kg;
        this.direccion=c.direccion;
        this.tipoServicio=c.tipoServicio;
    }
    
    public double getPiesCarga() {
        return piesCarga;
    }

    public void setPiesCarga(double piesCarga) {
        this.piesCarga = piesCarga;
    }    
    
    /*
    calcularExportacion: se aplica un costo adicional de $15 por pie a
    aquellos paquetes que superen los 18 pies.
    
    Los montos del servicio de carga suelta es el siguiente:
        Tipo de Envió Monto por Kilogramo
        Avión $100 + adicional si supera los 18
        pies
        Barco $50 + adicional si supera los 18
        pies
    */

    @Override
    public String calcularExportacion() {
        if(this.getPiesCarga() > 18) {
            if("Avion".equals(this.getTipoServicio())) {
                return super.calcularExportacion() + " Costo: "+ "El costo de su envío es de $" + (100 + 15) * this.getKg() + " dólares.";
            } else {
                return super.calcularExportacion() + " Costo: "+ "El costo de su envío es de $" + (50 + 15) * this.getKg() + " dólares.";
            }
        } else {
            if("Avion".equals(this.getTipoServicio())) {
                return super.calcularExportacion() + " Costo: "+ "El costo de su envío es de $" + 100 * this.getKg() + " dólares.";
            } else {
                return super.calcularExportacion() + " Costo: "+ "El costo de su envío es de $" + 50 * this.getKg() + " dólares.";
            }
        }
    }

}
