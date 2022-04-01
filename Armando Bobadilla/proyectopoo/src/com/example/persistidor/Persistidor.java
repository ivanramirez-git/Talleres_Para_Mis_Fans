package com.example.persistidor;

import com.example.modelo.Boleto;
import com.example.modelo.Factura;
// ObjectOuputStream
import java.io.*;
import java.util.HashMap;
import java.util.Vector;

// Clase Persistidor, guarda en un archivos binarios los datos de la clase Factura y de la Clase padre Boleto
public class Persistidor {
    // Atributos de la clase
    private Vector<Factura> factura_serializable;
    private Vector<Vector<Boleto>> boletos_serializable;

    // Constructor de la clase
    public Persistidor() {
        factura_serializable = new Vector<>();
        boletos_serializable = new Vector<>();
    }

    // Metodo para guardar los datos de la clase Factura en un archivo binario
    public void guardarFacturas(Vector<Factura> facturas) {
        factura_serializable = facturas;
        // Guardar en un archivo binario los datos de la clase Factura
        try {
            FileOutputStream file = new FileOutputStream("factura.dat");
            ObjectOutputStream object = new ObjectOutputStream(file);
            object.writeObject(factura_serializable);
            object.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    // Metodo para guardar los datos de la clase Boleto en un archivo binario
    public void guardarBoletos(Vector<Vector<Boleto>> boletos) {
        boletos_serializable = boletos;
        // Guardar en un archivo binario los datos de la clase Boleto
        try {
            FileOutputStream file = new FileOutputStream("boleto.dat");
            ObjectOutputStream object = new ObjectOutputStream(file);
            object.writeObject(boletos_serializable);
            object.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    // Metodo para recuperar los datos de la clase Factura del archivo binario
    public Vector<Factura> recuperarFactura() {
        Vector<Factura> facturas = new Vector<>();
        try {
            FileInputStream file = new FileInputStream("factura.dat");
            ObjectInputStream object = new ObjectInputStream(file);
            facturas = (Vector<Factura>) object.readObject();
            object.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            // System.out.println("No se encontro el archivo");
            System.out.println("No se encontro el archivo Factura");
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
            // System.out.println("Error al leer el archivo");
            System.out.println("Error al leer el archivo Factura");
        }

        return facturas;
    }

    // Metodo para recuperar los datos de la clase Boleto del archivo binario
    public Vector<Vector<Boleto>> recuperarBoleto() {
        Vector<Vector<Boleto>> boletos = new Vector<>();
        try {
            FileInputStream file = new FileInputStream("boleto.dat");
            ObjectInputStream object = new ObjectInputStream(file);
            boletos = (Vector<Vector<Boleto>>) object.readObject();
            object.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            // System.out.println("No se encontro el archivo");
            System.out.println("No se encontro el archivo Boleto");
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
            // System.out.println("Error al leer el archivo");
            System.out.println("Error al leer el archivo Boleto");
        }
        return boletos;
    }

    public Vector<Object> cargarDatos() {
        Vector<Object> datos = new Vector<>();
        datos.add(recuperarFactura());
        datos.add(recuperarBoleto());
        // System.out.println(datos);
        System.out.println("Datos cargados");
        return datos;
    }
}