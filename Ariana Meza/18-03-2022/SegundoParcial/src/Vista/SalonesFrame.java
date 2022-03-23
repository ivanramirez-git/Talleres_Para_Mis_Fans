package Vista;

import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;

import Modelo.Administrador;
import Modelo.Salon;
import Modelo.Usuario;

public class SalonesFrame extends JFrame {

    //  Tabla de salones
    //  Salones: Salon(int id, String nombre, String descripcion, int capacidad, double precio)
    private JTable tablaSalones;
    private JScrollPane scrollPane;
    private JPanel pnlSalones;
    private JButton btnAtras;

    private JButton btnAgregarSalon;
    private Usuario usuarioActual;

    private ArrayList<Salon> salones;
    private int estado;


    public SalonesFrame(ArrayList<Salon> salones, Usuario usuarioActual) {
        setTitle("Salones");
        setSize(500, 300);
        // setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // setResizable(false);
        this.salones = salones;
        estado = 0;
        this.usuarioActual = usuarioActual;

        initComponents();
    }

    private void initComponents() {
        pnlSalones = new JPanel();
        btnAtras = new JButton("Atras");
        pnlSalones.add(btnAtras);
        
        // listener
        btnAtras.addActionListener(e -> {
            this.dispose();
            estado = 1;
        });
        
        // Botones, validar instance of admin
        if (usuarioActual instanceof Administrador) {
            btnAgregarSalon = new JButton("Agregar Salon");
            pnlSalones.add(btnAgregarSalon);
            btnAgregarSalon.addActionListener(e -> {
                estado = 2;
                this.dispose();
            });
        } else if (!(usuarioActual instanceof Usuario)) {
            // Cerrar el Programa
            System.exit(0);
        }

        add(pnlSalones);
        
        // Tabla de salones
        String[] columnNames = {"ID", "Nombre", "Descripcion", "Capacidad", "Precio"};
        Object[][] data = new Object[salones.size()][5];
        for (int i = 0; i < salones.size(); i++) {
            data[i][0] = salones.get(i).getId();
            data[i][1] = salones.get(i).getNombre();
            data[i][2] = salones.get(i).getDescripcion();
            data[i][3] = salones.get(i).getCapacidad();
            data[i][4] = salones.get(i).getPrecio();
        }
        tablaSalones = new JTable(data, columnNames);
        scrollPane = new JScrollPane(tablaSalones);
        pnlSalones.add(scrollPane);



    }

    public void setSalones(ArrayList<Salon> salones) {
        this.salones = salones;
    }

    public void setEstado(int estado) {
        this.estado = estado;
    }

    public int getEstado() {
        return estado;
    }
}
