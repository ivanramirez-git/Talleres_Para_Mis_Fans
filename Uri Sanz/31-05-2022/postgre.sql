-- PostgreSQL
-- version 14.3.1
--- user: postgres
-- encoding: UTF-8
-- conetion limit: -1
-- Database: panaderia

-- Eliminar tablas si existen
DROP TABLE IF EXISTS detalle_venta;
DROP TABLE IF EXISTS venta;
DROP TABLE IF EXISTS cliente;
DROP TABLE IF EXISTS producto;
DROP TABLE IF EXISTS proveedor;
DROP TABLE IF EXISTS categoria;
DROP TABLE IF EXISTS proveedor_modificado;
DROP TABLE IF EXISTS categoria_modificada;


-- 5. Crear tablas con sus respectivas relaciones en SQLpostgre

-- tabla categoria
-- id_categoria
-- nombre
-- descripcion
CREATE TABLE categoria(
    id_categoria SERIAL PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL,
    descripcion VARCHAR(100) NOT NULL
);

-- tabla proveedor
-- id_proveedor
-- nombre
-- direccion
-- telefono
CREATE TABLE proveedor(
    id_proveedor SERIAL PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL,
    direccion VARCHAR(100) NOT NULL,
    telefono VARCHAR(10) NOT NULL
);

-- tabla producto
-- id_producto
-- nombre
-- descripcion
-- precio
-- id_categoria
-- id_proveedor
CREATE TABLE producto(
    id_producto SERIAL PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL,
    descripcion VARCHAR(100) NOT NULL,
    precio INTEGER NOT NULL,
    id_categoria INTEGER NOT NULL,
    id_proveedor INTEGER NOT NULL,
    FOREIGN KEY (id_categoria) REFERENCES categoria(id_categoria),
    FOREIGN KEY (id_proveedor) REFERENCES proveedor(id_proveedor)
);

-- tabla cliente
-- id_cliente
-- nombre
-- direccion
-- telefono
CREATE TABLE cliente(
    id_cliente SERIAL PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL,
    direccion VARCHAR(100) NOT NULL,
    telefono VARCHAR(10) NOT NULL
);

-- tabla venta
-- id_venta
-- fecha
-- id_cliente
CREATE TABLE venta(
    id_venta SERIAL PRIMARY KEY,
    fecha TIMESTAMP NOT NULL,
    id_cliente INTEGER NOT NULL,
    FOREIGN KEY (id_cliente) REFERENCES cliente(id_cliente)
);

-- tabla detalle_venta
-- id_detalle_venta
-- id_venta
-- id_producto
-- cantidad
CREATE TABLE detalle_venta(
    id_detalle_venta SERIAL PRIMARY KEY,
    id_venta INTEGER NOT NULL,
    id_producto INTEGER NOT NULL,
    cantidad INTEGER NOT NULL,
    FOREIGN KEY (id_venta) REFERENCES venta(id_venta),
    FOREIGN KEY (id_producto) REFERENCES producto(id_producto)
);

-- Mostrar tablas vacias
SELECT * FROM categoria;
SELECT * FROM proveedor;
SELECT * FROM producto;
SELECT * FROM cliente;
SELECT * FROM venta;
SELECT * FROM detalle_venta;

-- Insertar datos de prueba
-- 3 datos de prueba para la tabla categoria
-- id_categoria | nombre | descripcion
-- 1           | pan   | panaderia
-- 2           | bebida| bebida
-- 3           | postre| postre
INSERT INTO categoria(nombre, descripcion) VALUES ('pan', 'panaderia');
INSERT INTO categoria(nombre, descripcion) VALUES ('bebida', 'bebida');
INSERT INTO categoria(nombre, descripcion) VALUES ('postre', 'postre');
INSERT INTO categoria(nombre, descripcion) VALUES ('comida', 'comida');

-- 3 datos de prueba para la tabla proveedor
-- id_proveedor | nombre | direccion | telefono
-- 1            | juan   | calle     | 123456789
-- 2            | pedro  | carrera   | 234567890
-- 3            | maria  | avenida   | 345678901
INSERT INTO proveedor(nombre, direccion, telefono) VALUES ('juan', 'calle', '123456789');
INSERT INTO proveedor(nombre, direccion, telefono) VALUES ('pedro', 'carrera', '234567890');
INSERT INTO proveedor(nombre, direccion, telefono) VALUES ('maria', 'avenida', '345678901');
INSERT INTO proveedor(nombre, direccion, telefono) VALUES ('alfonso', 'calle', '123456789');
INSERT INTO proveedor(nombre, direccion, telefono) VALUES ('natalia', 'carrera', '234567890');

