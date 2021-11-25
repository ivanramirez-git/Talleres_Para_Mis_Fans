
Algoritmo punto4
    Definir NUM_ENTERO como entero;
    Definir NUM_REAL como real;
	
	
    // Ingrese el numero real positivo menor que 1 validando que sea menor que 1
    Escribir "Ingrese el numero real positivo menor que 1: "
    Leer Z
    // Validar que sea menor que 1
    Mientras Z>=1
        Escribir "El numero ingresado no es menor que 1"
        // Ingrese el numero real positivo menor que 1 validando que sea menor que 1
        Escribir "Ingrese el numero real positivo menor que 1: "
        Leer Z
    FinMientras
	
	
    // Ingrese la base
    Escribir "Ingrese la base esperada: "
    Leer B
	
    // Ingrese el numero de cifras
    Escribir "Ingrese el numero de cifras: "
    Leer K
	K<-K+1
	
    Dimension CIFRA[K];
    Definir PROD como real;
	
    I<-1
    // Iniciar ciclo
    Mientras I<>K
        PROD<-Z*B
        NUM_ENTERO<-TRUNC(PROD)
        Z<-PROD-NUM_ENTERO
        CIFRA[I]<-NUM_ENTERO
        Si Z==0
            I<-1            
            Escribir "El numero en base ", B, " es: "
			Escribir Sin Saltar "0."
            Mientras I<>K
                Escribir sin saltar CIFRA[I]
                I<-I+1
            FinMientras
        SiNo
            I<-I+1
        FinSi
    FinMientras
    Si Z<>0
        I<-1
        Escribir "El numero en base ", B, " es: "
		Escribir Sin Saltar "0."
        Mientras I<>K
            Escribir sin saltar CIFRA[I]
            I<-I+1
        FinMientras
    FinSi
	Escribir ""
	
    // Fin del ciclo
FinAlgoritmo