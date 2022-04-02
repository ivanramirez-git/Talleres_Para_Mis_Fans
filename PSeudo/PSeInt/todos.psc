// este es el ejemplo más simple de esta ayuda, 
// toma dos numeros, los suma y muestra el resultado

Proceso Suma

    Definir A,B,C como Reales;

    // para cargar un dato, se le muestra un mensaje al usuario
    // con la instrucción Escribir, y luego se lee el dato en 
    // una variable (A para el primero, B para el segundo) con 
    // la instrucción Leer

    Escribir "Ingrese el primer numero:";
    Leer A;

    Escribir "Ingrese el segundo numero:";
    Leer B;


    // ahora se calcula la suma y se guarda el resultado en la
    // variable C mediante la asignación (<-)
    
    C <- A+B;


    // finalmente, se muestra el resultado, precedido de un 
    // mensaje para avisar al usuario, todo en una sola
    // instrucción Escribir
    
    Escribir "El resultado es: ",C;

FinProceso


Proceso TaTeTi
    
    // incializa dos matrices de 3x3, una para guardar la ficha que se ve, 
    // y otra para un valor asociado a la ficha, para un jugador sera 1, para
    // el otro 2, entoces para ver quien gano se multiplica por fila, por 
    // columna y por diagonal, si el resultado es 1 gano el primer jugador,
    // si es 8 gano el segundo, si es 0 es porque faltaba completar, si
    // es otra cosa, estan las tres fichas, pero no son del mismo jugador
    Dimension Tab1[3,3]
    Dimension Tab2[3,3]
    Para i<-1 Hasta 3 Hacer
        Para j<-1 Hasta 3 Hacer
            Tab1[i,j]<-0
            Tab2[i,j]<-" "
        FinPara
    FinPara
    TurnoJugador1<-Verdadero
    Terminado<-Falso
    Ganador<-Falso
    CantTurnos<-0
    
    Mientras ~ Terminado hacer
        
        // dibuja el tablero
        Borrar Pantalla
        Escribir " "
        Escribir "      ||     ||     "
        Escribir "   ",Tab2[1,1],"  ||  ",Tab2[1,2],"  ||  ",Tab2[1,3]
        Escribir "     1||    2||    3"
        Escribir " =====++=====++======"
        Escribir "      ||     ||     "
        Escribir "   ",Tab2[2,1],"  ||  ",Tab2[2,2],"  ||  ",Tab2[2,3]
        Escribir "     4||    5||    6"
        Escribir " =====++=====++======"
        Escribir "      ||     ||     "
        Escribir "   ",Tab2[3,1],"  ||  ",Tab2[3,2],"  ||  ",Tab2[3,3]
        Escribir "     7||    8||    9"
        Escribir " "
        
        Si ~ Ganador y CantTurnos<9 Entonces
            
            // carga auxiliares segun a qué jugador le toca
            Si TurnoJugador1 Entonces
                Ficha<-'O'; Valor<- 1; Objetivo<-1
                Escribir "Turno del jugador 1 (X)"
            Sino
                Ficha<-'X'; Valor<- 2; Objetivo<-8
                Escribir "Turno del jugador 2 (O)"
            FinSi
            
            // pide la posición para colocar la ficha y la valida
            Escribir "Ingrese la Posición (1-9):"
            
            Repetir
                Leer Pos
                Si Pos<1 o Pos>9 Entonces
                    Escribir "Posición incorrecta, ingrese nuevamente: "
                    Pos<-99;
                Sino
                    i<-trunc((Pos-1)/3)+1
                    j<-((Pos-1) MOD 3)+1
                    Si Tab1[i,j]<>0 Entonces
                        pos<-99
                        Escribir "Posición incorrecta, ingrese nuevamente: "
                    FinSi
                FinSi
            Hasta Que Pos<>99
            // guarda la ficha en la matriz tab2 y el valor en tab1
            CantTurnos<-CantTurnos+1
            Tab1[i,j]<-Valor
            Tab2[i,j]<-Ficha
            
            // verifica si ganó, buscando que el producto de las fichas en el tablero de Objetivo
            aux_d1<-1; aux_d2<-1
            Para i<-1 hasta 3 hacer
                aux_i<-1; aux_j<-1
                aux_d1<-aux_d1*Tab1[i,i]
                aux_d2<-aux_d2*Tab1[i,4-i]
                Para j<-1 hasta 3 hacer
                    aux_i<-aux_i*Tab1[i,j]
                    aux_j<-aux_j*Tab1[j,i]
                FinPara
                Si aux_i=Objetivo o aux_j=Objetivo Entonces
                    Ganador<-Verdadero
                FinSi
            FinPara
            Si aux_d1=Objetivo o aux_d2=Objetivo Entonces
                Ganador<-Verdadero
            Sino
                TurnoJugador1 <- ~ TurnoJugador1
            FinSi
            
        Sino
            
            Si Ganador Entonces
                Escribir "Ganador: "
                Si TurnoJugador1 Entonces
                    Escribir "Jugador 1!"
                Sino
                    Escribir "Jugador 2!"
                FinSi
            Sino
                Escribir "Empate!"
            FinSi
            Terminado<-Verdadero
            
        FinSi
        
    FinMientras
    
