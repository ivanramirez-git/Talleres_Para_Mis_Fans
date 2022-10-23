
# -- TABLA products: id, name, description, price, stock, category_id(fk), image
# CREATE TABLE IF NOT EXISTS `products` (
#   `id` int(11) NOT NULL AUTO_INCREMENT,
#   `name` varchar(50) NOT NULL,
#   `description` varchar(255) NOT NULL,
#   `price` decimal(10, 2) NOT NULL,
#   `stock` int(11) NOT NULL,
#   `category_id` int(11) NOT NULL,
#   `image` varchar(255) NOT NULL,
#   PRIMARY KEY (`id`),
#   KEY `category_id` (`category_id`),
#   CONSTRAINT `products_ibfk_1` FOREIGN KEY (`category_id`) REFERENCES `categories` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
# ) ENGINE = InnoDB DEFAULT CHARSET = utf8;

class Product: # Clase Producto
    def __init__(self, id, name='', description='', price=0, stock=0, category_id=0, image=''): # Constructor
        self.id = id # Id del producto
        self.name = name # Nombre del producto
        self.description = description # Descripción del producto
        self.price = price # Precio del producto
        self.stock = stock # Stock del producto
        self.category_id = category_id # Id de la categoría a la que pertenece el producto
        self.image = image # Imagen del producto

    def __str__(self): # Método toString
        return f'Product: {self.id}, {self.name}, {self.description}, {self.price}, {self.stock}, {self.category_id}, {self.image}' # Devuelve el producto en formato string

    def save(self, db): # Método para guardar un producto en la base de datos
        # Consultamos si existe un producto con el mismo nombre
        if self.get_by_name(db, self.name) is None: # Si no existe
            try: # Intentamos guardar el producto
                cursor = db.connection.cursor()  # Creamos el cursor
                sql = """INSERT INTO products (name, description, price, stock, category_id, image) VALUES ('{}', '{}', {}, {}, {}, '{}')""".format(self.name, self.description, self.price, self.stock, self.category_id, self.image) # Creamos la consulta
                cursor.execute(sql) # Ejecutamos la consulta
                db.connection.commit() # Guardamos los cambios
                return True # Devolvemos True
            except Exception as ex: # Si hay algún error
                raise Exception(ex) # Devolvemos el error
        else: # Si existe
            return False # Devolvemos False

    def update(self, db): # Método para actualizar un producto
        try: # Intentamos actualizar el producto
            cursor = db.connection.cursor() # Creamos el cursor
            sql = """UPDATE products SET name = '{}', description = '{}', price = {}, stock = {}, category_id = {}, image = '{}' WHERE id = {}""".format(self.name, self.description, self.price, self.stock, self.category_id, self.image, self.id) # Creamos la consulta
            cursor.execute(sql) # Ejecutamos la consulta
            db.connection.commit() # Guardamos los cambios
            return True # Devolvemos True
        except Exception as ex: # Si hay algún error
            raise Exception(ex) # Devolvemos el error

    def delete(self, db): # Método para eliminar un producto
        try: # Intentamos eliminar el producto
            cursor = db.connection.cursor() # Creamos el cursor
            sql = """DELETE FROM products WHERE id = {}""".format(self.id) # Creamos la consulta
            cursor.execute(sql) # Ejecutamos la consulta
            db.connection.commit() # Guardamos los cambios
            return True # Devolvemos True
        except Exception as ex: # Si hay algún error
            raise Exception(ex) # Devolvemos el error

    @classmethod # Método estático
    def get_all(self, db): # Método para obtener todos los productos
        try: # Intentamos obtener los productos
            cursor = db.connection.cursor() # Creamos el cursor
            sql = """SELECT * FROM products""" # Creamos la consulta
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchall() # Obtenemos los datos
            products = [] # Creamos un array de productos
            product_aux = {} # Creamos un diccionario auxiliar
            for product in data: # Recorremos los productos
                product_aux['id'] = product[0] # Guardamos el id
                product_aux['name'] = product[1]  # Guardamos el nombre
                product_aux['description'] = product[2] # Guardamos la descripción
                product_aux['price'] = product[3] # Guardamos el precio
                product_aux['stock'] = product[4] # Guardamos el stock
                product_aux['category_id'] = product[5] # Guardamos el id de la categoría
                product_aux['image'] = product[6] # Guardamos la imagen
                products.append(product_aux) # Añadimos el producto al array
                product_aux = {} # Vaciamos el diccionario auxiliar

            return products # Devolvemos el array de productos
        except Exception as ex: # Si hay algún error
            raise Exception(ex) # Devolvemos el error

    @classmethod # Método estático
    def get_by_id(self, db, id): # Método para obtener un producto por su id
        try: # Intentamos obtener el producto
            cursor = db.connection.cursor() # Creamos el cursor
            sql = """SELECT * FROM products WHERE id = {}""".format(id) # Creamos la consulta
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            if data is not None: # Si existe el producto
                product = Product(data[0], data[1], data[2], data[3], data[4], data[5], data[6]) # Creamos el producto
            else: # Si no existe
                product = None  # Devolvemos None
            return product # Devolvemos el producto
        except Exception as ex: # Si hay algún error
            raise Exception(ex) # Devolvemos el error

    @classmethod # Método estático
    def get_by_name(self, db, name): # Método para obtener un producto por su nombre
        try: # Intentamos obtener el producto
            cursor = db.connection.cursor() # Creamos el cursor
            sql = """SELECT * FROM products WHERE name = '{}'""".format(name) # Creamos la consulta
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchone() # Obtenemos los datos
            product = {} # Creamos un diccionario
            if data is not None: # Si existe el producto
                product['id'] = data[0]  # Guardamos el id
                product['name'] = data[1]  # Guardamos el nombre
                product['description'] = data[2] # Guardamos la descripción
                product['price'] = data[3] # Guardamos el precio
                product['stock'] = data[4] # Guardamos el stock
                product['category_id'] = data[5] # Guardamos el id de la categoría
                product['image'] = data[6] # Guardamos la imagen
            else: # Si no existe
                product = None # Devolvemos None
            return product # Devolvemos el producto
        except Exception as ex: # Si hay algún error
            raise Exception(ex) # Devolvemos el error

        # Get by category

    @classmethod # Método estático
    def get_by_category(self, db, category_id): # Método para obtener los productos por su categoría
        try: # Intentamos obtener los productos
            cursor = db.connection.cursor() # Creamos el cursor
            sql = """SELECT * FROM products WHERE category_id = {}""".format(category_id) # Creamos la consulta
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchall()  # Obtenemos los datos
            products = [] # Creamos un array de productos
            product_aux = {}  # Creamos un diccionario auxiliar
            for product in data: # Recorremos los productos
                product_aux['id'] = product[0] # Guardamos el id
                product_aux['name'] = product[1] # Guardamos el nombre
                product_aux['description'] = product[2] # Guardamos la descripción
                product_aux['price'] = product[3] # Guardamos el precio
                product_aux['stock'] = product[4] # Guardamos el stock
                product_aux['category_id'] = product[5] # Guardamos el id de la categoría
                product_aux['image'] = product[6] # Guardamos la imagen
                products.append(product_aux) # Añadimos el producto al array
                product_aux = {} # Vaciamos el diccionario auxiliar

            return products # Devolvemos el array de productos
        except Exception as ex: # Si hay algún error
            raise Exception(ex) # Devolvemos el error

    # Get by pagination
    @classmethod # Método estático
    def get_by_pagination(self, db, page, per_page): # Método para obtener los productos por paginación
        try: # Intentamos obtener los productos
            cursor = db.connection.cursor() # Creamos el cursor
            sql = """SELECT * FROM products LIMIT {}, {}""".format(page, per_page) # Creamos la consulta
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchall() # Obtenemos los datos
            products = [] # Creamos un array de productos
            product_aux = {} # Creamos un diccionario auxiliar
            for product in data: # Recorremos los productos
                product_aux['id'] = product[0] # Guardamos el id
                product_aux['name'] = product[1] # Guardamos el nombre
                product_aux['description'] = product[2] # Guardamos la descripción
                product_aux['price'] = product[3] # Guardamos el precio
                product_aux['stock'] = product[4] # Guardamos el stock
                product_aux['category_id'] = product[5] # Guardamos el id de la categoría
                product_aux['image'] = product[6] # Guardamos la imagen
                products.append(product_aux) # Añadimos el producto al array
                product_aux = {} # Vaciamos el diccionario auxiliar

            return products # Devolvemos el array de productos
        except Exception as ex: # Si hay algún error
            raise Exception(ex) # Devolvemos el error

    # Get by search
    @classmethod # Método estático
    def get_by_search(self, db, search): # Método para obtener los productos por búsqueda
        try: # Intentamos obtener los productos
            cursor = db.connection.cursor() # Creamos el cursor
            sql = """SELECT * FROM products WHERE name LIKE '%{}%'""".format(search) # Creamos la consulta
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchall() # Obtenemos los datos
            products = [] # Creamos un array de productos
            product_aux = {} # Creamos un diccionario auxiliar
            for product in data: # Recorremos los productos
                product_aux['id'] = product[0] # Guardamos el id
                product_aux['name'] = product[1] # Guardamos el nombre
                product_aux['description'] = product[2] # Guardamos la descripción
                product_aux['price'] = product[3] # Guardamos el precio
                product_aux['stock'] = product[4] # Guardamos el stock 
                product_aux['category_id'] = product[5] # Guardamos el id de la categoría
                product_aux['image'] = product[6] # Guardamos la imagen
                products.append(product_aux) # Añadimos el producto al array
                product_aux = {} # Vaciamos el diccionario auxiliar

            return products # Devolvemos el array de productos
        except Exception as ex: # Si hay algún error
            raise Exception(ex) # Devolvemos el error

    # Get by search and category
    @classmethod # Método estático
    def get_by_search_and_category(self, db, search, category_id): # Método para obtener los productos por búsqueda y categoría
        try: # Intentamos obtener los productos
            cursor = db.connection.cursor() # Creamos el cursor
            sql = """SELECT * FROM products WHERE name LIKE '%{}%' AND category_id = {}""".format(search, category_id) # Creamos la consulta
            cursor.execute(sql) # Ejecutamos la consulta
            data = cursor.fetchall() # Obtenemos los datos
            products = [] # Creamos un array de productos
            product_aux = {} # Creamos un diccionario auxiliar
            for product in data: # Recorremos los productos
                product_aux['id'] = product[0] # Guardamos el id
                product_aux['name'] = product[1] # Guardamos el nombre
                product_aux['description'] = product[2] # Guardamos la descripción
                product_aux['price'] = product[3] # Guardamos el precio
                product_aux['stock'] = product[4] # Guardamos el stock
                product_aux['category_id'] = product[5] # Guardamos el id de la categoría
                product_aux['image'] = product[6] # Guardamos la imagen
                products.append(product_aux) # Añadimos el producto al array
                product_aux = {} # Vaciamos el diccionario auxiliar

            return products # Devolvemos el array de productos
        except Exception as ex: # Si hay algún error
            raise Exception(ex) # Devolvemos el error

    # Decrease stock
    @classmethod # Método estático
    def decrease_stock(self, db, id, quantity): # Método para disminuir el stock
        try: # Intentamos disminuir el stock
            cursor = db.connection.cursor() # Creamos el cursor
            sql = """UPDATE products SET stock = stock - {} WHERE id = {}""".format(quantity, id) # Creamos la consulta
            cursor.execute(sql) # Ejecutamos la consulta
            db.connection.commit() # Guardamos los cambios
            return True # Devolvemos True
        except Exception as ex: # Si hay algún error
            raise Exception(ex) # Devolvemos el error
 

# Abstract Product class
# Name: Product
# Attributes:
"""
+ id: int
+ name: str
+ description: str
+ price: float
+ stock: int
+ category_id: int
+ image: str
"""
# Methods:
"""
+ get_by_id(self, db, id)
+ get_by_name(self, db, name)
+ get_by_category(self, db, category_id)
+ get_by_pagination(self, db, page, per_page)
+ get_by_search(self, db, search)
+ get_by_search_and_category(self, db, search, category_id)
+ decrease_stock(self, db, id, quantity)
"""
