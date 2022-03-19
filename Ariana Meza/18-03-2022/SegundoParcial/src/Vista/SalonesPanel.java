package Vista;

import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class SalonesPanel extends JPanel {

    // Boton que envie un Hola Mundo
    JButton btnHolaMundo;

    public SalonesPanel() {
        // Crear un JButton
        btnHolaMundo = new JButton("Hola Mundo");
        // Añadir el JButton al panel
        add(btnHolaMundo);
        // Añadir un Listener al JButton
        btnHolaMundo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnHolaMundoActionPerformed(evt);
            }
        });

    }

    private void btnHolaMundoActionPerformed(java.awt.event.ActionEvent evt) {
        JOptionPane.showMessageDialog(null, "Hola Mundo");
    }

}