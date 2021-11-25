Algoritmo punto5
	// Ingrese el numero de datos
	Escribir 'Ingrese el numero de datos: '
	Leer N
	N <- N+1
	Dimension Arreglo[N]
	// Iniciar ciclo
	I <- 1
	Mientras I<>N Hacer
		// Ingrese el dato
		Escribir 'Ingrese el dato: '
		Leer DATO
		// Agregar el dato al arreglo
		Arreglo[I] <- DATO
		I <- I+1
	FinMientras
	// Imprimir arreglo
	Escribir 'El arreglo es: '
	I <- 1
	Escribir '[' Sin Saltar
	Mientras I<>N Hacer
		Escribir Arreglo[I],' ' Sin Saltar
		I <- I+1
	FinMientras
	Escribir ']'
FinAlgoritmo
