import pandas as pd
import openpyxl
import string
import random
import datetime
from datetime import date
from datetime import timedelta
import calendar
from imprimevuelos import vuelos
from aviones import avion1
from aviones import avion2
from funciones import dia
from funciones import matriz
from funciones import codigo
diaactual= date.today()
print("                 UTEC AEROLINEAS            ")
print("Vuelos entre: LIMA--------AREQUIPA--------CUSCO")
print("                |____________________________|  ")
print("             BIENVENIDO A UTEC AEROLINEAS        ")
print(f"Fecha actual: {diaactual}")
def intro_a_pagina():
    accion=int(input("¿Qué desea hacer?\n 1) Comprar pasajes\n 2) Hacer check-in\n 3) Ver estado de vuelo\n 4) Buscar mi reserva\n 5) Ver listado de pasajeros\n 6) Buscar mi reserva con DNI\n Opción elegida: "))
    return accion
accion = intro_a_pagina()

def tipo_de_viaje(viajenum):
    viaje = ""
    if viajenum == 1:
        viaje = "Ida"
    else:
        viaje="Ida y vuelta"
    return viaje

viajenum = int(input("Escoja el tipo de viaje que desea realizar:\n 1) Viaje de ida\n 2) Viaje de ida y vuelta\n Opción elegida: "))
viaje = tipo_de_viaje(viajenum)

def compra_de_vuelos(vuelo_iv):
    if vuelo_iv == ida:
        origen1 = int(input("Escoja su ciudad de origen:\n 1) Lima\n 2) Arequipa\n 3) Cusco\n Opción elegida: "))
        if origen1 == 1:
            origen = "Lima"
        elif origen1 == 2:
            origen = "Arequipa"
        else:
            origen = "Cusco"
        destino1 = int(input("y la de destino:\n 1) Lima\n 2) Arequipa\n 3) Cusco\n Opción elegida: "))
        if destino1 == 1:
            destino = "Lima"
        elif destino1 == 2:
            destino = "Arequipa"
        else:
            destino = "Cusco"
    if vuelo_iv == ida:
        vuelo_iv.append(origen)
        vuelo_iv.append(destino)
    else:
        vuelo_iv.append(ida[1])
        vuelo_iv.append(ida[0])
    if vuelo_iv == ida:
        fecha = input("Indique la fecha del pasaje de ida (dd/mm/aaaa): ")
    else:
        fecha = input("Indique la fecha del pasaje de vuelta (dd/mm/aaaa): ")
    dia_variable = dia(fecha)
    vuelo_iv.append(dia_variable)
    print("Los vuelos disponibles:")
    n = 1
    vp = []
    if vuelo_iv == ida:
        print("VUELO IDA")
    else:
        print("VUELO VUELTA")
    for i in range(len(vuelos)):
        if vuelos[i][0] == vuelo_iv[0] and vuelos[i][1] == vuelo_iv[1] and vuelos[i][2] == vuelo_iv[2]:
            print(f"Opcion {n}------> Tipo de avion: {vuelos[i][4]}-----> Hora: {vuelos[i][3]}hrs--------> Precio: ${vuelos[i][6]}")
            vp.append(vuelos[i])
            n += 1
    n = int(input("Elija una opción: "))
    n = n - 1
    print(f"Origen: {vp[n][0]}---> Destino: {vp[n][1]} | Dia: {vp[n][2]} Hora: {vp[n][3]}hrs | Tipo de avion: {vp[n][4]}, N° de vuelo: {vp[n][5]}  ")
    for i in range(3, 7, 1):
        vuelo_iv.append(vp[n][i])
    vuelo_iv.append(fecha)
    return vuelo_iv

fecha_ida = ""
fecha_vuelta = ""
ida = []
vuelta = []

def elegir_el_asiento(vuelo_iv):
    avion = []
    if vuelo_iv[4] == "1":
        avion = avion1
    else:
        avion = avion2
    print("MAPA DE ASIENTOS: ")
    print(matriz(avion))
    print("A continuación podrá elegir su asiento: ")
    f = 0
    a = 0
    aux = False
    while aux == False:
        f = int(input("N° DE FILA: "))
        letra = input("ASIENTO: ")
        letra = letra.strip().capitalize()
        a = ord(letra) - 64
        if avion[f][a] == "O":
            asiento = avion[f][a]
            avion[f][a] = "X"
            aux = True
            return f"Su asiento es el {f}{avion[0][a]}"
        else:
            print("Asiento Ocupado, elija otro")
            aux = False

if accion == 1:
    if viaje == "Ida":
        ida = compra_de_vuelos(ida)
        asiento = elegir_el_asiento(ida)
        fecha_ida = ida[7]
    else:
        ida = compra_de_vuelos(ida)
        asiento_ida = elegir_el_asiento(ida)
        fecha_ida = ida[7]
        vuelta = compra_de_vuelos(vuelta)
        asiento_vuelta = elegir_el_asiento(vuelta)
        fecha_vuelta = vuelta[7]
elif accion == 2:
    print("Hacer check-in")
else:
    print("Estado de vuelo: ")

def imprimir_el_pasaje(apellidos,nombres,dni,correo,codigoi,codigov):
    print(f"PASAJE IDA                                   Codigo de reserva: {codigoi}")
    print(f"Tipo de avion: {ida[4]}                             N° de vuelo: {ida[5]}")
    print(f"Origen: {ida[0]}                                    Destino: {ida[1]}")
    print(f"Fecha: {ida[2], fecha_ida}. Hora: {ida[3]}hrs.")
    print(f"Pasajero: {apellidos}, {nombres}. DNI: {dni} ")
    if viaje!="Ida":
        print("------------------------------------------------------------------------------------")
        print(f"PASAJE VUELTA                                    Codigo de reserva: {codigov}")
        print(f"Tipo de avion: {vuelta[4]}                             N° de vuelo: {vuelta[5]}")
        print(f"Origen: {vuelta[0]}                                    Destino: {vuelta[1]}")
        print(f"Fecha: {vuelta[2], fecha_vuelta}. Hora: {vuelta[3]}hrs.")
        print(f"Pasajero: {apellidos}, {nombres}. DNI: {dni} ")

apellidos, nombres, dni, correo = input("Ingrese sus apellidos: "), input("Ingrese sus nombres: "), input("Ingrese su numero de DNI: "), input("Ingrese su correo electronico: ")
codigoi, codigov=codigo(), codigo()
pasaje=imprimir_el_pasaje(apellidos,nombres,dni,correo,codigoi,codigov)

print("------------------------------------------------------------------------------------")
print(f"Los pasajes seran enviados al correo: {correo}")
print("Disfrute su vuelo")
print("Gracias por su compra")
print("------------------------------------------------------------------------------------")
print("                                UTEC AEROLINEAS                                     ")








