
-- ACTIVIDAD 4
-- REALIZAR CONSULTAS DE NIVELES (ANIDADAS) Y QUERIES AGRUPADOS (Utilizando
-- GROUP BY y HAVING)
-- Objetivo de la actividad: Elaboración de Consultas (QUERIES) de niveles en SQL,
-- utilizando las operaciones Producto Cartesiano y la operación INNER JOIN.. Mostrar el
-- Código SQL y los resultados.
-- EJEMPLO: Listar el número de parte y la ciudad de donde procede el proveedor, de las
-- partes que se están surtiendo actualmente.
-- select * from compras, proveedor
-- (OBSERVEN QUE EL OPERADOR DEL PRODUCTO CARTESIANO EN EL CÓDIGO SQL ES LA
-- COMA MUY IMPORTANTE SABER QUE ESTE SIGNO NO ES DE ADORNO SINO QUE ES UN
-- OPERADOR.
-- CORRAN EL PROGRAMA PARA OBSERVAR EL RESULTADO. AQUÍ SE REALIZA EL
-- PRODUCTO CARTESIANO ENTRE LAS TABLAS COMPRAS Y PROVEEDORES, PERO
-- OBTENDREMOS TODOS LOS ATRIBUTOS Y RENGLONES QUE NO TENGAN SIGNIFICADO,
-- SINO HASTA QUE HAGAMOS COINCIDIR LAS LLAVES DE LA TABLA PADRE O SEA
-- PROVEEDOR Y LA LLAVE DE LA TABLA HIJA, EN ESTE CASO ES LA TABLA COMPRAS)
-- select proveedor. numeroprov, ciudad from compras, proveedor where compras.
-- numeroprov = proveedor. numeroprov
-- (EN ESTE QUERIE, OBSERVEN QUE SE ESTÁ SOLICITANDO DESPLEGAR O MOSTRAR
-- CIERTOS ATRIBUTOS, ES DECIR APLICAMOS LA OPERACIÓN PROYECCIÓN AL ESCRIBIR
-- LOS ATRIBUTOS EN EL CÓDIGO y COMO EN LAS DOS TABLAS EXISTE UN ATRIBUTO
-- NUMEROPROV , SE DEBE INCLUIR EN NOMBRE DE LA TABLA CON UN PUNTO . ANTES
-- DEL NOMBRE DEL ATRIBUTO. PARA ENCONTRAR LAS TUPLAS QUE SI NOS INTERESAN,
-- ES DECIR COINCIDEN EN LA LLAVE)
-- CON QUERIES DE NIVELES ESTE MISMO PROGRAMA REQUIERE DE 2 NIVELES. ES DECIR
-- 2 PROGRAMAS CON SU CORRESPONDIENTE SELECT. PARA PRACTICAR CON 2
-- NIVELES, LO MODIFICAMOS ASÍ:
-- OBTENER LAS CIUDADES DE DONDE PROCEDEN LOS PROVEEDORES QUE ESTÁN
-- SURTIENDO PRODUCTOS, ES DECIR QUE APARECEN EN LA TABLA COMPRAS.
--  SELECT NUMEROPROV, CIUDAD FROM PROVEEDOR
-- sin repetidos se utiliza la cláusula DISTINCT :
-- select distinct prov. numeroprov , ciudad from Compras, Proveedor where compras.
-- numeroprov = prov.numeroprov WHERE NUMEROPROV = ANY ( SELECT NUMEROPROV
-- FROM COMPRAS)
-- SE UTILIZARÁN EN ESTA PRACTICA TAMBIÉN LA CLÁUSULA DESC Y LAS FUNCIONES
-- MIN, MAX, AVERAGE, COUNT y SUM. CONSULTE EN EL LIBRO SU SINTAXIS.

--SOLUCIONES

-- 1.- EXPLIQUE LA DIFERENCIA DE UTILIZAR OPERACIÓN PRODUCTO CARTESIANO Y LA
-- OPERACIÓN INNER JOIN EN SQL, ADEMÁS MENCIONE SU REPRESENTACIÓN EN
-- CÓDIGO SQL.

-- La diferencia entre el producto cartesiano y el inner join es que el producto cartesiano
-- nos muestra todos los datos de las tablas, sin importar si tienen relación o no, mientras que el inner
-- join nos muestra los datos que tienen relación entre sí.
-- Ejemplo:
-- SELECT * FROM PROVEEDOR, COMPRAS;
-- SELECT * FROM PROVEEDOR INNER JOIN COMPRAS ON PROVEEDOR.NUMEROPROV = COMPRAS.NUMEROPROV;

-- SE PIDE REALIZAR LOS PROGRAMAS EN SQL PARA :
-- 2.- Obtener un listado que muestre el NOMBRE del proveedor de los proveedores que
-- estén en la Cd. de Paris, en orden descendente del status.
SELECT NOMBRE FROM PROVEEDOR WHERE CIUDAD = 'PARIS' ORDER BY ESTATUS DESC;

