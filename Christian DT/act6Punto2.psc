Algoritmo act6Punto2
    // Ingrese el numero de datos
    Escribir "Ingrese el numero de datos: "
    Leer N
    // Dimensionar los vectores
    Dimension Arreglo1[N];
    Dimension Arreglo2[N];
    Dimension Arreglo3[N];
    // Pedir los datos
    I<-1
    Mientras I<=N
        // Ingrese el dato
        Escribir "Ingrese el dato " , I, " del primer arreglo: "
        Leer Arreglo1[I]
        I<-I+1
    FinMientras
    I<-1
    Mientras I<=N
        // Ingrese el dato
        Escribir "Ingrese el dato " , I, " del segundo arreglo: "
        Leer Arreglo2[I]
        I<-I+1
    FinMientras
    // Sumar los elementos del arreglo
    I<-1
    Mientras I<=N
        Arreglo3[I]<-Arreglo1[I]+Arreglo2[I]
        I<-I+1
    FinMientras
    // Imprimir el resultado
    Escribir "El arreglo resultante es: "
    I<-1
    Mientras I<=N
        Escribir sin saltar Arreglo3[I] " "
        I<-I+1
    FinMientras
FinAlgoritmo