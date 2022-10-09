
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