-- 15 datos de prueba para la tabla producto
-- id_producto | nombre | descripcion | precio | id_categoria | id_proveedor
-- 1           | pan de leche | pan de leche | 10      | 1           | 1
-- 2           | pan de queso | pan de queso | 15      | 1           | 1
-- 3           | pan de arroz | pan de arroz | 20      | 1           | 2
-- 4           | pan de pollo | pan de pollo | 25      | 1           | 2
-- 5           | pan de carne | pan de carne | 30      | 1           | 3
-- 6           | cocacola     | cocacola     | 10      | 2           | 1
-- 7           | fanta       | fanta       | 15      | 2           | 2
-- 8           | sprite      | sprite      | 20      | 2           | 2
-- 9           | agua        | agua        | 10      | 2           | 3
-- 10          | jugo        | jugo        | 15      | 2           | 3
-- 11          | flan        | flan        | 20      | 3           | 1
-- 12          | galletas    | galletas    | 10      | 3           | 2
-- 13          | chocolates  | chocolates  | 15      | 3           | 3
-- 14          | mermelada   | mermelada   | 20      | 3           | 1
-- 15          | merengue    | merengue    | 10      | 3           | 2
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('pan de leche', 'pan de leche', 10, 1, 1);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('pan de queso', 'pan de queso', 15, 1, 1);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('pan de arroz', 'pan de arroz', 20, 1, 2);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('pan de pollo', 'pan de pollo', 25, 1, 2);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('pan de carne', 'pan de carne', 30, 1, 3);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('cocacola', 'cocacola', 10, 2, 1);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('fanta', 'fanta', 15, 2, 2);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('sprite', 'sprite', 20, 2, 2);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('agua', 'agua', 10, 2, 3);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('jugo', 'jugo', 15, 2, 3);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('flan', 'flan', 20, 3, 1);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('galletas', 'galletas', 10, 3, 2);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('chocolates', 'chocolates', 15, 3, 3);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('mermelada', 'mermelada', 20, 3, 1);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('merengue', 'merengue', 10, 3, 2);
INSERT INTO producto(nombre, descripcion, precio, id_categoria, id_proveedor) VALUES ('pai de limon', 'pai de limon', 10, 3, 4);

-- 3 datos de prueba para la tabla cliente
-- id_cliente | nombre | direccion | telefono
-- 1          | alejandra | calle     | 456123456
-- 2          | mariana  | carrera   | 567123456
-- 3          | jose      | avenida   | 678123456
INSERT INTO cliente(nombre, direccion, telefono) VALUES ('alejandra', 'calle', '456123456');
INSERT INTO cliente(nombre, direccion, telefono) VALUES ('mariana', 'carrera', '567123456');
INSERT INTO cliente(nombre, direccion, telefono) VALUES ('jose', 'avenida', '678123456');
INSERT INTO cliente(nombre, direccion, telefono) VALUES ('pablo', 'calle carrera', '789123456');
INSERT INTO cliente(nombre, direccion, telefono) VALUES ('marcos', 'avenida carrera', '890123456');

-- 3 datos de prueba para la tabla venta
-- id_venta | fecha | id_cliente
-- 1       | '2020-05-20 13:02:52.281964' | 1
-- 2       | '2020-05-21 13:02:52.281964' | 2
-- 3       | '2020-05-22 13:02:52.281964' | 3
INSERT INTO venta(fecha, id_cliente) VALUES ('2020-05-20 13:02:52.281964', 1);
INSERT INTO venta(fecha, id_cliente) VALUES ('2020-05-21 13:02:52.281964', 2);
INSERT INTO venta(fecha, id_cliente) VALUES ('2020-05-22 13:02:52.281964', 3);

