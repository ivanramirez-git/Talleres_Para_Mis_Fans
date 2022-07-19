
"""
Tabla 1:
0 : Buena Vista
1 : Colon
2 : El Carmen
3 : Las Palmas
4 : Naranjo
5 : Rancho
6 : San Jorge
7 : Victoria

Tabla 2:
Origen      Destino         Costo Actual
El Carmen   Buena Vista     500
El Carmen   Colon           1000
El Carmen   Las Palmas      1500
El Carmen   Naranjo         300
El Carmen   Rancho          100
El Carmen   San Jorge       600
El Carmen   Victoria        600

Distancias (millas):
    0   1   2   3   4   5   6   7
0   0   22  48  0   0   0   15  0
1   22  0   0   45  0   0   0   0
2   48  0   0   0   0   5   60  0
3   0   45  0   0   0   0   60  45
4   0   0   0   0   0   30  30  20
5   0   0   5   0   30  0   0   0
6   15  0   60  60  30  0   0   0
7   0   0   0   45  20  0   0   0
"""
# Funciones utiles


def imprimir_tabla(matriz):
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            print(matriz[i][j], end=" ")
        print()


def millastokm(millas):
    return millas * 1.60934


# tabla 1
tabla1 = ['Buena Vista', 'Colon', 'El Carmen', 'Las Palmas',
          'Naranjo', 'Rancho', 'San Jorge', 'Victoria']
# tabla 2
tabla2 = [
    {'Origen': 'El Carmen', 'Destino': 'Buena Vista', 'Costo Actual': 500},
    {'Origen': 'El Carmen', 'Destino': 'Colon', 'Costo Actual': 1000},
    {'Origen': 'El Carmen', 'Destino': 'Las Palmas', 'Costo Actual': 1500},
    {'Origen': 'El Carmen', 'Destino': 'Naranjo', 'Costo Actual': 300},
    {'Origen': 'El Carmen', 'Destino': 'Rancho', 'Costo Actual': 100},
    {'Origen': 'El Carmen', 'Destino': 'San Jorge', 'Costo Actual': 600},
    {'Origen': 'El Carmen', 'Destino': 'Victoria', 'Costo Actual': 600}
]
# matriz de distancias (millas)
distancias = [
    [0, 22, 48, 0, 0, 0, 15, 0],
    [22, 0, 0, 45, 0, 0, 0, 0],
    [48, 0, 0, 0, 0, 5, 60, 0],
    [0, 45, 0, 0, 0, 0, 60, 45],
    [0, 0, 0, 0, 0, 30, 30, 20],
    [0, 0, 5, 0, 30, 0, 0, 0],
    [15, 0, 60, 60, 30, 0, 0, 0],
    [0, 0, 0, 45, 20, 0, 0, 0]
]
# matriz de adyacencia
adyacencia = []
for i in range(len(distancias)):
    adyacencia.append([])
    for j in range(len(distancias[i])):
        if distancias[i][j] == 0:
            adyacencia[i].append(0)
        else:
            adyacencia[i].append(1)

# matriz de recorridos y camino minimo
INFINITO = float('inf')
camino_minimo = []
recorridos = []
for i in range(len(distancias)):
    camino_minimo.append([])
    recorridos.append([])
    for j in range(len(distancias[i])):
        recorridos[i].append(j)
        if i == j:
            camino_minimo[i].append(0)
            recorridos[i][j] = -1
        elif distancias[i][j] == 0:
            camino_minimo[i].append(INFINITO)
        else:
            camino_minimo[i].append(distancias[i][j])

for k in range(len(distancias)):
    for i in range(len(distancias)):
        for j in range(len(distancias)):
            if camino_minimo[i][j] > camino_minimo[i][k] + camino_minimo[k][j]:
                camino_minimo[i][j] = camino_minimo[i][k] + camino_minimo[k][j]
                recorridos[i][j] = recorridos[i][k]

# print("Tabla 1")
# print(tabla1)
# print("Adyacencia:")
# imprimir_tabla(adyacencia)
# print("Distancias:")
# imprimir_tabla(distancias)
# print("Camino minimo:")
# imprimir_tabla(camino_minimo)
# print("Recorridos:")
# imprimir_tabla(recorridos)

# Consultas de recorridos desde El Carmen
indiceCiudad = int(input("Ingrese el indice de la ciudad destino: "))
if (indiceCiudad == 2):
    print("Error: No puede seleccionar la ciudad origen como ciudad destino")
    exit()
if (indiceCiudad < 0 or indiceCiudad > len(tabla1)-1):
    print("Error: El indice de la ciudad destino no es valido")
    exit()
print("Recorridos desde El Carmen:")
print("A) La longitud minima en kilometros desde El Carmen a la ciudad destino es: ",
      millastokm(camino_minimo[2][indiceCiudad]), "km")

print("B) El nodo intermedio es: ", recorridos[2][indiceCiudad],
      " que corresponde a la ciudad: ", tabla1[recorridos[2][indiceCiudad]])
# El costo del viaje, sabiendo que por cada 8 km se consume un galon de combustible con un precio de Q 45.00
costo = millastokm(camino_minimo[2][indiceCiudad])/8 * 45
print("C) El costo del viaje es: ", costo, "Q")
# indicar si existe o no ahorro de dinero comparando el costo con la tabla 2
costoCiudad = 0
for i in range(len(tabla2)):
    if tabla2[i]['Origen'] == 'El Carmen' and tabla2[i]['Destino'] == tabla1[indiceCiudad]:
        costoCiudad = tabla2[i]['Costo Actual']
        break
if costo < costoCiudad:
    print("D) Existe ahorro de dinero en ", costoCiudad - costo), "Q"
else:
    print("D) No existe ahorro de dinero, ya que el costo del viaje es ",
          costo, "Q y el costo actual de la ciudad es ", costoCiudad, "Q")
