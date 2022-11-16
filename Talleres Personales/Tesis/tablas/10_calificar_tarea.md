|# Requerimiento|10 |
|-|-|
| *Nombre*|Calificar tarea realizada
| *Descripción*| Permite calificar una tarea asignada a un asociado una vez que esta ha sido revisada |
|*Actores*| - Asociado<br> - Sistema<br> - Administrador
|*Precondiciones*| - El asociado debe existir en el sistema<br> - El asociado debe tener tareas asignadas<br> - La tarea debe haber sido revisada
|*Postcondiciones*| - El sistema guarda la calificación de la tarea asignada
|*Flujo principal*|0.  El asociado ingresa a la lista de tareas realizadas<br>1.  El asociado selecciona una tarea<br>2.  El asociado puede ver los detalles de la tarea<br>3.  El asociado puede calificar la tarea<br>4.  El sistema guarda la calificación de la tarea asignada
|*Flujos alternos*|0. <br> 0. El asociado no tiene tareas realizadas<br>1. El sistema muestra un mensaje de que no hay tareas realizadas<hr>1. <br> 0. El asociado quiere agregar una sugerencia<br>1. El sistema guarda la sugerencia<br>2. El sistema notifica al administrador acerca de la sugerencia

Tabla #. Caso de uso "Calificar tarea realizada"
