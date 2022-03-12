import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        // Ventana Autor
        JFrame autor = new JFrame("Autor");
        autor.setSize(600, 500);
        autor.setLocationRelativeTo(null);
        autor.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Formulario: Nombre(Texto), Apellido(Texto), Pais(ComboBox), Generos
        // Literarios(CheckBox), Guardar(Boton)
        JPanel panel = new JPanel();
        JPanel panelGeneros = new JPanel();
        panel.setLayout(new GridLayout(9, 1));
        JLabel nombre = new JLabel("Nombre");
        JLabel apellido = new JLabel("Apellido");
        JLabel pais = new JLabel("Pais");
        JLabel generos = new JLabel("Generos Literarios");
        JTextField nombreText = new JTextField();
        JTextField apellidoText = new JTextField();
        JComboBox paisCombo = new JComboBox();
        paisCombo.addItem("Colombia");
        paisCombo.addItem("Mexico");
        paisCombo.addItem("Peru");
        paisCombo.addItem("Venezuela");
        paisCombo.addItem("Ecuador");
        paisCombo.addItem("Argentina");
        paisCombo.addItem("Brasil");
        paisCombo.addItem("Chile");
        paisCombo.addItem("Uruguay");
        paisCombo.addItem("Paraguay");
        paisCombo.addItem("Bolivia");
        paisCombo.addItem("Panama");
        paisCombo.addItem("Costa Rica");

        JCheckBox literatura = new JCheckBox("Literatura");
        JCheckBox historia = new JCheckBox("Historia");
        JCheckBox filosofia = new JCheckBox("Filosofia");
        JCheckBox tecnologia = new JCheckBox("Tecnologia");
        JCheckBox ciencia = new JCheckBox("Ciencia");
        JCheckBox deportes = new JCheckBox("Deportes");
        JCheckBox musica = new JCheckBox("Musica");

        JButton guardar = new JButton("Guardar");
        panel.add(nombre);
        panel.add(nombreText);
        panel.add(apellido);
        panel.add(apellidoText);
        panel.add(pais);
        panel.add(paisCombo);
        panel.add(generos);

        panelGeneros.add(literatura);
        panelGeneros.add(historia);
        panelGeneros.add(filosofia);
        panelGeneros.add(tecnologia);
        panelGeneros.add(ciencia);
        panelGeneros.add(deportes);
        panelGeneros.add(musica);
        
        panel.add(panelGeneros);

        panel.add(guardar);
        autor.add(panel);
        autor.setVisible(true);

        // Funcionalidad
        guardar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String nombre = nombreText.getText();
                String apellido = apellidoText.getText();
                String pais = paisCombo.getSelectedItem().toString();
                String generos = "";
                if (literatura.isSelected()) {
                    generos += "Literatura, ";
                }
                if (historia.isSelected()) {
                    generos += "Historia, ";
                }
                if (filosofia.isSelected()) {
                    generos += "Filosofia, ";
                }
                if (tecnologia.isSelected()) {
                    generos += "Tecnologia, ";
                }
                if (ciencia.isSelected()) {
                    generos += "Ciencia, ";
                }
                if (deportes.isSelected()) {
                    generos += "Deportes, ";
                }
                if (musica.isSelected()) {
                    generos += "Musica, ";
                }
                System.out.println("Nombre: " + nombre);
                System.out.println("Apellido: " + apellido);
                System.out.println("Pais: " + pais);
                System.out.println("Generos Literarios: " + generos);

                // Mostrar JOptionPane con el pais seleccionado
                JOptionPane.showMessageDialog(null, "Pais: " + pais);
                
            }
        });

    }
}