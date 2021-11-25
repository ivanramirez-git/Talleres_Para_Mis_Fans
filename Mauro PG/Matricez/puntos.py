
while True:
    print("1. Muestra por pantalla una simulacion de tablero de ajedrez. Donde N son las negras y B las blancas.")
    print("2. Escriba un programa que pida al usuario ingresar el tamaño de una matriz cuadrada, e ingresar los numeros del 1 al 100. Si es mas grande que 100 se hace modulo 10.")
    print("3. Escriba un programa que pida al usuario los datos de una matriz 3x3 y muestre por pantalla la inverso de la matriz.")
    print("4. Salir")
    opcion = int(input("Ingrese una opcion: "))
    if opcion == 1:

        for i in range(8):
            for j in range(8):
                if (i+j)%2 == 0:
                    print("B", end=" ")
                else:
                    print("N", end=" ")
            print()

    elif opcion == 2:

        n = int(input("Ingrese el tamaño de la matriz: "))            
        matriz = []
        a=0
        for i in range(n):
            matriz.append([])
            for j in range(n):
                a+=1
                if a<=100:
                    matriz[i].append(a)
                else:
                    a=a-100
                    matriz[i].append(a)
        print(matriz)

    elif opcion == 3:
            
        matriz = []
        for i in range(3):
            matriz.append([])
            for j in range(3):
                matriz[i].append(int(input("Ingrese un numero: ")))
        # imprimir matriz
        print("Matriz original: ")
        for i in range(3):
            for j in range(3):
                print(matriz[i][j], end=" ")
            print()

        matriz_inversa = []
        for i in range(3):
            matriz_inversa.append([])
            for j in range(3):
                matriz_inversa[i].append(matriz[j][i])
        # imprimir matriz inversa
        print("Matriz inversa: ")
        for i in range(3):
            for j in range(3):
                print(matriz_inversa[i][j], end=" ")
            print()

    elif opcion == 4:
        break
    else:
        print("Opcion incorrecta")