package com.example.controlador;

import com.example.modelo.Boleto;
import com.example.modelo.ClaseTurista;
import com.example.modelo.Factura;
import com.example.modelo.PrimeraClase;
import com.example.persistidor.Persistidor;
import com.example.vista.Vista;

import java.util.Vector;

public class Controlador {

    // Constante iva
    private static final double IVA = 0.16;

    // MVCP
    private Persistidor p;
    private Vista v;

    // Vectores
    private Vector<Factura> facturas;
    private Vector<Vector<Boleto>> boletos;

    // Constructor
    public Controlador() {
        facturas = new Vector<Factura>();
        boletos = new Vector<Vector<Boleto>>();

        // Boletos[0] = Clase turista
        // Boletos[1] = Primera Clase
        boletos.add(new Vector<Boleto>());
        boletos.add(new Vector<Boleto>());

        p = new Persistidor();
        v = new Vista();

        // Cargar datos
         Vector<Object> o = p.cargarDatos();
         facturas = (Vector<Factura>) o.get(0);
         boletos = (Vector<Vector<Boleto>>) o.get(1);

        // Mostrar datos

    }

    // Métodos

    public String menu(char opcion) {
        /*
        • Presentar un menú con las siguientes opciones
            o Ventas Boletos
                ▪ Clase turista
                ▪ Primera Clase
                ▪ Cerrar factura
            o Consulta por factura
            o Consulta de boletos clase turista
            o Consulta de boletos primera clase
            o Consulta por factura detalle
            o Eliminación de facturas
            o Eliminación de boletos clase turista
            o Eliminación de boletos primera clase
        */
        if (opcion == 'p') {
            return "1. Ventas Boletos\n" + "2. Consulta facturas\n" + "3. Consulta de boletos clase turista\n" + "4. Consulta de boletos primera clase\n" + "5. Consulta por factura detalle\n" + "6. Eliminación de facturas\n" + "7. Eliminación de boletos\n" + "8. Salir.";
        }
        if (opcion == 's') {
            return "1. Clase turista\n" + "2. Primera Clase\n" + "3. Cerrar factura";
        }
        return "";
    }

