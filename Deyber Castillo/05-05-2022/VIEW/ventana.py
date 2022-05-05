# tkinter
from re import X
import tkinter

# Clase obstaculo, un cuadro de color rojo que puede recibir una cordenada y un tamano
class Obstaculo:
    def __init__(self, x, y, tamano):
        self.x = x
        self.y = y
        self.tamano = tamano
        self.cuadro = tkinter.Canvas(width=tamano, height=tamano, bg="blue")
        self.cuadro.place(x=x, y=y)

class Agente:
    # Caricatura de un agente 
    def __init__(self, x, y, tamano):
        self.x = x
        self.y = y
        self.tamano = tamano
        self.cuadro = tkinter.Canvas(width=tamano, height=tamano, bg="pink")
        self.cuadro.place(x=x, y=y)


# Ventana
class Ventana(tkinter.Tk):

    # Atributos
    # Lista de obstaculos
    obstaculos = []
    agente = None    

    def __init__(self,x,y):
        super().__init__()
        self.title("Ventana de prueba")
        self.geometry(f"{x}x{y}")
        self.config(bg="red")

        # Agregar una linea roja vertical al 10 % de el ancho de la ventana
        self.linea_vertical = tkinter.Canvas(width=x, height=y, bg="green")
        self.linea_vertical.place(x=x*0.1, y=0)

        # Agregar una linea amarilla vertical al 90 % de el ancho de la ventana
        self.linea_vertical = tkinter.Canvas(width=x, height=y, bg="yellow")
        self.linea_vertical.place(x=x*0.9, y=0)
    
    # funcion que agrega un obstaculo a la ventana dentro de un cuadro de color verde
    def agregar_obstaculo(self, x, y, tamano):
        obstaculo = Obstaculo(x, y, tamano)
        self.obstaculos.append(obstaculo)

    # funcion que agrega un agente a la ventana dentro de un cuadro de color rojo
    def agregar_agente(self, x, y, tamano):
        self.agente = Agente((x/tamano), (y/2)-(tamano/2), tamano)  



# funcion que genera 


