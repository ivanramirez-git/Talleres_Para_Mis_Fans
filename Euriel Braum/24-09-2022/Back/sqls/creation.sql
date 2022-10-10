-- Base de datos MySQL
--
-- Este archivo contiene las consultas SQL para crear la base de datos en xampp con mysql
--
-- Crear la base de datos flask_db si no existe
DROP DATABASE IF EXISTS flask_db;
CREATE DATABASE IF NOT EXISTS flask_db;
USE flask_db;
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
-- Insertar admin
INSERT INTO users (username, password, email, fullname, role) VALUES ('admin', 'pbkdf2:sha256:260000$l999FTgAfnN4E5Wx$485350051a7136b6cd38408d17f0fd0a0c5ebeba199a6d2a384cc0e31d7e17e9', 'admin@carrito.com', 'Administrador', 'admin');

-- Eliminar el procedimiento
DROP PROCEDURE IF EXISTS change_status_expired_session;
-- Procedimiento para cambiar el estado de la sesión a expirada cuando la fecha de expiración sea menor a la fecha actual si la sesión está activa
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
-- Ejecutar el procedimiento
CALL change_status_expired_session();
-- CARRITO DE COMPRAS
-- TABLAS: productos, categorias, ordenes, ordenes_detalle
-- TABLA categories: id, name, description
CREATE TABLE IF NOT EXISTS `categories` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL,
  `description` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE = InnoDB DEFAULT CHARSET = utf8;
-- TABLA products: id, name, description, price, stock, category_id(fk), image
CREATE TABLE IF NOT EXISTS `products` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL,
  `description` varchar(255) NOT NULL,
  `price` decimal(10, 2) NOT NULL,
  `stock` int(11) NOT NULL,
  `category_id` int(11) NOT NULL,
  `image` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `category_id` (`category_id`),
  CONSTRAINT `products_ibfk_1` FOREIGN KEY (`category_id`) REFERENCES `categories` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
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
-- INSERTAR DATOS
-- Insertar categorias
INSERT INTO categories (name, description)
VALUES (  'Bebidas',  'Articulos de supermercado para beber');
INSERT INTO categories (name, description)
VALUES (  'Comida',  'Articulos de supermercado para comer');
INSERT INTO categories (name, description)
VALUES (  'Limpieza',  'Articulos de supermercado para limpiar');
INSERT INTO products (  name,  description,  price,  stock,  category_id,  image)
VALUES (  'LIMPIAVIDRIOS BRILLAKING 500 ML',  'LIMPIAVIDRIOS BRILLAKING 500 ML',  2250,  328,  3,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12000232.png');
INSERT INTO products (  name,  description,  price,  stock,  category_id,  image)
VALUES (  'JUGO DEL VALLE FRUTAS CITRICAS 1500ML',  'JUGO DEL VALLE FRUTAS CITRICAS 1500ML',  2490,  35,  1,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004550.png');
INSERT INTO products (  name,  description,  price,  stock,  category_id,  image)
VALUES (  'GASEOSA COCA COLA PET 250ML',  'GASEOSA COCA COLA PET 250ML',  1290,  54,  1,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004548.png');
INSERT INTO products (  name,  description,  price,  stock,  category_id,  image)
VALUES (  'GASEOSA COCA COLA SIN AZUCAR PET 250ML',  'GASEOSA COCA COLA SIN AZUCAR PET 250ML',  990,  143,  1,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004549.png');
INSERT INTO products (  name,  description,  price,  stock,  category_id,  image)
VALUES (  'VARSOL BRILLA KING 800 ML',  'VARSOL BRILLA KING 800 ML',  6590,  29,  3,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12000721.png');
INSERT INTO products (  name,  description,  price,  stock,  category_id,  image)
VALUES (  'BLANQUEADOR EN GEL BRILLA KING 1000 ML',  'BLANQUEADOR EN GEL BRILLA KING 1000 ML',  5290,  251,  3,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12002695.png');
INSERT INTO products (  name,  description,  price,  stock,  category_id,  image)
VALUES (  'TRIDENT MORAZUL 5S 8,5G',  'TRIDENT MORAZUL 5S 8,5G',  1150,  31,  2,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004705.png');
INSERT INTO products (  name,  description,  price,  stock,  category_id,  image)
VALUES (  'ACEITE VEGETAL GOTA DE ORO 900 ML',  'ACEITE VEGETAL GOTA DE ORO 900 ML',  9690,  319,  2,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004740.png');
INSERT INTO products (name,description,price,stock,category_id,image)
VALUES (    'SALSA MAYONESA CON CHIPOTLE 350G',    'SALSA MAYONESA CON CHIPOTLE 350G',    3990,    40,    2,    'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004647.png');