# Taller # 1 – Desarrollo Web



PONTIFICIA UNIVERSIDAD JAVERIANA
FACULTAD DE INGENIERIA

Ivan Rene Ramirez Castro


Le han solicitado crear un MVP (Mínimo producto viable) de una tienda de libros tradicionales con las siguientes necesidades.

- Crear un libro:
    - El título debe tener mínimo 5 caracteres y máximo 100 caracteres
    - La descripción no puede tener más de 200 caracteres.
    - El precio debe ser positivo, mayor a 10000 pesos y sin centavos
    - El autor debe tener un nombre y un apellido.
    - El año de publicación debe ser un valor de año valido, no superior al año actual y con 4 dígitos.
    
- Listar los libros por autor.
    - A partir del autor, se debe buscar los libros asociados.
    - Debe traer únicamente el nombre del libro y el autor.
    
- Detallar un libro.
    - A partir del libro, se debe traer la descripción, el precio, el año de publicación y un nuevo atributo llamado número de páginas.
    - Las páginas deben ser numéricas positivas, y no pueden superar las 1500 páginas.
    
Cree un programa java de consola para la implementación.
Se puede usar una implementación en memoria de los libros.
    
Tenga en cuenta los siguientes principios:
- Ley de demeter
- Tell don't ask
- Clausulas de guarda
