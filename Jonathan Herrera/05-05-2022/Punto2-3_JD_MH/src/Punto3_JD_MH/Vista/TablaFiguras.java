/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package Punto3_JD_MH.Vista;

import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

import Punto3_JD_MH.Controlador.Controlador;
import Punto3_JD_MH.Modelo.Figura;

/**
 *
 * @author User
 */
public class TablaFiguras extends javax.swing.JFrame {

    
    private Controlador c;
    
    /**
     * Creates new form TablaFiguras
     */
    public TablaFiguras(Controlador c) {
        this.c = c;
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        btnIngresar = new javax.swing.JButton();
        btnCalcular = new javax.swing.JButton();
        btnPromedio = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("Tabla de Figuras");

        btnIngresar.setText("Ingresar");
        btnIngresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnIngresarActionPerformed(evt);
            }
        });

        btnCalcular.setText("Calcular");
        btnCalcular.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCalcularActionPerformed(evt);
            }
        });

        btnPromedio.setText("Promedio");
        btnPromedio.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnPromedioActionPerformed(evt);
            }
        });

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
            },
            new String [] {
            }
        ));
        jScrollPane1.setViewportView(jTable1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 562, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(btnIngresar)
                                .addGap(18, 18, 18)
                                .addComponent(btnCalcular)
                                .addGap(18, 18, 18)
                                .addComponent(btnPromedio))
                            .addComponent(jLabel1))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 258, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnIngresar)
                    .addComponent(btnCalcular)
                    .addComponent(btnPromedio))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnIngresarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnIngresarActionPerformed
        c.ingresarFigura();
    }//GEN-LAST:event_btnIngresarActionPerformed

    private void btnCalcularActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCalcularActionPerformed
        // Pedir el indice de la figura a calcular
        String indice = JOptionPane.showInputDialog("Ingrese el indice de la figura a calcular");
        if (indice != null) {
            try {
                int ind = Integer.parseInt(indice);
                JOptionPane.showMessageDialog(null, "El area de la figura es: " + c.getFigura(ind).calcularArea());
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(this, "El indice debe ser un numero entero");
            }
        }

    }//GEN-LAST:event_btnCalcularActionPerformed

    private void btnPromedioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnPromedioActionPerformed
        JOptionPane.showMessageDialog(null, "El promedio de las areas es: " + c.promedioAreas());
    }//GEN-LAST:event_btnPromedioActionPerformed

    // Actualizar la tabla
    public void actualizarTabla() {
        DefaultTableModel modelo = (DefaultTableModel) jTable1.getModel();
        modelo.setRowCount(0);

        String [] encabezados = {"Indice", "Tipo", "Area", "Detalles"};
        modelo.setColumnIdentifiers(encabezados);

        int count = 0;
        for (Figura f : c.getFiguras()) {
            Object [] fila = new Object[4];
            fila[0] = count;
            fila[1] = f.getNombre();
            fila[2] = f.calcularArea();
            fila[3] = f.toString();
            modelo.addRow(fila);
            count++;
        }
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnCalcular;
    private javax.swing.JButton btnIngresar;
    private javax.swing.JButton btnPromedio;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable jTable1;
    // End of variables declaration//GEN-END:variables
}