"""

Categoria   SUELDO BASICO (SB)  PAGO POR HORA EXTRA (PHX)
    a               3000.00             4
    b               2500.00             3
    c               2000.00             2
PH = (SB / 240 hrs)

"""


class Trabajador:
    def __init__(self, nombre, categoria, horas_extra, tardanza_minutos):
        self.nombre = nombre
        self.categoria = categoria
        self.horas_extra = horas_extra
        self.tardanza_minutos = tardanza_minutos

    def calcular_sueldo_basico(self):
        if self.categoria == "A":
            return 3000
        elif self.categoria == "B":
            return 2500
        elif self.categoria == "C":
            return 2000
        else:
            return 0
    
    def calcular_descuento_tardanza(self):
        if self.tardanza_minutos > 0:
            return ((self.tardanza_minutos / 60) * (self.calcular_sueldo_basico() / 240)).__round__(2)
        else:
            return 0

    def calcular_pago_horas_extra(self):
        return (self.calcular_sueldo_basico() / 240 * self.horas_extra).__round__(2)

    def calcular_sueldo_neto(self):
        return (self.calcular_sueldo_basico() + self.calcular_pago_horas_extra() - self.calcular_descuento_tardanza()).__round__(2)
        
class Boleta:
    def __init__(self, trabajador):
        self.trabajador = trabajador

    def imprimir_boleta(self):
        print("*** BOLETA DE PAGO ***")
        print("NOMBRE:                  ", self.trabajador.nombre)
        print("CATEGORIA:               ", self.trabajador.categoria)
        print("SUELDO BASICO:           ", self.trabajador.calcular_sueldo_basico())
        print("DESCUENTO TARDANZA:      ", self.trabajador.calcular_descuento_tardanza())
        print("PAGO HORAS EXTRA:        ", self.trabajador.calcular_pago_horas_extra())
        print("SUELDO NETO:             ", self.trabajador.calcular_sueldo_neto())


print("*** DATOS DE ENTRADA ***")
nombre =                    input("TRABAJADOR:                  ")
categoria =                 input("CATEGORIA:                   ")
horas_extra = int(          input("HORAS EXTRA:                 "))
tardanza_minutos = int(     input("TARDANZA: (minutos)          "))
t = Trabajador(nombre, categoria, horas_extra, tardanza_minutos)
b = Boleta(t)
b.imprimir_boleta()