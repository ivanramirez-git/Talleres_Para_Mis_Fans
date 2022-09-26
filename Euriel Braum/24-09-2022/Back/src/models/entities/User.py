from flask_login import UserMixin
import datetime
from werkzeug.security import check_password_hash, generate_password_hash
import jwt

# importar src\config.py
from config import Config


class User(UserMixin):
    def __init__(self, id, username, password, email, fullname, role, auth_token=None):
        self.id = id
        self.username = username
        self.password = password
        self.email = email
        self.fullname = fullname
        self.role = role
        self.auth_token = auth_token

    @classmethod
    def check_password(self, hashed_password, password):
        return check_password_hash(hashed_password, password)

    @classmethod
    def generate_password(self, password):
        return generate_password_hash(password)

    @classmethod
    def generate_jwt_token(self, id, username, role):
        payload = {
            'id': id,
            'exp': datetime.datetime.now() + datetime.timedelta(minutes=1),
            'iat': datetime.datetime.now(),
            'sub': username,
            'role': role
        }
        token = jwt.encode(payload, Config.SECRET_KEY,
                           algorithm='HS256')
        return {'token': token, 'created_at': payload['iat'], 'expires_at': payload['exp']}

    def login(self, db):
        if self.password is True:
            try:
                self.auth_token = User.generate_jwt_token(
                    self.id, self.username, self.role)
                cursor = db.connection.cursor()
                sql_session = """INSERT INTO sessions (user_id, token, created_at, expired_at, status) VALUES ({}, '{}', '{}', '{}', '{}')""".format(
                    self.id, self.auth_token['token'], self.auth_token['created_at'], self.auth_token['expires_at'], 'logged')
                cursor.execute(sql_session)
                db.connection.commit()
                return True
            except Exception as ex:
                raise Exception(ex)
        else:
            return False

    def logout(self, db):
        print(self)
        cursor = db.connection.cursor()
        cursor.callproc('change_status_expired_session')
        cursor.fetchall()
        sql_session = """SELECT id FROM sessions WHERE user_id = {} AND token = '{}' AND status = 'logged'""".format(
            self.id, self.auth_token['token'])
        cursor.execute(sql_session)
        row = cursor.fetchone()
        if row != None:
            sql_session = """UPDATE sessions SET expired_at = '{}', status = '{}' WHERE id = {}""".format(
                datetime.datetime.now(), 'logout', row[0])
            cursor.execute(sql_session)
            db.connection.commit()
            return {'status': 'logout', 'message': 'Sesión cerrada correctamente'}
        else:
            return {'status': 'session not found', 'message': 'No se ha encontrado la sesión activa'}

    # Comprueba si el usuario está logueado
    def is_logged(self, db):
        cursor = db.connection.cursor()
        # llamar el procedimiento almacenado change_status_expired_session
        cursor.callproc('change_status_expired_session')
        db.connection.commit()
        sql_session = """SELECT id FROM sessions WHERE token = '{}'""".format(
            self.auth_token)
        cursor.execute(sql_session)
        row = cursor.fetchone()
        if row != None:
            # Comprobar si la sesión está activa
            if row[6] == 'logged':
                return {'status': 'logged'}
            elif row[6] == 'expired':
                return {'status': 'expired'}
            else:
                return {'status': 'logout'}
        else:
            return {'status': 'session not found'}
