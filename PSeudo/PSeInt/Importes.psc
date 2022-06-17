
Algoritmo Principal
	
	// Variables
	N = 0
	Escribir "Ingrese el tamaño del arreglo: "
	Leer N
	Dimension arreglo(N)
	
	// Ingreso de datos
	Para i = 1 hasta N
		arreglo(i) = Aleatorio(1, 100)
	FinPara
	
	// Calculos
	Calcula(arreglo, N)
	
FinAlgoritmo

SubAlgoritmo Calcula(arreglo, N)
	media = 0.0
	varianza = 0.0
	desviacion = 0.0
	moda = arreglo(1)
	Dimension frecuencias(100)
	
	// frecuencias en 0
	Para i = 1 hasta 100
		frecuencias(i) = 0
	FinPara
	
	// frecuencias en 1
	Para i = 1 hasta N
		frecuencias(arreglo(i)) = frecuencias(arreglo(i)) + 1
	FinPara
	
	// media
	Para i = 1 hasta N
		media = media + arreglo(i)
	FinPara
	media = media / N
	
	// varianza
	Para i = 1 hasta N
		varianza = varianza + ( (arreglo(i) - media) * (arreglo(i) - media) )
	FinPara
	varianza = varianza / N
	
	// desviacion
	desviacion = Raiz(varianza)
	
	// moda
	Escribir sin saltar "["
	Para i = 1 hasta N
		Escribir sin saltar arreglo(i) ", "
		Si frecuencias(arreglo(i)) > frecuencias(moda)
			moda = arreglo(i)
		FinSi
	FinPara
	Escribir "]"
	
	// Resultados
	Escribir "Media: " media
	Escribir "Varianza: " varianza
	Escribir "Desviacion: " desviacion
	Escribir "Moda: " moda
	
FinSubAlgoritmo
