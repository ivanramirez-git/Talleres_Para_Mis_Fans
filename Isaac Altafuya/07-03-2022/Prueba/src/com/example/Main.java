package com.example;

import java.io.*;
import java.util.ArrayList;


public class Main {

    public static void main(String[] args) throws IOException {

        // Buffer de lectura
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Cargar archivos
        ArrayList<Producto> productos = LeerArchivoProductos();
        ArrayList<Venta> ventas = LeerArchivoVentas();

        int opcion = -1;
        while (opcion != 0) {

            // Menu
            System.out.println("1. Venta");
            System.out.println("2. Listado de productos");
            System.out.println("3. Listado de ventas");
            System.out.println("0. Salir");
            System.out.print("Ingrese una opcion: ");
            opcion = Integer.parseInt(br.readLine());

            switch (opcion) {
                case 1:
                    // Venta
                    System.out.println("Venta");
                    System.out.print("Ingrese el codigo del producto: ");
                    String codigo = br.readLine();
                    System.out.print("Ingrese la cantidad: ");
                    int cantidad = Integer.parseInt(br.readLine());

                    // Buscar el producto
                    Producto producto = null;
                    for (int i = 0; i < productos.size(); i++) {
                        if (productos.get(i).getCodigo().equals(codigo)) {
                            producto = productos.get(i);
                            break;
                        }
                    }
                    // Si el producto existe
                    if (producto != null) {
                        // Si el stock es suficiente
                        if (producto.getStock() >= cantidad) {
                            // Actualizar el stock
                            producto.setStock(producto.getStock() - cantidad);
                            // Agregar la venta
                            ventas.add(new Venta(producto.getCodigo(), cantidad));
                            System.out.println("Venta realizada");
                        } else {
                            System.out.println("No hay stock suficiente");
                        }
                    } else {
                        System.out.println("Producto no existe");
                    }
                    break;
                case 2:
                    // Listado de productos
                    System.out.println("Listado de productos");
                    for (int i = 0; i < productos.size(); i++) {
                        System.out.println(productos.get(i).toString());
                    }
                    break;
                case 3:
                    // Listado de ventas
                    System.out.println("Listado de ventas");
                    for (int i = 0; i < ventas.size(); i++) {
                        System.out.println(ventas.toString());
                    }
                    break;
                case 0:
                    // Salir
                    System.out.println("Saliendo...");
                    // Guardar el stock
                    GuardarArchivos(productos, ventas);
                    break;
                default:
                    System.out.println("Opcion incorrecta");
                    break;
            }
        }
    }

    public static void GuardarArchivos(ArrayList<Producto> p, ArrayList<Venta> v) {
        // Actualizar el archivo de texto productos.txt
        try {
            FileOutputStream fos = new FileOutputStream("productos.txt");
            // Encabezados: codigo$descripcion$stock$precio_unitario
            fos.write("codigo$descripcion$stock$precio_unitario\n".getBytes());
            // Reccorrer el arraylist de productos y guardar en el archivo de texto
            for (int i = 0; i < p.size(); i++) {
                fos.write((p.get(i).getCodigo() + "$" + p.get(i).getDescripcion() + "$" + p.get(i).getStock() + "$" + p.get(i).getPrecioUnitario() ).getBytes());
                if (i < p.size() - 1) {
                    fos.write("\n".getBytes());
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        // Actualizar el archivo binario ventas.dat
        try {
            FileOutputStream fos = new FileOutputStream("ventas.dat");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(v);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static ArrayList<Producto> LeerArchivoProductos() {

        ArrayList<Producto> productos = new ArrayList<>();
        try {
            FileInputStream fis = new FileInputStream("productos.txt");
            // Encabezados: codigo$descripcion$stock$precio_unitario
            BufferedReader br = new BufferedReader(new InputStreamReader(fis));
            String linea = br.readLine();
            linea = br.readLine();
            while (linea != null) {
                String[] datos = linea.split("\\$");
                String codigo = datos[0];
                String descripcion = datos[1];
                String stock = datos[2];
                String precioUnitario = datos[3];
                productos.add(new Producto(codigo, descripcion, Integer.parseInt(stock), Double.parseDouble(precioUnitario)));
                linea = br.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return productos;
    }


    public static ArrayList<Venta> LeerArchivoVentas() {
        ArrayList<Venta> ventas = new ArrayList<>();
        try {
            FileInputStream fis = new FileInputStream("ventas.dat");
            ObjectInputStream ois = new ObjectInputStream(fis);
            ventas = (ArrayList<Venta>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        return ventas;
    }
}
