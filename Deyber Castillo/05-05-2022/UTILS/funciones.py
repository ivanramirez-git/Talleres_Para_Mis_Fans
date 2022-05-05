import random

# funcion que retorna un numero aleatorio entre dos numeros
def numero_aleatorio(minimo, maximo):
    return random.randint(minimo, maximo)

# funcion que genera una lista de posiciones aleatorias
def generar_posiciones(x, y, tamano, numero_obstaculos):
    posiciones = []
    # no pueden haber mas de dos obstaculos a una distancia euclidiana de menos de ((x+y)/10) + (tamano*2)
    while len(posiciones) < numero_obstaculos:
        x_aleatorio = numero_aleatorio(0+tamano+(x/10), x-tamano-(x/10))
        y_aleatorio = numero_aleatorio(0+tamano, y-tamano)
        # si la distancia euclidiana entre dos obstaculos es mayor a ((x+y)/10) + (tamano*2)
        if len(posiciones) > 0:
            distancia_minima = ((x+y)/10) + (tamano*2)
            distancia_actual = ((x_aleatorio-posiciones[0][0])**2 + (y_aleatorio-posiciones[0][1])**2)**0.5
            if distancia_actual > distancia_minima:
                posiciones.append([x_aleatorio, y_aleatorio])
        else:
            posiciones.append([x_aleatorio, y_aleatorio])
    return posiciones
