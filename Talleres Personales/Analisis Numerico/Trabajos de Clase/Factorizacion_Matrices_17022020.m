% Lenguaje: Matlab
% Autor: Ivan Rene Ramirez Castro

% Limpiar el workspace
clear all

% Limpiar la pantalla
clc

% Pedir al usuario la matriz A
A = input('Ingrese la matriz A: '); % Ejemplo de input: [1 2 3; 4 5 6; 7 8 9]

% Funcion size
[filas, columnas] = size(A);

% Validar si es cuadrada
if filas ~= columnas
    % Si no es cuadrada, terminar el programa    
    error('La matriz no es cuadrada')
    return
end

% L = [0]
L = zeros(filas);
U = zeros(filas);

% Imprimir A, L y U
fprintf('Matriz A: \n')
disp(A)

% Factorizacion LU
for i = 1:filas
    for j = 1:columnas
        if i == j
            L(i,j) = 1;
        end
        if i > j
            U(i,j) = A(i,j);
        end
    end
end

% Imprimir L y U
fprintf('Matriz L: \n')
disp(L)
fprintf('Matriz U: \n')
disp(U)

% Norma de A
normaA = norm(A,2)

% Imprimir normaA
disp(normaA)