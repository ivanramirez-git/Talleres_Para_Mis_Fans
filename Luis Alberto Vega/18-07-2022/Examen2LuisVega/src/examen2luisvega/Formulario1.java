/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package examen2luisvega;

import java.util.ArrayList;

import javax.swing.JOptionPane;

/**
 *
 * @author User
 */
public class Formulario1 extends javax.swing.JFrame {

    /**
     * Creates new form Main
     */
    public Formulario1() {

        clientes = new ArrayList<>();
        facturas = new ArrayList<>();

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
        jLabel2 = new javax.swing.JLabel();
        txtNombre = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        txtCedula = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        txtTelefono = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        txtDireccion = new javax.swing.JTextField();
        btnElecticidad = new javax.swing.JButton();
        btnAgua = new javax.swing.JButton();
        btnCable = new javax.swing.JButton();
        btnTelefono = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("SERVICIOS PUBLICOS");

        jLabel2.setText("Nombre:");

        jLabel3.setText("Cedula:");

        jLabel4.setText("Teléfono:");
        jLabel4.setToolTipText("");

        jLabel5.setText("Dirección");

        btnElecticidad.setText("Electricidad");
        btnElecticidad.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnElecticidadActionPerformed(evt);
            }
        });

        btnAgua.setText("Agua");
        btnAgua.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAguaActionPerformed(evt);
            }
        });

        btnCable.setText("Cable");
        btnCable.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCableActionPerformed(evt);
            }
        });

        btnTelefono.setText("Teléfono");
        btnTelefono.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnTelefonoActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(btnElecticidad, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnCable, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 25, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(btnAgua, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnTelefono, javax.swing.GroupLayout.PREFERRED_SIZE, 91, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(6, 6, 6)
                                .addComponent(jLabel1))
                            .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel2)
                                    .addComponent(jLabel3)
                                    .addComponent(jLabel4)
                                    .addComponent(jLabel5))
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(txtTelefono, javax.swing.GroupLayout.DEFAULT_SIZE, 139, Short.MAX_VALUE)
                                    .addComponent(txtDireccion)
                                    .addComponent(txtCedula)
                                    .addComponent(txtNombre))))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(txtNombre, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(txtCedula, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(txtTelefono, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(txtDireccion, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnElecticidad)
                    .addComponent(btnAgua))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnCable)
                    .addComponent(btnTelefono))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    // Lista de clientes
    private ArrayList<Cliente> clientes;
    // Lista de facturas
    private ArrayList<Factura> facturas;

    private void btnElecticidadActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnElecticidadActionPerformed
        // Verificar que todos los campos esten llenos
        if (txtNombre.getText().isEmpty() || txtCedula.getText().isEmpty() || txtTelefono.getText().isEmpty() || txtDireccion.getText().isEmpty()) {
            JOptionPane.showMessageDialog(this, "Todos los campos deben estar llenos");
            System.out.println("Nombre: " + txtNombre.getText());
            System.out.println("Cedula: " + txtCedula.getText());
            System.out.println("Telefono: " + txtTelefono.getText());
            System.out.println("Direccion: " + txtDireccion.getText());
        } else {
            // Crear un nuevo cliente
            Cliente cliente = new Cliente(txtNombre.getText(), txtCedula.getText(), txtTelefono.getText(), txtDireccion.getText());
            // Agregarlo a la lista de clientes
            clientes.add(cliente);
            // Crear una nueva factura
            Factura factura = new Factura(facturas.size() + 1, "001");
            // Agregarla a la lista de facturas
            facturas.add(factura);
            // Mostrar mensaje de exito
            JOptionPane.showMessageDialog(this, "Cliente agregado con exito");
            // Redireccionar a la pantalla de facturacion: Formulario2.java
            Formulario2 formulario2 = new Formulario2(cliente, factura, this);
            formulario2.setVisible(true);
            this.setVisible(false);
        }
    }//GEN-LAST:event_btnElecticidadActionPerformed

    private void btnAguaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAguaActionPerformed
        // Verificar que todos los campos esten llenos
        if (txtNombre.getText().isEmpty() || txtCedula.getText().isEmpty() || txtTelefono.getText().isEmpty() || txtDireccion.getText().isEmpty()) {
            JOptionPane.showMessageDialog(this, "Todos los campos deben estar llenos");
            System.out.println("Nombre: " + txtNombre.getText());
            System.out.println("Cedula: " + txtCedula.getText());
            System.out.println("Telefono: " + txtTelefono.getText());
            System.out.println("Direccion: " + txtDireccion.getText());
        } else {
            // Crear un nuevo cliente
            Cliente cliente = new Cliente(txtNombre.getText(), txtCedula.getText(), txtTelefono.getText(), txtDireccion.getText());
            // Agregarlo a la lista de clientes
            clientes.add(cliente);
            // Crear una nueva factura
            Factura factura = new Factura(facturas.size() + 1, "002");
            // Agregarla a la lista de facturas
            facturas.add(factura);
            // Mostrar mensaje de exito
            JOptionPane.showMessageDialog(this, "Cliente agregado con exito");
            // Redireccionar a la pantalla de facturacion: Formulario2.java
            Formulario2 formulario2 = new Formulario2(cliente, factura, this);
            formulario2.setVisible(true);
            this.setVisible(false);
        }
    }//GEN-LAST:event_btnAguaActionPerformed

    private void btnCableActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCableActionPerformed
        // Verificar que todos los campos esten llenos
        if (txtNombre.getText().isEmpty() || txtCedula.getText().isEmpty() || txtTelefono.getText().isEmpty() || txtDireccion.getText().isEmpty()) {
            JOptionPane.showMessageDialog(this, "Todos los campos deben estar llenos");
            System.out.println("Nombre: " + txtNombre.getText());
            System.out.println("Cedula: " + txtCedula.getText());
            System.out.println("Telefono: " + txtTelefono.getText());
            System.out.println("Direccion: " + txtDireccion.getText());
        } else {
            // Crear un nuevo cliente
            Cliente cliente = new Cliente(txtNombre.getText(), txtCedula.getText(), txtTelefono.getText(), txtDireccion.getText());
            // Agregarlo a la lista de clientes
            clientes.add(cliente);
            // Crear una nueva factura
            Factura factura = new Factura(facturas.size() + 1, "003");
            // Agregarla a la lista de facturas
            facturas.add(factura);
            // Mostrar mensaje de exito
            JOptionPane.showMessageDialog(this, "Cliente agregado con exito");
            // Redireccionar a la pantalla de facturacion: Formulario2.java
            Formulario2 formulario2 = new Formulario2(cliente, factura, this);
            formulario2.setVisible(true);
            this.setVisible(false);
        }
    }//GEN-LAST:event_btnCableActionPerformed

    private void btnTelefonoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnTelefonoActionPerformed
        // Verificar que todos los campos esten llenos
        if (txtNombre.getText().isEmpty() || txtCedula.getText().isEmpty() || txtTelefono.getText().isEmpty() || txtDireccion.getText().isEmpty()) {
            JOptionPane.showMessageDialog(this, "Todos los campos deben estar llenos");
            System.out.println("Nombre: " + txtNombre.getText());
            System.out.println("Cedula: " + txtCedula.getText());
            System.out.println("Telefono: " + txtTelefono.getText());
            System.out.println("Direccion: " + txtDireccion.getText());
        } else {
            // Crear un nuevo cliente
            Cliente cliente = new Cliente(txtNombre.getText(), txtCedula.getText(), txtTelefono.getText(), txtDireccion.getText());
            // Agregarlo a la lista de clientes
            clientes.add(cliente);
            // Crear una nueva factura
            Factura factura = new Factura(facturas.size() + 1, "004");
            // Agregarla a la lista de facturas
            facturas.add(factura);
            // Mostrar mensaje de exito
            JOptionPane.showMessageDialog(this, "Cliente agregado con exito");
            // Redireccionar a la pantalla de facturacion: Formulario2.java
            Formulario2 formulario2 = new Formulario2(cliente, factura, this);
            formulario2.setVisible(true);
            this.setVisible(false);
        }
    }//GEN-LAST:event_btnTelefonoActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Formulario1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Formulario1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Formulario1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Formulario1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Formulario1().setVisible(true);
            }
        });
    }

    public void limpiar() {
        txtNombre.setText("");
        txtCedula.setText("");
        txtTelefono.setText("");
        txtDireccion.setText("");
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnAgua;
    private javax.swing.JButton btnCable;
    private javax.swing.JButton btnElecticidad;
    private javax.swing.JButton btnTelefono;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JTextField txtCedula;
    private javax.swing.JTextField txtDireccion;
    private javax.swing.JTextField txtNombre;
    private javax.swing.JTextField txtTelefono;
    // End of variables declaration//GEN-END:variables
}
