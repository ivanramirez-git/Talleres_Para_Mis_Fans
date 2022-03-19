package Vista;

import java.awt.event.ActionEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class SesionRegistroFrame extends JFrame {

    
    // Formulario de Registro Usuario(int id, String usuario, String nombre, String email, String password)
    private JPanel sesionRegistroPanel;
    private JLabel lblUsuario;
    private JLabel lblNombre;
    private JLabel lblEmail;
    private JLabel lblPassword;
    private JTextField txtUsuario;
    private JTextField txtNombre;
    private JTextField txtEmail;
    private JPasswordField txtPassword;

    private JButton btnRegistrarse;
    private JButton btnCancelar;
    private JLabel lblError;

    private int estado;

    public SesionRegistroFrame() {
        setTitle("Registrar Usuario");
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
        lblNombre = new JLabel("Nombre");
        lblPassword = new JLabel("Contraseña");
        lblEmail = new JLabel("Email");
        txtUsuario = new JTextField();
        txtPassword = new JPasswordField();
        txtNombre = new JTextField();
        txtEmail = new JTextField();
        btnRegistrarse = new JButton("Registrarse");

        btnCancelar = new JButton("Cancelar");
        lblError = new JLabel("");

        sesionRegistroPanel.setLayout(null);

        lblUsuario.setBounds(10, 10, 80, 25);
        sesionRegistroPanel.add(lblUsuario);

        lblPassword.setBounds(10, 40, 80, 25);
        sesionRegistroPanel.add(lblPassword);

        lblNombre.setBounds(10, 70, 80, 25);
        sesionRegistroPanel.add(lblNombre);

        lblEmail.setBounds(10, 100, 80, 25);
        sesionRegistroPanel.add(lblEmail);

        txtUsuario.setBounds(100, 10, 165, 25);
        sesionRegistroPanel.add(txtUsuario);

        txtPassword.setBounds(100, 40, 165, 25);
        sesionRegistroPanel.add(txtPassword);

        txtNombre.setBounds(100, 70, 165, 25);
        sesionRegistroPanel.add(txtNombre);

        txtEmail.setBounds(100, 100, 165, 25);
        sesionRegistroPanel.add(txtEmail);

        btnRegistrarse.setBounds(10, 130, 165, 25);
        sesionRegistroPanel.add(btnRegistrarse);
        btnRegistrarse.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnIniciarSesionActionPerformed(evt);
            }
        });

        btnCancelar.setBounds(185, 130, 165, 25);
        sesionRegistroPanel.add(btnRegistrarse);
        btnRegistrarse.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnRegistrarseActionPerformed(evt);
            }
        });

        lblError.setBounds(10, 160, 165, 25);
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
        if (txtUsuario.getText().isEmpty() || txtPassword.getText().isEmpty() || txtNombre.getText().isEmpty() || txtEmail.getText().isEmpty()) {
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

    public String getNombre() {
        return txtNombre.getText();
    }

    public String getEmail() {
        return txtEmail.getText();
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

