Algoritmo  aumentos
	
	// Una empresa aumentar� el salario de sus empleados seg�n el siguiente detalle: 
	
	// los que cobran hasta $ 18000 recibir�n un incremento del 15% del salario 
	// los que cobran m�s de $ 18000 pero menos de 25000 $, recibir�n un incremento del 10% del salario 
	// los que cobran 25000 $ o m�s, recibir�n un incremento del 5% del salario.
	
	// Desarrolle un algoritmo que indique cual ser� el nuevo salario para un empleado de esta empresa, solicite el nombre del mismo. 
	
	Escribir "�Cuanto es el salario del empleado?"
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