
# Importar librerias
import mysql.connector # Libreria para conectar con MySQL
"""
    1	Nombre	varchar(50)
    2	Apellido	varchar(50)
    3	Sexo	varchar(1)
    4	Edad	int(11)
    5	Peso	int(11)
    6	ID Primaria	varchar(15)
    7	Telefono	varchar(15)	
    localhost:3306/estudiantes
    user:root
    pass:
"""
# Clase conexion con la base de datos estudiantes
class Conexion:
    # Constructor
    def __init__(self):
        self.conexion = mysql.connector.connect(
            host="localhost",
            user="root",
            passwd="",
            database="ejercicio"
        )
        self.cursor = self.conexion.cursor()
    # Metodos

    def insertar(self, estudiante):
        # Insertar datos en la tabla estudiantes
        self.cursor.execute(
            "INSERT INTO estudiantes (nombre, apellido, sexo, edad, peso, ID, telefono) VALUES (%s, %s, %s, %s, %s, %s, %s)",
            (estudiante.get_nombre(), estudiante.get_apellido(), estudiante.get_sexo(), estudiante.get_edad(
            ), estudiante.get_peso(), estudiante.get_id_primaria(), estudiante.get_telefono())
        )
        # Guardar los cambios
        self.conexion.commit() # Guardar los cambios en la base de datos

    def listar(self):
        # Consultar datos de la tabla estudiantes
        self.cursor.execute("SELECT * FROM estudiantes")
        # Guardar los datos en una lista
        datos = self.cursor.fetchall()
        # Listar los datos
        return datos

    def buscarNombre(self, nombre):
        # Consultar datos de la tabla estudiantes
        self.cursor.execute("SELECT * FROM estudiantes WHERE nombre = %s", (nombre,))
        # Guardar los datos en una lista
        datos = self.cursor.fetchall()
        # Retornar los datos
        return datos

    def buscar(self, id_primaria):
        # Consultar datos de la tabla estudiantes
        self.cursor.execute("SELECT * FROM estudiantes WHERE ID = %s", (id_primaria,))
        # Guardar los datos en una lista
        datos = self.cursor.fetchall()
        # Retornar los datos
        return datos

    def actualizar(self, estudiante):
        # Actualizar datos de la tabla estudiantes
        self.cursor.execute(
            "UPDATE estudiantes SET nombre = %s, apellido = %s, sexo = %s, edad = %s, peso = %s, ID = %s, telefono = %s WHERE ID = %s",
            (estudiante.get_nombre(), estudiante.get_apellido(), estudiante.get_sexo(), estudiante.get_edad(
            ), estudiante.get_peso(), estudiante.get_id_primaria(), estudiante.get_telefono(), estudiante.get_id_primaria())
        )
        # Guardar los cambios
        self.conexion.commit()

    def eliminar(self, estudiante):
        # Eliminar datos de la tabla estudiantes
        self.cursor.execute(
            "DELETE FROM estudiantes WHERE ID = %s",
            (estudiante.get_id_primaria(),)
        )
        # Guardar los cambios
        self.conexion.commit()

    def __del__(self):
        # Cerrar la conexion
        self.conexion.close()
