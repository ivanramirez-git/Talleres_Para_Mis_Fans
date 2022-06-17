import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author User
 */
public class main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        /*
         * Una compañía distribuye 10 productos a distintos comercios de la ciudad. Para
         * ello almacena en
         * arreglos toda la información relacionada con su mercancía:
         * • Clave
         * • Descripción
         * • Existencia
         * • Mínimo a mantener de existencia
         * • Precio unitario
         * Escriba un programa que efectúe las siguientes operaciones:
         * a) Agregar Productos: debe ingresar productos y validar que el usuario pueda
         * decidir si
         * desea continuar agregando o no.
         * b) Venta de un producto: se deben actualizar los campos que correspondan y
         * verificar que la
         * nueva existencia no esté por debajo del mínimo. (Datos: clave, Cantidad
         * Vendida.)
         * c) Reabastecimiento de un producto: se deben actualizar los campos que
         * corresponda.
         * (Datos: clave, Cantidad Comprada.)
         * d) Actualizar el precio de un producto: (Datos: clave, porcentaje de aumento)
         * e) Informar sobre un producto: se deben proporcionar todos los datos
         * relacionados con un
         * producto. (Dato: clave.
         */

        // Informacion de productos: clave, descripcion, existencia, minimo a mantener
        // de existencia, precio unitario
        String descripciones[] = new String[10];
        int existencias[] = new int[10];
        int minimos[] = new int[10];
        double precios[] = new double[10];
        int count = 0;

        // menu de opciones
        int opcion;
        do {
            System.out.println("1. Agregar Productos");
            System.out.println("2. Venta de un producto");
            System.out.println("3. Reabastecimiento de un producto");
            System.out.println("4. Actualizar el precio de un producto");
            System.out.println("5. Informar sobre un producto");
            System.out.println("0. Salir");
            System.out.println("Ingrese una opcion: ");
            do {
                opcion = sc.nextInt();
                if (opcion < 0 || opcion > 5) {
                    System.out.println("Opcion invalida, ingrese una opcion valida: ");
                }
            } while (opcion < 0 || opcion > 5);

            switch (opcion) {
                case 1:
                    // agregar productos
                    do {
                        System.out.println("Producto # " + count);
                        System.out.println("Ingrese la descripcion: ");
                        descripciones[count] = sc.next();
                        System.out.println("Ingrese la existencia: ");
                        do {
                            existencias[count] = sc.nextInt();
                            if (existencias[count] < 0) {
                                System.out.println("Existencia invalida, ingrese una existencia valida: ");
                            }
                        } while (existencias[count] < 0);
                        System.out.println("Ingrese el minimo a mantener: ");
                        do {
                            minimos[count] = sc.nextInt();
                            if (minimos[count] > existencias[count] || minimos[count] < 0) {
                                System.out.println("Minimo a mantener invalida, ingrese un minimo a mantener valido: ");
                            }
                        } while (minimos[count] < 0 || minimos[count] > existencias[count]);

                        System.out.println("Ingrese el precio unitario: ");
                        do {
                            precios[count] = sc.nextDouble();
                            if (precios[count] < 0) {
                                System.out.println("Precio unitario invalido, ingrese un precio unitario valido: ");
                            }
                        } while (precios[count] < 0);
                        count++;
                        System.out.println("Desea agregar otro producto? (1. Si, 2. No)");
                        opcion = sc.nextInt();
                    } while (opcion == 1 && count < 10);
                    break;
                case 2:
                    // venta de un producto
                    System.out.println("Venta de un producto");
                    // listar productos
                    if (count == 0) {
                        System.out.println("No hay productos");
                    } else {
                        System.out.println("Lista de productos");
                        System.out.println("Clave\tDescripcion\tPrecio unitario");
                        for (int i = 0; i < count; i++) {
                            System.out.println(i + "\t" + descripciones[i] + "\t" + precios[i]);
                        }
                        int clave;
                        do {
                            System.out.println("Ingrese la clave del producto: ");
                            clave = sc.nextInt();
                        } while (clave < 0 || clave >= count);
                        do {
                            System.out.println("Ingrese la cantidad vendida: ");
                            opcion = sc.nextInt();
                        } while (opcion < 0);
                        if (existencias[clave] - opcion < minimos[clave]) {
                            System.out.println("No hay existencia suficiente");
                        } else {
                            existencias[clave] -= opcion;
                        }
                    }
                    break;
                case 3:
                    // reabastecimiento de un producto
                    System.out.println("Reabastecimiento de un producto");
                    // listar productos
                    if (count == 0) {
                        System.out.println("No hay productos");
                    } else {
                        System.out.println("Lista de productos");
                        System.out.println("Clave\tDescripcion\tPrecio unitario");
                        for (int i = 0; i < count; i++) {
                            System.out.println(i + "\t" + descripciones[i] + "\t" + precios[i]);
                        }
                        int clave;
                        do {
                            System.out.println("Ingrese la clave del producto: ");
                            clave = sc.nextInt();
                        } while (clave < 0 || clave >= count);
                        do {
                            System.out.println("Ingrese la cantidad comprada: ");
                            opcion = sc.nextInt();
                        } while (opcion < 0);
                        existencias[clave] += opcion;
                    }
                    break;
                case 4:
                    // actualizar el precio de un producto
                    System.out.println("Actualizar el precio de un producto");
                    // listar productos
                    if (count == 0) {
                        System.out.println("No hay productos");
                    } else {
                        System.out.println("Lista de productos");
                        System.out.println("Clave\tDescripcion\tPrecio unitario");
                        for (int i = 0; i < count; i++) {
                            System.out.println(i + "\t" + descripciones[i] + "\t" + precios[i]);
                        }
                        int clave;
                        do {
                            System.out.println("Ingrese la clave del producto: ");
                            clave = sc.nextInt();
                        } while (clave < 0 || clave >= count);
                        double porcentaje;
                        do {
                            System.out.println("Ingrese el porcentaje de aumento: ");
                            porcentaje = sc.nextDouble();
                        } while (porcentaje < 0);
                        precios[clave] += (precios[clave] * porcentaje / 100);
                    }
                    break;
                case 5:
                    // informar sobre un producto
                    System.out.println("Informar sobre un producto");
                    if (count == 0) {
                        System.out.println("No hay productos");
                    } else {
                        do {
                            System.out.println("Ingrese la clave del producto: ");
                            opcion = sc.nextInt();
                        } while (opcion < 0 || opcion >= count);
                        System.out.println("Clave: " + opcion);
                        System.out.println("Descripcion: " + descripciones[opcion]);
                        System.out.println("Existencia: " + existencias[opcion]);
                        System.out.println("Minimo a mantener: " + minimos[opcion]);
                        System.out.println("Precio unitario: " + precios[opcion]);
                    }
                    break;
                case 0:
                    System.out.println("Gracias por usar el sistema");
                    return;
                default:
                    System.out.println("Opcion no valida");
            }
        } while (true);

    }

}
