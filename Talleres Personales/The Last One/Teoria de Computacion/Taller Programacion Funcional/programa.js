/*
1.	Imprima, uno a uno, los elementos del arreglo users
2.	Convierta el arreglo posts en un arreglo que contenga únicamente los títulos 
3.	Repita el ejercicio, pero usando la función map
4.	Filtre los elementos del siguiente arreglo posts para que contengan únicamente aquellos posts donde el atributo userId == 1
5.	En una sola línea de código, realice las funcionalidades 3 y 4, es decir obtener el arreglo de los títulos de los posts donde  userId == 1 
6.	Calcule el promedio de la latitud (atributo address.geo.lat) de los usuarios del arreglo users
7.	Implemente una función que reciba longitud y latitud y un listado de usuarios y retorne true si al menos un usuario está a menos de 30 grados de la longitud y latitud dadas (utilice distancia euclidiana para hacer el cálculo). 
8.	Considere las funciones de la API de Javascript que usó en los ejercicios anteriores. Cuáles serían los métodos/funciones equivalentes en:
•	Python (Lambda) 
•	Java (Closures) 
•	C++ (Closures) 
*/
require('./datos.js');

// 1. Imprima, uno a uno, los elementos del arreglo users
function imprimirUsuarios() {
    console.log(users);
}

// 2. Convierta el arreglo posts en un arreglo que contenga únicamente los títulos
function titulosPosts() {
    posts.forEach(
        post => console.log(post.title)
    );
}

// 3. Repita el ejercicio, pero usando la función map
function titulosPostsMap() {
    console.log(posts.map(post => post.title));
}

// 4. Filtre los elementos del siguiente arreglo posts para que contengan únicamente aquellos posts donde el atributo userId == 1
function filtrarPosts() {
    console.log(posts.filter(post => post.userId == 1));
}

// 5. En una sola línea de código, realice las funcionalidades 3 y 4, es decir obtener el arreglo de los títulos de los posts donde  userId == 1
function titulosPostsFilter() { console.log(posts.filter(post => post.userId == 1).map(post => post.title)); }
titulosPostsFilter();
// 6. Calcule el promedio de la latitud (atributo address.geo.lat) de los usuarios del arreglo users
function promedioLatitud() {
    console.log(
        users.map(
            user => user.address.geo.lat
        ).reduce(
            (a, b) => a - (-b), 0) / users.length
    );
}

// 7. Implemente una función que reciba longitud y latitud y un listado de usuarios y retorne true si al menos un usuario está a menos de 30 grados de la longitud y latitud dadas (utilice distancia euclidiana para hacer el cálculo).
function distancia(longitud, latitud) {
    return function (user) {
        return Math.sqrt(
            Math.pow(user.address.geo.lng - longitud, 2) +
            Math.pow(user.address.geo.lat - latitud, 2)
        ) < 30;
    }
}

// 8. Considere las funciones de la API de Javascript que usó en los ejercicios anteriores. Cuáles serían los métodos/funciones equivalentes en:
/*
    Python (Lambda):
    1.	Imprima, uno a uno, los elementos del arreglo users


// Main
//imprimirUsuarios();
//titulosPosts();
//titulosPostsMap();
//filtrarPosts();
//titulosPostsFilter();
//promedioLatitud();
console.log(users.filter(distancia(10, 10)));
*/