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