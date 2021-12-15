import datetime
import calendar
import string
import random
def dia(fecha):
    day, month, year = (int(i) for i in fecha.split('/'))
    dayNumber = calendar.weekday(year, month, day)
    days = ["Lunes", "Martes", "Miercoles", "Jueves",
            "Viernes", "Sabado", "Domingo"]
    return (days[dayNumber])

def matriz(a=[]):
    for i in a:
        b = print(i, end="\n")
        if i==None:
            print("")
    return b

def codigo(size=8, chars=string.ascii_uppercase):
    return ''.join(random.choice(chars) for _ in range(size))


"""def hacer_check_in(estado):
    codigor=input("Escriba su codigo de reserva: ")
    if estado==False:
        c=int(input("Para hacer el check-in haga click en 1."))
        print("Check-in hecho")
        estado=True
    else:
        print("El check-in ya estaba hecho.")
    return estado
estado=hacer_check_in(estado)
def ver_estado_vuelo(estado):
    if estado==False:
        print("NO CHECKEADO")
    else:
        print("CHECKEADO")"""