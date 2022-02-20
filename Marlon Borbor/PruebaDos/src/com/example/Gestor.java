package com.example;

import java.io.*;
import java.util.Vector;

public class Gestor {
    // Atributos
    private String nombre;
    private Vector<Campana> campanas;


    // Constructores
    public Gestor() {
        this.nombre = "Rescate Perruno";
        this.campanas = new Vector<Campana>();
    }

    // Metodos publicos
    public void iniciar() {

        // Desea cargar el archivo?
        imprimir("Desea cargar el archivo? (s/n): ");
        char respuesta = leerChar();
        if (respuesta == 's') {
            cargar();
        }

        boolean salir = false;
        while (!salir) {
            menuPrincipal();
            int opcion = leerEntero();
            switch (opcion) {
                case 1:
                    crearCampana();
                    break;
                case 2:
                    hacerDonacion();
                    break;
                case 3:
                    verCampanas();
                    break;
                case 4:
                    verDonaciones();
                    break;
                case 0:
                    salir = true;
                    break;
                default:
                    imprimir("Opcion incorrecta\n");
            }
        }

        // Desea guardar el archivo?
        imprimir("Desea guardar el archivo? (s/n): ");
        respuesta = leerChar();
        if (respuesta == 's') {
            guardar();
        }
    }

    // Metodos privados
    private void menuPrincipal() {
        imprimir("1. Crear campaña de recolección de alimentos\n");
        imprimir("2. Hacer una donación\n");
        imprimir("3. Ver campañas\n");
        imprimir("4. Ver donaciones en una campaña\n");
        imprimir("0. Salir\n");
    }

    private void imprimir(String texto) {
        System.out.print(texto);
    }

