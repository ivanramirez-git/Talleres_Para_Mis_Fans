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
package Persistidor;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

import Modelo.Cliente;
import Modelo.Cotizacion;

/**
 *
 * @author melig
 */
public class Persistidor {

    // Constante: clientes_exportaciones.dat
    public static final String CLIENTES_EXPORTACIONES = "clientes_exportaciones.dat";
    // Constante: exportaciones_aprobadas.dat
    public static final String EXPORTACIONES_APROBADAS = "exportaciones_aprobadas.dat";

    // Funcion que guarda los datos de una lista de clientes en un archivo binario
    public static boolean guardarClientes(ArrayList<Cliente> clientes) {
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(CLIENTES_EXPORTACIONES));
            oos.writeObject(clientes);
            oos.close();
            return true;
        } catch (IOException ex) {
            return false;
        }
    }

    // Funcion que guarda los datos de una lista de exportaciones en un archivo binario
    public static boolean guardarExportaciones(ArrayList<Cliente> exportaciones) {
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(EXPORTACIONES_APROBADAS));
            oos.writeObject(exportaciones);
            oos.close();
            return true;
        } catch (IOException ex) {
            return false;
        }
    }

    // Funcion que carga los datos de una lista de clientes desde un archivo binario
    public static ArrayList<Cliente> cargarClientes() {
        try {
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream(CLIENTES_EXPORTACIONES));
            ArrayList<Cliente> clientes = (ArrayList<Cliente>) ois.readObject();
            ois.close();
            return clientes;
        } catch (IOException | ClassNotFoundException ex) {
            return null;
        }
    }

    // Funcion que carga los datos de una lista de exportaciones desde un archivo binario
    public static ArrayList<Cotizacion> cargarExportaciones() {
        try {
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream(EXPORTACIONES_APROBADAS));
            ArrayList<Cotizacion> exportaciones = (ArrayList<Cotizacion>) ois.readObject();
            ois.close();
            return exportaciones;
        } catch (IOException | ClassNotFoundException ex) {
            return null;
        }
    }
}
