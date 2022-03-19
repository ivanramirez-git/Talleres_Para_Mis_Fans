package Controlador;

import java.util.ArrayList;

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
    public void iniciar() throws Exception {

        SesionInicioFrame sesionInicioFrame = new SesionInicioFrame();
        while (!sesion && sesionInicioFrame.getEstado()!=3) {
            // 0: Continuar Esperando..., 1: Campos llenos, 2: Registro, 3: Salir
            if (sesionInicioFrame.getEstado() == 1) {
                iniciarSesion(sesionInicioFrame.getUsuario(), sesionInicioFrame.getPassword());
                if (sesion == true) {
                    sesionInicioFrame.setEstado(0);
                }
            } else if (sesionInicioFrame.getEstado() == 2) {                
                sesionInicioFrame.setEstado(0);
                SesionRegistroFrame sesionRegistroFrame = new SesionRegistroFrame();
                while (!sesion && sesionRegistroFrame.getEstado()!=3) {
                    if (sesionRegistroFrame.getEstado() == 1) {
                        Usuario usuario = new Usuario(usuarios.size(), sesionRegistroFrame.getUsuario(),
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

        System.out.println("Sesion iniciada");
        // Mostrar en consola todos los usuarios registrados

    }
}