FinProceso



SubAlgoritmo division
	
	Definir femeninos Como Entero
	Definir masculinos Como Entero
	Definir total Como Entero

	Escribir "Cuantos hombres hay en la division?"
	Leer masculinos

	Escribir "Cuantas mujeres hay en la division?"
	Leer femeninos

	total <- masculinos + femeninos

	Escribir "La fuerza efectiva de la division es: " total

	Si masculinos = femeninos Entonces
		Escribir "Igual cantidad de femeninos y masculinos"
	FinSi
	Si masculinos < femeninos Entonces
			Escribir "Mayor cantidad de aspirantes femeninos que masculinos"
	FinSi
	Si masculinos > femeninos Entonces
		Escribir "Mayor cantidad de aspirantes masculinos que femeninos"
	FinSi
	
			
FinSubAlgoritmo

SubAlgoritmo financiera

// Una financiera ofrece creditos personales, de hasta 40.000 $ con cuotas fijas mensuales, con los siguientes planes:

	// En 6 cuotas, cobran el 10 % de interos 
    // En 12 cuotas, cobran el 25 % de interos
    // En 18 cuotas, cobran el 55 % de interos

// Indique el valor de la cuota a pagar por una persona que saque un prestamo en esta financiera.

	Escribir "Cuanto es el monto del credito desea sacar?"
	Leer monto

	// Si supera los 40.000 $ volver a pedir el monto
	Si monto > 40000 Entonces
		Escribir "El monto debe ser menor a 40.000"
		Escribir "Cuanto es el monto del credito desea sacar?"
		Leer monto
	FinSi

	Escribir "Cuantas cuotas desea pagar?"
	Leer cuotas

	// Verificar que cuotas sea 6, 12 o 18, si no, volver a pedir cuotas
	Si cuotas <> 6 Entonces
		Si cuotas <> 12 Entonces
			Si cuotas <> 18 Entonces
				Escribir "Las cuotas deben ser 6, 12 o 18"
				Escribir "Cuantas cuotas desea pagar?"
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

FinSubAlgoritmo

SubAlgoritmo aumentos

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

FinSubAlgoritmo

SubAlgoritmo circo

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

SubAlgoritmo producto

	//	Una persona adquirió un producto para pagar en 20 meses. El primer mes pagó 10 euros, el segundo 20 euros, el tercero 40 euros y así sucesivamente. Realizar un algoritmo para determinar cuánto debe pagar mensualmente y el total de lo que pagó después de los 20 meses.

	Definir totalPagar Como Entero
	Definir meses Como Entero

	totalPagar <- 10
	meses <- 20


	// Imprimir cuota de cada mes y cuanto debe pagarse despues de los 20 meses
	Mientras meses <= 20
		Escribir "El total a pagar en el mes " meses " es de: " totalPagar
		totalPagar <- totalPagar * 2
		meses <- meses + 1
	FinMientras

	Escribir "El total a pagar despues de los 20 meses es de: " totalPagar

