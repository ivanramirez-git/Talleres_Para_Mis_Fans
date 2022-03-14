import java.io.IOException;

import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

public class enJava {
    public static void main(String[] args) throws IOException {
        // Pantalla con 5 radio buttons con paises
        JFrame frame = new JFrame("Pais");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        JRadioButton rb1 = new JRadioButton("España");
        JRadioButton rb2 = new JRadioButton("Francia");
        JRadioButton rb3 = new JRadioButton("Italia");
        JRadioButton rb4 = new JRadioButton("Alemania");
        JRadioButton rb5 = new JRadioButton("Portugal");
        ButtonGroup group = new ButtonGroup();
        group.add(rb1);
        group.add(rb2);
        group.add(rb3);
        group.add(rb4);
        group.add(rb5);
        panel.add(rb1);
        panel.add(rb2);
        panel.add(rb3);
        panel.add(rb4);
        panel.add(rb5);
        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
        // Pantalla con 5 radio buttons con idiomas
        
    }
}

