Algoritmo programa
	
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

Algoritmo financiera

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

Algoritmo aumentos

// Una empresa aumentará el salario de sus empleados según el siguiente detalle: 

// los que cobran hasta $ 18000 recibirán un incremento del 15% del salario 
// los que cobran más de $ 18000 pero menos de 25000 $, recibirán un incremento del 10% del salario 
// los que cobran 25000 $ o más, recibirán un incremento del 5% del salario.

// Desarrolle un algoritmo que indique cual será el nuevo salario para un empleado de esta empresa, solicite el nombre del mismo. 

	Escribir "¿Cuanto es el salario del empleado?"
	Leer salario

	// Si el salario es menor a 18000, aumentar el salario del 15%
	Si salario <= 18000 Entonces
		salario <- salario * 1.15
	FinSi

	// Si el salario es mayor a 18000 pero menor a 25000, aumentar el salario del 10%
	Si salario > 18000 Entonces
		Si salario <= 25000 Entonces
			salario <- salario * 1.10
		FinSi
	FinSi

	// Si el salario es mayor a 25000, aumentar el salario del 5%
	Si salario > 25000 Entonces
		salario <- salario * 1.05
	FinSi

	Escribir "El nuevo salario del empleado es: " salario

FinAlgoritmo

Algoritmo circo

	//¡Un circo llego a la ciudad! La entrada de los menores cuesta 100 $ y la de los mayores 230 $. 
	// Para que concurran más personas, tienen la siguiente promoción: 
	// “Por cada mayor que paga entrada, un menor entra GRATIS”
	// Indique cuánto dinero pagará un grupo de personas (familiares o amigos) que vaya al circo.

	Escribir "¿Cuantos mayores hay?"
	Leer mayores

	Escribir "¿Cuantos menores hay?"
	Leer menores

	menores <- menores - mayores

	Si menores > 0 Entonces
		Escribir "El total es de: " (230 * mayores) + (menores * 100)
	FinSi

	Si menores <= 0 Entonces
		Escribir "El total es de: " (230 * mayores)
	FinSi

FinAlgoritmo

