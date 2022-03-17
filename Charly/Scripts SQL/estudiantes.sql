-- MySQL MariaDB 10.1.23
CREATE TABLE universidad.estudiantes (
    id INT NOT NULL AUTO_INCREMENT,
    nombre VARCHAR(50) NOT NULL,
    telefono VARCHAR(10) NOT NULL,
    email VARCHAR(50) NOT NULL,
    anioingreso INT NOT NULL,
    PRIMARY KEY (id)
);