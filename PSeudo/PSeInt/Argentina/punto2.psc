// Desarolle un algoritmo que lea los angulos interiones de un triangulo y muestre un mensaje indicando si es: Acutangulo, Obtusangulo o Rectangulo.
Algoritmo punto2
    // Ingrese los angulos internos del triangulo
    Escribir "Ingrese los angulos internos del triangulo: "
    Leer angulo1
    Leer angulo2
    Leer angulo3
    // Acutangulo si sus 3 angulos miden menos de 90 grados
    Si angulo1<90 y angulo2<90 y angulo3<90 y angulo1+angulo2+angulo3==180
        Escribir "El triangulo es acutangulo"
    FinSi
    // Obtusangulo si uno de sus 3 angulos mide mas de 90 grados
    Si angulo1>90 o angulo2>90 o angulo3>90 y angulo1+angulo2+angulo3==180
        Escribir "El triangulo es obtusangulo"
    FinSi
    // Rectangulo si uno de sus 3 angulos miden exactamente 90 grados
    Si angulo1==90 o angulo2==90 o angulo3==90 y angulo1+angulo2+angulo3==180
        Escribir "El triangulo es rectangulo"
    FinSi
    // Si no es ninguno de los anteriores
    Si angulo1+angulo2+angulo3<>180
        Escribir "No puede ser un triangulo"
    FinSi
FinAlgoritmo