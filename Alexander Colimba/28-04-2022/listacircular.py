#Programa que gestiona una lista circular de enteros
class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.sig = None
        
class ListaCircular:
    def __init__(self):
        self.primero = None
        self.tam = 0
        
    def ingresar(self, dato):
        nodo = Nodo(dato)
        if self.primero is None:
            self.primero = nodo
            self.primero.sig = self.primero
        else:
            aux = self.primero
            while aux.sig is not self.primero:
                aux = aux.sig
            aux.sig = nodo
            nodo.sig = self.primero
        self.tam += 1
        
    def borrar(self, dato):
        if self.primero is None:
            print("No hay elementos en la lista")
        else:
            if self.primero.dato == dato:
                if self.primero.sig is self.primero:
                    self.primero = None
                else:
                    aux = self.primero
                    while aux.sig is not self.primero:
                        aux = aux.sig
                    aux.sig = self.primero.sig
                    self.primero = self.primero.sig
                self.tam -= 1
            else:
                aux = self.primero
                while aux.sig is not self.primero:
                    if aux.sig.dato == dato:
                        if aux.sig.sig is self.primero:
                            aux.sig = self.primero
                        else:
                            aux.sig = aux.sig.sig
                        self.tam -= 1
                        break
                    else:
                        aux = aux.sig
                        
    def ordenar(self):
        if self.primero is None:
            print("No hay elementos en la lista")
        else:
            if self.primero.sig is self.primero:
                print("La lista ya esta ordenada")
            else:
                aux = self.primero
                while aux.sig is not self.primero:
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
                aux = self.primero
                while aux.sig is not self.primero:
                    if aux.dato == dato:
                        return 1
                    else:
                        aux = aux.sig
                return -1

    def imprimir(self):
        if self.primero is None:
            print("No hay elementos en la lista")
        else:
            aux = self.primero
            while aux is not self.primero:
                print(aux.dato, end=" ")
                aux = aux.sig
            print(aux.dato)


# Programa principal
def menu_circular():
    lista = ListaCircular()
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
            if lista.buscar(dato) == -1:
                print("No se encontro el dato")
            else:
                print("Se encontro el dato")
        elif opcion == 5:
            break
        else:
            print("Opcion incorrecta")
