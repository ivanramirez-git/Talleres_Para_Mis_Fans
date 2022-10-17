
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

from .entities.Order import Order
from .entities.User import User
from .entities.Product import Product


class ModelOrder:

    # add_product_to_order(self, db, user: User, product: Product, quantity: int):
    # only users logged can do this
    @classmethod
    def add_product_to_order(self, db, user: User, product: Product, quantity: int):
        if user.is_logged(db):
            order = Order(None, user.id)
            if order.add_product_to_order(db, user, product, quantity):
                return 200
            else:
                return 409
        else:
            return 401

    # get_all(db, user)
    # only users logged can do this

    @classmethod
    def get_all(self, db, user: User):
        if user.is_logged(db):
            return Order.get_all(db, user)
        else:
            return 401

    # .close_order(db, user)
    # only users logged can do this

    @classmethod
    def close_order(self, db, user: User):
        if user.is_logged(db):
            order = Order(None, user.id)
            if order.close_order(db, user):
                return 200
            else:
                return 409
        else:
            return 401


# Abstract
# Name: ModelOrder
# Attributes: None
# Methods:
"""
+ add_product_to_order(self, db, user: User, product: Product, quantity: int)
+ get_all(db, user)
+ close_order(db, user)
"""
