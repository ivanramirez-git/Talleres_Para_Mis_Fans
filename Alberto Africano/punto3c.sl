var 
	p:numerico
inicio
	imprimir("Ingrese la longitud en PULGADAS para convertir a PIES y a MILLAS: ")
	leer(p)
	imprimir("Pulgadas: ",p)
	p=p/12
	imprimir("\nPies: ",p)
	p=p/5280
	imprimir("\nMillas: ",p) 
fin