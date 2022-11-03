# Packages
from flask import Flask, get_flashed_messages, jsonify, render_template, request, redirect, url_for, flash  # Paquetes para la crear la API
from flask_mysqldb import MySQL # Paquete para la conexión con MySQL
import pymysql  # Paquete para la conexión con MySQL
from config import config  # Paquete para la configuración de la conexión con MySQL
# Validar si la base de datos tiene las tablas necesarias
import test_conexion # Importar el archivo para validar la conexión con la base de datos

# Entities
from modelo.user import User # Importar la entidad User
from modelo.team import Team # Importar la entidad Team
from modelo.group import Group # Importar la entidad Group
from modelo.match_group import MatchGroup # Importar la entidad MatchGroup

# Models
from controlador.user_controller import UserController # Importar el modelo de usuario
from controlador.team_controller import TeamController # Importar el modelo de equipo
from controlador.group_controller import GroupController # Funciones centralizadas de manejo peticiones
from controlador.match_group_controller import MatchGroupController # Importar el modelo de partido de grupo

app = Flask(__name__)  # Instancia de Flask
db = MySQL(app)  # Instancia de MySQL


# Funciones centralizadas de manejo peticiones
# LOGIN
def login_main(username: str, password: str): # funcion que centraliza el login
    user = User(None, username, password, None, None, None) # Se crea un objeto de tipo User con los datos del usuario
    logged_user = UserController.login(db, user) # Se llama al método login de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
    if logged_user is not None: # Si el usuario existe
        return logged_user # Devolver el objeto de tipo User
    else: # Si el usuario no existe
        return None # Devolver un mensaje de error
# END LOGIN

# LOGOUT
def logout_main(id: str, auth_token: str): # Funcion para centralizar logout
    user = User(id, None, None, None, None, None, {'token':auth_token}) # crear objeto de tipo User
    return UserController.logout(db, user)# llamar al método logout de la clase ModelUser
# END LOGOUT

# USER
def user_main(id: str, auth_token: str):
    user = User(id, None, None, None, None, None, {'token':auth_token}) # crear objeto de tipo User
    return UserController.get_user_by_id(db, user)# llamar al método get_user_by_id de la clase ModelUser
# END USER

# CRUD TEAMS
def save_team_main(user_id, team_name, auth_token): # Funcion para centralizar el guardado de un equipo
    user = User(user_id, None, None, None, None, None, {'token':auth_token}) # Crear objeto de tipo User
    team = Team(None, team_name) # Crear objeto de tipo Team
    return TeamController.save(db, team, user) # Llamar al método save de la clase ModelTeam

def update_team_main(user_id , team_id, team_name, auth_token): # Funcion para centralizar la actualización de un equipo
    user = User(user_id, None, None, None, None, None, {'token':auth_token}) # Crear objeto de tipo User
    team = Team(team_id, team_name) # Crear objeto de tipo Team
    return TeamController.update(db, team, user) # Llamar al método update de la clase ModelTeam

def delete_team_main(user_id, team_id, auth_token): # Funcion para centralizar la eliminación de un equipo
    user = User(user_id, None, None, None, None, None, {'token':auth_token}) # Crear objeto de tipo User
    team = Team(team_id, None) # Crear objeto de tipo Team
    return TeamController.delete(db, team, user) # Llamar al método delete de la clase ModelTeam

def get_all_teams_main(): # Funcion para centralizar la obtención de todos los equipos
    return TeamController.get_all(db) # Llamar al método get_all de la clase ModelTeam

def get_team_by_id_main(team_id: str): # Funcion para centralizar la obtención de un equipo por id
    return TeamController.get_by_id(db, team_id) # Llamar al método get_by_id de la clase ModelTeam

def get_team_by_name_main(team_name: str): # Funcion para centralizar la obtención de un equipo por nombre
    return TeamController.get_by_name(db, team_name) # Llamar al método get_by_name de la clase ModelTeam

def get_teams_count_main(): # Funcion para centralizar la obtención del número de equipos
    return TeamController.get_count(db) # Llamar al método get_count de la clase ModelTeam
# END CRUD TEAMS

