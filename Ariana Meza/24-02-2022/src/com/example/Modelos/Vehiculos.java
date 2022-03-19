/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.example.Modelos;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author dell
 */
public class Vehiculos {
    
    
    String tipoVehiculo;
    String año;
    String tipoCambio;
    String adicionales;
    int valorBase;
    private double precioVehi;
    private double precioTotal;
    
    final int aireAcondicionado=460;
    final int sistemaIntegrado=240;
    final int asientosPiel= 70;
    public  Vehiculos(){}

    public Vehiculos(String tipoVehiculo, String año, String tipoCambio, String adicionales) {
        this.tipoVehiculo = tipoVehiculo;
        this.año = año;
        this.tipoCambio = tipoCambio;
        this.adicionales = adicionales;
    }

    public String getTipoVehiculo() {
        return tipoVehiculo;
    }

    public void setTipoVehiculo(String tipoVehiculo) {
        this.tipoVehiculo = tipoVehiculo;
    }

    public String getAño() {
        return año;
    }

    public void setAño(String año) {
        this.año = año;
    }

    public String getTipoCambio() {
        return tipoCambio;
    }

    public void setTipoCambio(String tipoCambio) {
        this.tipoCambio = tipoCambio;
    }

    public String getAdicionales() {
        return adicionales;
    }

    public void setAdicionales(String adicionales) {
        this.adicionales = adicionales;
    }

    public double calcularPrecios(){
        if(tipoVehiculo=="SUV"){
            precioVehi= 24000;
        }else if(tipoVehiculo=="Furgoneta"){
            precioVehi=30000;
        }else if (tipoVehiculo=="Sedan"){
            precioVehi= 18000;
        }
        
        if (año == "2022"){
            precioVehi= precioVehi+500;
        }
        if(tipoCambio== "Automatico"){
            precioVehi= precioVehi+200;
        }else if(tipoCambio=="Manual"){
            precioVehi= precioVehi+50;
        }
        
        if (adicionales== "Aire Acondicionado"){
            precioTotal= precioVehi+aireAcondicionado;
        }if (adicionales=="Sistema Integrado de navegacion"){
            precioTotal= precioVehi+sistemaIntegrado;
        }if(adicionales== "Asientos de Piel"){
            precioTotal= precioVehi+asientosPiel;
        }if(adicionales== "Asientos de Piel" && adicionales == "Sistema Integrado de navegacion"){
            precioTotal= precioVehi+asientosPiel+sistemaIntegrado;
            
        }if(adicionales== "Asientos de Piel"&& adicionales == "Aire Acondicionado"){
            precioTotal= precioVehi+asientosPiel+aireAcondicionado;
        }if(adicionales== "Aire Acondicionado" && adicionales == "Sistema Integrado de navegacion"){
            precioTotal= precioVehi+sistemaIntegrado+aireAcondicionado;
        }if(adicionales== "Asientos de Piel"&& adicionales == "Aire Acondicionado "&& adicionales == "Sistema Integrado de navegacion"){
            precioTotal= precioVehi+asientosPiel+aireAcondicionado+sistemaIntegrado;
        }
        return precioTotal;
    }

    public double calcularPrecio(){
        /*

        TIPO DE VEHICULO PRECIO BASE
        SUV             $24000
        Furgoneta       $30000
        Sedan           $18000

        Si el año es 2022, el precio base aumenta en $500

        TIPO DE CAMBIO PRECIO BASE
        Automatico      $200
        Manual          $50

        ADICIONALES PRECIO BASE
        Aire Acondicionado $460
        Sistema Integrado de navegacion $240
        Asientos de Piel $70

        */

        if(tipoVehiculo=="SUV"){
            precioVehi= 24000;
        } else if(tipoVehiculo=="Furgoneta"){
            precioVehi=30000;
        } else if (tipoVehiculo=="Sedan"){
            precioVehi= 18000;
        }

        if (año == "2022"){
            precioVehi= precioVehi+500;
        }

        if(tipoCambio== "Automatico"){
            precioVehi= precioVehi+200;
        } else if(tipoCambio=="Manual"){
            precioVehi= precioVehi+50;
        }

        if (adicionales== "P1"){
            precioVehi= precioVehi+aireAcondicionado;
        } else if(adicionales=="P2"){
            precioVehi= precioVehi+sistemaIntegrado;
        } else if(adicionales== "P3"){
            precioVehi= precioVehi+asientosPiel;
        } else if(adicionales== "P1,P2"){
            precioVehi= precioVehi+aireAcondicionado+sistemaIntegrado;
        } else if(adicionales== "P1,P3"){
            precioVehi= precioVehi+aireAcondicionado+asientosPiel;
        } else if(adicionales== "P2,P3"){
            precioVehi= precioVehi+sistemaIntegrado+asientosPiel;
        } else if(adicionales== "P1,P2,P3"){
            precioVehi= precioVehi+aireAcondicionado+sistemaIntegrado+asientosPiel;
        }

        System.out.println("El precio total es: " + precioVehi);

        precioTotal= precioVehi;

        return precioTotal;
    }
        @Override
    public String toString() {
        return "Precio Final: " + precioTotal;
    }
    

    }
    
    
    
    
    
    
    
    

    
    
    
    
    