FinSubAlgoritmo
	
Algoritmo todos
	
	// Ejecutar el algoritmo segun la opcion
	Mientras opcion <> 5 Hacer

		Escribir "1. Division"
		Escribir "2. Financiera"
		Escribir "3. Aumentos"
		Escribir "4. Circo"
		Escribir "5. Salir"
		Leer opcion
		
		Segun opcion
			Caso 1:
				division
			Caso 2:
				financiera
			Caso 3:
				aumentos
			Caso 4:
				circo
		FinSegun
		
	FinMientras
	
FinAlgoritmo

SubAlgoritmo llenarDatos(lista)
	
	// Llenar los datos de una lista de enteros
	
	Definir i Como Entero
	Definir numero Como Entero
	
	i <- 0
	
	Mientras i < 10
		Escribir "Ingrese un numero"
		Leer numero

FinAlgoritmo

SubAlgoritmo serie
	
	// Una empresa esta dividida en N sedes, cada sede en M secciones, y cada seccion tiene un numero no determinado de empleados.
	// De cada empleado se conoce nombre, sexo, edad, salario basico y deducciones.
	// Elabore un algoritmo que permita calcular e imprimir:
	// a) El promedio de edad de los empleados por cada seccion y por cada sede.
	// b) El porcentaje de mujeres de 18 anos por seccion y por sede.
	// c) El numero de mujeres que ganan mas de 4 salarios minimos por seccion.
	// d) Un mensaje "si existe al menos un empleado hombre que gane mas de 20 salarios minimos" de toda la empresa.
	// e) El nombre y la edad de la mujer mas joven por cada seccion.
	// f) El nombre y la edad del hombre mas viejo por cada sede.
	// g) El valor de las deducciones mas altas de toda la empresa.
	// h) El promedio de salarios netos de las mujeres mayores de 18 años por sede y seccion.
	// i) El porcentaje de empleados hombres que ganan menos de dos salarios minimos por cada seccion.
	// j) El salario neto mas bajo de toda la empresa.


	// Definir variables

	Escribir "Cual es el nombre de la empresa?"
	Leer nombreEmpresa

	Escribir "Cuantas sedes tiene la empresa?"
	Leer sedesNumero

	//Dimension de sedes
	Dimension sedesNombre(sedesNumero)
	Dimension sedesNumeroSecciones(sedesNumero)

	i <- 1

	// Ingresar nombre y cantidad de secciones de sedes
	Mientras i <= sedesNumero
		Escribir "Ingrese el nombre de la sede " i
		Leer sedesNombre(i)
		Escribir "Cuantas secciones tiene la sede " i ". " sedesNombre(i)
		Leer sedesNumeroSecciones(i)
		i <- i + 1
	FinMientras

	//Dimension de secciones
	Mientras i <= sedesNumero
		Escribir "Cuantas secciones tiene la sede " i "?"
		Leer sedesNumeroSecciones[i]
		i <- i + 1
	FinMientras


	// Definir dimensiones de secciones
	Dimension seccionesNombres(sedesNumero)
	Dimension seccionesEdades(sedesNumero)

	// Definir las estructuras
	




FinSubAlgoritmo


