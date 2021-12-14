# Ralizar un programa que maneje una lista de enteros a travez de un menu con seis opciones:
# 1. Agregar un elemento al final de la lista - mostrar la lista
# 2. Agregar un elemento en alguna posicion de la lista
# 3. Eliminar un elemento de la lista (comprobando que no este vacia) - mostrar la lista
# 4. Contar las apariciones de un numero en la lista
# 5. Calcular la media y el valor mas alto de los elementos de la lista
# 6. Terimnar

lista = []

while True:
    print("""
    1. Agregar un elemento al final de la lista
    2. Agregar un elemento en alguna posicion de la lista
    3. Eliminar un elemento de la lista (comprobando que no este vacia)
    4. Contar las apariciones de un numero en la lista
    5. Calcular la media y el valor mas alto de los elementos de la lista
    6. Terminar
    """)
    opcion = int(input("Ingrese una opcion: "))
    if opcion == 1:
        numero = int(input("Ingrese un numero: "))
        lista.append(numero)
        print(lista)
    elif opcion == 2:
        numero = int(input("Ingrese un numero: "))
        posicion = int(input("Ingrese la posicion: "))
        lista.insert(posicion, numero)
        print(lista)
    elif opcion == 3:
        # Comprobar que la lista no este vacia
        if len(lista) == 0:
            print("La lista esta vacia")
        elif numero in lista:
            numero = int(input("Ingrese el numero a eliminar: "))
            lista.remove(numero)
            print(lista)
        else:
            print("El numero no esta en la lista")
    elif opcion == 4:
        numero = int(input("Ingrese un numero: "))
        contador = 0
        for i in lista:
            if i == numero:
                contador += 1
        print("El numero {} aparece {} veces".format(numero, contador))
    elif opcion == 5:
        suma = 0
        for i in lista:
            suma += i
        # Calcular la media variable flotante
        media = suma / (0.0+len(lista))
        print("La media es: {}".format(media))
        # Calcular el valor mas alto
        valor_mas_alto = max(lista)
        print("El valor mas alto es: {}".format(valor_mas_alto))
    elif opcion == 6:
        break
    else:
        print("Opcion incorrecta")
print("Fin del programa")


