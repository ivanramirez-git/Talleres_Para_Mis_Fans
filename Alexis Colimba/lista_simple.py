class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.sig = None

    def __str__(self):
        return str(self.dato)

    def __repr__(self):
        return str(self.dato)


class Lista:
    def __init__(self):
        self.primero = None
        self.ultimo = None
        self.tam = 0

    def agregar(self, dato):
        nuevo = Nodo(dato)
        if self.primero == None:
            self.primero = nuevo
            self.ultimo = nuevo
        else:
            self.ultimo.sig = nuevo
            self.ultimo = nuevo
        self.tam += 1

    def agregar_ordenado(self, dato):
        nuevo = Nodo(dato)
        if self.primero == None:
            self.primero = nuevo
            self.ultimo = nuevo
        else:
            if nuevo.dato < self.primero.dato:
                nuevo.sig = self.primero
                self.primero = nuevo
            else:
                aux = self.primero
                while aux.sig != None and aux.sig.dato < nuevo.dato:
                    aux = aux.sig
                nuevo.sig = aux.sig
                aux.sig = nuevo
        self.tam += 1

    def listar(self):
        aux = self.primero
        print("[ ", end="")
        while aux != None:
            print(aux.dato, end="")
            aux = aux.sig
            if aux != None:
                print(",", end=" ")
        print(" ]")

    def eliminar(self, dato):
        aux = self.primero
        while aux != None and aux.dato != dato:
            aux = aux.sig
        if aux != None:
            if aux == self.primero:
                self.primero = aux.sig
            else:
                aux2 = self.primero
                while aux2.sig != aux:
                    aux2 = aux2.sig
                aux2.sig = aux.sig
            self.tam -= 1

    def mayor(self):
        if self.primero != None:
            aux = self.primero
            mayor = aux.dato
            while aux != None:
                if aux.dato > mayor:
                    mayor = aux.dato
                aux = aux.sig
            return mayor
        else:
            return None

    def promedio(self):
        if self.primero != None:
            aux = self.primero
            suma = 0
            while aux != None:
                suma += aux.dato
                aux = aux.sig
            return suma / self.tam
        else:
            return None

    def buscar(self, dato):
        aux = self.primero
        while aux != None and aux.dato != dato:
            aux = aux.sig
        return aux
