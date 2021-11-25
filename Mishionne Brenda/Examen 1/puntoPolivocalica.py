#Funcion que retorna un valor lógico que indica si una palabra es o no polivocálica.
def polivocal(palabra):
    vocales = ['a','e','i','o','u']
    vocales_encontradas = []
    for letra in palabra:
        if letra in vocales:
            vocales_encontradas.append(letra)
    if len(vocales_encontradas) == 5:
        return True
    else:
        return False

#Funcion que lee una frase con palabras separadas con un espacio en blanco y determine cuántas palabras polivocálicas contiene.
def polivocal_frase(frase):
    palabras = frase.split()
    cantidad_polivocales = 0
    for palabra in palabras:
        if polivocal(palabra):
            cantidad_polivocales += 1
    return cantidad_polivocales

# Programa Principal
frase = input("Ingrese un texto: ")
print("Cantidad de palabras polivocálicas: ", polivocal_frase(frase))