-- 15 datos de prueba para la tabla detalle_venta
-- id_detalle_venta | id_venta | id_producto | cantidad
-- 1               | 1        | 1           | 2
-- 2               | 1        | 2           | 3
-- 3               | 1        | 3           | 4
-- 4               | 1        | 4           | 5
-- 5               | 1        | 5           | 6
-- 6               | 2        | 7           | 5
-- 7               | 2        | 8           | 4
-- 8               | 2        | 9           | 3
-- 9               | 2        | 10          | 2
-- 10              | 2        | 11          | 1
-- 11              | 3        | 12          | 2
-- 12              | 3        | 13          | 3
-- 13              | 3        | 14          | 4
-- 14              | 3        | 15          | 5
-- 15              | 3        | 6          | 6
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (1, 1, 2);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (1, 2, 3);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (1, 3, 4);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (1, 4, 5);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (1, 5, 6);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (2, 7, 5);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (2, 8, 4);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (2, 9, 3);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (2, 10, 2);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (2, 11, 1);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (3, 12, 2);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (3, 13, 3);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (3, 14, 4);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (3, 15, 5);
INSERT INTO detalle_venta(id_venta, id_producto, cantidad) VALUES (3, 6, 6);

-- Consutar tablas
SELECT * FROM categoria;
SELECT * FROM proveedor;
SELECT * FROM producto;
SELECT * FROM cliente;
SELECT * FROM venta;
SELECT * FROM detalle_venta;


-- 6. Deberas modificar los nombres de al menos dos tablas

-- categoria
ALTER TABLE categoria RENAME TO categoria_modificada;
-- proveedor
ALTER TABLE proveedor RENAME TO proveedor_modificado;
-- consultar tablas
SELECT * FROM categoria_modificada;
SELECT * FROM proveedor_modificado;


-- 7. Cambiar el nombre de dos atributos de 3 tablas

-- producto
ALTER TABLE producto RENAME COLUMN nombre TO nombre_modificado;
ALTER TABLE producto RENAME COLUMN descripcion TO descripcion_modificada;
-- cliente
ALTER TABLE cliente RENAME COLUMN nombre TO nombre_modificado;
ALTER TABLE cliente RENAME COLUMN direccion TO direccion_modificada;
-- venta
ALTER TABLE venta RENAME COLUMN fecha TO fecha_modificada;
ALTER TABLE venta RENAME COLUMN id_cliente TO id_cliente_modificado;
-- consultar tablas
SELECT * FROM producto;
SELECT * FROM cliente;
SELECT * FROM venta;

-- 8. Realizar una consulta para cada tabla y mostrar elementos sin duplicar utilizando la clausula distint de alguna tabla

-- categoria_modificada
SELECT DISTINCT nombre FROM categoria_modificada;
-- proveedor_modificado
SELECT DISTINCT nombre FROM proveedor_modificado;
-- producto
SELECT DISTINCT nombre_modificado FROM producto;
-- cliente
SELECT DISTINCT nombre_modificado FROM cliente;
-- venta
SELECT DISTINCT fecha_modificada FROM venta;
-- detalle_venta
SELECT DISTINCT id_producto FROM detalle_venta;

-- 9. Relizar 3 consultas con la restricción unique y mostrar los resultados

-- mostrar los nombres de los clientes que han comprado al menos un producto y no repetir nombres
SELECT DISTINCT cliente.nombre_modificado FROM cliente INNER JOIN venta ON cliente.id_cliente = venta.id_cliente_modificado INNER JOIN detalle_venta ON venta.id_venta = detalle_venta.id_venta;
-- mostrar los productos que han sido comprados por algun cliente y no repetir nombres
SELECT DISTINCT producto.nombre_modificado FROM producto INNER JOIN detalle_venta ON producto.id_producto = detalle_venta.id_producto INNER JOIN venta ON detalle_venta.id_venta = venta.id_venta;

-- 10. Realizar 3 consultas con join y mostrar los resultados

-- mostrar los productos de un proveedor
SELECT producto.nombre_modificado, proveedor_modificado.nombre FROM producto INNER JOIN proveedor_modificado ON producto.id_proveedor = proveedor_modificado.id_proveedor;
-- mostrar los productos de una categoria
SELECT producto.nombre_modificado, categoria_modificada.nombre FROM producto INNER JOIN categoria_modificada ON producto.id_categoria = categoria_modificada.id_categoria;
-- mostrar los productos comprados por alejandra
SELECT producto.nombre_modificado, venta.fecha_modificada, cliente.nombre_modificado FROM producto INNER JOIN detalle_venta ON producto.id_producto = detalle_venta.id_producto INNER JOIN venta ON detalle_venta.id_venta = venta.id_venta INNER JOIN cliente ON venta.id_cliente_modificado = cliente.id_cliente WHERE cliente.nombre_modificado = 'alejandra';

