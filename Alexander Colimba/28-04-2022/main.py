# Listas simple, enlazadas, circular
import listasimple
import listacircular
import listaenlazada

# Menu principal
def menu_principal():
    while True:        
        print("1 listas simple")
        print("2 listas circular")
        print("3 listas enlazadas")
        print("4 salir")
        opcion = int(input("Ingrese una opcion: "))
        if opcion == 1:
            listasimple.menu_simple()
        elif opcion == 2:
            listacircular.menu_circular()
        elif opcion == 3:
            listaenlazada.menu_enlazada()
        elif opcion == 4:
            print("Saliendo...")
            exit()
        else:
            print("Opcion incorrecta")


# Programa principal
menu_principal()
