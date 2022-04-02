# Funciones
def llenar_lista(lista, n):
    """
    Funcion que llena una lista con numeros ingresados por el usuario
    """
    for i in range(n):
        lista.append(int(input("Ingrese un numero: ")))
    return lista

def mostrar_lista(lista):
    """
    Funcion que muestra los elementos de una lista
    """
    for i in range(len(lista)):
        print(lista[i])

def mostrar_elemento_repetido(lista):
    """
    Funcion que muestra el elemento repetido de una lista
    """
    elemento_repetido = 0
    for i in range(len(lista)):
        contador = 0
        for j in range(len(lista)):
            if lista[i] == lista[j]:
                contador += 1
        if contador > 1:
            elemento_repetido = lista[i]
    if elemento_repetido == 0:
        print("Todos los elementos son unicos en tu lista")
    else:
        print("El elemento repetido es: ", elemento_repetido)

# Programa Principal
lista = []
n = int(input("Ingrese la cantidad de elementos que desea ingresar: "))
llenar_lista(lista, n)
mostrar_lista(lista)
mostrar_elemento_repetido(lista)