# Programa en Python
# Funcion para crear una lista del tamaño que el usuario requiera. Al final muestra los valores ingresados.
# Funcion para sacar el promedio de la lista y mostrar el resultado.

def crear_lista(tam):
    lista = []
    for i in range(tam):
        lista.append(int(input("Ingrese un valor: ")))
    return lista

def promedio(lista):
    suma = 0
    for i in range(len(lista)):
        suma += lista[i]
    return suma / (0.0+len(lista))

# Programa Principal
tam = int(input("Ingrese el tamaño de la lista: "))
lista = crear_lista(tam)
print("Los valores ingresados fueron: ", lista)
print("El promedio de los valores es: ", promedio(lista))
