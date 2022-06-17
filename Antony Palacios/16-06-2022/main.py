# Tomando como referencia  la tabla y el grafo que se muestran en la parte inferior y empleando los algoritmos correspondientes cree un programa en el lenguaje python que realice lo siguiente:

"""
0:A
1:B
2:c
3:D
4:E
5:F
6:G
7:H
    A   B   C   D   E   F   G   H
A   0   2   0   3   0   0   0   0
B   4   0   4   0   6   0   0   0
C   0   6   0   0   0   7   0   0
D   0   0   0   0   5   0   4   0
E   0   0   0   6   0   4   0   3
F   0   0   0   0   0   0   0   0
G   0   0   0   2   0   0   0   5
H   0   0   0   0   0   0   1   0
"""
from cmath import e
_infinito = float('inf')


nombres = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
pesos = [[0, 2, 0, 3, 0, 0, 0, 0],
         [4, 0, 4, 0, 6, 0, 0, 0],
         [0, 6, 0, 0, 0, 7, 0, 0],
         [0, 0, 0, 0, 5, 0, 4, 0],
         [0, 0, 0, 6, 0, 4, 0, 3],
         [0, 0, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 2, 0, 0, 0, 5],
         [0, 0, 0, 0, 0, 0, 1, 0]]


def imprimirMatriz(matriz):
    print("Indx:", end="\t")
    for i in range(len(matriz)):
        print(nombres[i], end="\t")
    print()
    for i in range(len(matriz)):
        print(nombres[i], ": ", end="\t")
        for j in range(len(matriz[i])):
            print(round(matriz[i][j], 1), end="\t")
        print()


# 1.	Imprima la Matriz de adyacencia.
print("Matriz de adyacencia:")
adyacencia = []
for i in range(len(nombres)):
    aux = []
    for j in range(len(nombres)):
        if pesos[i][j] == 0:
            aux.append(0)
        else:
            aux.append(1)
    adyacencia.append(aux)
imprimirMatriz(adyacencia)
print()

# 2.	Imprima la Matriz C
print("Matriz C:")
cierre_transitivo = []
for i in range(len(nombres)):
    aux = []
    for j in range(len(nombres)):
        if pesos[i][j] == 0:
            aux.append(0)
        else:
            aux.append(1)
    cierre_transitivo.append(aux)

for k in range(len(nombres)):
    for i in range(len(nombres)):
        for j in range(len(nombres)):
            if cierre_transitivo[i][j] == 0:
                cierre_transitivo[i][j] = cierre_transitivo[i][k] * cierre_transitivo[k][j]
imprimirMatriz(cierre_transitivo)
print()

# 3.	Imprima la Matriz de Distancias/Costos
print("Matriz de distancias/costos:")
distancias = []
for i in range(len(nombres)):
    aux = []
    for j in range(len(nombres)):
        aux.append(pesos[i][j])
    distancias.append(aux)
imprimirMatriz(distancias)
print()

# 4.	Imprima la Matriz de Caminos Mínimos
print("Matriz de caminos minimos:")
caminos_minimos = []
for i in range(len(nombres)):
    aux = []
    for j in range(len(nombres)):
        if i == j:
            aux.append(0)
        elif distancias[i][j] == 0:
            aux.append(_infinito)
        else:
            aux.append(distancias[i][j])
    caminos_minimos.append(aux)
for k in range(len(nombres)):
    for i in range(len(nombres)):
        if i == k:
            continue
        for j in range(len(nombres)):
            if j == k:
                continue
            if caminos_minimos[i][j] > caminos_minimos[i][k] + caminos_minimos[k][j]:
                caminos_minimos[i][j] = caminos_minimos[i][k] + caminos_minimos[k][j]
imprimirMatriz(caminos_minimos)
print()

# 5.	Imprima la Matriz T de recorridos
print("Matriz T:")

