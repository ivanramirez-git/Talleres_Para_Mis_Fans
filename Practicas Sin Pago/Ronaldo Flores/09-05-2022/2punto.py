# funcion para ordenar la lista
def ordenar_lista(lista):
    # Caso base
    if len(lista) <= 1:
        return lista
    # Caso recursivo
    else:
        return ordenar_lista(
            [x for x in lista[1:] if x['numero'] < lista[0]['numero']]
        ) + [lista[0]] + ordenar_lista(
            [x for x in lista[1:] if x['numero'] >= lista[0]['numero']]
        )
        

# funcion para buscar el numero ganador
def buscar_ganador(lista, numero):
    # Caso base
    if len(lista) == 0:
        return False
    # Caso recursivo
    else:
        if lista[0]['numero'] == numero:
            print(lista[0])
            return True
        else:
            return buscar_ganador(lista[1:], numero)

"""
2.- La lotería de Mundo Rico registra los números de los billetes vendidos
 yel lugar dónde se vendió, en orden ascendente. En el momento de jugar
la lotería, al conocer el número ganador se requiere conocer
inmediatamente en qué lugar fue vendido. Diseñar un algoritmo para
realizar esta consulta. (Utilizar la búsqueda binaria)
"""

# Declaración de variables
numero_ganador = int(input("Introduce el número ganador: "))
loteria = [
    {
        'numero': 1,
        'lugar': 'jalisco'
    },
    {
        'numero': 2,
        'lugar': 'cdmx'
    },
    {
        'numero': 3,
        'lugar': 'guanajuato'
    },
    {
        'numero': 4,
        'lugar': 'bogota'
    },
    {
        'numero': 12,
        'lugar': 'medellin'
    },
    {
        'numero': 6,
        'lugar': 'cali'
    },
    {
        'numero': 7,
        'lugar': 'queretaro'
    },
    {
        'numero': 8,
        'lugar': 'monterrey'
    },
    {
        'numero': 9,
        'lugar': 'puebla'
    },
    {
        'numero': 11,
        'lugar': 'sinaloa'
    },
    {
        'numero': 10,
        'lugar': 'mexico'
    }
]
# Se ordena la lista
loteria = ordenar_lista(loteria)
# Se busca el numero ganador
buscar_ganador(loteria, numero_ganador)