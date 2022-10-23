# Aprendiendo a usar Lapython

# Funcion lambda

# Imprimir el resultado
print("Resultado: ", (lambda x: x * 2)(5))

# Uso de Pass

# Pass, simplemente indica un espacio que debería quedar en blanco dentro de la declaración compound.

# Ejemplo
def my_function():
    pass


# Ejemplo
class MyEmptyClass:
    pass


# Ejemplo
def initlog(*args):
    pass  # Remember to implement this!


# Copiando objetos

# Copiar objetos en Python no es tan sencillo como parece. Hay dos formas de copiar objetos en Python: Shallow Copy y Deep Copy.

# Shallow Copy

# Una copia superficial crea un nuevo objeto que contiene las referencias a los elementos de los objetos originales. Esto significa que cualquier cambio en el objeto original también afectará al objeto copiado.

# Ejemplo
print("Shallow Copy")
import copy

# Original list
list1 = [1, 2, [3, 5], 4]
# Shallow copy
list2 = copy.copy(list1)
# Adding and element to new list
list2.append(6)
# Adding and element to original list
list1[2].append(7)
# Printing new list
print("New List: ", list2)
# Printing original list
print("Original List: ", list1)

# Deep Copy

# Una copia profunda crea un nuevo objeto y copia los elementos y sus referencias internas. Esto significa que cualquier cambio en el objeto original no afectará al objeto copiado.

# Ejemplo
print("Deep Copy")
import copy

# Original list
list1 = [1, 2, [3, 5], 4]
# Deep copy
list2 = copy.deepcopy(list1)
# Adding and element to new list
list2.append(6)
# Adding and element to original list
list1[2].append(7)
# Printing new list
print("New List: ", list2)
# Printing original list
print("Original List: ", list1)


# Pregunta 1: Escribe un código que calcule una lista de números proporcionados.
def list_sum(num_list):
    sum = 0
    for i in num_list:
        sum = sum + i
    return sum


print(list_sum([3, 5, 8, 9, 9]))


# Pregunta 2: Escribe un código que brinde números al azar de una lista.
from random import shuffle

x = ['Krylin', 'Jhon', 'Doe', 'Jane', 'Smith', 'Alex', 'Bob', 'Alice']
shuffle(x)
print(x)

# Pregunta 7: Escriba un código que pueda contar todas las palabras mayúsculas de tu archivo.
def count_upper_case(file):
    count = 0
    with open(file) as f:
        for line in f:
            # is a word?
            for word in line.split():
                if word.isupper():
                    count += 1

                    
    return count


print(count_upper_case("servicio.py"))