    // Iniciar
    public void iniciar() {
        v.mostrar("Bienvenido al sistema de ventas de boletos");

        boolean salir = true;
        while (salir) {

            v.mostrar(menu('p'));
            int opcion = v.leerOpcion('p');
            if (opcion == 1) {
                // Ventas boletos
                // Venta iniciada
                v.mostrarSinLinea("Venta iniciada: ");

                boolean salidaVenta = true;

                while (salidaVenta) {
                    String folio = "";
                    if(facturas.isEmpty()){
                        // Folio
                        folio = v.ingresarFolio(0,"");
                        v.mostrar(folio);
                    }else {
                        // Folio
                        folio = v.ingresarFolio(facturas.size(),facturas.lastElement().getFolioFactura());
                        v.mostrar(folio);
                    }


                    v.mostrar(menu('s'));
                    opcion = v.leerOpcion('s');

                    if (opcion == 1) {
                        // Clase turista
                        v.mostrar("Clase turista");
                        /*
                        // Atributos de la clase padre Boleto
                            private String fechaVuelo;
                            private String destino;
                            private String origen;
                            private String vuelo;
                            private String folioFactura;
                            private double Precio;

                        // Atributos de la clase hija ClaseTurista
                            private int fila;
                            private char asiento;

                         */
                        // Fecha de vuelo
                        v.mostrarSinLinea("Fecha de vuelo: ");
                        String fechaVuelo = v.leerFecha();

                        // Destino
                        v.mostrarSinLinea("Destino: ");
                        String destino = v.leerCiudad();

                        // Origen
                        v.mostrarSinLinea("Origen: ");
                        String origen = v.leerCiudad();

                        // Vuelo
                        v.mostrarSinLinea("Vuelo: ");
                        String vuelo = v.leerVuelo();

                        // Precio
                        v.mostrarSinLinea("Precio: ");
                        double precio = v.leerPrecio();

                        // Fila
                        v.mostrarSinLinea("Fila: ");
                        int fila = v.leerFila();

                        // Asiento
                        v.mostrarSinLinea("Asiento: ");
                        char asiento = v.leerAsiento();

                        // Clase turista
                        // Constructor: public ClaseTurista(int fila, char asiento, String fechaVuelo, String destino, String origen, String vuelo, String folioFactura, double precio)
                        ClaseTurista ct = new ClaseTurista(fila, asiento, fechaVuelo, destino, origen, vuelo, folio, precio);

                        // Agregar boleto
                        boletos.get(0).add(ct);

                        // Agregar factura
                        // Constructor: public Factura(String folioFactura, String fechaFactura, double monto, double iva, double total)
                        Factura f = new Factura(folio, v.leerFechaActual(), precio, IVA, precio * (1+IVA));

                        // Agregar factura
                        facturas.add(f);

                        // Venta finalizada
                        v.mostrar("Venta finalizada");

                    } else if (opcion == 2) {
                        // Clase privada
                        v.mostrar("Primera clase");
                        /*

                        // Atributos de la clase padre Boleto
                            private String fechaVuelo;
                            private String destino;
                            private String origen;
                            private String vuelo;
                            private String folioFactura;
                            private double Precio;

                         // Atributos de la clase PrimeraClase
                            private boolean dormitorio;
                            private boolean ducha;
                            private boolean bar;
                            private String asiento;

                         */

                        // Fecha de vuelo
                        v.mostrarSinLinea("Fecha de vuelo: ");
                        String fechaVuelo = v.leerFecha();

                        // Destino
                        v.mostrarSinLinea("Destino: ");
                        String destino = v.leerCiudad();

                        // Origen
                        v.mostrarSinLinea("Origen: ");
                        String origen = v.leerCiudad();

                        // Vuelo
                        v.mostrarSinLinea("Vuelo: ");
                        String vuelo = v.leerVuelo();

                        // Precio
                        v.mostrarSinLinea("Precio: ");
                        double precio = v.leerPrecio();

                        // Dormitorio
                        v.mostrarSinLinea("Dormitorio (s/n): ");
                        boolean dormitorio = v.leerBoolean();

                        // Ducha
                        v.mostrarSinLinea("Ducha (s/n): ");
                        boolean ducha = v.leerBoolean();

                        // Bar
                        v.mostrarSinLinea("Bar (s/n): ");
                        boolean bar = v.leerBoolean();

                        // Asiento
                        v.mostrarSinLinea("Asiento: ");
                        String asiento = v.leerAsientoString();

                        // PrimeraClase
                        // Constructor: public PrimeraClase(String fechaVuelo, String destino, String origen, String vuelo, String folioFactura, double precio)
                        PrimeraClase pc = new PrimeraClase(fechaVuelo, destino, origen, vuelo, folio, precio);

                        // Agregar boleto
                        boletos.get(1).add(pc);

                        // Agregar factura
                        // Constructor: public Factura(String folioFactura, String fechaFactura, double monto, double iva, double total)
                        Factura f = new Factura(folio, v.leerFechaActual(), precio, IVA, precio * (1+IVA));

                        // Agregar factura
                        facturas.add(f);

                        // Venta finalizada
                        v.mostrar("Venta finalizada");
                    } else if (opcion == 3) {
                        // Cerrar factura
                        opcion = 0;
                        salidaVenta = false;
                    } else {
                        // Opción inválida
                        v.mostrar("Opción inválida");
                    }

                }
            } else if (opcion == 2) {

                // Consulta de facturas
                v.mostrar("Consulta de facturas");
                for (Factura f : facturas) {
                    v.mostrar(f.toString());
                }


            } else if (opcion == 3) {
                // Consulta de boletos clase turista
                v.mostrar("Consulta de boletos clase turista");
                for (Boleto b : boletos.get(0)) {
                    v.mostrar(b.toString());
                }
            } else if (opcion == 4) {
                // Consulta de boletos clase primera clase
                v.mostrar("Consulta de boletos clase primera clase");
                for (Boleto b : boletos.get(1)) {
                    v.mostrar(b.toString());
                }
            } else if (opcion == 5) {
                // Consulta de factura por folio
                v.mostrar("Consulta por factura");
                v.mostrarSinLinea("Folio de factura: ");
                String folio = v.leerFolio();

                // Buscar factura
                boolean encontrado = false;
                for (int i = 0; i < facturas.size(); i++) {
                    if (facturas.get(i).getFolioFactura().equals(folio)) {
                        v.mostrar(facturas.get(i).toString());
                        encontrado = true;
                    }
                }
            } else if (opcion == 6) {
                /*
                Eliminación por factura, solicita el folio de la factura a eliminar y una vez localizado eliminar
                de facturas dicho objeto y todos los objetos de la matriz de boletos que tengan dicho folio
                 */
                v.mostrar("Eliminación por factura");
                v.mostrarSinLinea("Folio de factura: ");
                String folio = v.leerFolio();
                // Buscar factura
                boolean encontrado = false;
                for (int i = 0; i < facturas.size(); i++) {
                    if (facturas.get(i).getFolioFactura().equals(folio)) {
                        facturas.remove(i);
                    }
                }
            } else if (opcion == 7) {
                // Eliminación de boletos clase turista o primera clase, solicitar el numero de folio de factura
                //a mostrar del tipo de boleto y seleccionar cual se desea eliminar o dar la opción de eliminar
                //todos, esto implica descontar dichos montos de la factura referida y recalcular iva y total y
                //si el monto llega a cero también se elimina la factura y eliminar de la matriz los objetos
                //referidos o marcados para eliminación
                v.mostrar("Eliminación de boletos");
                v.mostrarSinLinea("Folio de factura: ");
                String folio = v.leerFolio();
                // Buscar factura
                boolean encontrado = false;
                for (int i = 0; i < facturas.size(); i++) {
                    if (facturas.get(i).getFolioFactura().equals(folio)) {
                        v.mostrar("Seleccione el tipo de boleto a eliminar");
                        v.mostrar("1. Clase turista");
                        v.mostrar("2. Clase primera clase");
                        int opcionBoleto = v.leerOpcionEntre(1, 2);
                        if (opcionBoleto == 1) {
                            // Eliminar boletos clase turista
                            v.mostrar("Eliminación de boletos clase turista");
                            for (int j = 0; j < boletos.get(0).size(); j++) {
                                if (boletos.get(0).get(j).getFolioFactura().equals(folio)) {
                                    boletos.get(0).remove(j);

                                }
                            }
                        }
                        if (opcionBoleto == 2) {
                            // Eliminar boletos clase primera clase
                            v.mostrar("Eliminación de boletos clase primera clase");
                            for (int j = 0; j < boletos.get(1).size(); j++) {
                                if (boletos.get(1).get(j).getFolioFactura().equals(folio)) {
                                    boletos.get(1).remove(j);
                                }
                            }
                        }
                        // Eliminar el precio total de la factura
                        Factura temporal = facturas.get(i);
                        temporal.setTotal(0);
                        temporal.setMonto(0);
                        facturas.set(i, temporal);
                    }
                }
            } else if (opcion == 8) {

                // Guardar facturas
                v.mostrar("Guardar facturas");
                p.guardarFacturas(facturas);
                v.mostrar("Facturas guardadas");

                // Guardar boletos
                v.mostrar("Guardar boletos");
                p.guardarBoletos(boletos);
                v.mostrar("Boletos guardados");

                // Salir
                v.mostrar("Saliendo...");
                salir = false;
            } else {
                v.mostrar("Opción incorrecta");
            }

        }

    }

}
