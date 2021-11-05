Algoritmo  división 
	Definir femeninos Como Entero
	Definir masculinos Como Entero
	Definir total Como Entero
	
	Escribir "¿Cuantos hombres hay en la división?"
	Leer masculinos
	
	Escribir "¿Cuantas mujeres hay en la división?"
	Leer femeninos
	
	total <- masculinos + femeninos
	
	Escribir "La fuerza efectiva de la división es: " total
	
	Si masculinos = femeninos Entonces
		Escribir "Igual cantidad de femeninos y masculinos"
	FinSi
	Si masculinos < femeninos Entonces
		Escribir "Mayor cantidad de aspirantes femeninos que masculinos"
	FinSi
	Si masculinos > femeninos Entonces
		Escribir "Mayor cantidad de aspirantes masculinos que femeninos"
	FinSi
	
FinAlgoritmo
