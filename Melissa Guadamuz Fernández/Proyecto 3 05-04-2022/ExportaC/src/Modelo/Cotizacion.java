/*
 Universidad Estatal a Distancia
Estudiante:Melissa Guadamuz Fernández
Cedula:113870559
Centro Universitario San José
Grupo # 1
Tutor JOSE MANUEL SALAZAR HERRERA
Tarea#1
Primer Cuatrimestre 2022
 */
package Modelo;

import java.time.LocalDate;

/**
 *
 * @author melig
 */
public class Cotizacion {
    
   
    // Identificador de cotización: Debe ser un número aletorio entre 0 y 1000.
    protected int id;
    // Fecha de la cotización: Valor que almacena la fecha del día en que se realizó la cotización, debe ser igual a la fecha de ejecución del programa.
    protected String fecha;
    // Kilogramos a exportar: Corresponde un valor en kilogramos que puede contener decimales. El valor mínimo permitido es 1 Kilogramo.
    protected double kg;
    /*
    Zona de la Exportación (9 Zonas):
        - Nueva Inglaterra (Maine, Nuevo Hampshire, Vermont, Massachusetts, Connecticut, Rhode Island).
        - Atlántico Medio (Nueva York, Pensilvania, Nueva Jersey).
        - Atlántico Sur (Maryland, Delaware, Virginia Occidental, Virginia, Carolina del Norte, Carolina del Sur, Georgia, Florida).
        - Centro Norte Oriental (Michigan, Wisconsin, Illinois, Indiana, Ohio) o Centro Sur Oriental (Kentucky, Tennessee, Alabama, Misisipi).
        - Centro Norte Occidental (Minnesota, Dakota del Norte, Dakota del Sur, Iowa, Nebraska, Misuri, Kansas).
        - Centro Sur Occidental (Arkansas, Oklahoma, Texas, Luisiana).
        - Montaña (Montana, Idaho, Wyoming, Colorado, Utah, Nevada, Arizona, Nuevo México).
        - Pacífico (Alaska, Washington, Oregón, California, Hawái).
    */
    protected String zona;
    // Dirección de Entrega: Corresponde a una dirección física dentro de los EEUU para donde se entregara la carga. La misma debe al menos tener 20 Caracteres alfanuméricos, con la finalidad de ser lo más específico.
    protected String direccion;
    
    // Tipo de Servicio Barco o Avion
    protected boolean tipoServicio;

    // Constructor de la clase Cotización.
    public Cotizacion() {
        this.id = (int) (Math.random() * 1000);
        this.fecha = LocalDate.now().toString();
        this.kg = 0;
        this.zona = "";
        this.direccion ="";
    }

    // Método que retorna el identificador de la cotización.
    public int getId() {
        return id;
    }

    // Método que retorna la fecha de la cotización.
    public String getFecha() {
        return fecha;
    }

    // Método que retorna el valor en kilogramos que se desea exportar.
    public double getKg() {
        return kg;
    }

    // Método que retorna la zona de la exportación.
    public String getZona() {
        return zona;
    }

    // Método que retorna la dirección de entrega.
    public String getDireccion() {
        return direccion;
    }

    // Método que modifica el identificador de la cotización.
    public void setId(int id) {
        this.id = id;
    }

    // Método que modifica la fecha de la cotización.
    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    // Método que modifica el valor en kilogramos que se desea exportar.
    public void setKg(double kg) {
        this.kg = kg;
    }

    // Método que modifica la zona de la exportación.
    public void setZona(String zona) {
        this.zona = zona;
    }

    // Método que modifica la dirección de entrega.
    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    // Método que retorna el tipo de servicio que se desea realizar.
    public String getTipoServicio() {
        if (tipoServicio) {
            return "Barco";
        } else {
            return "Avion";
        }
    }

    // Método que modifica el tipo de servicio que se desea realizar.
    public void setTipoServicio(boolean tipoServicio) {
        this.tipoServicio = tipoServicio;
    }

    // Método que retorna una cadena de caracteres con la información de la cotización.
    @Override
    public String toString() {
        return "Cotización: " + " Id:" + id + ", Fecha: " + fecha + ", Kg: " + kg + ", Zona: " + zona + ", Direccion: " + direccion +  ", Tipo de Servicio: " + getTipoServicio();
    }

    // Calcula el precio de la cotización.

    /* El costo de la exportación es de $75 dólares por Kilogramo.
        Conversiones:
        Medida                      Formula de Conversión
        Kilogramos a gramos         Valor en Kg * 1.000
        Kilogramos a libras         Valor en Kg * 2.20462
        Kilogramos a toneladas      Valor en Kg / 1000.
    */
    public String calcularExportacion() {
        // Dividir el total de kilogramos en toneladas y lo que sobre en libras y lo que sobre en gramos.
        double toneladas;
        int ton = 0;
        double libras;
        int lib = 0;
        double gramos;
        int gra = 0;
        double exedente = this.kg;
        
        // Intentar convertir toneladas
        toneladas = exedente / 1000;
        if(toneladas > 0){
            // Sacar modulo
            ton = (int) toneladas;
            exedente = toneladas - (double) ton;
            exedente = exedente * 1000;
        }
        
        libras = exedente * 2.20462;
        if(libras > 0){
            // Sacar modulo
            lib = (int) libras;
            exedente = libras - (double) lib;
            exedente = exedente / 2.20462;
        }
        
        gramos = exedente * 1000;
        if(gramos > 0){
            // Sacar modulo
            gra = (int) gramos;
            exedente = gramos - (double) gra;
            exedente = exedente / 1000;
        }
        
        System.out.print(exedente);
        
        // Calculo de la cantidad de toneladas.
        return "Calculo de exportacion: Toneladas: "+ton+", Libras: "+lib+", Gramos: "+gra+".";
    } 
}
