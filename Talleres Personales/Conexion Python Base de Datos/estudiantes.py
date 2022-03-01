# Clase estudiante
class Estudiante:
    # Constructor
    def __init__(self, nombre, apellido, sexo, edad, peso, id_primaria, telefono):
        self.nombre = nombre
        self.apellido = apellido
        self.sexo = sexo
        self.edad = edad
        self.peso = peso
        self.id_primaria = id_primaria
        self.telefono = telefono
    # Metodos
    def get_nombre(self):
        return self.nombre
    def get_apellido(self):
        return self.apellido
    def get_sexo(self):
        return self.sexo
    def get_edad(self):
        return self.edad
    def get_peso(self):
        return self.peso
    def get_id_primaria(self):
        return self.id_primaria
    def get_telefono(self):
        return self.telefono
    def set_nombre(self, nombre):
        self.nombre = nombre
    def set_apellido(self, apellido):
        self.apellido = apellido
    def set_sexo(self, sexo):
        self.sexo = sexo
    def set_edad(self, edad):
        self.edad = edad
    def set_peso(self, peso):
        self.peso = peso
    def set_id_primaria(self, id_primaria):
        self.id_primaria = id_primaria
    def set_telefono(self, telefono):
        self.telefono = telefono
    def __str__(self):
        return "Nombre: {}\nApellido: {}\nSexo: {}\nEdad: {}\nPeso: {}\nID Primaria: {}\nTelefono: {}".format(self.nombre, self.apellido, self.sexo, self.edad, self.peso, self.id_primaria, self.telefono)
