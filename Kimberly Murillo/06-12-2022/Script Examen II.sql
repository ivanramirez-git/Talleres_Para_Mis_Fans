-- --------------------------------------------------------

-- Creación de la base de datos PRODUCTOS
CREATE DATABASE IF NOT EXISTS `PRODUCTOS`;
USE `PRODUCTOS`;


-- Creando la tabla Categoria
CREATE TABLE IF NOT EXISTS `Categoria` (
  `idCat` int(2) NOT NULL,
  `nomCat` varchar(20) NOT NULL,
  PRIMARY KEY (`idCat`)
);

INSERT INTO `Categoria` VALUES(1, 'Software');
INSERT INTO `Categoria` VALUES(2, 'Hardware');
INSERT INTO `Categoria` VALUES(3, 'Suministros');
INSERT INTO `Categoria` VALUES(4, 'Herramientas');

-- Creando la tabla Productos
CREATE TABLE IF NOT EXISTS `Productos` (
  `idProd` int(11) NOT NULL,
  `nomProd` varchar(30) NOT NULL,
  `idCat` int NOT NULL,
  `precCosto` int NOT NULL,
  `precVenta` int NOT NULL,
  `existencias` int NOT NULL,
  PRIMARY KEY (`idProd`),
  FOREIGN KEY (`idCat`) REFERENCES `Categoria`(`idCat`)
);

INSERT INTO `Productos` VALUES(1111, 'Windows 10', 1, 50000, 75000, 2);
INSERT INTO `Productos` VALUES(2222, 'Office 2016', 1, 20000, 35000, 4);
INSERT INTO `Productos` VALUES(3333, 'Laptop Asus i7', 2, 400000, 500000, 2);
INSERT INTO `Productos` VALUES(4444, 'Impresora Epson punto de venta', 2, 35000, 50000, 1);
INSERT INTO `Productos` VALUES(5555, 'Tinta Epson 420', 3, 1000, 15000, 1);
INSERT INTO `Productos` VALUES(6666, 'Soplador LG', 4, 20000, 25000, 2);