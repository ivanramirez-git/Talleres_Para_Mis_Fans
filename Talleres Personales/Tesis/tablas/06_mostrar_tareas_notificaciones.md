|# Requerimiento|6 |
|-|-|
| *Nombre*|Notificar tareas
| *Descripción*| Envía notificaciones a un asociado cuando se acerca la fecha de una tarea asignada |
|*Actores*| - Asociado<br> - Sistema
|*Precondiciones*| - El asociado debe existir en el sistema<br> - El asociado debe tener tareas asignadas
|*Postcondiciones*| - El sistema envía notificaciones al asociado cuando se acerca la fecha de una tarea asignada
|*Flujo principal*|0.  El sistema verifica si hay tareas asignadas al asociado<br>1.  El sistema verifica si hay tareas asignadas al asociado que se acerquen a su fecha de entrega<br>2.  El sistema envía una notificación de tareas próximas
|*Flujos alternos*|0. <br> 0. El asociado no tiene una sesión activa<br>1. El sistema no envía notificaciones
