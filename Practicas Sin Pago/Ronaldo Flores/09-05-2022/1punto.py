"""
1.- Desarrollar un programa que almacene en un arreglo el nombre de los
alumnosyen otro arreglo la calificación, que obtenga el promedio general
de todas las calificaciones,yque diga el nombre del alumno con la
calificación más alta. Si se repiten las calificaciones altas, deberá indicar
todos los alumnos con esa calificación.
"""

# Declaración de variables
alumnos = []
calificaciones = []
promedio = 0
alumno_mas_alto = ""
n = 0
alumnos_mas_altos = [] # 3 a

# Pedir al usuario que ingrese el número de alumnos
n = int(input("Ingrese el número de alumnos: "))

# Ingreso de datos
for i in range(0, n):
    alumnos.append(input("Ingrese el nombre del alumno: "))
    calificaciones.append(float(input("Ingrese la calificación del alumno: ")))


# Cálculo de promedio
for i in range(0, n):
    promedio += calificaciones[i]
promedio = promedio / n


# Cálculo del alumno con la calificación más alta
calificacion_mas_alta = 0
for i in range(0, n):
    if calificaciones[i] > calificacion_mas_alta:
        calificacion_mas_alta = calificaciones[i]
        alumno_mas_alto = alumnos[i]
        
# Impresión de resultados
print("El promedio general es: ", promedio.__round__(2))
print("El alumno con la calificación más alta es: ", alumno_mas_alto)
print("Los alumnos con la calificación más alta son: ")
for i in range(0, n):
    if calificaciones[i] == calificacion_mas_alta:
        print(alumnos[i])
print("Fin del programa")
input("\n\nPulse una tecla para finalizar...")
# Fin del programa