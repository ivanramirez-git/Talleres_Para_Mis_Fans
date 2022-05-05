package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"os/exec"
	"runtime"
	"strconv"
	"time"
)

var clear map[string]func()
var tablero [4][6]string
var fila, col int
var jug1, jug2 string
var punt1, punt2, turno int

func main() {

	var menu int
	punt1 = 0
	punt2 = 0
	turno = 0

	for menu <= 4 && menu >= 0 {
		mostrarMenu()
		fmt.Print("Digite la opción a realizar: ")
		fmt.Scanln(&menu)
		CallClear()

		for menu < 1 || menu > 4 {
			fmt.Println("")
			fmt.Println("No es una opción del menú")
			fmt.Println("Vuelva a ingresarlo")
			fmt.Scan(&menu)
		}
		if menu == 4 {
			break
		}

		switch menu {
		case 1: //  Instrucciones
			mostrarInstrucciones()
			break

		case 2: //Iniciar el juego

			llenarTablero()

			imprimirTablero()

			jugActual := escogerJugadores()

			// Suma
			for salida() {

				switch jugActual {

				case jug1:
					if turnoJugador(jug1) {
						println("Ganaste 1 punto")
					} else {
						println("No ganaste puntos")
					}
					println("Total de puntos: ", punt1)
					break

				case jug2:
					if turnoJugador(jug2) {
						println("Ganaste 1 punto")
					} else {
						println("No ganaste puntos")
					}
					println("Total de puntos: ", punt2)
					break
				default:
					panic("Esto no se puede dar!: 1")
				}

				println()
				println()

				if jugActual == jug1 {
					jugActual = jug2
				} else if jugActual == jug2 {
					jugActual = jug1
				} else {
					panic("Esto no se puede dar!: 2")
				}
			}

			// Sumar puntos de triadas
			punt1 += triadasJugador(jug1)
			punt2 += triadasJugador(jug2)

			// Mostrar Puntajes
			println("El Jugador: ", jug1, " tiene: ", punt1, " puntos.")
			println("El Jugador: ", jug2, " tiene: ", punt2, " puntos.")

			// Dar ganador o empate
			if punt1 > punt2 {
				println("El ganador es: ", jug1)
			} else if punt1 < punt2 {
				println("El ganador es: ", jug2)
			} else {
				println("Empate")
			}

			imprimirTablero()

			finJuego()

			break

		case 3: //Acerca de
			acercaDe()

		}
		fmt.Println("Presione ENTER para continuar")
		bufio.NewReader(os.Stdin).ReadBytes('\n')
		cleared()
		CallClear()
	}
}

func salida() bool {
	if turno < 24 {
		return true
	}
	return false
}

func dados() int {
	fmt.Println("┌—————————————LANZAMIENTO DE DADOS———————————————┐")
	fmt.Println("| Presione ENTER o ESPERE, para lanzar los dados |")
	fmt.Println("└————————————————————————————————————————————————┘")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
	return lanzarDados()
}

func mostrarMenu() {
	fmt.Println("┌--------------------------------┐")
	fmt.Println("|......Bienvenidos al juego......|")
	fmt.Println("|..........SUM OF DICE...........|")
	fmt.Println("|--------------------------------|")
	fmt.Println("|1). Instrucciones del juego     |")
	fmt.Println("|2). Iniciar juego               |")
	fmt.Println("|3). Acerca de                   |")
	fmt.Println("|4). Salir del juego             |")
	fmt.Println("└--------------------------------┘")
	fmt.Println("")

}

func mostrarInstrucciones() {
	fmt.Println("┌-----------------------------------------------------------------------------------------------------------------┐")
	fmt.Println("|                                          INSTRUCCIONES DEL JUEGO                                                |")
	fmt.Println("|-----------------------------------------------------------------------------------------------------------------|")
	fmt.Println("|1. Se sortea aleatoriamente el primer turno.                                                                     |")
	fmt.Println("|                                                                                                                 |")
	fmt.Println("|2. Se lanzan dos dados y estos se suman.                                                                         |")
	fmt.Println("|                                                                                                                 |")
	fmt.Println("|3. El resultado de la suma se busca en el tablero.                                                               |")
	fmt.Println("|                                                                                                                 |")
	fmt.Println("|4. Debe indicar el número de fila y columna                                                                      |")
	fmt.Println("|                                                                                                                 |")
	fmt.Println("|5. Si la posición es valida, gana un punto y se sustituye el número por su inicial                               |")
	fmt.Println("|                                                                                                                 |")
	fmt.Println("|6. Si la posición no es válida, el jugador puede repetir el turno. Si falla no gana puntos.                      |")
	fmt.Println("|                                                                                                                 |")
	fmt.Println("|7. Los turnos se irán intercambiando entre los jugadores hasta que el tablero se llene con sus iniciales.        |")
	fmt.Println("|                                                                                                                 |")
	fmt.Println("|8. Si en ambos dados sale cero el jugador no gana puntos y le corresponde el turno al siguiente jugador.         |")
	fmt.Println("|                                                                                                                 |")
	fmt.Println("|9. Al llenarse el tablero se contará triadas de iniciales consecutivas de cada jugador                           |")
	fmt.Println("|                                                                                                                 |")
	fmt.Println("|10. Solo se permite contar una triada por cada fila y columna por jugador                                        |")
	fmt.Println("|                                                                                                                 |")
	fmt.Println("|11. Por cada triada encontrada ganará tres puntos                                                                |")
	fmt.Println("|                                                                                                                 |")
	fmt.Println("|12. Gana el jugador que tenga más puntos                                                                         |")
	fmt.Println("└-----------------------------------------------------------------------------------------------------------------┘")

}

