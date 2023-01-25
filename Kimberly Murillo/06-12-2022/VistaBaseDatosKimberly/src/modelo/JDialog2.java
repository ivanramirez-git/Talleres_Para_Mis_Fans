package modelo;

import java.sql.ResultSet;

import javax.swing.JDialog;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

import controlador.Conexion;

public class JDialog2 extends JDialog {
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

    private JTable jTable1; // Tabla para mostrar los datos del producto
    private Conexion c;

    public static void iniciar(String args[]) {
        /*
         * Crear un objeto de la clase JDialog2 y mostrarlo
         */
    }

    public JDialog2() {
        /*
         * Inicializar los componentes del JDialog
         */
        // Inicializar la conexión
        c = new Conexion();
        jTable1 = new JTable();
        // Agregar los componentes al JDialog
        // Llamar funcion UpdateTable() para actualizar la tabla
        try {
            UpdateTable();
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        // Dimenciones del JDialog
        this.setSize(275, 85);
        // agregar la tabla al JDialog con un scroll y dimensiones
        this.add(new javax.swing.JScrollPane(jTable1), java.awt.BorderLayout.CENTER);
        // Mostrar el JDialog
        this.setVisible(true);
    }

    private void UpdateTable() throws Exception {
        /*
         * Actualizar la tabla con los datos del producto
         */
        ResultSet rs = (ResultSet) c.consultar("CALL mostrarInventario();");
        System.out.println(rs.toString());
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

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {
        /*
         * Al hacer click en el botón buscar, se debe mostrar en la tabla los datos del
         * producto
         * con el ID que se ingresó en el campo de texto
         */
    }

}
