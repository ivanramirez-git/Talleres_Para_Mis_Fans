-- MySQL MariaDB 10.1.23
-- Crear Base de Datos: recuperacion, si ya existe no se crea
CREATE DATABASE IF NOT EXISTS recuperacion;

-- Tabla: clientes
-- id: int pk
-- dni: varchar(45)
-- nombre: varchar(45)
-- direccion: varchar(45)
-- telefono: varchar(45)
CREATE TABLE IF NOT EXISTS recuperacion.clientes (
  id int(11) NOT NULL AUTO_INCREMENT,
  dni varchar(45) NOT NULL,
  nombre varchar(45) NOT NULL,
  direccion varchar(45) NOT NULL,
  telefono varchar(45) NOT NULL,
  PRIMARY KEY (id)
);

-- Tabla: reservas
-- id: int pk
-- id_cliente: int fk
-- fechainicio: datetime
-- fechafinal: datetime
-- precio: double
CREATE TABLE IF NOT EXISTS recuperacion.reservas (
  id int(11) NOT NULL AUTO_INCREMENT,
  id_cliente int(11) NOT NULL,
  fechainicio datetime NOT NULL,
  fechafinal datetime NOT NULL,
  precio double NOT NULL,
  PRIMARY KEY (id),
  KEY fk_reservas_clientes1_idx (id_cliente),
  CONSTRAINT fk_reservas_clientes1 FOREIGN KEY (id_cliente) REFERENCES recuperacion.clientes (id) ON DELETE NO ACTION ON UPDATE NO ACTION
);

-- Tabla: coches
-- id: int pk
-- matricula: varchar(45)
-- modelo: varcahr(45)
-- color: varchar(45)
-- marca: varchar(45)
-- preciohora: double
CREATE TABLE IF NOT EXISTS recuperacion.coches (
  id int(11) NOT NULL AUTO_INCREMENT,
  matricula varchar(45) NOT NULL,
  modelo varchar(45) NOT NULL,
  color varchar(45) NOT NULL,
  marca varchar(45) NOT NULL,
  preciohora double NOT NULL,
  PRIMARY KEY (id)
);

-- Tabla: alquileres
-- id: int pk
-- id_coch: int fk
-- id_reserva: int fk
-- litrosinicio: int
-- litrosfinal: int
CREATE TABLE IF NOT EXISTS recuperacion.alquileres (
  id int(11) NOT NULL AUTO_INCREMENT,
  id_coch int(11) NOT NULL,
  id_reserva int(11) NOT NULL,
  litrosinicio int(11) NOT NULL,
  litrosfinal int(11) NOT NULL,
  PRIMARY KEY (id),
  KEY fk_alquileres_coches1_idx (id_coch),
  KEY fk_alquileres_reservas1_idx (id_reserva),
  CONSTRAINT fk_alquileres_coches1 FOREIGN KEY (id_coch) REFERENCES recuperacion.coches (id) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT fk_alquileres_reservas1 FOREIGN KEY (id_reserva) REFERENCES recuperacion.reservas (id) ON DELETE NO ACTION ON UPDATE NO ACTION
);

-- a) Insertar 1 registros en cada tabla. (3 puntos)
INSERT INTO recuperacion.clientes (dni, nombre, direccion, telefono) VALUES ('12345678A', 'Pepe', 'C/Falsa', '12345678');
INSERT INTO recuperacion.reservas (id_cliente, fechainicio, fechafinal, precio) VALUES (1, '2020-01-01', '2020-01-02', 100);
INSERT INTO recuperacion.coches (matricula, modelo, color, marca, preciohora) VALUES ('ABC123', 1, 'Rojo', 'Fiat', 10);
INSERT INTO recuperacion.alquileres (id_coch, id_reserva, litrosinicio, litrosfinal) VALUES (1, 1, 10, 20);

-- b) Visualizar todos los registros de cada tabla. (1 puntos)
SELECT * FROM recuperacion.clientes;
SELECT * FROM recuperacion.reservas;
SELECT * FROM recuperacion.coches;
SELECT * FROM recuperacion.alquileres;

-- c) Agregar la columna fecha_nacimiento a la tabla cliente, después de la columna nombre. (1 punto)
ALTER TABLE recuperacion.clientes ADD fecha_nacimiento datetime;

-- d) Actualizar el campo modelo a la tabla coche, ingresando en el primer registro lo siguiente: "Aveo Familiy". (1 punto)
UPDATE recuperacion.coches SET modelo = 'Aveo Family' WHERE id = 1;

