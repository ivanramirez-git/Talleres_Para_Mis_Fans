from .entities.User import User


class ModelUser():

    @classmethod
    def login(self, db, user):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT id, username, password, email, fullname, role FROM users 
                    WHERE username = '{}'""".format(user.username)
            cursor.execute(sql)
            row = cursor.fetchone()
            if row != None:
                # Creamos el objeto usuario
                current_user = User(row[0], row[1], User.check_password(
                    row[2], user.password), row[3], row[4], row[5])
                # Creamos la sesión
                if current_user.login(db):
                    return current_user
                else:
                    return None
            else:
                return None
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def register(self, db, user):
        try:
            cursor = db.connection.cursor()
            sql = """INSERT INTO users (username, password, email, fullname, role)
                    VALUES ('{}', '{}', '{}', '{}', '{}')""".format(user.username, User.generate_password(user.password), user.email, user.fullname, user.role)
            cursor.execute(sql)
            db.connection.commit()
            return True
        except Exception as ex:
            # Si el usuario ya existe
            if ex.args[0] == 1062:
                return False
            else:
                raise Exception(ex)

    @classmethod
    def logout(self, db, user):
        try:
            return user.logout(db)
        except Exception as ex:
            raise Exception(ex)

    # Traer usuario por id

    @classmethod
    def get_user_by_id(self, db, user: User):
        if user.is_logged(db):
            try:
                cursor = db.connection.cursor()
                # Consulta que según el token del usuario, traiga el id del usuario y según el id del usuario, traiga el resto de los datos de la tabla users
                sql = """SELECT users.id, users.username, users.password, users.email, users.fullname, users.role FROM users
                        INNER JOIN sessions ON users.id = sessions.user_id
                        WHERE sessions.token = '{}' AND sessions.status = 'logged'""".format(user.auth_token['token'])
                cursor.execute(sql)
                row = cursor.fetchone()
                if row != None:
                    # Creamos el objeto usuario
                    current_user = User(
                        row[0], row[1], row[2], row[3], row[4], row[5], user.auth_token)
                    return current_user
                else:
                    return None
            except Exception as ex:
                raise Exception(ex)
        else:
            return None
