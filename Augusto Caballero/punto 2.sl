var
	n, fact, contador: numerico	
inicio
	imprimir("Ingrese un numero natural para calcular su factorial: ")
	leer(n)

	si(0<n and n%1==0){
		fact=1
		contador=1
		mientras(contador<=n){
			fact=fact*contador
			contador=contador+1
		}
		imprimir("El factorial es: ", fact)
	sino
		imprimir("No es un numero natural.")
	}


fin