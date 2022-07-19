-- Languaje: SQL Server 2019
--
-- Description:
-- La cooperativa CoopeTaxi desea implementar una base de datos para dar control a los servicios prestados por sus asociados:
-- Los socios son los dueños de taxis de ellos se registra un IdSocio, identificación, Nombre (Nombre Completo, Apellido1, Apellido2), Sexo, FechaNacimiento EstadoCivil, Número Cuenta Bancaria, teléfonos, email. 
-- Los socios inscriben sus automóviles de los cuales se registra, la placa, el modelo, la marca, el año de fabricación, el color, cantidad pasajeros, marchamoActual y poliza de seguros que son indicadores de si/no.
-- Además por cada automóvil, un socio puede registrar de uno a varios choferes de los cuales se debe registrar: IdChofer, identificación, Nombre (Nombre Completo, Apellido1, Apellido2), Sexo, Fecha Nacimiento, Estado Civil, Tipo Licencia, número Licencia, fecha vencimiento licencia, y la foto, teléfono, email.
-- Para poder solicitar un servicio los clientes deben registrarse brindando sus datos personales, identificación, Nombre (Nombre Completo, Apellido1, Apellido2), Sexo, Fecha Nacimiento, teléfono.  
-- El cliente además, puede proveer varias direcciones para que queden registradas de donde van a solicitar servicios. Las direcciones se registran por, provincia, cantón, distrito, dirección exacta.  
-- Por cada servicio solicitado se registra el IdViaje, Fecha, el cliente que lo solicita,  la hora de inicio, el kilometraje, la hora fin, el vehículo, y el chofer. La tarifas por kilómetro están establecidas por ley es un precio de 700 colones para el primer kilómetro y 550 el resto.
-- Se le solicita al cliente que califique el servicio con cantidad de estrellas (1 – 5), y escriba alguna observación sea positiva o negativa.
-- Se requiere un informe por servicio y un informe de viajes para el chofer y los socios.
-- Nombre de la base de datos: CoopeTaxi

USE MASTER
GO
DROP DATABASE IF EXISTS CoopeTaxi;
CREATE DATABASE CoopeTaxi;
USE CoopeTaxi;

-- Tabla de estado civil
DROP TABLE IF EXISTS EstadoCivil;
CREATE TABLE EstadoCivil (
    IdEstadoCivil int NOT NULL IDENTITY(1,1),
    Nombre varchar(50) NOT NULL,
    PRIMARY KEY (IdEstadoCivil)
);

-- Datos de estado civil
INSERT INTO EstadoCivil (Nombre) VALUES ('Soltero');
INSERT INTO EstadoCivil (Nombre) VALUES ('Casado');
INSERT INTO EstadoCivil (Nombre) VALUES ('Divorciado');
INSERT INTO EstadoCivil (Nombre) VALUES ('Viudo');

-- Tabla telefonos
DROP TABLE IF EXISTS Telefonos;
CREATE TABLE Telefonos (
    IdTelefono int NOT NULL IDENTITY(1,1),
    Numero varchar(10) NOT NULL,
    PRIMARY KEY (IdTelefono)
);

-- Datos de telefonos
INSERT INTO Telefonos (Numero) VALUES ('70496185');
INSERT INTO Telefonos (Numero) VALUES ('70496186');
INSERT INTO Telefonos (Numero) VALUES ('70496187');
INSERT INTO Telefonos (Numero) VALUES ('70496188');
INSERT INTO Telefonos (Numero) VALUES ('70496189');
INSERT INTO Telefonos (Numero) VALUES ('70496190');
INSERT INTO Telefonos (Numero) VALUES ('70496191');
INSERT INTO Telefonos (Numero) VALUES ('70496192');
INSERT INTO Telefonos (Numero) VALUES ('70496193');
INSERT INTO Telefonos (Numero) VALUES ('70496194');
INSERT INTO Telefonos (Numero) VALUES ('70496195');
INSERT INTO Telefonos (Numero) VALUES ('70496196');
INSERT INTO Telefonos (Numero) VALUES ('70496197');
INSERT INTO Telefonos (Numero) VALUES ('70496198');
INSERT INTO Telefonos (Numero) VALUES ('70496199');
INSERT INTO Telefonos (Numero) VALUES ('70496200');
INSERT INTO Telefonos (Numero) VALUES ('70496201');
INSERT INTO Telefonos (Numero) VALUES ('70496202');
INSERT INTO Telefonos (Numero) VALUES ('70496203');
INSERT INTO Telefonos (Numero) VALUES ('70496204');
INSERT INTO Telefonos (Numero) VALUES ('70496205');
INSERT INTO Telefonos (Numero) VALUES ('70496206');
INSERT INTO Telefonos (Numero) VALUES ('70496207');
INSERT INTO Telefonos (Numero) VALUES ('70496208');
INSERT INTO Telefonos (Numero) VALUES ('70496209');
INSERT INTO Telefonos (Numero) VALUES ('70496210');

