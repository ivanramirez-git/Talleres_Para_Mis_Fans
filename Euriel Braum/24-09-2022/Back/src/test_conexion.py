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
    # To close the connection
    conn.close() # Cerrar la conexión

# Driver Code
if __name__ == "__main__": # Si el archivo se ejecuta directamente
    mysqlconnect() # Llamar a la función para conectar con la base de datos
