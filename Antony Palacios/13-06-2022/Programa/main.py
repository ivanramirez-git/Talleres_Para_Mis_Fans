# mysql
from platform import java_ver
import tkinter as tk
from tkinter import messagebox
import mysql.connector
from numpy import Infinity

# cargar los datos de la base de datos 'matriz' de xampp
conexion = mysql.connector.connect(
    host="localhost",
    user="root",
    passwd="",
    database="matriz"
)
# crear cursor
cursor = conexion.cursor()


def importar_datos():
    # consultar los nombres de las ciudades
    ciudades = []
    # query para obtener los nombres de las ciudades
    query = "SELECT nombre FROM ciudades ORDER BY id"
    # ejecutar query
    cursor.execute(query)
    # obtener resultados
    resultados = cursor.fetchall()
    # guardar los nombres de las ciudades
    for resultado in resultados:
        ciudades.append(resultado[0])

    # consultar las distancias entre ciudades
    distancias = []
    aux = []
    # query para obtener las distancias entre ciudades
    for i in range(len(ciudades)):
        query = "SELECT distancia FROM distancias WHERE id_ciudad1 = " + \
            str(i+1) + " ORDER BY id_ciudad2"
        # ejecutar query
        cursor.execute(query)
        # obtener resultados
        resultados = cursor.fetchall()
        # guardar las distancias entre ciudades
        for resultado in resultados:
            aux.append(resultado[0])
        distancias.append(aux)
        aux = []

    # usando las distancias construir las matriz de adyacencia
    adyacencia = []
    for i in range(len(ciudades)):
        aux = []
        for j in range(len(ciudades)):
            if distancias[i][j] == 0:
                aux.append(0)
            else:
                aux.append(1)
        adyacencia.append(aux)

    """
    Adyacencia:

        A   B   C   D   E   F
    A   0   1   0   0   1   0
    B   0   0   0   1   0   0
    C   0   1   0   0   0   0
    D   0   0   1   0   0   1
    E   0   0   0   0   0   0
    F   0   0   0   0   0   0

    Cierre transitivo:

        A   B   C   D   E   F
    A   0   1   1   1   1   1
    B   0   1   1   1   0   1
    C   0   1   1   1   0   1
    D   0   1   1   1   0   1
    E   0   0   0   0   0   0
    F   0   0   0   0   0   0

    """

    # usando la matriz de adyacencia construir la matriz de Cierre Transitivo de warshall:
    # Warshall (Recibe como entrada Matriz de Adyacencia y produce Matriz C)
    cierre_transitivo = []
    for i in range(len(ciudades)):
        aux = []
        for j in range(len(ciudades)):
            if adyacencia[i][j] == 1:
                aux.append(1)
            else:
                aux.append(0)
        cierre_transitivo.append(aux)
    for k in range(len(ciudades)):
        for i in range(len(ciudades)):
            for j in range(len(ciudades)):
                if cierre_transitivo[i][j] == 0:
                    cierre_transitivo[i][j] = cierre_transitivo[i][k] * \
                        cierre_transitivo[k][j]

    # Floyd (Recibe como entrada Matriz de Distancias y produce Matriz de Caminos Mínimos)
    caminos_minimos = []
    recorridos = []
    # llenando matriz de recorridos
    for i in range(len(ciudades)):
        aux = []
        for j in range(len(ciudades)):
            if i == j:
                aux.append(-1)
            else:
                aux.append(i)
        recorridos.append(aux)

    _infinito = Infinity

    # llenar matriz de caminos minimos con las distancias, si no hay camino directo la distancia es _infinito
    for i in range(len(ciudades)):
        aux = []
        for j in range(len(ciudades)):
            if i == j:
                aux.append(0)
            elif distancias[i][j] == 0:
                aux.append(_infinito)
            else:
                aux.append(distancias[i][j])

        caminos_minimos.append(aux)

    aux = caminos_minimos

    # operar las matrices
    for k in range(len(ciudades)):
        for i in range(len(ciudades)):
            if i == k:
                continue
            for j in range(len(ciudades)):
                if j == k:
                    continue
                if caminos_minimos[i][j] > aux[i][k] + aux[k][j]:
                    caminos_minimos[i][j] = caminos_minimos[i][k] + \
                        caminos_minimos[k][j]
                    recorridos[i][j] = k

    # Floyd Guarda Vértices (Recibe como entrada Matriz de Distancias y produce Matriz de Caminos Mínimos y Matriz T)
    vertices = []
    t = []
    for i in range(len(ciudades)):
        aux = []
        for j in range(len(ciudades)):
            if i == j:
                aux.append(0)
            else:
                aux.append(1)
        vertices.append(aux)
        aux = []
    for i in range(len(ciudades)):
        aux = []
        for j in range(len(ciudades)):
            aux.append(0)
        t.append(aux)
    for k in range(len(ciudades)):
        for i in range(len(ciudades)):
            for j in range(len(ciudades)):
                if vertices[i][j] == 1:
                    if caminos_minimos[i][j] > caminos_minimos[i][k] + caminos_minimos[k][j]:
                        caminos_minimos[i][j] = caminos_minimos[i][k] + \
                            caminos_minimos[k][j]
                        recorridos[i][j] = k
                        t[i][j] = k

    # Dijkstra (Nodos del camino más corto)
    dijkstra = []
    for i in range(len(ciudades)):
        aux = []
        for j in range(len(ciudades)):
            aux.append(0)
        dijkstra.append(aux)
    for i in range(len(ciudades)):
        dijkstra[i][i] = 1
    for i in range(len(ciudades)):
        for j in range(len(ciudades)):
            if caminos_minimos[i][j] == _infinito:
                dijkstra[i][j] = 0
            else:
                dijkstra[i][j] = 1
    for i in range(len(ciudades)):
        for j in range(len(ciudades)):
            if dijkstra[i][j] == 1:
                for k in range(len(ciudades)):
                    if dijkstra[j][k] == 1:
                        dijkstra[i][k] = 1

    return ciudades, distancias, adyacencia, cierre_transitivo, caminos_minimos, recorridos, t, vertices, dijkstra


