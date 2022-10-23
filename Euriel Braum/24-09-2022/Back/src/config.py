class Config: # Clase Config
    SECRET_KEY = 'c4rr1t0' # Clave secreta

#Configuracion de desarollo
class DevelomentConfig(Config): # Clase DevelomentConfig
    DEBUG = True # Debug activado
    MYSQL_HOST = 'localhost' # Host de la base de datos
    MYSQL_USER = 'root' # Usuario de la base de datos
    MYSQL_PASSWORD = '' # Contraseña de la base de datos
    MYSQL_DB = 'flask_db' # Nombre de la base de datos
 
config = { # Diccionario de configuraciones
    'development': DevelomentConfig, # Configuración de desarrollo
} # Fin del diccionario de configuraciones