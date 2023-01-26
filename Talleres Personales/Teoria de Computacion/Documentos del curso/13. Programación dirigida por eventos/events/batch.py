def open(file, mode):
    ...


def close():
    ...


def write():
    ...


def calcular_nómina(empleado):
    ...


empleados_file = open("empleados", "r")
nómina_file = open("nómina", "w")

for empleado in empleados_file:
    nómina = calcular_nómina(empleado)
    nómina_file.write(empleado, nómina)

empleados_file.close()
nómina_file.close()
