
-- Diagrama Entidad Relación 
-- Registros 10 mínimo por tabla
-- 2 triggers /Desencadenadores 
-- 2 vistas (1 vista compleja con un join de 3 tablas)
-- 2 funciones
-- 2 procedimientos

-- Diagrama Entidad Relación
-- 1. Crear la base de datos
-- Base de datos MySQL
--
-- Este archivo contiene las consultas SQL para crear la base de datos en xampp con mysql
--
-- Crear la base de datos basededatos si no existe
DROP DATABASE IF EXISTS basededatos;
CREATE DATABASE IF NOT EXISTS basededatos;
USE basededatos;
-- Tabla users: id, username, password, email, fullname, role, code
CREATE TABLE IF NOT EXISTS `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) NOT NULL, -- unique
  `password` varchar(255) NOT NULL,
  `email` varchar(50) NOT NULL, -- unique
  `fullname` varchar(50) NOT NULL,
  `role` varchar(50) NOT NULL,
  -- adicionar los campos que son unicos
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


-- Tabla sessions: id, user_id(fk), token, created_at, expired_at, status
CREATE TABLE IF NOT EXISTS `sessions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `token` varchar(255) NOT NULL,
  `created_at` datetime NOT NULL,
  `expired_at` datetime NOT NULL,
  `status` varchar(50) NOT NULL, -- logged, expired, logout
  PRIMARY KEY (`id`),
  KEY `user_id` (`user_id`),
  CONSTRAINT `sessions_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;


-- CARRITO DE COMPRAS
-- TABLAS: productos, categorias, ordenes, ordenes_detalle
-- TABLA categories: id, name (unico), description
CREATE TABLE IF NOT EXISTS `categories` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL UNIQUE,
  `description` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE = InnoDB DEFAULT CHARSET = utf8;
-- TABLA products: id, name, description, price, stock, category_id(fk)
CREATE TABLE IF NOT EXISTS `products` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL,
  `description` varchar(255) NOT NULL,
  `price` decimal(10, 2) NOT NULL,
  `stock` int(11) NOT NULL,
  `category_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `category_id` (`category_id`),
  CONSTRAINT `products_ibfk_1` FOREIGN KEY (`category_id`) REFERENCES `categories` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB DEFAULT CHARSET = utf8;
-- TABLA products_images: id, product_id(fk), image
CREATE TABLE IF NOT EXISTS `products_images` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `product_id` int(11) NOT NULL,
  `image` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `product_id` (`product_id`),
  CONSTRAINT `products_images_ibfk_1` FOREIGN KEY (`product_id`) REFERENCES `products` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB DEFAULT CHARSET = utf8;
-- TABLA orders: id, user_id(fk), total, created_at, status
CREATE TABLE IF NOT EXISTS `orders` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `total` decimal(10, 2) NOT NULL,
  `created_at` datetime NOT NULL,
  `status` varchar(50) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `user_id` (`user_id`),
  CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB DEFAULT CHARSET = utf8;



-- TABLA orders_detail: id, order_id(fk), product_id(fk), quantity, price
CREATE TABLE IF NOT EXISTS `orders_detail` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `order_id` int(11) NOT NULL,
  `product_id` int(11) NOT NULL,
  `quantity` int(11) NOT NULL,
  `price` decimal(10, 2) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `order_id` (`order_id`),
  KEY `product_id` (`product_id`),
  CONSTRAINT `orders_detail_ibfk_1` FOREIGN KEY (`order_id`) REFERENCES `orders` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `orders_detail_ibfk_2` FOREIGN KEY (`product_id`) REFERENCES `products` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB DEFAULT CHARSET = utf8;



-- Procedimiento para cambiar el estado de la sesión a expirada cuando la fecha de expiración sea menor a la fecha actual si la sesión está activa
-- Eliminar el procedimiento
DROP PROCEDURE IF EXISTS change_status_expired_session;

DELIMITER $$
CREATE PROCEDURE `change_status_expired_session`()
BEGIN
-- fecha actual del servidor
  SET @current_date = NOW();
  SELECT *  FROM sessions  WHERE status = 'logged' AND expired_at < @current_date;
  UPDATE sessions SET status = 'expired' WHERE status = 'logged' AND expired_at < @current_date;
  COMMIT;
