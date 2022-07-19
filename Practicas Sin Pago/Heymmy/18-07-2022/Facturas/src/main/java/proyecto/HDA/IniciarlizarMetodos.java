package main.java.proyecto.HDA;

import javax.swing.JOptionPane;

public class IniciarlizarMetodos {

    Cliente cliente;

    String respuesta;

    public void llenarProductos() {
        JOptionPane.showMessageDialog(null, "Llenando Productos...");
    }

    public void llenarCliente() {
        do {
            cliente = new Cliente();
            do {

                cliente.setNombre(JOptionPane.showInputDialog("Por favor, ingrese el nombre de la persona:"));
                if (cliente.getNombre() == null) {
                    JOptionPane.showMessageDialog(null, "No se puede ingresar un nombre nulo");
                    System.exit(0);
                }
            } while (cliente.getNombre().equals(""));

            do {
                cliente.setApellido(JOptionPane.showInputDialog("Por favor, ingrese el apellido de la persona:"));
                if (cliente.getApellido() == null) {
                    JOptionPane.showMessageDialog(null, "No se puede ingresar un apellido nulo");
                    System.exit(0);
                }
            } while (cliente.getApellido().equals(""));

            do {
                cliente.setNumeroTelefono(JOptionPane.showInputDialog("Por favor, ingrese el telefono de la persona:"));
                if (cliente.getNumeroTelefono() == null) {
                    JOptionPane.showMessageDialog(null, "No se puede ingresar un telefono nulo");
                    System.exit(0);
                }
            } while (cliente.getNumeroTelefono().equals(""));
            do {
                cliente.setEmail(JOptionPane.showInputDialog("Por favor, ingrese el email de la persona:"));
                if (cliente.getEmail() == null) {
                    JOptionPane.showMessageDialog(null, "No se puede ingresar un email nulo");
                    System.exit(0);
                }
            } while (cliente.getEmail().equals(""));

            do {
                respuesta = JOptionPane.showInputDialog("Si desea continuar presione S en caso contrario presione N:");
                switch (respuesta) {
                    case "S":
                    case "s":
                        // Aqui la logica para continuar
                        break;
                    case "N":
                    case "n":
                        JOptionPane.showMessageDialog(null, "Gracias por su visita");
                        System.exit(0);
                        break;
                    default:
                        JOptionPane.showMessageDialog(null, "No se puede ingresar una opcion invalida");
                        break;
                }
            } while (!respuesta.equals("S") && !respuesta.equals("s") && !respuesta.equals("N")
                    && !respuesta.equals("n"));
        } while (true);
    }

    public void mostrarCliente() {
        System.out.println("El nombre del cliente: " + cliente.getNombre());
        System.out.println("El apellido del cliente: " + cliente.getApellido());
        System.out.println("El telefono del cliente: " + cliente.getNumeroTelefono());
        System.out.println("El email del cliente: " + cliente.getEmail());
    }
}
