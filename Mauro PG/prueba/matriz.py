# Programa en python:
# a) Solicite las dimenciones de una matriz
# b) Solicite ingresar los valores a la matriz
# c) Devuelva la ubicacion de un valor ingresado por el usuario
# d) Pueda imprimir la matriz y su transpuesta

# a) Solicite las dimenciones de una matriz
x = int(input("Ingrese la cantidad de filas: "))
y = int(input("Ingrese la cantidad de columnas: "))

# b) Solicite ingresar los valores a la matriz
matriz = []
for i in range(x):
    matriz.append([])
    for j in range(y):
        matriz[i].append(int(input("Ingrese el valor de la posicion [{}][{}]: ".format(i, j))))

# c) Devuelva la ubicacion de un valor ingresado por el usuario
valor = int(input("Ingrese el valor a buscar: "))
for i in range(x):
    for j in range(y):
        if matriz[i][j] == valor:
            print("El valor {} se encuentra en la posicion [{}][{}]".format(valor, i, j))

# d) Pueda imprimir la matriz y su transpuesta
print("Matriz original:")
for i in range(x):
    print(matriz[i])
    
# Transpuesta
print("Matriz transpuesta:")
for i in range(y):
    for j in range(x):
        print(matriz[j][i], end=" ")
    print()







