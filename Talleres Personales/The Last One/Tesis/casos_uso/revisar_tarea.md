# Revisar tarea realizada

Permite aprobar o rechazar una tarea asignada a un asociado

## Precondiciones

* El asociado debe existir en el sistema
* El asociado debe tener tareas asignadas

## Postcondiciones

* El sistema agregará la tarea a la lista de tareas realizadas

## Actores

* Administrador
* Sistema

## Flujo principal

0. El administrador ingresa a la lista de tareas, donde se muestran las tareas pendientes organizadas por fecha ascendente
1. El administrador selecciona una tarea
2. El administrador puede ver los detalles de la tarea
3. El administrador puede aprueba la tarea
4. El sistema muestra un mensaje de éxito

## Flujos alternos

### 0.  Flujo alterno

0. El administrador rechaza la tarea
1. El sistema muestra un mensaje de éxito

