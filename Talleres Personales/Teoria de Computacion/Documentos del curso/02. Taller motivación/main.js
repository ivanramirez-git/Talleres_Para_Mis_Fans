// Escribir un método en Java (o el lenguaje de su preferencia) que compruebe si una dirección de correo electrónico es válida o no. Para probar si el método funciona bien, escriba un programa que utilice dicho método para comprobar al menos 10 direcciones de correo diferentes.
// Una dirección de correo electrónico está compuesta por 3 partes:
// o	Nombre
// o	@
// o	Dominio
// •	El nombre cumple las siguientes reglas:
// o	Contiene sólo letras
// o	Las letras pueden ser mayúsculas o minúsculas
// •	El dominio cumple las siguientes reglas:
// o	Las letras pueden ser mayúsculas o minúsculas
// o	Contiene solo letras separadas por puntos
// o	Al menos debe existir un punto
// o	No debe haber dos o más puntos adyacentes
// o	No debe terminar en punto
// o	No debe comenzar en punto
// o	No debe contener números
// o	No es necesario validar que el dominio corresponda a una dirección de Internet real
// Por ejemplo, el string Madfjkq@hotakld.dfq.eqe.de debe ser aceptado como válido. Los strings Medfa.fadd o jdfkla@fadfa deben ser rechazados. 
// 2.	Modifique el programa para que permita:
// 	El uso de puntos '.', underscores '_' y números en el nombre del correo electrónico. Los nombres deben comenzar siempre por una letra.
// 	El uso de números en el dominio. No es necesario que el dominio comience con una letra.




// micorreo@aaaa.bbbb.ccc       Correcto
// micorreo@aaaa.bbbb.ccc.		Incorrecto
// micorreo@.aaaa.bbbb.ccc		Incorrecto
// micorreo@@aaaa.bbbb.ccc		Incorrecto
// micorreo@aaaa..bbbb.ccc		Incorrecto
// micorreo@					Incorrecto
// @aaa.bbb.ccc					Incorrecto


function validateEmail(email) {
    var re = /^[A-Za-z0-9._%+-]+@[A-Za-z0-9-]+(?:\.[A-Za-z0-9-]+)*$/;
    return re.test(email);
}


const emails = [
    'micorreo@aaaa.bbbb.ccc',
    'micorreo@aaaa.bbbb.ccc.',
    'micorreo@.aaaa.bbbb.ccc',
    'micorreo@@aaaa.bbbb.ccc',
    'micorreo@aaaa..bbbb.ccc',
    'micorreo@',
    '@aaa.bbb.ccc',
    'ivanrene10@gmail.com',
    'ivan_ramirez@javeriana.edu.co'
]

emails.forEach(email => {
    console.log(`${email} ${validateEmail(email) ? 'Correcto' : 'Incorrecto'}`);
});
