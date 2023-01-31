# Documentar tarea realizada

Permite documentar una tarea asignada a un asociado para su posterior revisión y toma de decisiones de prioridades para próximas asignaciones de tareas

## Precondiciones

* Una tarea acaba de ser asignada a un asociado

## Postcondiciones

* El sistema guarda la documentación de la tarea asignada
* Las prioridades de las asignaciones siguientes se actualizan

## Actores

* Asociado
* Sistema
* Administrador

## Flujo principal

0. El sistema asigna una tarea a un asociado
1. El sistema guarda la documentación de la tarea asignada
2. El sistema actualiza las prioridades de las asignaciones siguientes

## Flujos alternos

### 0.  Flujo alterno

0. No hay tareas asignadas
1. El sistema duerme

