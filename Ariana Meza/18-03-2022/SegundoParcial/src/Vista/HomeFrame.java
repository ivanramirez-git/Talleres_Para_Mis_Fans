package Vista;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import Controlador.ControladorGUI;

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

    ControladorGUI cg;
    
    public HomeFrame() {

        setTitle("Home");
        setSize(400, 300);
        // setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        estado = 0;
        initComponents();

    }

    private void initComponents() {
        pnlHomeFrame = new JPanel();
        pnlCerrarSesion = new JPanel();
        pnlSalones = new JPanel();
        pnlReservarSala = new JPanel();

        btnCerrarSesion = new JButton("Cerrar Sesion");
        btnSalones = new JButton("Salones");
        btnReservarSala = new JButton("Reservar Sala");
        btnMisReservas = new JButton("Mis Reservas");

        pnlHomeFrame.add(pnlCerrarSesion);
        pnlHomeFrame.add(pnlSalones);
        pnlHomeFrame.add(pnlReservarSala);

        pnlCerrarSesion.add(btnCerrarSesion);
        pnlSalones.add(btnSalones);
        pnlReservarSala.add(btnReservarSala);
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
        btnReservarSala.setBounds(10, 10, 100, 30);
        // listener para reservar sala
        btnReservarSala.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnReservarSalaActionPerformed(evt);
            }
        });
        btnMisReservas.setBounds(10, 10, 100, 30);
        // listener para mis reservas
        btnMisReservas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnMisReservasActionPerformed(evt);
            }
        });

        setContentPane(pnlHomeFrame);
    }

    private void btnCerrarSesionActionPerformed(java.awt.event.ActionEvent evt) {
        JOptionPane.showMessageDialog(null, "Cerrar Sesion");   
        estado = 1;
        System.out.println("estado: " + estado);
        this.dispose();
    }

    private void btnSalonesActionPerformed(java.awt.event.ActionEvent evt) {
        estado = 2;
        JOptionPane.showMessageDialog(null, "Salones");
    }

    private void btnReservarSalaActionPerformed(java.awt.event.ActionEvent evt) {
        estado = 3;
        JOptionPane.showMessageDialog(null, "Reservar Sala");
    }

    private void btnMisReservasActionPerformed(java.awt.event.ActionEvent evt) {
        estado = 4;
        JOptionPane.showMessageDialog(null, "Mis Reservas");
    }

    public int getEstado() {
        return estado;
    }

    public void setEstado(int estado) {
        this.estado = estado;
    }
}
