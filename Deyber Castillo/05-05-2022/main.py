# Importar la vista ventana
from VIEW import ventana
from UTILS import funciones

# tamanio de la ventana
x = 700
y = 400

# numero de obstaculos
numero_obstaculos = 9

# tamanio de los obstaculos
tamano_obstaculos = min(x,y) // numero_obstaculos

# lista de posiciones de los obstaculos
posiciones_obstaculos = funciones.generar_posiciones(x, y, tamano_obstaculos, numero_obstaculos)

# Ventana principal
ventana = ventana.Ventana(x, y)


# 9 obstaculos de 50x50 aleatorios
for posicion in posiciones_obstaculos:
    ventana.agregar_obstaculo(posicion[0], posicion[1], tamano_obstaculos)

# agente
ventana.agregar_agente(x, y, tamano_obstaculos)


ventana.mainloop()