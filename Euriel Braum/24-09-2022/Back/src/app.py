# importamos flask
from models.entities.User import User
from models.ModelUser import ModelUser
from flask import Flask, jsonify, request
from flask_mysqldb import MySQL
from config import config

app = Flask(__name__)
app.config.from_object(config['development'])
db = MySQL(app)
# ma = Marshmallow(app)

# Models:

# Entities:

# Creación de tablas

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
                request.json['email'], request.json['fullname'], request.json['role'])
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

# Ruta para obtener los datos del usuario


# Inicio del programa
if __name__ == '__main__':
    app.run()
