

# cur.execute("CREATE TABLE IF NOT EXISTS `groups` (`id` int(11) NOT NULL AUTO_INCREMENT,`name` varchar(50) NOT NULL,`team_1` int(11) NOT NULL,`team_2` int(11) NOT NULL,`team_3` int(11) NOT NULL,`team_4` int(11) NOT NULL,PRIMARY KEY (`id`),UNIQUE KEY `name` (`name`),KEY `team_1` (`team_1`),KEY `team_2` (`team_2`),KEY `team_3` (`team_3`),KEY `team_4` (`team_4`),CONSTRAINT `groups_ibfk_1` FOREIGN KEY (`team_1`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `groups_ibfk_2` FOREIGN KEY (`team_2`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `groups_ibfk_3` FOREIGN KEY (`team_3`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,CONSTRAINT `groups_ibfk_4` FOREIGN KEY (`team_4`) REFERENCES `teams` (`id`) ON DELETE CASCADE ON UPDATE CASCADE) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;")
class Group: # Clase para los grupos
    def __init__(self, id, name, team_1, team_2, team_3, team_4): # Constructor
        self.id = id # Asignamos el id
        self.name = name # Asignamos el nombre
        self.team_1 = team_1 # Asignamos el primer equipo
        self.team_2 = team_2 # Asignamos el segundo equipo
        self.team_3 = team_3 # Asignamos el tercer equipo
        self.team_4 = team_4 # Asignamos el cuarto equipo

    def __str__(self): # Método para convertir a string
        return "Group: {} - {} - {} - {} - {} - {}".format(self.id, self.name, self.team_1, self.team_2, self.team_3, self.team_4) # Devolvemos el string

    def save(self, db): # Método para guardar un grupo
        try: # Intentamos, validar que los equipos no pertenezcan a otro grupo
            cursor = db.connection.cursor() # Obtenemos el cursor
            # validamos que los equipos no pertenezcan a otro grupo
            sql = """SELECT * FROM groups WHERE team_1 = {} OR team_2 = {} OR team_3 = {} OR team_4 = {}""".format(self.team_1, self.team_1, self.team_1, self.team_1) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None: # Si hay datos
                return False # Devolvemos False
            sql = """SELECT * FROM groups WHERE team_1 = {} OR team_2 = {} OR team_3 = {} OR team_4 = {}""".format(self.team_2, self.team_2, self.team_2, self.team_2) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None: # Si hay datos
                return False # Devolvemos False
            sql = """SELECT * FROM groups WHERE team_1 = {} OR team_2 = {} OR team_3 = {} OR team_4 = {}""".format(self.team_3, self.team_3, self.team_3, self.team_3) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None: # Si hay datos
                return False # Devolvemos False
            sql = """SELECT * FROM groups WHERE team_1 = {} OR team_2 = {} OR team_3 = {} OR team_4 = {}""".format(self.team_4, self.team_4, self.team_4, self.team_4) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None: # Si hay datos
                return False # Devolvemos False
            sql = """INSERT INTO groups (name, team_1, team_2, team_3, team_4) VALUES ('{}', {}, {}, {}, {})""".format(self.name, self.team_1, self.team_2, self.team_3, self.team_4) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            db.connection.commit() # Guardamos los cambios
            return True # Devolvemos True
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    def update(self, db): # Método para actualizar un grupo
        try: # Intentamos, validar que los equipos no pertenezcan a otro grupo
            cursor = db.connection.cursor() # Obtenemos el cursor
            # validamos que los equipos no pertenezcan a otro grupo
            sql = """SELECT * FROM groups WHERE team_1 = {} OR team_2 = {} OR team_3 = {} OR team_4 = {}""".format(self.team_1, self.team_1, self.team_1, self.team_1) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None and data[0] != self.id: # Si hay datos y el id es diferente
                return False # Devolvemos el error
            sql = """SELECT * FROM groups WHERE team_1 = {} OR team_2 = {} OR team_3 = {} OR team_4 = {}""".format(self.team_2, self.team_2, self.team_2, self.team_2) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None and data[0] != self.id: # Si hay datos y el id es diferente
                return False # Devolvemos el error
            sql = """SELECT * FROM groups WHERE team_1 = {} OR team_2 = {} OR team_3 = {} OR team_4 = {}""".format(self.team_3, self.team_3, self.team_3, self.team_3) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None and data[0] != self.id: # Si hay datos y el id es diferente
                return False # Devolvemos el error
            sql = """SELECT * FROM groups WHERE team_1 = {} OR team_2 = {} OR team_3 = {} OR team_4 = {}""".format(self.team_4, self.team_4, self.team_4, self.team_4) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None and data[0] != self.id: # Si hay datos y el id es diferente
                return False # Devolvemos el error
            sql = """UPDATE groups SET name = '{}', team_1 = {}, team_2 = {}, team_3 = {}, team_4 = {} WHERE id = {}""".format(self.name, self.team_1, self.team_2, self.team_3, self.team_4, self.id) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            db.connection.commit() # Guardamos los cambios
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    def delete(self, db): # Método para eliminar un grupo
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor

            # Eliminar todos los datos de la tabla matches_group
            # sql = """DELETE FROM matches_group"""
            # cursor.execute(sql)
            # db.connection.commit()

            sql = """DELETE FROM groups WHERE id = {}""".format(self.id) # Consulta SQL
            print('SQL: ', sql)
            cursor.execute(sql) # Ejecutamos la consulta
            db.connection.commit() # Guardamos los cambios
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    def get(self, db): # Método para obtener un grupo
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """SELECT * FROM groups WHERE id = {}""".format(self.id) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None: # Si hay datos
                self.id = data[0] # Asignamos el id
                self.name = data[1] # Asignamos el nombre
                self.team_1 = data[2] # Asignamos el equipo 1
                self.team_2 = data[3] # Asignamos el equipo 2
                self.team_3 = data[4] # Asignamos el equipo 3
                self.team_4 = data[5] # Asignamos el equipo 4
            else: # Si no hay datos
                return None # Devolvemos None
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    @classmethod
    def get_all(self, db): # Método para obtener todos los grupos
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """SELECT * FROM groups""" # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchall() # Obtenemos los datos
            return data # Devolvemos los datos
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    def get_teams_by_name(self, db): # Método para obtener los equipos de un grupo con el nombre del grupo
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """SELECT * FROM groups WHERE name = '{}'""".format(self.name) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None: # Si hay datos
                self.id = data[0] # Asignamos el id
                self.name = data[1] # Asignamos el nombre
                self.team_1 = data[2] # Asignamos el equipo 1
                self.team_2 = data[3] # Asignamos el equipo 2
                self.team_3 = data[4] # Asignamos el equipo 3
                self.team_4 = data[5] # Asignamos el equipo 4
            else: # Si no hay datos
                return None # Devolvemos None
            sql = """SELECT * FROM teams WHERE id = {} OR id = {} OR id = {} OR id = {}""".format(self.team_1, self.team_2, self.team_3, self.team_4) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchall() # Obtenemos los datos
            return data # Devolvemos los datos
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    def get_teams_by_id(self, db): # Método para obtener los equipos de un grupo con el id del grupo
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """SELECT * FROM groups WHERE id = {}""".format(self.id) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None: # Si hay datos
                self.id = data[0] # Asignamos el id
                self.name = data[1] # Asignamos el nombre
                self.team_1 = data[2] # Asignamos el equipo 1
                self.team_2 = data[3] # Asignamos el equipo 2
                self.team_3 = data[4] # Asignamos el equipo 3
                self.team_4 = data[5] # Asignamos el equipo 4
            else: # Si no hay datos
                return None # Devolvemos None
            sql = """SELECT * FROM teams WHERE id = {} OR id = {} OR id = {} OR id = {}""".format(self.team_1, self.team_2, self.team_3, self.team_4) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchall() # Obtenemos los datos
            return data # Devolvemos los datos
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    @classmethod
    def get_count(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT COUNT(*) FROM groups"""
            cursor.execute(sql)
            data = cursor.fetchone()
            return data[0]
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_teams_without_group(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM teams WHERE id NOT IN (SELECT team_1 FROM groups) AND id NOT IN (SELECT team_2 FROM groups) AND id NOT IN (SELECT team_3 FROM groups) AND id NOT IN (SELECT team_4 FROM groups)"""
            cursor.execute(sql)
            data = cursor.fetchall()
            return data
        except Exception as ex:
            raise Exception(ex)

# Abstract class
# Name: Group
# Description: Class for the groups of the tournament
# Atributes: id, name, team_1, team_2, team_3, team_4
# Methods: __init__, __str__, __repr__, save, update, delete, get, get_all, get_teams_by_name, get_teams_by_id, get_count


