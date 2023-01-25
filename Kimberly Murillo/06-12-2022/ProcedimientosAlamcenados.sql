
-- PROCEDIMIENTOS ALMACENADOS
-- PUNTO 1

-- todos los registros y campos de la tabla Productos, con 
-- la excepción que: 1) en lugar del idCat, aparecerá el nombre de la categoría (uso del 
-- inner join), que es nomCat y 2) que se debe agregar al final un nuevo campo calculado 
-- llamado utilidad, el cuál será calculará restando el precio de venta – precio de costo 
-- de cada producto. (Haga un procedimiento almacenado) 
USE `productos`;
DROP procedure IF EXISTS `mostrarProductos`;

DELIMITER $$
USE `productos`$$
CREATE PROCEDURE `mostrarProductos`()
BEGIN
  SELECT p.idProd AS 'ID Producto', p.nomProd AS 'Nombre Producto', c.nomCat AS 'Categoria', p.precCosto AS 'Precio Costo', p.precVenta AS 'Precio Venta', p.existencias AS 'Existencias', (p.precVenta - p.precCosto) AS 'Utilidad'
  FROM Productos p
  INNER JOIN Categoria c ON p.idCat = c.idCat;
END$$

DELIMITER ;

-- Llamada al procedimiento almacenado
-- CALL mostrarProductos();



-- PUNTO 2

-- el valor total del inventario existente y el total de productos
-- (todas las unidades existentes) que hay en la tabla productos (Use funciones de agregado 
-- de SQL en los procedimientos almacenados). El valor en colones del inventario se 
-- obtiene de la sumatoria del precio de costo de todos los productos que existe en la BD.
-- (Haga un procedimiento almacenado) 10 pts

USE `productos`;
DROP procedure IF EXISTS `mostrarInventario`;

DELIMITER $$
USE `productos`$$
CREATE PROCEDURE `mostrarInventario`()
BEGIN
  SELECT SUM(p.precCosto) AS 'Valor Total Inventario', SUM(p.existencias) AS 'Total Productos'
  FROM Productos p;
END$$

DELIMITER ;

-- Llamada al procedimiento almacenado
-- CALL mostrarInventario();



-- PUNTO 3

-- Se requiere que exista otro JDialoj, quien será llamado desde un botón (Ejercicio 3) del 
-- JFrame frmPricipal que le permita al usuario hacer ajustes de inventario. El ajuste de 
-- inventario consiste en aumentar o decrementar las existencias de la tabla productos(Use 
-- Update dentro de procedimientos almacenados). Entonces, en el formulario se pide el 
-- idProducto, se busca en la BD, si existe se despliega la siguiente información: idProd, 
-- nomProd, existencias; de estos datos el usuario sólo podrá ver la información sin cambiar 
-- nada. En el mismo formulario aparecerá un cuadro de texto en el que el usuario debe 
-- indicar la cantidad de existencias que quiere agregar o sacar del inventario; por lo tanto,
-- existirán 2 botones: Aumentar Inventario y Sacar de inventario, dependiendo de lo que 
-- el usuario presione se aumentará o restará del campo existencias, la cantidad especificada 
-- por el usuario en el campo de texto. Si el idProd no existe, se debe enviar un mensaje de 
-- error explicando el mismo. 10 pt


-- Lista de procedimientos almacenados necesarios para el punto 3

-- 1. Procedimiento almacenado para buscar un producto por id y mostrarlo
-- 2. Procedimiento almacenado para aumentar el inventario
-- 3. Procedimiento almacenado para disminuir el inventario
-- 4. Procedimiento almacenado para sacar el inventario de un producto

-- Tener en cuenta validaciones ( si existe el producto o no, si el inventario es negativo, etc)

-- 1. Procedimiento almacenado para buscar un producto por id y mostrarlo
USE `productos`;
DROP procedure IF EXISTS `buscarProducto`;

DELIMITER $$
USE `productos`$$
CREATE PROCEDURE `buscarProducto`(IN idProd INT)
BEGIN
  SELECT p.idProd AS 'ID Producto', p.nomProd AS 'Nombre Producto', c.nomCat AS 'Categoria', p.precCosto AS 'Precio Costo', p.precVenta AS 'Precio Venta', p.existencias AS 'Existencias', (p.precVenta - p.precCosto) AS 'Utilidad'
  FROM Productos p
  INNER JOIN Categoria c ON p.idCat = c.idCat
  WHERE p.idProd = idProd;
END$$

DELIMITER ;

-- Llamada al procedimiento almacenado
-- CALL buscarProducto(1);



-- 2. Procedimiento almacenado para aumentar el inventario
USE `productos`;
DROP procedure IF EXISTS `aumentarInventario`;

DELIMITER $$
USE `productos`$$
CREATE PROCEDURE `aumentarInventario`(IN idProd INT, IN cantidad INT)
BEGIN
  UPDATE Productos
  SET existencias = existencias + cantidad
  WHERE idProd = idProd;
END$$

DELIMITER ;

-- Llamada al procedimiento almacenado
-- CALL aumentarInventario(1, 10);



-- 3. Procedimiento almacenado para disminuir el inventario
USE `productos`;
DROP procedure IF EXISTS `disminuirInventario`;

DELIMITER $$
USE `productos`$$
CREATE PROCEDURE `disminuirInventario`(IN idProd INT, IN cantidad INT)
BEGIN
  UPDATE Productos
  SET existencias = existencias - cantidad
  WHERE idProd = idProd;
END$$

DELIMITER ;

-- Llamada al procedimiento almacenado
-- CALL disminuirInventario(1, 10);



-- 4. Procedimiento almacenado para sacar el inventario de un producto
USE `productos`;
DROP procedure IF EXISTS `sacarInventario`;

DELIMITER $$
USE `productos`$$
CREATE PROCEDURE `sacarInventario`(IN idProd INT)
BEGIN
  UPDATE Productos
  SET existencias = 0
  WHERE idProd = idProd;
END$$

DELIMITER ;

-- Llamada al procedimiento almacenado
-- CALL sacarInventario(1);
