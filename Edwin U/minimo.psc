Algoritmo minimo
	Dimension A[50]
	Escribir 'Ingrese cantidad de datos: '
	Leer N
	Para I<-1 Hasta N Hacer
		Escribir 'Ingrese el dato ',I,':'
		Leer A[I]
	FinPara
	MIN <- A[1]
	Para I<-2 Hasta N Hacer
		Si A[I]<MIN Entonces
			MIN <- A[I]
		FinSi
	FinPara
	Escribir 'El minimo de los ',N,' numeros es: ',MIN
FinAlgoritmo

