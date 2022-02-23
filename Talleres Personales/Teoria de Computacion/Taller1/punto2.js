// Expresion para leer string con numeros decimales

// Expresion:
expresion = /^[0-9]+([.][0-9]+)?$/;

// Pruebas:
pruebas = [
    "1.2",
    "1.2.3",
    "3.141592"
]

// Resultado:
for (var i = 0; i < pruebas.length; i++) {
    if (expresion.test(pruebas[i])) {
        console.log(pruebas[i] + " es un numero decimal");
    } else {
        console.log(pruebas[i] + " no es un numero decimal");
    }
}