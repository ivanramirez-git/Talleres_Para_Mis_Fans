
# CREATE TABLE IF NOT EXISTS `teams` (`id` int(11) NOT NULL AUTO_INCREMENT,`name` varchar(50) NOT NULL,PRIMARY KEY (`id`),UNIQUE KEY `name` (`name`)) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;

class Team: # Clase para los equipos
    def __init__(self, id, name): # Constructor
        self.id = id # Asignamos el id
        self.name = name # Asignamos el nombre

    def __str__(self): # Método para mostrar la información del equipo
        return """Team: {}""".format(self.name) # Devolvemos la información

    def save(self, db): # Método para guardar un equipo
        if self.get_by_name(db, self.name) is None: # Si no existe
            try: # Intentamos
                cursor = db.connection.cursor() # Obtenemos el cursor
                sql = """INSERT INTO teams (name) VALUES ('{}')""".format(self.name) # Consulta SQL
                cursor.execute(sql) # Ejecutamos la consulta
                db.connection.commit() # Guardamos los cambios
                return True # Devolvemos True
            except Exception as ex: # Si hay un error
                raise Exception(ex) # Lo devolvemos
        else: # Si existe
            return False # Devolvemos False

    def update(self, db): # Método para actualizar un equipo
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """UPDATE teams SET name = '{}' WHERE id = {}""".format(self.name, self.id) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            db.connection.commit() # Guardamos los cambios
            return True # Devolvemos True
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    def delete(self, db): # Método para eliminar un equipo
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            # Eliminar todos los datos de la tabla matches_group
            # sql = """DELETE FROM matches_group"""
            # cursor.execute(sql)
            # db.connection.commit()
            
            sql = """DELETE FROM teams WHERE id = {}""".format(self.id) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            db.connection.commit() # Guardamos los cambios
            return True # Devolvemos True
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    @classmethod # Método estático
    def get_all(cls, db): # Método para obtener todos los equipos
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """SELECT * FROM teams""" # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchall() # Obtenemos los datos
            teams = [] # Creamos un array para los equipos
            team_aux = {} # Creamos un diccionario para el equipo
            for team in data: # Recorremos los datos
                team_aux['id'] = team[0] # Asignamos el id
                team_aux['name'] = team[1] # Asignamos el nombre
                teams.append(team_aux) # Añadimos el equipo al array
                team_aux = {} # Vaciamos el diccionario
            return teams # Devolvemos los equipos
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    @classmethod # Método estático
    def get_by_id(cls, db, id): # Método para obtener un equipo por su id
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """SELECT * FROM teams WHERE id = {}""".format(id) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            team = {} # Creamos un diccionario para el equipo
            if data is not None: # Si hay datos
                team['id'] = data[0] # Asignamos el id
                team['name'] = data[1] # Asignamos el nombre
            else: # Si no hay datos
                team = None # Devolvemos None
            return team # Devolvemos el equipo
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    @classmethod # Método estático
    def get_by_name(cls, db, name): # Método para obtener un equipo por su nombre
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """SELECT * FROM teams WHERE name = '{}'""".format(name) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            team = {} # Creamos un diccionario para el equipo
            if data is not None: # Si hay datos
                team['id'] = data[0] # Asignamos el id
                team['name'] = data[1] # Asignamos el nombre
            else: # Si no hay datos
                team = None # Devolvemos None
            return team # Devolvemos el equipo
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    @classmethod # Método estático que devuelve el número de equipos
    def get_count(cls, db): # Método para obtener el número de equipos
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """SELECT COUNT(*) FROM teams""" # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            return data[0] # Devolvemos el número de equipos
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos



# Abstract class
# Name: Team
# Description: Team entity
# Attributes: id, name
# Methods: __init__, __str__, save, update, delete, get_all, get_by_id, get_by_name, get_count

