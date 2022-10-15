# Packages
from flask import Flask, jsonify, request
from flask_mysqldb import MySQL
from config import config

# Entities
from models.entities.User import User
from models.entities.Category import Category

# Models
from models.ModelUser import ModelUser
from models.ModelCategory import ModelCategory

app = Flask(__name__)
app.config.from_object(config['development'])
db = MySQL(app)

# Ruta login


@app.route('/login', methods=['POST'])
def login():
    # Obtenemos los datos del usuario
    print(request.json)
    user = User(None, request.json['username'],
                request.json['password'], None, None, None)
    logger_user = ModelUser.login(db, user)
    if logger_user is not None:
        return jsonify(logger_user.__dict__)
    else:
        return jsonify({"error": "Usuario o contraseña incorrectos"})

# Ruta registro


@app.route('/register', methods=['POST'])
def register():
    # Obtenemos los datos del usuario
    print(request.json)
    user = User(0, request.json['username'], request.json['password'],
                request.json['email'], request.json['fullname'])
    if ModelUser.register(db, user):
        return jsonify({"success": "Usuario registrado correctamente"})
    else:
        return jsonify({"error": "El usuario ya existe"})

# Ruta logout


@app.route('/logout', methods=['POST'])
def logout():
    # Obtenemos los datos del usuario
    print(request.json)
    user = User(request.json['id'], None, None,
                None, None, None, request.json['auth_token'])
    return ModelUser.logout(db, user)


# Ruta de error
@app.route('/error')
def error(message):
    return jsonify({"error": "Error en la petición", "message": message})

# Ruta para obtener los datos del usuario, sesión activa requerida


@app.route('/user', methods=['GET'])
def get_user():
    # Obtenemos el token del header
    token = request.headers.get('token')
    u = User(None, None, None, None, None, None, {'token': token})

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, u)
        if user is not None:
            return jsonify(user.__dict__)
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")

# Ruta para guardar una categoría, sesión activa requerida y rol admin


@app.route('/saveCategory', methods=['POST'])
def saveCategory():
    # Obtenemos el token del header
    token = request.headers.get('token')

    if token is not None:
        user = ModelUser.get_user_by_id(
            db, User(None, None, None, None, None, None, {'token': token}))
        if user is not None:
            category = Category(
                0, request.json['name'], request.json['description'])
            if ModelCategory.save(db, category, user):
                return jsonify({"success": "Categoria guardada correctamente"})
            else:
                return error("No tienes permisos para realizar esta acción")
        else:
            return error("No se ha encontrado una sesión activa")
    else:
        return error("El token no ha sido enviado")


# Inicio del programa
if __name__ == '__main__':
    app.run()
