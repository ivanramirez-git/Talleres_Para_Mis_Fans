/*
Haga un programa en Go que le pregunte al usuario cuantos números quiere ingresar. Una obtenido este dato solicite
al usuario que ingrese por teclado la cantidad de números que el indico y léalos uno por uno. El programa debe
generar como salida el número mayor y menor ingresados, la sumatoria de todos los números ingresados y el
promedio. Use el ciclo que mejor se adapta al problema.
*/
/******************************************************************************

                            Online Go Lang Compiler.
                Code, Compile, Run and Debug Go Lang program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/


package main
import "fmt"

func main() {
	//Declaracion de variables
	var cantidad int
	var numero int
	var suma int
	var promedio float32
	var numeroMayor int
	var numeroMenor int

	//Preguntamos al usuario cuantos numeros quiere ingresar
	fmt.Println("Ingrese la cantidad de numeros que desea ingresar: ")
	fmt.Scan(&cantidad)

	//Ciclo para ingresar los numeros
	for i := 0; i < cantidad; i++ {
		fmt.Println("Ingrese el numero: ")
		fmt.Scan(&numero)
		//Sumamos los numeros
		suma += numero
		//Verificamos si es el primer numero
		if i == 0 {
			numeroMayor = numero
			numeroMenor = numero
		}
		//Verificamos si el numero es mayor que el mayor
		if numero > numeroMayor {
			numeroMayor = numero
		}
		//Verificamos si el numero es menor que el menor
		if numero < numeroMenor {
			numeroMenor = numero
		}
	}
	//Calculamos el promedio
	promedio = float32(suma) / float32(cantidad)

	//Mostramos los resultados
	fmt.Println("El numero mayor es: ", numeroMayor)
	fmt.Println("El numero menor es: ", numeroMenor)
	fmt.Println("La suma de los numeros es: ", suma)
	fmt.Println("El promedio de los numeros es: ", promedio)


}
