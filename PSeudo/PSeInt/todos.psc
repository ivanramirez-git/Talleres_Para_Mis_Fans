

/*
realizar un algoritmo que lea cuando el cliente inserte la moneda, que esta le de 3 generos musicales, de cada genero musical 3 artistas, y por cada artista 20 canciones de las  cuales el usuario podra elegir la cancion a reproducir
*/
Algoritmo rockola

	moneda = -1
	Mientras moneda <> 0

		// Definir matriz
		Dimension generos(3)
		Dimension artistas(3, 3)
		Dimension canciones(3, 3, 20)

		// Datos		
		// Llenar datos
		generos(1) <- "Reggueton"
		generos(2) <- "Pop"
		generos(3) <- "Electronica"
		artistas(1,1) <- "Bad Bunny"
		artistas(1,2) <- "J Balvin"
		artistas(1,3) <- "Karol G"
		artistas(2,1) <- "Justin Bieber"
		artistas(2,2) <- "Bruno Mars"
		artistas(2,3) <- "Shakira"
		artistas(3,1) <- "Coldplay"
		artistas(3,2) <- "Imagine Dragons"
		artistas(3,3) <- "The Chainsmokers"

		canciones(1,1,1) <- "DAKITI"
		canciones(1,1,2) <- "MIA"
		canciones(1,1,3) <- "Yonaguni"
		canciones(1,1,4) <- "La Noche de Anoche"
		canciones(1,1,5) <- "Yo Perreo sola"
		canciones(1,1,6) <- "Callaita"
		canciones(1,1,7) <- "Vete"
		canciones(1,1,8) <- "Safaera"
		canciones(1,1,9) <- "La Dificil"
		canciones(1,1,10) <- "Si Veo a Tu Mama"
		canciones(1,1,11) <- "La Santa"
		canciones(1,1,12) <- "Ignorantes"
		canciones(1,1,13) <- "Si Estuvieramos Juntos"
		canciones(1,1,14) <- "Pero Ya No"
		canciones(1,1,15) <- "Solo de Mi"
		canciones(1,1,16) <- "Bichiyal"
		canciones(1,1,17) <- "Ni Bien Ni Mal"
		canciones(1,1,18) <- "Solia"
		canciones(1,1,19) <- "Amorfoda"
		canciones(1,1,20) <- "La Romana"

		canciones(1,2,1) <- "Medusa"
		canciones(1,2,2) <- "Morado"
		canciones(1,2,3) <- "Blanco"
		canciones(1,2,4) <- "Ritmo"
		canciones(1,2,5) <- "Que Pena"
		canciones(1,2,6) <- "La Cancion"
		canciones(1,2,7) <- "Reggueton"
		canciones(1,2,8) <- "Que Pretendes"
		canciones(1,2,9) <- "Loco contigo"
		canciones(1,2,10) <- "Ven y hazlo tú"
		canciones(1,2,11) <- "Con altura"
		canciones(1,2,12) <- "Contra la pared"
		canciones(1,2,13) <- "Bola rebola"
		canciones(1,2,14) <- "Say My Name"
		canciones(1,2,15) <- "No Es Justo"
		canciones(1,2,16) <- "I Like It"
		canciones(1,2,17) <- "Machika"
		canciones(1,2,18) <- "Downtown"
		canciones(1,2,19) <- "Bum Bum Tam Tam"
		canciones(1,2,20) <- "Mi Gente"

		canciones(1,3,1) <- "Pineapple"
		canciones(1,3,2) <- "Tu Pum Pum"
		canciones(1,3,3) <- "Princesa"
		canciones(1,3,4) <- "Dicen"
		canciones(1,3,5) <- "Punto G"
		canciones(1,3,6) <- "Mi cama"
		canciones(1,3,7) <- "Dices que te vas"
		canciones(1,3,8) <- "Follow"
		canciones(1,3,9) <- "Bichota"
		canciones(1,3,10) <- "El Makinon"
		canciones(1,3,11) <- "Tusa"
		canciones(1,3,12) <- "Location"
		canciones(1,3,13) <- "Ocean"
		canciones(1,3,14) <- "Culpables"
		canciones(1,3,15) <- "Creeme"
		canciones(1,3,16) <- "Princesa"
		canciones(1,3,17) <- "Mi Mala"
		canciones(1,3,18) <- "A Ella"
		canciones(1,3,19) <- "Si te confieso"
		canciones(1,3,20) <- "China"
		
		canciones(2,1,1) <- "One Time"
		canciones(2,1,2) <- "One Less Lonely
		canciones(2,1,3) <- "Baby"
		canciones(2,1,4) <- "Eenie Meenie"
		canciones(2,1,5) <- "Somebody to Love"
		canciones(2,1,6) <- "U Smile"
		canciones(2,1,7) <- "Never Say Never"
		canciones(2,1,8) <- "Pray"
		canciones(2,1,9) <- "Mistletoe"
		canciones(2,1,10) <- "Boyfriend"
		canciones(2,1,11) <- "As Long as You Love Me"
		canciones(2,1,12) <- "Beauty and a Beat"
		canciones(2,1,13) <- "Attention"
		canciones(2,1,14) <- "Ghost"
		canciones(2,1,15) <- "Wandered to LA"
		canciones(2,1,16) <- "Don't Go"
		canciones(2,1,17) <- "Stay"
		canciones(2,1,18) <- "Peaches"
		canciones(2,1,19) <- "Anyone"
		canciones(2,1,20) <- "Hold On"

		canciones(2,2,1) <- "Just the Way You Are"
		canciones(2,2,2) <- "Grenade"
		canciones(2,2,3) <- "The Lazy Song"
		canciones(2,2,4) <- "Marry You"
		canciones(2,2,5) <- "It Will Rain"
		canciones(2,2,6) <- "Count on Me"
		canciones(2,2,7) <- "Locked Out of Heaven"
		canciones(2,2,8) <- "When I Was Your"
		canciones(2,2,9) <- "Treasure"
		canciones(2,2,10) <- "Young Girls"
		canciones(2,2,11) <- "Gorilla"
		canciones(2,2,12) <- "24K Magic"
		canciones(2,2,13) <- "That's What I Like"
		canciones(2,2,14) <- "Versace on the Floor"
		canciones(2,2,15) <- "Chunky"
		canciones(2,2,16) <- "Please Me"
		canciones(2,2,17) <- "Blow"
		canciones(2,2,18) <- "Leave the Door Open"
		canciones(2,2,19) <- "Nothin' on You"
		canciones(2,2,20) <- "Billionaire"

		canciones(2,3,1) <- "The One"
		canciones(2,3,2) <- "Te dejo Madrid"
		canciones(2,3,3) <- "Que me quedes tú"
		canciones(2,3,4) <- "No"
		canciones(2,3,5) <- "Don't Bother"
		canciones(2,3,6) <- "Día de enero"
		canciones(2,3,7) <- "Gypsy / Gitana"
		canciones(2,3,8) <- "She Wolf / Loba"
		canciones(2,3,9) <- "Sale el sol"
		canciones(2,3,10) <- "Rabiosa"
		canciones(2,3,11) <- "Antes de las seis"
		canciones(2,3,12) <- "Je L'aime A Mourir"
		canciones(2,3,13) <- "Addicted to You"
		canciones(2,3,14) <- "Empire"
		canciones(2,3,15) <- "Try Everything"
		canciones(2,3,16) <- "Chantaje"
		canciones(2,3,17) <- "Me enamoré"
		canciones(2,3,18) <- "Perro fiel"
		canciones(2,3,19) <- "Trap"
		canciones(2,3,20) <- "Clandestino"

		canciones(3,1,1) <- "Fix You"
		canciones(3,1,2) <- "Talk"	
		canciones(3,1,3) <- "The Hardest Part"
		canciones(3,1,4) <- "What If"
		canciones(3,1,5) <- "White Shadows"
		canciones(3,1,6) <- "Violet Hill"
		canciones(3,1,7) <- "Viva la Vida"
		canciones(3,1,8) <- "Christmas Lights"
		canciones(3,1,9) <- "Paradise"
		canciones(3,1,10) <- "Charlie Brown"
		canciones(3,1,11) <- "Princess of China"
		canciones(3,1,12) <- "Atlas"
		canciones(3,1,13) <- "Hurts Like Heaven"
		canciones(3,1,14) <- "Let Somebody Go"
		canciones(3,1,15) <- "Higher Power"
		canciones(3,1,16) <- "Champion of the World"
		canciones(3,1,17) <- "Daddy"
		canciones(3,1,18) <- "Arabesque"
		canciones(3,1,19) <- "Something Just Like This"
		canciones(3,1,20) <- "Orphans"

		canciones(3,2,1) <- "Enemy (feat. J.I.D)"
		canciones(3,2,2) <- "Believer"
		canciones(3,2,3) <- "Demons"
		canciones(3,2,4) <- "Enemy (Solo Mix)"
		canciones(3,2,5) <- "Bones"
		canciones(3,2,6) <- "Next To Me"
		canciones(3,2,7) <- "Wrecked"
		canciones(3,2,8) <- "Bad Liar"
		canciones(3,2,9) <- "Natural"
		canciones(3,2,10) <- "Follow You"
		canciones(3,2,11) <- "Thunder"
		canciones(3,2,12) <- "Birds"
		canciones(3,2,13) <- "Radioactive"
		canciones(3,2,14) <- "It's Time"
		canciones(3,2,15) <- "Not Today"
		canciones(3,2,16) <- "Whatever It Takes"
		canciones(3,2,17) <- "One Day"
		canciones(3,2,18) <- "Radioactive"
		canciones(3,2,19) <- "Dream"
		canciones(3,2,20) <- "Monday"

		canciones(3,3,1) <- "Something Just Like This"
		canciones(3,3,2) <- "Closer"
		canciones(3,3,3) <- "Don't Let Me Down"
		canciones(3,3,4) <- "Paris"
		canciones(3,3,5) <- "Who Do You Love"
		canciones(3,3,6) <- "Takeaway"
		canciones(3,3,7) <- "Roses"
		canciones(3,3,8) <- "Sick
		canciones(3,3,9) <- "Call You Mine"
		canciones(3,3,10) <- "Family"
		canciones(3,3,11) <- "All We Know"
		canciones(3,3,12) <- "This Feeling"
		canciones(3,3,13) <- "Hope"
		canciones(3,3,14) <- "Beach House"
		canciones(3,3,15) <- "Honest"
		canciones(3,3,16) <- "Young"
		canciones(3,3,17) <- "iPad"
		canciones(3,3,18) <- "The One"
		canciones(3,3,19) <- "You Owe Me"
		canciones(3,3,20) <- "#SELFIE"

		// rockola
		Escribir "Inserte una moneda (0 para salir): "
		Leer moneda

		// Mostrar los Generos
		Escribir "Generos: "
		i <- 1
		Mientras i <= 3
			Escribir generos(i)
			i <- i + 1
		FinMientras
		// Pedir genero
		Escribir "Ingrese el genero: "
		Leer genero

		// Mostrar los Artistas
		Escribir "Artistas: "
		i <- 1
		Mientras i <= 3
			Escribir artistas(genero, i)
			i <- i + 1
		FinMientras
		// Pedir artista
		Escribir "Ingrese el artista: "
		Leer artista

		// Mostrar las canciones
		Escribir "Canciones: "
		i <- 1
		Mientras i <= 20
			Escribir canciones(genero, artista, i)
			i <- i + 1
		FinMientras
		// Pedir cancion
		Escribir "Ingrese la cancion: "
		Leer cancion

		// Reproducir cancion
		Escribir "Reproduciendo cancion..."
		Escribir canciones(genero, artista, cancion)

		Leer tecla

		// Fin
		Escribir "Canción finalizada"

	FinMientras

