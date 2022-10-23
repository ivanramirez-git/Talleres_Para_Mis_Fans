
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

# Abstract class
# Name: Product
# Description: Product entity
# Attributes: id, name, description, price, stock, category_id, image
# Methods: save, delete, update
# Class methods: get_all, get_by_id, get_by_name, get_by_category, get_by_pagination, get_by_search, get_by_search_and_category, decrease_stock

from .entities.Product import Product # Importamos la clase Product
from .entities.User import User # Importamos la clase User


class ModelProduct: # Creamos la clase ModelProduct

    # Save, only admins can do this

    @classmethod # Creamos el método save
    def save(self, db, product: Product, user: User): # Creamos el método save
        if user.is_admin(db): # Si el usuario es administrador
            if product.save(db): # Si el método save de la clase Product devuelve True
                return 200  # Devolvemos 200
            else: # Si no
                return 409  # Devolvemos 409
        else: # Si no
            return 401 # Devolvemos 401

    # Update, only admins can do this

    @classmethod # Creamos el método update
    def update(self, db, product: Product, user: User): # Creamos el método update
        if user.is_admin(db): # Si el usuario es administrador
            if product.update(db): # Si el método update de la clase Product devuelve True
                return 200 # Devolvemos 200
            else: # Si no
                return 409 # Devolvemos 409
        else: # Si no
            return 401 # Devolvemos 401

    # Delete, only admins can do this

    @classmethod # Creamos el método delete
    def delete(self, db, product: Product, user: User): # Creamos el método delete
        if user.is_admin(db): # Si el usuario es administrador
            if product.delete(db): # Si el método delete de la clase Product devuelve True
                return 200  # Devolvemos 200
            else:   # Si no
                return 409 # Devolvemos 409
        else: # Si no
            return 401 # Devolvemos 401

    # Get all products

    @classmethod    # Creamos el método get_all
    def get_all(self, db): # Creamos el método get_all
        try: # Intentamos
            return Product.get_all(db) # Devolvemos el método get_all de la clase Product
        except Exception as ex: # Si no
            raise Exception(ex) # Devolvemos el error

    # Get product by id

    @classmethod # Creamos el método get_by_id
    def get_by_id(self, db, id):  # Creamos el método get_by_id
        try:     # Intentamos
            return Product.get_by_id(db, id) # Devolvemos el método get_by_id de la clase Product
        except Exception as ex: # Si no
            raise Exception(ex) # Devolvemos el error

    # Get product by name

    @classmethod # Creamos el método get_by_name
    def get_by_name(self, db, name): # Creamos el método get_by_name
        try: # Intentamos
            return Product.get_by_name(db, name) # Devolvemos el método get_by_name de la clase Product
        except Exception as ex: # Si no
            raise Exception(ex) # Devolvemos el error

    # Get products by category

    @classmethod # Creamos el método get_by_category
    def get_by_category(self, db, category_id): # Creamos el método get_by_category
        try: # Intentamos
            return Product.get_by_category(db, category_id) # Devolvemos el método get_by_category de la clase Product
        except Exception as ex: # Si no
            raise Exception(ex) # Devolvemos el error

    # Get products by pagination

    @classmethod # Creamos el método get_by_pagination
    def get_by_pagination(self, db, offset, limit): # Creamos el método get_by_pagination
        try: # Intentamos
            return Product.get_by_pagination(db, offset, limit) # Devolvemos el método get_by_pagination de la clase Product
        except Exception as ex: # Si no
            raise Exception(ex) # Devolvemos el error

    # Get products by search

    @classmethod # Creamos el método get_by_search
    def get_by_search(self, db, search): # Creamos el método get_by_search
        try: # Intentamos
            return Product.get_by_search(db, search) # Devolvemos el método get_by_search de la clase Product
        except Exception as ex: # Si no
            raise Exception(ex) # Devolvemos el error

    # Get products by search and category

    @classmethod # Creamos el método get_by_search_and_category
    def get_by_search_and_category(self, db, search, category_id): # Creamos el método get_by_search_and_category
        try: # Intentamos
            return Product.get_by_search_and_category(db, search, category_id) # Devolvemos el método get_by_search_and_category de la clase Product

        except Exception as ex: # Si no
            raise Exception(ex) # Devolvemos el error

    # Decrease stock

    @classmethod # Creamos el método decrease_stock
    def decrease_stock(self, db, product: Product, quantity): # Creamos el método decrease_stock
        try:  # Intentamos
            return product.decrease_stock(db, quantity) # Devolvemos el método decrease_stock de la clase Product
        except Exception as ex: # Si no
            raise Exception(ex) # Devolvemos el error


# Path: src\models\ModelProduct.py
# Abstract model
# Name: ModelProduct
# Description: Product model
# Class methods: save, delete, update, get_all, get_by_id, get_by_name, get_by_category, get_by_pagination, get_by_search, get_by_search_and_category, decrease_stock


# Abstract Model Product
# Name: ModelProduct
# Description: Product model
# Class methods:
"""
+ save(self, db, product: Product, user: User)
+ update(self, db, product: Product, user: User)
+ delete(self, db, product: Product, user: User)
+ get_all(self, db)
+ get_by_id(self, db, id)
+ get_by_name(self, db, name)
+ get_by_category(self, db, category_id)
+ get_by_pagination(self, db, offset, limit)
+ get_by_search(self, db, search)
+ get_by_search_and_category(self, db, search, category_id)
+ decrease_stock(self, db, product: Product, quantity)
"""
