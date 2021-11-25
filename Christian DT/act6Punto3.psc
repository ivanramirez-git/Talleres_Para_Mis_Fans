Algoritmo act6Punto3
    // Dimensionar el arreglo
    Dimension Arreglo[10];
    // Pedir los datos
    I<-1
    Mientras I<=10
        // Ingrese el dato
        Arreglo[I]<-azar(100)
        I<-I+1
    FinMientras
    // Imprimir el resultado
    Escribir "El arreglo resultante es: "
    I<-1
    Escribir sin saltar "["
    Mientras I<=10
        Si I+1<=10
            Escribir sin saltar Arreglo[I], ", "
        SiNo
            Escribir sin saltar Arreglo[I]
        FinSi
        I<-I+1
    FinMientras
    Escribir sin saltar "]"
FinAlgoritmo