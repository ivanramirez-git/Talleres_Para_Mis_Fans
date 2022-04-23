"""
Se requiere que diseñe su propia función hash con las operaciones y criterios que usted decida empleando como
referencia las funciones hash por plegamiento y la función hash por truncamiento. Deberá programar en el
lenguaje python esta función hash utilizando como claves de entrada las siguientes:
15515321
33598192
26901527
Deberá devolver 3 digitos.
En un comentario dentro del programa deberá indicar el procedimiento de calculo que ud eligió.
"""

# Funcion hash por plegamiento
from xml.etree.ElementTree import tostring


def hash_plegamiento(clave):
    clave = int(clave)
    while not (clave > 99 and clave < 1000):
        digito = clave % 10
        clave /= 10
        clave += digito
    return int(clave)

# Funcion hash por truncamiento
def hash_truncamiento(clave):    
    tam = len(clave)
    clave = int(clave)
    retorno = 0
    while not (retorno > 99 and retorno < 1000):
        digito = clave % 10
        clave /= 10
        tam-=1
        # Aleatorio entre 0 y 1
        import random
        if random.randint(0, 1) == 0:
            retorno += digito
            retorno *= 10
        if tam == 0:
            clave = retorno                
            # tam es igual al numero de digitos de la clave
            tam = 3
            print("Cate")

    return int(retorno)

# Priebas
def prueba1():
    """
    Funcion principal
    :return:
    """
    print("Plegamiento (15515321):", hash_plegamiento("15515321"))
    print("Plegamiento (33598192):", hash_plegamiento("33598192"))
    print("Plegamiento (26901527):", hash_plegamiento("26901527"))

    print("Truncamiento (15515321):", hash_truncamiento("15515321"))
    print("Truncamiento (33598192):", hash_truncamiento("33598192"))
    print("Truncamiento (26901527):", hash_truncamiento("26901527"))


# Funcion principal
def main():
    """
    Funcion principal
    :return:
    """
    prueba1()


# Llamada a la funcion principal
main()