# CRUD MATCH GROUPS
def save_match_group_main(user_id, group_id, team_1, team_2, score_1, score_2, date, status, auth_token): # Funcion para centralizar el guardado de un partido de grupo
    user = User(user_id, None, None, None, None, None, {'token':auth_token}) # Crear objeto de tipo User
    match_group = MatchGroup(None, group_id, team_1, team_2, score_1, score_2, date, status) # Crear objeto de tipo MatchGroup
    return MatchGroupController.save(db, match_group, user) # Llamar al método save de la clase ModelMatchGroup

def update_match_group_main(user_id, match_group_id, group_id, team_1, team_2, score_1, score_2, date, status, auth_token): # Funcion para centralizar la actualización de un partido de grupo
    user = User(user_id, None, None, None, None, None, {'token':auth_token}) # Crear objeto de tipo User
    match_group = MatchGroup(match_group_id, group_id, team_1, team_2, score_1, score_2, date, status) # Crear objeto de tipo MatchGroup
    return MatchGroupController.update(db, match_group, user) # Llamar al método update de la clase ModelMatchGroup

def delete_match_group_main(user_id, match_group_id, auth_token): # Funcion para centralizar la eliminación de un partido de grupo
    user = User(user_id, None, None, None, None, None, {'token':auth_token}) # Crear objeto de tipo User
    match_group = MatchGroup(match_group_id, None) # Crear objeto de tipo MatchGroup
    return MatchGroupController.delete(db, match_group, user) # Llamar al método delete de la clase ModelMatchGroup

def get_all_match_groups_main(): # Funcion para centralizar la obtención de todos los partidos de grupo
    return MatchGroupController.get_all(db) # Llamar al método get_all de la clase ModelMatchGroup

def get_match_group_by_id_main(match_group_id: str): # Funcion para centralizar la obtención de un partido de grupo por id
    return MatchGroupController.get_by_id(db, match_group_id) # Llamar al método get_by_id de la clase ModelMatchGroup

def get_match_group_by_group_main(group_id: str): # Funcion para centralizar la obtención de un partido de grupo por grupo
    return MatchGroupController.get_by_group(db, group_id) # Llamar al método get_by_group de la clase ModelMatchGroup

def get_match_group_by_team_main(team_id: str): # Funcion para centralizar la obtención de un partido de grupo por equipo
    return MatchGroupController.get_by_team(db, team_id) # Llamar al método get_by_team de la clase ModelMatchGroup

def get_match_groups_count_main(): # Funcion para centralizar la obtención del número de partidos de grupo
    return MatchGroupController.get_count(db) # Llamar al método get_count de la clase ModelMatchGroup

def create_match_groups(): # Funcion para crear los partidos de grupo
    return MatchGroupController.create_match_groups(db) # Llamar al método create_match_groups de la clase ModelMatchGroup
# END CRUD MATCH GROUPS


# CRUD GROUPS
def save_group_main(user_id, group_name, auth_token, team_1, team_2, team_3, team_4): # Funcion para centralizar el guardado de un grupo
    user = User(user_id, None, None, None, None, None, {'token':auth_token}) # Crear objeto de tipo User
    group = Group(None, group_name, team_1, team_2, team_3, team_4) # Crear objeto de tipo Group
    groupControllerResponse = GroupController.save(db, group, user)
    print('groupControllerResponse', groupControllerResponse)
    # Si existen 8 grupos, crear los partidos de grupo por cada grupo
    if groupControllerResponse == 200:
        print("Creando partidos de grupo...")
        if GroupController.get_count(db) == 8:
            print("Creando partidos de grupo... num grupos: 8")
            create_match_groups()
    return groupControllerResponse # Llamar al método save de la clase ModelGroup
    
def update_group_main(user_id , group_id, group_name, auth_token, team_1, team_2, team_3, team_4): # Funcion para centralizar la actualización de un grupo
    user = User(user_id, None, None, None, None, None, {'token':auth_token}) # Crear objeto de tipo User
    group = Group(group_id, group_name, team_1, team_2, team_3, team_4) # Crear objeto de tipo Group
    return GroupController.update(db, group, user) # Llamar al método update de la clase ModelGroup

