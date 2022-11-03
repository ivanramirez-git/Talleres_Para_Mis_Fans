class Config: # Clase Config
    SECRET_KEY = 'futb0l_4p1' # Clave secreta

#Configuracion de desarollo
class DevelomentConfig(Config): # Clase DevelomentConfig
    DEBUG = True # Debug activado
    MYSQL_HOST = 'db4free.net' # Host de la base de datos
    MYSQL_USER = 'deybercastillo' # Usuario de la base de datos
    MYSQL_PASSWORD = 'p78yWsfu_B_km_J' # Contraseña de la base de datos
    MYSQL_DB = 'api_futbol_db' # Nombre de la base de datos

class DevelopmentConfigLocal(Config): # Clase DevelopmentConfigLocal
    DEBUG = True # Debug activado
    MYSQL_HOST = 'localhost' # Host de la base de datos
    MYSQL_USER = 'root' # Usuario de la base de datos
    MYSQL_PASSWORD = '' # Contraseña de la base de datos
    MYSQL_DB = 'api_futbol_db' # Nombre de la base de datos
 
config = { # Diccionario de configuraciones
    'development': DevelomentConfig, # Configuración de desarrollo
    'development_local': DevelopmentConfigLocal # Configuración de desarrollo local
} # Fin del diccionario de configuraciones