/*
// Lista con datos de personas
let people = [
    {
        name: 'Arnold',
        specialization: 'C++',
    },
    {
        name: 'Phil',
        specialization: 'Python',
    },
    {
        name: 'Percy',
        specialization: 'JS',
    },
];

// Encontrar la persona con especialización C++
let folksDoingCpp = people.filter((person) => person.specialization == 'C++');

// Convertir la nueva persona a JS!
for (person of folksDoingCpp) {
    person.specialization = 'JS';
}

// Imprimir la nueva persona
console.log(
    "Nueva persona (modificada): ", folksDoingCpp,
    // Imprimir la lista de personas sin modificar
    "\nLista de personas (sin modificar): ", people
);
*/
/*
[
  { name: 'Arnold', specialization: 'JS' },
  { name: 'Phil', specialization: 'Python' },
  { name: 'Percy', specialization: 'JS' }
]
*/

// Notese que lo unico modificado es la nueva especialización de Arnold, en una variable aparte.
// El array original no se modifica, pero al imprimir el array original, se muestra la nueva especialización de Arnold.
// Esto es debido a que JavaScript asigna una referencia a la variable, en vez de copiar el valor.
// Esto es lo que se conoce como "copia por valor" o "shallow copy".
// Para copiar un objeto, se utiliza la función con ayuda de lodash usaremos la función _.cloneDeep.

// Requerimos el paquete de lodash para poder utilizar sus funciones 
const _ = require('lodash');

let people = [
    {
        name: 'Arnold',
        specialization: 'C++',
    },
    {
        name: 'Phil',
        specialization: 'Python',
    },
    {
        name: 'Percy',
        specialization: 'JS',
    },
];

// Creamos una copia del array de personas
let peopleCopy = _.cloneDeep(people); 

// Encontrar la persona con especialización C++, en el nuevo array
let folksDoingCpp = peopleCopy.filter(
    (person) => person.specialization == 'C++'
);

// Convertir la nueva persona a JS!
for (person of folksDoingCpp) {
    person.specialization = 'JS';
}

console.log(
    "Nueva persona (modificada): ", folksDoingCpp,
    // Imprimir la lista de personas sin modificar
    "\nLista de personas (sin modificar): ", people
);
  /*
[
  { name: 'Arnold', specialization: 'C++' },
  { name: 'Phil', specialization: 'Python' },
  { name: 'Percy', specialization: 'JS' }
]
*/