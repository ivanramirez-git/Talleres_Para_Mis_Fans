|# Requerimiento|8 |
|-|-|
| *Nombre*|Documentar tarea realizada
| *Descripción*| Permite documentar una tarea asignada a un asociado para su posterior revisión y toma de decisiones de prioridades para próximas asignaciones de tareas |
|*Actores*| - Asociado<br> - Sistema<br> - Administrador
|*Precondiciones*| - Una tarea acaba de ser asignada a un asociado
|*Postcondiciones*| - El sistema guarda la documentación de la tarea asignada<br> - Las prioridades de las asignaciones siguientes se actualizan
|*Flujo principal*|0.  El sistema asigna una tarea a un asociado<br>1.  El sistema guarda la documentación de la tarea asignada<br>2.  El sistema actualiza las prioridades de las asignaciones siguientes
|*Flujos alternos*|0. <br> 0. No hay tareas asignadas<br>1. El sistema duerme