-- 11. Relizar 2 consultas con Left join

-- mostrar las categorias de un producto
SELECT categoria_modificada.nombre, producto.nombre_modificado FROM categoria_modificada LEFT JOIN producto ON categoria_modificada.id_categoria = producto.id_categoria;
-- mostrar los proveedores de un producto
SELECT proveedor_modificado.nombre, producto.nombre_modificado FROM proveedor_modificado LEFT JOIN producto ON proveedor_modificado.id_proveedor = producto.id_proveedor;

-- 12. Relizar 2 consultas con Right join

-- mostrar los nombres de los clientes de una venta
SELECT cliente.nombre_modificado, venta.id_venta FROM cliente RIGHT JOIN venta ON cliente.id_cliente = venta.id_cliente_modificado;
-- mostrar los nombres de los productos de una venta
SELECT producto.nombre_modificado, venta.id_venta FROM producto RIGHT JOIN detalle_venta ON producto.id_producto = detalle_venta.id_producto RIGHT JOIN venta ON detalle_venta.id_venta = venta.id_venta;

-- 13. Relizar 2 consultas con Cross join

-- mostrar los nombres de los productos que no han sido vendidos a ningun cliente
SELECT producto.nombre_modificado FROM producto CROSS JOIN venta WHERE producto.id_producto NOT IN (SELECT id_producto FROM detalle_venta);
-- mostrar los nombres de los proveedores que no han sido asignados a ningun producto
SELECT proveedor_modificado.nombre FROM proveedor_modificado CROSS JOIN producto WHERE proveedor_modificado.id_proveedor NOT IN (SELECT id_proveedor FROM producto);

-- 14. Realizar 1 consulta con Autocombinación

-- mostrar los nombres de los clientes que han comprado al menos un producto
SELECT cliente.nombre_modificado FROM cliente INNER JOIN venta ON cliente.id_cliente = venta.id_cliente_modificado INNER JOIN detalle_venta ON venta.id_venta = detalle_venta.id_venta;
-- mostrar los productos que han sido comprados por algun cliente
SELECT producto.nombre_modificado FROM producto INNER JOIN detalle_venta ON producto.id_producto = detalle_venta.id_producto INNER JOIN venta ON detalle_venta.id_venta = venta.id_venta;

-- 15. Realizar 1 consulta con combinaciones y funciones de agrupamiento

-- agrupar los productos por proveedor y mostrar el total de productos vendidos por cada proveedor
SELECT proveedor_modificado.nombre, COUNT(producto.nombre_modificado) FROM proveedor_modificado INNER JOIN producto ON proveedor_modificado.id_proveedor = producto.id_proveedor GROUP BY proveedor_modificado.nombre;
-- agrupar los productos por categoria y mostrar el total de productos vendidos por cada categoria
SELECT categoria_modificada.nombre, COUNT(producto.nombre_modificado) FROM categoria_modificada INNER JOIN producto ON categoria_modificada.id_categoria = producto.id_categoria GROUP BY categoria_modificada.nombre;

-- 16. Realizar 1 consulta con combinacion de más de dos tablas

-- mostrar los nombres de los clientes que no han comprado ningun producto
SELECT cliente.nombre_modificado FROM cliente LEFT JOIN venta ON cliente.id_cliente = venta.id_cliente_modificado LEFT JOIN detalle_venta ON venta.id_venta = detalle_venta.id_venta WHERE detalle_venta.id_venta IS NULL;
-- mostrar las ventas con nombre de cliente y nombre de producto y categoria y proveedor y contar cuanto costo
SELECT cliente.nombre_modificado, producto.nombre_modificado, categoria_modificada.nombre, proveedor_modificado.nombre, SUM(detalle_venta.cantidad * producto.precio) FROM cliente JOIN venta ON cliente.id_cliente = venta.id_cliente_modificado JOIN detalle_venta ON venta.id_venta = detalle_venta.id_venta JOIN producto ON detalle_venta.id_producto = producto.id_producto JOIN categoria_modificada ON producto.id_categoria = categoria_modificada.id_categoria JOIN proveedor_modificado ON producto.id_proveedor = proveedor_modificado.id_proveedor GROUP BY cliente.nombre_modificado, producto.nombre_modificado, categoria_modificada.nombre, proveedor_modificado.nombre;
