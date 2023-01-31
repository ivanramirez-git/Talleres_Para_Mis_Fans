# Asignar tarea

Permite asignar una tarea a un asociado

## Precondiciones

* El asociado debe existir en el sistema
* La tarea debe existir en el sistema

## Postcondiciones

* La tarea debe estar asignada al asociado en una fecha determinada

## Actores

* Administrador
* Sistema

## Flujo principal

0. El administrador selecciona inscribir tarea manualmente
1. El administrador selecciona una fecha para la asignación
2. El administrador selecciona una tarea desde la lista de tareas disponibles
3. El administrador selecciona un asociado, o varios asociados, la lista de asociados se organiza por el indice de prioridad
4. El sistema asigna la tarea a los asociados seleccionados
5. El sistema muestra un mensaje de éxito

## Flujos alternos

### 0.  Flujo alterno

0. El asociado ya tiene una tarea asignada en la fecha seleccionada
1. El sistema muestra un mensaje de recomendación para cambiar el asociado
2. Continuar con el flujo principal, paso 3 o 4

### 1.  Flujo alterno

0. El administrador selecciona inscribir tarea automáticamente
1. El sistema asigna las tareas disponibles a los asociados disponibles por orden de prioridad
2. El sistema muestra un mensaje de éxito

### 2.  Flujo alterno

0. El administrador no encuentra la tarea en la lista de tareas
1. El administrador entra a la vista de crear nueva tarea
2. El administrador llena el formulario de nueva tarea
3. El administrador pulsa el botón de crear tarea
4. El sistema crea la tarea
5. Continuar con el flujo principal, paso 2

