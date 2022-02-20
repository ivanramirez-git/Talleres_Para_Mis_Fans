let jsieee754 = require('./index.js'); 

// Taller No 1 Analisis del Error
// Punto 5
// Integrantes: Ivan Rene Ramirez, Alejandro

value = '01000001111110100000011010010101';
options = 'double';

test1 = jsieee754.getDecimal(value, options);

value2 = '1.66666666666666';

test2 = jsieee754.getPrecision(value2, options)
console.log();

test3 = jsieee754.getM(2, 3, -1, 2);

test4 = jsieee754.getM(2, 2, -2, 2);

// Result:
console.log('Prueba1: \n' + test1 + '\n');
console.log('Prueba2: \n' + test2 + '\n');
console.log('Prueba3: \n' + test3 + '\n');
console.log('Prueba4: \n' + test4 + '\n');

// Utilizando un sistema de computo algebraico, realizar un programa que genere todos los números de máquina, dados los valores iniciales M(β, t, L, U)
/*
    Solución:
    console.log(jsieee754.getM( *Aqui los parametrso de la funcion M* ));
    Ejemplo:
    console.log(jsieee754.getM( 2, 2, -2, 2 ));
    Resultado:
    [
            -6,    -4,    -3,   -2,
            -1.5,    -1, -0.75, -0.5,
        -0.375, -0.25,     0, 0.25,
        0.375,   0.5,  0.75,    1,
            1.5,     2,     3,    4,
            6
    ]    
*/
