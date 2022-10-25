import pymysql # pip install pymysql
from config import DevelomentConfig # Importar la configuración de la secret key


def mysqlconnect(): # Función para conectar con la base de datos
    # To connect MySQL database
    conn = pymysql.connect( # Conectar con la base de datos
        host=DevelomentConfig.MYSQL_HOST, # Host de la base de datos
        user=DevelomentConfig.MYSQL_USER, # Usuario de la base de datos
        password=DevelomentConfig.MYSQL_PASSWORD, # Contraseña de la base de datos
        db=DevelomentConfig.MYSQL_DB, # Nombre de la base de datos
    )  # Fin de la conexión

    cur = conn.cursor() # Crear el cursor
    cur.execute("select @@version") # Ejecutar el query
    output = cur.fetchall() # Obtener los resultados
    print(output) # Imprimir los resultados

    validar_tablas(conn) # Validar las tablas
    
    validar_procedimientos(conn) # Validar los procedimientos almacenados

    # To close the connection
    conn.close() # Cerrar la conexión

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
    else:
        print("No existe la tabla")
    conn.commit() # Guardar los cambios

def crear_procedimiento(procedimiento,conn):
    # Crear el procedimiento almacenado
    cur = conn.cursor() # Crear el cursor

    if procedimiento == 'change_status_expired_sessions':
        cur.execute("CREATE DEFINER=`deybercastillo`@`%` PROCEDURE `change_status_expired_sessions`() BEGIN UPDATE sessions SET status = 'expired' WHERE expired_at < NOW(); END")
        cur.execute("CALL change_status_expired_sessions()")
        print("Procedimiento almacenado change_status_expired_session creado")
    else:
        print("No existe el procedimiento almacenado")
    conn.commit() # Guardar los cambios


def validar_tablas(conn): # Función para validar las tablas
    print("Validando las tablas") # Imprimir mensaje
    
    # lista de tablas
    tablas = ['users', 'sessions' ]

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


def validar_procedimientos(conn): # Función para validar los procedimientos almacenados
    print("Validando los procedimientos almacenados") # Imprimir mensaje

    # lista de procedimientos almacenados [change_status_expired_sessions]
    procedimientos = ['change_status_expired_sessions']

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


# Driver Code
# if __name__ == "__main__": # Si el archivo se ejecuta directamente
#     mysqlconnect() # Llamar a la función para conectar con la base de datos