def delete_group_main(user_id, group_id, auth_token): # Funcion para centralizar la eliminación de un grupo
    user = User(user_id, None, None, None, None, None, {'token':auth_token}) # Crear objeto de tipo User
    group = Group(group_id, None, None, None, None, None) # Crear objeto de tipo Group
    return GroupController.delete(db, group, user) # Llamar al método delete de la clase ModelGroup

def get_all_groups_main(): # Funcion para centralizar la obtención de todos los grupos
    return GroupController.get_all(db) # Llamar al método get_all de la clase ModelGroup

def get_group_by_id_main(group_id: str): # Funcion para centralizar la obtención de un grupo por id
    return GroupController.get_by_id(db, group_id) # Llamar al método get_by_id de la clase ModelGroup

def get_group_by_name_main(group_name: str): # Funcion para centralizar la obtención de un grupo por nombre
    return GroupController.get_by_name(db, group_name) # Llamar al método get_by_name de la clase ModelGroup

def get_groups_count_main(): # Funcion para centralizar la obtención del número de grupos
    return GroupController.get_count(db) # Llamar al método get_count de la clase ModelGroup

def get_teams_without_group_main(): # Funcion para centralizar la obtención de los equipos sin grupo
    return GroupController.get_teams_without_group(db) # Llamar al método get_teams_without_group de la clase ModelGroup
# END CRUD GROUPS

# Rutas para peticiones REST

# FRONTEND

# Ruta principal
@app.route('/') # Decorador para la ruta principal
def index(): # Función para la ruta principal
    # imprimir 1 linea del archivo index.html
    titulo = "Login Solo Admin"
    # leer los argumentos de la url
    error = request.args.get('error')
    if error is None:
        error = ""
    return render_template('index.html', titulo=titulo, error=error) # Retornar el archivo index.html

        
@app.route('/login_form', methods=['POST']) # Ruta para el login se le indica que solo acepta peticiones POST, desde un formulario html
def login_form(): # Función para el login
    # Obtenemos los datos del usuario
    username = request.form['username'] # Se obtiene el valor del campo username del formulario html
    password = request.form['password'] # Se obtiene el valor del campo password del formulario html
    # Validar campos vacios
    if username == '' or password == '' or username is None or password is None:
        return redirect(url_for('index', error="Usuario o contraseña no pueden estar vacios"))
    # Validar si es admin
    logged_user = login_main(username, password)
    if logged_user is not None: # Si el usuario existe
        objUser = logged_user.__dict__
        print('Is admin: ', objUser['role'])
        # validar si es admin
        if objUser['role'] == 'admin':
            flash(objUser)   
            return redirect(url_for('home'))
        else:
            return redirect(url_for('index', error='No eres admin'))
    else: # Si el usuario no existe
        return redirect(url_for('index', error="Usuario o contraseña incorrectos")) # Redireccionar a la ruta index con un mensaje de error

# Ruta logout front
@app.route('/logout', methods=['GET']) # Ruta para el logout
def logout_get(): # Función para el logout
    # recuperar token de autenticación de la url
    user_id =request.args.get('id')
    auth_token =request.args.get('token')
    if auth_token is None and id is None:
        return error('No se ha enviado el token de autenticación', 401)
    else:
        # llamar a la función logout
        if logout_main(user_id, auth_token) is not None:
            return redirect(url_for('index', error='Sesión cerrada correctamente'))

# Ruta para guardar un equipo a través del formulario
@app.route('/save_team_form', methods=['POST']) # Ruta para guardar un equipo a través del formulario
def save_team_form(): # Función para guardar un equipo a través del formulario
    # recuperar token de autenticación de la url
    name = request.form['name'] # Se obtiene el valor del campo name del formulario html
    user_id =request.args.get('id') # Se obtiene el valor del campo user_id de la url
    auth_token =request.args.get('token') # Se obtiene el valor del campo auth_token de la url
    # Validar campos vacios
    if name == '' or name is None:
        return redirect(url_for('home', save_team_form_message="El nombre del equipo no puede estar vacio"))
    # Validar si es admin
    logged_user = user_main(user_id, auth_token)
    if logged_user is not None: # Si el usuario existe
        objUser = logged_user.__dict__
        # validar si es admin
        if objUser['role'] == 'admin':
            flash(objUser)   
            code_request = save_team_main(user_id, name, auth_token)
            # llamar a la función save_team_main
            if  code_request == 200:
                return redirect(url_for('home', save_team_form_message="Equipo guardado correctamente"))
            elif code_request == 409:
                return redirect(url_for('home', save_team_form_message="El equipo ya existe"))
            else: # 401
                return redirect(url_for('home', save_team_form_message="No tienes permisos para realizar esta acción"))
        else:
            return redirect(url_for('index', error='No eres admin'))


