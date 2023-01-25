package modelo;

import java.sql.ResultSet;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

import controlador.Conexion;

public class JDialog3 extends JDialog {
    /*
     * Se necesita mostrar al usuario en un JDialoj que es llamado desde un botón
     * (Ejercicio 2)
     * del JFrame frmPricipal, el valor total del inventario existente y el total de
     * productos
     * (todas las unidades existentes) que hay en la tabla productos (Use funciones
     * de agregado
     * de SQL en los procedimientos almacenados). El valor en colones del inventario
     * se
     * obtiene de la sumatoria del precio de costo de todos los productos que existe
     * en la BD.
     * (Haga un procedimiento almacenado) 10 pts
     */

    /*
     * EJEMPLO DEL FORM:
     * |----------------------------------------|
     * | ID producto a visualizar: [__________] |
     * | |
     * | (BUSCAR) |
     * |----------------------------------------|
     * | Producto: |
     * | |
     * ...
     * |----------------------------------------|
     */

    private JButton jButton1; // Boton de buscar
    private JTextField jTextField1; // Campo de texto para el ID del producto
    private JLabel jLabel1; // Etiqueta para el ID del producto
    private JTable jTable1; // Tabla para mostrar los datos del producto
    private Conexion c;

    public static void iniciar(String args[]) {
        /*
         * Crear un objeto de la clase JDialog2 y mostrarlo
         */
    }

