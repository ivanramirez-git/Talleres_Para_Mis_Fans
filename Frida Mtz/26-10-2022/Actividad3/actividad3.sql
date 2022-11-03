
-- ACTIVIDAD 3 
-- SELECT * FROM tabla
-- Objetivo de la actividad:
-- Elaboración de Consultas (QUERIES) Básicas en SQL, utilizando SELECT, WHERE y
-- funciones a nivel de registro. Mostrar el Código SQL y los resultados.

-- SOLUCIONES
-- 1.- Obtener un listado de todos los proveedores.
SELECT * FROM PROVEEDOR;

-- 2.- Obtener un listado que muestre el nombre y el número de proveedor, de las ciudades
-- que tengan ESTATUS MAYOR DE 10.
SELECT NOMBRE, NUMEROPROV FROM PROVEEDOR WHERE ESTATUS > 10;

-- 3. - Obtener un listado que muestre el número de proveedor de los proveedores que
-- estén en la Cd. de Paris.
SELECT NUMEROPROV FROM PROVEEDOR WHERE CIUDAD = 'PARIS';

-- 4- Obtener un listado que muestre el número de proveedor, de los proveedores que
-- estén en la Cd. de Paris, en orden descendente de status.
SELECT NUMEROPROV FROM PROVEEDOR WHERE CIUDAD = 'PARIS' ORDER BY ESTATUS DESC;

-- 5.- Obtener un listado que muestre la descripción y el costo de los productos que sean
-- de color ROSA.
SELECT NOMPARTE, COSTO FROM PARTES WHERE COLOR = 'ROSA';

-- 6.- Obtener un listado que muestre todos los datos de los productos ( todos los datos)
-- que cuesten más de 5000.
SELECT * FROM PARTES WHERE COSTO > 5000;

-- 7 .- Obtener un listado que muestre la descripción de los productos de color AZUL.
SELECT NOMPARTE FROM PARTES WHERE COLOR = 'AZUL';

-- 8 - Obtener un listado que muestre el nombre de los proveedores que surten la pieza
-- “P02”
SELECT NOMBRE FROM PROVEEDOR WHERE NUMEROPROV IN (SELECT NUMEROPROV FROM COMPRAS WHERE NUMPARTE = 'P02');

