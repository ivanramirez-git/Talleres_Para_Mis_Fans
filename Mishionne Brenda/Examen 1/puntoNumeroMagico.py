#Leer la fecha
print("Introduzca una fecha en formato DD/MM/AAAA")
dia = int(input("Dia: "))
mes = int(input("Mes: "))
anio = int(input("Año: "))

#Calcular el número mágico
suma = dia + mes + anio

while suma > 10:
    print(suma)
    suma = suma // 10 + suma % 10

print("El número mágico es: ", suma)
