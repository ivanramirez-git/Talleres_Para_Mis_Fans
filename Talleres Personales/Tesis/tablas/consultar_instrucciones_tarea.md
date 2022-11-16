|# Requerimiento|9 |
|-|-|
| *Nombre*|Consultar instrucciones de tarea
| *Descripción*| Permite consultar las instrucciones de una tarea asignada a un asociado |
|*Actores*| - Asociado<br> - Sistema
|*Precondiciones*| - El asociado debe existir en el sistema<br> - El asociado debe tener tareas asignadas
|*Postcondiciones*| - El sistema muestra las instrucciones de la tarea asignada
|*Flujo principal*|0.  El asociado ingresa a la lista de tareas, donde se muestran las tareas pendientes organizadas por fecha asendente<br>1.  El asociado selecciona una tarea<br>2.  El asociado puede ver los detalles de la tarea<br>3.  El asociado puede ver las instrucciones de la tarea
|*Flujos alternos*|0.  El asociado no tiene tareas asignadas<br>El sistema muestra un mensaje de que no hay tareas asignadas
