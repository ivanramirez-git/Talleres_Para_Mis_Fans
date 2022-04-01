-- MySQL MariaDB 10.1.23
CREATE TABLE registroinmuebles.inmuebles (
    codigo INT NOT NULL,
    tipo VARCHAR(50) NOT NULL,
    numero INT NOT NULL,
    valor FLOAT NOT NULL,
    PRIMARY KEY (codigo)
);
    