#Una franquicia de ropa, vende N productos diferentes en sucursales ubicadas en M zonas distintas de la ciudad. Los datos de las ventas diarias de cada zona, se tienen en una matriz bidimensional llamada ventas [zona, productos] donde zona indica el número de la zona y producto, indica el número de productos que se vende dentro de la zona.
#Elaborar un programa en que determine y muestre lo siguiente:
#1.	Mostrar la matriz cargada con todas las ventas diarias, calcular y mostrar el valor de la venta promedio de toda la franquicia. (Valor 1)
#2.	zona en la que se realizó la venta más alta y la venta más baja. (valor 1)
#3.	En un arreglo unidimensional mostrar por producto el valor de la venta promedio de todas las zonas. (Valor 1)
#4.	En qué zona todos los productos vendidos en esta, obtuvieron ventas superiores a $5 (Valor 2)

# Cuantos productos hay en la franquicia
N = int(input("Cuantos productos hay en la franquicia: "))

# Cuantas zonas hay en la franquicia
M = int(input("Cuantas zonas hay en la franquicia: "))

# Arreglo bidimensional para guardar las ventas
ventas = []


# Cargar las ventas
for i in range(M):
    ventas.append([])
    for j in range(N):
        ventas[i].append(int(input("Ingrese la venta del producto " + str(j+1) + " en la zona " + str(i+1) + ": ")))
        
# Menu
while True:
    print("\n1. Mostrar la matriz cargada con todas las ventas diarias, calcular y mostrar el valor de la venta promedio de toda la franquicia.\n2. zona en la que se realizó la venta más alta y la venta más baja.\n3. En un arreglo unidimensional mostrar por producto el valor de la venta promedio de todas las zonas.\n4. En qué zona todos los productos vendidos en esta, obtuvieron ventas superiores a $5\n5. Salir")
    opcion = int(input("Ingrese una opcion: "))
    if opcion == 1:
        # 1. Mostrar la matriz cargada con todas las ventas diarias, calcular y mostrar el valor de la venta promedio de toda la franquicia.
        
        # Mostrar la matriz print beautiful
        print("Zona\Producto")
        for i in range(M):
            for j in range(N):
                print("[" + str(ventas[i][j]) + "]", end="\t")
            print("\n\n")
        
        promedio = 0
        for i in range(M):
            for j in range(N):
                promedio += ventas[i][j]
        promedio = promedio / (M * N)
        print("El promedio de ventas es: " + str(promedio))
    elif opcion == 2:
        # 2. zona en la que se realizó la venta más alta y la venta más baja.
        print("\nzona en la que se realizó la venta más alta y la venta más baja.\n")
        max = 0
        min = ventas[0][0]
        zonaMax = 0
        zonaMin = 0
        for i in range(M):
            for j in range(N):
                if ventas[i][j] > max:
                    max = ventas[i][j]
                    zonaMax = i
                if ventas[i][j] < min:
                    min = ventas[i][j]
                    zonaMin = i
        print("La venta mas alta fue en la zona " + str(zonaMax+1) + " con un valor de " + str(max))
        print("La venta mas baja fue en la zona " + str(zonaMin+1) + " con un valor de " + str(min))
    elif opcion == 3:
        # 3. En un arreglo unidimensional mostrar por producto el valor de la venta promedio de todas las zonas.
        print("\nEn un arreglo unidimensional mostrar por producto el valor de la venta promedio de todas las zonas.\n")
        promedio = 0
        # Arreglo para guardar los promedios
        promedios = []
        for i in range(N):
            for j in range(M):
                promedio += ventas[j][i]
            promedio = promedio / M
            promedios.append(promedio)
            print("El promedio de ventas del producto " + str(i+1) + " es: " + str(promedio))
            promedio = 0
        
        # Mostrar el arreglo
        print("\nProducto\Promedio")
        print(promedios)
    elif opcion == 4:
        # 4. En qué zona todos los productos vendidos en esta, obtuvieron ventas superiores a $5
        print("\nEn qué zona todos los productos vendidos en esta, obtuvieron ventas superiores a $5\n")
        for i in range(M):
            for j in range(N):
                if ventas[i][j] > 5:
                    print("El producto " + str(j+1) + " vendido en la zona " + str(i+1) + " supero el valor de $5")
        
        # Verificar en que zonas todos los productos vendidos son mas de $5
        acumulador = 0
        for i in range(M):
            for j in range(N):
                if ventas[i][j] > 5:
                    acumulador += 1
                if(acumulador == N):
                    print("Todos los productos vendidos en la zona " + str(i+1) + " superaron el valor de $5")
            acumulador = 0


    elif opcion == 5:
        break
    else:
        print("Opcion no valida")

