import sys
import pymysql # pip install pymysql
from config import DevelopmentConfigLocal,DevelomentConfig # Importar la configuración de la secret key
# time para saber el tiempo de la consulta
import time

def connection(isLocal: bool):
    if (isLocal):
        return pymysql.connect( # Conectar con la base de datos
            host=DevelopmentConfigLocal.MYSQL_HOST, # Host de la base de datos
            user=DevelopmentConfigLocal.MYSQL_USER, # Usuario de la base de datos
            password=DevelopmentConfigLocal.MYSQL_PASSWORD, # Contraseña de la base de datos
            db=DevelopmentConfigLocal.MYSQL_DB, # Nombre de la base de datos
    )  # Fin de la conexión

    else:
        return pymysql.connect( # Conectar con la base de datos
            host=DevelomentConfig.MYSQL_HOST, # Host de la base de datos
            user=DevelomentConfig.MYSQL_USER, # Usuario de la base de datos
            password=DevelomentConfig.MYSQL_PASSWORD, # Contraseña de la base de datos
            db=DevelomentConfig.MYSQL_DB, # Nombre de la base de datos
        )  # Fin de la conexión



def mysqlconnect(isLocal: bool): # Función para conectar con la base de datos
    # time
    start_time = time.time() # Iniciar el tiempo
    # To connect MySQL database
    conn = connection(isLocal) # Conectar con la base de datos

    cur = conn.cursor() # Crear el cursor
    cur.execute("select @@version") # Ejecutar el query
    output = cur.fetchall() # Obtener los resultados
    print(output) # Imprimir los resultados

    validar_tablas(conn) # Validar las tablas
    
    validar_procedimientos(conn) # Validar los procedimientos almacenados

    # To close the connection
    conn.close() # Cerrar la conexión

    # time
    print("--- %s seconds ---" % (time.time() - start_time)) # Imprimir el tiempo de la consulta


def validar_procedimientos(conn): # Función para validar los procedimientos almacenados
    print("Validando los procedimientos almacenados") # Imprimir mensaje

    # lista de procedimientos almacenados [change_status_expired_sessions]
    procedimientos = ['change_status_expired_session']

    # Consultar los procedimientos almacenados existentes en la base de datos
    cur = conn.cursor() # Crear el cursor
    # Listar los nombres de los procedimientos almacenados
    cur.execute("SHOW PROCEDURE STATUS") # Ejecutar el query
    list_names_procedures = [] # Lista para almacenar los nombres de los procedimientos almacenados

    for row in cur.fetchall(): # Recorrer los resultados
        list_names_procedures.append(row[1]) # Agregar el nombre del procedimiento almacenado a la lista
    # print(list_names_procedures) # Imprimir los resultados
    # Validar los procedimientos almacenados
    for procedimiento in procedimientos: # Recorrer los procedimientos almacenados
        if procedimiento in list_names_procedures: # Si el procedimiento almacenado existe
            print("El procedimiento almacenado " + procedimiento + " existe") # Imprimir mensaje
        else: # Si el procedimiento almacenado no existe
            print("El procedimiento almacenado " + procedimiento + " no existe") # Imprimir mensaje
            crear_procedimiento(procedimiento,conn) # Crear el procedimiento almacenado
            # llamar el procedimiento almacenado
        
        cur.execute("CALL {0}();".format(procedimiento))
        conn.commit() # Guardar los cambios



def validar_tablas(conn): # Función para validar las tablas
    print("Validando las tablas") # Imprimir mensaje
    
    # lista de tablas para la base de datos del Mundial Qatar 2022
    tablas = ['users', 'sessions', 'teams', 'groups', 'matches_group' ]

    # Consultar las tablas existentes en la base de datos
    cur = conn.cursor() # Crear el cursor
    cur.execute("SHOW TABLES") # Ejecutar el query
    output = cur.fetchall() # Obtener los resultados
    # print(output) # Imprimir los resultados
    # Validar las tablas
    for tabla in tablas: # Recorrer las tablas
        if (tabla,) in output: # Si la tabla existe
            print("La tabla " + tabla + " existe") # Imprimir mensaje
        else: # Si la tabla no existe
            print("La tabla " + tabla + " no existe") # Imprimir mensaje
            crear_tabla(tabla,conn) # Crear la tabla



