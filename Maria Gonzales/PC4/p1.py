# Evalua diccionarios

def evaluaDiccionarios(mobiles):
    resultado = {}
    for key in mobiles:
        if mobiles[key][" Company "] not in resultado:
            resultado[mobiles[key][" Company "]] = { " quantity ": 1 , " average ": mobiles[key][" price "]}
        else:
            resultado[mobiles[key][" Company "]][" quantity "] += 1
            resultado[mobiles[key][" Company "]][" average "] += mobiles[key][" price "]
    for key in resultado:
        resultado[key][" average "] = resultado[key][" average "]/resultado[key][" quantity "]
    return resultado
"""
mobiles = {
    1: { " Company ": " iphone " , " model ": " XR " , " OS ": " IOS " ," price " :4000},
    2: { " Company " : " Samsung " , " model ": " Note ␣ 10 " , " OS ": " Android " , " price " :3000},
    3: { " Company ": " Samsung " , " model ": " Galaxy ␣ S20 ","OS " : " Android " , " price " :3500},
    4: { " Company ": " Samsung " , " model ": " Galaxy ␣ S21 ","OS " : " Android " , " price " :4000},
    5: { " Company ": " iphone " , " model ": " XR " , " OS ": " IOS " ," price " :8000},
}

resultado = {
    " iphone ": { " quantity ": 1 , " average ": 4000.0},
    " Samsung ": { " quantity ": 3 , " average ": 3500.0}
}

resultado = evaluaDiccionarios(mobiles)
print(resultado)
"""