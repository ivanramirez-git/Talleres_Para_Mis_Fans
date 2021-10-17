var

	i, r :numerico

inicio

	r=0
	mientras (i<=20) {
		si(i%2 <> 0){
		
			r=r+i
		
		}
		i=i+1
	} 

	imprimir("La suma es: ",r)
fin