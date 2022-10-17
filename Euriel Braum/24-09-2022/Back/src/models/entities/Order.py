

# -- TABLA orders: id, user_id(fk), total, created_at, status
# CREATE TABLE IF NOT EXISTS `orders` (
#   `id` int(11) NOT NULL AUTO_INCREMENT,
#   `user_id` int(11) NOT NULL,
#   `total` decimal(10, 2) NOT NULL,
#   `created_at` datetime NOT NULL,
#   `status` varchar(50) NOT NULL, -- open, closed
#   PRIMARY KEY (`id`),
#   KEY `user_id` (`user_id`),
#   CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
# ) ENGINE = InnoDB DEFAULT CHARSET = utf8;

# -- TABLA orders_detail: id, order_id(fk), product_id(fk), quantity, price
# CREATE TABLE IF NOT EXISTS `orders_detail` (
#   `id` int(11) NOT NULL AUTO_INCREMENT,
#   `order_id` int(11) NOT NULL,
#   `product_id` int(11) NOT NULL,
#   `quantity` int(11) NOT NULL,
#   `price` decimal(10, 2) NOT NULL,
#   PRIMARY KEY (`id`),
#   KEY `order_id` (`order_id`),
#   KEY `product_id` (`product_id`),
#   CONSTRAINT `orders_detail_ibfk_1` FOREIGN KEY (`order_id`) REFERENCES `orders` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
#   CONSTRAINT `orders_detail_ibfk_2` FOREIGN KEY (`product_id`) REFERENCES `products` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
# ) ENGINE = InnoDB DEFAULT CHARSET = utf8;

import datetime
from .User import User
from .Product import Product


