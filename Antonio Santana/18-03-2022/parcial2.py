
"""
El programa deberá crear un Menu que tenga lo siguiente: 
    1)	Crear un estudiante con nombre, apellido, cedula. Estos estarán en un diccionario donde la llave será la cedula (int), y los valores serán dos STRs nombre y apellido, y el tercer valor será una lista con las notas que podrán agregar en el siguiente literal 
    2)	Agregar/Modificar notas a usuarios nota 1P y nota 2P y notas adicionales en caso de ser necesarias (Mejoramiento o Recuperación) Aplicar todas las reglas que tuvimos en cuenta en el primer parcial. 
    3)	Imprimir registro de notas: 
    a. Si Hay alumnos que no tengas sus notas enlistarlos al final 
    4)	Eliminar estudiantes con la cedula. Si ingresan una cedula que no existe deberán decirle al usuario que no se encontró la cedula. 
    5)	Salir. 
"""

from select import select


estudiante = {
    "cedula": "",
    "nombre": "",
    "apellido": "",
    "notas": []
}

estudiantes = []

def crear_estudiante():
    estudiante["cedula"] = int(input("Ingrese la cedula: "))
    # Verificar si la cedula ya existe
    if estudiante["cedula"] in estudiantes:
        print("La cedula ya existe")
        return 0
    estudiante["nombre"] = input("Ingrese el nombre: ")
    estudiante["apellido"] = input("Ingrese el apellido: ")
    estudiante["notas"] = [0, 0, 0, 0]
    estudiantes.append(estudiante.copy())

def agregar_notas():
    cedula = int(input("Ingrese la cedula: "))
    # Verificar si la cedula no existe
    existe = False
    for estudiante in estudiantes:
        if estudiante["cedula"] == cedula:
            existe = True
            break
    if not existe:
        print("No se encontró la cedula")
        return 0

    nota1p = float(input("Ingrese la nota 1P: ")) 
    nota2p = float(input("Ingrese la nota 2P: "))
    nota_mejoramiento = 0
    nota_recuperacion = 0
    # Notas adicionales (Mejoramiento o Recuperacion)
    print("Desea agregar nota de Mejoramiento (S/N)? ")
    opcion = input()
    if opcion == "S" or opcion == "s":
        nota_mejoramiento = float(input("Ingrese la nota de Mejoramiento: "))
    print("Desea agregar nota de Recuperacion (S/N)? ")
    opcion = input()
    if opcion == "S" or opcion == "s":
        nota_recuperacion = float(input("Ingrese la nota de Recuperacion: "))

    # Agregar notas
    estudiante["notas"] = [nota1p, nota2p, nota_mejoramiento, nota_recuperacion]

def imprimir_registro():
    print("Registro de notas")
    estudiantesConNota = []
    estudiantesSinNota = []
    for estudiante in estudiantes:
        # Verificar si el estudiante no tiene notas
        if estudiante["notas"] == [0, 0, 0, 0]:
            estudiantesSinNota.append(estudiante)
        else:
            estudiantesConNota.append(estudiante)
    # Imprimir tabla de estudiantes con notas
    print("Cedula\tNombre\tApellido Nota 1P\tNota 2P\tMejoramiento\tRecuperacion")
    for estudiante in estudiantesConNota:
        print(estudiante["cedula"], "\t", estudiante["nombre"], "\t", estudiante["apellido"], "\t", estudiante["notas"][0], "\t", estudiante["notas"][1], "\t", estudiante["notas"][2], "\t", estudiante["notas"][3])
    # Imprimir tabla de estudiantes sin notas
    for estudiante in estudiantesSinNota:
        print(estudiante["cedula"], "\t", estudiante["nombre"], "\t", estudiante["apellido"], "\t", estudiante["notas"][0], "\t", estudiante["notas"][1], "\t", estudiante["notas"][2], "\t", estudiante["notas"][3])



def eliminar_estudiante():
    cedula = int(input("Ingrese la cedula: "))
    # Verificar si la cedula no existe
    existe = False
    for estudiante in estudiantes:
        if estudiante["cedula"] == cedula:
            existe = True
            break
    if not existe:
        print("No se encontró la cedula")
        return 0
    # Eliminar estudiante
    estudiantes.remove(estudiante)


def menu():
    opcion = 0
    while opcion != 5:
        print("1) Crear estudiante")
        print("2) Agregar notas")
        print("3) Imprimir registro de notas")
        print("4) Eliminar estudiante")
        print("5) Salir")
        opcion = int(input("Ingrese una opcion: "))
        if opcion == 1:
            crear_estudiante()
        elif opcion == 2:
            agregar_notas()
        elif opcion == 3:
            imprimir_registro()
        elif opcion == 4:
            eliminar_estudiante()
        elif opcion == 5:
            print("Gracias por usar el programa")
            return 0
        else:
            print("Ingrese una opcion valida")

# Main
menu()