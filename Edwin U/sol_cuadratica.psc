Algoritmo sol_cuadratica
	Escribir 'Ingrese los coeficientes A, B y C:'
	Leer A,B,C
	Si B^2<4*A*C Entonces
		Escribir 'La ecuacion no tiene raices reales'
	SiNo
		X <- -raiz(B^2-4*A*C)
		X1 <- (-B+X)/(2*A)
		X2 <- (-B-X)/(2*A)
		Escribir 'X1: ',X1
		Escribir 'X2: ',X2
	FinSi
FinAlgoritmo

