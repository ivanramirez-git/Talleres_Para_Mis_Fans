Algoritmo circo
	
	
	//�Un circo llego a la ciudad! La entrada de los menores cuesta 100 $ y la de los mayores 230 $. 
	// Para que concurran m�s personas, tienen la siguiente promoci�n: 
	// "Por cada mayor que paga entrada, un menor entra GRATIS"
	// Indique cu�nto dinero pagar� un grupo de personas (familiares o amigos) que vaya al circo.
	
	Escribir "�Cuantos mayores hay?"
	Leer mayores
	
	Escribir "�Cuantos menores hay?"
	Leer menores
	
	menores <- menores - mayores
	
	Si menores > 0 Entonces
		Escribir "El total es de: " (230 * mayores) + (menores * 100)
	FinSi
	
	Si menores <= 0 Entonces
		Escribir "El total es de: " (230 * mayores)
	FinSi
	
	
FinAlgoritmo