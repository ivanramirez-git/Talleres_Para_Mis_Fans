|# Requerimiento|7 |
|-|-|
| *Nombre*|Revisar tarea realizada
| *Descripción*| Permite aprobar o rechazar una tarea asignada a un asociado |
|*Actores*| - Administrador<br> - Sistema
|*Precondiciones*| - El asociado debe existir en el sistema<br> - El asociado debe tener tareas asignadas
|*Postcondiciones*| - El sistema agregará la tarea a la lista de tareas realizadas
|*Flujo principal*|0.  El administrador ingresa a la lista de tareas, donde se muestran las tareas pendientes organizadas por fecha ascendente<br>1.  El administrador selecciona una tarea<br>2.  El administrador puede ver los detalles de la tarea<br>3.  El administrador puede aprueba la tarea<br>4.  El sistema muestra un mensaje de éxito
|*Flujos alternos*|0.  El administrador rechaza la tarea<br>El sistema muestra un mensaje de éxito
