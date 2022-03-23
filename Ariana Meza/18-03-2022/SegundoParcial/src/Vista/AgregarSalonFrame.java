package Vista;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class AgregarSalonFrame extends JFrame {

    //  Formulario para agregar salon
    //  Salones: Salon(int id, String nombre, String descripcion, int capacidad, double precio)
    private JPanel pnlAgregarSalon;
    private JButton btnAtras;
    private JButton btnAgregar;
    private JTextField txtNombre;
    private JTextField txtDescripcion;
    private JTextField txtCapacidad;
    private JTextField txtPrecio;
    private JLabel lblNombre;
    private JLabel lblDescripcion;
    private JLabel lblCapacidad;
    private JLabel lblPrecio;
    private JLabel lblError;
    private int estado;

    public AgregarSalonFrame() {
        setTitle("Agregar Salon");
        setSize(400, 300);
        // setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        estado = 0;

        initComponents();
    }

    private void initComponents() {
        pnlAgregarSalon = new JPanel();
        btnAtras = new JButton("Atras");
        btnAgregar = new JButton("Agregar");
        txtNombre = new JTextField();
        txtDescripcion = new JTextField();
        txtCapacidad = new JTextField();
        txtPrecio = new JTextField();
        lblNombre = new JLabel("Nombre");
        lblDescripcion = new JLabel("Descripcion");
        lblCapacidad = new JLabel("Capacidad");
        lblPrecio = new JLabel("Precio");
        lblError = new JLabel("");

        pnlAgregarSalon.setLayout(null);
        
        // dimensiones
        btnAtras.setBounds(10, 10, 100, 30);
        btnAgregar.setBounds(120, 10, 100, 30);
        lblNombre.setBounds(10, 50, 100, 30);
        txtNombre.setBounds(120, 50, 100, 30);
        lblDescripcion.setBounds(10, 90, 100, 30);
        txtDescripcion.setBounds(120, 90, 100, 30);
        lblCapacidad.setBounds(10, 130, 100, 30);
        txtCapacidad.setBounds(120, 130, 100, 30);
        lblPrecio.setBounds(10, 170, 100, 30);
        txtPrecio.setBounds(120, 170, 100, 30);
        lblError.setBounds(10, 210, 300, 30);

        pnlAgregarSalon.add(btnAtras);
        pnlAgregarSalon.add(btnAgregar);
        pnlAgregarSalon.add(txtNombre);
        pnlAgregarSalon.add(txtDescripcion);
        pnlAgregarSalon.add(txtCapacidad);
        pnlAgregarSalon.add(txtPrecio);
        pnlAgregarSalon.add(lblNombre);
        pnlAgregarSalon.add(lblDescripcion);
        pnlAgregarSalon.add(lblCapacidad);
        pnlAgregarSalon.add(lblPrecio);
        pnlAgregarSalon.add(lblError);
        // agregar panel
        add(pnlAgregarSalon);

        // listener
        btnAtras.addActionListener(e -> {
            
            estado = 1;
            this.dispose();
        });
        btnAgregar.addActionListener(e -> {
            if (txtNombre.getText().equals("") || txtDescripcion.getText().equals("") || txtCapacidad.getText().equals("") || txtPrecio.getText().equals("")) {
                lblError.setText("Todos los campos son obligatorios");
            } else {
                estado = 2;
                this.dispose();
            }
        });
    }

    public int getEstado() {
        return estado;
    }

    public void setEstado(int estado) {
        this.estado = estado;
    }

    public String getNombre() {
        return txtNombre.getText();
    }

    public String getDescripcion() {
        return txtDescripcion.getText();
    }

    public int getCapacidad() {
        return Integer.parseInt(txtCapacidad.getText());
    }

    public double getPrecio() {
        return Double.parseDouble(txtPrecio.getText());
    }

}
    
