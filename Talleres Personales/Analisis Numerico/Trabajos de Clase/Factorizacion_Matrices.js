// Lenguaje: JavaScript
// Autor: Ivan Rene Ramirez Castro



// Norma de matriz A
function normaMatriz(A,p){
        
    var norma = 0;
    // Validar que A sea cuadrada
    if(A.length == A[0].length){
        // Calcular la norma
        for(var i = 1; i < A.length; i++){
            for(var j = 0; j < A[i].length; j++){
                norma += Math.pow(Math.abs(A[i][j]),p);
            }
        }

        norma = Math.pow(norma,1/p);

    } else {
        console.log("La matriz A no es cuadrada");
        return null;
    }

    return norma;
}



// Limpiar consola
console.clear();

// Pedir al usuario que ingrese la matriz A
var A = [];

A = [
        [2,-1,1],
        [3,3,9],
        [3,3,5]
    ];

// Imprimir la matriz A
console.log("Matriz A:");
console.log(A);

// Norma de la matriz A
console.log("Norma de la matriz A: "+normaMatriz(A,1));


