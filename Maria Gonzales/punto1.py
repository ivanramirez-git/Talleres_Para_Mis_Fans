import requests
import json

def getCountry(countryCode):
    url = "https://restcountries.com/v3/alpha/" + countryCode
    response = requests.get(url)
    if response.status_code == 200:
        return json.loads(response.content.decode("utf-8"))[0]["name"]["official"]
    else:
        return None


def ordenarDiccionario(diccionario):
    resultado = {}
    # Ordena los platos por cantidad de comensales
    for plato in sorted(diccionario, key=lambda x: len(diccionario[x]), reverse=False):
        resultado[plato] = diccionario[plato]
    return resultado
