-- -- DBM: PostgreSQL 14.3
--

-- Primer problema: 
-- 1.	Crear una tabla llamada medicamentos2 con la siguiente estructura:

-- •	codigo serial primary key
-- •	nombre varchar(20)
-- •	laboratorio varchar(20)
-- •	precio decimal(6,2)
-- •	cantidad smallint
-- •	fechavencimiento date not null
-- •	numerolote int default null

DROP TABLE IF EXISTS medicamentos2;
CREATE TABLE medicamentos2 (
    codigo serial primary key,
    nombre varchar(20) not null,
    laboratorio varchar(20) default null,
    precio decimal(6,2) default null,
    cantidad smallint default null,
    fechavencimiento date not null,
    numerolote int default null
);
-- Ingrese algunos registros:
-- •	Sertal,Roche,5.2,1,2015-02-01,null
-- •	Buscapina,Roche,4.10,3,2016-03-01,null
-- •	Amoxidal 500,Bayer,15.60,100,2017-05-01,null
-- •	Paracetamol 500,Bago,1.90,20,2018-02-01,null
-- •	Bayaspirina,null,2.10,null,2019-12-01,null 
-- •	Amoxidal jarabe,Bayer,null,250,2019-12-15,null 
INSERT INTO medicamentos2 (nombre, laboratorio, precio, cantidad, fechavencimiento, numerolote)
VALUES ('Sertal', 'Roche', 5.2, 1, '2015-02-01', null);
INSERT INTO medicamentos2 (nombre, laboratorio, precio, cantidad, fechavencimiento, numerolote)
VALUES ('Buscapina', 'Roche', 4.10, 3, '2016-03-01', null);
INSERT INTO medicamentos2 (nombre, laboratorio, precio, cantidad, fechavencimiento, numerolote)
VALUES ('Amoxidal 500', 'Bayer', 15.60, 100, '2017-05-01', null);
INSERT INTO medicamentos2 (nombre, laboratorio, precio, cantidad, fechavencimiento, numerolote)
VALUES ('Paracetamol 500', 'Bago', 1.90, 20, '2018-02-01', null);
INSERT INTO medicamentos2 (nombre, laboratorio, precio, cantidad, fechavencimiento, numerolote)
VALUES ('Bayaspirina', null, 2.10, null, '2019-12-01', null);
INSERT INTO medicamentos2 (nombre, laboratorio, precio, cantidad, fechavencimiento, numerolote)
VALUES ('Amoxidal jarabe', 'Bayer', null, 250, '2019-12-15', null);
-- 2.	Muestre la cantidad de registros empleando la función "count(*)" (6 registros.
SELECT count(*) FROM medicamentos2;
-- 3.	Cuente la cantidad de medicamentos que tienen laboratorio conocido (5 registros).
SELECT count(*) FROM medicamentos2 WHERE laboratorio IS NOT NULL;
-- 4.	Cuente la cantidad de medicamentos que tienen precio distinto a "null" y que tienen cantidad distinto a "null", disponer alias para las columnas.
SELECT count(*) AS cantidad FROM medicamentos2 WHERE precio IS NOT NULL AND cantidad IS NOT NULL;
-- 5.	Cuente la cantidad de remedios con precio conocido, cuyo laboratorio comience con "B" (2 registros.
SELECT count(*) FROM medicamentos2 WHERE laboratorio LIKE 'B%';
-- 6.	Cuente la cantidad de medicamentos con número de lote distinto de "null" (0 registros).
SELECT count(*) FROM medicamentos2 WHERE numerolote IS NOT NULL;






-- Segundo problema 

-- Una empresa guarda los datos de sus empleados en una tabla "empleados".

-- 1.	Crear tabla empleados con la suguiente estructura
-- •	nombre varchar(30),
-- •	documento char(8) primary key,
-- •	domicilio varchar(30),
-- •	seccion varchar(20),
-- •	sueldo decimal(6,2),
-- •	cantidadhijos smallint,

DROP TABLE IF EXISTS empleados;
CREATE TABLE empleados (
    nombre varchar(30) not null,
    documento char(8) primary key,
    domicilio varchar(30) not null,
    seccion varchar(20) not null,
    sueldo decimal(6,2) default null,
    cantidadhijos smallint default null
);

-- 2.	Ingrese algunos registros:
 
-- •	Juan Perez,22333444,Colon 123,Gerencia,5000,2
-- •	Ana Acosta,23444555,Caseros 987,Secretaria,2000,0
-- •	Lucas Duarte,25666777,Sucre 235,Sistemas,4000,1
-- •	Pamela Gonzalez,26777888,Sarmiento 873,Secretaria,2200,3
-- •	Marcos Juarez,30000111,Rivadavia 801,Contaduria,3000,0
-- •	Yolanda Perez,35111222,Colon 180,Administracion,3200,1
-- •	Rodolfo Perez,35555888,Coronel Olmedo 588,Sistemas,4000,3
-- •	Martina Rodriguez,30141414,Sarmiento 1234,Administracion,3800,4
-- •	Andres Costa,28444555,default,Secretaria,null,null
INSERT INTO empleados (nombre, documento, domicilio, seccion, sueldo, cantidadhijos)
VALUES ('Juan Perez', '22333444', 'Colon 123', 'Gerencia', 5000, 2);
INSERT INTO empleados (nombre, documento, domicilio, seccion, sueldo, cantidadhijos)
VALUES ('Ana Acosta', '23444555', 'Caseros 987', 'Secretaria', 2000, 0);
INSERT INTO empleados (nombre, documento, domicilio, seccion, sueldo, cantidadhijos)
VALUES ('Lucas Duarte', '25666777', 'Sucre 235', 'Sistemas', 4000, 1);
INSERT INTO empleados (nombre, documento, domicilio, seccion, sueldo, cantidadhijos)
VALUES ('Pamela Gonzalez', '26777888', 'Sarmiento 873', 'Secretaria', 2200, 3);
INSERT INTO empleados (nombre, documento, domicilio, seccion, sueldo, cantidadhijos)
VALUES ('Marcos Juarez', '30000111', 'Rivadavia 801', 'Contaduria', 3000, 0);
INSERT INTO empleados (nombre, documento, domicilio, seccion, sueldo, cantidadhijos)
VALUES ('Yolanda Perez', '35111222', 'Colon 180', 'Administracion', 3200, 1);
INSERT INTO empleados (nombre, documento, domicilio, seccion, sueldo, cantidadhijos)
VALUES ('Rodolfo Perez', '35555888', 'Coronel Olmedo 588', 'Sistemas', 4000, 3);
INSERT INTO empleados (nombre, documento, domicilio, seccion, sueldo, cantidadhijos)
VALUES ('Martina Rodriguez', '30141414', 'Sarmiento 1234', 'Administracion', 3800, 4);
INSERT INTO empleados (nombre, documento, domicilio, seccion, sueldo, cantidadhijos)
VALUES ('Andres Costa', '28444555', 'default', 'Secretaria', null, null);

-- 3.	Muestre la cantidad de empleados usando "count" (9 empleados.
SELECT count(*) FROM empleados;
-- 4.	Muestre la cantidad de empleados con sueldo no nulo de la sección "Secretaria" (2 empleados.
SELECT count(*) FROM empleados WHERE seccion = 'Secretaria' AND sueldo IS NOT NULL;
-- 5.	Muestre el sueldo más alto y el más bajo colocando un alias (5000 y 2000).
SELECT max(sueldo) AS max, min(sueldo) AS min FROM empleados;
-- 6.	Muestre el valor mayor de "cantidadhijos" de los empleados que contengan "Perez" (3 hijos).
SELECT cantidadhijos FROM empleados WHERE nombre LIKE '%Perez%' ORDER BY cantidadhijos DESC LIMIT 1;
-- 7.	Muestre el promedio de sueldos de todo los empleados (3400. Note que hay un sueldo nulo y no es tenido en cuenta
SELECT avg(sueldo) FROM empleados;
-- 8.	Muestre el promedio de sueldos de los empleados de la sección "Secretaría" (2100.
SELECT avg(sueldo) FROM empleados WHERE seccion = 'Secretaria';
-- 9.	Muestre el promedio de hijos de todos los empleados de "Sistemas" (2).
SELECT avg(cantidadhijos) FROM empleados WHERE seccion = 'Sistemas';


-- Tercer problema 
-- Un comercio que tiene un stand en una feria registra en una tabla llamada "visitantes" algunos datos de las personas que visitan o compran en su stand para luego enviarle publicidad de sus productos.

-- 1.	Cree la tabla visitantes  con la siguiente estructura:
--   nombre varchar(30)
--   edad smallint
--   sexo char(1) default 'f'
--   domicilio varchar(30)
--   ciudad varchar(20) default 'Cordoba'
--   telefono varchar(11),
--   mail varchar(30) default 'no tiene'
--   montocompra decimal (6,2)
DROP TABLE IF EXISTS visitantes;
CREATE TABLE visitantes (
    nombre varchar(30) not null,
    edad smallint default null,
    sexo char(1) default 'f',
    domicilio varchar(30) default null,
    ciudad varchar(20) default 'Cordoba',
    telefono varchar(11) default null,
    mail varchar(30) default 'no tiene',
    montocompra decimal (6,2) default null
); 
-- 2.	Ingrese algunos registros:
-- •	Susana Molina,35,default,Colon 123,default,null,null,59.80
-- •	Marcos Torres,29,m,default,Carlos Paz,default, marcostorres@hotmail.com, 150.50
-- •	Mariana Juarez,45,default,default,Carlos Paz,null,default,23.90
-- •	Fabian Perez,36,m,4556677,fabianperez@xaxamail.com
-- •	Alejandra Gonzalez,La Falda,280.50
-- •	Gaston Perez,29,m,Carlos Paz,gastonperez1@gmail.com,95.40
-- •	Liliana Torres,40,default,Sarmiento 876,default,default,default,85
-- •	GabrielaDuarte,21,null,null,RioTercero,default,gabrielaltorres@hotmail.com,321.50
INSERT INTO visitantes (nombre, edad, sexo, domicilio, ciudad, telefono, mail, montocompra)
VALUES ('Susana Molina', 35, default, 'Colon 123', default, null, null, 59.80);
INSERT INTO visitantes (nombre, edad, sexo, domicilio, ciudad, mail, montocompra)
VALUES ('Marcos Torres', 29, 'm', default, 'Carlos Paz', 'marcostorres@hotmail.com', 150.50);
INSERT INTO visitantes (nombre, edad, sexo, domicilio, ciudad, telefono, mail, montocompra)
VALUES ('Mariana Juarez', 45, default, 'default', 'Carlos Paz', null, default, 23.90);
INSERT INTO visitantes (nombre, edad, sexo, domicilio, mail)
VALUES ('Fabian Perez', 36, 'm', '4556677', 'fabianperez@xaxamail.com');
INSERT INTO visitantes (nombre, ciudad, montocompra)
VALUES ('Alejandra Gonzalez', 'La Falda', 280.50);
INSERT INTO visitantes (nombre, edad, sexo, ciudad, mail, montocompra)
VALUES ('Gaston Perez', 29, 'm', 'Carlos Paz', 'gastonperez1@gmail.com', 95.40);
INSERT INTO visitantes (nombre, edad, sexo, domicilio, ciudad, telefono, mail, montocompra)
VALUES ('Liliana Torres', 40, default, 'Sarmiento 876', default, default, default, 85);
INSERT INTO visitantes (nombre, edad, sexo, domicilio, ciudad, telefono, mail, montocompra)
VALUES ('GabrielaDuarte', 21, null, null, 'RioTercero', default, 'gabrielaltorres@hotmail.com', 321.50);
-- 3.	Se requiere saber la cantidad de visitantes de cada ciudad utilizando la cláusula "group by" (4 filas devueltas)
SELECT ciudad, count(*) FROM visitantes GROUP BY ciudad;
-- 4.	Conocer la cantidad visitantes con teléfono no nulo, de cada ciudad (4 filas devueltas)
SELECT ciudad, count(*) FROM visitantes WHERE telefono IS NOT NULL GROUP BY ciudad;
-- 5.	Total del monto de las compras agrupadas por sexo (3 filas)
SELECT sexo, sum(montocompra) FROM visitantes GROUP BY sexo;
-- 6.	Se necesita saber el máximo y mínimo valor de compra agrupados por sexo y ciudad (6 filas)
SELECT sexo, ciudad, max(montocompra), min(montocompra) FROM visitantes GROUP BY sexo, ciudad;
-- 7.	Calcule el promedio del valor de compra agrupados por ciudad (4 filas)
SELECT ciudad, avg(montocompra) FROM visitantes GROUP BY ciudad;
-- 8.	Cuente y agrupe por ciudad sin tener en cuenta los visitantes que no tienen mail (3 filas)
SELECT ciudad, count(*) FROM visitantes WHERE mail IS NOT NULL GROUP BY ciudad;