class Order:
    def __init__(self, id, user_id, total=0, created_at=None, status='', order_detail=[]):
        self.id = id  # 1
        self.user_id = user_id  # 1
        self.total = total  # 100.00 # if open, total = 0, if closet, total = sum of prices of all products with order_id = id
        self.created_at = created_at  # datetime.datetime.now()
        self.status = status  # open, closed
        # [{"id": 1, "order_id": 1, "product_id": 1, "quantity": 1, "price": 1.00}, ...]
        self.order_detail = order_detail

    def __str__(self):
        return f'Order: {self.id}, {self.user_id}, {self.total}, {self.created_at}, {self.status}, {self.order_detail}'

    def add_product_to_order(self, db, user: User, product: Product, quantity: int):
        # user logged in
        if user.is_logged(db):
            # search if product exists
            if product:
                # get order with status = open and user_id = user.id and set this order to self
                cursor = db.connection.cursor()
                cursor.execute(
                    "SELECT * FROM orders WHERE status = 'open' AND user_id = %s", (user.id,))
                order = cursor.fetchone()
                if order:
                    self.id = order[0]
                    self.user_id = order[1]
                    self.total = order[2]
                    self.created_at = order[3]
                    self.status = order[4]
                else:
                    # create new order with status = open and user_id = user.id and set this order to self
                    cursor.execute(
                        "INSERT INTO orders (user_id, total, created_at, status) VALUES (%s, %s, %s, %s)", (user.id, 0, datetime.datetime.now(), 'open'))
                    db.connection.commit()
                    self.id = cursor.lastrowid
                    self.user_id = user.id
                    self.total = 0
                    self.created_at = datetime.datetime.now()
                    self.status = 'open'

                # search if product exists in order_detail with order_id = self.id
                cursor.execute(
                    "SELECT * FROM orders_detail WHERE order_id = %s AND product_id = %s", (self.id, product.id))
                order_detail = cursor.fetchone()
                if order_detail:
                    # validate quantity
                    if quantity+order_detail[3] > 0:
                        # update quantity and price in order_detail
                        cursor.execute(
                            "UPDATE orders_detail SET quantity = %s, price = %s WHERE order_id = %s AND product_id = %s", (order_detail[3] + quantity, product.price * (quantity + order_detail[3]), self.id, product.id))
                        db.connection.commit()
                    elif quantity+order_detail[3] == 0:
                        # delete product from order_detail
                        cursor.execute(
                            "DELETE FROM orders_detail WHERE order_id = %s AND product_id = %s", (self.id, product.id))
                        db.connection.commit()
                    else:
                        return False

                else:
                    # validate quantity
                    if quantity > 0:
                        # insert product in order_detail
                        cursor.execute(
                            "INSERT INTO orders_detail (order_id, product_id, quantity, price) VALUES (%s, %s, %s, %s)", (self.id, product.id, quantity, product.price * quantity))
                        db.connection.commit()
                    else:
                        return False

                # update total in orders
                cursor.execute(
                    "SELECT SUM(price) FROM orders_detail WHERE order_id = %s", (self.id,))
                total = cursor.fetchone()[0]
                cursor.execute(
                    "UPDATE orders SET total = %s WHERE id = %s", (total, self.id))
                db.connection.commit()
                self.total = total

                # get order_detail from orders_detail with order_id = self.id and set this order_detail to self
                cursor.execute(
                    "SELECT * FROM orders_detail WHERE order_id = %s", (self.id,))
                order_detail = cursor.fetchall()
                self.order_detail = []
                for od in order_detail:
                    self.order_detail.append({
                        "id": od[0],
                        "order_id": od[1],
                        "product_id": od[2],
                        "quantity": od[3],
                        "price": od[4]
                    })

                return True
            else:
                return False
        else:
            return False

    def get_all(db, user: User):
        # user logged in
        if user.is_logged(db):
            # get all orders with user_id = user.id
            cursor = db.connection.cursor()
            cursor.execute(
                "SELECT * FROM orders WHERE user_id = %s", (user.id,))
            orders = cursor.fetchall()
            orders_list = []
            for order in orders:
                cursor.execute(
                    "SELECT * FROM orders_detail WHERE order_id = %s", (order[0],))
                order_detail = cursor.fetchall()
                order_detail_list = []
                for od in order_detail:
                    order_detail_list.append({
                        "id": od[0],
                        "order_id": od[1],
                        "product_id": od[2],
                        "quantity": od[3],
                        "price": od[4]
                    })
                orders_list.append(
                    {
                        "id": order[0],
                        "user_id": order[1],
                        "total": order[2],
                        "created_at": order[3],
                        "status": order[4],
                        "order_detail": order_detail_list
                    })
            return orders_list
        else:
            return False

    def close_order(self, db, user: User):
        # user logged in
        if user.is_logged(db):
            # search if order exists, user_id = user.id and status = open
            cursor = db.connection.cursor()
            cursor.execute(
                "SELECT * FROM orders WHERE user_id = %s AND status = 'open'", (user.id,))
            order = cursor.fetchone()
            if order:
                self.id = order[0]
                self.user_id = order[1]
                self.total = order[2]
                self.created_at = order[3]
                self.status = order[4]

                # get all order_detail
                cursor.execute(
                    "SELECT * FROM orders_detail WHERE order_id = %s", (self.id,))
                order_detail = cursor.fetchall()
                # for each product in order_detail
                for od in order_detail:
                    # get product
                    cursor.execute(
                        "SELECT * FROM products WHERE id = %s", (od[2],))
                    product = cursor.fetchone()
                    # validate quantity
                    if od[3] > product[4]:
                        # delete this product from order_detail
                        cursor.execute(
                            "DELETE FROM orders_detail WHERE id = %s", (od[0],))
                        db.connection.commit()
                        self.calculate_total(db)
                    else:
                        # update quantity in products
                        cursor.execute(
                            "UPDATE products SET stock = %s WHERE id = %s", (product[4] - od[3], product[0]))
                        db.connection.commit()
                # update status in orders
                cursor.execute(
                    "UPDATE orders SET status = %s WHERE id = %s", ('closed', self.id))
                db.connection.commit()
                self.status = 'closed'
                return True
            else:
                print('Order not found')
                return False
        else:
            return False

    def calculate_total(self, db):
        # get total from order_detail
        cursor = db.connection.cursor()
        cursor.execute(
            "SELECT SUM(price) FROM orders_detail WHERE order_id = %s", (self.id,))
        total = cursor.fetchone()[0]
        # update total in orders
        cursor.execute(
            "UPDATE orders SET total = %s WHERE id = %s", (total, self.id))
        db.connection.commit()
        self.total = total
        return True


# Abstract Order class
# Name: Order
# Attributes:
"""
+ id: int
+ user_id: int
+ total: float
+ created_at: datetime
+ status: str
+ order_detail: list
"""
# Methods:
"""
+ get(self, db, user: User)
+ add_product(self, db, user: User, product: Product, quantity: int)
+ get_all(db, user: User)
+ close_order(self, db, user: User)
+ calculate_total(self, db)
"""
