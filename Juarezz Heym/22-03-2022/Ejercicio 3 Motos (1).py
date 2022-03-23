#Una distribuidora de motocicletas con promociones por marcas

def factura(Tipo,Descuento,Cantidad,IVA,TotalDescuento,Subtotal):
    Nombre = input("Indique el nombre del cliente ")
    print("\t********FACTURA PROFORMA********")
    print("\nNombre del cliente:\t", Tipo)
    print("Marca de moto:\t\t", Cantidad)
    print("Precio inicial:\t\t",Subtotal)
    print("Descuento:\t\t",Descuento)
    print("Monto descuento:\t",IVA)
    print("Precio final:\t\t",TotalDescuento)
    print("Precio final:\t\t",Total_Pagar)
    

def descuento(Tipo,Porcen,Subtotal):
    MontoDesc = Subtotal*Porcen
    factura(Moto, Porc, Costo, MontoDesc)
    
    

def marca():
    MotoElegida = " "
    PorcDesc = 0
    Precio = 0
    while True:
        vuelve= input("\nDesea realizar una cotización 1. Si  2. No ")
        if vuelve == "1":
            menu()
            opcion = input("\tSelecciona una opción: ")
            if opcion == "1":
                MotoElegida = "Honda"
                PorcDesc = 0.05
                Precio = 3250000.00
            elif opcion =="2":
                MotoElegida = "Yamaha"
                PorcDesc = 0.08
                Precio = 1500000.00
            elif opcion =="3":
                MotoElegida = "Suzuki"
                PorcDesc = 0.1
                Precio = 1800000.00
            elif opcion == "4":
                MotoElegida = "Otras"
                PorcDesc = 0.02
                Precio = 1000000.00
            elif opcion == "5":
                break
            else:
                print ("")
                input("No has pulsado ninguna opción correcta...\npulsa una tecla para continuar")
            descuento(MotoElegida, PorcDesc,Precio)
        else:
            break

def menu():
##Función que limpia la pantalla y muestra nuevamente el menu
        print()
        print("\t :::: Le ofrecemos 4 opciones que puede elegir  ::::")
        print()
        print ("\t1 - Moto Honda   -- Precio ¢3.250.000 -- descuento 5%")
        print ("\t2 - Moto Yamaha  -- Precio ¢1.500.000 -- descuento 8%")
        print ("\t3 - Moto Suzuki  -- Precio ¢1.800.000 -- descuento 10%")
        print ("\t4 - Otras marcas -- Precio ¢1.000.000 -- descuento 2%")
        print ("\t5 - Salir")
    

#Programa principal

print("***************Distribuidora de motos La Cordial***************")
print("             %%%%%Bienvenido a nuestro sistema%%%%%")
marca()

print ("\n****Gracias por utilizar nuestro programa***")
