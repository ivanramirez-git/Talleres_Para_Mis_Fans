import numpy
import pandas as pd
import openpyxl
import numpy as np
archivo = pd.read_excel("E:/UTEC/Programación 1.01/Info.xlsx") #Cambiar la ruta del archivo segun la computadora que usen
datos = list(archivo)
vuelos = pd.array(archivo)
vuelos1=[]
for a in range(len(vuelos)):
    for i in vuelos[a]:
        if i not in vuelos1:
            if i=="[" or i=="]" or i=="'":
                del i
            vuelos1.append(i)
vuelos=[]
s= " "
for i in range(len(vuelos1)):
    s = vuelos1[i]
    v = s.split("[")
    vuelos.append(v)
vuelos1=[]
for i in range(len(vuelos)):
    s = vuelos[i][1]
    v = s.split("]")
    vuelos1.append(v)
vuelos=[]
for i in range(len(vuelos1)):
    s = vuelos1[i][0]
    v = s.split("'")
    vuelos.append(v)
vuelos1=[]
for i in range(len(vuelos)):
    del vuelos[i][0]
    del vuelos[i][1]
    del vuelos[i][2]
for i in range(len(vuelos)):
    s1 = vuelos[i][5]
    del vuelos[i][5]
    s1 = s1.strip()
    vuelo=vuelos[i]
    vuelo.append(s1)
for i in range(len(vuelos)):
    s1 = vuelos[i][3]
    del vuelos[i][3]
    s1 = s1.strip()
    v = s1.split(" ")
    v1 = vuelos[i]
    v1.insert(3,v[0])
    v1.insert(4,v[1])
#print(vuelos)                                            # FILA:       1            2         3
#LO DE ARRIBA YA DA EL EXCEL EN FORMA DE MATRIZ DE ESTA MANERA: [[A,B,C,D,E],[A,B,C,D,E],[A,B,C,D,E],]
                                                        # LETRAS SON COLUMNAS DEL EXCEL
