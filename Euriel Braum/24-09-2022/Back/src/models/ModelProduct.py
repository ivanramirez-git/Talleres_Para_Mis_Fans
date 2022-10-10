
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
# CREAR PRODUCTOS
