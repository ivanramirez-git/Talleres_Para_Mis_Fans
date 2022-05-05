/*
Universidad Estatal a Distancia
Estudiante:Melissa Guadamuz Fernández
Cedula:113870559
Centro Universitario San José
Grupo # 1
Tutor JOSE MANUEL SALAZAR HERRERA
Tarea#1
Primer Cuatrimestre 2022
*/
package Utilidades;

import java.awt.Component;

import javax.swing.JButton;
import javax.swing.table.DefaultTableCellRenderer;

/**
 *
 * @author melig
 */
public class Render extends DefaultTableCellRenderer {

    @Override
    public Component getTableCellRendererComponent(javax.swing.JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
        
        if (value instanceof JButton) {
            return (JButton) value;        
        }

        return super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
    }
}