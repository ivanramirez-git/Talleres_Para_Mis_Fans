Algoritmo  financiera 
	
	
	// Una financiera ofrece créditos personales, de hasta 40.000 $ con cuotas fijas mensuales, con los siguientes planes:
	
	// En 6 cuotas, cobran el 10 % de interés 
    // En 12 cuotas, cobran el 25 % de interés
    // En 18 cuotas, cobran el 55 % de interés
	
	// Indique el valor de la cuota a pagar por una persona que saque un préstamo en esta financiera.
	
	Escribir "¿Cuanto es el monto del credito desea sacar?"
	Leer monto
	
	// Si supera los 40.000 $ volver a pedir el monto
	Si monto > 40000 Entonces
		Escribir "El monto debe ser menor a 40.000"
		Escribir "¿Cuanto es el monto del credito desea sacar?"
		Leer monto
	FinSi
	
	Escribir "¿Cuantas cuotas desea pagar?"
	Leer cuotas
	
	// Verificar que cuotas sea 6, 12 o 18, si no, volver a pedir cuotas
	Si cuotas <> 6 Entonces
		Si cuotas <> 12 Entonces
			Si cuotas <> 18 Entonces
				Escribir "Las cuotas deben ser 6, 12 o 18"
				Escribir "¿Cuantas cuotas desea pagar?"
				Leer cuotas
			FinSi
		FinSi
	FinSi
	
	// Calcular el valor de la cuota
	Si cuotas = 6 Entonces
		valorCuota <- monto/6 * 1.1
	FinSi
	Si cuotas = 12 Entonces
		valorCuota <- monto/12 * 1.25
	FinSi
	Si cuotas = 18 Entonces
		valorCuota <- monto/18 * 1.55
	FinSi
	
	Escribir "El valor de la cuota es: " valorCuota
	
FinAlgoritmo
