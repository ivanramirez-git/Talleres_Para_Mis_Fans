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
    
    private boolean piesCarga;
    
    // Constructor
    public CargaSuelta() {
        super();
    }
    
    public boolean getPiesCarga() {
        return piesCarga;
    }

    public void setPiesCarga(boolean piesCarga) {
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
        String mensaje = "";
        if (this.getPiesCarga() == true) {
            mensaje = "El costo de la carga suelta es de $" + (this.getKg() * 100) + " + $15 por pie";
        } else {
            mensaje = "El costo de la carga suelta es de $" + (this.getKg() * 100);
        }
        return mensaje;
    }
    
}
