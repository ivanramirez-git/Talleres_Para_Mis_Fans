
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

class Product:
    def __init__(self, id, name='', description='', price=0, stock=0, category_id=0, image=''):
        self.id = id
        self.name = name
        self.description = description
        self.price = price
        self.stock = stock
        self.category_id = category_id
        self.image = image

    def __str__(self):
        return f'Product: {self.id}, {self.name}, {self.description}, {self.price}, {self.stock}, {self.category_id}, {self.image}'

    def save(self, db):
        # Consultamos si existe un producto con el mismo nombre
        if self.get_by_name(db, self.name) is None:
            try:
                cursor = db.connection.cursor()
                sql = """INSERT INTO products (name, description, price, stock, category_id, image) VALUES ('{}', '{}', {}, {}, {}, '{}')""".format(
                    self.name, self.description, self.price, self.stock, self.category_id, self.image)
                cursor.execute(sql)
                db.connection.commit()
                return True
            except Exception as ex:
                raise Exception(ex)
        else:
            return False

    def update(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """UPDATE products SET name = '{}', description = '{}', price = {}, stock = {}, category_id = {}, image = '{}' WHERE id = {}""".format(
                self.name, self.description, self.price, self.stock, self.category_id, self.image, self.id)
            cursor.execute(sql)
            db.connection.commit()
            return True
        except Exception as ex:
            raise Exception(ex)

    def delete(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """DELETE FROM products WHERE id = {}""".format(self.id)
            cursor.execute(sql)
            db.connection.commit()
            return True
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_all(self, db):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM products"""
            cursor.execute(sql)
            data = cursor.fetchall()
            products = []
            product_aux = {}
            for product in data:
                product_aux['id'] = product[0]
                product_aux['name'] = product[1]
                product_aux['description'] = product[2]
                product_aux['price'] = product[3]
                product_aux['stock'] = product[4]
                product_aux['category_id'] = product[5]
                product_aux['image'] = product[6]
                products.append(product_aux)
                product_aux = {}

            return products
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_by_id(self, db, id):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM products WHERE id = {}""".format(id)
            cursor.execute(sql)
            data = cursor.fetchone()
            if data is not None:
                product = Product(data[0], data[1], data[2],
                                  data[3], data[4], data[5], data[6])
            else:
                product = None
            return product
        except Exception as ex:
            raise Exception(ex)

    @classmethod
    def get_by_name(self, db, name):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM products WHERE name = '{}'""".format(name)
            cursor.execute(sql)
            data = cursor.fetchone()
            product = {}
            if data is not None:
                product['id'] = data[0]
                product['name'] = data[1]
                product['description'] = data[2]
                product['price'] = data[3]
                product['stock'] = data[4]
                product['category_id'] = data[5]
                product['image'] = data[6]
            else:
                product = None
            return product
        except Exception as ex:
            raise Exception(ex)

        # Get by category

    @classmethod
    def get_by_category(self, db, category_id):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM products WHERE category_id = {}""".format(
                category_id)
            cursor.execute(sql)
            data = cursor.fetchall()
            products = []
            product_aux = {}
            for product in data:
                product_aux['id'] = product[0]
                product_aux['name'] = product[1]
                product_aux['description'] = product[2]
                product_aux['price'] = product[3]
                product_aux['stock'] = product[4]
                product_aux['category_id'] = product[5]
                product_aux['image'] = product[6]
                products.append(product_aux)
                product_aux = {}

            return products
        except Exception as ex:
            raise Exception(ex)

    # Get by pagination
    @classmethod
    def get_by_pagination(self, db, page, per_page):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM products LIMIT {}, {}""".format(
                page, per_page)
            cursor.execute(sql)
            data = cursor.fetchall()
            products = []
            product_aux = {}
            for product in data:
                product_aux['id'] = product[0]
                product_aux['name'] = product[1]
                product_aux['description'] = product[2]
                product_aux['price'] = product[3]
                product_aux['stock'] = product[4]
                product_aux['category_id'] = product[5]
                product_aux['image'] = product[6]
                products.append(product_aux)
                product_aux = {}

            return products
        except Exception as ex:
            raise Exception(ex)

    # Get by search
    @classmethod
    def get_by_search(self, db, search):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM products WHERE name LIKE '%{}%'""".format(
                search)
            cursor.execute(sql)
            data = cursor.fetchall()
            products = []
            product_aux = {}
            for product in data:
                product_aux['id'] = product[0]
                product_aux['name'] = product[1]
                product_aux['description'] = product[2]
                product_aux['price'] = product[3]
                product_aux['stock'] = product[4]
                product_aux['category_id'] = product[5]
                product_aux['image'] = product[6]
                products.append(product_aux)
                product_aux = {}

            return products
        except Exception as ex:
            raise Exception(ex)

    # Get by search and category
    @classmethod
    def get_by_search_and_category(self, db, search, category_id):
        try:
            cursor = db.connection.cursor()
            sql = """SELECT * FROM products WHERE name LIKE '%{}%' AND category_id = {}""".format(
                search, category_id)
            cursor.execute(sql)
            data = cursor.fetchall()
            products = []
            product_aux = {}
            for product in data:
                product_aux['id'] = product[0]
                product_aux['name'] = product[1]
                product_aux['description'] = product[2]
                product_aux['price'] = product[3]
                product_aux['stock'] = product[4]
                product_aux['category_id'] = product[5]
                product_aux['image'] = product[6]
                products.append(product_aux)
                product_aux = {}

            return products
        except Exception as ex:
            raise Exception(ex)

    # Decrease stock
    @classmethod
    def decrease_stock(self, db, id, quantity):
        try:
            cursor = db.connection.cursor()
            sql = """UPDATE products SET stock = stock - {} WHERE id = {}""".format(
                quantity, id)
            cursor.execute(sql)
            db.connection.commit()
            return True
        except Exception as ex:
            raise Exception(ex)

# Abstract class
# Name: Product
# Description: Product entity
# Attributes: id, name, description, price, stock, category_id, image
# Methods: save, delete, update
# Class methods: get_all, get_by_id, get_by_name, get_by_category, get_by_pagination, get_by_search, get_by_search_and_category, decrease_stock
