# Importar la vista ventana
from VIEW import ventana
from UTILS import funciones

# tamanio de la ventana
x = 700
y = 400

# numero de obstaculos
numero_obstaculos = 9 # minimo 4 

# tamanio de los obstaculos
tamano_obstaculos = min(x,y) // numero_obstaculos

# lista de posiciones de los obstaculos
# posiciones_obstaculos = 
# [
#    [x1, y1],
#    [x2, y2],
#    [x3, y3],
#    [x4, y4],
#    ...
#    [x9, y9]
# ]
posiciones_obstaculos = funciones.generar_posiciones(x, y, tamano_obstaculos, numero_obstaculos) # Lista de posiciones de los obstaculos
# p2 = [
#     [150, 50],
#     [200, 150],
#     [250, 250],
#     [300, 350],
#     [350, 250],
#     [400, 150],
#     [450, 50],
#     [500, 80],
#     [550, 290]
# ]


# Ventana principal
v = ventana.Ventana(x, y)

# 9 obstaculos de 50x50 aleatorios
for posicion in posiciones_obstaculos:
    v.agregar_obstaculo(posicion[0], posicion[1], tamano_obstaculos)

# agente
v.agregar_agente(x, y, tamano_obstaculos)

# mover agente
v.iniciar()

# mostrar ventana
v.mainloop()