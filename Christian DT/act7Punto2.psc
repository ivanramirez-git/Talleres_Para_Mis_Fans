Algoritmo act7Punto2
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
    // Sumar los elementos superiores a la diagonal Principal
    I<-1
    Mientras I<=N
        J<-I+1
        Mientras J<=N
            Acumulador<-Acumulador+Arreglo[I,J]
            J<-J+1
        FinMientras
        I<-I+1
    FinMientras
    // Imprimir el resultado
    Escribir "La suma de los elementos superiores a la diagonal principal es: ", Acumulador
FinAlgoritmo