Fin

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

	// Ingreso de datos
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir "Ingrese la cantidad vendida del articulo " nombreArticulo(i) " en la sede " sede(j) ": "
			Leer cantidad(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	// Resultados
	Escribir "Las cantidades totales de cada articulo son: "
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir "El articulo " nombreArticulo(i) " en la sede " sede(j) " tiene " cantidad(i, j) " unidades vendidas"
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	Escribir "Ingrese la sede x a consultar: "
	Leer x

	Escribir "Las cantidad de articulos en la sede " x " son: "
	i <- 1
	total <- 0
	Mientras i <= n
		total <- total + cantidad(i, x)
		i <- i + 1
	FinMientras
	Escribir total

	Escribir "Ingrese el articulo a consultar: "
	Leer a

	Escribir "La cantidad del articulo " a " en la sede " x " es: " cantidad(a, x)

	Escribir "Las ventas totales de cada sede son: "
	i <- 1
	Mientras i <= m
		j <- 1
		total <- 0
		Mientras j <= n
			total <- total + cantidad(j, i)
			j <- j + 1
		FinMientras
		Escribir "La sede " sede(i) " tiene " total " unidades vendidas"
		i <- i + 1
	FinMientras

	Escribir "Las ventas totales del almacen son: "
	i <- 1
	total <- 0
	Mientras i <= n
		j <- 1
		Mientras j <= m
			total <- total + cantidad(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras
	Escribir total

FinSubAlgoritmo

//Desarrolle un algoritmo tal que dada una matriz de nxm elementos calcule su promedio y sume los valores que se encuentren en la matriz y que sean mayores a éste además sumar los cuadrados de los números que sean menores o iguales a éste.
SubAlgoritmo promedioMatriz

	// Pedir n
	Escribir "Ingrese el numero de filas: "
	Leer n

	// Pedir m
	Escribir "Ingrese el numero de columnas: "
	Leer m

	// Definir matriz
	Dimension matriz(n, m)

	// Ingreso de datos
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir "Ingrese el valor de la posicion " i "," j ": "
			Leer matriz(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	// Promedio
	promedio <- 0
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			promedio <- promedio + matriz(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras
	promedio <- promedio / (n * m)

	// Suma de valores mayores al promedio
	suma <- 0
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Si matriz(i, j) > promedio
				suma <- suma + matriz(i, j)
			FinSi
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	Escribir "La suma de los valores mayores al promedio es: " suma

	// Suma de cuadrados de valores menores o iguales al promedio
	suma <- 0
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Si matriz(i, j) <= promedio
				suma <- suma + matriz(i, j) ^ 2
			FinSi
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	Escribir "La suma de los cuadrados de los valores menores o iguales al promedio es: " suma


FinSubAlgoritmo

//Desarrolle un algoritmo tal que dada una matriz de nxm elementos que corresponden a los nombres de unos estudiantes de Algoritmos muestre aquellos cuyo nombres tenga una longitud mayor o igual de 10 letras y cuente cuántos tienen menos de 10 letras.
SubAlgoritmo nombres

	// Pedir n
	Escribir "Ingrese el numero de filas: "
	Leer n

	// Pedir m
	Escribir "Ingrese el numero de columnas: "
	Leer m

	// Definir matriz
	Dimension matriz(n, m)

	// Ingreso de datos
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Escribir "Ingrese el nombre del estudiante " i ": "
			Leer matriz(i, j)
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	// Resultados
	Escribir "Los nombres de los estudiantes con mas de 10 letras son: "
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Si longitud(matriz(i, j)) >= 10
				Escribir matriz(i, j)
			FinSi
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras

	Escribir "Los nombres de los estudiantes con menos de 10 letras son: "
	i <- 1
	Mientras i <= n
		j <- 1
		Mientras j <= m
			Si longitud(matriz(i, j)) < 10
				Escribir matriz(i, j)
			FinSi
			j <- j + 1
		FinMientras
		i <- i + 1
	FinMientras


FinSubAlgoritmo


Algoritmo main
	opcion <- -1
	Mientras opcion <> 0
		Escribir "1. Buscar numero en matriz"
		Escribir "2. Sumar multiplos de un numero en una matriz"
		Escribir "3. Contar elementos de una matriz"
		Escribir "4. Calcular cuadrados de una matriz"
		Escribir "5. Reemplazar nros mayores o iguales a un numero en una matriz"
		Escribir "6. Sumar columnas y filas de una matriz"
		Escribir "7. Almacen"
		Escribir "8. Promedio"
		Escribir "9. Nombres"
		Escribir "0. Salir"
		Escribir "Ingrese una opcion: "
		Leer opcion
		Si opcion = 1
			Escribir "Punto 1: Buscar numero en matriz"
			buscarNroEnMatriz
		FinSi
		Si opcion = 2
			Escribir "Punto 2: Sumar multiplos de un numero en una matriz"
			sumarMultiplosMatriz
		FinSi
		Si opcion = 3
			Escribir "Punto 3: Contar elementos de una matriz"
			contarElementosMatriz
		FinSi
		Si opcion = 4
			Escribir "Punto 4: Calcular cuadrados de una matriz"
			calcularCuadradosMatriz
		FinSi
		Si opcion = 5
			Escribir "Punto 5: Reemplazar nros mayores o iguales a un numero en una matriz"
			reemplazarNrosMatriz
		FinSi
		Si opcion = 6
			Escribir "Punto 6: Sumar columnas y filas de una matriz"
			sumarColumnasFilasMatriz
		FinSi
		Si opcion = 7
			Escribir "Punto 7: Almacen"
			problemaDeAlmacen
		FinSi
		Si opcion = 8
			Escribir "Punto 8: Promedio"
			promedioMatriz
		FinSi
		Si opcion = 9
			Escribir "Punto 9: Nombres"
			nombres
		FinSi
	FinMientras

FinAlgoritmo


// Algoritmo que permita mostrar los n primeros multiplos de M
SubAlgoritmo multiplos
	// Pedir n
	Escribir "Ingrese el numero de multiplos a mostrar: "
	Leer n

	// Pedir M
	Escribir "Ingrese el numero de multiplos: "
	Leer M

	// Definir matriz
	Dimension matriz(n)

	// Ingreso de datos
	i <- 1
	Mientras i <= n
		matriz(i) <- i * M
		i <- i + 1
	FinMientras

	// Resultados
	Escribir "Los multiplos de " M " son: "
	i <- 1
	Mientras i <= n
		Escribir matriz(i)
		i <- i + 1
	FinMientras

FinSubAlgoritmo

// Algoritmo que permita generar la secuencia de Fibonacci hasta el n-esimo numero
SubAlgoritmo fibonacci
	// Pedir n
	Escribir "Ingrese el numero de Fibonacci a mostrar: "
	Leer n

	// Definir matriz
	Dimension matriz(n)

	// Ingreso de datos
	matriz(1) <- 1
	matriz(2) <- 1
	i <- 3
	Mientras i <= n
		matriz(i) <- matriz(i - 1) + matriz(i - 2)
		i <- i + 1
	FinMientras

	// Resultados
	Escribir "La secuencia de Fibonacci hasta el " n " es: "
	i <- 1
	Mientras i <= n
		Escribir matriz(i)
		i <- i + 1
	FinMientras


FinSubAlgoritmo

// principal
Algoritmo principal
	// Menu
	opcion <- -1
	Mientras opcion <> 0
		Escribir "1. Multiplos"
		Escribir "2. Fibonacci"
		Escribir "0. Salir"
		Escribir "Ingrese una opcion: "
		Leer opcion
		Si opcion = 1
			Escribir "Punto 1: Multiplos"
			multiplos
		FinSi
		Si opcion = 2
			Escribir "Punto 2: Fibonacci"
			fibonacci
		FinSi
	FinMientras


FinAlgoritmo


/*
Un supermercado ha puesto en oferta la venta de postres a los precios dados en la siguiente tabla:

Postre			Precio
Flan Royal		$2.80
Pudin Royal		$3.70
Gelatina Royal	$4.80

Como oferta especial la tienda aplica un porcentaje de descuento sobre el importe de la compra de acuerdo a la siguiente tabla:

Cantidad de postres			Descuento
>= 12							13%
>= 8 y < 12						11%
>= 4 y < 8						9%
< 4								7%

Diseñe un programa que permita efectuar ventas y muestre luego de cada una de ellas la siguiente informacion:
El importe de la compra
El importe del descuento
El importe a pagar
La cantidad de postres vendidos de cada tipo entre todas las ventas
La cantidad de ventas efectuadas de cada tipo de postre entre todas las ventas
El importe total acumulado de cada tipo de postre entre todas las ventas


*/
Algoritmo Principal
	// variables
	importeDeCompra = 0.0
	importeDeDescuento = 0.0
	importeAPagar = 0.0
	cantidadDePostres = 0
	cantidadDeVentas = 0
	importeTotal = 0.0

	Dimension cantPostres(3)

	opcion = -1

	// Ingreso de datos
	Mientras opcion <> 0
		Escribir "Compra Actual: "
		Escribir "Flan Royal => " cantPostres(1)
		Escribir "Pudin Royal => " cantPostres(2)
		Escribir "Gelatina Royal => " cantPostres(3)
		Escribir ""
		Escribir "1. Flan Royal"
		Escribir "2. Pudin Royal"
		Escribir "3. Gelatina Royal"
		Escribir "0. Salir"
		Escribir "Ingrese el tipo de postre: "
		opcion = -1
		Mientras opcion <> 1 && opcion <> 2 && opcion <> 3 && opcion <> 0
			Leer opcion
		FinMientras

		Si opcion <> 0
			Escribir "Ingrese la cantidad de postres: "
			cantidadDePostres = 0
			Mientras cantidadDePostres < 1
				Leer cantidadDePostres
			FinMientras
			cantPostres(opcion) <- cantPostres(opcion) + cantidadDePostres
			cantidadDeVentas <- cantidadDeVentas + 1
		FinSi
	FinMientras

	// Calculos
	importeDeCompra = (cantPostres(1) * 2.8) + (cantPostres(2) * 3.7) + (cantPostres(3) * 4.8)

	Si cantPostres(1) + cantPostres(2) + cantPostres(3) >= 12
		importeDeDescuento = importeDeCompra * 0.13
	FinSi

	Si cantPostres(1) + cantPostres(2) + cantPostres(3) >= 8 && cantPostres(1) + cantPostres(2) + cantPostres(3) < 12
		importeDeDescuento = importeDeCompra * 0.11
	FinSi

	Si cantPostres(1) + cantPostres(2) + cantPostres(3) >= 4 && cantPostres(1) + cantPostres(2) + cantPostres(3) < 8
		importeDeDescuento = importeDeCompra * 0.09
	FinSi

	Si cantPostres(1) + cantPostres(2) + cantPostres(3) < 4
		importeDeDescuento = importeDeCompra * 0.07
	FinSi

	importeAPagar = importeDeCompra - importeDeDescuento

	cantidadDePostres <- cantPostres(1) + cantPostres(2) + cantPostres(3)

	// Resultados
	Escribir "Importe de la compra: " importeDeCompra
	Escribir "Importe del descuento: " importeDeDescuento
	Escribir "Importe a pagar: " importeAPagar
	Escribir "Cantidad de postres vendidos: "
	Escribir "Flan Royal => " cantPostres(1) " con un total de " cantPostres(1) * 2.8
	Escribir "Pudin Royal => " cantPostres(2) " con un total de " cantPostres(2) * 3.7
	Escribir "Gelatina Royal => " cantPostres(3) " con un total de " cantPostres(3) * 4.8
	Escribir "Cantidad de ventas: " cantidadDeVentas

FinAlgoritmo
	


/*
-Programa que, al recibir un arreglo unidimensional de tipo entero de tamaño N, que contiene números aleatorios en un rango de 1 a 100, calcule lo siguiente:
-La media aritmética. Ésta se calcula como la suma de los elementos entre el número de elementos.
-La varianza. Ésta se calcula como la suma de los cuadrados de las desviaciones de la media, entre el número de elementos.
-La desviación estándar. Se calcula como la raíz cuadrada de la varianza.
-La moda. Se calcula obteniendo el número con mayor frecuencia.
*/

Algoritmo Principal

	// Variables
	N = 0
	Escribir "Ingrese el tamaño del arreglo: "
	Leer N
	Dimension arreglo(N)
	
	// Ingreso de datos
	Para i = 1 hasta N
		arreglo(i) = Aleatorio(1, 100)
	FinPara

	// Calculos
	Calcula(arreglo, N)

FinAlgoritmo

SubAlgoritmo Calcula(arreglo, N)
	media = 0.0
	varianza = 0.0
	desviacion = 0.0
	moda = arreglo(1)
	Dimension frecuencias(100)

	// frecuencias en 0
	Para i = 1 hasta 100
		frecuencias(i) = 0
	FinPara

	// frecuencias en 1
	Para i = 1 hasta N
		frecuencias(arreglo(i)) = frecuencias(arreglo(i)) + 1
	FinPara

	// media
	Para i = 1 hasta N
		media = media + arreglo(i)
	FinPara
	media = media / N

	// varianza
	Para i = 1 hasta N
		varianza = varianza + ( (arreglo(i) - media) * (arreglo(i) - media) )
	FinPara
	varianza = varianza / N

	// desviacion
	desviacion = Raiz(varianza)

	// moda
	Escribir sin saltar "["
	Para i = 1 hasta N
		Escribir sin saltar arreglo(i) ", "
		Si frecuencias(arreglo(i)) > frecuencias(moda)
			moda = arreglo(i)
		FinSi
	FinPara
	Escribir "]"

	// Resultados
	Escribir "Media: " media
	Escribir "Varianza: " varianza
	Escribir "Desviacion: " desviacion
	Escribir "Moda: " moda

FinSubAlgoritmo
		




