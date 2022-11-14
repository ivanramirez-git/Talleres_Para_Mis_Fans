# Buscar artículo

Permite que los asociados busquen artículos de los reglamentos

## Precondiciones

* Debe existir un asociado
* Debe existir un reglamento

## Postcondiciones

* El sistema muestra los artículos del reglamento que coincidan con la búsqueda

## Actores

* Asociado
* Sistema

## Flujo principal

0. El asociado ingresa a la vista de reglamentos
1. El asociado selecciona la opción de buscar artículo
2. El sistema le envia a la vista de búsqueda de artículos
3. El asociado ingresa los datos de la búsqueda
4. El sistema muestra los artículos del reglamento que coincidan con la búsqueda

## Flujos alternos

### 0.  Flujo alterno

0. No hay artículos que coincidan con la búsqueda
1. El sistema muestra un mensaje de que no hay artículos que coincidan con la búsqueda

