# Notificar tareas

Envía notificaciones a un asociado cuando se acerca la fecha de una tarea asignada

## Precondiciones

* El asociado debe existir en el sistema
* El asociado debe tener tareas asignadas

## Postcondiciones

* El sistema envía notificaciones al asociado cuando se acerca la fecha de una tarea asignada

## Actores

* Asociado
* Sistema

## Flujo principal

0. El sistema verifica si hay tareas asignadas al asociado
1. El sistema verifica si hay tareas asignadas al asociado que se acerquen a su fecha de entrega
2. El sistema envía una notificación de tareas próximas

## Flujos alternos

### 0.  Flujo alterno

0. El asociado no tiene una sesión activa
1. El sistema no envía notificaciones