"""
6.	Considerando la matriz del inciso 2) y el formato que se indica al final del problema ,imprima en pantalla la posición (fila, col) y el valor que ahí se encuentra que permita indicar si existe o no camino entre:
0.	F y A  
1.	H y A  
"""
print("Posiciones y valores que indican si existe o no camino entre:")
print("F y A", end=": ")
if cierre_transitivo[5][0] == 1:
    # Según la Matriz C en la posición x,y cuyo valor es z existe camino entre A y B
    print(f"Según la Matriz C en la posición {5},{0} cuyo valor es {cierre_transitivo[5][0]} existe camino entre F y A")
else:
    print(f"Según la Matriz C en la posición {5},{0} cuyo valor es {cierre_transitivo[5][0]} NO existe camino entre F y A")   
print()

print("H y A", end=": ")
if cierre_transitivo[6][0] == 1:
    # Según la Matriz C en la posición x,y cuyo valor es z existe camino entre A y B
    print(f"Según la Matriz C en la posición {6},{0} cuyo valor es {cierre_transitivo[6][0]} existe camino entre H y A")
else:
    print(f"Según la Matriz C en la posición {6},{0} cuyo valor es {cierre_transitivo[6][0]} NO existe camino entre H y A")
print()

"""
7.	Considerando la matriz del inciso 4) y el formato que se indica el final del problema, imprima en pantalla la posición (fila, col) y el valor que corresponde a:
0.	La longitud mínima entre A y E 
1.	Longitud mínima entre A y H 
2.	Longitud mínima entre G y C 
3.	Longitud mínima entre D y C 
"""
print("Posiciones y valores que corresponden a:")
print("La longitud mínima entre A y E", end=": ")
if caminos_minimos[0][4] == _infinito:
    # Según la Matriz  de Caminos Mínimos en la posición x,y la longitud mínima entre A y B es z
    print(f"Según la Matriz  de Caminos Mínimos en la posición {0},{4} NO existe camino entre A y E ya que es INFINITO")
else:
    print(f"Según la Matriz  de Caminos Mínimos en la posición {0},{4} la longitud mínima entre A y E es {caminos_minimos[0][4]}")
print()

print("Longitud mínima entre A y H", end=": ")
if caminos_minimos[0][7] == _infinito:
    print(f"Según la Matriz  de Caminos Mínimos en la posición {0},{7} NO existe camino entre A y H ya que es INFINITO")
else:
    print(f"Según la Matriz  de Caminos Mínimos en la posición {0},{7} la longitud mínima entre A y H es {caminos_minimos[0][7]}")
print()

print("Longitud mínima entre G y C", end=": ")
if caminos_minimos[6][2] == _infinito:
    print(f"Según la Matriz  de Caminos Mínimos en la posición {6},{2} NO existe camino entre G y C ya que es INFINITO")
else:
    print(f"Según la Matriz  de Caminos Mínimos en la posición {6},{2} la longitud mínima entre G y C es {caminos_minimos[6][2]}")
print()

print("Longitud mínima entre D y C", end=": ")
if caminos_minimos[3][2] == _infinito:
    print(f"Según la Matriz  de Caminos Mínimos en la posición {3},{2} NO existe camino entre D y C ya que es INFINITO")
else:
    print(f"Según la Matriz  de Caminos Mínimos en la posición {3},{2} la longitud mínima entre D y C es {caminos_minimos[3][2]}")
print()

"""
8.	Considerando la matriz del inciso 5) y el formato que se indica al final del problema, imprima en pantalla la posición (fila, col) y nombre del nodo:
0.	Intermedio entre G y C 
1.	Intermedio entre H y A 
"""
# Según la Matriz  T en la posición x,y cuyo valor es Z el nodo intermedio es A

# 9.	 Inserte todos los valores de la  Matriz de Caminos Mínimos (utilizando dos ciclos for anidados para recorrer la matriz) dentro de un arreglo de N = 100 utilizando la función hash módulo K%N+1.  Si encuentra una colisión resolverla por medio del método de doble dirección hash con la segund funcion hash igual a (K+1)%N+1. Finalmente imprima en pantalla el arreglo completo.
arreglo = []