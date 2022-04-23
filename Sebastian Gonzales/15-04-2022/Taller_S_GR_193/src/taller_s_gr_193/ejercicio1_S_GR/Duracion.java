/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package taller_s_gr_193.ejercicio1_S_GR;

import java.time.LocalDateTime;

/**
 *
 * @author User
 */
public class Duracion {
    // Horas
    private int horas;
    // Minutos
    private int minutos;
    
    // Constructor, se define una hora enviada por parametro
    public Duracion(int h, int m){
        this.horas = h;
        this.minutos = m;        
    }
    
    // Constructor, se define una hora actual
    public Duracion(){
        LocalDateTime ahora = LocalDateTime.now();
        this.horas = ahora.getHour();
        this.minutos = ahora.getMinute();       
    }

    public int getHoras() {
        return horas;
    }

    public void setHoras(int horas) {
        this.horas = horas;
    }

    public int getMinutos() {
        return minutos;
    }

    public void setMinutos(int minutos) {
        this.minutos = minutos;
    }
    
    // Retorna la duracion restada
    Duracion resta(Duracion d){
        int h = this.horas - d.horas;
        int m = this.minutos - d.minutos;
        if(m < 0){
            h--;
            m = 60 + m;
        }
        return new Duracion(h, m);
    }

    @Override
    public String toString() {
        String m;
        if(this.horas < 10){
            m = "0" + this.horas;
        }else{
            m = "" + this.horas;
        }
        if(this.minutos < 10){
            m += ":0" + this.minutos;
        }else{
            m += ":" + this.minutos;
        }
        return m;
    }
}
