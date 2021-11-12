#include <iostream>

using namespace std;

// Funcion que genera un numero aleatorio entre 1 y 19
int generarNumero() {
    int numero = rand() % 19 + 1;
    return numero;
}

// Funcion que llena un tablero con numeros aleatorios
void llenarTablero(int tablero[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tablero[i][j] = generarNumero();
        }
    }
}

// Funcion que valida que los elementos del vector suman 20
bool validarJugada(int vector[]) {
    int suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += vector[i];
    }
    if (suma == 20) {
        return true;
    } else {
        return false;
    }
}

// Funcion que valida imput de jugada retorna -2 si debe salir de la partida, -1 si se ingreso una jugada invalida y si se ingreso una jugada valida retornar la posicion de la matriz donde se encuentra la jugada
int 
validarEntrada(string imput){
    if (imput == "salirPartida") {
        return -2;
    } else {

        // Validar que el imput tenga 2 digitos
        if (imput.length() != 2) {
            return -1;
        }
        // Validar que el primer digito sea un numero entre 0 y 7
        if (imput[0] < '0' || imput[0] > '7') {
            return -1;
        }
        // Validar que el segundo digito sea un numero entre 0 y 7
        if (imput[1] < '0' || imput[1] > '7') {
            return -1;
        }

        int posicion1 = imput[0] - '0';
        int posicion2 = imput[1] - '0' - 1;
        return (posicion1 * 10 + posicion2) + 1;
    }
}

// Funcion que imprime las reglas del juego
void imprimirReglas(){
    cout << "Reglas del juego:" << endl;
    cout << "El objetivo del juego es tener el menor numero de posiciones disponibles en un tablero de 8x8. " << endl;
    cout << "Cada jugada debe ser una combinacion de 2 o 3 posiciones del tablero, esta combinacion debe sumar 20." << endl;
    cout << "Si la jugada suma 20, el jugador gana el turno y las casillas seleccionadas quedan con 0, haciendo que esa casilla no este disponible." << endl;
    cout << "Si la jugada NO suma 20, el jugador cede el turno al siguiente jugador y el tablero de ese jugador vuelve a estar como al inicio de la jugada." << endl;
    cout << "El juego termina cuando en uno de los tableros no se puede hacer ninguna jugada valida." << endl;
    cout << "Gana el jugador con menos posiciones disponibles en su tablero." << endl;
    cout << "Si hay empate, el juego termina." << endl;
    cout << "Las posiciones del tablero se numeran de la siguiente manera:" << endl;
    cout << "00 01 02 03 04 05 06 07" << endl;
    cout << "10 11 12 13 14 15 16 17" << endl;
    cout << "20 21 22 23 24 25 26 27" << endl;
    cout << "30 31 32 33 34 35 36 37" << endl;
    cout << "40 41 42 43 44 45 46 47" << endl;
    cout << "50 51 52 53 54 55 56 57" << endl;
    cout << "60 61 62 63 64 65 66 67" << endl;
    cout << "70 71 72 73 74 75 76 77" << endl;    
}

// Funcion que imprime las instrucciones del juego
void imprimirInstrucciones(){
    cout << "Instrucciones del juego:" << endl;
    cout << "Ingrese la jugada que desea realizar, donde una jugada se compone de 2 o 3 posiciones en el tablero." << endl;
    cout << "Para ingresar una posicion del tablero, ingrese dos digitos, el primer digito es la posicion en la fila y el segundo digito es la posicion en la columna." << endl;
    cout << "Ejemplo de jugada: 12, para ingresar la posicion 12 del tablero." << endl;
    cout << "Para desea salir del juego ingrese 'salir', si desea salir de la partida ingrese 'salirPartida'." << endl;
    cout << "Para imprimir las reglas del juego ingrese 'reglas'." << endl;
    cout << "Para imprimir el estado del juego ingrese 'estado'." << endl;
    cout << "Para imprimir las instrucciones del juego ingrese 'instrucciones'." << endl;

}

// Funcion que imprime un tablero con tabuladores y el nombre del jugador
void imprimirTablero(int tablero[8][8], string jugador) {
    cout << "Tablero de " << jugador << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << tablero[i][j] << "\t";
        }
        cout << endl;
    }
}

