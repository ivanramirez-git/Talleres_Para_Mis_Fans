

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

import datetime # Importamos el módulo datetime para trabajar con fechas
from .User import User  # Importamos la clase User
from .Product import Product  # Importamos la clase Product


class Order: # Creamos la clase Order
    def __init__(self, id, user_id, total=0, created_at=None, status='', order_detail=[]):  # Constructor
        self.id = id  # 1 # id de la orden
        self.user_id = user_id  # 1 # id del usuario
        self.total = total  # 100.00 # if open, total = 0, if closet, total = sum of prices of all products with order_id = id # total de la orden
        self.created_at = created_at  # datetime.datetime.now() # fecha de creación de la orden
        self.status = status  # open, closed # estado de la orden
        # [{"id": 1, "order_id": 1, "product_id": 1, "quantity": 1, "price": 1.00}, ...] # detalle de la orden
        self.order_detail = order_detail  # Listar todos los productos de una orden

    def __str__(self): # Método mágico __str__
        return f'Order: {self.id}, {self.user_id}, {self.total}, {self.created_at}, {self.status}, {self.order_detail}' # Retornamos un string con los datos de la orden

    def add_product_to_order(self, db, user: User, product: Product, quantity: int): # Método para agregar un producto a una orden
        # user logged in
        if user.is_logged(db): # Si el usuario está logueado
            # search if product exists
            if product: # Si el producto existe
                # get order with status = open and user_id = user.id and set this order to self
                cursor = db.connection.cursor() # Creamos un cursor
                cursor.execute("SELECT * FROM orders WHERE status = 'open' AND user_id = %s", (user.id,)) # Ejecutamos la consulta
                order = cursor.fetchone() # Obtenemos el resultado de la consulta
                if order: # Si la orden existe
                    self.id = order[0] # Asignamos el id de la orden a la propiedad id de la clase Order
                    self.user_id = order[1] # Asignamos el id del usuario a la propiedad user_id de la clase Order
                    self.total = order[2] # Asignamos el total de la orden a la propiedad total de la clase Order
                    self.created_at = order[3] # Asignamos la fecha de creación de la orden a la propiedad created_at de la clase Order
                    self.status = order[4] # Asignamos el estado de la orden a la propiedad status de la clase Order
                else: # Si la orden no existe
                    # create new order with status = open and user_id = user.id and set this order to self
                    cursor.execute("INSERT INTO orders (user_id, total, created_at, status) VALUES (%s, %s, %s, %s)", (user.id, 0, datetime.datetime.now(), 'open')) # Ejecutamos la consulta
                    db.connection.commit() # Guardamos los cambios en la base de datos
                    self.id = cursor.lastrowid # Asignamos el id de la orden a la propiedad id de la clase Order
                    self.user_id = user.id # Asignamos el id del usuario a la propiedad user_id de la clase Order
                    self.total = 0 # Asignamos el total de la orden a la propiedad total de la clase Order
                    self.created_at = datetime.datetime.now() # Asignamos la fecha de creación de la orden a la propiedad created_at de la clase Order
                    self.status = 'open' # Asignamos el estado de la orden a la propiedad status de la clase Order

                # search if product exists in order_detail with order_id = self.id
                cursor.execute("SELECT * FROM orders_detail WHERE order_id = %s AND product_id = %s", (self.id, product.id)) # Ejecutamos la consulta
                order_detail = cursor.fetchone() # Obtenemos el resultado de la consulta
                if order_detail: # Si el detalle de la orden existe
                    # validate quantity
                    if quantity+order_detail[3] > 0: # Si la cantidad es mayor a 0
                        # update quantity and price in order_detail
                        cursor.execute("UPDATE orders_detail SET quantity = %s, price = %s WHERE order_id = %s AND product_id = %s", (order_detail[3] + quantity, product.price * (quantity + order_detail[3]), self.id, product.id)) # Ejecutamos la consulta
                        db.connection.commit() # Guardamos los cambios en la base de datos
                    elif quantity+order_detail[3] == 0:     # Si la cantidad es igual a 0
                        # delete product from order_detail
                        cursor.execute("DELETE FROM orders_detail WHERE order_id = %s AND product_id = %s", (self.id, product.id)) # Ejecutamos la consulta
                        db.connection.commit() # Guardamos los cambios en la base de datos
                    else: # Si la cantidad es menor a 0
                        return False # Retornamos False
                else: # Si el detalle de la orden no existe
                    # validate quantity
                    if quantity > 0: # Si la cantidad es mayor a 0
                        # insert product in order_detail
                        cursor.execute("INSERT INTO orders_detail (order_id, product_id, quantity, price) VALUES (%s, %s, %s, %s)", (self.id, product.id, quantity, product.price * quantity)) # Ejecutamos la consulta
                        db.connection.commit() # Guardamos los cambios en la base de datos
                    else: # Si la cantidad es menor o igual a 0
                        return False # Retornamos False

                # update total in orders
                cursor.execute("SELECT SUM(price) FROM orders_detail WHERE order_id = %s", (self.id,)) # Ejecutamos la consulta
                total = cursor.fetchone()[0] # Obtenemos el resultado de la consulta
                cursor.execute("UPDATE orders SET total = %s WHERE id = %s", (total, self.id)) # Ejecutamos la consulta
                db.connection.commit() # Guardamos los cambios en la base de datos
                self.total = total # Asignamos el total de la orden a la propiedad total de la clase Order

                # get order_detail from orders_detail with order_id = self.id and set this order_detail to self
                cursor.execute("SELECT * FROM orders_detail WHERE order_id = %s", (self.id,)) # Ejecutamos la consulta
                order_detail = cursor.fetchall() # Obtenemos el resultado de la consulta
                self.order_detail = [] # Asignamos una lista vacía a la propiedad order_detail de la clase Order
                for od in order_detail: # Iteramos sobre el resultado de la consulta
                    self.order_detail.append({ # Agregamos un diccionario con los datos del detalle de la orden a la propiedad order_detail de la clase Order
                        "id": od[0], # Asignamos el id del detalle de la orden al diccionario
                        "order_id": od[1], # Asignamos el id de la orden al diccionario
                        "product_id": od[2],  # Asignamos el id del producto al diccionario
                        "quantity": od[3],   # Asignamos la cantidad del producto al diccionario
                        "price": od[4]  # Asignamos el precio del producto al diccionario
                    })

                return True # Retornamos True
            else: # Si el usuario no existe
                return False # Retornamos False
        else: # Si el producto no existe
            return False # Retornamos False

    def get_all(db, user: User): # Método estático para obtener todas las ordenes de un usuario
        # user logged in
        if user.is_logged(db): # Si el usuario está logueado
            # get all orders with user_id = user.id
            cursor = db.connection.cursor() # Obtenemos el cursor de la base de datos
            cursor.execute("SELECT * FROM orders WHERE user_id = %s", (user.id,)) # Ejecutamos la consulta
            orders = cursor.fetchall() # Obtenemos el resultado de la consulta
            orders_list = [] # Creamos una lista vacía
            for order in orders:  # Iteramos sobre el resultado de la consulta
                cursor.execute("SELECT * FROM orders_detail WHERE order_id = %s", (order[0],)) # Ejecutamos la consulta
                order_detail = cursor.fetchall() # Obtenemos el resultado de la consulta
                order_detail_list = [] # Creamos una lista vacía
                for od in order_detail: # Iteramos sobre el resultado de la consulta
                    order_detail_list.append({ # Agregamos un diccionario con los datos del detalle de la orden a la lista
                        "id": od[0], # Asignamos el id del detalle de la orden al diccionario
                        "order_id": od[1], # Asignamos el id de la orden al diccionario
                        "product_id": od[2], # Asignamos el id del producto al diccionario
                        "quantity": od[3],  # Asignamos la cantidad del producto al diccionario
                        "price": od[4]      # Asignamos el precio del producto al diccionario
                    })
                orders_list.append( # Agregamos un diccionario con los datos de la orden a la lista
                    { # Agregamos un diccionario con los datos de la orden a la lista
                        "id": order[0], # Asignamos el id de la orden al diccionario
                        "user_id": order[1], # Asignamos el id del usuario al diccionario
                        "total": order[2], # Asignamos el total de la orden al diccionario
                        "created_at": order[3], # Asignamos la fecha de creación de la orden al diccionario
                        "status": order[4], # Asignamos el estado de la orden al diccionario
                        "order_detail": order_detail_list # Asignamos la lista de detalles de la orden al diccionario
                    })
            return orders_list # Retornamos la lista de ordenes
        else: # Si el usuario no está logueado
            return False # Retornamos False

    def close_order(self, db, user: User): # Método para cerrar una orden
        # user logged in
        if user.is_logged(db): # Si el usuario está logueado
            # search if order exists, user_id = user.id and status = open
            cursor = db.connection.cursor() # Obtenemos el cursor de la base de datos
            cursor.execute("SELECT * FROM orders WHERE user_id = %s AND status = 'open'", (user.id,)) # Ejecutamos la consulta
            order = cursor.fetchone() # Obtenemos el resultado de la consulta
            if order: # Si la orden existe
                self.id = order[0] # Asignamos el id de la orden a la propiedad id de la clase Order
                self.user_id = order[1] # Asignamos el id del usuario a la propiedad user_id de la clase Order
                self.total = order[2] # Asignamos el total de la orden a la propiedad total de la clase Order
                self.created_at = order[3] # Asignamos la fecha de creación de la orden a la propiedad created_at de la clase Order
                self.status = order[4] # Asignamos el estado de la orden a la propiedad status de la clase Order

                # get all order_detail
                cursor.execute("SELECT * FROM orders_detail WHERE order_id = %s", (self.id,)) # Ejecutamos la consulta
                order_detail = cursor.fetchall() # Obtenemos el resultado de la consulta
                # for each product in order_detail
                for od in order_detail: # Iteramos sobre el resultado de la consulta
                    # get product
                    cursor.execute("SELECT * FROM products WHERE id = %s", (od[2],)) # Ejecutamos la consulta
                    product = cursor.fetchone() # Obtenemos el resultado de la consulta
                    # validate quantity
                    if od[3] > product[4]: # Si la cantidad del producto es mayor a la cantidad disponible
                        # delete this product from order_detail
                        cursor.execute("DELETE FROM orders_detail WHERE id = %s", (od[0],)) # Ejecutamos la consulta
                        db.connection.commit() # Guardamos los cambios en la base de datos
                        self.calculate_total(db) # Calculamos el total de la orden
                    else:  # Si la cantidad del producto es menor o igual a la cantidad disponible
                        # update quantity in products
                        cursor.execute("UPDATE products SET stock = %s WHERE id = %s", (product[4] - od[3], product[0])) # Ejecutamos la consulta
                        db.connection.commit() # Guardamos los cambios en la base de datos
                # update status in orders
                cursor.execute("UPDATE orders SET status = %s WHERE id = %s", ('closed', self.id)) # Ejecutamos la consulta
                db.connection.commit() # Guardamos los cambios en la base de datos
                self.status = 'closed'  # Asignamos el estado de la orden a la propiedad status de la clase Order
                return True # Retornamos True
            else: # Si la orden no existe
                # print('Order not found') # Imprimimos un mensaje
                return False # Retornamos False
        else: # Si el usuario no está logueado
            return False # Retornamos False

    def calculate_total(self, db): # Método para calcular el total de la orden
        # get total from order_detail
        cursor = db.connection.cursor() # Obtenemos el cursor de la base de datos
        cursor.execute("SELECT SUM(price) FROM orders_detail WHERE order_id = %s", (self.id,)) # Ejecutamos la consulta
        total = cursor.fetchone()[0] # Obtenemos el resultado de la consulta
        # update total in orders
        cursor.execute("UPDATE orders SET total = %s WHERE id = %s", (total, self.id)) # Ejecutamos la consulta
        db.connection.commit() # Guardamos los cambios en la base de datos
        self.total = total # Asignamos el total de la orden a la propiedad total de la clase Order
        return True # Retornamos True


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
