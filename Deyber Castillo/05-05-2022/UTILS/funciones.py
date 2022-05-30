import random

# funcion que retorna un numero aleatorio entre dos numeros
def numero_aleatorio(minimo, maximo):
    return random.randint(minimo, maximo)

# funcion que genera una lista de posiciones aleatorias
def generar_posiciones(x, y, tamano, numero_obstaculos):
    posiciones = []
    # no pueden haber mas de dos obstaculos a una distancia euclidiana de menos de ((x+y)/10) + (tamano*2)
    while len(posiciones) < numero_obstaculos:
        x_aleatorio = numero_aleatorio(tamano+(x/10), x-tamano-(x/10))
        y_aleatorio = numero_aleatorio(tamano, y-tamano)
        posiciones.append([x_aleatorio, y_aleatorio])
    return posiciones
