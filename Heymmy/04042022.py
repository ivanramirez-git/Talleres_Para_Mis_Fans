# Realice un ejercicio que llene con numeros aleatorios una matriz de 5x5
# Funciones: 
# 1. Suma cada una de las filas y total de la matriz
# 2. Saca el promedio de la matriz
# 3. Indica cuantos numeros de la matriz pares
# 4. Modifica la matriz en la fila 3 muntiplicando por 2

import random

def suma_filas(matriz):
    suma = 0
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            suma += matriz[i][j]
        print(f"La suma de la fila {i+1} es: {matriz[i][0]} + {matriz[i][1]} + {matriz[i][2]} + {matriz[i][3]} + {matriz[i][4]} = {suma}")
        suma = 0
    print("Total de la matriz: ")
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            suma += matriz[i][j]
    print(suma)

def promedio(matriz):
    suma = 0
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            suma += matriz[i][j]
    print(suma / (len(matriz) * len(matriz[i])))

def pares(matriz):
    cont = 0
    a = []
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            if matriz[i][j] % 2 == 0:
                cont += 1
                a.append(matriz[i][j])
    print(f"Hay {cont} numeros pares en la matriz y son: {a}")

def multiplicar_fila(matriz):
    for i in range(len(matriz)):
        matriz[i][3] = matriz[i][3] * 2
    print(matriz)

def main():
    matriz = [[0 for x in range(5)] for y in range(5)]
    print("Generando aleatorios...")
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            matriz[i][j] = random.randint(0, 100)
    print("Matriz generada: ")
    print(matriz)
    print("Suma de cada fila: ")
    suma_filas(matriz)
    print("Promedio de la matriz: ")
    promedio(matriz)
    print("Cantidad de numeros pares: ")
    pares(matriz)
    print("Fila 3 multiplicada por 2: ")
    multiplicar_fila(matriz)

# Inicio del programa
main()