-- Los socios son los dueños de taxis de ellos se registra un IdSocio, identificación, Nombre (Nombre Completo, Apellido1, Apellido2), Sexo, FechaNacimiento EstadoCivil, Número Cuenta Bancaria, teléfonos, email. 
DROP TABLE IF EXISTS Socios;
CREATE TABLE dbo.Socios (
    IdSocio int NOT NULL IDENTITY(1,1), -- Id del socio (autoincremental)
    Identificacion varchar(20) NOT NULL, -- Identificación del socio
    Nombre varchar(50) NOT NULL, -- Nombre del socio
    Apellido1 varchar(50) NOT NULL, -- Apellido1 del socio
    Apellido2 varchar(50) NOT NULL, -- Apellido2 del socio
    Sexo varchar(1) NOT NULL, -- Sexo del socio, M o F
    FechaNacimiento date NOT NULL, -- Fecha de nacimiento del socio
    EstadoCivil int NOT NULL, -- Id del estado civil del socio
    NumeroCuentaBancaria varchar(20) NOT NULL, -- Número de cuenta bancaria del socio
    IdTelefono int NOT NULL, -- Id del teléfono del socio
    IdTelefono2 int NOT NULL, -- Id del teléfono 2 del socio
    Email varchar(50) NOT NULL, -- Email del socio
    CONSTRAINT PK_Socios PRIMARY KEY (IdSocio),
    CONSTRAINT FK_Socios_EstadoCivil FOREIGN KEY (EstadoCivil) REFERENCES EstadoCivil(IdEstadoCivil),
    CONSTRAINT FK_Socios_Telefonos FOREIGN KEY (IdTelefono) REFERENCES Telefonos(IdTelefono),
    CONSTRAINT FK_Socios_Telefonos2 FOREIGN KEY (IdTelefono2) REFERENCES Telefonos(IdTelefono)
);

-- Datos de los socios
INSERT INTO dbo.Socios (Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, EstadoCivil, NumeroCuentaBancaria, IdTelefono, IdTelefono2, Email)
VALUES ('12345678', 'Juan', 'Pérez', 'Pérez', 'M', '01/01/2000', 1, '123456789', 1, 2, 'juan@mail.com');
INSERT INTO dbo.Socios (Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, EstadoCivil, NumeroCuentaBancaria, IdTelefono, IdTelefono2, Email)
VALUES ('22345678', 'Pedro', 'Pablo', 'Emilio', 'M', '02/02/1998', 2, '223456789', 3, 4, 'pedro@mail.com');
INSERT INTO dbo.Socios (Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, EstadoCivil, NumeroCuentaBancaria, IdTelefono, IdTelefono2, Email)
VALUES ('32345678', 'Alejandra', 'Gonzales', 'Gonzales', 'F', '03/03/1997', 3, '323456789', 5, 6, 'alejandra@mail.com');


