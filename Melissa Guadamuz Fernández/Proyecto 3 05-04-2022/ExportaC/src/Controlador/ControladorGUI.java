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
package Controlador;

import java.util.ArrayList;

import Modelo.Cliente;
import Modelo.Cotizacion;
import Persistidor.Persistidor;
import Vista.Clientes;

/**
 *
 * @author melig
 */
public class ControladorGUI {

    // Lista Clientes
    private ArrayList<Cliente> clientes;

    // Lista Exportaciones
    private ArrayList<Cotizacion> exportaciones;

    // Constructor
    public ControladorGUI() {

        clientes = Persistidor.cargarClientes();
        exportaciones = Persistidor.cargarExportaciones();

        if (clientes == null) {
            clientes = new ArrayList<>();
            exportaciones = new ArrayList<>();
        }

        if (exportaciones == null) {            
            exportaciones = new ArrayList<>();
        }

    }

    public void iniciar() {
        Clientes c = new Clientes(this);
        c.setVisible(true);
    }
}
