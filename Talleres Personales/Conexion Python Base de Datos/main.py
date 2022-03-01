from estudiantes import Estudiante
from conexion import Conexion

# Menu
def menu():
    print("\n\t\t\tMENU")
    print("1. Agregar estudiante")
    print("2. Buscar estudiante")
    print("3. Eliminar estudiante")
    print("4. Actualizar estudiante")
    print("5. Listar estudiantes")
    print("0. Salir")
    opcion = int(input("\nIngrese una opcion: "))
    return opcion

# Agregar estudiante
def agregar():
    # Pedir datos
    nombre = input("\nIngrese el nombre: ")
    apellido = input("Ingrese el apellido: ")
    sexo = input("Ingrese el sexo (M/F): ")
    edad = int(input("Ingrese la edad: "))
    peso = int(input("Ingrese el peso: "))
    id_primaria = input("Ingrese el ID primaria: ")
    telefono = input("Ingrese el telefono: ")
    estudiante = Estudiante(nombre, apellido, sexo, edad,
                            peso, id_primaria, telefono)
    return estudiante

# Buscar estudiante
def buscar():
    # Pedir datos
    nombre = input("\nIngrese el nombre: ")
    return nombre

# Eliminar estudiante
def eliminar():
    # Pedir datos
    id = input("\nIngrese el ID: ")
    # Confirmar eliminacion
    confirmacion = input(
        "\nEsta seguro que desea eliminar el estudiante? (S/N): ")
    if confirmacion == "S":
        # Eliminar estudiante
        estudiante = Estudiante("", "", "", 0, 0, id, "")
        return estudiante
    else:
        return None

# Actualizar estudiante
def actualizar():
    # Pedir datos
    id_primaria = input("\nIngrese el ID primaria: ")
    # Pedir nuevos datos
    nombre = input("\nIngrese el nuevo nombre: ")
    apellido = input("Ingrese el nuevo apellido: ")
    sexo = input("Ingrese el nuevo sexo (M/F): ")
    edad = int(input("Ingrese la nueva edad: "))
    peso = int(input("Ingrese el nuevo peso: "))
    telefono = input("Ingrese el nuevo telefono: ")
    # Actualizar datos
    estudiante = Estudiante(nombre, apellido, sexo, edad,
                            peso, id_primaria, telefono)
    return estudiante

# Progran principal
def main():
    # Crear objeto conexion
    conexion = Conexion()
    # Opcion
    opcion = -1
    # Ciclo
    while opcion != 0:
        # Menu
        opcion = menu()
        if opcion == 1:
            # Titulo
            print("\n\t\t\tAGREGAR ESTUDIANTE")
            # Agregar estudiante
            estudiante = agregar()
            # Insertar datos en la tabla estudiantes
            conexion.insertar(estudiante)
        elif opcion == 2:
            # Titulo
            print("\n\t\t\tBUSCAR ESTUDIANTE")
            # Buscar estudiante
            nombre = buscar()
            # Buscar estudiante
            estudiante = conexion.buscarNombre(nombre)
            # Mostrar datos
            print("\nNombre, Apellido, Sexo, Edad, Peso, ID primaria, Telefono")
            print(estudiante)
        elif opcion == 3:
            # Titulo
            print("\n\t\t\tELIMINAR ESTUDIANTE")
            # Eliminar estudiante
            nombre = eliminar()
            # Eliminar estudiante
            if nombre != None:
                conexion.eliminar(nombre)
        elif opcion == 4:
            # Titulo
            print("\n\t\t\tACTUALIZAR ESTUDIANTE")
            # Actualizar estudiante
            estudiante = actualizar()
            # Actualizar estudiante
            conexion.actualizar(estudiante)
        elif opcion == 5:
            # Titulo
            print("\n\t\t\tLISTAR ESTUDIANTES")
            # Listar estudiantes
            lista = conexion.listar()            
            print("\nNombre, Apellido, Sexo, Edad, Peso, ID primaria, Telefono")
            for estudiante in lista:
                print(estudiante)

        elif opcion == 0:
            print("\n\t\t\tSALIR")
        else:
            print("\n\t\t\tOPCION INCORRECTA")

main()