Algoritmo principal

	Empresa <- ""

	// Definir variables
	Escribir "Bienvenido al programa de empresas"
	Escribir "Ingrese el nombre de la empresa: "
	Leer nombreEmpresa

	Escribir "Ingrese el numero de sedes: "
	Leer sedesNumero

	// Definir dimensiones de sedes
	Dimension sedesNombres(sedesNumero)
	Dimension sedesNumeroSecciones(sedesNumero)

	// Guardar datos empresa
	Empresa <- "{°nombre°:°" + nombreEmpresa + "°,°sedes°:["

	i <- 1
	Mientras i <= sedesNumero
		Escribir "Ingrese el nombre de la sede " i
		Leer sedesNombres(i)

		Escribir "Cuantas secciones tiene la sede " i ". " sedesNombres(i)
		Leer sedesNumeroSecciones(i)

		// Definir dimensiones de secciones
		Dimension seccionesNombres(sedesNumeroSecciones(i))
		Dimension seccionesNumeroPersonas(sedesNumeroSecciones(i))

		j <- 1
		Mientras j <= sedesNumeroSecciones(i)
			Escribir "Ingrese el nombre de la seccion " j " de la sede " i
			Leer seccionesNombres(j)

			Escribir "Cuantas personas tiene la seccion " j " de la sede " i
			Leer seccionesNumeroPersonas(j)

			// Definir dimensiones de personas
			Dimension personasNombres(seccionesNumeroPersonas(j))
			Dimension personasSexo(seccionesNumeroPersonas(j))
			Dimension personasEdades(seccionesNumeroPersonas(j))
			Dimension personasSalarios(seccionesNumeroPersonas(j))
			Dimension personasDeducciones(seccionesNumeroPersonas(j))

			k <- 1
			Mientras k <= seccionesNumeroPersonas(j)
				Escribir "Ingrese el nombre de la persona " k " de la seccion " j " de la sede " i
				Leer personasNombres(k)

				Escribir "Ingrese el sexo de la persona " k " de la seccion " j " de la sede " i
				Leer personasSexo(k)

				Escribir "Ingrese la edad de la persona " k " de la seccion " j " de la sede " i
				Leer personasEdades(k)

				Escribir "Ingrese el salario de la persona " k " de la seccion " j " de la sede " i
				Leer personasSalarios(k)

				Escribir "Ingrese las deducciones de la persona " k " de la seccion " j " de la sede " i
				Leer personasDeducciones(k)

				k <- k + 1
			FinMientras

			// Guardar datos seccion
			Empresa <- Empresa + "{°nombre°:°" + seccionesNombres(j) + "°,°personas°:["

			l <- 1
			Mientras l <= seccionesNumeroPersonas(j)
				Empresa <- Empresa + "{°nombre°:°" + personasNombres(l) + "°,°sexo°:°" + personasSexo(l) + "°,°edad°:°" + personasEdades(l) + "°,°salario°:°" + personasSalarios(l) + "°,°deducciones°:°" + personasDeducciones(l) + "°}"
				l <- l + 1
			FinMientras

			Empresa <- Empresa + "]}"
			j <- j + 1
		FinMientras

		Empresa <- Empresa + "]}"
		i <- i + 1
	FinMientras

	Empresa <- Empresa + "}"

	Escribir Empresa
	
FinAlgoritmo


// Sea una cola de caracteres. Por ejemplo: a, b, a, c, d, x, e, a, b, d. Ordenar de acuerdo al numero de repeticiones del dato
// a. Asendentemente: c, x, e, b, b, d, d, a, a, a
// b. Desendentemente: a, a, a, b, b, d, d, e, x, c

Algoritmo ordenarCaracteres

	// Definir variables
	Dimension caracteres(10)
	
	// Ingreso de datos
	i <- 1
	Mientras i <= 10
		Escribir "Ingrese un caracter: "
		Leer caracteres(i)
		i <- i + 1
	FinMientras

	// Ordenar ascendentemente
	contador <- 0
	j <- 1
	Mientras j <= 10
		k <- 1
		Mientras k <= 10
			Si caracteres(k) = caracteres(j)
				contador <- contador + 1
			FinSi
			k <- k + 1
		FinMientras

		Escribir "El caracter " caracteres(j) " se repite " contador " veces"
		j <- j + 1
		contador <- 0
	FinMientras

	// Ordenar descendentemente
	contador <- 0
	j <- 1
	Mientras j <= 10
		k <- 1
		Mientras k <= 10
			Si caracteres(k) = caracteres(j)
				contador <- contador + 1
			FinSi
			k <- k + 1
		FinMientras

		Escribir "El caracter " caracteres(j) " se repite " contador " veces"
		j <- j + 1
		contador <- 0
	FinMientras
	
FinAlgoritmo




