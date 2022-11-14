# Consultar instrucciones de tarea

Permite consultar las instrucciones de una tarea asignada a un asociado

## Precondiciones

* El asociado debe existir en el sistema
* El asociado debe tener tareas asignadas

## Postcondiciones

* El sistema muestra las instrucciones de la tarea asignada

## Actores

* Asociado
* Sistema

## Flujo principal

0. El asociado ingresa a la lista de tareas, donde se muestran las tareas pendientes organizadas por fecha asendente
1. El asociado selecciona una tarea
2. El asociado puede ver los detalles de la tarea
3. El asociado puede ver las instrucciones de la tarea

## Flujos alternos

### 0.  Flujo alterno

0. El asociado no tiene tareas asignadas
1. El sistema muestra un mensaje de que no hay tareas asignadas

