
# -- TABLA categories: id, name, description
# CREATE TABLE IF NOT EXISTS `categories` (
#   `id` int(11) NOT NULL AUTO_INCREMENT,
#   `name` varchar(50) NOT NULL,
#   `description` varchar(255) NOT NULL,
#   PRIMARY KEY (`id`)
# ) ENGINE = InnoDB DEFAULT CHARSET = utf8;

class Category: # Clase Category
    def __init__(self, id, name='', description=''): # Constructor
        self.id = id # id de la categoría
        self.name = name # nombre de la categoría
        self.description = description # descripción de la categoría

    def __str__(self): # Método toString
        return f'Category: {self.id}, {self.name}, {self.description}'  # Devuelve una cadena con los datos de la categoría

    def save(self, db): # Método para guardar una categoría en la base de datos
        # Consultamos si existe una categoría con el mismo nombre
        if self.get_by_name(db, self.name) is None: # Si no existe
            try: # Intentamos
                cursor = db.connection.cursor() # Obtenemos el cursor
                sql = """INSERT INTO categories (name, description) VALUES ('{}', '{}')""".format(self.name, self.description) # Consulta SQL
                cursor.execute(sql) # Ejecutamos la consulta
                db.connection.commit() # Guardamos los cambios
                return True  # Devolvemos True
            except Exception as ex: # Si hay un error
                raise Exception(ex) # Lo devolvemos
        else: # Si existe
            return False # Devolvemos False

    def update(self, db): # Método para actualizar una categoría
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """UPDATE categories SET name = '{}', description = '{}' WHERE id = {}""".format(self.name, self.description, self.id) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            db.connection.commit() # Guardamos los cambios
            return True # Devolvemos True
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    def delete(self, db): # Método para eliminar una categoría
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """DELETE FROM categories WHERE id = {}""".format(self.id) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            db.connection.commit() # Guardamos los cambios
            return True # Devolvemos True
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    @classmethod # Método estático
    def get_all(cls, db): # Método para obtener todas las categorías
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """SELECT * FROM categories""" # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchall() # Obtenemos los datos
            categories = [] # Creamos un array para las categorías
            category_aux = {} # Creamos un diccionario para la categoría
            for category in data:  # Recorremos los datos
                category_aux['id'] = category[0] # Asignamos el id
                category_aux['name'] = category[1] # Asignamos el nombre
                category_aux['description'] = category[2] # Asignamos la descripción
                categories.append(category_aux) # Añadimos la categoría al array
                category_aux = {} # Vaciamos el diccionario

            return categories # Devolvemos el array de categorías
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos

    @classmethod # Método estático
    def get_by_id(cls, db, id):  # Método para obtener una categoría por su id
        try: # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """SELECT * FROM categories WHERE id = {}""".format(id) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            category = {}   # Creamos un diccionario para la categoría
            if data is not None:    # Si hay datos
                category['id'] = data[0]    # Asignamos el id
                category['name'] = data[1] # Asignamos el nombre
                category['description'] = data[2]  # Asignamos la descripción
            else:  # Si no hay datos
                category = None # Devolvemos None
            return category # Devolvemos la categoría
        except Exception as ex:  # Si hay un error
            raise Exception(ex) # Lo devolvemos

    @classmethod # Método estático
    def get_by_name(cls, db, name): # Método para obtener una categoría por su nombre
        try:  # Intentamos
            cursor = db.connection.cursor() # Obtenemos el cursor
            sql = """SELECT * FROM categories WHERE name = '{}'""".format(name) # Consulta SQL
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            category = {} # Creamos un diccionario para la categoría
            if data is not None: # Si hay datos
                category['id'] = data[0] # Asignamos el id
                category['name'] = data[1] # Asignamos el nombre
                category['description'] = data[2] # Asignamos la descripción
            else: # Si no hay datos
                category = None # Devolvemos None
            return category # Devolvemos la categoría
        except Exception as ex: # Si hay un error
            raise Exception(ex) # Lo devolvemos


# Abstract class
# Name: Category
# Description: Category entity
# Attributes: id, name, description
# Methods: __init__, __str__, save, update, delete, get_all, get_by_id, get_by_name
