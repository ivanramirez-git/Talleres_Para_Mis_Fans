# tkinter
import random
# from re import X
import tkinter, time
from tkinter import messagebox

# Clase obstaculo, un cuadro de color azul que puede recibir una cordenada y un tamano
class Obstaculo:
    # Atributos
    x = 0
    y = 0
    tamano = 0

    def __init__(self, x, y, tamano):
        self.x = x
        self.y = y
        self.tamano = tamano
        self.cuadro = tkinter.Canvas(width=tamano, height=tamano, bg="blue")
        self.cuadro.place(x=x, y=y)

# Clase Agente, un cuadro de color rosa que puede recibir una cordenada y un tamano
class Agente:

    # Atributos
    x = 0 # posicion en horizontal del agente
    y = 0 # posicion en vertical del agente
    tamano = 0 # tamano del agente

    # Caricatura de un agente 
    def __init__(self, x, y, tamano):
        self.x = x # guardar la posicion en horizontal
        self.y = y # guardar la posicion en vertical
        self.tamano = tamano # guardar el tamano del agente
        self.cuadro = tkinter.Canvas(width=tamano, height=tamano, bg="pink") # crear el cuadro de color rosa
        self.cuadro.place(x=x, y=y) # Clase ventana, la ventana principal

    # Mover el agente
    def mover(self, x, y):
        self.cuadro.place(x=x, y=y) # mover el cuadro a la nueva posicion
        self.x = x # guardar la nueva posicion en horizontal
        self.y = y # guardar la nueva posicion en vertical

