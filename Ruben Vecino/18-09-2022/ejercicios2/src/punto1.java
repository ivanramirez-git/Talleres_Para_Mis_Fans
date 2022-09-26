import java.util.Scanner;

public class punto1 {
    /*
     * 1. Adivina el personaje
     * Escriba un programa que pida al usuario elegir uno de los personajes de la
     * lista de abajo (sin
     * informar de su elección a su programa). Posteriormente, su programa debe
     * hacer al usuario
     * un conjunto de preguntas (máximo 5) de tipo Sí/No hasta determinar el
     * personaje escogido
     * por el usuario.
     * Personajes: Radamel Falcao García, Goku, Michael Jordan, Eminem, Darth Vader,
     * Adam
     * Sandler, Bruce Wayne, Tin Tin, Ayudante de Santa, Joe Biden, José Saramago,
     * Günter Grass
     * y Kim Jong Un.
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);// Objeto para leer datos de teclado
        String personaje = ""; // Variable para guardar el personaje
        String respuesta = ""; // Variable para guardar la respuesta del usuario
        System.out.println("Adivina el personaje"); // Mensaje de bienvenida
        System.out.println("Elija un personaje de la lista, mantenlo en mente"); // Mensaje de elección de personaje
        String[] personajes = { "Radamel Falcao García", "Goku", "Michael Jordan", "Eminem", "Darth Vader",
                "Adam Sandler", "Bruce Wayne", "Tin Tin", "Ayudante de Santa", "Joe Biden", "José Saramago",
                "Günter Grass", "Kim Jong Un" }; // Lista de personajes
        for (int i = 0; i < personajes.length; i++) { // Ciclo para mostrar la lista de personajes
            System.out.println((i + 1) + ". " + personajes[i]); // Mostrar personajes
        } // Fin ciclo

        // Base de datos de preguntas
        String preguntasFalcao[] = { "¿Es un futbolista?", "¿Es colombiano?", "¿Juega en el Rayo Vallecano?",
                "¿Jugó en el Atlético de Madrid?", "¿Nacio en Santa Marta?", "¿Es Radamel Falcao García" }; // Deportista
        String preguntasGoku[] = { "¿Es un personaje de anime?", "¿Es un Saiyajin?", "¿Es un guerrero?",
                "¿Es un super sayayin?", "¿Es Goku?" }; // Anime
        String preguntasJordan[] = { "¿Es un jugador de baloncesto?", "¿Jugó en los Chicago Bulls?",
                "¿Es el mejor jugador de la historia?", "¿Fué campeón de la NBA?", "¿Es estadounidense?",
                "¿Es Michael Jordan?" }; // Deportista
        String preguntasEminem[] = { "¿Es un rapero?", "¿Es de Detroit?", "¿Es Marshall Bruce Mathers III?",
                "¿Es Eminem?" }; // Músico
        String preguntasVader[] = { "¿Es un personaje de Star Wars?", "¿Es un Sith?", "¿Es un villano?",
                "¿Es un Lord Sith?", "¿Es Darth Vader?" }; // Cine
        String preguntasSandler[] = { "¿Es un actor?", "¿Es un comediante?", "¿Es un actor de comedia?",
                "¿Es Adam Sandler?" }; // Cine
        String preguntasWayne[] = { "¿Es un personaje de DC Comics?", "¿Es un superhéroe?", "¿Es Batman?",
                "¿Es Bruce Wayne?" }; // Cine
        String preguntasTinTin[] = { "¿Es un personaje de cómic?", "¿Es un reportero?", "¿Es un joven?", "¿Es un niño?",
                "¿Es Tin Tin?" }; // Anime
        String preguntasAyudanteSanta[] = { "¿Es un personaje de Navidad?", "¿Es un ayudante de Santa Claus?",
                "¿Es un elfo?", "¿Es un ayudante de Santa?" }; // Navidad
        String preguntasBiden[] = { "¿Fue un senador?", "¿Es un presidente?", "¿Es Joe Biden?" }; // Político
        String preguntasSaramago[] = { "¿Es portugués?", "¿Es José Saramago?" }; // Escritor
        String preguntasGrass[] = { "¿Es alemán?", "¿Es Günter Grass?" }; // Escritor
        String preguntasJongUn[] = { "¿Es un dictador?", "¿Es un líder militar?", "¿Es un líder de Corea del Norte?",
                "¿Es Kim Jong Un?" }; // Político
        // "¿Es un escritor?","¿Es un líder político?","¿Es un político?", "¿Es un
        // deportista?"
        String preguntasGenerales[] = { "¿Tu personaje es o fue un deportista?", "¿Tu personaje es un animé?",
                "¿Tu personaje es un músico?", "¿Tu personaje tiene que ver con el cine?",
                "¿Tu personaje es un personaje de Navidad?", "¿Tu personaje es un político?",
                "¿Tu personaje es un escritor?" }; // Preguntas generales
        // Vector de preguntas
        String todasPreguntas[] = new String[preguntasGenerales.length + preguntasFalcao.length + preguntasGoku.length
                + preguntasJordan.length + preguntasEminem.length + preguntasVader.length + preguntasSandler.length
                + preguntasWayne.length + preguntasTinTin.length + preguntasAyudanteSanta.length + preguntasBiden.length
                + preguntasSaramago.length + preguntasGrass.length + preguntasJongUn.length];
        // donde la primera columna son los nombres, y cada columna siguiente
        // corresponde a una pregunta, se coloca true o false si esa pregunta aplica
        // para ese personaje
        boolean respuestas[][] = new boolean[personajes.length][preguntasGenerales.length + preguntasFalcao.length
                + preguntasGoku.length
                + preguntasJordan.length + preguntasEminem.length + preguntasVader.length + preguntasSandler.length
                + preguntasWayne.length + preguntasTinTin.length + preguntasAyudanteSanta.length + preguntasBiden.length
                + preguntasSaramago.length + preguntasGrass.length + preguntasJongUn.length]; // Vector de respuestas
        // 1. Radamel Falcao García
        int contador = 0; // Contador de preguntas
        for (int i = 0; i < preguntasFalcao.length; i++) {
            todasPreguntas[contador] = preguntasFalcao[i];
            respuestas[0][contador] = true;
            contador++;
        }
        // 2. Goku
        for (int i = 0; i < preguntasGoku.length; i++) {
            todasPreguntas[contador] = preguntasGoku[i];
            respuestas[1][contador] = true;
            contador++;
        }
        // 3. Michael Jordan
        for (int i = 0; i < preguntasJordan.length; i++) {
            todasPreguntas[contador] = preguntasJordan[i];
            respuestas[2][contador] = true;
            contador++;
        }
        // 4. Eminem
        for (int i = 0; i < preguntasEminem.length; i++) {
            todasPreguntas[contador] = preguntasEminem[i];
            respuestas[3][contador] = true;
            contador++;
        }
        // 5. Darth Vader
        for (int i = 0; i < preguntasVader.length; i++) {
            todasPreguntas[contador] = preguntasVader[i];
            respuestas[4][contador] = true;
            contador++;
        }
        // 6. Adam Sandler
        for (int i = 0; i < preguntasSandler.length; i++) {
            todasPreguntas[contador] = preguntasSandler[i];
            respuestas[5][contador] = true;
            contador++;
        }
        // 7. Bruce Wayne
        for (int i = 0; i < preguntasWayne.length; i++) {
            todasPreguntas[contador] = preguntasWayne[i];
            respuestas[6][contador] = true;
            contador++;
        }
        // 8. Tin Tin
        for (int i = 0; i < preguntasTinTin.length; i++) {
            todasPreguntas[contador] = preguntasTinTin[i];
            respuestas[7][contador] = true;
            contador++;
        }
        // 9. Ayudante de Santa
        for (int i = 0; i < preguntasAyudanteSanta.length; i++) {
            todasPreguntas[contador] = preguntasAyudanteSanta[i];
            respuestas[8][contador] = true;
            contador++;
        }
        // 10. Joe Biden
        for (int i = 0; i < preguntasBiden.length; i++) {
            todasPreguntas[contador] = preguntasBiden[i];
            respuestas[9][contador] = true;
            contador++;
        }
        // 11. José Saramago
        for (int i = 0; i < preguntasSaramago.length; i++) {
            todasPreguntas[contador] = preguntasSaramago[i];
            respuestas[10][contador] = true;
            contador++;
        }
        // 12. Günter Grass
        for (int i = 0; i < preguntasGrass.length; i++) {
            todasPreguntas[contador] = preguntasGrass[i];
            respuestas[11][contador] = true;
            contador++;
        }
        // 13. Kim Jong Un
        for (int i = 0; i < preguntasJongUn.length; i++) {
            todasPreguntas[contador] = preguntasJongUn[i];
            respuestas[12][contador] = true;
            contador++;
        }
        // Preguntas generales
        // Deportistas
        todasPreguntas[contador] = preguntasGenerales[0];
        respuestas[0][contador] = true;
        respuestas[2][contador] = true;
        contador++;
        // Animé
        todasPreguntas[contador] = preguntasGenerales[1];
        respuestas[1][contador] = true;
        respuestas[7][contador] = true;
        contador++;
        // Músicos
        todasPreguntas[contador] = preguntasGenerales[2];
        respuestas[3][contador] = true;
        contador++;
        // Cine
        todasPreguntas[contador] = preguntasGenerales[3];
        respuestas[4][contador] = true;
        respuestas[5][contador] = true;
        respuestas[6][contador] = true;
        contador++;
        // Navidad
        todasPreguntas[contador] = preguntasGenerales[4];
        respuestas[8][contador] = true;
        contador++;
        // Políticos
        todasPreguntas[contador] = preguntasGenerales[5];
        respuestas[9][contador] = true;
        respuestas[10][contador] = true;
        respuestas[11][contador] = true;
        respuestas[12][contador] = true;
        contador++;
        // Escritores
        todasPreguntas[contador] = preguntasGenerales[6];
        respuestas[10][contador] = true;
        respuestas[11][contador] = true;
        contador++;
        preguntadera(todasPreguntas, personajes, respuestas);
        sc.close();
    }

    // funcion que devuelve un numero aleatorio entre un minimo y un maximo
    public static int numeroAleatorio(int minimo, int maximo) {
        int num = (int) Math.floor(Math.random() * (minimo - (maximo + 1)) + (maximo + 1));
        return num;
    }

    public static void preguntadera(String[] todasPreguntas, String[] personajes, boolean[][] respuestas) {
        boolean fin = false;
        int contador = 0;
        boolean[] preguntasHechas = new boolean[todasPreguntas.length]; // falso si no se ha hecho la pregunta
        // todo en falso
        for (int i = 0; i < preguntasHechas.length; i++) {
            preguntasHechas[i] = false;
        }
        // respuestas del usuario
        int respuestasUsuario[] = new int[todasPreguntas.length]; // -1 sin responder, 0 no, 1 si
        // colocar tdo en -1
        for (int i = 0; i < respuestasUsuario.length; i++) {
            respuestasUsuario[i] = -1;
        }
        Scanner sc = new Scanner(System.in);
        while (!fin) {
            int pregunta = numeroAleatorio(0, todasPreguntas.length - 1);
            if (!preguntasHechas[pregunta]) {
                System.out.println(todasPreguntas[pregunta]);
                System.out.println("1. Si");
                System.out.println("2. No");
                System.out.println("3. No se");
                int respuesta = sc.nextInt();
                if (respuesta == 1) {
                    respuestasUsuario[pregunta] = 1;
                } else if (respuesta == 2) {
                    respuestasUsuario[pregunta] = 0;
                } else if (respuesta == 3) {
                    respuestasUsuario[pregunta] = -1;
                }
                preguntasHechas[pregunta] = true;
                contador++;
            }
            if (contador == todasPreguntas.length) {
                fin = true;
            }
        }
        // comprobar respuestas
        int contadorPersonajes = 0;
        for (int i = 0; i < personajes.length; i++) {
            boolean personaje = true;
            for (int j = 0; j < respuestasUsuario.length; j++) {
                if (respuestasUsuario[j] == 1) {
                    if (!respuestas[i][j]) {
                        personaje = false;
                    }
                } else if (respuestasUsuario[j] == 0) {
                    if (respuestas[i][j]) {
                        personaje = false;
                    }
                }
            }
            if (personaje) {
                System.out.println(personajes[i]);
                contadorPersonajes++;
            }
        }
        if (contadorPersonajes == 0) {
            System.out.println("No se ha encontrado ningún personaje");
        }

    }

}