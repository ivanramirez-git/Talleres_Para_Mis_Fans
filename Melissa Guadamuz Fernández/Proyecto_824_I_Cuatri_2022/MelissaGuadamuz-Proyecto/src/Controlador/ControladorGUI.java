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
import Modelo.Exportacion;
import Persistidor.Persistidor;
import Vista.Clientes;
import Vista.Exportaciones;

/**
 *
 * @author melig
 */
public class ControladorGUI {

    // Lista Clientes
    private ArrayList<Cliente> clientes;

    // Lista Exportaciones
    private ArrayList<Exportacion> exportaciones;

    // Constructor
    public ControladorGUI() {

        // Cargar la lista desde el archivo de clientes
        clientes = Persistidor.cargarClientes();
        // Cargar la lista desde el archivo de exportaciones
        exportaciones = Persistidor.cargarExportaciones();

        // Si no encontro datos de clientes
        if (clientes == null) {
            // Crear una nueva lista de clientes
            clientes = new ArrayList<>();
            // Y crear una nueva lista de exportaciones
            exportaciones = new ArrayList<>();
        }

        // Si no encontro datos de exportaciones
        if (exportaciones == null) {            
            // Crear una nueva lista de exportaciones
            exportaciones = new ArrayList<>();
        }

        // Mostrar Clientes
        // System.out.println("Clientes: ");
        for (Cliente c : clientes) {
            // System.out.println(c.toString());            
        }
        // Mostrar Exportaciones
        // System.out.println("Exportaciones: ");
        for (Exportacion e : exportaciones) {
            // System.out.println(e.toString());            
        }


    }

    // Inicio del programa
    public void iniciar() {
        Clientes c = new Clientes(this);
        c.setVisible(true);
    }

    // Agregar nuevo cliente
    public void agregarCliente(Cliente c) {
        // Agregar cliente
        clientes.add(c);
        // Persistir
        Persistidor.guardarClientes(clientes);
    }

    // Agregar nueva exportacion
    public void agregarExportacion(Exportacion e) {
        // Agregar exportacion
        exportaciones.add(e);
        // Persistir
        Persistidor.guardarExportaciones(exportaciones);
    }

    // Devolver el numero de exportaciones de un cliente
    public int nExportaciones(String identificacion) { 
        // Variable del contador
        int count = 0;
        // Recorrer lista de exportaciones
        for (Exportacion c : exportaciones) {
            // Si la identificacion del cliente es igual a la identificacion de la exportacion
            if(c.getIdCliente().equals(identificacion)){
                // Aumentar contador
                count++;
            }            
        }
        // Devolver contador
        return count;
    }
    
    // Eliminar exportacion
    public boolean eliminarExportacion(int id, String identificacionCliente){
        // Buscar exportacion
        for (Exportacion e : exportaciones) {
            // Si encontramos la exportacion
            if (e.getId() == id && e.getIdCliente().equals(identificacionCliente)) {
                // Eliminarla
                exportaciones.remove(e);
                // Persistir
                Persistidor.guardarExportaciones(exportaciones);
                // Retornar true
                return true;
            }
        }
        // Retornar false
        return false;
    }

    // Eliminar cliente, si este no tiene exportaciones
    public boolean eliminarCliente(String actionCommand) {
        // Buscar cliente
        for (Cliente c : clientes) {
            // Si encontramos el cliente
            if (c.getIdentificacion().equals(actionCommand)) {
                // Si no tiene exportaciones
                if (nExportaciones(c.getIdentificacion()) == 0) {
                    // Eliminarlo
                    clientes.remove(c);                
                    // Persistir
                    Persistidor.guardarClientes(clientes);
                    // Retornar true
                    return true;
                } else {
                    // Retornar false
                    return false;
                }
            }
        }
        // Retornar false 
        return false;
    }

    // Listar clientes
    public ArrayList<Cliente> listarClientes() {
        return clientes;
    }

    // Listar exportaciones
    public ArrayList<Exportacion> listarExportaciones() {
        return exportaciones;
    }

    // Mostrar exportaciones de un cliente
    public void mostrarExportaciones(String identificacion) {
        Exportaciones e = new Exportaciones(this, identificacion);
        e.setVisible(true);
    }

    // Buscar cliente por identificacion
    public Cliente buscarCliente(String identificacion) {
        for (Cliente c : clientes) {
            if (c.getIdentificacion().equals(identificacion)) {
                return c;
            }
        }
        return null;
    }

    // Buscar exportacion por id y identificacion del cliente 
    public Exportacion buscarExportacion(int id, String identificaion) {
        // System.out.println("id: " + id + ", identificacion: " + identificaion); 
        for (Exportacion e : exportaciones) {
            // System.out.println("Exportacion: " + e.toString());
            if (e.getId() == id && e.getIdCliente().equals(identificaion)) {
                return e;
            }
        }
        return null;
    }   

}