-- Los socios inscriben sus automóviles de los cuales se registra, la placa, el modelo, la marca, el año de fabricación, el color, cantidad pasajeros, marchamoActual y poliza de seguros que son indicadores de si/no.
DROP TABLE IF EXISTS Automoviles;
CREATE TABLE dbo.Automoviles (
    IdAutomovil int NOT NULL IDENTITY(1,1), -- Id del automóvil (autoincremental)
    IdSocio int NOT NULL, -- Id del socio que lo registra
    Placa varchar(20) NOT NULL, -- Placa del automóvil
    Modelo varchar(20) NOT NULL, -- Modelo del automóvil
    Marca varchar(20) NOT NULL, -- Marca del automóvil
    AnioFabricacion int NOT NULL, -- Año de fabricación del automóvil
    Color varchar(20) NOT NULL, -- Color del automóvil
    CantidadPasajeros int NOT NULL, -- Cantidad de pasajeros del automóvil
    MarchamoActual int NOT NULL, -- Marchamo actual del automóvil
    PolizaSeguros int NOT NULL, -- Poliza de seguros del automóvil
    CONSTRAINT PK_Automoviles PRIMARY KEY (IdAutomovil),
    CONSTRAINT FK_Automoviles_Socios FOREIGN KEY (IdSocio) REFERENCES dbo.Socios (IdSocio)
);


-- Datos de los automóviles
INSERT INTO dbo.Automoviles (IdSocio, Placa, Modelo, Marca, AnioFabricacion, Color, CantidadPasajeros, MarchamoActual, PolizaSeguros)
VALUES (1, 'ABC123', 'Toyota', 'Toyota', 2000, 'Rojo', 5, 1, 1);
INSERT INTO dbo.Automoviles (IdSocio, Placa, Modelo, Marca, AnioFabricacion, Color, CantidadPasajeros, MarchamoActual, PolizaSeguros)
VALUES (1, 'DEF456', 'Nissan', 'Nissan', 2001, 'Azul', 4, 1, 1);
INSERT INTO dbo.Automoviles (IdSocio, Placa, Modelo, Marca, AnioFabricacion, Color, CantidadPasajeros, MarchamoActual, PolizaSeguros)
VALUES (2, 'GHI789', 'Honda', 'Honda', 2002, 'Gris', 5, 1, 1);
INSERT INTO dbo.Automoviles (IdSocio, Placa, Modelo, Marca, AnioFabricacion, Color, CantidadPasajeros, MarchamoActual, PolizaSeguros)
VALUES (2, 'JKL012', 'Chevrolet', 'Chevrolet', 2003, 'Blanco', 4, 1, 1);
INSERT INTO dbo.Automoviles (IdSocio, Placa, Modelo, Marca, AnioFabricacion, Color, CantidadPasajeros, MarchamoActual, PolizaSeguros)
VALUES (3, 'MNO345', 'Fiat', 'Fiat', 2004, 'Blanco', 5, 1, 1);
INSERT INTO dbo.Automoviles (IdSocio, Placa, Modelo, Marca, AnioFabricacion, Color, CantidadPasajeros, MarchamoActual, PolizaSeguros)
VALUES (3, 'PQR678', 'Ford', 'Ford', 2005, 'Rojo', 4, 1, 1);



-- Además por cada automóvil, un socio puede registrar de uno a varios choferes de los cuales se debe registrar: IdChofer, identificación, Nombre (Nombre Completo, Apellido1, Apellido2), Sexo, Fecha Nacimiento, Estado Civil, Tipo Licencia, número Licencia, fecha vencimiento licencia, y la foto, teléfono, email.
DROP TABLE IF EXISTS Choferes;
CREATE TABLE dbo.Choferes (
    IdChofer int NOT NULL IDENTITY(1,1), -- Id del chofer (autoincremental)
    IdAutomovil int NOT NULL, -- Id del automóvil que lo registra
    Identificacion varchar(20) NOT NULL, -- Identificación del chofer
    Nombre varchar(50) NOT NULL, -- Nombre completo del chofer
    Apellido1 varchar(20) NOT NULL, -- Primer apellido del chofer
    Apellido2 varchar(20) NOT NULL, -- Segundo apellido del chofer
    Sexo varchar(1) NOT NULL, -- Sexo del chofer
    FechaNacimiento datetime NOT NULL, -- Fecha de nacimiento del chofer
    EstadoCivil int NOT NULL, -- Estado civil del chofer
    TipoLicencia varchar(20) NOT NULL, -- Tipo de licencia del chofer
    NumeroLicencia varchar(20) NOT NULL, -- Número de licencia del chofer
    FechaVencimientoLicencia datetime NOT NULL, -- Fecha de vencimiento de la licencia del chofer
    Foto varchar(50) NOT NULL, -- Foto del chofer
    IdTelefono int NOT NULL, -- Id del teléfono del chofer
    Email varchar(50) NOT NULL, -- Email del chofer
    CONSTRAINT PK_Choferes PRIMARY KEY (IdChofer),
    CONSTRAINT FK_Choferes_Automoviles FOREIGN KEY (IdAutomovil) REFERENCES dbo.Automoviles (IdAutomovil),
    CONSTRAINT FK_Choferes_Telefonos FOREIGN KEY (IdTelefono) REFERENCES dbo.Telefonos (IdTelefono)
);


