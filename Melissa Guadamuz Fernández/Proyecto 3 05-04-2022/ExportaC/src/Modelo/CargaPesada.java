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
public class CargaPesada extends Cotizacion {
    private String tipoCarga;
    private boolean piesContenedor;

    // Constructor    
    public CargaPesada() {
        super();
    }
    
    public String getTipoCarga() {
        return tipoCarga;
    }

    public void setTipoCarga(String tipoCarga) {
        this.tipoCarga = tipoCarga;
    }

    public boolean getPiesContenedor() {
        return piesContenedor;
    }

    public void setPiesContenedor(boolean piesContenedor) {
        this.piesContenedor = piesContenedor;
    }
    
    /*
    calcularExportacion: Este cálculo se genera según lo siguiente:
        • Un contenedor 40 pies vacío tiene un peso o tara de 3.750 kg y
        admite una carga de alrededor de 29 toneladas (29.000 kg), lo
        cual los primeros 3.750 kg se cobraran a $20 dólares, y a partir
        del kilo 3751 se cobrara a $ 75 dólares. Servicio exclusivo por
        barco.
        • Un contenedor 20 pies vacío tiene un peso o tara de 1.500 kg y
        admite una carga de alrededor de 28 toneladas (28.000 kg), lo
        cual los primeros 1500 kg se cobraran a $20 dólares, y a partir
        del kilo 1501 se cobrara a $ 85 dólares. Servicio exclusivo por
        barco.
        • La carga embalada se cobrara por Kilo en barco a $ 75 dólares o
        en avión $125 el kilo. Esta modalidad es la única que permite a
        nivel de carga pesada escoger si se envía por avión o por barco.
        • Los contenedores no pueden superar las cargas máximas
        indicadas.
    */

    @Override
    public String calcularExportacion() {
        double valor = 0;
        if(this.getTipoCarga().equals("40 pies")){
            if(this.getPiesContenedor()){
                if(this.getKg() <= 29000){
                    valor = this.getKg() * 0.20;
                }else{
                    valor = (this.getKg() - 29000) * 0.75 + 29000 * 0.20;
                }
            }else{
                if(this.getKg() <= 3751){
                    valor = this.getKg() * 0.20;
                }else{
                    valor = (this.getKg() - 3751) * 0.75 + 3751 * 0.20;
                }
            }
        }else{
            if(this.getPiesContenedor()){
                if(this.getKg() <= 28000){
                    valor = this.getKg() * 0.20;
                }else{
                    valor = (this.getKg() - 28000) * 0.85 + 28000 * 0.20;
                }
            }else{
                if(this.getKg() <= 1501){
                    valor = this.getKg() * 0.20;
                }else{
                    valor = (this.getKg() - 1501) * 0.85 + 1501 * 0.20;
                }
            }
        }
        return "El valor de la carga pesada es: $" + valor;
    }
    
}