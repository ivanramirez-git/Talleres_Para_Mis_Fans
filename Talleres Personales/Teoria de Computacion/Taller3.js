// Aplicacion de Expresiones Regulares

// 1. Correo electronico
function punto1() {

    correoRegExp = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9]+(.[a-zA-Z])+$/;

    pruebas = [
        'ivanrene10@gmail.com',
        'm.m.m@glp.co.co.',
        'mp3 @gmail.com',
        'scudo-vamos@com.co'
    ]

    // Validar
    resultado = pruebas.map(function (valor) {
        return correoRegExp.test(valor);
    });

    // Imprimir resultado
    for (var i = 0; i < resultado.length; i++) {
        console.log(i + ' (' + resultado[i] + ') ' + ': ' + pruebas[i] );
    }
}

// 2. Ruta de archivos en linux
function punto2() {
    
    rutaRegExp = /^[a-zA-Z0-9/._-]+(\/[a-zA-Z0-9]+)+(\.[a-zA-Z0-9]+)*$/;

    pruebas = [
        'home/ivanrene/archivo.txt',
        '../src%archivo.txt',
        'hola/archivo.txt',
        '/ruta/archivo.txt',
        'ruta/archivo',
        'ruta/archivo.txt.txt',
        '/a/b/c.mp3'
    ]

    // Validar
    resultado = pruebas.map(function (valor) {
        return rutaRegExp.test(valor);
    });

    // Imprimir resultado
    for (var i = 0; i < resultado.length; i++) {
        console.log(i + ' (' + resultado[i] + ') ' + ': ' + pruebas[i] );
    }
}

// 3. Rutas URL
function punto3() {

    urlRegExp = /^?:http|https::\/\/[a-zA-Z0-9/._-]+(\/[a-zA-Z0-9]+)+(\.[a-zA-Z0-9]+)+$/;

    pruebas = [
        'http://www.google.com',
        'https://www.google.com',
        'https://www.google.com/',
        'https://www.google.com/hola',
        'https://www.google.com/hola/',
        'https://www.google.com.co',
        'https://www.google.com.co/',
        'https://www.google.com.co/hola',
        'https://www.google.com.co/hola/',
        'https://www.google.com.co/hola/hola',
        'http://draw.io',
        'htpt://www.google.com',
        'www.google.com',
        'https://w.wwgooglecom',
        'https://wwwgooglecom',
        'https://www.bing.com/search?q=regx101&cvid=00a99f90349c42798db774d3d938389c&aqs=edge.1.69i57j69i59j69i60l2j69i61l2.2649j0j4&pglt=43&FORM=ANAB01&PC=U531'
    ]

    // Validar
    resultado = pruebas.map(function (valor) {
        return urlRegExp.test(valor);
    });

    // Imprimir resultado
    for (var i = 0; i < resultado.length; i++) {
        console.log(i + ' (' + resultado[i] + ') ' + ': ' + pruebas[i] );
    }

}

punto3();
