#Programa que gestiona una lista simple de enteros
class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.sig = None


class ListaSimple:
    def __init__(self):
        self.primero = None
        self.tam = 0

    def ingresar(self, dato):
        nodo = Nodo(dato)
        if self.primero is None:
            self.primero = nodo
        else:
            aux = self.primero
            while aux.sig is not None:
                aux = aux.sig
            aux.sig = nodo
        self.tam += 1

    def borrar(self, dato):
        if self.primero is None:
            print("No hay elementos en la lista")
        else:
            if self.primero.dato == dato:
                self.primero = self.primero.sig
                self.tam -= 1
            else:
                aux = self.primero
                while aux.sig is not None:
                    if aux.sig.dato == dato:
                        aux.sig = aux.sig.sig
                        self.tam -= 1
                        break
                    else:
                        aux = aux.sig

    def ordenar(self):
        if self.primero is None:
            print("No hay elementos en la lista")
        else:
            if self.primero.sig is None:
                print("La lista ya esta ordenada")
            else:
                aux = self.primero
                while aux.sig is not None:
                    if aux.dato > aux.sig.dato:
                        aux.dato, aux.sig.dato = aux.sig.dato, aux.dato
                    aux = aux.sig

    def buscar(self, dato):
        if self.primero is None:
            print("No hay elementos en la lista")
        else:
            if self.primero.dato == dato:
                return 0
            else:
                pos = 0
                aux = self.primero
                while aux is not None:
                    if aux.dato == dato:
                        return pos
                    else:
                        aux = aux.sig
                        pos += 1
                return -1

    def imprimir(self):
        if self.primero is None:
            print("No hay elementos en la lista")
        else:
            aux = self.primero
            while aux is not None:
                print(aux.dato)
                aux = aux.sig

# Programa principal
def menu_simple():
    lista = ListaSimple()
    while True:
        print("1 ingresar")
        print("2 borrar")
        print("3 ordenar")
        print("4 buscar")
        print("5 salir")
        opcion = int(input("Ingrese una opcion: "))
        if opcion == 1:
            dato = int(input("Ingrese un dato: "))
            lista.ingresar(dato)
            lista.imprimir()
        elif opcion == 2:
            dato = int(input("Ingrese un dato: "))
            lista.borrar(dato)
            lista.imprimir()
        elif opcion == 3:
            lista.ordenar()
            lista.imprimir()
        elif opcion == 4:
            dato = int(input("Ingrese un dato: "))
            pos = lista.buscar(dato)
            if pos == -1:
                print("No se encontro el dato")
            else:
                print("El dato fue encontrado en la posicion", pos)
        elif opcion == 5:
            break