# Ruta para eliminar un equipo a través del formulario
@app.route('/delete_team_form', methods=['GET']) # Ruta para eliminar un equipo a través del formulario
def delete_team_form(): # Función para eliminar un equipo a través del formulario
    # recuperar token de autenticación de la url
    team_id =request.args.get('id') # Se obtiene el valor del campo team_id de la url
    user_id =request.args.get('user_id') # Se obtiene el valor del campo user_id de la url
    auth_token =request.args.get('token') # Se obtiene el valor del campo auth_token de la url
    # Validar si es admin
    logged_user = user_main(user_id, auth_token)
    if logged_user is not None: # Si el usuario existe
        objUser = logged_user.__dict__
        # validar si es admin
        if objUser['role'] == 'admin':
            flash(objUser)   
            code_request = delete_team_main(user_id,team_id, auth_token)
            # llamar a la función delete_team_main
            if  code_request == 200:
                return redirect(url_for('home', delete_team_form_message="Equipo eliminado correctamente"))
            elif code_request == 409:
                return redirect(url_for('home', delete_team_form_message="El equipo no existe"))
            else:
                return redirect(url_for('home', delete_team_form_message="No tienes permisos para realizar esta acción"))
        else:
            return redirect(url_for('index', error='No eres admin'))

# Ruta para modificar un equipo a través del formulario
@app.route('/update_team_form', methods=['POST']) # Ruta para modificar un equipo a través del formulario
def update_team_form(): # Función para modificar un equipo a través del formulario
    # recuperar token de autenticación de la url
    team_id =request.args.get('id') # Se obtiene el valor del campo team_id de la url
    user_id =request.args.get('user_id') # Se obtiene el valor del campo user_id de la url
    auth_token =request.args.get('token') # Se obtiene el valor del campo auth_token de la url
    team_name = request.form['name'] # Se obtiene el valor del campo name del formulario html
    # Validar campos vacios
    if team_name == '' or team_name is None:
        return redirect(url_for('home', update_team_form_message="El nombre del equipo no puede estar vacio"))
    # Validar si es admin
    logged_user = user_main(user_id, auth_token)
    if logged_user is not None: # Si el usuario existe
        objUser = logged_user.__dict__
        # validar si es admin
        if objUser['role'] == 'admin':
            flash(objUser)   
            code_request = update_team_main(user_id, team_id, team_name, auth_token)
            # llamar a la función update_team_main
            if  code_request == 200:
                return redirect(url_for('home', update_team_form_message="Equipo modificado correctamente"))
            elif code_request == 409:
                return redirect(url_for('home', update_team_form_message="El equipo no existe"))
            else:
                return redirect(url_for('home', update_team_form_message="No tienes permisos para realizar esta acción"))
        else:
            return redirect(url_for('index', error='No eres admin'))




# Ruta para guardar un grupo a través del formulario
@app.route('/save_group_form', methods=['POST']) # Ruta para guardar un grupo a través del formulario
def save_group_form(): # Función para guardar un grupo a través del formulario
    # recuperar token de autenticación de la url
    user_id =request.args.get('user_id') # Se obtiene el valor del campo user_id de la url
    auth_token =request.args.get('token') # Se obtiene el valor del campo auth_token de la url
    group_name = request.form['name'] # Se obtiene el valor del campo name del formulario html
    team_1 = request.form['team1'] # Se obtiene el valor del campo team_1 del formulario html
    team_2 = request.form['team2'] # Se obtiene el valor del campo team_2 del formulario html
    team_3 = request.form['team3'] # Se obtiene el valor del campo team_3 del formulario html
    team_4 = request.form['team4'] # Se obtiene el valor del campo team_4 del formulario html
    # Validar campos vacios
    if group_name == '' or group_name is None:
        return redirect(url_for('home', save_group_form_message="El nombre del grupo no puede estar vacio"))
    # Validar si es admin
    logged_user = user_main(user_id, auth_token)
    if logged_user is not None: # Si el usuario existe
        objUser = logged_user.__dict__
        # validar si es admin
        if objUser['role'] == 'admin':
            flash(objUser)   
            code_request = save_group_main(user_id, group_name, auth_token, team_1, team_2, team_3, team_4)
            # llamar a la función save_group_main
            if  code_request == 200:
                return redirect(url_for('home', save_group_form_message="Grupo guardado correctamente"))
            elif code_request == 409:
                return redirect(url_for('home', save_group_form_message="El grupo ya existe"))
            else:
                return redirect(url_for('home', save_group_form_message="No tienes permisos para realizar esta acción"))
        else:
            return redirect(url_for('index', error='No eres admin'))

