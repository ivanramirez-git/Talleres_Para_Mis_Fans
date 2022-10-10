-- GENERAR la base de datos INVENTARIOS, con las siguientes especificaciones:
-- ( UTILIZANDO LOS NOMBRES DE LOS DATOS COMO AQUI SE INDICAN,)
-- En este caso práctico, un proveedor puede surtir varios productos. Pero un producto
-- puede ser surtido por varios proveedores, en diferente fecha y cantidad.
-- BASE DE DATOS "INVENTARIOS"
-- TABLAS:
-- PROD    (NUMPROD character(3)
--          NOMPROD character(20)
--          COLOR character(10)
--          PESO numeric(3)
--          COSTO numeric(4)
--          EXISTENCIA numeric(4))
-- PROVEDEDOR (NUMPROV character(3)
--             NOMPROD character(20)
--             CIUDAD character(20)
--             ESTATUS numeric(2))
-- COMPRAS ( USTED DEBERÁ ESCRIBIR LOS ATRIBUTOS DE LOS QUE SE COMPONE
-- ESTA RELACIÓN, RESULTANTE DE LA NORMALIZACIÓN E INDICAR LAS LLAVES
-- CORRESPONDIENTES)
-- INCLUYA LAS LLAVES YA SEAN PRIMARIAS O SECUNDARIAS EN LA INSTRUCCIÓN
-- CORRESPONDIENTE, CONSIDERANDO QUE NUMPROD ES LA LLAVE PRINCIPAL DE LA
-- TABLA PROD Y NUMPROV ES LA LLAVE PRINCIPAL DE LA TABLA PROVEEDOR.
-- Si no existe crear la base de datos
DROP DATABASE IF EXISTS inventarios;
CREATE DATABASE IF NOT EXISTS inventarios;
-- Seleccionar la base de datos
USE inventarios;
-- Crear la tabla PROD
DROP TABLE IF EXISTS prod;
CREATE TABLE IF NOT EXISTS prod (
    numprod CHAR(3) NOT NULL,
    nomprod CHAR(20) NOT NULL,
    color CHAR(10) NOT NULL,
    peso DECIMAL(3, 2) NOT NULL,
    costo DECIMAL(4, 2) NOT NULL,
    existencia DECIMAL(4, 2) NOT NULL,
    PRIMARY KEY (numprod)
);
-- Crear la tabla PROVEEDOR
DROP TABLE IF EXISTS proveedor;
CREATE TABLE IF NOT EXISTS proveedor (
    numprov CHAR(3) NOT NULL,
    nomprov CHAR(20) NOT NULL,
    ciudad CHAR(20) NOT NULL,
    estatus DECIMAL(2, 0) NOT NULL,
    PRIMARY KEY (numprov)
);
-- Crear la tabla COMPRAS
DROP TABLE IF EXISTS compras;
CREATE TABLE IF NOT EXISTS compras (
    numprod CHAR(3) NOT NULL,
    numprov CHAR(3) NOT NULL,
    fecha DATE NOT NULL,
    cantidad DECIMAL(4, 2) NOT NULL,
    PRIMARY KEY (numprod, numprov, fecha),
    FOREIGN KEY (numprod) REFERENCES prod(numprod),
    FOREIGN KEY (numprov) REFERENCES proveedor(numprov)
);
-- Insertar datos en la tabla PROD
INSERT INTO prod (numprod, nomprod, color, peso, costo, existencia)
VALUES ('001', 'Tornillo', 'Rojo', 0.05, 0.10, 3000);
INSERT INTO prod (numprod, nomprod, color, peso, costo, existencia)
VALUES ('002', 'Tuerca', 'Verde', 0.03, 0.05, 2000);
INSERT INTO prod (numprod, nomprod, color, peso, costo, existencia)
VALUES ('003', 'Clavo', 'Azul', 0.01, 0.02, 4000);
INSERT INTO prod (numprod, nomprod, color, peso, costo, existencia)
VALUES ('004', 'Martillo', 'Amarillo', 0.50, 50.00, 10);
INSERT INTO prod (numprod, nomprod, color, peso, costo, existencia)
VALUES ('005', 'Destornillador', 'Blanco', 0.25, 40.00, 20);
-- Insertar datos en la tabla PROVEEDOR
INSERT INTO proveedor (numprov, nomprov, ciudad, estatus)
VALUES ('001', 'Juan Perez', 'Monterrey', 1);
INSERT INTO proveedor (numprov, nomprov, ciudad, estatus)
VALUES ('002', 'Maria Lopez', 'Guadalajara', 1);
INSERT INTO proveedor (numprov, nomprov, ciudad, estatus)
VALUES ('003', 'Pedro Sanchez', 'Montemorelos', 1);
INSERT INTO proveedor (numprov, nomprov, ciudad, estatus)
VALUES ('004', 'Jose Garcia', 'Matamoros', 1);
INSERT INTO proveedor (numprov, nomprov, ciudad, estatus)
VALUES ('005', 'Luis Hernandez', 'Saltillo', 1);
-- Insertar datos en la tabla COMPRAS
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('001', '001', '2018-01-01', 100);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('001', '002', '2018-01-02', 200);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('001', '003', '2018-01-03', 300);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('001', '004', '2018-01-04', 400);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('002', '001', '2018-01-05', 100);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('002', '002', '2018-01-06', 200);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('002', '003', '2018-01-07', 300);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('002', '004', '2018-01-08', 400);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('003', '001', '2018-01-09', 100);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('003', '002', '2018-01-10', 200);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('003', '003', '2018-01-11', 300);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('003', '004', '2018-01-12', 400);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('004', '001', '2018-01-13', 1);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('004', '002', '2018-01-14', 2);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('004', '003', '2018-01-15', 3);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('004', '004', '2018-01-16', 4);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('005', '001', '2018-01-17', 2);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('005', '002', '2018-01-18', 3);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('005', '003', '2018-01-19', 4);
INSERT INTO compras (numprod, numprov, fecha, cantidad)
VALUES ('005', '004', '2018-01-20', 5);



-- Consultar la tabla PROD
SELECT *
FROM prod;
-- Consultar la tabla PROVEEDOR
SELECT *
FROM proveedor;
-- Consultar la tabla COMPRAS
SELECT *
FROM compras;