
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

from .entities.Product import Product
from .entities.User import User


class ModelProduct:

    # Save, only admins can do this

    @classmethod
    def save(self, db, product: Product, user: User):
        if user.is_admin(db):
            if product.save(db):
                return 200
            else:
                return 409
        else:
            return 401

    # Update, only admins can do this

    @classmethod
    def update(self, db, product: Product, user: User):
        if user.is_admin(db):
            if product.update(db):
                return 200
            else:
                return 409
        else:
            return 401

    # Delete, only admins can do this

    @classmethod
    def delete(self, db, product: Product, user: User):
        if user.is_admin(db):
            if product.delete(db):
                return 200
            else:
                return 409
        else:
            return 401

    # Get all products

    @classmethod
    def get_all(self, db):
        try:
            return Product.get_all(db)
        except Exception as ex:
            raise Exception(ex)

    # Get product by id

    @classmethod
    def get_by_id(self, db, id):
        try:
            return Product.get_by_id(db, id)
        except Exception as ex:
            raise Exception(ex)

    # Get product by name

    @classmethod
    def get_by_name(self, db, name):
        try:
            return Product.get_by_name(db, name)
        except Exception as ex:
            raise Exception(ex)

    # Get products by category

    @classmethod
    def get_by_category(self, db, category_id):
        try:
            return Product.get_by_category(db, category_id)
        except Exception as ex:
            raise Exception(ex)

    # Get products by pagination

    @classmethod
    def get_by_pagination(self, db, offset, limit):
        try:
            return Product.get_by_pagination(db, offset, limit)
        except Exception as ex:
            raise Exception(ex)

    # Get products by search

    @classmethod
    def get_by_search(self, db, search):
        try:
            return Product.get_by_search(db, search)
        except Exception as ex:
            raise Exception(ex)

    # Get products by search and category

    @classmethod
    def get_by_search_and_category(self, db, search, category_id):
        try:
            return Product.get_by_search_and_category(db, search, category_id)

        except Exception as ex:
            raise Exception(ex)

    # Decrease stock

    @classmethod
    def decrease_stock(self, db, product: Product, quantity):
        try:
            return product.decrease_stock(db, quantity)
        except Exception as ex:
            raise Exception(ex)


# Path: src\models\ModelProduct.py
# Abstract model
# Name: ModelProduct
# Description: Product model
# Class methods: save, delete, update, get_all, get_by_id, get_by_name, get_by_category, get_by_pagination, get_by_search, get_by_search_and_category, decrease_stock