// Funcion que imprime el nombre del jugador y el tablero con tabuladores mostrando coordenadas [x][y] en los bordes
void imprimirTableroConCoordenadas(int tablero[8][8], string jugador) {
    cout << "Tablero de " << jugador << endl;
    cout << "  j\t ";
    for (int i = 0; i < 8; i++) {
        cout << i << "\t";
    }
    cout << endl;
    cout << "i \t ";
    for (int i = 0; i < 8; i++) {
        cout << "-" << "\t";
    }
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << i << "\t"<<"|";
        for (int j = 0; j < 8; j++) {
            if(j!=7){
                cout << tablero[i][j] << "\t";  
            }else{
                if(tablero[i][j]<10)
                    cout << tablero[i][j]<<" ";
                else
                    cout << tablero[i][j];
            }
        }
        cout <<"|"<< endl;
    }
    cout << "  \t ";
    for (int i = 0; i < 8; i++) {
        cout << "-" << "\t";
    }
    cout << endl;
}




// Funcion que imprime tableros y puntajes de jugadores e indica el turno del jugador
void imprimirTableros(int tablero1[8][8], int tablero2[8][8], int puntaje1, int puntaje2, string jugador1, string jugador2, int turno) {
    
    cout << "Puntaje de " << jugador1 << ": " << puntaje1 << endl;
    cout << "Puntaje de " << jugador2 << ": " << puntaje2 << endl;
    
    if (turno == 1) {
        // Imprimir tablero de jugador 2
        imprimirTableroConCoordenadas(tablero2, jugador2);

        // Imprimir tablero de jugador 1
        imprimirTableroConCoordenadas(tablero1, jugador1);
        
        //  Imprimir turno de jugador 1
        cout << "Turno de " << jugador1 << endl;
        
    } else {
        // Imprimir tablero de jugador 1
        imprimirTableroConCoordenadas(tablero1, jugador1);

        // Imprimir tablero de jugador 2
        imprimirTableroConCoordenadas(tablero2, jugador2);

        //  Imprimir turno de jugador 2
        cout << "Turno de " << jugador2 << endl;
    }
}

// Imprimir puntajes
void imprimirPuntajes(int puntaje1, int puntaje2, string jugador1, string jugador2) {
    cout << "Puntaje de " << jugador1 << ": " << puntaje1 << endl;
    cout << "Puntaje de " << jugador2 << ": " << puntaje2 << endl;
}

// fin
void fin(string jugador1, string jugador2, int puntajeJugador1, int puntajeJugador2) {
    
        imprimirPuntajes( puntajeJugador1 ,  puntajeJugador2,  jugador1,  jugador2);

        if(puntajeJugador1>puntajeJugador2){
            cout << jugador1 << " gana" << endl;
        }else if(puntajeJugador1<puntajeJugador2){
            cout << jugador2 << " gana" << endl;
        }else{
            cout << "Empate" << endl;
        }
        exit(0);
}


// Juego


