import java.util.Scanner;

import javax.swing.JOptionPane;

import Modelo.Estudiante;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

/**
 *
 * @author User
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // menu
        int opcion = -1;
        do {
            System.out.println("1. Primos");
            System.out.println("2. Tablas");
            System.out.println("3. Estudiantes");
            System.out.println("0. Salir");
            try {
                opcion = sc.nextInt();
            } catch (Exception e) {
                System.out.println("Opción no valida");
                sc.nextLine();
            }
            switch (opcion) {
                case 1:
                    try {
                        System.out.print("Introduce el inicio del rango: ");
                        int inicio = sc.nextInt();
                        System.out.print("Introduce el fin del rango: ");
                        int fin = sc.nextInt();
                        int[] primos = Primos.primos(inicio, fin);
                        String primosString = "{ ";

                        for (int i = 0; i < primos.length - 1; i++) {
                            primosString += primos[i] + ", ";
                        }
                        primosString += primos[primos.length - 1] + " }";
                        JOptionPane.showMessageDialog(null, "Los primos son: " + primosString);
                    } catch (Exception e) {
                        System.out.println("Error al introducir los datos");
                    }
                    break;
                case 2:
                    try {
                        System.out.print("Introduce el numero de tablas: ");
                        int n = sc.nextInt();
                        int[][] tablas = Multiplicaciones.tablas(n);
                        String tablasString = "";
                        for (int i = 0; i < tablas.length; i++) {
                            tablasString += "Tabla del " + (i + 1) + ": { ";
                            for (int j = 0; j < tablas[i].length - 1; j++) {
                                tablasString += tablas[i][j] + ", ";
                            }
                            tablasString += tablas[i][tablas[i].length - 1] + " }\n";
                        }
                        System.out.println(tablasString);
                    } catch (Exception e) {
                        System.out.println("Error al introducir los datos");
                    }
                    break;
                case 3:
                    try {
                        System.out.print("Introduce el número de estudiantes: ");
                        int n = sc.nextInt();
                        GestionEstudiantes ge = new GestionEstudiantes();
                        for (int i = 0; i < n; i++) {
                            sc.nextLine();
                            System.out.print("Introduce el nombre del estudiante: ");
                            String nombre = sc.nextLine();
                            System.out.print("Introduce la cédula del estudiante: ");
                            String cedula = sc.nextLine();
                            System.out.print("Introduce el promedio del estudiante: ");
                            double promedio = sc.nextDouble();
                            Estudiante estudiante = new Estudiante(nombre, cedula, promedio);
                            ge.agregarEstudiante(estudiante);
                        }
                        System.out.println("Estudiantes agregados");
                        ge.mostrarEstudiantes();
                        System.out.print("Introduce la cédula del estudiante a buscar: ");
                        sc.nextLine();
                        String cedula = sc.nextLine();
                        ge.buscarPorCedula(cedula);
                    } catch (Exception e) {
                        System.out.println("Error al introducir los datos");
                    }
                    break;
                case 0:
                    System.out.println("Adios");
                    break;
                default:
                    System.out.println("Opción no valida");
                    break;
            }

        } while (opcion != 0);

    }

}