-- Datos de los choferes
INSERT INTO dbo.Choferes (IdAutomovil, Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, EstadoCivil, TipoLicencia, NumeroLicencia, FechaVencimientoLicencia, Foto, IdTelefono, Email)
VALUES (1, '12345670', 'Lida', 'Perez', 'Bella', 'F', '01/01/2000', 1, 'A', '11345678', '01/01/2000', 'foto1.jpg', 7, 'lida@mail.com');
INSERT INTO dbo.Choferes (IdAutomovil, Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, EstadoCivil, TipoLicencia, NumeroLicencia, FechaVencimientoLicencia, Foto, IdTelefono, Email)
VALUES (1, '23456780', 'Ivan', 'Ramirez', 'Sabio', 'M', '12/21/1998', 2, 'A', '12345678', '01/01/2000', 'foto2.jpg', 8, 'ivan@mail.com');
INSERT INTO dbo.Choferes (IdAutomovil, Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, EstadoCivil, TipoLicencia, NumeroLicencia, FechaVencimientoLicencia, Foto, IdTelefono, Email)
VALUES (2, '34567890', 'Emiliano', 'Rodriguez', 'Falso', 'M', '01/01/2001', 3, 'A', '12345678', '01/01/2000', 'foto3.jpg', 9, 'emiliano@mail.com');
INSERT INTO dbo.Choferes (IdAutomovil, Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, EstadoCivil, TipoLicencia, NumeroLicencia, FechaVencimientoLicencia, Foto, IdTelefono, Email)
VALUES (3, '45678901', 'Miguel', 'Alejando', 'Hurtado', 'M', '01/01/2002', 4, 'A', '12345678', '01/01/2000', 'foto4.jpg', 10, 'miguel@mail.com');


-- Para poder solicitar un servicio los clientes deben registrarse brindando sus datos personales, identificación, Nombre (Nombre Completo, Apellido1, Apellido2), Sexo, Fecha Nacimiento, teléfono. 
DROP TABLE IF EXISTS Clientes;
CREATE TABLE dbo.Clientes (
    IdCliente int NOT NULL IDENTITY(1,1), -- Id del cliente (autoincremental)
    Identificacion varchar(20) NOT NULL, -- Identificación del cliente
    Nombre varchar(50) NOT NULL, -- Nombre completo del cliente
    Apellido1 varchar(20) NOT NULL, -- Primer apellido del cliente
    Apellido2 varchar(20) NOT NULL, -- Segundo apellido del cliente
    Sexo varchar(1) NOT NULL, -- Sexo del cliente
    FechaNacimiento datetime NOT NULL, -- Fecha de nacimiento del cliente
    IdTelefono int NOT NULL, -- Id del teléfono del cliente
    CONSTRAINT PK_Clientes PRIMARY KEY (IdCliente),
    CONSTRAINT FK_Clientes_Telefonos FOREIGN KEY (IdTelefono) REFERENCES dbo.Telefonos (IdTelefono)
);


