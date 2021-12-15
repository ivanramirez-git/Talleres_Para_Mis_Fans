import algoritmo
# Datos quemados para probar el sistema

nombre = "Compañia UTEC Aereolineas"

descripcion = "Sistema para gestion de ventas de pasajes de aviones"

list_vuelos = algoritmo.cargar_datos_csv()

# Estructura Vuelos
"""
    "Destino": "Arequipa",
    "D\u00eda": "Lunes",
    "Hora": "700",
    "Modelo Avion": "1",
    "Nro Vuelo": "UT0001",
    "Origen": "Lima",
    "Precio Base": "60"

"""

# Estructura Cliente
"""
Atributos:
    - Nombres
    - Apellidos
    - DNI
    - Correo
"""

list_clientes = []

# Estructura Pasaje
"""
Atributos:
    - Cliente: Cliente
    - Vuelo_Ida: Vuelo
    - Vuelo_Vuelta?: Vuelo
    - Precio_final: float
    - Fecha_compra: date
    - Fecha_salida: date
    - Fecha_regreso?: date
    - check_in?: bool
    - codigo_reserva: string
"""

list_pasajes = []

# Estructura Sistema
"""
Atríbutos:
    - nombre: string
    - descripcion: string
    - vuelos: list(Vuelo)
    - clientes: list(Cliente)
    - pasajes: list(Pasaje)
"""

datos = {
    "nombre": nombre,
    "descripcion": descripcion,
    "vuelos": list_vuelos,
    "clientes": list_clientes,
    "pasajes": list_pasajes
}


# Imprimir sistema
def imprimir_sistema():
    print("\nSistema:")
    print("\tNombre: " + datos["nombre"])
    print("\tDescripcion: " + datos["descripcion"])
    print("\nVuelos: ")
    print("\t\tOrigen\t\tDestino\t\tDia\t\tHora\t\tModelo\t\tNro Vuelo\t\tPrecio Base")
    for vuelo in datos["vuelos"]:
        print("\t\t" + vuelo["Origen"] + "\t\t" + vuelo["Destino"] + "\t\t" + vuelo["D\u00eda"] + "\t\t" + vuelo["Hora"] + "\t\t" + vuelo["Modelo Avion"] + "\t\t" + vuelo["Nro Vuelo"] + "\t\t" + vuelo["Precio Base"])
    print("\nClientes: ")
    for cliente in datos["clientes"]:
        print("\t" + str(cliente))
    print("\nPasajes: ")
    for pasaje in datos["pasajes"]:
        print("\t" + str(pasaje))
    print("\n")

# Retornar lista de Origenes
def get_list_origenes():
    list_origenes = []
    for vuelo in datos["vuelos"]:
        if vuelo["Origen"] not in list_origenes:
            list_origenes.append(vuelo["Origen"])
    return list_origenes
