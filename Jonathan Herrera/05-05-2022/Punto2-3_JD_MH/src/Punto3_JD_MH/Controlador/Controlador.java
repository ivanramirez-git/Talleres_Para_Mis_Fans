/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Punto3_JD_MH.Controlador;

import java.util.ArrayList;

import Punto3_JD_MH.Modelo.Figura;
import Punto3_JD_MH.Vista.CrearFigura;
import Punto3_JD_MH.Vista.TablaFiguras;

/**
 *
 * @author User
 */
public class Controlador {
    private ArrayList<Figura> figuras;
    public TablaFiguras tablaFiguras;

    public Controlador() {
        this.figuras = new ArrayList<Figura>();
        this.tablaFiguras = new TablaFiguras(this);
    }

    public ArrayList<Figura> getFiguras() {
        return figuras;
    }

    public void setFiguras(ArrayList<Figura> figuras) {
        this.figuras = figuras;
    }

    public ArrayList<Figura> getFiguras(String nombre) {
        ArrayList<Figura> figuras = new ArrayList<Figura>();
        for (Figura f : this.figuras) {
            if (f.getNombre().equals(nombre)) {
                figuras.add(f);
            }
        }
        return figuras;
    }

    public void agregarFigura(Figura figura) {
        this.figuras.add(figura);
    }

    public Figura getFigura(int index) {
        return this.figuras.get(index);
    }
    
    public double promedioAreas() {
        double suma = 0;
        for (Figura figura : this.figuras) {
            suma += figura.calcularArea();
        }
        return suma / this.figuras.size();
    }

    public void ingresarFigura(){
        CrearFigura crearFigura = new CrearFigura(this);
        crearFigura.setVisible(true);
    }

    public void iniciar() {
        tablaFiguras.setVisible(true);
    }
}


// Una clase Abstracta es una clase que no puede ser instanciada, es decir, no se puede crear un objeto de ella.
// Una interfaz es una clase que solo contiene la definición de métodos, estos métodos deben ser implementados por una clase adicional.