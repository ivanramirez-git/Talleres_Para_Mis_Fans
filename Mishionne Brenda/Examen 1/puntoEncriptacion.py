# Funcion que recibe una frase y devuelve una palabra encriptada
def encriptar(frase):
    # Pasar la palabra a minúsculas
    frase = frase.lower()
    # Encriptar la frase
    encriptada = ""
    for caracter in frase:
        if caracter == "a":
            encriptada += "*"
        elif caracter == "e":
            encriptada += "-"
        elif caracter == "i":
            encriptada += "?"
        elif caracter == "o":
            encriptada += "#"
        elif caracter == "u":
            encriptada += "&"
        elif caracter in "bcdfghjklmnpqrstvwxyz0123456789":
            encriptada += "$"
        else:
            encriptada += caracter
    return encriptada

# Programa Principal
frase = input("Ingrese un texto: ")
print("Mensaje encriptado: ", encriptar(frase))