def crear_tabla(tabla,conn):
    # Crear la tabla
    cur = conn.cursor() # Crear el cursor
    if tabla == 'users':
        cur.execute("CREATE TABLE IF NOT EXISTS `users` (`id` int(11) NOT NULL AUTO_INCREMENT,`username` varchar(50) NOT NULL,`password` varchar(255) NOT NULL,`email` varchar(50) NOT NULL,`fullname` varchar(50) NOT NULL,`role` varchar(50) NOT NULL,PRIMARY KEY (`id`),UNIQUE KEY `username` (`username`),UNIQUE KEY `email` (`email`)) ENGINE=InnoDB DEFAULT CHARSET=utf8;")
        cur.execute("INSERT INTO users (username, password, email, fullname, role) VALUES ('admin', 'pbkdf2:sha256:260000$l999FTgAfnN4E5Wx$485350051a7136b6cd38408d17f0fd0a0c5ebeba199a6d2a384cc0e31d7e17e9', 'admin@carrito.com', 'Administrador', 'admin');")
        print("Tabla users creada")
    elif tabla == 'sessions':
        cur.execute("CREATE TABLE IF NOT EXISTS `sessions` (`id` int(11) NOT NULL AUTO_INCREMENT,`user_id` int(11) NOT NULL,`token` varchar(255) NOT NULL,`created_at` datetime NOT NULL,`expired_at` datetime NOT NULL,`status` varchar(50) NOT NULL,PRIMARY KEY (`id`),KEY `user_id` (`user_id`),CONSTRAINT `sessions_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;")
        print("Tabla sessions creada")
    elif tabla == 'teams':
        # id y nombre del equipo, el nombre debe ser único
        cur.execute("CREATE TABLE IF NOT EXISTS `teams` (`id` int(11) NOT NULL AUTO_INCREMENT,`name` varchar(50) NOT NULL,PRIMARY KEY (`id`),UNIQUE KEY `name` (`name`)) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;")
        print("Tabla teams creada")
    elif tabla == 'groups':
        # id y nombre del grupo, team_1, team_2, team_3, team_4  todos son llaves foráneas de la tabla teams
        cur.execute("CREATE TABLE IF NOT EXISTS `groups` (`id` int(11) NOT NULL AUTO_INCREMENT,`name` varchar(50) NOT NULL,`team_1` int(11) NOT NULL,`team_2` int(11) NOT NULL,`team_3` int(11) NOT NULL,`team_4` int(11) NOT NULL,PRIMARY KEY (`id`),UNIQUE KEY `name` (`name`),KEY `team_1` (`team_1`),KEY `team_2` (`team_2`),KEY `team_3` (`team_3`),KEY `team_4` (`team_4`),CONSTRAINT `groups_ibfk_1` FOREIGN KEY (`team_1`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `groups_ibfk_2` FOREIGN KEY (`team_2`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `groups_ibfk_3` FOREIGN KEY (`team_3`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `groups_ibfk_4` FOREIGN KEY (`team_4`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;")
        print("Tabla groups creada")
    elif tabla == 'matches_group':
        # id, group_id, team_1, team_2, score_1 null, score_2 null, fecha null, status
        cur.execute("CREATE TABLE IF NOT EXISTS `matches_group` (`id` int(11) NOT NULL AUTO_INCREMENT,`group_id` int(11) NOT NULL,`team_1` int(11) NOT NULL,`team_2` int(11) NOT NULL,`score_1` int(11) DEFAULT NULL,`score_2` int(11) DEFAULT NULL,`date` datetime DEFAULT NULL,`status` varchar(50) NOT NULL,PRIMARY KEY (`id`),KEY `group_id` (`group_id`),KEY `team_1` (`team_1`),KEY `team_2` (`team_2`),CONSTRAINT `matches_group_ibfk_1` FOREIGN KEY (`group_id`) REFERENCES `groups` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `matches_group_ibfk_2` FOREIGN KEY (`team_1`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `matches_group_ibfk_3` FOREIGN KEY (`team_2`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;")
        print("Tabla matches_group creada")
    else:
        print("No existe la tabla")
    conn.commit() # Guardar los cambios

def crear_procedimiento(procedimiento,conn):
    # Crear el procedimiento almacenado
    cur = conn.cursor() # Crear el cursor

    if procedimiento == 'change_status_expired_session':
        cur.execute("CREATE PROCEDURE `change_status_expired_session`() BEGIN UPDATE sessions SET status = 'expired' WHERE expired_at < NOW(); END")
        conn.commit() # Guardar los cambios
        print("Procedimiento almacenado change_status_expired_session creado")
    else:
        print("No existe el procedimiento almacenado")


# Driver Code
if __name__ == "__main__": # Si el archivo se ejecuta directamente
    # si en los parametros que llegan desde consola se envia 'local' se conecta a la base de datos local
    if len(sys.argv) > 1 and sys.argv[1] == 'local':
        mysqlconnect(True)
    else:   
        mysqlconnect(False)