-- e) Renombrar el campo nombre de la tabla cliente, con “nombre_cliente”. (1 punto).
ALTER TABLE recuperacion.clientes CHANGE nombre nombre_cliente varchar(45);

-- f) Eliminar el campo fecha_nacimiento a la tabla cliente. (1 punto)
ALTER TABLE recuperacion.clientes DROP fecha_nacimiento;

-- g) Eliminar un registro a su elección de la tabla cliente. (1 punto)
INSERT INTO recuperacion.clientes (dni, nombre_cliente, direccion, telefono) VALUES ('12345678A', 'Pepe', 'C/Falsa', '12345678');
DELETE FROM recuperacion.clientes WHERE id = 2;

-- h) Renombrar la tabla coche, con el nombre “vehículos”. (0.5 puntos).
RENAME TABLE recuperacion.coches TO recuperacion.vehiculos;

-- i) Eliminar la tabla cliente. (0.5 puntos)
-- DROP TABLE recuperacion.clientes;
-- No se puede ya que la tabla reservas tiene una FK a clientes

-- j) Mostrar la marca y modelo del coche, cuando el precio por hora sea mayor a $15. (1 punto).
SELECT marca, modelo FROM recuperacion.vehiculos WHERE preciohora > 15;

-- k) Mostrar el modelo del coche, cuando el precio por hora este entre $10 y $15. (1 punto).
SELECT modelo FROM recuperacion.vehiculos WHERE preciohora BETWEEN 10 AND 15;

-- l) Mostrar los nombres de los clientes, ordenados de forma descendente. (1 punto).
SELECT nombre_cliente FROM recuperacion.clientes ORDER BY nombre_cliente DESC;

-- m) Mostrar el modelo del coche cuando el precio por hora sea menor a $20 y el color sea rojo. (1 punto).
SELECT modelo FROM recuperacion.vehiculos WHERE preciohora < 20 AND color = 'Rojo';

-- n) Mostrar la fecha de inicio y fecha de fin de la reserva cuando el precio total sea distinto de $50. (1 punto).
SELECT fechainicio, fechafinal FROM recuperacion.reservas WHERE precio != 50;

-- ñ) Mostrar la marca y modelo de los coches cuando el color sea negro. (1 punto).
SELECT marca, modelo FROM recuperacion.vehiculos WHERE color = 'Negro';

-- o) Mostrar la marca, modelo y color de los coches cuando el color sea rojo o la marca sea Hyundai. (1 punto).
SELECT marca, modelo, color FROM recuperacion.vehiculos WHERE color = 'Rojo' OR marca = 'Hyundai';

-- p) Mostrar la suma total del precio de las reservas. (1 punto).
SELECT SUM(precio) FROM recuperacion.reservas;

-- q) Mostrar el valor máximo de los precios de alquiler por hora de los coches. (1 punto).
SELECT MAX(preciohora) FROM recuperacion.vehiculos;

-- r) Mostrar el valor mínimo de los precios de alquiler por hora de los coches. (1 punto).
SELECT MIN(preciohora) FROM recuperacion.vehiculos;

-- s) Mostrar el valor promedio de los precios de alquiler por hora de los coches. (1 punto).
SELECT AVG(preciohora) FROM recuperacion.vehiculos;

-- t) Mostrar el modelo, color y marca de los coches, cuyos colores sean gris, negro y blanco. (1 punto).
SELECT modelo, color, marca FROM recuperacion.vehiculos WHERE color = 'Gris' OR color = 'Negro' OR color = 'Blanco';

-- u) Mostrar el nombre y teléfono de los clientes, cuyos nombres inicien con la letra R. (1 punto).
SELECT nombre, telefono FROM recuperacion.clientes WHERE nombre NOT LIKE 'R%';

-- v) Mostrar el nombre y teléfono de los clientes, cuyos nombres no culminen en la letra S. (1 punto).
SELECT nombre, telefono FROM recuperacion.clientes WHERE nombre NOT LIKE '%S';

-- w) Mostrar el promedio del precio de alquiler por hora de los coches, agrupados por marca, pero solamente aquellos grupos cuyo promedio supere los $15. (1 punto).
SELECT marca, AVG(preciohora) FROM recuperacion.vehiculos GROUP BY marca HAVING AVG(preciohora) > 15;

