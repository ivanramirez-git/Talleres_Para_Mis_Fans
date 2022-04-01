use SistemVenta;

--FUNCIÓN 1: Función que retorna el promedio del precio de todos los productos
CREATE FUNCTION precio_promedio ()
RETURNS DECIMAL(4,2)
AS 
BEGIN
	DECLARE @prom DECIMAL(4,2)
	SET @prom = (SELECT AVG(prec) FROM producto)
RETURN @prom
END;

--Llammar a la función
SELECT dbo.precio_promedio() as promedio;


--FUNCIÓN 2: Función que retorna el vuelto de un cliente por su id y por la id de producto de acuerdo a lo que pagó y lós productos que compró
CREATE FUNCTION vuelto (@id_usuario varchar(5), @id_producto varchar(5))
RETURNS DECIMAL(4,2)
AS 
BEGIN
	DECLARE @importe DECIMAL(4,2)
	SET @importe = 	(SELECT import FROM cliente_producto 
					WHERE cliente_producto.id_clien = @id_usuario AND cliente_producto.id_prod = @id_producto)

	DECLARE @cantidad INT
	SET @cantidad = 	(SELECT cant FROM cliente_producto 
					WHERE cliente_producto.id_clien = @id_usuario AND cliente_producto.id_prod = @id_producto)

	DECLARE @precio DECIMAL(4,2)
	SET @precio = (SELECT prec FROM producto WHERE producto.id_prod = @id_producto)

RETURN @importe - (@precio*@cantidad)
END;


--Llammar a la función
SELECT dbo.vuelto('C01', 'PR10') as vuelto;



--FUNCIÓN 3: Función que retorna el la dirección del cajero por la id de voucher
CREATE FUNCTION direccion_voucher(@id_voucher varchar(5))
RETURNS VARCHAR(50)
AS 
BEGIN
	DECLARE @nombre VARCHAR(50)
	SET @nombre = (SELECT cajero.dire FROM cajero, voucher WHERE 
					voucher.id_vou = @id_voucher AND voucher.id_caje = cajero.id_caje)

RETURN @nombre
END; 

--Llammar a la función
SELECT dbo.direccion_voucher('V1010') as direccion;



--FUNCIÓN 4: Función que retorna el nombre del local que administra un administrado por su id
CREATE FUNCTION nom_local_por_id_admin(@idAdmin varchar(15))
RETURNS VARCHAR(50)
AS 
BEGIN
	DECLARE @nombre VARCHAR(50)
	SET @nombre = (SELECT local.nom FROM administrador, local WHERE 
					local.id_loc = administrador.id_loc AND administrador.id_admin = @idAdmin)
RETURN @nombre
END; 

--Llammar a la función
SELECT dbo.nom_local_por_id_admin('ADMIN78290') as nombre_local;



--FUNCIÓN 5: Función que retorna el valor que consiguió vender un vendedor en ventas por la id del vendedor
CREATE FUNCTION valor_ventas_por_id_vendedor(@id_vendedor varchar(5))
RETURNS DECIMAL(4,2)
AS
BEGIN
    DECLARE @valor DECIMAL(4,2)
    SET @valor = (SELECT SUM(import) FROM venta WHERE venta.id_vende = @id_vendedor)
RETURN @valor
END;
--Llamar a la función
SELECT dbo.valor_ventas_por_id_vendedor('VD1201') as valor_ventas;

--FUNCIÓN 6: Función que muestra la dirección del administrador un proveedor por su id
CREATE FUNCTION dirAdmin_por_idProveedor(@id VARCHAR(10))
RETURNS VARCHAR(50)
AS 
BEGIN
	DECLARE @dir VARCHAR(50)
	SET @dir = (SELECT administrador.dire FROM administrador, proveedor WHERE 
					proveedor.id_admin = administrador.id_admin AND proveedor.id_pro = @id)
	RETURN @dir;
END; 

--Llamar a la función
SELECT dbo.dirAdmin_por_idProveedor('P0000002') as direccion;


--FUNCIÓN 7: Función que retorna el total obtenido en ventas
CREATE FUNCTION totalGastado()
RETURNS NUMERIC
AS 
BEGIN
	DECLARE @total NUMERIC
	SET @total = (SELECT SUM(ventas.ing) FROM ventas)
	RETURN @total;
END; 

--Llamar a la función
SELECT dbo.totalVentas() as total;


--FUNCIÓN 8: Función que retorna la cantidad de dinero gastada por un cliente por su id
CREATE FUNCTION totalGastado_porIDCliente(@id VARCHAR(4))
RETURNS DECIMAL(4,2)
AS 
BEGIN
	DECLARE @total DECIMAL(4,2)
	SET @total = (SELECT SUM(cliente_producto.cant * producto.prec) FROM producto, cliente_producto 
	WHERE cliente_producto.id_prod = producto.id_prod AND cliente_producto.id_clien = @id)
	RETURN @total;
END; 


--Llamar a la función
SELECT dbo.totalGastado_porIDCliente('C01') as total;



--FUNCIÓN 9: Función que retorna la fecha de un voucher por la id de este
CREATE FUNCTION fechaVoucher(@id VARCHAR(10))
RETURNS DATE
AS 
BEGIN
	DECLARE @fecha DATE
	SET @fecha = (SELECT voucher.fech FROM voucher WHERE voucher.id_vou = @id)
	RETURN @fecha;
END; 

--Llamar a la función
SELECT dbo.fechaVoucher('V1010') as fecha;



--FUNCIÓN 10: Función que retorna la cantidad de compradores que tuvo un producto
CREATE FUNCTION numCompradoresPorProducto(@idProducto VARCHAR(10))
RETURNS INT
AS 
BEGIN
	DECLARE @cant INT
	SET @cant = (SELECT COUNT(cliente_producto.id_clien) FROM cliente, cliente_producto 
	WHERE cliente_producto.id_clien = cliente.id_clien AND cliente_producto.id_prod = @idProducto)
	RETURN @cant;
END; 

--Llamar a la función

SELECT dbo.numCompradoresPorProducto('PR10') as nroCompradores;
