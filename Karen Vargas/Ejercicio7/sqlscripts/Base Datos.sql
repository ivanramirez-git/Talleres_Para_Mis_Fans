CREATE DATABASE registroinmuebles;

-- MySQL MariaDB 10.1.23
CREATE TABLE registroinmuebles.inmuebles (
    codigo INT NOT NULL,
    tipo VARCHAR(50) NOT NULL,
    numero INT NOT NULL,
    valor FLOAT NOT NULL,
    PRIMARY KEY (codigo)
);

INSERT INTO registroinmuebles.inmuebles (codigo, tipo, numero, valor) VALUES (1020, 'Apto', 201, 210000000);

-- TODOS LOS INMUEBLES
SELECT *
FROM inmuebles;
-- INMUEBLES CON VALOR MENOR A 200.000.000
SELECT *
FROM inmuebles
WHERE valor < 200000000;
-- INMUEBLES CON VALOR MAYOR O IGUAL A 200.000.000
SELECT *
FROM inmuebles
WHERE valor >= 200000000;