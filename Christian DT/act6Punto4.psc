Algoritmo act6Punto4
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
    I<-1
    Acumulador<-0
    Mientras I<=N
        // Si el dato es positivo
        Si Arreglo[I]>0
            // Acumular
            Acumulador<-Acumulador+1
        FinSi
        I<-I+1
    FinMientras
    // Imprimir el resultado
    Escribir "La cantidad de numeros positivos es: ", Acumulador
FinAlgoritmo