func escogerJugadores() string {
	var turn int

	fmt.Println("\tSORTEO DEL TURNO DEL JUGADOR\t")
	fmt.Println("")
	fmt.Println("")

	//Se solicitan las iniciales de los jugadores
	for {
		fmt.Printf("Inicial del Jugador 1: ")
		fmt.Scanln(&jug1)
		fmt.Println("")

		//Validar Iniciales
		if len(jug1) > 1 {
			fmt.Println("Debe ser la primer inicial")
			fmt.Println("")
			fmt.Println("Intentelo de nuevo")
		} else {
			break
		}
	}

	for {
		fmt.Printf("Inicial del Jugador 2: ")
		fmt.Scanln(&jug2)
		fmt.Println("")

		//Validar Iniciales
		if len(jug2) > 1 {
			fmt.Println("Debe ser la primer inicial")
			fmt.Println("")
			fmt.Println("Intentelo de nuevo")
		} else {
			break
		}
	}

	//Escoger un jugador aleatoriamente
	rand.Seed(time.Now().Unix())
	turn = rand.Intn(2) + 1
	fmt.Println("")

	if turn == 1 {
		fmt.Println("El primer jugador es: ", jug1)
		return jug1
	} else {
		fmt.Println("El primer jugador es: ", jug2)
		return jug2
	}
}

func init() {
	clear = make(map[string]func()) //Initialize it
	clear["windows"] = func() {
		cmd := exec.Command("cmd", "/c", "cls")
		cmd.Stdout = os.Stdout
		cmd.Run()
	}
}

func CallClear() {
	value, ok := clear[runtime.GOOS]
	if ok {
		value()
	} else {
		panic("Your platform is unsupported! I can't clear terminal screen :(")
	}
}

func cleared() {
	fmt.Println("Espere!")
	time.Sleep(time.Second)
	CallClear()
	fmt.Println("")
}

func acercaDe() {

	fmt.Println("┌-------------------------┐")
	fmt.Println("|        ACERCA DE        |")
	fmt.Println("|-------------------------|")
	fmt.Println("| Integrantes:            |")
	fmt.Println("|   Kimberly Murillo      |")
	fmt.Println("|   Darien Yesca          |")
	fmt.Println("|   Kevin Vilchez         |")
	fmt.Println("| Proyecto:  ITI 121      |")
	fmt.Println("└-------------------------┘")
}

func llenarTablero() {

	var f, c, conta int
	var vector [13]int
	var conta3 string
	fmt.Println("")
	fmt.Println("\t\t  TABLERO\t")

	rand.Seed(time.Now().Unix())

	for f = 0; f < 13; f++ {
		vector[f] = 2
	}

	for f = 0; f < 4; f++ {
		for c = 0; c < 6; c++ {
			conta = 1 + rand.Intn(13-1)
			conta3 = strconv.Itoa(conta)
			if vector[conta] < 3 && vector[conta] > 0 {
				vector[conta] = vector[conta] - 1
				tablero[f][c] = conta3
			} else {
				c = c - 1
			}

		}
	}

}

func imprimirTablero() {
	var numFil int

	fmt.Println("┌————————————————————————————————————————┐")
	fmt.Println("|C→  |  0  |  1  |  2  |  3  |  4  |  5  |")
	fmt.Println("|F↓  |  ↓  |  ↓  |  ↓  |  ↓  |  ↓  |  ↓  |")
	fmt.Println("└————|—————|—————|—————|—————|—————|—————┘")

	for f := 0; f < 4; f++ {
		fmt.Print("|", numFil, " → | ")
		for c := 0; c < 6; c++ {
			if tablero[f][c] == "1" || tablero[f][c] == "2" || tablero[f][c] == "3" || tablero[f][c] == "4" || tablero[f][c] == "5" || tablero[f][c] == "6" || tablero[f][c] == "7" || tablero[f][c] == "8" || tablero[f][c] == "9" {
				fmt.Print("0", tablero[f][c], "  | ")
			} else {
				fmt.Print(tablero[f][c], "  | ")
			}
		}
		numFil++
		fmt.Println(" ")
	}
	fmt.Println("└————————————————————————————————————————┘")
}

