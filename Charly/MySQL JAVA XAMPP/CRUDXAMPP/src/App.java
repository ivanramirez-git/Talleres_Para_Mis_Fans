import java.sql.ResultSet;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import javax.swing.JOptionPane;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Bienvenido");
        Conexion c = new Conexion();
        c.getConnection();
        /*
        id INT NOT NULL AUTO_INCREMENT,
        nombre VARCHAR(50) NOT NULL,
        telefono VARCHAR(10) NOT NULL,
        email VARCHAR(50) NOT NULL,
        anioingreso INT NOT NULL,
        PRIMARY KEY (id)        
        */
        // Interfaz
        JFrame frame = new JFrame("Estudiantes");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);
        // Panel de botones
        JPanel panel = new JPanel();
        frame.add(panel);
        // Botones
        JButton btn = new JButton("Agregar");
        JButton btn2 = new JButton("Eliminar");
        JButton btn3 = new JButton("Modificar");
        JButton btn4 = new JButton("Consultar por ID");
        JButton btn5 = new JButton("Consultar por nombre");
        JButton btn6 = new JButton("Consultar todos");
        panel.add(btn);
        panel.add(btn2);
        panel.add(btn3);
        panel.add(btn4);
        panel.add(btn5);
        panel.add(btn6);        
        // Tabla
        JTable tabla = new JTable(); // metodo actualizarTabla(tabla,c,sql)        
        actualizarTabla(tabla, c, "SELECT * FROM estudiantes");
        JScrollPane scroll = new JScrollPane(tabla);
        panel.add(scroll);

        // Eventos
        btn.addActionListener(e -> {
            try {
                // Pedir datos
                String nombre = JOptionPane.showInputDialog("Nombre");
                String telefono = JOptionPane.showInputDialog("Telefono");
                String email = JOptionPane.showInputDialog("Email");
                String anioingreso = JOptionPane.showInputDialog("Año de ingreso");
                // Insertar datos
                String sql = "INSERT INTO estudiantes (nombre, telefono, email, anioingreso) VALUES ('" + nombre + "', '" + telefono + "', '" + email + "', '" + anioingreso + "')";
                c.ingresar(sql);
                JOptionPane.showMessageDialog(null, "Estudiante agregado");
                // Actualizar tabla
                actualizarTabla(tabla, c, "SELECT * FROM estudiantes");
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "Error: " + ex.getMessage());
            }
        });
        btn2.addActionListener(e -> {
            try {
                // Pedir datos
                String id = JOptionPane.showInputDialog("ID");
                // Eliminar datos
                String sql = "DELETE FROM estudiantes WHERE id = " + id;
                c.ingresar(sql);
                JOptionPane.showMessageDialog(null, "Estudiante eliminado");
                // Actualizar tabla
                actualizarTabla(tabla, c, "SELECT * FROM estudiantes");
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "Error: " + ex.getMessage());
            }
        });
        btn3.addActionListener(e -> {
            try {
                // Pedir datos
                String id = JOptionPane.showInputDialog("ID");
                String nombre = JOptionPane.showInputDialog("Nombre");
                String telefono = JOptionPane.showInputDialog("Telefono");
                String email = JOptionPane.showInputDialog("Email");
                String anioingreso = JOptionPane.showInputDialog("Año de ingreso");
                // Modificar datos
                String sql = "UPDATE estudiantes SET nombre = '" + nombre + "', telefono = '" + telefono + "', email = '" + email + "', anioingreso = '" + anioingreso + "' WHERE id = " + id;
                c.ingresar(sql);
                JOptionPane.showMessageDialog(null, "Estudiante modificado");
                // Actualizar tabla
                actualizarTabla(tabla, c, "SELECT * FROM estudiantes");
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "Error: " + ex.getMessage());
            }
        });
        btn4.addActionListener(e -> {
            try {
                // Pedir datos
                String id = JOptionPane.showInputDialog("ID");
                // Consultar datos
                String sql = "SELECT * FROM estudiantes WHERE id = " + id;
                // ResultSet rs = (ResultSet) c.consulta(sql);
                // while (rs.next()) {
                //     JOptionPane.showMessageDialog(null, "ID: " + rs.getString("id") + "\nNombre: " + rs.getString("nombre") + "\nTelefono: " + rs.getString("telefono") + "\nEmail: " + rs.getString("email") + "\nAño de ingreso: " + rs.getString("anioingreso"));
                // }
                // Actualizar tabla
                actualizarTabla(tabla, c, sql);
                
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "Error: " + ex.getMessage());
            }
        });
        btn5.addActionListener(e -> {
            try {
                // Pedir datos
                String nombre = JOptionPane.showInputDialog("Nombre");
                // Consultar datos
                String sql = "SELECT * FROM estudiantes WHERE nombre = '" + nombre + "'";
                // ResultSet rs = (ResultSet) c.consulta(sql);
                // while (rs.next()) {
                //     JOptionPane.showMessageDialog(null, "ID: " + rs.getString("id") + "\nNombre: " + rs.getString("nombre") + "\nTelefono: " + rs.getString("telefono") + "\nEmail: " + rs.getString("email") + "\nAño de ingreso: " + rs.getString("anioingreso"));
                // }
                // Actualizar tabla
                actualizarTabla(tabla, c, sql);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "Error: " + ex.getMessage());
            }
        });
        btn6.addActionListener(e -> {
            try {
                // Consultar datos
                String sql = "SELECT * FROM estudiantes";
                // ResultSet rs = (ResultSet) c.consulta(sql);
                // while (rs.next()) {
                //     JOptionPane.showMessageDialog(null, "ID: " + rs.getString("id") + "\nNombre: " + rs.getString("nombre") + "\nTelefono: " + rs.getString("telefono") + "\nEmail: " + rs.getString("email") + "\nAño de ingreso: " + rs.getString("anioingreso"));
                // }
                // Actualizar tabla
                actualizarTabla(tabla, c, sql);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "Error: " + ex.getMessage());
            }
        });
        // Mostrar
        frame.setVisible(true);

    }

    public static JTable actualizarTabla(JTable tabla, Conexion c, String sql) {
        try {
            ResultSet rs = (ResultSet) c.consulta(sql);
            DefaultTableModel modelo = new DefaultTableModel();
            modelo.addColumn("ID");
            modelo.addColumn("Nombre");
            modelo.addColumn("Telefono");
            modelo.addColumn("Email");
            modelo.addColumn("Año de ingreso");
            while (rs.next()) {
                modelo.addRow(new Object[]{rs.getString("id"), rs.getString("nombre"), rs.getString("telefono"), rs.getString("email"), rs.getString("anioingreso")});
            }
            tabla.setModel(modelo);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, "Error: " + ex.getMessage());
        }
        return tabla;
    }
    
}
