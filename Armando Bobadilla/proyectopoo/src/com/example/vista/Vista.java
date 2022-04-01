package com.example.vista;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Vista {
    // Variables auxiliares para lectura y escritura en consola
    private BufferedReader entrada;

    // Constructor
    public Vista() {
        // Limpiar el Buffer
        System.out.flush();
        // Inicializar el Buffer
        entrada = new BufferedReader(new InputStreamReader(System.in));
    }

    public void mostrar(String mensaje) {
        System.out.println(mensaje);
    }

    public void mostrarSinLinea(String mensaje) {
        System.out.print(mensaje);
    }

    public String leerString() {
        try {
            return entrada.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    public int leerInt() {
        // Lee un int
        while (true) {
            try {
                return Integer.parseInt(leerString());
            } catch (NumberFormatException e) {
                mostrar("Ingrese un entero: ");
            }
        }
    }

    public double leerDouble() {
        // Validar que sea un double
        while (true) {
            try {
                return Double.parseDouble(leerString());
            } catch (NumberFormatException e) {
                mostrar("Ingrese un double: ");
            }
        }
    }

    private char leerChar() {
        // Lee un char
        while (true) {
            String caracter = leerString();
            if (caracter.length() == 1) {
                return caracter.charAt(0);
            } else {
                mostrar("Ingrese un caracter: ");
            }
        }
    }

    public int leerOpcion(char opcion) {
        if (opcion == 'p') {
            while (true) {
                int opcionInt = leerInt();
                if (opcionInt ==1 ) {
                    return 1;
                }
                if (opcionInt == 2) {
                    return 2;
                }
                if (opcionInt == 3) {
                    return 3;
                }
                if (opcionInt == 4) {
                    return 4;
                }
                if (opcionInt == 5) {
                    return 5;
                }
                if (opcionInt == 6) {
                    return 6;
                }
                if (opcionInt == 7) {
                    return 7;
                }
                if (opcionInt == 8) {
                    return 8;
                }
                if (opcionInt == 9) {
                    return 9;
                }
                mostrarSinLinea("Ingrese una opción valida: ");
            }
        } else if (opcion == 's') {
            while (true) {
                int opcionInt = leerInt();
                if (opcionInt == 1) {
                    return 1;
                }
                if (opcionInt == 2) {
                    return 2;
                }
                if (opcionInt == 3) {
                    return 3;
                }
                mostrarSinLinea("Ingrese una opción valida: ");
            }
        } else {
            return -1;
        }
    }

    public int leerOpcionEntre(int inicial, int numfinal) {
        // Lee una opcion entre inicial y final
        int opcion = -1;
        while (true) {
            opcion = leerInt();
            if (opcion >= inicial && opcion <= numfinal) {
                return opcion;
            }
            mostrar("Ingrese una opción valida: ");
        }
    }

    public String leerFecha() {
        // Lee una fecha en formato dd/MM/yyyy
        String fecha = "";
        while (true) {
            fecha = leerString();
            if (fecha.length() == 10) {
                if (fecha.charAt(2) == '/' && fecha.charAt(5) == '/') {
                    if (fecha.charAt(0) >= '0' && fecha.charAt(0) <= '9' && fecha.charAt(1) >= '0' && fecha.charAt(1) <= '9' && fecha.charAt(3) >= '0' && fecha.charAt(3) <= '9' && fecha.charAt(4) >= '0' && fecha.charAt(4) <= '9' && fecha.charAt(6) >= '0' && fecha.charAt(6) <= '9' && fecha.charAt(7) >= '0' && fecha.charAt(7) <= '9' && fecha.charAt(8) >= '0' && fecha.charAt(8) <= '9' && fecha.charAt(9) >= '0' && fecha.charAt(9) <= '9') {
                        return fecha;
                    }
                }
            }
            mostrar("Fecha incorrecta. Ingrese nuevamente: ");
        }
    }


    public String leerFechaActual() {
        // Retorna fecha actual en formato dd/MM/yyyy
        String fecha = "";
        Date fechaDate = new java.util.Date();
        SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
        fecha = formato.format(fechaDate);
        return fecha;
    }

    public String leerCiudad() {
        // Lee una ciudad
        String ciudad = "";
        while (true) {
            ciudad = leerString();
            if (ciudad.length() > 0) {
                return ciudad;
            }
            mostrar("Ciudad incorrecta. Ingrese nuevamente: ");
        }
    }

    public String leerVuelo() {
        // Lee un vuelo
        String vuelo = "";
        while (true) {
            vuelo = leerString();
            if (vuelo.length() > 0) {
                return vuelo;
            }
            mostrar("Vuelo incorrecto. Ingrese nuevamente: ");
        }
    }

    public double leerPrecio() {
        // Lee un precio
        double precio = leerDouble();
        while (precio < 0) {
            mostrar("Precio incorrecto. Ingrese nuevamente: ");
            precio = leerDouble();
        }
        return precio;
    }

    public int leerFila() {
        // Lee una fila
        int fila = leerInt();
        while (fila < 0) {
            mostrar("Fila incorrecta. Ingrese nuevamente: ");
            fila = leerInt();
        }
        return fila;
    }

    public char leerAsiento() {
        // Lee un asiento
        char asiento = leerChar();
        while (asiento != 'A' && asiento != 'B' && asiento != 'C' && asiento != 'D' && asiento != 'E' && asiento != 'F' && asiento != 'G' && asiento != 'H') {
            mostrar("Asiento incorrecto. Ingrese nuevamente: ");
            asiento = leerChar();
        }
        return asiento;
    }


    public boolean leerBoolean() {
        // Lee un boolean (s/n)
        String bool = leerString();
        while (true) {
            if (bool.equals("s")) {
                return true;
            } else if (bool.equals("n")) {
                return false;
            } else {
                mostrar("Boolean incorrecto. Ingrese nuevamente: ");
                bool = leerString();
            }
        }
    }

    public String leerAsientoString() {
        // Lee un asiento
        String asiento = leerString();
        while (asiento.length() != 1) {
            mostrar("Asiento incorrecto. Ingrese nuevamente: ");
            asiento = leerString();
        }
        return asiento;
    }

    public String ingresarFolio(int size, String folioUltimo) {
        // Ingresa un folio de factura con el formato F0000 siendo size el consecutivo
        // y folioUltimo el ultimo folio ingresado retornar el siguiente folio
        String folio = "";
        if (size == 0) {
            folio = "F0000";
        }
        if (size > 0){
            // Sacar consecutivo del ultimo folio ingresado
            int consecutivo = Integer.parseInt(folioUltimo.substring(1));
            // Incrementar consecutivo
            consecutivo++;
            // Formatear el consecutivo
            String consecutivoString = String.format("%04d", consecutivo);
            // Construir el nuevo folio
            folio = "F" + consecutivoString;
        }
        return folio;

    }

    public String leerFolio() {
        // Lee un folio
        String folio = "";
        while (true) {
            folio = leerString();
            if (folio.length() == 5) {
                if (folio.charAt(0) == 'F') {
                    if (folio.charAt(1) >= '0' && folio.charAt(1) <= '9' && folio.charAt(2) >= '0' && folio.charAt(2) <= '9' && folio.charAt(3) >= '0' && folio.charAt(3) <= '9' && folio.charAt(4) >= '0' && folio.charAt(4) <= '9') {
                        return folio;
                    }
                }
            }
            mostrar("Folio de factura incorrecto. Ingrese nuevamente: ");
        }
    }
}