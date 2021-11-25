#Escriba un programa que lea un mensaje y calcule su costo.
mensaje = input("Ingrese un mensaje: ")

#Se crea una lista con los caracteres que son letras mayúsculas
caracteres_letras_mayusculas = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']

#Se crea una lista con los caracteres que son dígitos
caracteres_digitos = ['0','1','2','3','4','5','6','7','8','9']

#Se crea una lista con los caracteres que son letras minúsculas
caracteres_letras_minusculas = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

#Calculo del costo del mensaje
costo_mensaje = 0
for caracter in mensaje:
    if caracter in caracteres_letras_mayusculas:
        costo_mensaje += 13
    elif caracter in caracteres_letras_minusculas:
        costo_mensaje += 8.5
    elif caracter in caracteres_digitos:
        costo_mensaje += 18
    elif caracter == ' ':
        costo_mensaje += 0
    else:
        costo_mensaje += 20

#Se muestra el costo del mensaje
print("El costo del mensaje es: $", costo_mensaje)