-- Datos de los clientes
INSERT INTO dbo.Clientes (Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, IdTelefono)
VALUES ('56789012', 'Brandon', 'Perez', 'Sandoval', 'M', '04/04/2004', 11);
INSERT INTO dbo.Clientes (Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, IdTelefono)
VALUES ('67890123', 'Alexandra', 'Martinez', 'Gonzalez', 'F', '12/27/1997', 12);
INSERT INTO dbo.Clientes (Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, IdTelefono)
VALUES ('78901234', 'Javer', 'Gonzalez', 'Gonzalez', 'M', '01/01/2001', 13);
INSERT INTO dbo.Clientes (Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, IdTelefono)
VALUES ('89012345', 'Kimberly', 'Muñoz', 'Muñoz', 'F', '01/01/2004', 14);
INSERT INTO dbo.Clientes (Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, IdTelefono)
VALUES ('90123456', 'Maricela', 'Gonzalez', 'Ramirez', 'F', '01/01/2002', 15);
INSERT INTO dbo.Clientes (Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, IdTelefono)
VALUES ('01234567', 'Fabiola', 'Ramirez', 'Gonzalez', 'F', '01/01/2001', 16);
INSERT INTO dbo.Clientes (Identificacion, Nombre, Apellido1, Apellido2, Sexo, FechaNacimiento, IdTelefono)
VALUES ('12345678', 'Fabiana', 'Gonzalez', 'Martinez', 'F', '01/01/2001', 17);


-- Datos de las provincias
DROP TABLE IF EXISTS Provincia;
CREATE TABLE dbo.Provincia (
    IdProvincia int NOT NULL IDENTITY(1,1), -- Id de la provincia (autoincremental)
    Nombre varchar(50) NOT NULL, -- Nombre de la provincia
    CONSTRAINT PK_Provincia PRIMARY KEY (IdProvincia)
);

-- Datos de las cantones
DROP TABLE IF EXISTS Canton;
CREATE TABLE dbo.Canton (
    IdCanton int NOT NULL IDENTITY(1,1), -- Id del cantón (autoincremental)
    Nombre varchar(50) NOT NULL, -- Nombre del cantón
    IdProvincia int NOT NULL, -- Id de la provincia a la que pertenece
    CONSTRAINT PK_Canton PRIMARY KEY (IdCanton),
    CONSTRAINT FK_Canton_Provincia FOREIGN KEY (IdProvincia) REFERENCES dbo.Provincia (IdProvincia)
);

-- Datos de los distritos
DROP TABLE IF EXISTS Distrito;
CREATE TABLE dbo.Distrito (
    IdDistrito int NOT NULL IDENTITY(1,1), -- Id del distrito (autoincremental)
    Nombre varchar(50) NOT NULL, -- Nombre del distrito
    IdCanton int NOT NULL, -- Id del cantón al que pertenece
    CONSTRAINT PK_Distrito PRIMARY KEY (IdDistrito),
    CONSTRAINT FK_Distrito_Canton FOREIGN KEY (IdCanton) REFERENCES dbo.Canton (IdCanton)
);

--  El cliente además, puede proveer varias direcciones para que queden registradas de donde van a solicitar servicios. Las direcciones se registran por, provincia, cantón, distrito, dirección exacta.  
DROP TABLE IF EXISTS Direcciones;
CREATE TABLE dbo.Direcciones (
    IdDireccion int NOT NULL IDENTITY(1,1), -- Id de la dirección (autoincremental)
    IdCliente int NOT NULL, -- Id del cliente al que pertenece
    IdDistrito int NOT NULL, -- Id del distrito a la que pertenece
    DireccionExacta varchar(50) NOT NULL, -- Dirección exacta
    CONSTRAINT PK_Direcciones PRIMARY KEY (IdDireccion),
    CONSTRAINT FK_Direcciones_Cliente FOREIGN KEY (IdCliente) REFERENCES dbo.Clientes (IdCliente),
    CONSTRAINT FK_Direcciones_Distrito FOREIGN KEY (IdDistrito) REFERENCES dbo.Distrito (IdDistrito)
);


-- Provincias de Costa Rica:
--Alajuela
--Cartago 
--Guanacaste
--Heredia
--Limón 
--Puntarenas
--San José
INSERT INTO dbo.Provincia (Nombre)
VALUES ('Alajuela');

-- Cantones de Alajuela:
-- Alajuela --
-- Atenas
-- Grecia
-- Guatuso
-- Los Chiles
-- Naranjo
-- Orotina
-- Palmares
-- Rio Cuarto
-- San Carlos
-- San Mateo
-- San Ramón
-- Upala
-- Valverde Vega
-- Zarcero
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Alajuela', 1);