func lanzarDados() int {

	dado1, dado2, suma := sumarDados()

	for !buscarEnTablero(suma) {
		dado1, dado2, suma = sumarDados()
	}

	fmt.Println("┌——————————————————————————————————————————┐")
	fmt.Println("|Dado 1: \t", dado1, "\t                   |")
	fmt.Println("└——————————————————————————————————————————┘")
	fmt.Println("┌——————————————————————————————————————————┐")
	fmt.Println("|Dado 2: \t", dado2, "\t                   |")
	fmt.Println("└——————————————————————————————————————————┘")
	fmt.Println("┌——————————————————————————————————————————┐")
	if suma < 10 {
		fmt.Println("| Suma de dados:\t ", suma, "\t           |")
	} else {
		fmt.Println("| Suma de dados:\t ", suma, "\t          |")
	}
	fmt.Println("└——————————————————————————————————————————┘")

	//RETORNAR
	return suma
}

func sumarDados() (int, int, int) {
	dado1, dado2, suma := 0, 0, 0

	rand.Seed(time.Now().Unix() - time.Hour.Microseconds())
	dado1 = rand.Intn(7)
	rand.Seed(time.Now().Unix()*int64(dado1) - time.Now().Unix()*time.Hour.Nanoseconds())
	dado2 = rand.Intn(7)
	suma = dado1 + dado2

	return dado1, dado2, suma
}

func buscarEnTablero(suma int) bool {
	for f := 0; f < len(tablero); f++ {
		for c := 0; c < len(tablero[0]); c++ {
			s := tablero[f][c]
			if s == strconv.Itoa(suma) {
				return true
			}
		}
	}
	return false
}

func validarPosiciones(f int, c int, suma int) bool {
	if tablero[f][c] == strconv.Itoa(suma) {
		return true
	}
	return false
}

func turnoJugador(jugActual string) bool {

	// Turno de jugador
	println("Turno de jugador: ", jugActual)

	// Casillas restantes
	println("Casillas restantes: ", 24-turno)

	// Lanzar dados
	suma := dados()

	// Imprimir tablero
	imprimirTablero()

	// Primera Oportunidad
	fmt.Println("PRIMER OPORTUNIDAD")
	fmt.Println("¿Cual celda desea pintar?")
	fmt.Print(" Fila: ")
	for {
		fmt.Scan(&fila)
		if fila < 0 || fila > len(tablero)-1 {
			fmt.Print("Ingrese una fila valida: ")
		} else {
			break
		}
	}
	fmt.Print(" Columna: ")
	for {
		fmt.Scan(&col)
		if col < 0 || col > len(tablero[0])-1 {
			fmt.Print("Ingrese una columna valida: ")
		} else {
			break
		}
	}
	if validarPosiciones(fila, col, suma) {
		tablero[fila][col] = (" " + jugActual)
		if jugActual == jug1 {
			punt1++
		} else if jugActual == jug2 {
			punt2++
		}
		turno++
		return true
	}
	// Segunda Oportunidad
	fmt.Println("SEGUNDA OPORTUNIDAD")
	fmt.Println("¿Cual celda desea pintar?")
	fmt.Print(" Fila: ")
	fmt.Scan(&fila)
	fmt.Print(" Columna: ")
	fmt.Scan(&col)
	if validarPosiciones(fila, col, suma) {
		tablero[fila][col] = (" " + jugActual)
		if jugActual == jug1 {
			punt1++
		} else if jugActual == jug2 {
			punt2++
		}
		turno++
		return true
	}

	return false
}

func triadasJugador(jugActual string) int {
	// Buscar 3 veces jugActual en el tablero, horizontal, vertical
	puntaje := 0

	for f := 0; f < len(tablero); f++ {
		for c := 0; c < len(tablero[0]); c++ {
			// Busqueda horizontal
			if f < len(tablero)-2 && tablero[f][c] == jugActual && tablero[f+1][c] == jugActual && tablero[f+2][c] == jugActual {
				puntaje += 3
				break
			}
		}
	}

	for c := 0; c < len(tablero[0]); c++ {
		for f := 0; f < len(tablero); f++ {
			// Busqueda vertical
			if c < len(tablero[0])-2 && tablero[f][c] == jugActual && tablero[f][c+1] == jugActual && tablero[f][c+2] == jugActual {
				puntaje += 3
				break
			}
		}
	}
	return puntaje
}

func finJuego() {
	// Esperar hasta que de click
	fmt.Scanln()
	fmt.Println("Espere 10 Segundos!")
	time.Sleep(time.Second * 10)
}
