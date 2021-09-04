import com.company.Tablero;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static boolean entradaUsuario; // Si ingresa algo erroneo, entonces es falso
    static Tablero tablero; //Tablero
    public static int numeroTurno = 0; //Cuantas tiradas se han hecho

    public static void main(String[] args) {
        int ganador = 0;
        int intentoJugador;
        entradaUsuario = true;
        tablero = new Tablero(7, 6);

        while (ganador == 0) {
            tablero.imprimirTablero();

            intentoJugador = numeroTurno % 2 + 1;
            while (!turno(0, intentoJugador)) {
                System.out.println("Intento invalido");

            }
            numeroTurno++;

            ganador = darGanador();
        }

        mostrarGanador(ganador);
    }

    private static int entradaUsuario() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); //entrada por teclado
        int num;
        try {
            String texto = reader.readLine();
            if (texto.isEmpty()) {
                return -1;
            }
            num = Integer.parseInt(texto) - 1; //se tira en la columna-1, ya que el vector es de 0 a cols-1
        } catch (IOException | NumberFormatException e) {
            return -1;
        }
        return num;
    }

    public static boolean turno(int pos, int turnoJugador) { //Función que ejecuta cada tirada, devuelve falso si no se ha podido realizar
        System.out.println("Jugador " + turnoJugador);

        int num;
        if (entradaUsuario) {
            num = entradaUsuario();
        } else {
            num = pos;
        }

        if (num < 0 || num > tablero.getColumnas() - 1) {
            return false;
        }

        return tablero.marcarIntento(num, turnoJugador);
    }

    private static int darGanador() {
        int ganador = tablero.chequearTablero();

        if (ganador == 0 && numeroTurno == tablero.getColumnas() * tablero.getFilas()) { // Empate
            ganador = -1;
        }
        return ganador;
    }

    private static void mostrarGanador(int ganador) {
        tablero.imprimirTablero();
        System.out.println();
        if (ganador == -1) {
            System.out.println("Esto es un empate.");
        } else {
            System.out.println("El Jugador " + ganador+ " gana.");
        }
    }
}