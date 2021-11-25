Algoritmo punto1
    // Ingrese la antiguedad del trabajador
    Escribir "Ingrese la antiguedad del trabajador: "
    Leer antiguedad
    Escribir "Ingrese el salario mensual del trabajador: "
    Leer salario
    // Calcular el monto que recibe mensualmente
    Si antiguedad>=3 y antiguedad<=10
        monto<-salario*0.1
    FinSi
    Si antiguedad>=11 y antiguedad<=20
        monto<-salario*0.25
    FinSi
    Si antiguedad>=21 y antiguedad<=35
        monto<-salario*0.5
    FinSi
    Si antiguedad>35
        monto<-salario*0.8
    FinSi
    // Mostrar el monto que recibe mensualmente
    Escribir "El monto que recibe mensualmente es: " monto
	
    
FinAlgoritmo