-- 3.- Obtener el número de proveedor de los proveedores, que actualmente estén
-- surtiendo la parte P03. CON PRODUCTO CARTESIANO
SELECT PROVEEDOR.NUMEROPROV FROM PROVEEDOR, COMPRAS WHERE PROVEEDOR.NUMEROPROV = COMPRAS.NUMEROPROV AND COMPRAS.NUMPARTE = 'P03';

-- 4.- Obtener el nombre de proveedor de los proveedores, que actualmente estén
-- surtiendo la parte P03. CON REUNIÓN NATURAL
SELECT PROVEEDOR.NOMBRE FROM PROVEEDOR NATURAL JOIN COMPRAS WHERE COMPRAS.NUMPARTE = 'P03';

-- 5.-Obtener el nombre de proveedor de los proveedores, que actualmente estén surtiendo
-- la parte P03. CON QUERIES DE NIVELES
SELECT PROVEEDOR.NOMBRE FROM PROVEEDOR WHERE PROVEEDOR.NUMEROPROV IN (SELECT COMPRAS.NUMEROPROV FROM COMPRAS WHERE COMPRAS.NUMPARTE = 'P03');

-- 6.-.-Obtener el nombre de proveedor de los proveedores, que actualmente estén
-- surtiendo la parte P03.
SELECT PROVEEDOR.NOMBRE FROM PROVEEDOR INNER JOIN COMPRAS ON PROVEEDOR.NUMEROPROV = COMPRAS.NUMEROPROV WHERE COMPRAS.NUMPARTE = 'P03';

-- 7.- Obtener el número del proveedor de aquellos que tengan menor status. Obtener el
-- nombre de proveedor que tenga el Estatus máximo.
SELECT NUMEROPROV FROM PROVEEDOR WHERE ESTATUS = (SELECT MIN(ESTATUS) FROM PROVEEDOR);
SELECT NOMBRE FROM PROVEEDOR WHERE ESTATUS = (SELECT MAX(ESTATUS) FROM PROVEEDOR);

-- 8.-Utilizando “Querys” de 2 niveles , obtener el número del proveedor ,de aquellos que
-- actualmente están surtiendo la parte P10.
SELECT PROVEEDOR.NUMEROPROV FROM PROVEEDOR WHERE PROVEEDOR.NUMEROPROV IN (SELECT COMPRAS.NUMEROPROV FROM COMPRAS WHERE COMPRAS.NUMPARTE = 'P10');

-- 9.- Utilizando “Querys” de niveles, obtener el nombre del proveedor de aquellos que
-- actualmente están surtiendo partes de color “rojo”.
SELECT PROVEEDOR.NOMBRE FROM PROVEEDOR WHERE PROVEEDOR.NUMEROPROV IN (SELECT COMPRAS.NUMEROPROV FROM COMPRAS WHERE COMPRAS.NUMPARTE IN (SELECT PARTES.NUMPARTE FROM PARTES WHERE PARTES.COLOR = 'ROJO'));

-- 10.- Utilizando “Querys” de niveles obtener el nombre de las partes que surten más de
-- un proveedor.
SELECT PARTES.NOMPARTE FROM PARTES WHERE PARTES.NUMPARTE IN (SELECT COMPRAS.NUMPARTE FROM COMPRAS GROUP BY COMPRAS.NUMPARTE HAVING COUNT(COMPRAS.NUMPARTE) > 1);

-- 11.- Obtener el número total de proveedores. Utilizando la función COUNT.
SELECT COUNT(NUMEROPROV) FROM PROVEEDOR;

-- 12.- Listar todos los datos de proveedor que esté surtiendo actualmente cualquier parte
-- y que la ciudad sea LONDRES.
SELECT * FROM PROVEEDOR WHERE PROVEEDOR.NUMEROPROV IN (SELECT COMPRAS.NUMEROPROV FROM COMPRAS) AND CIUDAD = 'LONDRES';

-- 13.- Utilizando “Querys” de niveles, obtener las ciudades en las que haya más de un
-- proveedor.
SELECT CIUDAD FROM PROVEEDOR WHERE PROVEEDOR.NUMEROPROV IN (SELECT COMPRAS.NUMEROPROV FROM COMPRAS GROUP BY COMPRAS.NUMEROPROV HAVING COUNT(COMPRAS.NUMEROPROV) > 1);

-- 14.- Obtener un listado de las partes que pesen más de 5.
SELECT * FROM PARTES WHERE PESO > 5;

-- 15.- Obtener un listado de los proveedores (nombres) que están en una misma ciudad.
SELECT NOMBRE FROM PROVEEDOR WHERE CIUDAD IN (SELECT CIUDAD FROM PROVEEDOR GROUP BY CIUDAD HAVING COUNT(CIUDAD) > 1);

-- 16.- Analice el siguiente programa y determine lo que obtiene select * from Proveedor as
-- primera, Proveedor as segunda where primera.ciudad = segunda.ciudad and
-- primera.numeroprov > segunda.numeroprov
-- SOLUCIONES
-- SOLUCIÓN: El programa anterior nos muestra los datos de los proveedores que se encuentran en la misma ciudad y que el número de proveedor de la primera tabla sea mayor al de la segunda tabla.