    private String leer() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            return br.readLine();
        } catch (IOException e) {
            imprimir("Error al leer, intente de nuevo: ");
            return leer();
        }
    }

    private int leerEntero() {
        String texto = leer();
        try {
            return Integer.parseInt(texto);
        } catch (NumberFormatException e) {
            imprimir("Error al leer, intente de nuevo: ");
            return leerEntero();
        }
    }

    private char leerChar() {
        String texto = leer();
        try {
            // Validamos que sea un caracter
            if (texto.length() == 1) {
                return texto.charAt(0);
            } else {
                imprimir("Error al leer, intente de nuevo: ");
                return leerChar();
            }
        } catch (NumberFormatException e) {
            imprimir("Error al leer, intente de nuevo: ");
            return leerChar();
        }
    }

    // Crear campana
    private void crearCampana() {
        /*
        public Campana(String nombre, String lugar, String fecha, char estado)
         */
        imprimir("Nombre: ");
        String nombre = leer();
        imprimir("Lugar: ");
        String lugar = leer();
        imprimir("Fecha: ");
        String fecha = leer();
        imprimir("Estado (a/i): ");
        char estado = leerChar();
        Campana campana = new Campana(nombre, lugar, fecha, estado);

        // Crear voluntario
        boolean salirVoluntario = false;
        while (!salirVoluntario) {
            // Validar si tiene voluntario
            if(campana.getVoluntarios().size() > 0) {
                imprimir("Ya tiene un voluntario, desea agregar otro? (s/n): ");
                char respuesta = leerChar();
                if (respuesta == 's') {
                    // TODO: Crear voluntario

                    imprimir("Cédula: ");
                    String cedula = leer();
                    imprimir("Apellidos: ");
                    String apellidos = leer();
                    imprimir("Nombres: ");
                    String nombres = leer();
                    imprimir("Fecha de nacimiento: ");
                    String fechaNacimiento = leer();
                    imprimir("Dirección: ");
                    String direccion = leer();
                    imprimir("Usuario: ");
                    String usuario = leer();
                    imprimir("Clave: ");
                    String clave = leer();
                    String nombreCampana = campana.getNombre();
                    Voluntario voluntario = new Voluntario(cedula, apellidos, nombres, fechaNacimiento, direccion, usuario, clave, nombreCampana);
                    campana.agregarVoluntario(voluntario);

                    salirVoluntario = false;
                } else {
                    salirVoluntario = true;
                }
            } else {
                imprimir("No tiene voluntario, agregando uno...\n");
                imprimir("Cédula: ");
                String cedula = leer();
                imprimir("Apellidos: ");
                String apellidos = leer();
                imprimir("Nombres: ");
                String nombres = leer();
                imprimir("Fecha de nacimiento: ");
                String fechaNacimiento = leer();
                imprimir("Dirección: ");
                String direccion = leer();
                imprimir("Usuario: ");
                String usuario = leer();
                imprimir("Clave: ");
                String clave = leer();
                String nombreCampana = campana.getNombre();
                Voluntario voluntario = new Voluntario(cedula, apellidos, nombres, fechaNacimiento, direccion, usuario, clave, nombreCampana);
                campana.agregarVoluntario(voluntario);

                // Preguntar si desea agregar otro voluntario
                imprimir("Desea agregar otro voluntario? (s/n): ");
                char respuesta = leerChar();
                if (respuesta == 's') {
                    salirVoluntario = false;
                } else {
                    salirVoluntario = true;
                }
            }
        }
        // Agregar campana
        campanas.add(campana);
    }

    // Hacer donacion
    private void hacerDonacion() {
        // Listar campanas enumeradas
        imprimir("\nSeleccione una campana: \n");
        int i = 1;
        for (Campana campana : campanas) {
            imprimir("[" + i + "] " + campana.getNombre() + "\n");
            i++;
        }
        imprimir("[" + i + "] Salir\n");
        int opcion = leerEntero();
        if (opcion == i) {
            return;
        }
        Campana campana = campanas.get(opcion - 1);

        // Crear donacion
        /*
            public Donacion(String nombreProducto, int cantidad, Donante donante) {

         */

        // Datos de donacion
        imprimir("Nombre del producto: ");
        String nombreProducto = leer();
        imprimir("Cantidad: ");
        int cantidad = leerEntero();
        imprimir("Cédula del donante: ");
        String cedulaDonante = leer();

        // Buscar donante
        Donante donante = null;

        if(campana.getDonaciones().size() > 0) {
            for(Donacion donacion : campana.getDonaciones()) {
                if(donacion.getDonante().getCedula().equals(cedulaDonante)) {
                    donante = donacion.getDonante();
                } else {
                    imprimir("No se encontró el donante");
                }
            }
        } else {
            imprimir("Primera donación");
        }

        // Crear donante
        /*
            public Donante(String cedula, String apellidos, String nombres, String fechaNacimiento, String direccion, String telefono, String correo) {

         */
        if(donante == null) {
            imprimir("Apellidos: ");
            String apellidos = leer();
            imprimir("Nombres: ");
            String nombres = leer();
            imprimir("Fecha de nacimiento: ");
            String fechaNacimiento = leer();
            imprimir("Dirección: ");
            String direccion = leer();
            imprimir("Teléfono: ");
            String telefono = leer();
            imprimir("Correo: ");
            String correo = leer();
            donante = new Donante(cedulaDonante, apellidos, nombres, fechaNacimiento, direccion, telefono, correo);

        } else {
            imprimir("Donante encontrado: " + donante.toString());
        }

        // Agregar donante a donacion
        Donacion donacion = new Donacion(nombreProducto, cantidad, donante);

        // Agregar donacion a campana
        campana.agregarDonacion(donacion);
    }

    // Ver campanas
    private void verCampanas() {
        // Imprimir
        for (Campana campana : campanas) {
            imprimir(campana.toString() + "\n");
        }
    }

    // Ver donaciones
    private void verDonaciones() {
        // Listar campanas enumeradas
        imprimir("\nSeleccione una campana: \n");
        int i = 1;
        for (Campana campana : campanas) {
            imprimir("[" + i + "] " + campana.getNombre() + "\n");
            i++;
        }
        imprimir("[" + i + "] Salir\n Seleccione una opción: ");
        int opcion = leerEntero();
        if (opcion == i) {
            return;
        }
        Campana campana = campanas.get(opcion - 1);

        // Donaciones de la campana
        imprimir("Donaciones de la campana: " + campana.getNombre() + "\n");
        for (Donacion donacion : campana.getDonaciones()) {
            imprimir(donacion.toString() + "\n");
        }
    }

    // Archivos de Objeto
    private void guardar() {

        // Pedimos el nombre del archivo
        imprimir("Nombre del archivo: ");
        String nombreArchivo = leer();

        // Guardamos el vector en un archivo binario
        try {
            FileOutputStream fos = new FileOutputStream(nombreArchivo);
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(campanas);
            oos.close();
            fos.close();
            imprimir("Archivo guardado\n");
        } catch (IOException e) {
            imprimir("Error al guardar el archivo\n");
        }
    }

    private void cargar() {
        // Pedimos el nombre del archivo
        imprimir("Nombre del archivo: ");
        String nombreArchivo = leer();

        // Cargamos el vector desde un archivo binario
        try {
            FileInputStream fis = new FileInputStream(nombreArchivo);
            ObjectInputStream ois = new ObjectInputStream(fis);
            campanas = (Vector<Campana>) ois.readObject();
            ois.close();
            fis.close();
            imprimir("Archivo cargado\n");
        } catch (IOException e) {
            imprimir("Error al cargar el archivo\n");
        } catch (ClassNotFoundException e) {
            imprimir("Error, la clase no existe en el archivo " + nombreArchivo + "\n");
        }
    }

    // ToString

}
