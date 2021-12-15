import funciones
import sistema

# Bienvenidos a el sistema de gestion de pasajes de aviones UTEC AEREOLINEAS
print(".:: Bienvenidos a el sistema de gestion de pasajes de aviones UTEC AEREOLINEAS ::.")

# 1. Ventas
# 2. Consultas
# 3. Clientes
# 4. Salir

while True:
    print("\n1. Ventas")
    print("2. Consultas")
    print("3. Clientes")
    print("4. Salir")
    opcion = funciones.opcion("\nIngrese una opcion: ", 1, 4)
    if opcion == 1:
        # Preguntar si es solo ida o ida y vuelta
        print("\n1. Solo ida")
        print("2. ida y vuelta")
        opcion = funciones.opcion("\nIngrese una opcion: ", 1, 2)
        if opcion == 1:
            # Pedir datos de cliente
            print("\nIngrese los datos del cliente: ")
            nombre = funciones.entrada("Nombre: ")
            apellido = funciones.entrada("Apellido: ")
            dni = funciones.entrada_dni("DNI: ")
            correo = funciones.entrada_correo("Correo: ")
            # Pedir datos de vuelo
            print("\nIngrese los datos del vuelo: ")
            origenes = sistema.get_list_origenes()
            origen = funciones.opcion("Origen: ", origenes)
            destinos = sistema.get_list_destinos(origen)
            destino = funciones.opcion("Destino: ", destinos)
            fecha = funciones.entrada("Fecha (dd/mm/aaaa): ")