ciudades, distancias, adyacencia, cierre_transitivo, caminos_minimos, recorridos, t, vertices, dijkstra = importar_datos()


# tkinter

"""
6.	El usuario podrá seleccionar un municipio de origen y un municipio de destino, de manera que el programa deberá indicar:
    a.	Si existe camino entre esos municipios (verificar Matriz C de Warshall)
    b.	Cual es la longitud del camino más corto (verificar Matriz de Caminos Mínimos)
    c.	Cual es el nodo intermedio para llegar del origen al destino (verificar Matriz T)
    d.	Nodos (municipios) del camino más corto(Algoritmo Dijkstra)
"""


# funcion que retorna el indice dado el nombre de la ciudad
def indice_ciudad(ciudad):
    for i in range(len(ciudades)):
        if ciudades[i] == ciudad:
            return i


# funcion que imprime una matriz
def imprimir_matriz(matriz):
    for i in range(len(matriz)):
        print(ciudades[i], ": ", i)
    for i in range(len(matriz)):
        print(i, ": ", end="\t")
        for j in range(len(matriz[i])):
            print(round(matriz[i][j], 1), end="\t")
        print()


print("Distancias:")
print()
imprimir_matriz(distancias)
print()
print("Adyacencia:")
print()
imprimir_matriz(adyacencia)
print()
print("Cierre Transitivo:")
print()
imprimir_matriz(cierre_transitivo)
print()
print("Caminos Mínimos:")
print()
imprimir_matriz(caminos_minimos)
print()
print("Recorridos:")
print()
imprimir_matriz(recorridos)
print()
print("Caminos Mínimos Guarda Vertices:")
print()
imprimir_matriz(vertices)
print()
print("Dijkstra:")
print()
imprimir_matriz(dijkstra)
# funcion que da los nombres de los nodos del camino más corto


def nodos_camino_corto(ciudad_origen, ciudad_destino):
    origen = indice_ciudad(ciudad_origen)
    destino = indice_ciudad(ciudad_destino)
    camino = []
    while True:
        camino.append(ciudades[destino])
        destino = recorridos[origen][destino]
        if destino == origen:
            camino.append(ciudades[origen])
            break
    return camino

# nodos dijkstra


def nodos_dijkstra(ciudad_origen, ciudad_destino):
    origen = indice_ciudad(ciudad_origen)
    destino = indice_ciudad(ciudad_destino)
    camino = []
    while True:
        camino.append(ciudades[destino])
        destino = dijkstra[origen][destino]
        if destino == origen:
            camino.append(ciudades[origen])
            break
    return camino


# ventana darkmode
ventana = tk.Tk()
ventana.title("Camino Más Corto")
ventana.geometry("550x100")
ventana.configure(background='black')


# formulario, donde el usuario escoge los municipios de origen y destino desde un dropdown
formulario = tk.Frame(ventana, bg='black')
formulario.pack(fill=tk.BOTH, expand=1)

# dropdown de origen
tk.Label(formulario, text="Origen", bg='black', fg='white').pack(side=tk.LEFT)
origen = tk.StringVar()
origen.set("Seleccione una ciudad")
dropdown_origen = tk.OptionMenu(formulario, origen, *ciudades)
dropdown_origen.pack(side=tk.LEFT)


# dropdown de destino
tk.Label(formulario, text="Destino", bg='black', fg='white').pack(side=tk.LEFT)
destino = tk.StringVar()
destino.set("Seleccione una ciudad")
dropdown_destino = tk.OptionMenu(formulario, destino, *ciudades)
dropdown_destino.pack(side=tk.LEFT)

# boton que llama a la funcion que dice si existe camino entre dos ciudades


def existe_camino(ciudad_origen, ciudad_destino):
    if ciudad_origen == ciudad_destino:
        return True
    else:
        return cierre_transitivo[indice_ciudad(ciudad_origen)][indice_ciudad(ciudad_destino)] == 1


def existe_camino_boton():
    ciudad_origen = origen.get()
    ciudad_destino = destino.get()
    if existe_camino(ciudad_origen, ciudad_destino):
        # msgbox de que existe camino
        messagebox.showinfo(
            "Existe Camino", "Existe camino entre " + ciudad_origen + " y " + ciudad_destino)
        messagebox.showinfo("Longitud Camino Más Corto", "La longitud del camino más corto es " +
                            str(caminos_minimos[indice_ciudad(ciudad_origen)][indice_ciudad(ciudad_destino)]))
        messagebox.showinfo("Nodo Intermedio", "El nodo intermedio para llegar del origen al destino es " +
                            str(nodos_camino_corto(ciudad_origen, ciudad_destino)))
        # messagebox.showinfo("Nodos del Camino Más Corto", "Los nodos del camino más corto son " + str(nodos_dijkstra(ciudad_origen,ciudad_destino)))
    else:
        # msgbox de que no existe camino
        messagebox.showinfo(
            "No Existe Camino", "No existe camino entre " + ciudad_origen + " y " + ciudad_destino)


boton_existe_camino = tk.Button(
    formulario, text="Existe camino", command=existe_camino_boton, bg='black', fg='white')
boton_existe_camino.pack(side=tk.LEFT)

# mainloop
ventana.mainloop()
