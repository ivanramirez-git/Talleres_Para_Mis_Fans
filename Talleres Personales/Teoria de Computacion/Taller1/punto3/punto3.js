// Expresion para leer string con expresiones aritmeticas simples (Suma y resta de dos numeros positivos)

// Expresion:
expresion = /^([0-9]+([.][0-9]+)?)(([+\-])([0-9]+([.][0-9]+)?))+$/;

// Pruebas: "pruebas3.json"
pruebas = require("../pruebas3.json");

// Resultado:
for (var i = 0; i < pruebas.length; i++) {
    if (expresion.test(pruebas[i])) {
        console.log(pruebas[i] + " es una expresion aritmetica");
    } else {
        console.log(pruebas[i] + " no es una expresion aritmetica");
    }
}