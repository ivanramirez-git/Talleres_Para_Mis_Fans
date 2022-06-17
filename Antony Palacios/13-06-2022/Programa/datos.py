# numpy
import numpy as np
# importar archivos de excel
import xlrd
# conexion con mysql xampp
import mysql.connector

ruta_distancias = "../Matrices/DistanciasCiudades.xlsx"


def leer_distancias(ruta):
    # abrir archivo
    archivo = xlrd.open_workbook(ruta)
    # obtener hoja
    hoja = archivo.sheet_by_index(0)
    # obtener filas y columnas
    filas = hoja.nrows
    columnas = hoja.ncols
    # header de tipo string
    header = []
    # crear matriz
    matriz = np.zeros((filas-1, columnas-1))
    # leer matriz
    for i in range(filas):
        for j in range(columnas):
            if i == 0:
                if j == 0:
                    continue
                header.append(hoja.cell_value(i, j))
            if i == 0:
                continue
            if j == 0:
                continue
            matriz[i-1][j-1] = hoja.cell_value(i, j)
    return header, matriz


def imprimir_matriz(header, matriz):
    # imprimir matriz
    for i in range(len(matriz)):
        print(header[i], ": ", end="")
        for j in range(len(matriz[i])):
            print(matriz[i][j], end="\t")
        print()

# crear base de datos


def crear_base_datos(header, matriz):
    # conexion con mysql xampp
    conexion = mysql.connector.connect(
        host="localhost",
        user="root",
        passwd="",
        database="matriz"
    )
    # crear cursor
    cursor = conexion.cursor()

    # borrar datos de las tablas
    cursor.execute("DROP TABLE IF EXISTS distancias")
    cursor.execute("DROP TABLE IF EXISTS ciudades")

    # crear tabla ciudades
    cursor.execute(
        "CREATE TABLE IF NOT EXISTS ciudades (id INTEGER PRIMARY KEY auto_increment, nombre VARCHAR(50))")
    # crear tabla distancias
    cursor.execute(
        "CREATE TABLE IF NOT EXISTS distancias (id_ciudad1 INTEGER, id_ciudad2 INTEGER, distancia REAL)")

    # insertar ciudades
    for i in range(len(header)):
        cursor.execute(
            "INSERT INTO ciudades (nombre) VALUES ('"+header[i]+"')")
    # insertar distancias
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            cursor.execute("INSERT INTO distancias (id_ciudad1, id_ciudad2, distancia) VALUES (" +
                           str(i+1)+","+str(j+1)+","+str(matriz[i][j])+")")
    # commit
    conexion.commit()

def main():
    # leer matriz de distancias
    header2, matriz_distancias = leer_distancias(ruta_distancias)
    # imprimir matriz de distancias
    imprimir_matriz(header2, matriz_distancias)
    # crear base de datos
    crear_base_datos(header2, matriz_distancias)


main()
