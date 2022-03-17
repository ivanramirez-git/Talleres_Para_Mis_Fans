import java.sql.DriverManager;
import java.sql.ResultSet;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.event.TableModelListener;
import javax.swing.table.TableModel;
import com.mysql.cj.*;
import com.mysql.cj.jdbc.Driver;

public class App {
    public static void main(String[] args) throws Exception {
        /*

        DBMS: MySQL (ver. 5.5.5-10.4.22-MariaDB)
        Case sensitivity: plain=lower, delimited=lower
        Driver: MySQL Connector/J (ver. mysql-connector-java-8.0.25 (Revision: 08be9e9b4cba6aa115f9b27b215887af40b159e0), JDBC4.2)
        Effective version: MariaDB (ver. 10.4.22)
        Ping: 24 ms
        SSL: no
        DATABASE: universidad
        Servidor: localhost
        Puerto: 3306
        Usuario: root
        Contraseña:


        Tabla: estudiantes
            id INT NOT NULL AUTO_INCREMENT,
            nombre VARCHAR(50) NOT NULL,
            telefono VARCHAR(10) NOT NULL,
            email VARCHAR(50) NOT NULL,
            anioingreso INT NOT NULL,
            PRIMARY KEY (id)

        */
        
        ResultSet resultSet = consulta("SELECT * FROM estudiantes");
        ArrayList<Object[]> data = new ArrayList<>();
        ArrayList<String> columnNames = new ArrayList<>();
        
        // Panel con botones
        // Boton 1: agregar
        // Boton 2: eliminar
        // Boton 3: modificar
        // Boton 4: buscar por id
        // Boton 5: buscar por nombre

        JPanel panel = new JPanel();
        JButton button1 = new JButton("Agregar");
        JButton button2 = new JButton("Eliminar");
        JButton button3 = new JButton("Modificar");
        JButton button4 = new JButton("Buscar por id");
        JButton button5 = new JButton("Buscar por nombre");

        
         
        // encabezados
        // datos
        while (resultSet.next()) {
            data.add(new Object[]{
                resultSet.getInt("id"),
                resultSet.getString("nombre"),
                resultSet.getString("telefono"),
                resultSet.getString("email"),
                resultSet.getInt("anioingreso")
            });
        }
        // crear tabla
        JTable table = new JTable(new TableModel() {
            @Override
            public int getRowCount() {
                return data.size();
            }

            @Override
            public int getColumnCount() {
                return columnNames.size();
            }

            @Override
            public String getColumnName(int columnIndex) {
                return columnNames.get(columnIndex);
            }

            @Override
            public Class<?> getColumnClass(int columnIndex) {
                return String.class;
            }

            @Override
            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return false;
            }

            @Override
            public Object getValueAt(int rowIndex, int columnIndex) {
                return data.get(rowIndex)[columnIndex];
            }

            @Override
            public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
                data.get(rowIndex)[columnIndex] = aValue;
            }

            @Override
            public void addTableModelListener(TableModelListener l) {
            }

            @Override
            public void removeTableModelListener(TableModelListener l) {
            }
        });
        

        // Logica de botones
        button1.addActionListener(e -> {
            // agregar un nuevo registro a la base de datos
            // 1. obtener los datos del usuario
            String nombre = JOptionPane.showInputDialog("Nombre");
            String telefono = JOptionPane.showInputDialog("Telefono");
            String email = JOptionPane.showInputDialog("Email");
            String anioingreso = JOptionPane.showInputDialog("Año de ingreso");
            // 2. insertar los datos en la base de datos
            ResultSet r = consulta("INSERT INTO estudiantes (nombre, telefono, email, anioingreso) VALUES ('" + nombre + "', '" + telefono + "', '" + email + "', '" + anioingreso + "')");
            // 3. actualizar la tabla
            table.setModel(new TableModel() {
                @Override
                public int getRowCount() {
                    return data.size();
                }

                @Override
                public int getColumnCount() {
                    return columnNames.size();
                }

                @Override
                public String getColumnName(int columnIndex) {
                    return columnNames.get(columnIndex);
                }

                @Override
                public Class<?> getColumnClass(int columnIndex) {
                    return String.class;
                }

                @Override
                public boolean isCellEditable(int rowIndex, int columnIndex) {
                    return false;
                }

                @Override
                public Object getValueAt(int rowIndex, int columnIndex) {
                    return data.get(rowIndex)[columnIndex];
                }

                @Override
                public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
                    data.get(rowIndex)[columnIndex] = aValue;
                }

                @Override
                public void addTableModelListener(TableModelListener l) {
                }

                @Override
                public void removeTableModelListener(TableModelListener l) {
                }
            });
        });
        button2.addActionListener(e -> {
            // eliminar
            // 1. obtener el id del registro a eliminar
            String id = JOptionPane.showInputDialog("Id");
            // 2. eliminar el registro de la base de datos
            ResultSet r = consulta("DELETE FROM estudiantes WHERE id = " + id);
            // 3. actualizar la tabla
            table.setModel(new TableModel() {
                @Override
                public int getRowCount() {
                    return data.size();
                }

                @Override
                public int getColumnCount() {
                    return columnNames.size();
                }

                @Override
                public String getColumnName(int columnIndex) {
                    return columnNames.get(columnIndex);
                }

                @Override
                public Class<?> getColumnClass(int columnIndex) {
                    return String.class;
                }

                @Override
                public boolean isCellEditable(int rowIndex, int columnIndex) {
                    return false;
                }

                @Override
                public Object getValueAt(int rowIndex, int columnIndex) {
                    return data.get(rowIndex)[columnIndex];
                }

                @Override
                public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
                    data.get(rowIndex)[columnIndex] = aValue;
                }

                @Override
                public void addTableModelListener(TableModelListener l) {
                }

                @Override
                public void removeTableModelListener(TableModelListener l) {
                }
            }); 
        });
        button3.addActionListener(e -> {
            // modificar
            // 1. obtener el id del registro a modificar
            String id = JOptionPane.showInputDialog("Id");
            // 2. obtener los datos del usuario
            String nombre = JOptionPane.showInputDialog("Nombre");
            String telefono = JOptionPane.showInputDialog("Telefono");
            String email = JOptionPane.showInputDialog("Email");
            String anioingreso = JOptionPane.showInputDialog("Año de ingreso");
            // 3. modificar el registro en la base de datos
            ResultSet r = consulta("UPDATE estudiantes SET nombre = '" + nombre + "', telefono = '" + telefono + "', email = '" + email + "', anioingreso = '" + anioingreso + "' WHERE id = " + id);
            // 4. actualizar la tabla
            table.setModel(new TableModel() {
                @Override
                public int getRowCount() {
                    return data.size();
                }

                @Override
                public int getColumnCount() {
                    return columnNames.size();
                }

                @Override
                public String getColumnName(int columnIndex) {
                    return columnNames.get(columnIndex);
                }

                @Override
                public Class<?> getColumnClass(int columnIndex) {
                    return String.class;
                }

                @Override
                public boolean isCellEditable(int rowIndex, int columnIndex) {
                    return false;
                }

                @Override
                public Object getValueAt(int rowIndex, int columnIndex) {
                    return data.get(rowIndex)[columnIndex];
                }

                @Override
                public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
                    data.get(rowIndex)[columnIndex] = aValue;
                }

                @Override
                public void addTableModelListener(TableModelListener l) {
                }

                @Override
                public void removeTableModelListener(TableModelListener l) {
                }
            });
        
        });
        button4.addActionListener(e -> {
            // buscar por id
            // 1. obtener el id del registro a buscar
            String id = JOptionPane.showInputDialog("Id");
            // 2. buscar el registro en la base de datos
            ResultSet r = consulta("SELECT * FROM estudiantes WHERE id = " + id);
            // 3. actualizar la tabla
            table.setModel(new TableModel() {
                @Override
                public int getRowCount() {
                    return data.size();
                }

                @Override
                public int getColumnCount() {
                    return columnNames.size();
                }

                @Override
                public String getColumnName(int columnIndex) {
                    return columnNames.get(columnIndex);
                }

                @Override
                public Class<?> getColumnClass(int columnIndex) {
                    return String.class;
                }

                @Override
                public boolean isCellEditable(int rowIndex, int columnIndex) {
                    return false;
                }

                @Override
                public Object getValueAt(int rowIndex, int columnIndex) {
                    return data.get(rowIndex)[columnIndex];
                }

                @Override
                public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
                    data.get(rowIndex)[columnIndex] = aValue;
                }

                @Override
                public void addTableModelListener(TableModelListener l) {
                }

                @Override
                public void removeTableModelListener(TableModelListener l) {
                }
            });
        });
        button5.addActionListener(e -> {
            // buscar por nombre
            // 1. obtener el nombre del registro a buscar
            String nombre = JOptionPane.showInputDialog("Nombre");
            // 2. buscar el registro en la base de datos
            ResultSet r = consulta("SELECT * FROM estudiantes WHERE nombre = '" + nombre + "'");
            // 3. actualizar la tabla
            table.setModel(new TableModel() {
                @Override
                public int getRowCount() {
                    return data.size();
                }

                @Override
                public int getColumnCount() {
                    return columnNames.size();
                }

                @Override
                public String getColumnName(int columnIndex) {
                    return columnNames.get(columnIndex);
                }

                @Override
                public Class<?> getColumnClass(int columnIndex) {
                    return String.class;
                }

                @Override
                public boolean isCellEditable(int rowIndex, int columnIndex) {
                    return false;
                }

                @Override
                public Object getValueAt(int rowIndex, int columnIndex) {
                    return data.get(rowIndex)[columnIndex];
                }

                @Override
                public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
                    data.get(rowIndex)[columnIndex] = aValue;
                }

                @Override
                public void addTableModelListener(TableModelListener l) {
                }

                @Override
                public void removeTableModelListener(TableModelListener l) {
                }
            });
        });      

        JFrame frame = new JFrame("Estudiantes");
        // agregar los botones al panel
        panel.add(button1);
        panel.add(button2);
        panel.add(button3);
        panel.add(button4);
        panel.add(button5);
        panel.add(table);
        
        frame.add(panel);
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    public static ResultSet consulta(String query) {
        try {
            return DriverManager.getConnection("jdbc:mysql://localhost:3306/estudiantes?useTimezone=true&serverTimezone=UTC", "root", "").createStatement().executeQuery(query);
        } catch (Exception e) {
            System.out.println(e);
            return null;
        }
    }
}