-- Distritos de Alajuela:
-- Upala (Centro) 
-- Aguas Claras
-- San José
-- Bijagua
-- Delicias
-- Dos Ríos
-- Yolillal
-- Canalete
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Upala (Centro)', 1);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Aguas Claras', 1);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('San José', 1);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Bijagua', 1);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Delicias', 1);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Dos Ríos', 1);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Yolillal', 1);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Canalete', 1);

INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Atenas', 1);
-- Distritos de Atenas:
-- Atenas
-- Jesús
-- Mercedes
-- San Isidro
-- Concepción
-- San José
-- Santa Eulalia
-- Escobal
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Atenas', 2);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Jesús', 2);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Mercedes', 2);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('San Isidro', 2);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Concepción', 2);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('San José', 2);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Santa Eulalia', 2);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Escobal', 2);

INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Grecia', 1);
-- Distritos de Grecia:
-- Bolívar
-- Grecia
-- Puente de Piedra
-- San Isidro
-- San José
-- San Roque
-- Tacares
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Bolívar', 3);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Grecia', 3);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Puente de Piedra', 3);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('San Isidro', 3);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('San José', 3);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('San Roque', 3);
INSERT INTO dbo.Distrito (Nombre, IdCanton)
VALUES ('Tacares', 3);

INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Guatuso', 1);
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Los Chiles', 1);
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Naranjo', 1);
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Orotina', 1);
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Palmares', 1);
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Rio Cuarto', 1);
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('San Carlos', 1);
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('San Mateo', 1);
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('San Ramón', 1);
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Upala', 1);
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Valverde Vega', 1);
INSERT INTO dbo.Canton (Nombre, IdProvincia)
VALUES ('Zarcero', 1);

INSERT INTO dbo.Provincia (Nombre)
VALUES ('Cartago');
INSERT INTO dbo.Provincia (Nombre)
VALUES ('Liberia');
INSERT INTO dbo.Provincia (Nombre)
VALUES ('Heredia');
INSERT INTO dbo.Provincia (Nombre)
VALUES ('Puerto Limon');
INSERT INTO dbo.Provincia (Nombre)
VALUES ('Puntarenas');
INSERT INTO dbo.Provincia (Nombre)
VALUES ('San Jose');

-- Datos de las direcciones
INSERT INTO dbo.Direcciones (IdCliente, IdDistrito, DireccionExacta)
VALUES (1, 1, 'Calle 1');
INSERT INTO dbo.Direcciones (IdCliente, IdDistrito, DireccionExacta)
VALUES (1, 2, 'Calle 2');
INSERT INTO dbo.Direcciones (IdCliente, IdDistrito, DireccionExacta)
VALUES (2, 3, 'Calle 3');
INSERT INTO dbo.Direcciones (IdCliente, IdDistrito, DireccionExacta)
VALUES (3, 4, 'Calle 4');
INSERT INTO dbo.Direcciones (IdCliente, IdDistrito, DireccionExacta)
VALUES (4, 7, 'Calle 5');
INSERT INTO dbo.Direcciones (IdCliente, IdDistrito, DireccionExacta)
VALUES (5, 9, 'Calle 6');
INSERT INTO dbo.Direcciones (IdCliente, IdDistrito, DireccionExacta)
VALUES (6, 15, 'Calle 7');
INSERT INTO dbo.Direcciones (IdCliente, IdDistrito, DireccionExacta)
VALUES (7, 17, 'Calle 8');
INSERT INTO dbo.Direcciones (IdCliente, IdDistrito, DireccionExacta)
VALUES (7, 21, 'Calle 9');





