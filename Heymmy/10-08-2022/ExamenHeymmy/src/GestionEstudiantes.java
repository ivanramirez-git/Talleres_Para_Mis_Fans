import javax.swing.JOptionPane;

import Modelo.Estudiante;

public class GestionEstudiantes {

    private final int MAX_ESTUDIANTES = 100;
    private Estudiante[] estudiantes;
    private int numEstudiantes;

    public GestionEstudiantes() {
        estudiantes = new Estudiante[MAX_ESTUDIANTES];
        numEstudiantes = 0;
    }

    public void agregarEstudiante(Estudiante estudiante) {
        if (numEstudiantes < MAX_ESTUDIANTES) {
            estudiantes[numEstudiantes] = estudiante;
            numEstudiantes++;
        } else {
            System.out.println("No se pueden agregar más estudiantes");
        }
    }

    public void mostrarEstudiantes() {
        for (int i = 0; i < numEstudiantes; i++) {
            System.out.println(estudiantes[i]);
        }
    }

    public void buscarPorCedula(String cedula) {
        for (int i = 0; i < numEstudiantes; i++) {
            if (estudiantes[i].getCedula().equals(cedula)) {
                JOptionPane.showMessageDialog(null, estudiantes[i].toString());
                return;
            }
        }
        JOptionPane.showMessageDialog(null, "No se encontró el estudiante");
    }

}
