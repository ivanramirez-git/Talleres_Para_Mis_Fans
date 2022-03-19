package Vista;

import java.awt.event.ActionEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class SesionInicioFrame extends JFrame {

    
    // Formulario de Inicio de Sesión y Registro
    private JPanel sesionRegistroPanel;
    private JLabel lblUsuario;
    private JLabel lblPassword;
    private JTextField txtUsuario;
    private JPasswordField txtPassword;
    private JButton btnIniciarSesion;
    private JButton btnRegistrarse;
    private JButton btnCancelar;
    private JLabel lblError;

    private int estado;

    public SesionInicioFrame() {
        setTitle("Inicio de Sesión");
        setSize(400, 300);
        // setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        estado = 0;
        // setLayout(null);
        // setVisible(true);
        initComponents();
    }
    
    private void initComponents() {
        sesionRegistroPanel = new JPanel();
        lblUsuario = new JLabel("Usuario");
        lblPassword = new JLabel("Contraseña");
        txtUsuario = new JTextField();
        txtPassword = new JPasswordField();
        btnIniciarSesion = new JButton("Iniciar Sesión");
        btnRegistrarse = new JButton("Registrarse");
        btnCancelar = new JButton("Cancelar");
        lblError = new JLabel("");

        sesionRegistroPanel.setLayout(null);

        lblUsuario.setBounds(10, 10, 80, 25);
        sesionRegistroPanel.add(lblUsuario);

        lblPassword.setBounds(10, 40, 80, 25);
        sesionRegistroPanel.add(lblPassword);

        txtUsuario.setBounds(100, 10, 165, 25);
        sesionRegistroPanel.add(txtUsuario);

        txtPassword.setBounds(100, 40, 165, 25);
        sesionRegistroPanel.add(txtPassword);

        btnIniciarSesion.setBounds(10, 80, 165, 25);
        sesionRegistroPanel.add(btnIniciarSesion);
        btnIniciarSesion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnIniciarSesionActionPerformed(evt);
            }
        });

        btnRegistrarse.setBounds(185, 80, 165, 25);
        sesionRegistroPanel.add(btnRegistrarse);
        btnRegistrarse.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnRegistrarseActionPerformed(evt);
            }
        });

        btnCancelar.setBounds(10, 110, 165, 25);
        sesionRegistroPanel.add(btnCancelar);
        btnCancelar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCancelarActionPerformed(evt);
            }
        });

        lblError.setBounds(10, 140, 365, 25);
        sesionRegistroPanel.add(lblError);

        add(sesionRegistroPanel);
    }

    // OnClick del botón Iniciar Sesión
    private void btnIniciarSesionActionPerformed(ActionEvent evt) {
        // Validar campos
        if (txtUsuario.getText().isEmpty() || txtPassword.getText().isEmpty()) {
            lblError.setText("Debe completar todos los campos");
        } else {
            estado = 1;
            this.dispose();
        }
    }

    // OnClick del botón Cancelar
    private void btnCancelarActionPerformed(ActionEvent evt) {
        // Mensaje de confirmación
        int confirmacion = JOptionPane.showConfirmDialog(null, "¿Está seguro que desea cancelar?", "Confirmar", JOptionPane.YES_NO_OPTION);
        if (confirmacion == 0) {
            estado = 3;
            this.dispose();
        }
    }

    // OnClick del botón Registrarse
    private void btnRegistrarseActionPerformed(ActionEvent evt) {
        // Mostrar ventana de registro
        estado = 2;
        this.dispose();
    }

    // Método para mostrar un mensaje de error
    public void setError(String error) {
        lblError.setText(error);
    }

    // Método para obtener el usuario
    public String getUsuario() {
        return txtUsuario.getText();
    }
    
    // Método para obtener el password
    public String getPassword() {
        return txtPassword.getText();
    }

    // Método para limpiar el formulario
    public void clearForm() {
        txtUsuario.setText("");
        txtPassword.setText("");
    }

    public void datosErroneos() {
        setVisible(true);
        lblError.setText("Datos Erroneos");
    }

    public int getEstado() {
        return estado; // 1: Campos llenos, 2: Cancelar, 3: Registrarse
    }

    public void setEstado(int estado) {
        this.estado = estado;
    }

    
    
}

