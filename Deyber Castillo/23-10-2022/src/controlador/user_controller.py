from modelo.user import User # Importar la clase User


class UserController(): # Clase para el modelo de usuario

    @classmethod # Método de clase
    def login(self, db, user: User): # Iniciar sesión
        try: # Intentar
            cursor = db.connection.cursor() # Crear el cursor
            sql = """SELECT id, username, password, email, fullname, role FROM users WHERE username = '{}'""".format(user.username) # Query para obtener los datos del usuario con el nombre de username ingresado
            cursor.execute(sql) # Ejecutar el query
            row = cursor.fetchone() # Obtener la fila
            if row != None: # Si la fila no está vacía osea si existe un username igual al que se ingresó
                # Creamos el objeto usuario
                current_user = User(row[0], row[1], User.check_password(row[2], user.password), row[3], row[4], row[5]) # Crear el objeto usuario, se hace uso de la función check_password para comparar la contraseña ingresada con la contraseña encriptada en la base de datos
                # Creamos la sesión
                if current_user.login(db): # Si el usuario existe y la contraseña es correcta
                    return current_user # Devolver el objeto usuario
                else: # Si la contraseña es incorrecta
                    return None # Devolver None
            else: # Si el usuario no existe
                return None # Devolver None
        except Exception as ex: # Si ocurre un error
            raise Exception(ex) # Lanzar la excepción

    @classmethod # Método de clase
    def register(cls, db, user: User): # Registrar usuario
        try: # Intentar
            cursor = db.connection.cursor() # Crear el cursor
            sql = """INSERT INTO users (username, password, email, fullname, role) VALUES ('{}', '{}', '{}', '{}', '{}')""".format(user.username, User.generate_password(user.password), user.email, user.fullname, user.role) # Query para insertar un nuevo usuario
            cursor.execute(sql) # Ejecutar el query
            db.connection.commit() # Hacer commit a la base de datos
            return True # Devolver True
        except Exception as ex: # Si ocurre un error
            # Si el usuario ya existe
            if ex.args[0] == 1062: # Si el error es por duplicado
                return False # Devolver False
            else: # Si el error es por otro motivo
                raise Exception(ex) # Lanzar la excepción

    @classmethod
    def logout(cls, db, user: User): # Cerrar sesión
        try: # Intentar
            return user.logout(db) # Devolver el resultado de la función logout del objeto usuario
        except Exception as ex: # Si ocurre un error
            raise Exception(ex) # Lanzar la excepción

    # Traer usuario por id
    @classmethod # Método de clase
    def get_user_by_id(cls, db, user: User): # Traer usuario por id
        if user.is_logged(db): # Si el usuario está logueado
            try: # Intentar
                cursor = db.connection.cursor() # Crear el cursor
                # Consulta que según el token del usuario, traiga el id del usuario y según el id del usuario, traiga el resto de los datos de la tabla users
                sql = """SELECT users.id, users.username, users.password, users.email, users.fullname, users.role FROM users INNER JOIN sessions ON users.id = sessions.user_id WHERE sessions.token = '{}' AND sessions.status = 'logged'""".format(user.auth_token['token']) # Query para obtener los datos del usuario con el id del usuario
                cursor.execute(sql) # Ejecutar el query
                row = cursor.fetchone() # Obtener la fila
                if row != None: # Si la fila no está vacía osea si existe un usuario con el id ingresado
                    # Creamos el objeto usuario
                    current_user = User(row[0], row[1], row[2], row[3], row[4], row[5], user.auth_token) # Crear el objeto usuario
                    return current_user # Devolver el objeto usuario
                else: # Si el usuario no existe
                    return None # Devolver None
            except Exception as ex: # Si ocurre un error
                raise Exception(ex) # Lanzar la excepción
        else: # Si el usuario no está logueado
            return None # Devolver None


# Abstract class
# Name: ModelUser
# Attributes: None
# Methods: