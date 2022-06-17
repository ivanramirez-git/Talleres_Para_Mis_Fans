-- DBM: PostgreSQL 14.3
--
-- Tarea #2
-- Intrucciones 
-- 1.	Crear 3 tablas:
-- Tabla 1 con 4 columnas o atributos
-- Tabla 2 con 5 columnas o atributos
-- Tabla 3 con 6 columnas o atributos
DROP TABLE IF EXISTS tabla1;
DROP TABLE IF EXISTS tabla2;
DROP TABLE IF EXISTS tabla3;
-- •	Escribir el codigo para crearlas:
CREATE TABLE tabla1 (
    id INTEGER NOT NULL,
    nombre VARCHAR(50) NOT NULL,
    apellido VARCHAR(50) NOT NULL,
    edad INTEGER NOT NULL,
    PRIMARY KEY (id)
);
CREATE TABLE tabla2 (
    id INTEGER NOT NULL,
    equipo VARCHAR(50) NOT NULL,
    ciudad VARCHAR(50) NOT NULL,
    pais VARCHAR(50) NOT NULL,
    confederacion VARCHAR(50) NOT NULL,
    PRIMARY KEY (id)
);
CREATE TABLE tabla3 (
    id INTEGER NOT NULL,
    marca VARCHAR(50) NOT NULL,
    modelo VARCHAR(50) NOT NULL,
    color VARCHAR(50) NOT NULL,
    precio INTEGER NOT NULL,
    anio INTEGER NOT NULL,
    PRIMARY KEY (id)
);
-- •	Copia el codigo en el documento.
-- •	Ejecuta una consulta para verlo.
SELECT * FROM tabla1;
SELECT * FROM tabla2;
SELECT * FROM tabla3;
-- •	Realiza una captura de pantalla.
-- •	Como la que se muestra a continuación:
-- 2.	Para la tabla  deberas agregar información, copia el codigo para realizarlo y saca captura de pantalla, y agregalos al documento.
INSERT INTO tabla1 (id, nombre, apellido, edad)
VALUES (1, 'Juan', 'Perez', 20);
INSERT INTO tabla1 (id, nombre, apellido, edad)
VALUES (2, 'Pedro', 'Gonzalez', 30);
INSERT INTO tabla1 (id, nombre, apellido, edad)
VALUES (3, 'Maria', 'Gonzalez', 40);
INSERT INTO tabla1 (id, nombre, apellido, edad)
VALUES (4, 'Jose', 'Gonzalez', 50);

SELECT * FROM tabla1;

INSERT INTO tabla2 (id, equipo, ciudad, pais, confederacion)
VALUES (1, 'Barcelona', 'Barcelona', 'España', 'UEFA');
INSERT INTO tabla2 (id, equipo, ciudad, pais, confederacion)
VALUES (2, 'Real Madrid', 'Madrid', 'España', 'UEFA');
INSERT INTO tabla2 (id, equipo, ciudad, pais, confederacion)
VALUES (3, 'Manchester United', 'Manchester', 'Inglaterra', 'UEFA');
INSERT INTO tabla2 (id, equipo, ciudad, pais, confederacion)
VALUES (4, 'Juventus', 'Milan', 'Italia', 'AS');

SELECT * FROM tabla2;

INSERT INTO tabla3 (id, marca, modelo, color, precio, anio) 
VALUES (1, 'Ford', 'Focus', '2000', '100000', '2000');
INSERT INTO tabla3 (id, marca, modelo, color, precio, anio) 
VALUES (2, 'Ford', 'Fiesta', '2010', '200000', '2010');
INSERT INTO tabla3 (id, marca, modelo, color, precio, anio) 
VALUES (3, 'Ford', 'Mustang', '2020', '300000', '2020');
INSERT INTO tabla3 (id, marca, modelo, color, precio, anio) 
VALUES (4, 'Ford', 'Fusion', '2020', '400000', '2020');

SELECT * FROM tabla3;

-- 3.	Para la tabla 1 deberias borrar dos columnas, copia el codigo para realizarlo y saca caputa de pantalla y agregalos al documento 
ALTER TABLE tabla1 DROP COLUMN edad;
ALTER TABLE tabla1 DROP COLUMN nombre;
-- 4.	Para la tabla 2 actualiza el nombre de dos columnas Copia el codigo y agregarlo al documento, realiza consulta y saca captura de pantalla agregarlo al documento.
ALTER TABLE tabla2 RENAME COLUMN equipo TO equipo_nuevo;
ALTER TABLE tabla2 RENAME COLUMN ciudad TO ciudad_nuevo;
-- 5.	Para la tabla 3 borrar 2 filas copia el codigo y agregarlo al documento, realiza consulta y saca captura de pantalla agregarlo al documento.
DELETE FROM tabla3 WHERE id = 1;
DELETE FROM tabla3 WHERE id = 2;