// Desarrolle un algoritmo tal que dada una matriz de nxm elementos indique si un nro x se encuentra en la matriz y en qué posición está.
SubAlgoritmo buscarNroEnMatriz

	// Pedir n y m
	Escribir "n: "
	Leer n
	Escribir "m: "
	Leer m

	// Definir matriz
	Dimension matriz(n, m)

	// Ingreso de datos
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir "Ingrese el elemento " i "," j " de la matriz: "
			Leer matriz(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	// Buscar nro
	Escribir "Ingrese el nro a buscar: "
	Leer nro
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Si matriz(i, j) = nro
				Escribir "El nro " nro " se encuentra en la posicion " i "," j " de la matriz"
			FinSi
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras
	
FinSubAlgoritmo

// Desarrolle un algoritmo tal que dada una matriz de nxm elementos y un nro entero x calcule la suma de sus múltiplos que se encuentren en la matriz.
SubAlgoritmo sumarMultiplosMatriz

	// Pedir n y m
	Escribir "n: "
	Leer n
	Escribir "m: "
	Leer m

	// Definir matriz
	Dimension matriz(n, m)

	// Ingreso de datos
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir "Ingrese el elemento " i "," j " de la matriz: "
			Leer matriz(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	// Buscar multiplos y sumar
	Escribir "Ingrese el nro a buscar: "
	Leer nro
	suma <- 0
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Si (matriz(i, j) % nro) = 0
				suma <- suma + matriz(i, j)
			FinSi
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	Escribir "La suma de los multiplos de " nro " en la matriz es " suma
	
FinSubAlgoritmo

// Desarrolle un algoritmo tal que dada una matriz de nxm elementos y un nro entero x calcule cuántos elementos hay que sean mayores y cuántos menores o iguales.
SubAlgoritmo contarElementosMatriz

	// Pedir n y m
	Escribir "n: "
	Leer n
	Escribir "m: "
	Leer m

	// Definir matriz
	Dimension matriz(n, m)

	// Ingreso de datos
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir "Ingrese el elemento " i "," j " de la matriz: "
			Leer matriz(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	// Buscar multiplos y sumar
	Escribir "Ingrese el nro a buscar: "
	Leer nro
	mayores <- 0
	menores <- 0
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Si matriz(i, j) > nro
				mayores <- mayores + 1
			FinSi
			Si matriz(i, j) <= nro
				menores <- menores + 1
			FinSi
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	Escribir "La cantidad de elementos mayores a " nro " es " mayores
	Escribir "La cantidad de elementos menores o iguales a " nro " es " menores

FinSubAlgoritmo

//  Desarrolle un algoritmo tal que dada una matriz de nxm elementos y un nro entero x muestre en otra matriz los cuadrados de los nros menores a éste y la raíz cuadrada de los nros mayores o iguales.
SubAlgoritmo calcularCuadradosMatriz

	// Pedir n y m
	Escribir "n: "
	Leer n
	Escribir "m: "
	Leer m

	// Definir matriz
	Dimension matriz(n, m)
	Dimension matriz2(n, m)

	// Ingreso de datos
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir "Ingrese el elemento " i "," j " de la matriz: "
			Leer matriz(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	// Buscar multiplos y sumar
	Escribir "Ingrese el nro a buscar: "
	Leer nro
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Si matriz(i, j) < nro
				matriz2(i, j) <- matriz(i, j) ^ 2
			SiNo
				matriz2(i, j) <- matriz(i, j) ^ (1/2)
			FinSi
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	Escribir "La matriz resultante es: "
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir Sin Saltar matriz2(i, j) " "
			j <- j + 1
		FinMientras
		Escribir ""
		i <- i + 1
	FinMientras

FinSubAlgoritmo

//Desarrolle un algoritmo tal que dada una matriz de nxm elementos y un nro entero x reemplace los números mayores o iguales a éste por su doble y los menores por su triple.
SubAlgoritmo reemplazarNrosMatriz

	// Pedir n y m
	Escribir "n: "
	Leer n
	Escribir "m: "
	Leer m

	// Definir matriz
	Dimension matriz(n, m)
	Dimension matriz2(n, m)

	// Ingreso de datos
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir "Ingrese el elemento " i "," j " de la matriz: "
			Leer matriz(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	// Buscar multiplos y sumar
	Escribir "Ingrese el nro a buscar: "
	Leer nro
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Si matriz(i, j) >= nro
				matriz2(i, j) <- matriz(i, j) * 2
			SiNo
				matriz2(i, j) <- matriz(i, j) * 3
			FinSi
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	Escribir "La matriz resultante es: "
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir Sin Saltar matriz2(i, j) " "
			j <- j + 1
		FinMientras
		Escribir ""
		i <- i + 1
	FinMientras

FinSubAlgoritmo

// Desarrolle un algoritmo tal que dada una matriz de nxm elementos muestre la suma de cada una de sus columnas y la suma de cada una de sus filas.
SubAlgoritmo sumarColumnasFilasMatriz

	// Pedir n y m
	Escribir "n: "
	Leer n
	Escribir "m: "
	Leer m

	// Definir matriz
	Dimension matriz(n, m)
	Dimension matriz2(n, m)

	// Ingreso de datos
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir "Ingrese el elemento " i "," j " de la matriz: "
			Leer matriz(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	Dimension sumaColumna(m)
	Dimension sumaFila(n)

	// Sumar
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			sumaFila(i) <- sumaFila(i) + matriz(i, j)
			sumaColumna(j) <- sumaColumna(j) + matriz(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	// Mostrar
	i <- 1
	Mientras i <= n
		Escribir "Los elementos de la fila " (i-1) " suman " sumaFila(i)
		i <- i + 1
	FinMientras

	i <- 1
	Mientras i <= m
		Escribir "Los elementos de la columna " (i-1) " suman " sumaColumna(i)
		i <- i + 1
	FinMientras

FinSubAlgoritmo


// Desarrolle un algoritmo tal que represente mediante una matriz el siguiente problema: Se tienen los precios de 10 artículos y las cantidades vendidas por un almacén en sus 5 sedes. El algoritmo debe responder las siguientes preguntas:
//• Las cantidades totales de cada artículo.
//• La cantidad de artículos en la sede x.
//• La cantidad del articulo a en la sede x.
//• Las ventas totales de cada sede.
//• Las ventas totales del almacén.
SubAlgoritmo problemaDeAlmacen

	// Pedir numero de articulos
	Escribir "Ingrese el numero de articulos: "
	Leer n

	// Pedir cantidad de articulos vendidos por cada sede
	Escribir "Ingrese la cantidad de articulos vendidos por cada sede: "
	Leer m

	// Arreglo de nombre de articulos
	Dimension nombreArticulo(n)

	// Arreglo de sedes
	Dimension sede(m)

	// Nombrar articulos
	i <- 1
	Mientras i <= n
		Escribir "Ingrese el nombre del articulo " i ": "
		Leer nombreArticulo(i)
		i <- i + 1
	FinMientras

	// Nombrar sedes
	i <- 1
	Mientras i <= m
		Escribir "Ingrese el nombre de la sede " i ": "
		Leer sede(i)
		i <- i + 1
	FinMientras

	// Definir matriz de precios
	Dimension matriz(n, m)

	// Ingreso de datos
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir "Ingrese el precio del articulo " nombreArticulo(i) " en la sede " sede(j) ": "
			Leer matriz(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	// Definir matriz de cantidades
	Dimension cantidad(n, m)



Algoritmo main
	Escribir "Punto 1: Buscar numero en matriz"
	buscarNroEnMatriz
	Escribir "Punto 2: Sumar multiplos de un numero en una matriz"
	sumarMultiplosMatriz
	Escribir "Punto 3: Contar elementos de una matriz"
	contarElementosMatriz
	Escribir "Punto 4: Calcular cuadrados de una matriz"
	calcularCuadradosMatriz
	Escribir "Punto 5: Reemplazar nros mayores o iguales a un numero en una matriz"
	reemplazarNrosMatriz
	Escribir "Punto 6: Sumar columnas y filas de una matriz"
	sumarColumnasFilasMatriz
FinAlgoritmo