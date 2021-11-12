

// Punto 5
// Leer una matriz de AxB elementos, de numeros enteros introducidos por teclado.
// Calcular e imprimir "Filas magicas" si la suma de los elementos de todas las filas es igual.
// Calcular e imprimir "Columnas magicas" si la suma de los elementos de todas las columnas es igual.

var
    A : matriz [*,*] numerico
    B : vector [*] numerico
    n : numerico
    contador,cont,contador2,contador1,aux:numerico
    sumaFila,sumaColumna:numerico
    sumaFilaAux,sumaColumnaAux:numerico
inicio
    cls()
    // Cuantas filas y columnas tiene la matriz
    imprimir("Ingrese la cantidad de filas o columnas:")
    leer(n)

    // Dimensionar la matriz y vector auxiliar
    dim (A,n,n)
    dim (B,n)

    // Pedir datos de la matriz
    contador=1
    mientras(contador<=n){
        contador1=1
        mientras(contador1<=n){
            imprimir("\nIngrese el dato ",contador,",",contador1,":")
            leer(A[contador,contador1])
            contador1=contador1+1
        }
        contador=contador+1
    }

    // Imprimir matriz de forma cuadrada
    imprimir("Matriz:\n")
    contador=1
    mientras(contador<=n){
        contador1=1
        mientras(contador1<=n){
            imprimir(A[contador,contador1]," ")
            contador1=contador1+1
        }
        imprimir("\n")
        contador=contador+1
    }

    // Guardar sumas de cada fila en B
    contador=1
    mientras(contador<=n){
        sumaFila=0
        contador1=1
        mientras(contador1<=n){
            sumaFila=sumaFila+A[contador,contador1]
            contador1=contador1+1
        }
        B[contador]=sumaFila
        contador=contador+1
    }

    // Validar que todos los elementos de B son iguales
    contador=1
    mientras(contador<=n){
        si(B[contador]<>B[1]){
            imprimir("\nNo es una matriz con filas magicas")
            contador=n+1
        }
        contador=contador+1
        si(contador==n && B[contador]==B[1]){
            imprimir("\nEs una matriz con filas magicas")
        }
    }

    // Guardar sumas de cada columna en B
    contador=1
    mientras(contador<=n){
        sumaColumna=0
        contador1=1
        mientras(contador1<=n){
            sumaColumna=sumaColumna+A[contador1,contador]
            contador1=contador1+1
        }
        B[contador]=sumaColumna
        contador=contador+1
    }

    // Validar que todos los elementos de B son iguales
    contador=1
    mientras(contador<=n){
        si(B[contador]<>B[1]){
            imprimir("\nNo es una matriz con columnas magicas")
            contador=n+1
        }
        contador=contador+1
        si(contador==n && B[contador]==B[1]){
            imprimir("\nEs una matriz con columnas magicas")
        }
    }

fin
