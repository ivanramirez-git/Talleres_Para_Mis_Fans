package Vista;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import Modelo.Administrador;
import Modelo.Cliente;
import Modelo.Usuario;

public class HomeFrame extends JFrame {

    private static final long serialVersionUID = 1L;

    // Botones: Cerrar Sesion, Salones, Reservar Sala, Mis Reservas
    JButton btnCerrarSesion;
    JButton btnSalones;
    JButton btnReservarSala;
    JButton btnMisReservas;

    // Paneles: Cerrar Sesion, Salones, Reservar Sala, Mis Reservas
    JPanel pnlCerrarSesion;
    JPanel pnlSalones;
    JPanel pnlReservarSala;

    // HomeFrame Panel principal
    JPanel pnlHomeFrame;

    // Estado
    private int estado;

    // Usuario
    Usuario usuario;

    public HomeFrame(Usuario usuario) {

        setTitle("Home");
        setSize(400, 300);
        // setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        estado = 0;
        this.usuario = usuario;
        initComponents();

    }

    private void initComponents() {
        pnlHomeFrame = new JPanel();
        pnlCerrarSesion = new JPanel();
        pnlSalones = new JPanel();
        pnlReservarSala = new JPanel();

        btnCerrarSesion = new JButton("Cerrar Sesion");
        btnSalones = new JButton("Salones");

        if (usuario instanceof Administrador) {
            btnMisReservas = new JButton("Ver Reservas");
            // listener para ver reservas
            btnMisReservas.addActionListener(new java.awt.event.ActionListener() {
                public void actionPerformed(java.awt.event.ActionEvent evt) {
                    btnVerReservasActionPerformed(evt);
                }
            });
        } else if (usuario instanceof Cliente) {
            btnMisReservas = new JButton("Mis Reservas");

            btnReservarSala = new JButton("Reservar Sala");

            pnlReservarSala.add(btnReservarSala);
            
            // listener para mis reservas
            btnMisReservas.addActionListener(new java.awt.event.ActionListener() {
                public void actionPerformed(java.awt.event.ActionEvent evt) {
                    btnMisReservasActionPerformed(evt);
                }
            });
            
            btnReservarSala.setBounds(10, 10, 100, 30);
            // listener para reservar sala
            btnReservarSala.addActionListener(new java.awt.event.ActionListener() {
                public void actionPerformed(java.awt.event.ActionEvent evt) {
                    btnReservarSalaActionPerformed(evt);
                }
            });
        } else {
            System.exit(0);
        }

        btnMisReservas.setBounds(10, 10, 100, 30);

        pnlHomeFrame.add(pnlCerrarSesion);
        pnlHomeFrame.add(pnlSalones);
        pnlHomeFrame.add(pnlReservarSala);

        pnlCerrarSesion.add(btnCerrarSesion);
        pnlSalones.add(btnSalones);
        pnlReservarSala.add(btnMisReservas);

        btnCerrarSesion.setBounds(10, 10, 100, 30);
        // listener para cerrar sesion
        btnCerrarSesion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCerrarSesionActionPerformed(evt);
            }
        });
        btnSalones.setBounds(10, 10, 100, 30);
        // listener para salones
        btnSalones.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSalonesActionPerformed(evt);
            }
        });

        setContentPane(pnlHomeFrame);
    }

    private void btnCerrarSesionActionPerformed(java.awt.event.ActionEvent evt) {
        estado = 1;
        this.dispose();
    }

    private void btnSalonesActionPerformed(java.awt.event.ActionEvent evt) {
        estado = 2;
    }

    private void btnReservarSalaActionPerformed(java.awt.event.ActionEvent evt) {
        estado = 3;
    }

    private void btnMisReservasActionPerformed(java.awt.event.ActionEvent evt) {
        estado = 4;
        JOptionPane.showMessageDialog(null, "Mis Reservas");
    }

    private void btnVerReservasActionPerformed(java.awt.event.ActionEvent evt) {
        estado = 5;
        JOptionPane.showMessageDialog(null, "Ver Reservas");
    }

    public int getEstado() {
        return estado;
    }

    public void setEstado(int estado) {
        this.estado = estado;
    }
}
