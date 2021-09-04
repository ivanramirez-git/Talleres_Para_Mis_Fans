var
	contador:numerico
inicio
	contador=1
	mientras(contador<=100){
		si(contador%5==0 and contador%3==0){
			imprimir("Fizzbuzz")
		sino si(contador%3==0)
					imprimir("Fizz")
				sino si(contador%5==0)
					imprimir("Buzz")
					sino 
						imprimir(contador)
		}
		imprimir("\n")
		contador=contador+1
		
	}
fin