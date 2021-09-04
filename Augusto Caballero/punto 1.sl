var
	n, suma, promedio, contador :numerico
inicio
	imprimir("ingrese un numero: ")
	leer(n)

	suma=0
	promedio=0
	contador=0
	
	mientras(0<n){
		si(n%3 == 0){
			suma=suma+n
			contador=contador+1
			imprimir(n,"\n")
		}
		n=n-1
	}

	si(contador>0){
		promedio=suma/contador
		imprimir("La suma es: ", suma, " y el promedio es: ", promedio)
	}
fin