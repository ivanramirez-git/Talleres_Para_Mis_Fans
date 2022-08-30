# importar lista_simple
from lista_simple import Lista

# Menu de opciones
def menu():
    print("1. Agregar")
    print("2. Listar")
    print("3. Eliminar")
    print("4. Buscar")
    print("5. Mayor")
    print("6. Promedio")
    print("0. Salir")
    opcion = int(input("Ingrese una opcion: "))
    return opcion


# Ejecucion del programa
lista = Lista()
print("Bienvenido a la lista simple")
while True:
    opcion = menu()
    if opcion == 1:
        dato = int(input("Ingrese un dato: "))
        lista.agregar(dato)
    elif opcion == 2:
        lista.listar()
    elif opcion == 3:
        dato = int(input("Ingrese un dato: "))
        lista.eliminar(dato)
    elif opcion == 4:
        dato = int(input("Ingrese un dato: "))
        print(lista.buscar(dato))
    elif opcion == 5:
        print(lista.mayor())
    elif opcion == 6:
        print(lista.promedio())
    elif opcion == 0:
        break
    else:
        print("Opcion no valida")
print("Fin del programa")
