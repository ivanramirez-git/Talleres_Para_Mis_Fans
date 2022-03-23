# Caclulo de neumaticos
def calculoNeumaticos(tipo):
    precio = 0
    if tipo == 1:
        precio = 12000
    elif tipo == 2:
        precio = 25000
    elif tipo == 3:
        precio = 45000
    else:
        print("No selecciono una opcion valida")
    return precio
    # Caclulo de llantas

# Aplica descuento
def aplicaDescuento(tipo, cantidad):
    descuento = 0
    if cantidad > 10:
        if tipo == 1:
            descuento = 0.05
        elif tipo == 2:
            descuento = 0.1
    elif cantidad > 8 and tipo == 3:
        descuento = 0.007
    return descuento
    
# Imprime factura
def factura(tipo, cantidad, subtotal, descuento, iva, total):
    print("\n.:: FACTURA DE VENTA ::.")
    if tipo == 1:
        print("\nTipo de neumatico: Sinteticos")
    elif tipo == 2:
        print("\nTipo de neumatico: Naturales")
    elif tipo == 3:
        print("\nTipo de neumatico: Hibridos")
    print("\nCantidad de neumaticos: ", cantidad)
    print("\nPrecio: ", subtotal)
    print("\nDescuento: ", descuento)
    print("\nIVA: ", iva)
    print("\nTotal: ", total)
    
IVA = 0.13
# Caldulo del iva
def calculoIVA():
    # Pedir el tipo de neumatico, 1 2 o 3
    tipo = 0
    while tipo < 1 or tipo > 3:
        tipo = int(input("Ingrese el tipo de neumatico:\n\t1. Sinteticos: 12000\n\t2. Naturales: 25000\n\t3. Hibridos: 45000\n"))
    precio = calculoNeumaticos(tipo)
    # Pedir la cantidad de neumaticos, > 0
    cantidad = 0
    while cantidad < 1:
        cantidad = int(input("Ingrese la cantidad de neumaticos:\n"))
    # Aplicar descuento
    descuento = aplicaDescuento(tipo, cantidad)
    # Calcular el subtotal
    subtotal = precio * cantidad
    # Calcular el descuento
    descuento = subtotal * descuento
    # Calcular el iva
    iva = subtotal * IVA
    # Calcular el total
    total = subtotal - descuento + iva
    # Imprimir la factura
    factura(tipo, cantidad, subtotal, descuento, iva, total)

# Programa principal
print("***************Distribuidora de motos La Cordial***************")
print("             %%%%%Bienvenido a nuestro sistema%%%%%")
calculoIVA()