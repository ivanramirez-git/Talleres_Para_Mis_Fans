Algoritmo act6Punto1
    // Ingrese el numero de datos
    Escribir "Ingrese el numero de datos: "
    Leer N
    // Dimensionar el arreglo
    Dimension Arreglo[N];
    // Pedir los datos
    I<-1
    Mientras I<=N
        // Ingrese el dato
        Escribir "Ingrese el dato " , I, ": "
        Leer Arreglo[I]
        I<-I+1
    FinMientras
    
    // Iniciar acumulador
    Acumulador<-0
    // Sumar los elementos del arreglo
    I<-1
    Mientras I<=N
        Acumulador<-Acumulador+Arreglo[I]
        I<-I+1
    FinMientras
    // Imprimir el resultado
    Escribir "La suma de los elementos del arreglo es: ", Acumulador
FinAlgoritmo