# Validar DNI, retornar true o false
def validar_dni(dni):
    if len(dni) == 8:
        if dni.isdigit():
            return True
        else:
            return False
    else:
        return False
    
# Validar correo, retornar true o false
def validar_correo(correo):
    if correo.count('@') == 1 and correo.count('.') == 1:
        return True
    else:
        return False

# Validar nombres, apellidos
def validar_nombre(nombre):
    if nombre.isalpha():
        return True
    else:
        return False

# Entrada de string
def entrada(mensaje):
    while True:
        entrada = input(mensaje)
        if entrada.isalpha():
            return entrada
        else:
            print("Opcion invalida: Por favor ingrese una opcion valida: ")

# Entrada correo
def entrada_correo(mensaje):
    while True:
        entrada = input(mensaje)
        if validar_correo(entrada):
            return entrada
        else:
            print("Opcion invalida: Por favor ingrese una opcion valida: ")

# Entrada de entero
def entrada_entero(mensaje):
    while True:
        entrada = input(mensaje)
        if entrada.isdigit():
            return int(entrada)
        else:
            print("Opcion invalida: Por favor ingrese una opcion valida: ")

# Entrada dni
def entrada_dni(mensaje):
    while True:
        entrada = input(mensaje)
        if validar_dni(entrada):
            return entrada
        else:
            print("Opcion invalida: Por favor ingrese una opcion valida: ")

# Validar entero
def validar_entero(entero):
    if entero.isdigit():
        return True
    else:
        return False

# Validar asiento
# avión modelo 1, tiene 10 filas y 6 asientos (A - F)
# avión modelo 2, tiene 20 filas y 8 asientos (A-H)
def validar_modelo(asiento, modelo):
    if modelo == 1:
        if asiento.isalpha() and len(asiento) == 2:
            if asiento[0] in ['A', 'B', 'C', 'D', 'E', 'F'] and asiento[1] in ['1', '2', '3', '4', '5', '6']:
                return True
            else:
                return False
        else:
            return False
    elif modelo == 2:
        if asiento.isalpha() and len(asiento) == 2:
            if asiento[0] in ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'] and asiento[1] in ['1', '2', '3', '4', '5', '6', '7', '8']:
                return True
            else:
                return False
        else:
            return False
    else:
        return False

# Generar un string aleatorio de 8 letras
def generar_codigo():
    import random
    import string
    return ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(8))

# Retornar el dia de la semana segun la fecha '01/01/2020'
def dia_semana(fecha):
    import datetime
    dia = datetime.datetime.strptime(fecha, '%d/%m/%Y').weekday()
    if dia == 0:
        return 'Lunes'
    elif dia == 1:
        return 'Martes'
    elif dia == 2:
        return 'Miercoles'
    elif dia == 3:
        return 'Jueves'
    elif dia == 4:
        return 'Viernes'
    elif dia == 5:
        return 'Sabado'
    elif dia == 6:
        return 'Domingo'

# Validar fecha '01/01/2020'
def validar_fecha(fecha):
    import datetime
    try:
        datetime.datetime.strptime(fecha, '%d/%m/%Y')
        return True
    except ValueError:
        return False

# Retorna la fecha de hoy
def fecha_hoy():
    import datetime
    return datetime.datetime.now().strftime('%d/%m/%Y')

# Ingresar opcion de menu
def opcion(mensaje, minimo, maximo):
    while True:
        entrada = input(mensaje)
        # Si opcion es menor que 1 o mayor que 4 es invalido
        # Si es diferente de un numero es invalido
        # Validar que sea numerico
        if entrada.isdigit() and int(entrada) > minimo-1 and int(entrada) < maximo+1:
            return int(entrada)
        else:
            print("Opcion invalida: Por favor ingrese una opcion valida: ")
