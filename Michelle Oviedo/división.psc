Algoritmo  divisi�n 
	Definir femeninos Como Entero
	Definir masculinos Como Entero
	Definir total Como Entero
	
	Escribir "�Cuantos hombres hay en la divisi�n?"
	Leer masculinos
	
	Escribir "�Cuantas mujeres hay en la divisi�n?"
	Leer femeninos
	
	total <- masculinos + femeninos
	
	Escribir "La fuerza efectiva de la divisi�n es: " total
	
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
