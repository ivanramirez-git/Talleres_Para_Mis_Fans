package Vista;

import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import Modelo.Salon;

public class ReservacionesFrame extends JFrame {

    // Formulario de Reservaciones: Reservacion(int id, int id_cliente, int
    // id_salon, String fecha, String hora_inicio, String hora_fin)

    // Botones: Atras, Reservar Sala
    private JButton btnAtras;
    private JButton btnReservarSala;

    private JLabel id_salon;
    private JTextField id_salon_text;
    private JLabel fecha;
    private JTextField fecha_text;
    private JLabel hora_inicio;
    private JTextField hora_inicio_text;
    private JLabel hora_fin;
    private JTextField hora_fin_text;
    private JLabel error;

    // Array de salones
    ArrayList<Salon> salones;

    int estado;

    // panel
    private JPanel pnlReservaciones;

    public ReservacionesFrame(ArrayList<Salon> salones) {
        setTitle("Reservaciones");
        setSize(400, 350);
        // setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        estado = 0;
        this.salones = salones;
        initComponents();
    }

    private void initComponents() {
        pnlReservaciones = new JPanel();
        pnlReservaciones.setLayout(null);

        btnAtras = new JButton("Atras");
        btnReservarSala = new JButton("Reservar Sala");

        id_salon = new JLabel("Id Salon:");
        id_salon_text = new JTextField();
        fecha = new JLabel("Fecha:");
        fecha_text = new JTextField();
        hora_inicio = new JLabel("Hora Inicio:");
        hora_inicio_text = new JTextField();
        hora_fin = new JLabel("Hora Fin:");
        hora_fin_text = new JTextField();
        error = new JLabel("");

        // dimensiones
        id_salon.setBounds(10, 10, 100, 20);
        id_salon_text.setBounds(10, 30, 100, 20);
        fecha.setBounds(10, 60, 100, 20);
        fecha_text.setBounds(10, 80, 100, 20);
        hora_inicio.setBounds(10, 110, 100, 20);
        hora_inicio_text.setBounds(10, 130, 100, 20);
        hora_fin.setBounds(10, 160, 100, 20);
        hora_fin_text.setBounds(10, 180, 100, 20);
        error.setBounds(10, 210, 100, 20);

        pnlReservaciones.add(id_salon);
        pnlReservaciones.add(id_salon_text);
        pnlReservaciones.add(fecha);
        pnlReservaciones.add(fecha_text);
        pnlReservaciones.add(hora_inicio);
        pnlReservaciones.add(hora_inicio_text);
        pnlReservaciones.add(hora_fin);
        pnlReservaciones.add(hora_fin_text);
        pnlReservaciones.add(error);

        btnAtras.setBounds(10, 240, 100, 20);
        // listener
        btnAtras.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAtrasActionPerformed(evt);
            }
        });
        btnReservarSala.setBounds(120, 240, 100, 20);
        // listener
        btnReservarSala.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnReservarSalaActionPerformed(evt);
            }
        });

        pnlReservaciones.add(btnAtras);
        pnlReservaciones.add(btnReservarSala);

        add(pnlReservaciones);
    }

    private void btnAtrasActionPerformed(java.awt.event.ActionEvent evt) {
        estado = 1;
        dispose();
    }

    private void btnReservarSalaActionPerformed(java.awt.event.ActionEvent evt) {
        // Validar campos
        if (id_salon_text.getText().isEmpty() || fecha_text.getText().isEmpty() || hora_inicio_text.getText().isEmpty()
                || hora_fin_text.getText().isEmpty()) {
            error.setText("Campos vacios");
            estado = 0;
        } else {
            // Validar que el id del salon exista
            int id_salon = Integer.parseInt(id_salon_text.getText());
            boolean existe = false;
            for (int i = 0; i < salones.size(); i++) {
                if (salones.get(i).getId() == id_salon) {
                    existe = true;
                }
            }
            if (!existe) {
                error.setText("El id del salon no existe");
            } else {

                // Validar Formato de fecha dd/mm/yyyy
                if (fecha_text.getText().length() != 10) {
                    error.setText("Formato de fecha incorrecto, debe ser dd/mm/yyyy");
                } else {
                    // Validar Formato de hora hh:mm
                    if (hora_inicio_text.getText().length() != 5 || hora_fin_text.getText().length() != 5) {
                        error.setText("Formato de hora incorrecto, debe ser hh:mm");
                    } else {

                        estado = 2;
                        dispose();
                    }
                }
            }
        }
    }

    public int getEstado() {
        return estado;
    }

    public void setEstado(int estado) {
        this.estado = estado;
    }

    public int getSalon() {
        return Integer.parseInt(id_salon_text.getText());
    }

    public String getFecha() {
        return fecha_text.getText();
    }

    public String getHoraInicio() {
        return hora_inicio_text.getText();
    }

    public String getHoraFin() {
        return hora_fin_text.getText();
    }

}