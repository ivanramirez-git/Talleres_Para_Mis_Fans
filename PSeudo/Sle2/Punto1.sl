

// Punto 1
var
	contador,aux,cont:numerico
	 A : vector [15] numerico
inicio
	cls()
	
	contador=1
	mientras(contador<=15){
		A[contador]=random(100)
		contador=contador+1
	}

    imprimir("Vector de  aleatorios:")
    imprimir("\n")

    contador=1
    mientras(contador<=15){
        imprimir("\n",A[contador])
        contador=contador+1			
    }

    // Ordenar de forma ascendente

    contador=1
    cont=1
    mientras(contador<15){
        mientras(cont<15){
            si(A[cont]>A[cont+1]){
                aux=A[cont]
                A[cont]=A[cont+1]
                A[cont+1]=aux
            }
            cont=cont+1
        }
        contador=contador+1
        cont=contador
    }

    imprimir("\nVector ordenado de forma ascendente:")
    imprimir("\n")

    contador=1
    mientras(contador<=15){
        imprimir("\n",A[contador])
        contador=contador+1			
    }

    
fin
