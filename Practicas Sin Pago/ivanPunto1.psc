Algoritmo punto1
	Dimension P[5]
	Dimension Q[5]
	Dimension R[5]
	Dimension Qordenado[5]
	P[1] <- 9
	P[2] <- 0
	P[3] <- -5
	P[4] <- 12
	P[5] <- -1
	i <- 1
	Mientras i<=5 Hacer
		Si Q[1]<P[i] Entonces
			Q[1] <- P[i]
		FinSi
		i <- i+1
	FinMientras
	Q[1] <- Q[1]/2
	i <- 1
	Mientras i<=5 Hacer
		Si Q[2]>P[i] Entonces
			Q[2] <- P[i]
		FinSi
		i <- i+1
	FinMientras
	Q[3] <- 16
	i <- 1
	Mientras i<=5 Hacer
		Q[4] <- Q[4]+P[i]
		i <- i+1
	FinMientras
	Q[4] <- Q[4]/5
	Q[5] <- Q[1]+Q[1]+Q[2]
	i <- 1
	Mientras i<=5 Hacer
		Qordenado[i] <- Q[i]
		i <- i+1
	FinMientras
	i <- 1
	Mientras i<=5 Hacer
		j <- 1
		Mientras j<=5 Hacer
			Si Qordenado[i]<Qordenado[j] Entonces
				temporal <- Qordenado[i]
				Qordenado[i] <- Qordenado[j]
				Qordenado[j] <- temporal
			FinSi
			j <- j+1
		FinMientras
		i <- i+1
	FinMientras
	i <- 1
	Mientras i<=5 Hacer
		R[i] <- P[i]+Qordenado[i]
		i <- i+1
	FinMientras
	Escribir 'Lectura en proceso'
	Escribir 'P     Q       Qordenado       R'
	Escribir '_______________________________'
	i <- 1
	Mientras i<=5 Hacer
		Escribir P[i],'     ',Q[i],'     ',Qordenado[i],'     ',R[i]
		i <- i+1
	FinMientras
	Escribir ''
	Escribir 'Informe'
	Escribir 'P     Q ordenado       R'
	Escribir '____________________________'
	i <- 1
	Mientras i<=5 Hacer
		Escribir P[i],'     ',Qordenado[i],'     ',R[i]
		i <- i+1
	FinMientras
FinAlgoritmo