int main(){
    // Bienvenida
    cout << "Bienvenido al juego Parejas y tríos: suma a 20." << endl;
    cout << endl;
    
    // Imprimir reglas
    imprimirReglas();
    cout << endl;

    // Imprimir instrucciones
    imprimirInstrucciones();
    cout << endl;

    //Debe pedir nombre de cada jugador al inicio, solamente 2 jugadores, alternar turnos de cada jugador hasta que haya un ganador. 
    string jugador1, jugador2;

    cout << "Ingrese el nombre del jugador 1: ";
    cin >> jugador1;
    cout << "Ingrese el nombre del jugador 2: ";
    cin >> jugador2;

    // Configuracion de tableros
    int tableroJugador1[8][8]={0};
    int tableroJugador2[8][8]={0};

    // Vectores de punteros que guarda las posiciones jugadas validas
    int *posicionesJugador1 = new int[2];
    int *posicionesJugador2 = new int[2];

    // Vector que guarda los turnos de jugadas en curso
    int jugadaActual[3]={0};

    // Llenar tableros con numeros aleatorios
    llenarTablero(tableroJugador1);
    llenarTablero(tableroJugador2);

    // Configuracion de turnos
    int turno = 1;
    int turnoJugador1 = 1;
    int turnoJugador2 = 1;

    // Configuracion de marcador
    int marcadorJugador1 = 0;
    int marcadorJugador2 = 0;

    // Configuracion de ganador
    bool ganador = false;

    // Configuracion de jugada
    bool jugada = false;

    // Configuracion de jugada valida
    bool jugadaValida = false;

    // Configuracion de salida
    bool salida = false;

    // Configuracion de puntaje
    int puntajeJugador1 = 0;
    int puntajeJugador2 = 0;

    // Retorno de entrada
    int retorno = 0;


    // Tablero temporal
    int tableroTemporal[8][8]={0};

    // Imput
    string input;
        
    // Iniciar juego donde un jugador puede seleccionar dos o tres elementos en la matriz cuya suma sea 20. Si suma 20, los elementos seleccionados quedan en 0. Si no suma 20 pierde el turno y el tablero vuelve a su estado anterior.
    // EL jugador puede escribir salir en la linea y el juego termina.
    // Si elije dos posiciones y la jugada no suma 20, puede elegir una tercera, y si las 3 suman 20, se suma el puntaje del jugador y el tablero queda con 0 en las posiciones seleccionadas.
    // Si el jugador elige una posicion que ya fue elegida, el juego le indica que seleccione otra posicion.
    // El puntaje de cada jugador es la suma de posiciones en 0.
    // El juego termina cuando un jugador no puede sumar 20 puntos con los elementos en su tablero.

    // Juego se puede volver a jugar despues de terminar una partida
    while(!salida){
        // Juego
        cout<<".. :: || Juego iniciado || :: .."<<endl;
        // Imprimir Tableros
        imprimirTableros(tableroJugador1, tableroJugador2, marcadorJugador1, marcadorJugador2, jugador1, jugador2, turno);
        // Instrucciones
        cout << "Ingrese la posicion de la jugada (ejemplo: 12) o escriba salir para salir del juego: ";

        int turnos30 = 30;

        while(!ganador){    
            // Jugadas
            // Turno de jugador 1
                jugadaActual[0] = 0;
                jugadaActual[1] = 0;
                jugadaActual[2] = 0;    
            
            cout << endl;
            cout << endl;            

            // imprimir turno de jugador 1
            cout << "Turno de " << jugador1 << endl;
            // Imput
            imprimirTableroConCoordenadas(tableroJugador1,jugador1);
            /*
            */

            // Copiar tablero
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    tableroTemporal[i][j] = tableroJugador1[i][j];
                }
            }
            // turno

            for(int i=0;i<3 && jugadaActual[0]+jugadaActual[1]<20;i++){  

                cout << "-> ";
                cin >> input;
                if(input == "salir"){
                    fin(jugador1,  jugador2, puntajeJugador1,  puntajeJugador2);
                }
                if (input == "sarirPartida"){
                    cout << "Iniciando una nueva partida" << endl;
                    // reiniciar tableros
                    llenarTablero(tableroJugador1);
                    llenarTablero(tableroJugador2);
                    // reiniciar turnos
                    turnoJugador1 = 1;
                    turnoJugador2 = 1;
                    // reiniciar marcador
                    marcadorJugador1 = 0;
                    marcadorJugador2 = 0;
                    // reiniciar ganador
                    ganador = false;
                    // reiniciar jugada
                    jugada = false;
                    // reiniciar jugada valida
                    jugadaValida = false;
                    // reiniciar salida
                    salida = false;
                    // reiniciar puntaje
                    puntajeJugador1 = 0;
                    puntajeJugador2 = 0;
                    // reiniciar posiciones jugada
                    jugadaActual[0] = 0;
                    jugadaActual[1] = 0;
                    jugadaActual[2] = 0;
                    // reiniciar posiciones jugada
                    posicionesJugador1[0] = 0;
                    posicionesJugador1[1] = 0;
                    posicionesJugador2[0] = 0;
                    posicionesJugador2[1] = 0;
                    // reiniciar tablero temporal
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            tableroTemporal[i][j] = 0;
                        }
                    }
                    // reiniciar imput
                    input = "";
                    // reiniciar retorno
                    retorno = 0;
                    break;
                }

                retorno = validarEntrada(input);
                if(retorno < 0){
                    cout << "Ingrese una posicion valida" << endl;
                    cout << "Pierde turno" << endl;
                    break;
                }else{
                    jugadaValida = false;
                    
                    int posI, posJ;
                    posI = retorno / 10;
                    posJ = retorno % 10;
                    do{
                        if(tableroTemporal[posI][posJ] != 0){

                            jugadaValida = true;
                            jugadaActual[i] = tableroTemporal[posI][posJ];
                            tableroTemporal[posI][posJ] = 0;
                            imprimirTableroConCoordenadas(tableroTemporal, "Jugada Actual");
                            cout<<i+1<<". Ok"<<endl;
                            //break;
                        }else{
                            cout << "Posicion ya fue elegida, ingrese otra posicion: ";
                            cin >> input;
                            if(input == "salir"){
                                fin(jugador1,  jugador2, puntajeJugador1,  puntajeJugador2);
                            }
                            retorno = validarEntrada(input);
                            if(retorno < 0){
                                cout<< jugador1 <<" pierde turno"<<endl;
                                break;
                            }else{
                                posI = retorno / 10;
                                posJ = retorno % 10;
                            }
                        }
                        if(i==0){
                            cout << "Seleccion: {" << jugadaActual[i] <<"}"<< endl;
                        }else if(i==1){
                            
                                
                            cout << "Seleccion: {" << jugadaActual[i] <<","<< jugadaActual[i-1] <<"}"<< endl;

                            if(jugadaActual[i]+jugadaActual[i-1]==20){
                                cout << "+2 Puntos"<< endl;
                                puntajeJugador1 += 2;
                                marcadorJugador1 += 2;

                                // tablero jugar 1 = tablero temporal
                                for (int i = 0; i < 8; i++) {
                                    for (int j = 0; j < 8; j++) {
                                        tableroJugador1[i][j] = tableroTemporal[i][j];
                                    }
                                }

                            }

                        }else if(i==2){
                            cout << "Seleccion: {" << jugadaActual[i] <<","<< jugadaActual[i-1] <<","<< jugadaActual[i-2] <<"}"<< endl;

                            if(jugadaActual[i]+jugadaActual[i-1]+jugadaActual[i-2]==20){
                                cout << "+3 Puntos"<< endl;
                                puntajeJugador1 += 3;
                                marcadorJugador1 += 3;

                                // tablero jugar 1 = tablero temporal
                                for (int i = 0; i < 8; i++) {
                                    for (int j = 0; j < 8; j++) {
                                        tableroJugador1[i][j] = tableroTemporal[i][j];
                                    }
                                }

                            }
                        }


                            


                    }while(!jugadaValida);
                }
                
            }
                
            imprimirPuntajes( puntajeJugador1 ,  puntajeJugador2,  jugador1,  jugador2);

            // Jugadas
            // Turno de jugador 2
                jugadaActual[0] = 0;
                jugadaActual[1] = 0;
                jugadaActual[2] = 0;    
            
            cout << endl;
            cout << endl;            

            // imprimir turno de jugador 2
            cout << "Turno de " << jugador2 << endl;
            // Imput
            imprimirTableroConCoordenadas(tableroJugador2,jugador2);
            /*
            */

           // copiar tablero temporal de tablero jugador 2
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    tableroTemporal[i][j] = tableroJugador2[i][j];
                }
            }
           
           
            for(int i=0;i<3 && jugadaActual[0]+jugadaActual[1]<20;i++){  

                cout << "-> ";
                cin >> input;
                if(input == "salir"){
                    fin(jugador1,  jugador2, puntajeJugador1,  puntajeJugador2);
                }
                if (input == "salir") {
                    salida = true;
                    break;
                }
                if (input == "sarirPartida"){
                    cout << "Iniciando una nueva partida" << endl;
                    // reiniciar tableros
                    llenarTablero(tableroJugador1);
                    llenarTablero(tableroJugador2);
                    // reiniciar turnos
                    turnoJugador1 = 1;
                    turnoJugador2 = 1;
                    // reiniciar marcador
                    marcadorJugador1 = 0;
                    marcadorJugador2 = 0;
                    // reiniciar ganador
                    ganador = false;
                    // reiniciar jugada
                    jugada = false;
                    // reiniciar jugada valida
                    jugadaValida = false;
                    // reiniciar salida
                    salida = false;
                    // reiniciar puntaje
                    puntajeJugador1 = 0;
                    puntajeJugador2 = 0;
                    // reiniciar posiciones jugada
                    jugadaActual[0] = 0;
                    jugadaActual[1] = 0;
                    jugadaActual[2] = 0;
                    // reiniciar posiciones jugada
                    posicionesJugador1[0] = 0;
                    posicionesJugador1[1] = 0;
                    posicionesJugador2[0] = 0;
                    posicionesJugador2[1] = 0;
                    // reiniciar tablero temporal
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            tableroTemporal[i][j] = 0;
                        }
                    }
                    // reiniciar input
                    input = "";
                    break;
                }

                retorno = validarEntrada(input);
                if(retorno < 0){
                    cout << "Ingrese una posicion valida" << endl;
                    cout << "Pierde turno" << endl;
                    break;
                }else{
                    jugadaValida = false;
                    
                    int posI, posJ;
                    posI = retorno / 10;
                    posJ = retorno % 10;
                    do{
                        if(tableroTemporal[posI][posJ] != 0){

                            jugadaValida = true;
                            jugadaActual[i] = tableroTemporal[posI][posJ];
                            tableroTemporal[posI][posJ] = 0;
                            imprimirTableroConCoordenadas(tableroTemporal, "Jugada Actual");
                            cout<<i+1<<". Ok"<<endl;
                            //break;
                        }else{
                            cout << "Posicion ya fue elegida, ingrese otra posicion: ";
                            cin >> input;
                            if(input == "salir"){
                                fin(jugador1,  jugador2, puntajeJugador1,  puntajeJugador2);
                            }

                            retorno = validarEntrada(input);
                            if(retorno < 0){
                                cout<< jugador2 <<" pierde turno"<<endl;
                                break;
                            }else{
                                posI = retorno / 10;
                                posJ = retorno % 10;
                            }
                        }
                        if(i==0){
                            cout << "Seleccion: {" << jugadaActual[i] <<"}"<< endl;
                        }else if(i==1){
                            
                                
                            cout << "Seleccion: {" << jugadaActual[i] <<","<< jugadaActual[i-1] <<"}"<< endl;

                            if(jugadaActual[i]+jugadaActual[i-1]==20){
                                cout << "+2 Puntos"<< endl;
                                puntajeJugador2 += 2;
                                marcadorJugador2 += 2;
                                
                                // tablero jugar 2 = tablero temporal
                                for (int i = 0; i < 8; i++) {
                                    for (int j = 0; j < 8; j++) {
                                        tableroJugador2[i][j] = tableroTemporal[i][j];
                                    }
                                }

                            }

                        }else if(i==2){
                            cout << "Seleccion: {" << jugadaActual[i] <<","<< jugadaActual[i-1] <<","<< jugadaActual[i-2] <<"}"<< endl;

                            if(jugadaActual[i]+jugadaActual[i-1]+jugadaActual[i-2]==20){
                                cout << "+3 Puntos"<< endl;
                                puntajeJugador2 += 3;
                                marcadorJugador2 += 3;

                                // tablero jugar 2 = tablero temporal
                                for (int i = 0; i < 8; i++) {
                                    for (int j = 0; j < 8; j++) {
                                        tableroJugador2[i][j] = tableroTemporal[i][j];
                                    }
                                }

                            }
                        }
                    }while(!jugadaValida);
                }

            }














            
            imprimirPuntajes( puntajeJugador1 ,  puntajeJugador2,  jugador1,  jugador2);

           turnos30++;
           if(turnos30==30){
                break;
           }

            // turno

        }
        fin(jugador1,  jugador2, puntajeJugador1,  puntajeJugador2);
        break;
    }

    return 0;
}