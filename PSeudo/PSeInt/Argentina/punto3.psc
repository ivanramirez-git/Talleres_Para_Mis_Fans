Algoritmo punto3
    // Ingrese los 3 numeros
    Escribir "Ingrese los 3 numeros: "
    Escribir "Ingrese el primer numero: "
    Leer num1
    Escribir "Ingrese el segundo numero: "
    Leer num2
    Escribir "Ingrese el tercer numero: "
    Leer num3
    // Verificar si son consecutivos
    suma<-num1+num2+num3
    promedio<-suma/3
    Si num1 == promedio o num2 == promedio o num3 == promedio
        Si num1 == num2+1 o num1 == num2-1 o num1 == num3+1 o num1 == num3-1
            Escribir "Los numeros son consecutivos"
        FinSi
    SiNo
        Escribir "Los numeros no son consecutivos"
    FinSi
FinAlgoritmo