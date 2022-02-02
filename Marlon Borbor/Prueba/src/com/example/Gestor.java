package com.example;

import java.io.*;
import java.util.Vector;

import static java.lang.System.exit;

public class Gestor {

    Vector<Vehiculo> vehiculos;

    public Gestor() {
        vehiculos = new Vector<Vehiculo>();
    }

    public void iniciar() {
        // Menu
        menu();
    }

    private void imprimir(String cadena) {
        // Imprime en pantalla
        System.out.print(cadena);
    }

    // Funcion que lee por teclado y retorna un String
    private String leer() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String cadena = "";
        try {
            cadena = br.readLine();
        } catch (Exception e) {
            System.out.println("Error al leer");
        }
        return cadena;
    }

    private int leerEntero() {
        int numero = 0;
        do {
            try {
                numero = Integer.parseInt(leer());
            } catch (Exception e) {
                imprimir("Error al leer el numero");
            }
        } while (numero < 0);
        return numero;
    }

    private float leerFlotante() {
        float numero = 0;
        do {
            try {
                numero = Float.parseFloat(leer());
            } catch (Exception e) {
                imprimir("Error al leer el numero");
            }
        } while (numero < 0);
        return numero;
    }

    private boolean leerBooleano() {
        boolean booleano = false;
        boolean error = false;
        do {
            imprimir("s/n: ");
            try {
                String cadena = leer();
                if (cadena.equals("s")) {
                    booleano = true;
                    error = false;
                } else if (cadena.equals("n")) {
                    booleano = false;
                    error = false;
                } else {
                    imprimir("Error al leer el booleano");
                    error = true;
                }
            } catch (Exception e) {
                imprimir("Error al leer el booleano");
                error = true;
            }
        } while (error);
        return booleano;
    }

    private void menu() {
        imprimir("1. Gestionar Vehiculos\n");
        imprimir("2. Gestionar Archivos\n");
        imprimir("3. Gestionar Consultas\n");
        imprimir("0. Salir\n");
        imprimir("Opcion: ");
        int opcion = leerEntero();
        switch (opcion) {
            case 1:
                gestionarVehiculos();
                break;
            case 2:
                gestionarArchivos();
                break;
            case 3:
                gestionarConsultas();
                break;
            case 0:
                // Salir del programa
                exit(0);
                break;
            default:
                imprimir("Opcion no valida");
                menu();
        }
        menu();
    }

    // Funcion que gestiona los vehiculos
    private void gestionarVehiculos() {
        imprimir("1. Agregar Vehiculo\n");
        // imprimir("2. Eliminar Vehiculo\n");
        // imprimir("3. Mostrar Vehiculos\n");
        imprimir("0. Volver\n");
        imprimir("Opcion: ");
        int opcion = leerEntero();
        switch (opcion) {
            case 1:
                agregarVehiculo();
                break;
            /*
            case 2:
                eliminarVehiculo();
                break;
            case 3:
                mostrarVehiculos();
                break;
            */
            case 0:
                break;
            default:
                imprimir("Opcion no valida");
                gestionarVehiculos();
                break;
        }
    }

    // Funcion agregarVehiculo
    private void agregarVehiculo() {
        imprimir("1. Agregar Moto\n");
        imprimir("2. Agregar Camioneta\n");
        imprimir("3. Agregar Coche\n");
        imprimir("4. Agregar Bicicleta\n");
        imprimir("0. Volver\n");
        imprimir("Opcion: ");
        int opcion = leerEntero();
        switch (opcion) {
            case 1:
                agregarMoto();
                break;
            case 2:
                agregarCamioneta();
                break;
            case 3:
                agregarCoche();
                break;
            case 4:
                agregarBicicleta();
                break;
            case 0:
                break;
            default:
                imprimir("Opcion no valida");
                agregarVehiculo();
                break;
        }
    }

    // Funcion agregarMoto
    private void agregarMoto() {

        // Pedir datos
        imprimir("Color: ");
        String color = leer();
        boolean tipo = false;
        do {
            imprimir("Tipo (urbana/deportiva): ");
            String t = leer();
            if (t.equals("urbana")) {
                tipo = true;
                break;
            } else if (t.equals("deportiva")) {
                tipo = false;
                break;
            } else {
                imprimir("Error al leer el tipo");
            }
        } while (true);
        imprimir("Velocidad: ");
        float velocidad = leerFlotante();
        imprimir("Cilindrada: ");
        float cilindrada = leerFlotante();

        // Crear objeto
        Vehiculo moto = new Motocicleta(color, tipo, velocidad, cilindrada);

        // Agregar a la lista
        vehiculos.add(moto);

        // Volver al menu
        gestionarVehiculos();
    }

    // Funcion agregarCamioneta
    private void agregarCamioneta() {

        // Pedir datos
        imprimir("Color: ");
        String color = leer();
        imprimir("Velocidad: ");
        float velocidad = leerFlotante();
        imprimir("Cilindrada: ");
        float cilindrada = leerFlotante();
        imprimir("Carga: ");
        float carga = leerFlotante();

        // Crear objeto
        Vehiculo camioneta = new Camioneta(color, velocidad, cilindrada, carga);

        // Agregar a la lista
        vehiculos.add(camioneta);

        // Volver al menu
        gestionarVehiculos();
    }

    // Funcion agregarCoche
    private void agregarCoche() {

        // Pedir datos
        imprimir("Color: ");
        String color = leer();
        imprimir("Velocidad: ");
        float velocidad = leerFlotante();
        imprimir("Cilindrada: ");
        float cilindrada = leerFlotante();

        // Crear objeto
        Vehiculo coche = new Coche(color, velocidad, cilindrada);

        // Agregar a la lista
        vehiculos.add(coche);

        // Volver al menu
        gestionarVehiculos();
    }

    // Funcion agregarBicicleta
    private void agregarBicicleta() {

        // Pedir datos
        imprimir("Color: ");
        String color = leer();
        boolean tipo = false;
        do {
            imprimir("Tipo (urbana/deportiva): ");
            String t = leer();
            if (t.equals("urbana")) {
                tipo = true;
                break;
            } else if (t.equals("deportiva")) {
                tipo = false;
                break;
            } else {
                imprimir("Error al leer el tipo");
            }
        } while (true);

        // Crear objeto
        Vehiculo bicicleta = new Bicicleta(color, tipo);

        // Agregar a la lista
        vehiculos.add(bicicleta);

        // Volver al menu
        gestionarVehiculos();
    }

    // Funcion que gestiona los archivos binarios
    private void gestionarArchivos() {
        imprimir("1. Cargar Archivo\n");
        imprimir("2. Guardar Archivo\n");
        imprimir("0. Volver\n");
        imprimir("Opcion: ");
        int opcion = leerEntero();
        switch (opcion) {
            case 1:
                cargarArchivo();
                break;
            case 2:
                guardarArchivo();
                break;
            case 0:
                // Volver al menu
                menu();
                break;
            default:
                imprimir("Opcion no valida");
                gestionarArchivos();
                break;
        }
    }

    // Funcion cargarArchivo
    private void cargarArchivo() {

        // Pedir nombre del archivo
        imprimir("Nombre del archivo: ");
        String nombre = leer();

        // Cargar el archivo binario en la lista
        try {
            FileInputStream fis = new FileInputStream(nombre);
            ObjectInputStream ois = new ObjectInputStream(fis);
            vehiculos = (Vector<Vehiculo>) ois.readObject();
            ois.close();
            fis.close();
            imprimir("Archivo cargado");
        } catch (Exception e) {
            imprimir("Error al cargar el archivo");
        }
    }

    // Funcion guardarArchivo
    private void guardarArchivo() {

        // Pedir nombre del archivo
        imprimir("Nombre del archivo: ");
        String nombre = leer();

        // Guardar la lista en el archivo binario
        try {
            FileOutputStream fos = new FileOutputStream(nombre);
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(vehiculos);
            oos.close();
            fos.close();
            imprimir("Archivo guardado");
        } catch (Exception e) {
            imprimir("Error al guardar el archivo");
        }

        // Volver al menu
        menu();
    }

    // Funcion que gestiona las consultas
    private void gestionarConsultas() {
        imprimir("1. Listado de Vehiculos\n");
        imprimir("2. Consultar por ruedas\n");
        imprimir("0. Volver\n");
        imprimir("Opcion: ");
        int opcion = leerEntero();
        switch (opcion) {
            case 1:
                listadoVehiculos(vehiculos);
                break;
            case 2:
                // Pedir el numero de ruedas
                imprimir("Numero de ruedas: ");
                int ruedas = leerEntero();
                consultarRuedas(vehiculos, ruedas);
                break;
            case 0:
                break;
            default:
                imprimir("Opcion no valida");
                gestionarConsultas();
                break;
        }

        // Volver al menu
        menu();
    }

    // Funcion listadoVehiculos
    public void listadoVehiculos(Vector<Vehiculo> v){
        // Recorrer la lista de vehiculos, imprimir el nombre de la clase y los atributos de cada vehiculo
        imprimir("Listado de vehiculos\n");
        for (Vehiculo vehiculo : v) {
            imprimir(vehiculo.toString());
            imprimir("\n");
        }

        // Volver al menu
        gestionarConsultas();
    }

    // Funcion consultarRuedas
    public void consultarRuedas(Vector<Vehiculo> v, int ruedas) {
        // Recorrer la lista de vehiculos, imprimir el vehiculo con las ruedas indicadas y contar cuantos vehiculos hay con esas ruedas
        int contador = 0;
        imprimir("Listado de vehiculos con " + ruedas + " ruedas\n");
        for (Vehiculo vehiculo : v) {
            if (vehiculo.getRuedas() == ruedas) {
                imprimir(vehiculo.toString());
                contador++;
                imprimir("\n");
            }
        }
        imprimir("Hay " + contador + " vehiculos con " + ruedas + " ruedas\n");

        // Volver al menu
        gestionarConsultas();
    }
}
