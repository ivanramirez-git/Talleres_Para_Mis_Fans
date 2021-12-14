# Declarar una clase llamada Empleado que hereda de la clase Persona y agrega el atributo sueldo.
# Debe mostrar si tiene que pagar o no impuestos (sueldo superior a 3000).

class Persona:
    def __init__(self, nombre, apellido, dni):
        self.nombre = nombre
        self.apellido = apellido
        self.dni = dni

    def __str__(self):
        return "{} {}".format(self.nombre, self.apellido)


class Empleado(Persona):
    def __init__(self, nombre, apellido, dni, sueldo):
        super().__init__(nombre, apellido, dni)
        self.sueldo = sueldo

    def impuesto(self):
        if self.sueldo > 3000:
            return "Tiene que pagar impuestos"
        else:
            return "No tiene que pagar impuestos"


empleado = Empleado("Mauro", "Peredo", "12345678", 5000)
print(empleado)
print(empleado.impuesto())

empleado2 = Empleado("Mauro", "Guaman", "98765432", 2500)
print(empleado2)
print(empleado2.impuesto())

