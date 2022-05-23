create database db_demo;

use db_demo;

create table cuentas (
    cuentaId int primary key auto_increment,
    pelicula varchar(100),
    precio double,
    plataforma varchar(100),
    fvencimiento date,
    cuentasdisponibles int
);

select * from cuentas;

