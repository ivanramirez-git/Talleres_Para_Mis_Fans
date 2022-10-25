# Packages
from flask import Flask, jsonify, render_template, request, redirect, url_for  # Paquetes para la crear la API
from flask_mysqldb import MySQL  # Paquete para la conexión con MySQL
from config import config  # Paquete para la configuración de la conexión con MySQL
# Validar si la base de datos tiene las tablas necesarias
import test_conexion # Importar el archivo para validar la conexión con la base de datos

# Entities
from modelo.user import User # Importar la entidad User

# Models
from controlador.user_controller import UserController # Importar el modelo de usuario

app = Flask(__name__)  # Instancia de Flask
app.config.from_object(config['development']) # Agregamos la configuración de la conexión con MySQL a la instancia de Flask
db = MySQL(app)  # Instancia de MySQL


# Rutas para peticiones REST

# Ruta principal
@app.route('/') # Decorador para la ruta principal
def index(): # Función para la ruta principal
    # imprimir 1 linea del archivo index.html
    return render_template('index.html') # Devolver el template index.html


# Ruta de error
@app.route('/error')
def error(message, code):
    respuesta = {
        'status': 'error',
        'message': message
    }
    # si el codigo es 404
    if code == 404:
        # retornar la vista html 404, .\vista\404.html
        return render_template('./vista/404.html'), code
    else:
        # retornar la respuesta en formato JSON
        return jsonify(respuesta), code

# Ruta login
@app.route('/login', methods=['POST']) # Ruta para el login se le indica que solo acepta peticiones POST
def login(): # Función para el login
    # Obtenemos los datos del usuario
    user = User(None, request.json['username'], request.json['password'], None, None, None) # Se crea un objeto de tipo User con los datos del usuario
    logger_user = UserController.login(db, user) # Se llama al método login de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
    if logger_user is not None: # Si el usuario existe
        return jsonify(logger_user.__dict__) # Devolver el objeto de tipo User en formato JSON
    else: # Si el usuario no existe
        return jsonify({"error": "Usuario o contraseña incorrectos"}) # Devolver un mensaje de error

# Ruta registro
@app.route('/register', methods=['POST']) # Ruta para el registro se le indica que solo acepta peticiones POST
def register(): # Función para el registro
    # Obtenemos los datos del usuario
    user = User(0, request.json['username'], request.json['password'], request.json['email'], request.json['fullname']) # Se crea un objeto de tipo User con los datos del usuario
    if UserController.register(db, user): # Se llama al método register de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        return jsonify({"success": "Usuario registrado correctamente"}) # Devolver un mensaje de éxito
    else: # Si el usuario no se ha podido registrar
        return jsonify({"error": "El usuario ya existe"}) # Devolver un mensaje de error

# Ruta logout
@app.route('/logout', methods=['POST']) # Ruta para el logout se le indica que solo acepta peticiones POST
def logout(): # Función para el logout
    # Obtenemos los datos del usuario
    user = User(request.json['id'], None, None, None, None, None, request.json['auth_token']) # Se crea un objeto de tipo User con los datos del usuario
    return UserController.logout(db, user) # Se llama al método logout de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL

# Ruta para obtener los datos del usuario, sesión activa requerida
@app.route('/user', methods=['GET']) # Ruta para obtener los datos del usuario se le indica que solo acepta peticiones GET
def get_user(): # Función para obtener los datos del usuario
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header
    user = User(None, None, None, None, None, None, {'token': token}) # Se crea un objeto de tipo User con el token
    if token is not None: # Si el token no es nulo
        user = UserController.get_user_by_id(db, user) # Se llama al método get_user_by_id de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        if user is not None: # Si el usuario existe
            return jsonify(user.__dict__) # Devolver el objeto de tipo User en formato JSON
        else: # Si el usuario no existe
            return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error
    else: # Si el token es nulo
        return error("El token no ha sido enviado") # Devolver un mensaje de error

@app.route('/login_admin', methods=['POST']) # Ruta para el login se le indica que solo acepta peticiones POST, desde un formulario html
def login_admin(): # Función para el login
    # Obtenemos los datos del usuario
    user = User(None, request.form['username'], request.form['password'], None, None, None) # Se crea un objeto de tipo User con los datos del usuario
    logger_user = UserController.login(db, user) # Se llama al método login de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
    print(logger_user)
    return redirect(url_for('index')) # Redireccionar a la ruta principal

# Inicio del programa
if __name__ == '__main__': # Si el programa se ejecuta directamente
    # Validar si la base de datos tiene las tablas necesarias
    # test_conexion.mysqlconnect() # Se llama al método test de la clase TestConexion y se le pasa la instancia de MySQL
    app.run() # Se ejecuta la aplicación
