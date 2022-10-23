
# -- TABLA orders: id, user_id(fk), total, created_at, status
# CREATE TABLE IF NOT EXISTS `orders` (
#   `id` int(11) NOT NULL AUTO_INCREMENT,
#   `user_id` int(11) NOT NULL,
#   `total` decimal(10, 2) NOT NULL,
#   `created_at` datetime NOT NULL,
#   `status` varchar(50) NOT NULL,
#   PRIMARY KEY (`id`),
#   KEY `user_id` (`user_id`),
#   CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
# ) ENGINE = InnoDB DEFAULT CHARSET = utf8;

# Abstract class
# Name: Order
# Attributes: id, user_id, total, created_at, status
# Methods: save, update, delete
# Class methods: get_all, get_by_id, get_by_user, get_by_status, get_by_date

from .entities.Order import Order # Importamos la clase Order
from .entities.User import User # Importamos la clase User
from .entities.Product import Product # Importamos la clase Product


class ModelOrder: # Creamos la clase ModelOrder
    # add_product_to_order(self, db, user: User, product: Product, quantity: int):
    # only users logged can do this
    @classmethod # Creamos el método add_product_to_order
    def add_product_to_order(self, db, user: User, product: Product, quantity: int): # Creamos el método add_product_to_order
        if user.is_logged(db): # Si el usuario está logueado
            order = Order(None, user.id) # Creamos un objeto de la clase Order
            if order.add_product_to_order(db, user, product, quantity): # Si el método add_product_to_order de la clase Order devuelve True
                return 200 # Devolvemos 200
            else: # Si no
                return 409 # Devolvemos 409
        else: # Si no
            return 401 # Devolvemos 401

    # get_all(db, user)
    # only users logged can do this

    @classmethod # Creamos el método get_all
    def get_all(self, db, user: User): # Creamos el método get_all
        if user.is_logged(db): # Si el usuario está logueado
            return Order.get_all(db, user) # Devolvemos el método get_all de la clase Order
        else: # Si no
            return 401 # Devolvemos 401

    # .close_order(db, user)
    # only users logged can do this

    @classmethod # Creamos el método close_order
    def close_order(self, db, user: User): # Creamos el método close_order
        if user.is_logged(db): # Si el usuario está logueado 
            order = Order(None, user.id) # Creamos un objeto de la clase Order
            if order.close_order(db, user): # Si el método close_order de la clase Order devuelve True
                return 200 # Devolvemos 200
            else: # Si no
                return 409 # Devolvemos 409
        else: # Si no
            return 401 # Devolvemos 401


# Abstract
# Name: ModelOrder
# Attributes: None
# Methods:
"""
+ add_product_to_order(self, db, user: User, product: Product, quantity: int)
+ get_all(db, user)
+ close_order(db, user)
"""
