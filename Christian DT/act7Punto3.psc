Algoritmo act7Punto3
    // Ingrese el numero de datos
    Escribir "Ingrese el numero de datos: "
    Leer N
    // Dimensionar el matriz de NxN
    Dimension Arreglo[N,N];
    // Pedir los datos
    I<-1
    Mientras I<=N
        J<-1
        Mientras J<=N
            // Ingrese el dato
            Escribir "Ingrese el dato " , I, "," , J, ": "
            Leer Arreglo[I,J]
            J<-J+1
        FinMientras
        I<-I+1
    FinMientras
    // Imprimir la matriz de forma inversa con saltos de linea y espacios
    I<-N
    Mientras I>=1
        J<-N
        Mientras J>=1
            Escribir sin saltar de linea Arreglo[I,J]
            J<-J-1
        FinMientras
        Escribir ""
        I<-I-1
    FinMientras
FinAlgoritmo