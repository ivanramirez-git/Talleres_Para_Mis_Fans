"""Se tiene una lista de diccionarios, ordenada por la propiedad de anio. Escribe un programa que permita a un usuario buscar la propiedad de un elemento en la lista. Se debe
usar busqueda binaria para realizar la busqueda.
Algunos ejemplos de dialogo de este programa serian:
Listing 8: Ejemplo 1
lista = [
{ " nombre ": " Pedro Lopez " , " anio " :2000 , " nacimiento "
:1980 , " educacion ": " secundaria "} ,
{ " nombre ": " Maria Almenara " , " anio " :2003 , " nacimiento
" :1990 , " educacion ": " primaria "} ,
{ " nombre ": " Susana Distancia ", " anio " :2004 , "
nacimiento " :1970 , " educacion ": " universidad "} ,
{ " nombre ": " Elena Nito " , " anio " :2006 , " nacimiento "
:2003 , " educacion ": " secundaria "} ,
{ " nombre ": " Aquiles Bailollo ", " anio " :2007 , "
nacimiento " :2003 , " educacion ": " maestria "} ,
{ " nombre ": " Luis Califa " , " anio " :2008 , " nacimiento "
:2003 , " educacion ": " doctorado "}
]
Ingrese un anio para buscar : 2000
Ingrese la propiedad a buscar : nacimiento
nacimiento 1980
Listing 9: Ejemplo 2
lista = [
{ " nombre ": " Pedro Lopez " , " anio " :2000 , " nacimiento "
:1980 , " educacion ": " secundaria "} ,
{ " nombre ": " Maria Almenara " , " anio " :2003 , " nacimiento
" :1990 , " educacion ": " primaria "} ,
{ " nombre ": " Susana Distancia ", " anio " :2004 , "
nacimiento " :1970 , " educacion ": " universidad "} ,
{ " nombre ": " Elena Nito " , " anio " :2006 , " nacimiento "
:2003 , " educacion ": " secundaria "} ,
{ " nombre ": " Aquiles Bailollo ", " anio " :2007 , "
nacimiento " :2003 , " educacion ": " maestria "} ,
{ " nombre ": " Luis Califa " , " anio " :2008 , " nacimiento "
:2003 , " educacion ": " doctorado "}
]
Ingrese un anio para buscar : 2007
Ingrese la propiedad a buscar : nombre
nombre Aquiles Bailollo"""

def busquedaBinaria(lista, elemento, propiedad):
    # Si la lista esta vacia o el elemento no esta en la lista
    if len(lista) == 0 or elemento not in lista:
        return False
    # Si el elemento esta en la lista
    else:
        # Buscamos el elemento en la lista
        posicion = busquedaBinariaAux(lista, elemento, propiedad, 0, len(lista) - 1)
        # Si la posicion es -1, el elemento no esta en la lista
        if posicion == -1:
            return False
        # Si la posicion es mayor a -1, el elemento esta en la lista
        else:
            return True