# Ruta para eliminar un grupo a través del formulario
@app.route('/delete_group_form', methods=['GET']) # Ruta para eliminar un grupo a través del formulario
def delete_group_form(): # Función para eliminar un grupo a través del formulario
    # recuperar token de autenticación de la url
    group_id =request.args.get('id') # Se obtiene el valor del campo group_id de la url
    user_id =request.args.get('user_id') # Se obtiene el valor del campo user_id de la url
    auth_token =request.args.get('token') # Se obtiene el valor del campo auth_token de la url
    print('Parameters: ', group_id, user_id, auth_token)
    # Validar si es admin
    logged_user = user_main(user_id, auth_token)
    if logged_user is not None: # Si el usuario existe
        objUser = logged_user.__dict__
        # validar si es admin
        if objUser['role'] == 'admin':
            flash(objUser)   
            code_request = delete_group_main(user_id, group_id, auth_token)
            # llamar a la función delete_group_main
            if  code_request == 200:
                return redirect(url_for('home', delete_group_form_message="Grupo eliminado correctamente"))
            elif code_request == 409:
                return redirect(url_for('home', delete_group_form_message="El grupo no existe"))
            else:
                return redirect(url_for('home', delete_group_form_message="No tienes permisos para realizar esta acción"))
        else:
            return redirect(url_for('index', error='No eres admin'))

# Ruta para actualizar un grupo a través del formulario
@app.route('/update_group_form', methods=['POST']) # Ruta para actualizar un grupo a través del formulario
def update_group_form(): # Función para actualizar un grupo a través del formulario
    # recuperar token de autenticación de la url
    group_id =request.args.get('id') # Se obtiene el valor del campo group_id de la url
    user_id =request.args.get('user_id') # Se obtiene el valor del campo user_id de la url
    auth_token =request.args.get('token') # Se obtiene el valor del campo auth_token de la url
    group_name = request.form['name'] # Se obtiene el valor del campo name del formulario html
    team_1 = request.form['team1'] # Se obtiene el valor del campo team_1 del formulario html
    team_2 = request.form['team2'] # Se obtiene el valor del campo team_2 del formulario html
    team_3 = request.form['team3'] # Se obtiene el valor del campo team_3 del formulario html
    team_4 = request.form['team4'] # Se obtiene el valor del campo team_4 del formulario html
    # Validar campos vacios
    if group_name == '' or group_name is None:
        return redirect(url_for('home', update_group_form_message="El nombre del grupo no puede estar vacio"))
    # Validar si es admin
    logged_user = user_main(user_id, auth_token)
    if logged_user is not None: # Si el usuario existe
        objUser = logged_user.__dict__
        # validar si es admin
        if objUser['role'] == 'admin':
            flash(objUser)   
            code_request = update_group_main(user_id, group_id, group_name, auth_token, team_1, team_2, team_3, team_4)
            # llamar a la función update_group_main
            if  code_request == 200:
                return redirect(url_for('home', update_group_form_message="Grupo actualizado correctamente"))
            elif code_request == 409:
                return redirect(url_for('home', update_group_form_message="El grupo no existe"))
            else:
                return redirect(url_for('home', update_group_form_message="No tienes permisos para realizar esta acción"))
        else:
            return redirect(url_for('index', error='No eres admin'))





