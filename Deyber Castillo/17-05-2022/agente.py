# tkinter
import tkinter as tk
import random, time

# ventana de 600x400
ventana = tk.Tk()
ventana.title("Agente")
ventana.geometry("600x400")
# fondo verde
ventana.config(bg="green")

# 9 cuadrados azules de 50x50
posiciones = [] # Posiciones de los enemigos
cuadrados = [] # Lista de los cuadrados enemigos
for i in range(9):
    x = random.randint(100, 450) # Posiciones aleatorias
    y = random.randint(0, 350) # Posiciones aleatorias 
    posiciones.append({'x': x, 'y': y}) # Agregar posiciones a la lista
    cuadrados.append(tk.Canvas(ventana, width=35, height=50, bg="blue")) # Crear los cuadrados
    # colocar texto dentro del cuadrado
    cuadrados[i].create_text(17, 25, text=i+1, font=("Arial", 20)) # Texto
    cuadrados[i].place(x=x, y=y) # Colocar los cuadrados en la ventana

# agente amarillo 35x35
# variables del agente
x = 0 # Posicion x
y = 0 # Posicion y
z = 0 # numero de choques
agente = tk.Canvas(ventana, width=35, height=35, bg="yellow") # Crear el agente
agente.create_text(17, 17, text="A", font=("Arial", 20)) # Texto
agente.place(x=x, y=y)  # ubicar el agente en la esquina superior izquierda

# tipo de choque:
derecha = False # Choque a la derecha
abajo = False # Choque abajo

while x < 565: # mientras no se salga de la ventana

    # Choque con un cuadrado en la derecha
    for i in range(9): # recorrer los cuadrados enemigos
        if x + 35 == posiciones[i]['x'] and (y + 35 >= posiciones[i]['y'] and y + 35 <= posiciones[i]['y'] + 50 + 35 or y == posiciones[i]['y'] and y <= posiciones[i]['y'] + 50 + 35):
            derecha = True # Choque a la derecha

    # Choque con un obstaculo abajo
    for j in range(9): # recorrer los cuadrados enemigos
        if y + 35 == posiciones[j]['y'] and (x + 35 >= posiciones[j]['x'] and x + 35 <= posiciones[j]['x'] + 50 or x == posiciones[j]['x'] and x <= posiciones[j]['x'] + 50):
            abajo = True # Choque abajo

    # Mover a la derecha
    if not derecha: # Si no hay choque a la derecha
        x += 1 # mover a la derecha un paso

    # Mover abajo
    if derecha and not abajo: # Si hay choque a la derecha y no hay choque abajo
        y += 1 # mover abajo un paso

    # Retroceder hasta que no choque abajo y a la derecha
    p = x # Posicion x
    s = y # Posicion y
    if derecha and abajo: # Si hay choque a la derecha y choque abajo
        while p - 50 != x:   
            x -= 1
            time.sleep(0.01)
            agente.place(x=x, y=y)
            ventana.update()
        while s + 50 != y:
            y += 1
            time.sleep(0.01)
            agente.place(x=x, y=y)
            ventana.update()

    time.sleep(0.01) # esperar una centesima de segundo
    agente.place(x=x, y=y)  # ubicar el agente en la nueva posicion
    ventana.update() # actualizar la ventana
    derecha = False # reiniciar el choque a la derecha
    abajo = False # reiniciar el choque abajo

# Mensaje de finalizacion
mensaje = tk.Label(ventana, text="Fin del juego", font=("Arial", 20))
mensaje.place(x=200, y=200)

# mainloop
ventana.mainloop()
