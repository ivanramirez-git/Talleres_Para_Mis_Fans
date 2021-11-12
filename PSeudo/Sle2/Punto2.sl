
// Punto 2
// Escribir un programa que lea dos cadena de caracteres y contar cuantas veces aparece la primera en la segunda

var
    cadena1,cadena2,aux:cadena
    cont,contador:numerico
inicio
    cls()
    imprimir("Ingrese la primera cadena:")
    leer(cadena1)
    imprimir("\nIngrese la segunda cadena:")
    leer(cadena2)
    contador=1
    cont=1
    mientras(contador<=strlen(cadena2)){
        aux=substr(cadena2,contador,strlen(cadena1))
        si(aux==cadena1){
            cont=cont+1
        }
        contador=contador+1
    }
    imprimir("\nLa cadena ",cadena1," aparece ",cont-1," veces en la cadena ",cadena2)
fin
