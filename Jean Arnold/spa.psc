Algoritmo spa
	Escribir "Ingrese el tipo de tratamiento"
	Leer x
	Escribir "Ingrese su edad"
	leer edad
	segun x Hacer
		1:
			x<-2800
		2:
			x<-1950
		3:
			x<-2500
		4:
			x<-1150
		De Otro Modo:
			Escribir "Error"
	FinSegun
	si edad >60 Entonces
		x<-(x*0.75)
	SiNo
		si edad>25 Entonces
			x<-(x*0.85)
		FinSi
	FinSi
	Escribir "El costo es" x
	
FinAlgoritmo