-- Por cada servicio solicitado se registra el IdViaje, Fecha, el cliente que lo solicita,  la hora de inicio, el kilometraje, la hora fin, el vehículo, y el chofer. La tarifas por kilómetro están establecidas por ley es un precio de 700 colones para el primer kilómetro y 550 el resto.
DROP TABLE IF EXISTS Viajes;
CREATE TABLE dbo.Viajes (
    IdViaje int NOT NULL IDENTITY(1,1), -- Id del viaje (autoincremental)
    Fecha datetime NOT NULL, -- Fecha del viaje
    IdCliente int NOT NULL, -- Id del cliente que solicita el viaje
    HoraInicio datetime NOT NULL, -- Hora de inicio del viaje
    Kilometraje int NOT NULL, -- Kilometraje del viaje
    HoraFin datetime NOT NULL, -- Hora de fin del viaje
    IdAutomovil int NOT NULL, -- Id del automóvil que se utiliza en el viaje
    IdChofer int NOT NULL, -- Id del chofer que se utiliza en el viaje
    IdDireccion int NOT NULL, -- Id de la dirección donde se realiza el viaje
    CONSTRAINT PK_Viajes PRIMARY KEY (IdViaje),
    CONSTRAINT FK_Viajes_Clientes FOREIGN KEY (IdCliente) REFERENCES dbo.Clientes (IdCliente),
    CONSTRAINT FK_Viajes_Automoviles FOREIGN KEY (IdAutomovil) REFERENCES dbo.Automoviles (IdAutomovil),
    CONSTRAINT FK_Viajes_Choferes FOREIGN KEY (IdChofer) REFERENCES dbo.Choferes (IdChofer),
    CONSTRAINT FK_Viajes_Direcciones FOREIGN KEY (IdDireccion) REFERENCES dbo.Direcciones (IdDireccion)
);


-- Datos de los viajes
INSERT INTO dbo.Viajes (Fecha, IdCliente, HoraInicio, Kilometraje, HoraFin, IdAutomovil, IdChofer, IdDireccion)
VALUES ('2018-01-01', 1, '08:00:00', 4, '08:00:00', 1, 1, 1);
INSERT INTO dbo.Viajes (Fecha, IdCliente, HoraInicio, Kilometraje, HoraFin, IdAutomovil, IdChofer, IdDireccion)
VALUES ('01/02/2021', 2, '02:00:00', 22, '04:00:00', 2, 3, 3);
INSERT INTO dbo.Viajes (Fecha, IdCliente, HoraInicio, Kilometraje, HoraFin, IdAutomovil, IdChofer, IdDireccion)
VALUES ('01/03/2021', 3, '03:00:00', 3, '05:00:00', 3, 4, 4);
INSERT INTO dbo.Viajes (Fecha, IdCliente, HoraInicio, Kilometraje, HoraFin, IdAutomovil, IdChofer, IdDireccion)
VALUES ('01/04/2021', 4, '04:00:00', 4, '06:00:00', 1, 2, 5);
INSERT INTO dbo.Viajes (Fecha, IdCliente, HoraInicio, Kilometraje, HoraFin, IdAutomovil, IdChofer, IdDireccion)
VALUES ('01/05/2021', 5, '05:00:00', 12, '07:00:00', 2, 3, 6);
INSERT INTO dbo.Viajes (Fecha, IdCliente, HoraInicio, Kilometraje, HoraFin, IdAutomovil, IdChofer, IdDireccion)
VALUES ('01/06/2021', 6, '06:00:00', 6, '08:00:00', 3, 4, 7);
INSERT INTO dbo.Viajes (Fecha, IdCliente, HoraInicio, Kilometraje, HoraFin, IdAutomovil, IdChofer, IdDireccion)
VALUES ('01/07/2021', 7, '07:00:00', 10, '09:00:00', 1, 2, 8);
INSERT INTO dbo.Viajes (Fecha, IdCliente, HoraInicio, Kilometraje, HoraFin, IdAutomovil, IdChofer, IdDireccion)
VALUES ('01/08/2021', 7, '08:00:00', 8, '10:00:00', 2, 3, 9);




-- Se le solicita al cliente que califique el servicio con cantidad de estrellas (1 – 5), y escriba alguna observación sea positiva o negativa.
DROP TABLE IF EXISTS Calificaciones;
CREATE TABLE dbo.Calificaciones (
    IdCalificacion int NOT NULL IDENTITY(1,1), -- Id de la calificación (autoincremental)
    IdViaje int NOT NULL, -- Id del viaje que se califica
    Estrellas int NOT NULL, -- Cantidad de estrellas que se le da al cliente
    Observaciones varchar(200) NOT NULL, -- Observaciones del cliente
    CONSTRAINT PK_Calificaciones PRIMARY KEY (IdCalificacion),
    CONSTRAINT FK_Calificaciones_Viajes FOREIGN KEY (IdViaje) REFERENCES dbo.Viajes (IdViaje)
);