# Ventana
class Ventana(tkinter.Tk):

    # Atributos
    # Lista de obstaculos
    obstaculos = []
    agente = None  
    coutChoques = 0
    x = 0 # Tamanio de la ventana en horizontal
    y = 0 # Tamanio de la ventana en vertical

    # Constructor
    def __init__(self,x,y):
        super().__init__()
        # Titulo
        self.title("Ventana de prueba")
        # Definimos el tamanio de la ventana
        self.geometry(f"{x}x{y}")
        # Definimos el color de fondo
        self.config(bg="red")

        # Agregar una linea verde vertical al 10 % de el ancho de la ventana
        self.linea_vertical = tkinter.Canvas(width=x, height=y, bg="green")
        self.linea_vertical.place(x=x*0.1, y=0) # desde el 10% al final en horizontal, y desde 0 hasta el final en vertical, se pinta de verde

        # Agregar una linea amarilla vertical al 90 % de el ancho de la ventana
        self.linea_vertical = tkinter.Canvas(width=x, height=y, bg="yellow")
        self.linea_vertical.place(x=x*0.9, y=0) # desde el 90% al final en horizontal, y desde 0 hasta el final en vertical, se pinta de amarillo

        # X,Y de la ventana
        self.x = x
        self.y = y
    
    # funcion que agrega un obstaculo a la ventana dentro de un cuadro de color verde
    def agregar_obstaculo(self, x, y, tamano):
        obstaculo = Obstaculo(x, y, tamano) # se crea el obstaculo
        self.obstaculos.append(obstaculo) # agregar un obstaculo a la lista de obstaculos

    # funcion que agrega un agente a la ventana dentro de un cuadro de color rojo
    def agregar_agente(self, x, y, tamano):
        self.agente = Agente((x/tamano), (y/2)-(tamano/2), tamano)  
            
    # funcion que evalua si el agente choca con la linea de arriba
    def choca_con_linea_arriba(self):
        if self.agente.y <= 0:
            return True
        return False

    # funcion que evalua si el agente choca con la linea de abajo
    def choca_con_linea_abajo(self):
        if self.agente.y+ self.agente.tamano >= self.winfo_height():
            return True
        return False

    # funcion que evalua si el agente choca con la linea de la izquierda
    def choca_con_linea_izquierda(self):
        if self.agente.x <= 0:
            return True
        return False

    # funcion que evalua si el agente choca con la linea de la derecha, Funcion Que nos dice si Logro Ganar o Perder
    def choca_con_linea_derecha(self):
        if self.agente.x+ self.agente.tamano >= self.winfo_width():
            return True
        return False

        # funcion que evalua si el agente choca con un obstaculo
    def choca_con_obstaculo(self):
        for obstaculo in self.obstaculos:
            if self.agente.x >= obstaculo.x and self.agente.x <= obstaculo.x+obstaculo.tamano and self.agente.y >= obstaculo.y and self.agente.y <= obstaculo.y+obstaculo.tamano:
                return True
            if self.agente.x+self.agente.tamano >= obstaculo.x and self.agente.x+self.agente.tamano <= obstaculo.x+obstaculo.tamano and self.agente.y >= obstaculo.y and self.agente.y <= obstaculo.y+obstaculo.tamano:
                return True
            if self.agente.x >= obstaculo.x and self.agente.x <= obstaculo.x+obstaculo.tamano and self.agente.y+self.agente.tamano >= obstaculo.y and self.agente.y+self.agente.tamano <= obstaculo.y+obstaculo.tamano:
                return True
            if self.agente.x+self.agente.tamano >= obstaculo.x and self.agente.x+self.agente.tamano <= obstaculo.x+obstaculo.tamano and self.agente.y+self.agente.tamano >= obstaculo.y and self.agente.y+self.agente.tamano <= obstaculo.y+obstaculo.tamano:
                return True

        return False

    # funcion que evalua si el agente choca con algun obstaculo o con la linea
    def choca_con_linea_o_obstaculo(self):
        if self.choca_con_obstaculo() or self.choca_con_linea_arriba() or self.choca_con_linea_abajo() or self.choca_con_linea_izquierda():
            return True
        return False

    # funcion que mueve el agente a la posicion x,y en t cantidad de tiempo, t en segundos
    def mover_agente(self, x, y, t):
        # Convertir t en segundos
        t = t*100

        # x_0 posicion inicial en horizontal
        x_0 = self.agente.x
        # y_0 posicion inicial en vertical
        y_0 = self.agente.y    
        
        self.agente.mover(x_0, y_0)  # mover el agente a la posicion inicial
        self.update() # actualizar la ventana
    
        # Ciclo hasta que se choque con la linea final o con un obstaculo
        while True:
            if self.choca_con_linea_o_obstaculo():
                print("Choque ", self.coutChoques)
                return False
                
            if self.choca_con_linea_derecha():
                print("Victoria")
                return True
                
            # Movimiento del agente
            self.agente.mover(x_0, y_0)
            if x != 0 and y != 0:
                x_0 += x/t
                y_0 += y/t           
            if x == 0:
                y_0 += y/t
            if y == 0:
                x_0 += x/t
            self.update()
            if x_0 >= x:
                break
            if y_0 <= y:
                break
            # aumenta una centecima de segundo
            time.sleep(0.001)

    # funcion que retrocede el agente en 0.5 segundos 10 pixeles
    def retroceder_agente(self):
        # Tiempo de retroceso 0.5 segundos
        t = 50
        # Posicion inicial en horizontal
        x_0 = self.agente.x
        # Posicion final en horizontal, 10 pixeles atras de la posicion inicial
        x_1 = self.agente.x - 10

        while True:
            # Se mueve en horizontal, en y se queda quieto
            self.agente.mover(x_0, self.agente.y)
            # Actualiza la ventana
            self.update()
            # Retrocede un paso
            x_0 -= 10/t
            # Espera 1 centecimo de segundo
            time.sleep(0.001)
            # Si x_0 llega a donde esta x_1, se termina el ciclo     
            if x_0 <= x_1:
                break

    # funcion que sube o baja el agente en 1 segundos y pixeles
    def subir_bajar_agente(self, y):
        t = 100
        y_0 = self.agente.y
        y_1 = self.agente.y + y

        while True:

            # Si choca retrocede
            if self.choca_con_linea_o_obstaculo():
                self.retroceder_agente()
            else:                
                self.agente.mover(self.agente.x, y_0)
                self.update()
                y_0 += y/t
                time.sleep(0.001)
                
                # Si baja y llega a donde esta y_1, se termina el ciclo
                if y > 0:                
                    if y_0 >= y_1:
                        break  
                # Si sube y llega a donde esta y_1, se termina el ciclo
                else:
                    if y_0 <= y_1:
                        break

    # iniciar
    def iniciar(self):
        # Ciclo de ejecucion hasta llegar a la meta o hasta que el agente choca con un obstaculo 5 veces
        while True:
            # Esperar 1 segundo
            time.sleep(1)

            # Si choca 5 veces, terminar
            if self.coutChoques == 5:
                # Enviar mensaje emergente
                messagebox.showinfo("Fin del juego", "El agente choco 5 veces")
                break

            # Mover al final en 10 segundos
            if self.mover_agente(self.x, 0, 10):
                # Enviar mensaje emergente
                messagebox.showinfo("Fin del juego", "El agente llego a la meta")
                break
            else:
                # devolver el agente 10 pixeles atras
                self.retroceder_agente()

                # Subir o bajar 2 veces el tamano del agente
                yTamano = 0
                rand = random.randint(0, 1) # Escoge un numero aleatorio entre 0 y 1, para saber si sube o baja
                if rand == 0:
                    yTamano += self.agente.tamano * 2
                else:
                    yTamano -= self.agente.tamano * 2    

                self.subir_bajar_agente(yTamano)

                # Incrementar contador de choques
                self.coutChoques += 1