END$$
DELIMITER ;
-- Procedimiento para calcular el total de la orden
-- Eliminar el procedimiento
DROP PROCEDURE IF EXISTS calculate_total_order;
DELIMITER $$
CREATE PROCEDURE `calculate_total_order`(IN order_id INT)
BEGIN
  DECLARE total DECIMAL(10, 2);
  SELECT SUM(price * quantity) INTO total FROM orders_detail WHERE order_id = order_id;
  UPDATE orders SET total = total WHERE id = order_id;
  COMMIT;
END$$
DELIMITER ;


-- Función para saber si se pueden pedir más productos, si el stock es mayor a la cantidad de productos pedidos
-- Eliminar la función
DROP FUNCTION IF EXISTS can_order_more;
DELIMITER $$
CREATE FUNCTION `can_order_more`(order_id INT) RETURNS BOOLEAN
BEGIN
  DECLARE can_order_more BOOLEAN;
  SELECT SUM(quantity) < stock INTO can_order_more FROM orders_detail od INNER JOIN products p ON od.product_id = p.id WHERE order_id = order_id;
  RETURN can_order_more;
END$$
DELIMITER ;

-- Función para saber si un usuario que quiere agregar detaalles a una orden tiene una sesión activa
-- Eliminar la función
DROP FUNCTION IF EXISTS user_is_logged;
DELIMITER $$
CREATE FUNCTION `user_is_logged`(user_id INT) RETURNS BOOLEAN
BEGIN

  DECLARE logged BOOLEAN;
  SELECT status INTO logged FROM sessions WHERE user_id = user_id AND status = 'logged';
  IF logged IS NULL THEN
    RETURN FALSE;
  ELSE
    RETURN TRUE;
  END IF;
END$$
DELIMITER ;

-- TRIGGER para saber si se puede agregar más productos a una orden, comprobacion antes de insertar, si no se puede agregar más productos, se cancela la inserción
-- Eliminar el trigger
DROP TRIGGER IF EXISTS check_can_order_more;
DELIMITER $$
CREATE TRIGGER `check_can_order_more` BEFORE INSERT ON `orders_detail` FOR EACH ROW
BEGIN
  IF NOT can_order_more(NEW.order_id) THEN
    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No se puede agregar más productos a la orden';
  END IF;
END$$
DELIMITER ;

-- TRIGGER para saber si un usuario tiene una sesión activa, comprobacion antes de insertar, si no tiene una sesión activa, se cancela la inserción
-- Eliminar el trigger
DROP TRIGGER IF EXISTS check_user_is_logged;
DELIMITER $$
CREATE TRIGGER `check_user_is_logged` BEFORE INSERT ON `orders_detail` FOR EACH ROW
BEGIN
-- Consultar la orden para saber el usuario
  SELECT user_id INTO @user_id FROM orders WHERE id = NEW.order_id;
  IF NOT user_is_logged(@user_id) THEN
    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'El usuario no tiene una sesión activa';
  END IF;
END$$
DELIMITER ;

-- Vista para obtener los datos de una orden: id, nombre del usuario, total, fecha de creación, estado, lista de productos(nombres, cantidad, precio)
-- Eliminar la vista
DROP VIEW IF EXISTS order_detail;
CREATE OR REPLACE VIEW `order_detail` AS
SELECT o.id, u.fullname, o.total, o.created_at, o.status, GROUP_CONCAT(CONCAT(p.name, ' - ', od.quantity, ' - ', od.price) SEPARATOR ', ') AS products
FROM orders o
INNER JOIN users u ON o.user_id = u.id
INNER JOIN orders_detail od ON o.id = od.order_id
INNER JOIN products p ON od.product_id = p.id
GROUP BY o.id;
-- Vista para obtener los registros de sesiones de un usuario por fechas de inicio de sesión: id, fecha de ingreso, tiempo de sesion (en horas), nombre del usuario
-- Eliminar la vista
DROP VIEW IF EXISTS session_detail;
CREATE OR REPLACE VIEW `session_detail` AS
SELECT s.id, s.created_at, TIMESTAMPDIFF(HOUR, s.created_at, s.expired_at) AS session_time, u.fullname
FROM sessions s
INNER JOIN users u ON s.user_id = u.id
WHERE s.status = 'logged';
-- Vista para obtener el total de ordenes de un cliente por mes: mes, total de ordenes
-- Eliminar la vista
DROP VIEW IF EXISTS orders_by_month;
CREATE OR REPLACE VIEW `orders_by_month` AS
SELECT MONTHNAME(created_at) AS month, COUNT(*) AS total_orders
FROM orders
GROUP BY MONTH(created_at);