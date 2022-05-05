/*

Implementar una lista enlazada doblemente enlazada.
La implementación debe tener al menos las siguientes funciones:
  Agregar primero
  Agregar último
  Eliminar primero
  Eliminar último
  Metodo toString
  Esta Vacio?
*/
package main

import "fmt"

type Nodo struct {
	valor     int
	siguiente *Nodo
	anterior  *Nodo
}

type Lista struct {
	primero *Nodo
	ultimo  *Nodo
	tamano  int
}

func (lista *Lista) agregarPrimero(valor int) {
	nuevoNodo := &Nodo{valor, nil, nil}
	if lista.tamano == 0 {
		lista.primero = nuevoNodo
		lista.ultimo = nuevoNodo
	} else {
		lista.primero.anterior = nuevoNodo
		nuevoNodo.siguiente = lista.primero
		lista.primero = nuevoNodo
	}
	lista.tamano++
}

func (lista *Lista) agregarUltimo(valor int) {
	nuevoNodo := &Nodo{valor, nil, nil}
	if lista.tamano == 0 {
		lista.primero = nuevoNodo
		lista.ultimo = nuevoNodo
	} else {
		lista.ultimo.siguiente = nuevoNodo
		nuevoNodo.anterior = lista.ultimo
		lista.ultimo = nuevoNodo
	}
	lista.tamano++
}

func (lista *Lista) eliminarPrimero() {
	if lista.tamano == 0 {
		fmt.Println("La lista esta vacia")
	} else {
		lista.primero = lista.primero.siguiente
		lista.primero.anterior = nil
		lista.tamano--
	}
}

func (lista *Lista) eliminarUltimo() {
	if lista.tamano == 0 {
		fmt.Println("La lista esta vacia")
	} else {
		lista.ultimo = lista.ultimo.anterior
		lista.ultimo.siguiente = nil
		lista.tamano--
	}
}

func (lista *Lista) toString() {
	if lista.tamano == 0 {
		fmt.Println("La lista esta vacia")
	} else {
		nodo := lista.primero
		print("[ ")
		for nodo.siguiente != nil {
			fmt.Print(nodo.valor, ", ")
			nodo = nodo.siguiente
		}
		fmt.Println(nodo.valor, "]")
	}
}

func (lista *Lista) estaVacio() bool {
	return lista.tamano == 0
}

// Pruebas
func prueba1() {
	lista := &Lista{}
	println("Prueba 1: ")
	println("Agregando primero: 1")
	lista.agregarPrimero(1)
	lista.toString()
	println("Agregando primero: 2")
	lista.agregarPrimero(2)
	lista.toString()
	println("Agregando primero: 3")
	lista.agregarPrimero(3)
	lista.toString()
	println("Agregando primero: 4")
	lista.agregarPrimero(4)
	lista.toString()
	println("Agregando primero: 5")
	lista.agregarPrimero(5)
	lista.toString()
	println("Agregando ultimo: 6")
	lista.agregarUltimo(6)
	lista.toString()
	println("Agregando ultimo: 7")
	lista.agregarUltimo(7)
	lista.toString()
	println("Agregando ultimo: 8")
	lista.agregarUltimo(8)
	lista.toString()
	println("Eliminando el primero")
	lista.eliminarPrimero()
	lista.toString()
	println("Eliminando el ultimo")
	lista.eliminarUltimo()
	lista.toString()
	println("¿Esta vacia? ", lista.estaVacio())
	println("Agregando uno mas")
	lista.agregarUltimo(6)
	lista.toString()
	println("Eliminando el primero")
	lista.eliminarPrimero()
	lista.toString()
	println("Eliminando el ultimo")
	lista.eliminarUltimo()
	lista.toString()
	println("¿Esta vacia? ", lista.estaVacio())
}

// Menu
func menu() {
	var opcion int
	var valor int
	opcion = -1
	valor = 0
	lista := &Lista{}
	for opcion != 0 {
		println("1. Agregar primero")
		println("2. Agregar ultimo")
		println("3. Eliminar primero")
		println("4. Eliminar ultimo")
		println("5. Imprimir lista")
		println("0. Salir")
		fmt.Scan(&opcion)
		switch opcion {
		case 1:
			fmt.Printf("numero a agregar primero: ")
			fmt.Scan(&valor)
			lista.agregarPrimero(valor)
		case 2:
			fmt.Printf("numero a agregar ultimo: ")
			fmt.Scan(&valor)
			lista.agregarUltimo(valor)
		case 3:
			fmt.Println("Eliminando el primero...")
			lista.eliminarPrimero()
		case 4:
			fmt.Println("Eliminando el ultimo...")
			lista.eliminarUltimo()
		case 5:
			lista.toString()
		case 0:
			println("Saliendo...")
		default:
			println("Opcion invalida")
		}
	}
}

// Main
func main() {
	// prueba1()
	menu()
}
