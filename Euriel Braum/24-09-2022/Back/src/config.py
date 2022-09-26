class Config:
    SECRET_KEY = 'c4rr1t0'

#Configuracion de desarollo
class DevelomentConfig(Config):
    DEBUG = True
    MYSQL_HOST = 'localhost'
    MYSQL_USER = 'root'
    MYSQL_PASSWORD = ''
    MYSQL_DB = 'flask_db'

config = {
    'development': DevelomentConfig,
}
