package Controlador;

import java.util.ArrayList;

import Modelo.Administrador;
import Modelo.Cliente;
import Modelo.Reservacion;
import Modelo.Salon;
import Modelo.Usuario;
import Vista.HomeFrame;
import Vista.SesionInicioFrame;
import Vista.SesionRegistroFrame;

public class ControladorGUI {

    // Atributos
    ArrayList<Usuario> usuarios;
    // Usuario Tipo Cliente: Cliente(int id, String usuario, String nombre, String
    // email, String password)
    // Usuario Tipo Administrador: Administrador(int id, String usuario, String
    // nombre, String email, String password, String fecha_de_creacion, int
    // creado_por_id_administrador)
    ArrayList<Salon> salones;
    // Salon: Salon(int id, String nombre, String descripcion, int capacidad, double
    // precio)
    ArrayList<Reservacion> reservaciones;
    // Reservacion: Reservacion(int id, String fecha, int salon_id, int cliente_id,
    // int hora_inicio, int hora_fin, double precio)

    private boolean sesion = false;
    private Usuario usuarioActual;

    // Constructor
    public ControladorGUI() {
        usuarios = new ArrayList<Usuario>();
        salones = new ArrayList<Salon>();
        reservaciones = new ArrayList<Reservacion>();
    }

    public boolean isSesion() {
        return sesion;
    }

    public void iniciarSesion(String usuario, String password) {
        for (int i = 0; i < usuarios.size(); i++) {
            if (usuarios.get(i).getUsuario().equals(usuario) && usuarios.get(i).validarPassword(password)) {
                sesion = true;
                usuarioActual = usuarios.get(i);
                // Llamar al frame home
                HomeFrame homeFrame = new HomeFrame();
                homeFrame.setVisible(true);
                System.out.println("Sesion iniciada");
                while (homeFrame.getEstado() != 1) {
                    if (homeFrame.getEstado() == 1) {
                        // Cerrar Sesion
                        homeFrame.setEstado(0);
                        cerrarSesion();
                        break;
                    } else if (homeFrame.getEstado() == 2) {
                        // Salones
                        // salones();
                        homeFrame.setEstado(0);
                    } else if (homeFrame.getEstado() == 3) {
                        // Reservar Sala
                        // reservarSala();
                        homeFrame.setEstado(0);
                    } else if (homeFrame.getEstado() == 4) {
                        // Mis Reservas
                        // misReservas();
                        homeFrame.setEstado(0);
                    } else {
                        homeFrame.setVisible(true);
                    }
                }
                return;
            }
        }
        System.out.println("Sesion no iniciada");
    }

    public void cerrarSesion() {
        sesion = false;
        usuarioActual = null;
        System.out.println("Sesion cerrada");
    }

    // iniciar sesion
    public void iniciar() {

        SesionInicioFrame sesionInicioFrame = new SesionInicioFrame();
        while (sesionInicioFrame.getEstado() != 3) {
            // 0: Continuar Esperando..., 1: Campos llenos, 2: Registro, 3: Salir
            if (sesionInicioFrame.getEstado() == 1) {
                iniciarSesion(sesionInicioFrame.getUsuario(), sesionInicioFrame.getPassword());
                System.out.println("Sesion Finalizada");
                sesionInicioFrame = new SesionInicioFrame();
                sesionInicioFrame.setVisible(true);
                sesion = false;
            } else if (sesionInicioFrame.getEstado() == 2) {
                sesionInicioFrame.setEstado(0);
                SesionRegistroFrame sesionRegistroFrame = new SesionRegistroFrame();
                while (!sesion && sesionRegistroFrame.getEstado() != 3) {
                    if (sesionRegistroFrame.getEstado() == 1) {
                        Usuario usuario = new Cliente(usuarios.size(), sesionRegistroFrame.getUsuario(),
                                sesionRegistroFrame.getNombre(), sesionRegistroFrame.getEmail(),
                                sesionRegistroFrame.getPassword());
                        usuarios.add(usuario);
                        sesion = true;
                        sesionRegistroFrame.setEstado(0);
                    } else if (sesionRegistroFrame.getEstado() == 2) {
                        sesionRegistroFrame.setEstado(0);
                    }
                    if (!sesion && sesionRegistroFrame.getEstado() != 2) {
                        sesionRegistroFrame.setEstado(0);
                        sesionRegistroFrame.setVisible(true);
                    }
                }
                sesion = false;
            }

            if (!sesion && sesionInicioFrame.getEstado() != 2) {
                sesionInicioFrame.setEstado(0);
                sesionInicioFrame.setVisible(true);
            }
        }

        // Mostrar Tabla de Usuarios tipo Administrador
        // ID, Usuario, Nombre, Email, Password, Fecha de Creacion, Creado por
        System.out.println("Usuarios tipo Administrador:");
        String[] encabezado = { "ID", "Usuario", "Nombre", "Email", "Password", "Fecha de Creacion", "Creado por" };
        for (int i = 0; i < usuarios.size(); i++) {
            // Class Administrador, instanceof Administrador
            if (usuarios.get(i) instanceof Administrador) {
                System.out.println(usuarios.get(i).toString());
            }
        }

        // Mostrar Tabla de Usuarios tipo Cliente
        // ID, Usuario, Nombre, Email, Password
        System.out.println("Usuarios tipo Cliente:");
        String[] encabezado2 = { "ID", "Usuario", "Nombre", "Email", "Password" };
        for (int i = 0; i < usuarios.size(); i++) {
            // Class Cliente
            if (usuarios.get(i) instanceof Cliente) {
                System.out.println(usuarios.get(i).toString());
            }
        }

        // Mostrar Tabla de Salones
        // ID, Nombre, Descripcion, Capacidad, Precio
        System.out.println("Salones:");
        String[] encabezado3 = { "ID", "Nombre", "Descripcion", "Capacidad", "Precio" };
        for (int i = 0; i < salones.size(); i++) {
            System.out.println(salones.get(i).toString());
        }

        // Mostrar Tabla de Reservaciones
        // ID, Fecha, Salon, Cliente, Hora Inicio, Hora Fin, Precio
        System.out.println("Reservaciones:");
        String[] encabezado4 = { "ID", "Fecha", "Salon", "Cliente", "Hora Inicio", "Hora Fin", "Precio" };
        for (int i = 0; i < reservaciones.size(); i++) {
            System.out.println(reservaciones.get(i).toString());
        }

    }
}