'''
update_match_group_main(user_id, match_group_id, group_id, team_1, team_2, score_1, score_2, date, status, auth_token)
get_all_match_groups_main()
'''
# Ruta para actualizar el marcador de un partido a través del formulario
@app.route('/update_match_group_form', methods=['POST']) # Ruta para actualizar el marcador de un partido a través del formulario
def update_match_group_form(): # Función para actualizar el marcador de un partido a través del formulario
    # recuperar token de autenticación de la url
    match_group_id =request.args.get('id') # Se obtiene el valor del campo match_group_id de la url
    user_id =request.args.get('user_id') # Se obtiene el valor del campo user_id de la url
    auth_token =request.args.get('token') # Se obtiene el valor del campo auth_token de la url
    group_id = request.form['group_id'] # Se obtiene el valor del campo group_id del formulario html
    team_1 = request.form['team1'] # Se obtiene el valor del campo team_1 del formulario html
    team_2 = request.form['team2'] # Se obtiene el valor del campo team_2 del formulario html
    score_1 = request.form['score1'] # Se obtiene el valor del campo score_1 del formulario html
    score_2 = request.form['score2'] # Se obtiene el valor del campo score_2 del formulario html
    date = request.form['date'] # Se obtiene el valor del campo date del formulario html
    status = request.form['status'] # Se obtiene el valor del campo status del formulario html
    # Validar campos vacios
    if group_id == '' or group_id is None:
        return redirect(url_for('home', update_match_group_form_message="El id del grupo no puede estar vacio"))
    if team_1 == '' or team_1 is None:
        return redirect(url_for('home', update_match_group_form_message="El equipo 1 no puede estar vacio"))
    if team_2 == '' or team_2 is None:
        return redirect(url_for('home', update_match_group_form_message="El equipo 2 no puede estar vacio"))
    if score_1 == '' or score_1 is None:
        return redirect(url_for('home', update_match_group_form_message="El marcador 1 no puede estar vacio"))
    if score_2 == '' or score_2 is None:
        return redirect(url_for('home', update_match_group_form_message="El marcador 2 no puede estar vacio"))
    if date == '' or date is None:
        return redirect(url_for('home', update_match_group_form_message="La fecha no puede estar vacia"))
    if status == '' or status is None:
        return redirect(url_for('home', update_match_group_form_message="El estado no puede estar vacio"))
    # Validar si es admin
    logged_user = user_main(user_id, auth_token)
    if logged_user is not None: # Si el usuario existe
        objUser = logged_user.__dict__
        # validar si es admin
        if objUser['role'] == 'admin':
            flash(objUser)   
            code_request = update_match_group_main(user_id, match_group_id, group_id, team_1, team_2, score_1, score_2, date, status, auth_token)
            # llamar a la función update_match_group_main
            if  code_request == 200:
                return redirect(url_for('home', update_match_group_form_message="Partido actualizado correctamente"))
            elif code_request == 409:
                return redirect(url_for('home', update_match_group_form_message="El partido no existe"))
            else:
                return redirect(url_for('home', update_match_group_form_message="No tienes permisos para realizar esta acción"))
        else:
            return redirect(url_for('index', error='No eres admin'))


# Ruta para el home
@app.route('/home') # Ruta para el home
def home(): # Función para el home
    # get messages flashed
    objUser = get_flashed_messages()
    # save_team_form_message
    save_team_form_message = request.args.get('save_team_form_message')
    # number of teams
    teams_count = get_teams_count_main()
    # get all teams
    teams = get_all_teams_main()
    # get all groups
    groups = get_all_groups_main()
    # get all teams without group
    teams_without_group = get_teams_without_group_main()
    # get all match groups
    match_groups = get_all_match_groups_main()
    # number of groups
    groups_count = get_groups_count_main()
    # number of match groups
    match_groups_count = get_match_groups_count_main()
    print(
        {
            'objUser': objUser,
            'save_team_form_message': save_team_form_message,
            'teams_count': teams_count,
            'teams': teams,
            'groups': groups,
            'teams_without_group': teams_without_group,
            'groups_count': groups_count,
            'match_groups': match_groups
        }
    )
    if save_team_form_message is None:
        save_team_form_message = ""
    if objUser is None or len(objUser) == 0:
        return redirect(url_for('index', error='No eres admin'))
    else:
        jsonObjUser = objUser[0]
        return render_template('home.html', user=jsonObjUser, titulo='Home', save_team_form_message=save_team_form_message, teams_count=teams_count, teams=teams, groups=groups, groups_count=groups_count, teams_without_group=teams_without_group, match_groups=match_groups, match_groups_count=match_groups_count)


