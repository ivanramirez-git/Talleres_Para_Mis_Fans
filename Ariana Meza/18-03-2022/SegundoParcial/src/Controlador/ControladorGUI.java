package Controlador;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

import Modelo.Administrador;
import Modelo.Cliente;
import Modelo.Reservacion;
import Modelo.Salon;
import Modelo.Usuario;
import Vista.HomeFrame;
import Vista.ReservacionesFrame;
import Vista.SalonesFrame;
import Vista.SesionInicioFrame;
import Vista.SesionRegistroFrame;
import Vista.AgregarSalonFrame;

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

    // Constructor
    public ControladorGUI() {
        usuarios = new ArrayList<Usuario>();
        salones = new ArrayList<Salon>();
        reservaciones = new ArrayList<Reservacion>();
        // Crear usuario administrador
        Administrador admin = new Administrador(1, "admin", "admin", "admin@eventos.com", "admin", "2020-01-01", 1);
        usuarios.add(admin);
        cargarArchivos();
    }

    // Guardar ArrayLists en archivos binarios
    public void guardarArchivos() {
        try {
            FileOutputStream usuariosBIN = new FileOutputStream("usuarios.bin");
            FileOutputStream salonesBIN = new FileOutputStream("salones.bin");
            FileOutputStream reservacionesBIN = new FileOutputStream("reservaciones.bin");
            ObjectOutputStream usuariosOBJ = new ObjectOutputStream(usuariosBIN);
            ObjectOutputStream salonesOBJ = new ObjectOutputStream(salonesBIN);
            ObjectOutputStream reservacionesOBJ = new ObjectOutputStream(reservacionesBIN);
            usuariosOBJ.writeObject(usuarios);
            salonesOBJ.writeObject(salones);
            reservacionesOBJ.writeObject(reservaciones);
            usuariosOBJ.close();
            salonesOBJ.close();
            reservacionesOBJ.close();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Cargar ArrayLists de archivos binarios
    public void cargarArchivos() {
        try {
            FileInputStream usuariosBIN = new FileInputStream("usuarios.bin");
            FileInputStream salonesBIN = new FileInputStream("salones.bin");
            FileInputStream reservacionesBIN = new FileInputStream("reservaciones.bin");
            ObjectInputStream usuariosOBJ = new ObjectInputStream(usuariosBIN);
            ObjectInputStream salonesOBJ = new ObjectInputStream(salonesBIN);
            ObjectInputStream reservacionesOBJ = new ObjectInputStream(reservacionesBIN);
            usuarios = (ArrayList<Usuario>) usuariosOBJ.readObject();
            salones = (ArrayList<Salon>) salonesOBJ.readObject();
            reservaciones = (ArrayList<Reservacion>) reservacionesOBJ.readObject();
            usuariosOBJ.close();
            salonesOBJ.close();
            reservacionesOBJ.close();            
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public boolean isSesion() {
        return sesion;
    }

    public void iniciarSesion(String usuario, String password) {
        for (int i = 0; i < usuarios.size(); i++) {
            if (usuarios.get(i).getUsuario().equals(usuario) && usuarios.get(i).validarPassword(password)) {
                sesion = true;
                // Llamar al frame home
                HomeFrame homeFrame = new HomeFrame( usuarios.get(i));
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
                        SalonesFrame salonesFrame = new SalonesFrame(salones, usuarios.get(i));
                        salonesFrame.setVisible(true);
                        while (salonesFrame.getEstado() != 1) {
                            if (salonesFrame.getEstado() == 1) {
                                // Atras
                                salonesFrame.setEstado(0);
                                break;
                            } else if (salonesFrame.getEstado() == 2) {
                                // Agregar Salon
                                AgregarSalonFrame agregarSalonFrame = new AgregarSalonFrame();
                                agregarSalonFrame.setVisible(true);
                                while (agregarSalonFrame.getEstado() != 1) {
                                    if (agregarSalonFrame.getEstado() == 1) {
                                        // Atras
                                        agregarSalonFrame.setEstado(0);
                                        break;
                                    } else if (agregarSalonFrame.getEstado() == 2) {
                                        // Agregar Salon
                                        Salon salon = new Salon(salones.size(), agregarSalonFrame.getNombre(),
                                                agregarSalonFrame.getDescripcion(), agregarSalonFrame.getCapacidad(),
                                                agregarSalonFrame.getPrecio());
                                        salones.add(salon);
                                        agregarSalonFrame.setEstado(0);
                                        break;
                                    }
                                }
                                salonesFrame.setEstado(0);
                                break;
                            }
                        }
                        homeFrame.setEstado(0);
                    } else if (homeFrame.getEstado() == 3) {
                        // Reservaciones
                        ReservacionesFrame reservacionesFrame = new ReservacionesFrame(salones);
                        reservacionesFrame.setVisible(true);
                        while (reservacionesFrame.getEstado() != 1) {
                            if (reservacionesFrame.getEstado() == 1) {
                                // Atras
                                reservacionesFrame.setEstado(0);
                                break;
                            } else if (reservacionesFrame.getEstado() == 2) {
                                // Agregar Reservacion
                                Reservacion reservacion = new Reservacion(reservaciones.size(), usuarios.get(i).getId(),
                                        reservacionesFrame.getSalon(), reservacionesFrame.getFecha(),
                                        reservacionesFrame.getHoraInicio(), reservacionesFrame.getHoraFin());
                                reservaciones.add(reservacion);
                                reservacionesFrame.setEstado(0);
                                break;
                            }
                        homeFrame.setEstado(0);
                        }
                    } else if (homeFrame.getEstado() == 4) {
                        // Mis Reservas
                        // misReservas();
                        homeFrame.setEstado(0);
                    } else if (homeFrame.getEstado() == 5) {
                        // Ver Reservas
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

        // Guardar Archivos
        guardarArchivos();

    }
}
