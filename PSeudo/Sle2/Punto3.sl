
// Punto 3
var
	N,contador : numerico
	A : vector[10] numerico
	B : vector[9] numerico
inicio
    cls()
    // Cuantos datos tiene el vector de pares
    //imprimir("Ingrese la cantidad de datos que tendra el vector:")
    //leer(N)
		 
	N=10
    // Crear el vector de pares
    
    // Pedir datos del vector
    contador=1
    mientras(contador<=N){
        imprimir("\nIngrese el dato ",contador,":")
        leer(A[contador])
        contador=contador+1
    }
    // Enviar vector a la funcion
    imprimir("Resultado: ",vectorPares(A,N))
fin

subrutina vectorPares(A:vector[10]numerico;N:numerico) retorna vector[9] numerico
    var
        contador:numerico
        resultado:cadena
        respuestas: vector[9] numerico
	inicio
    // Comparar parejas consecutivas y escribir en vector respuestas 0 si el primer caracter es mayor o 1 si el segundo es mayor
    contador=1
    mientras(contador<=N-1){
        si(A[contador]>A[contador+1]){
            respuestas[contador]=0
        }
        si(A[contador]<A[contador+1]){
            respuestas[contador]=1
        }
        contador=contador+1
    }
    retorna respuestas
fin
