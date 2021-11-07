// Ingrese una cadena de texto
    Escribir "Ingrese una cadena de texto: "
    Leer texto
	Escribir "Una cadena mas grande de texto: "
    Leer texto2	
    // Cuantas veces aparece texto en texto2?    
    j<-longitud(texto)
	i<-longitud(texto2)	
	contador<-0
    k<-1	
    //Escribir "Las longitudes son j: " j " y i: " i " y k: " k
    cade2<-subcadena(texto2,k,j)
    Mientras k<i Hacer
        //Escribir "Cadena 2: " cade2
        Si cade2==texto
            contador<-contador+1
        FinSi
        k<-k+1
        j<-j+1		
        //Escribir "Las longitudes son j: " j " y i: " i " y k: " k		
        cade2<-subcadena(texto2,k,j)
    FinMientras
    // Mostrar el resultado
    Escribir "El texto aparece ",contador," veces en la cadena"