-- Datos de las calificaciones
INSERT INTO dbo.Calificaciones (IdViaje, Estrellas, Observaciones)
VALUES (1, 5, 'Excelente servicio');
INSERT INTO dbo.Calificaciones (IdViaje, Estrellas, Observaciones)
VALUES (2, 4, 'Muy buen servicio');
INSERT INTO dbo.Calificaciones (IdViaje, Estrellas, Observaciones)
VALUES (3, 3, 'Buen servicio');
INSERT INTO dbo.Calificaciones (IdViaje, Estrellas, Observaciones)
VALUES (4, 2, 'Regular servicio');
INSERT INTO dbo.Calificaciones (IdViaje, Estrellas, Observaciones)
VALUES (5, 1, 'Malo servicio');
INSERT INTO dbo.Calificaciones (IdViaje, Estrellas, Observaciones)
VALUES (6, 5, 'Excelente servicio');
INSERT INTO dbo.Calificaciones (IdViaje, Estrellas, Observaciones)
VALUES (7, 4, 'Muy buen servicio');
INSERT INTO dbo.Calificaciones (IdViaje, Estrellas, Observaciones)
VALUES (8, 3, 'Buen servicio');


-- Se requiere un informe por servicio y un informe de viajes para el chofer y los socios.
-- Informe por servicio: Id Viaje, Fecha, Nombre Cliente, Hora Inicio, Kilometraje, Hora Fin, Id Automovil, Nombre Chofer, Estrellas, Observaciones, Calle, Número, Distrito, Canton, Provincia
SELECT dbo.Viajes.IdViaje, dbo.Viajes.Fecha, dbo.Clientes.Nombre AS NombreCliente, dbo.Viajes.HoraInicio, dbo.Viajes.Kilometraje, dbo.Viajes.HoraFin, dbo.Automoviles.IdAutomovil, dbo.Choferes.Nombre AS NombreChofer, dbo.Calificaciones.Estrellas, dbo.Calificaciones.Observaciones, dbo.Direcciones.DireccionExacta, dbo.Distrito.Nombre AS NombreDistrito, dbo.Canton.Nombre AS NombreCanton, dbo.Provincia.Nombre AS NombreProvincia
FROM dbo.Viajes
INNER JOIN dbo.Clientes ON dbo.Viajes.IdCliente = dbo.Clientes.IdCliente
INNER JOIN dbo.Automoviles ON dbo.Viajes.IdAutomovil = dbo.Automoviles.IdAutomovil
INNER JOIN dbo.Choferes ON dbo.Viajes.IdChofer = dbo.Choferes.IdChofer
INNER JOIN dbo.Calificaciones ON dbo.Viajes.IdViaje = dbo.Calificaciones.IdViaje
INNER JOIN dbo.Direcciones ON dbo.Viajes.IdDireccion = dbo.Direcciones.IdDireccion
INNER JOIN dbo.Distrito ON dbo.Direcciones.IdDistrito = dbo.Distrito.IdDistrito
INNER JOIN dbo.Canton ON dbo.Distrito.IdCanton = dbo.Canton.IdCanton
INNER JOIN dbo.Provincia ON dbo.Canton.IdProvincia = dbo.Provincia.IdProvincia
ORDER BY dbo.Viajes.IdViaje;


-- Informe de viajes: Nombre Chofer, Cantidad de viajes, Total de kilometros
SELECT dbo.Choferes.Nombre, COUNT(dbo.Viajes.IdViaje) AS CantidadViajes, SUM(dbo.Viajes.Kilometraje) AS TotalKilometros
FROM dbo.Viajes
INNER JOIN dbo.Choferes ON dbo.Viajes.IdChofer = dbo.Choferes.IdChofer
GROUP BY dbo.Choferes.Nombre
ORDER BY dbo.Choferes.Nombre;