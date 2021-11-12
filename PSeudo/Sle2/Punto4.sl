
// Punto 4
// Dado un vector de enteros imprimir el primer elemento repetido
var
    contador,aux,cont:numerico
    A : vector [15] numerico
inicio
    cls()
    // Crear el vector de pares
    contador=1
    mientras(contador<=15){
        A[contador]=random(10)
        contador=contador+1
    }

    // Imprimir el vector
    imprimir("Vector de  aleatorios:",A)
    imprimir("\n")


    // Enviar vector a la funcion
    imprimir("El primer elemento repetido es: ",primerElementoRepetido(A,15))
fin

subrutina primerElementoRepetido(A:vector[15]numerico;N:numerico) retorna numerico
    var
        contador,aux,cont:numerico
        respuesta:numerico
    inicio
    // Comparar parejas consecutivas y escribir en vector respuestas 0 si el primer caracter es mayor o 1 si el segundo es mayor
    contador=1
    mientras(contador<=N-1){
        si(A[contador]==A[contador+1]){
            respuesta=A[contador]
            cont=contador
        }
        contador=contador+1
    }
    retorna respuesta
fin
