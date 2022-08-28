# importar lista_simple
from lista_simple import Lista, Nodo

# Elabore un metodo que reciba la direccion del primer noto y un dato, borre de la lista todos los datos iguales a dato.
def eliminar_todos(nodo, dato):
    if nodo != None:
        if nodo.dato == dato:
            if nodo.sig != None:
                nodo.dato = nodo.sig.dato
                if nodo.sig.sig != None:
                    nodo.sig = nodo.sig.sig
                else:
                    nodo.sig = None
            else:
                nodo = None

    while nodo != None:
        if nodo.dato == dato:
            nodo = nodo.sig
        else:
            if nodo.sig != None and nodo.sig.dato == dato:
                nodo.sig = nodo.sig.sig
            else:
                nodo = nodo.sig


# Elabore metodo que reciba un numero y elabore una lista con todos los digitos de ese numero.
def listar_digitos(numero):
    lista = Lista()
    inverso = 0
    while numero > 0:
        inverso = inverso * 10 + numero % 10
        numero = numero // 10
    while inverso > 0:
        lista.agregar(inverso % 10)
        inverso = inverso // 10
    return lista


# Menu de opciones
def menu():
    print("1 ingresar datos")
    print("2 imprimir lista")
    print("3 eliminar datos repetidos")
    print("4 crear lista con un número entero")
    print("0 salir")
    opcion = int(input("Ingrese una opcion: "))
    return opcion


# Ejecucion del programa
lista = Lista()
print("Bienvenido a la lista simple")
while True:
    opcion = menu()
    if opcion == 1:
        dato = int(input("Ingrese un dato: "))
        lista.agregar_ordenado(dato)
    elif opcion == 2:
        lista.listar()
    elif opcion == 3:
        dato = int(input("Ingrese un dato: "))
        eliminar_todos(lista.primero, dato)
    elif opcion == 4:
        numero = int(input("Ingrese un numero: "))
        lista = listar_digitos(numero)
    elif opcion == 0:
        break
    else:
        print("Opcion no valida")
print("Gracias por usar el programa")