# BACKEND

# Ruta de login
@app.route('/login', methods=['POST']) # Ruta para el login se le indica que solo acepta peticiones POST
def login(): # Función para el login
    # Obtenemos los datos del usuario
    username = request.json['username']
    password = request.json['password']
    # Validar campos vacios
    if username == '' or password == '' or username is None or password is None:
        return jsonify({"error": "Usuario o contraseña no pueden estar vacios"})
    # iniciar sesion
    logged_user = login_main(username, password)
    if logged_user is not None: # Si el usuario existe
        objUser = logged_user.__dict__
        return jsonify(objUser) # Devolver el objeto de tipo User en formato JSON
    else: # Si el usuario no existe
        return jsonify({"error": "Usuario o contraseña incorrectos"}) # Devolver un mensaje de error

# Ruta logout
@app.route('/logout', methods=['POST']) # Ruta para el logout se le indica que solo acepta peticiones POST
def logout(): # Función para el logout
    # Obtenemos los datos del usuario
    user_id = request.json['id']
    auth_token = request.json['auth_token']
    # llamar a la función logout
    return logout_main(user_id, auth_token)


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

# Ruta registro
@app.route('/register', methods=['POST']) # Ruta para el registro se le indica que solo acepta peticiones POST
def register(): # Función para el registro
    # Obtenemos los datos del usuario
    user = User(0, request.json['username'], request.json['password'], request.json['email'], request.json['fullname']) # Se crea un objeto de tipo User con los datos del usuario
    if UserController.register(db, user): # Se llama al método register de la clase ModelUser y se le pasa el objeto de tipo User y la instancia de MySQL
        return jsonify({"success": "Usuario registrado correctamente"}) # Devolver un mensaje de éxito
    else: # Si el usuario no se ha podido registrar
        return jsonify({"error": "El usuario ya existe"}) # Devolver un mensaje de error

    
# Ruta para obtener los datos del usuario, sesión activa requerida
@app.route('/user', methods=['GET']) # Ruta para obtener los datos del usuario se le indica que solo acepta peticiones GET
def get_user(): # Función para obtener los datos del usuario
    # Obtenemos el token del header
    token = request.headers.get('token') # Se obtiene el token del header
    # llamar a la funcion user_main
    user = user_main(None, token)
    if user is not None: # Si el usuario existe
        return jsonify(user.__dict__) # Devolver el objeto de tipo User en formato JSON
    else: # Si el usuario no existe
        return error("No se ha encontrado una sesión activa") # Devolver un mensaje de error

# Inicio del programa
if __name__ == '__main__': # Si el programa se ejecuta directamente
    # Validar si la base de datos tiene las tablas necesarias
    # test_conexion.mysqlconnect() # Se llama al método test de la clase TestConexion y se le pasa la instancia de MySQL
        

    import sys
    # si en los argumentos viene test se debe llamar la funcion test en el archivo test_conexion.py
    args = sys.argv # Se obtienen los argumentos de la consola
    # buscar local en los argumentos
    if 'local' in args: # Si el argumento test está en los argumentos
        print(' * Conectando a la base de datos local') # Se imprime un mensaje en la consola
        data_base_connection = 'development_local' # Se establece la conexión a la base de datos local
    else: # Si el argumento test no está en los argumentos
        print(' * Conectando a la base de datos remota') # Se imprime un mensaje en la consola
        data_base_connection = 'development' # Se establece la conexión a la base de datos remota

    # buscar test esta en los argumentos
    if 'test' in args: # Si el argumento local está en los argumentos
        print(' * Ejecutando test') # Se imprime un mensaje en la consola
        test_conexion.mysqlconnect(data_base_connection == 'development_local') # Se llama al método test de la clase TestConexion y se le pasa la instancia de MySQL
    
    app.config.from_object(config[data_base_connection]) # Se le indica a la aplicación que se debe conectar a la base de datos de desarrollo
    app.run() # Se ejecuta la aplicación

