-- Languaje: SQL (MySQL)
--
-- Crear base de datos matriz
--
CREATE DATABASE IF NOT EXISTS matriz;
USE matriz;
CREATE TABLE IF NOT EXISTS ciudades (
    id INTEGER PRIMARY KEY auto_increment,
    nombre VARCHAR(50)
);
CREATE TABLE IF NOT EXISTS distancias (
    id_ciudad1 INTEGER,
    id_ciudad2 INTEGER,
    distancia REAL
);