from flask_login import UserMixin # UserMixin es una clase que nos permite usar las funciones de login de flask
import datetime # Para poder usar la fecha actual
from werkzeug.security import check_password_hash, generate_password_hash # Para poder encriptar la contraseña
import jwt # Para poder generar el tokens de autenticación

# importar src\config.py
from config import Config # Importar la configuración de la secret key


class User(UserMixin): # Heredar de UserMixin para poder usar las funciones de login de flask
    def __init__(self, id, username, password, email, fullname, role='user', auth_token=None): # Constructor
        self.id = id # id del usuario   
        self.username = username  # Nombre de usuario
        self.password = password # Contraseña
        self.email = email # Email
        self.fullname = fullname # Nombre completo
        self.role = role # Rol del usuario
        self.auth_token = auth_token # Token de autenticación

    # toStr

    def __str__(self): # Función para imprimir el objeto
        return str(self.__dict__) # Imprimir el diccionario del objeto

    @classmethod # Método de clase
    def check_password(self, hashed_password, password): # Comprobar la contraseña
        return check_password_hash(hashed_password, password) # Comprobar la contraseña

    @classmethod # Método de clase
    def generate_password(self, password): # Generar la contraseña
        return generate_password_hash(password) # Generar la contraseña

    @classmethod # Método de clase
    def generate_jwt_token(self, id, username, role): # Generar el token de autenticación
        payload = { # Payload del token
            'id': id, # id del usuario
            # Duración de la sesión 
            'exp': datetime.datetime.now() + datetime.timedelta(days=1), # Fecha de expiración del token durante 1 día
            'iat': datetime.datetime.now(), # Fecha de creación del token es la fecha actual
            'sub': username, # Nombre de usuario
            'role': role # Rol del usuario
        }
        token = jwt.encode(payload, Config.SECRET_KEY, algorithm='HS256') # Generar el token
        return {'token': token, 'created_at': payload['iat'], 'expires_at': payload['exp']} # Devolver el objeto que contiene el token de autenticación

    def login(self, db): # Iniciar sesión
        if self.password is True: # Comprobar si la contraseña es correcta
            try: # Intentar
                self.auth_token = User.generate_jwt_token(self.id, self.username, self.role)  # Generar el token de autenticación
                cursor = db.connection.cursor() # Crear el cursor
                sql_session = """INSERT INTO sessions (user_id, token, created_at, expired_at, status) VALUES ({}, '{}', '{}', '{}', '{}')""".format(self.id, self.auth_token['token'], self.auth_token['created_at'], self.auth_token['expires_at'], 'logged') # Sentencia SQL para insertar la sesión
                cursor.execute(sql_session) # Ejecutar la sentencia SQL
                db.connection.commit() # Hacer commit de la transacción
                return True # Devolver True porque todo ha ido bien
            except Exception as ex: # Si ha habido algún error
                raise Exception(ex) # Lanzar la excepción
        else: # Si la contraseña no es correcta
            return False # Devolver False porque la contraseña no es correcta

    def logout(self, db): # Cerrar sesión
        cursor = db.connection.cursor() # Crear el cursor
        cursor.callproc('change_status_expired_session') # Llamar el procedimiento almacenado change_status_expired_session
        cursor.fetchall() # Obtener los resultados
        sql_session = """SELECT id FROM sessions WHERE user_id = {} AND token = '{}' AND status = 'logged'""".format(self.id, self.auth_token['token']) # Sentencia SQL para obtener la sesión
        cursor.execute(sql_session) # Ejecutar la sentencia SQL
        row = cursor.fetchone() # Obtener el resultado
        if row != None: # Si la sesión existe
            sql_session = """UPDATE sessions SET expired_at = '{}', status = '{}' WHERE id = {}""".format(datetime.datetime.now(), 'logout', row[0]) # Sentencia SQL para actualizar la sesión
            cursor.execute(sql_session) # Ejecutar la sentencia SQL
            db.connection.commit() # Hacer commit de la transacción
            return {'status': 'logout', 'message': 'Sesión cerrada correctamente'} # Devolver el objeto que contiene el estado de la sesión y el mensaje
        else:
            return {'status': 'session not found', 'message': 'No se ha encontrado la sesión activa'} # Devolver el objeto que contiene el estado de la sesión y el mensaje

    # Da el estado de la sesion
    @classmethod # Método de clase
    def status_sesion(self, db, token): # Comprobar el estado de la sesión
        cursor = db.connection.cursor() # Crear el cursor
        cursor.callproc('change_status_expired_session') # Llamar el procedimiento almacenado change_status_expired_session
        cursor.fetchall() # Obtener los resultados
        sql_session = """SELECT * FROM sessions WHERE token = '{}'""".format(token) # Sentencia SQL para obtener la sesión
        cursor.execute(sql_session) # Ejecutar la sentencia SQL
        row = cursor.fetchone() # Obtener el resultado
        if row != None: # Si la sesión existe
            # Comprobar si la sesión está activa
            if row[5] == 'logged': # Si la sesión está activa
                return {'status': 'logged', 'message': 'Sesión activa'} # Devolver el objeto que contiene el estado de la sesión y el mensaje
            elif row[5] == 'expired': # Si la sesión está caducada
                return {'status': 'expired', 'message': 'Sesión caducada'} # Devolver el objeto que contiene el estado de la sesión y el mensaje
            else: # Si la sesión está cerrada
                return {'status': 'logout', 'message': 'Sesión cerrada'} # Devolver el objeto que contiene el estado de la sesión y el mensaje
        else: # Si la sesión no existe
            return {'status': 'session not found', 'message': 'No se ha encontrado la sesión, inicie sesión'} # Devolver el objeto que contiene el estado de la sesión y el mensaje

    # is_admin
    @classmethod # Método de clase
    def is_admin_service(self, db, token): # Comprobar si el usuario es administrador
        cursor = db.connection.cursor() # Crear el cursor
        # llamar el procedimiento almacenado change_status_expired_session
        cursor.callproc('change_status_expired_session') # Llamar el procedimiento almacenado change_status_expired_session
        cursor.fetchall() # Obtener los resultados

        sql_one_query = """SELECT * FROM sessions INNER JOIN users ON sessions.user_id = users.id WHERE sessions.token = '{}'""".format(token) # Sentencia SQL para obtener la sesión
        cursor.execute(sql_one_query) # Ejecutar la sentencia SQL
        row = cursor.fetchone() # Obtener el resultado
        # Imprimir toda la fila
        # print(row) # Imprimir toda la fila
        if row != None: # Si la sesión existe
            # Comprobar si la sesión está activa
            if row[5] == 'logged' and row[7] == 'admin': # Si la sesión está activa y el usuario es administrador
                return True # Devolver True porque el usuario es administrador
            else: # Si la sesión está caducada o el usuario no es administrador
                return False # Devolver False porque el usuario no es administrador
        else: # Si la sesión no existe
            return False # Devolver False porque el usuario no es administrador

    # Comprueba si el usuario está logueado
    def is_logged(self, db): # Comprobar si el usuario está logueado
        if self.status_sesion(db, self.auth_token['token'])['status'] == 'logged': # Comprobar si la sesión está activa
            # Print de prueba
            # print('Sesión activa') # Imprimir el mensaje
            return True # Devolver True porque la sesión está activa
        else: # Si la sesión no está activa
            return False # Devolver False porque la sesión no está activa

    # Comprueba si el usuario está logueado y es administrador
    def is_admin(self, db): # Comprobar si el usuario está logueado y es administrador
        if self.is_logged(db) and self.is_admin_service(db, self.auth_token['token']): # Comprobar si la sesión está activa y es administrador
            return True # Devolver True porque la sesión está activa y es administrador
        else: # Si la sesión no está activa o no es administrador
            return False # Devolver False porque la sesión no está activa o no es administrador


# Abstract User class
# Name: User
# Attributes:
"""
+ id: int
+ username: str
+ password: str
+ fullname: str
+ email: str
+ role: str
+ auth_token: str
"""
# Methods:
"""
+ login(self, db)
+ logout(self, db)
+ status_sesion(self, db, token)
+ is_admin_service(self, db, token)
+ is_logged(self, db)
+ is_admin(self, db)
"""