    public JDialog3() {
        /*
         * Inicializar los componentes del JDialog
         */
        c = new Conexion();
        jButton1 = new JButton();
        // Cambiar el texto del botón
        jButton1.setText("Buscar");
        // Agregar un evento al botón
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jTextField1 = new JTextField();
        // Cambiar el texto del campo de texto
        jTextField1.setText("                                                       ");

        jLabel1 = new JLabel();
        // Cambiar el texto de la etiqueta
        jLabel1.setText("ID producto a visualizar: ");

        jTable1 = new JTable();
        // Llamar funcion UpdateTable() para actualizar la tabla
        try {
            UpdateTable(1111);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        // Dimenciones del JDialog
        this.setSize(575, 485);
        // agregar la tabla al JDialog con un scroll y dimensiones
        this.add(new javax.swing.JScrollPane(jTable1), java.awt.BorderLayout.CENTER);
        // agregar el botón al JDialog
        this.add(jButton1, java.awt.BorderLayout.SOUTH);
        // agregar un panel temporal al norte del JDialog
        JPanel panel = new JPanel();
        // Dimensiones del panel
        panel.setSize(575, 50);
        // Dimensiones del campo de texto
        jTextField1.setSize(250, 20);
        // Dimensiones de la etiqueta
        jLabel1.setSize(250, 20);
        // Agregar la etiqueta al panel
        panel.add(jLabel1);
        // Agregar el campo de texto al panel
        panel.add(jTextField1);
        // Agregar el panel al JDialog
        this.add(panel, java.awt.BorderLayout.NORTH);
        // Mostrar el JDialog
        this.setVisible(true);
    }

    private void UpdateTable(int id) throws Exception {
        /*
         * Actualizar la tabla con los datos del producto
         */
        ResultSet rs = (ResultSet) c.consultar("CALL buscarProducto(" + id + ");");
        DefaultTableModel model = new DefaultTableModel();
        String[] columnNames;
        // Sacar los nombres de las columnas de la consulta
        columnNames = new String[rs.getMetaData().getColumnCount()];
        for (int i = 0; i < columnNames.length; i++) {
            // Nombre asignado a la columna en la consulta AS
            columnNames[i] = rs.getMetaData().getColumnLabel(i + 1);
        }
        // Agregar los nombres de las columnas al modelo de la tabla
        model.setColumnIdentifiers(columnNames);
        // Agregar los datos de la consulta al modelo de la tabla
        while (rs.next()) {
            Object[] row = new Object[rs.getMetaData().getColumnCount()];
            for (int i = 0; i < row.length; i++) {
                row[i] = rs.getObject(i + 1);
            }
            model.addRow(row);
        }
        // Agregar el modelo de la tabla a la tabla
        jTable1.setModel(model);

    }
    /*
     * EJEMPLO DEL FORM:
     * |----------------------------------------|
     * | ID producto a visualizar: [__________] |
     * | |
     * | (BUSCAR) |
     * |----------------------------------------|
     * | Producto: |
     * | |
     * [TABLA]
     * |----------------------------------------|
     * | BOTON PARA AGREGAR 1 UNIDAD AL INVENTARIO | -> Procedimiento almacenado:
     * aumentarInventario(id, cantidad);
     * | BOTON PARA DISMINUIR 1 UNIDAD AL INVENTARIO | -> Procedimiento almacenado:
     * disminuirInventario(id, cantidad);
     * | BOTON PARA QUITAR EL PRODUCTO DEL INVENTARIO | -> Procedimiento almacenado:
     * sacarInventario(id);
     * 
     */

    private JButton jButton2; // Boton para aumentar el inventario
    private JButton jButton3; // Boton para disminuir el inventario
    private JButton jButton4; // Boton para sacar el producto del inventario

    private void inicializarBotonesControl() {
        jButton2 = new JButton();
        jButton3 = new JButton();
        jButton4 = new JButton();
        // Cambiar el texto de los botones
        jButton2.setText("Aumentar inventario");
        jButton3.setText("Disminuir inventario");
        jButton4.setText("Sacar del inventario");
        // Agregar un evento a los botones
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });
        // Agregar los botones a un panel
        JPanel panel = new JPanel();
        // Dimensiones del panel
        panel.setSize(575, 50);
        // Agregar dimencionalidad al panel
        panel.setLayout(new java.awt.GridLayout(2, 3));
        // Agregar los botones al panel con dimencionalidad
        panel.add(jButton2, java.awt.BorderLayout.WEST);
        panel.add(jButton3, java.awt.BorderLayout.CENTER);
        panel.add(jButton4, java.awt.BorderLayout.EAST);
        // quitar del dialog el boton de buscar
        this.remove(jButton1);
        // Agregar el boton de buscar al panel
        panel.add(jButton1, java.awt.BorderLayout.SOUTH);
        // Agregar el panel al JDialog
        this.add(panel, java.awt.BorderLayout.SOUTH);
    }

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {
        /*
         * Al hacer click en el botón buscar, se debe mostrar en la tabla los datos del
         * producto
         * con el ID que se ingresó en el campo de texto
         */
        try {
            int data = Integer.parseInt(jTextField1.getText().trim());
            UpdateTable(data);
            // Si la tabla tiene 1 fila, Imprimir Encontrado
            if (jTable1.getRowCount() == 1) {
                inicializarBotonesControl();
            } else {
                // Si la tabla tiene 0 filas, Imprimir No encontrado
                // Ocultar los botones de control
                jButton2.setVisible(false);
                jButton3.setVisible(false);
                jButton4.setVisible(false);
                
            }
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {
        /*
         * Al hacer click en el botón aumentar inventario, se debe aumentar en 1 la
         * cantidad del producto
         * con el ID que se ingresó en el campo de texto
         */
        try {
            int data = Integer.parseInt(jTextField1.getText().trim());
            c.consultar("CALL aumentarInventario(" + data + ", 1);");
            UpdateTable(data);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {
        /*
         * Al hacer click en el botón disminuir inventario, se debe disminuir en 1 la
         * cantidad del producto
         * con el ID que se ingresó en el campo de texto
         */
        try {
            int data = Integer.parseInt(jTextField1.getText().trim());
            c.consultar("CALL disminuirInventario(" + data + ", 1);");
            UpdateTable(data);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {
        /*
         * Al hacer click en el botón sacar del inventario, se debe sacar el producto
         * con el ID que se ingresó en el campo de texto
         */
        try {
            int data = Integer.parseInt(jTextField1.getText().trim());
            c.consultar("CALL sacarInventario(" + data + ");");
            UpdateTable(data);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}
