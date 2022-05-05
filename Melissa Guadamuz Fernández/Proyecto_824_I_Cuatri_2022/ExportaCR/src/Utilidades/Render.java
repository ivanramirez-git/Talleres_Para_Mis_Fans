package Utilidades;

import java.awt.Component;

import javax.swing.JButton;
import javax.swing.table.DefaultTableCellRenderer;

public class Render extends DefaultTableCellRenderer {

    @Override
    public Component getTableCellRendererComponent(javax.swing.JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
        
        if (value instanceof JButton) {
            return (JButton) value;        
        }

        return super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
    }
}