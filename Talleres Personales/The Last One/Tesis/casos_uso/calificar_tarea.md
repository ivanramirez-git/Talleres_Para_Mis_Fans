# Calificar tarea realizada

Permite calificar una tarea asignada a un asociado una vez que esta ha sido revisada

## Precondiciones

* El asociado debe existir en el sistema
* El asociado debe tener tareas asignadas
* La tarea debe haber sido revisada

## Postcondiciones

* El sistema guarda la calificación de la tarea asignada

## Actores

* Asociado
* Sistema
* Administrador

## Flujo principal

0. El asociado ingresa a la lista de tareas realizadas
1. El asociado selecciona una tarea
2. El asociado puede ver los detalles de la tarea
3. El asociado puede calificar la tarea
4. El sistema guarda la calificación de la tarea asignada

## Flujos alternos

### 0.  Flujo alterno

0. El asociado no tiene tareas realizadas
1. El sistema muestra un mensaje de que no hay tareas realizadas

### 1.  Flujo alterno

0. El asociado quiere agregar una sugerencia
1. El sistema guarda la sugerencia
2. El sistema notifica al administrador acerca de la sugerencia

