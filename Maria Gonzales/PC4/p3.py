"""
diccionario = { 
    " El despertar " :100000 ,
    " Todo lo que sube tiene que bajar " : 133 ,
    " Problemas en el paraiso " : 500323,
    " Hasta cuando ? " : 134554,
    " En el circo " : 2455 ,
    " La casa roja " : 44444 ,
    " Navidad azul " : 567121 ,
    " Pequenos accidentes , grandes problemas " : 2000000 ,
    " La familia de ariba " : 76
}
"""

def ordenarValorBurbuja(diccionario):
    lista = []
    respuesta = {}
    # Recorrremos cada atributo del diccionario
    for key in diccionario:
        # Agregamos el valor del atributo a la lista
        lista.append({key: diccionario[key]})
    # Ordenamos la lista
    for i in range(len(lista)):
        for j in range(len(lista)-1):
            if lista[j][lista[j].keys()[0]] > lista[j+1][lista[j+1].keys()[0]]:
                lista[j], lista[j+1] = lista[j+1], lista[j]
    # Agregamos los elementos de la lista al diccionario como clave y valor
    for i in range(len(lista)):
        respuesta[lista[i].keys()[0]] = lista[i].values()[0]
    return respuesta
    
diccionario = { 
    " El despertar " :100000 ,
    " Todo lo que sube tiene que bajar " : 133 ,
    " Problemas en el paraiso " : 500323,
    " Hasta cuando ? " : 134554,
    " En el circo " : 2455 ,
    " La casa roja " : 44444 ,
    " Navidad azul " : 567121 ,
    " Pequenos accidentes , grandes problemas " : 2000000 ,
    " La familia de ariba " : 76
}


print(ordenarValorBurbuja(diccionario))

