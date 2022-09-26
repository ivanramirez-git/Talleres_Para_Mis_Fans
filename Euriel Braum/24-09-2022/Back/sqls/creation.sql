-- Base de datos MySQL
--
-- Este archivo contiene las consultas SQL para crear la base de datos en xampp con mysql
--
-- Crear la base de datos flask_db si no existe
DROP DATABASE IF EXISTS flask_db;
CREATE DATABASE IF NOT EXISTS flask_db;
USE flask_db;
-- Tabla users: id, username, password, email, fullname, role, code
CREATE TABLE IF NOT EXISTS `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) NOT NULL, -- unique
  `password` varchar(255) NOT NULL,
  `email` varchar(50) NOT NULL, -- unique
  `fullname` varchar(50) NOT NULL,
  `role` varchar(50) NOT NULL,
  -- adicionar los campos que son unicos
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Tabla sessions: id, user_id(fk), token, created_at, expired_at, status
CREATE TABLE IF NOT EXISTS `sessions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `token` varchar(255) NOT NULL,
  `created_at` datetime NOT NULL,
  `expired_at` datetime NOT NULL,
  `status` varchar(50) NOT NULL, -- logged, expired, logout
  PRIMARY KEY (`id`),
  KEY `user_id` (`user_id`),
  CONSTRAINT `sessions_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1;
-- Insertar admin
INSERT INTO users (username, password, email, fullname, role) VALUES ('admin', 'pbkdf2:sha256:260000$l999FTgAfnN4E5Wx$485350051a7136b6cd38408d17f0fd0a0c5ebeba199a6d2a384cc0e31d7e17e9', 'admin@carrito.com', 'Administrador', 'admin');

-- Eliminar el procedimiento
DROP PROCEDURE IF EXISTS change_status_expired_session;
-- Procedimiento para cambiar el estado de la sesión a expirada cuando la fecha de expiración sea menor a la fecha actual si la sesión está activa
DELIMITER $$
CREATE PROCEDURE `change_status_expired_session`()
BEGIN
-- fecha actual del servidor
  SET @current_date = NOW();
  SELECT *  FROM sessions  WHERE status = 'logged' AND expired_at < @current_date;
  UPDATE sessions SET status = 'expired' WHERE status = 'logged' AND expired_at < @current_date;
  COMMIT;
END$$
DELIMITER ;
-- Ejecutar el procedimiento
CALL change_status_expired_session();
