|# Requerimiento|3 |
|-|-|
| *Nombre*|Asignar tarea
| *Descripción*| Permite asignar una tarea a un asociado |
|*Actores*| - Administrador<br> - Sistema
|*Precondiciones*| - El asociado debe existir en el sistema<br> - La tarea debe existir en el sistema
|*Postcondiciones*| - La tarea debe estar asignada al asociado en una fecha determinada
|*Flujo principal*|0.  El administrador selecciona inscribir tarea manualmente<br>1.  El administrador selecciona una fecha para la asignación<br>2.  El administrador selecciona una tarea desde la lista de tareas disponibles<br>3.  El administrador selecciona un asociado, o varios asociados, la lista de asociados se organiza por el indice de prioridad<br>4.  El sistema asigna la tarea a los asociados seleccionados<br>5.  El sistema muestra un mensaje de éxito
|*Flujos alternos*|0. <br> 0. El asociado ya tiene una tarea asignada en la fecha seleccionada<br>1. El sistema muestra un mensaje de recomendación para cambiar el asociado<br>2. Continuar con el flujo principal, paso 3 o 4<hr>1. <br> 0. El administrador selecciona inscribir tarea automáticamente<br>1. El sistema asigna las tareas disponibles a los asociados disponibles por orden de prioridad<br>2. El sistema muestra un mensaje de éxito<hr>2. <br> 0. El administrador no encuentra la tarea en la lista de tareas<br>1. El administrador entra a la vista de crear nueva tarea<br>2. El administrador llena el formulario de nueva tarea<br>3. El administrador pulsa el botón de crear tarea<br>4. El sistema crea la tarea<br>5. Continuar con el flujo principal, paso 2

Tabla #. Caso de uso "Asignar tarea"
