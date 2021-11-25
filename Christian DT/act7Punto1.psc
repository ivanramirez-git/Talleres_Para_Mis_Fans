Algoritmo act7Punto1
    // Ingrese el numero de datos
    Escribir "Ingrese el numero de datos: "
    Leer N
    // Dimensionar el arreglo
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
    // Iniciar acumulador
    Acumulador<-0
    // Sumar los elementos de la diagonal principal
    I<-1
    Mientras I<=N
        Acumulador<-Acumulador+Arreglo[I,I]
        I<-I+1
    FinMientras
    // Sumar los elementos de la diagonal secundaria
    I<-1
    Acumulador2<-0
    Mientras I<=N
        Acumulador2<-Acumulador2+Arreglo[I,N-I+1]
        I<-I+1
    FinMientras
    // Imprimir el resultado
    Escribir "La suma de los elementos de la diagonal principal es: ", Acumulador
    Escribir "La suma de los elementos de la diagonal secundaria es: ", Acumulador2
FinAlgoritmo