
-- Insertar admin
INSERT INTO users (username, password, email, fullname, role) VALUES ('admin', 'c4rr1t0', 'admin@carrito.com', 'Administrador', 'admin');
-- INSERTAR DATOS

-- Insertar sesión
INSERT INTO sessions (user_id, token, created_at, expired_at, status) VALUES (1, '123456789', '2022-01-01 00:00:00', '2022-01-02 00:00:00', 'logged');



-- Insertar categorias
INSERT INTO categories (name, description)
VALUES (  'Bebidas',  'Articulos de supermercado para beber');
INSERT INTO categories (name, description)
VALUES (  'Comida',  'Articulos de supermercado para comer');
INSERT INTO categories (name, description)
VALUES (  'Limpieza',  'Articulos de supermercado para limpiar');
-- 'LIMPIAVIDRIOS BRILLAKING 500 ML',  'LIMPIAVIDRIOS BRILLAKING 500 ML',  2250,  328,  3,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12000232.png'
-- 'JUGO DEL VALLE FRUTAS CITRICAS 1500ML',  'JUGO DEL VALLE FRUTAS CITRICAS 1500ML',  2490,  35,  1,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004550.png'
-- 'GASEOSA COCA COLA PET 250ML',  'GASEOSA COCA COLA PET 250ML',  1290,  54,  1,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004548.png'
-- 'GASEOSA COCA COLA SIN AZUCAR PET 250ML',  'GASEOSA COCA COLA SIN AZUCAR PET 250ML',  990,  143,  1,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004549.png'
-- 'VARSOL BRILLA KING 800 ML',  'VARSOL BRILLA KING 800 ML',  6590,  29,  3,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12000721.png'
-- 'BLANQUEADOR EN GEL BRILLA KING 1000 ML',  'BLANQUEADOR EN GEL BRILLA KING 1000 ML',  5290,  251,  3,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12002695.png'
-- 'TRIDENT MORAZUL 5S 8,5G',  'TRIDENT MORAZUL 5S 8,5G',  1150,  31,  2,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004705.png'
-- 'ACEITE VEGETAL GOTA DE ORO 900 ML',  'ACEITE VEGETAL GOTA DE ORO 900 ML',  9690,  319,  2,  'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004740.png'
--   'SALSA MAYONESA CON CHIPOTLE 350G',    'SALSA MAYONESA CON CHIPOTLE 350G',    3990,    40,    2,    'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004647.png'
INSERT INTO `products` (`name`, `description`, `price`, `stock`, `category_id`)
VALUES
('LIMPIAVIDRIOS BRILLAKING 500 ML',  'LIMPIAVIDRIOS BRILLAKING 500 ML',  2250,  328,  3),
('JUGO DEL VALLE FRUTAS CITRICAS 1500ML',  'JUGO DEL VALLE FRUTAS CITRICAS 1500ML',  2490,  35,  1),
('GASEOSA COCA COLA PET 250ML',  'GASEOSA COCA COLA PET 250ML',  1290,  54,  1),
('GASEOSA COCA COLA SIN AZUCAR PET 250ML',  'GASEOSA COCA COLA SIN AZUCAR PET 250ML',  990,  143,  1),
('VARSOL BRILLA KING 800 ML',  'VARSOL BRILLA KING 800 ML',  6590,  29,  3),
('BLANQUEADOR EN GEL BRILLA KING 1000 ML',  'BLANQUEADOR EN GEL BRILLA KING 1000 ML',  5290,  251,  3),
('TRIDENT MORAZUL 5S 8,5G',  'TRIDENT MORAZUL 5S 8,5G',  1150,  31,  2),
('ACEITE VEGETAL GOTA DE ORO 900 ML',  'ACEITE VEGETAL GOTA DE ORO 900 ML',  9690,  319,  2),
('SALSA MAYONESA CON CHIPOTLE 350G',  'SALSA MAYONESA CON CHIPOTLE 350G',  3990,  40,  2);
INSERT INTO `products_images` (`product_id`, `image`)
VALUES
(1, 'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12000232.png'),
(2, 'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004550.png'),
(3, 'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004548.png'),
(4, 'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004549.png'),
(5, 'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12000721.png'),
(6, 'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12002695.png'),
(7, 'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004705.png'),
(8, 'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004740.png'),
(9, 'https://stockimages.tiendasd1.com/stockimages.tiendasd1.com/kobastockimages/IMAGENES/12004647.png');


INSERT INTO orders (user_id, total, status, created_at)
VALUES (1,300,'pending','2022-01-01 00:00:00');


-- Insertar un detalle de orden
INSERT INTO orders_detail (order_id, product_id, quantity, price) VALUES (1, 1, 1, 100);
INSERT INTO orders_detail (order_id, product_id, quantity, price) VALUES (1, 2, 1, 100);
INSERT INTO orders_detail (order_id, product_id, quantity, price) VALUES (1, 3, 1, 100);

