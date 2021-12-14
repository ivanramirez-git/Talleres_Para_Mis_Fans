# Para funcionamiento escribir en consola:
# pip install requests
# python3 solucion.py

import requests
import json

def getCountry(countryCode):
    url = "https://restcountries.com/v3/alpha/" + countryCode
    response = requests.get(url)
    if response.status_code == 200:
        return json.loads(response.content.decode("utf-8"))[0]["name"]["official"]
    else:
        return None


def darPlatosOrdenados(diccionario):
    resultado = {}
    # Ordena los platos por cantidad de comensales
    for plato in sorted(diccionario, key=lambda x: len(diccionario[x]), reverse=False):
        resultado[plato] = diccionario[plato]
    return resultado

# Programa principal
diccionario = {'Lomo saltado':['Kevin','Fernando','Kathia'],
                'Arroz chaufa':['Alessandra'],
                'Causa':['Mateo','Camila']}

#resultado = {'Arroz chaufa':['Alessandra'],
#                'Causa':['Mateo','Camila'],
#                'Lomo saltado':['Kevin','Fernando','Kathia']}

# 1. Pedir el codigo de pais
# 3. Ordenar un diccionario de clave platos tipicos y valor una lista de nombres de personas que comen ese plato

# Menu
while True:
    print("1. Nombre oficical del pais")
    print("3. Ver platos ordenados por numero de comensales")
    print("4. Salir")
    opcion = input("Ingrese una opcion: ")
    if opcion == "1":
        countryCode = input("Ingrese el codigo de pais: ")
        country = getCountry(countryCode)
        if country is None:
            print("No se encontro el pais")
        else:
            print("El pais es: ", country)
    elif opcion == "3":
        print(darPlatosOrdenados(diccionario))
    elif opcion == "4":
        break
    else:
        print("Opcion invalida")
