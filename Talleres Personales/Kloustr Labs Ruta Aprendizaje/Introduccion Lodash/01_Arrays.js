// Se requiere el paquete de lodash para poder utilizar sus funciones
const _ = require('lodash');

// Ejercicios con arrays
// 1. Meses del año
const meses = ['Enero', 'Febrero', 'Marzo', 'Abril', 'Mayo', 'Junio', 'Julio', 'Agosto', 'Septiembre', 'Octubre', 'Noviembre', 'Diciembre'];

// Ordenar el array de meses por tamaño de nombre.
const mesesOrdenados = _.sortBy(meses, 'length');

// Ordena por orden alfabético
const mesesOrdenados2 = _.sortBy(meses);

// Invertir el orden del array de meses.
const mesesInvertidos = _.reverse(meses);

// Añadimos un nuevo mes al array de meses.
const mesesNuevos = _.concat(meses, 'Septiembre');

// Eliminar elementos duplicados del array de meses.
const mesesSinDuplicados = _.uniq(meses);

// Imprimir los resultados
console.log(
    'Meses del año:', meses,
    '\nMeses ordenados por tamaño de nombre:', mesesOrdenados,
    '\nMeses ordenados por orden alfabético:', mesesOrdenados2,
    '\nMeses invertidos:', mesesInvertidos,
    '\nMeses nuevos:', mesesNuevos,
    '\nMeses sin duplicados:', mesesSinDuplicados
);