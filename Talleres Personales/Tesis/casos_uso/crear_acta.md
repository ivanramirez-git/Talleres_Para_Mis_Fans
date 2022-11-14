# Crear acta

Permite que el administrador cree una acta

## Precondiciones

* Debe existir un administrador

## Postcondiciones

* El sistema crea una acta
* Los asociados son notificados con el acta
* Se actualizan las tablas de calendarios y compromisos correspondientes

## Actores

* Administrador
* Sistema
* Asociado

## Flujo principal

0. El administrador ingresa a la vista de actas
1. El administrador selecciona la opción de crear acta
2. El administrador selecciona el tipo de reunión
3. El sistema le envia a la vista de edición de actas
4. El administrador ingresa los datos de la acta
5. El administrador publica la acta
6. El sistema notifica a los asociados con la acta
7. El sistema actualiza las tablas de calendarios y compromisos correspondientes

## Flujos alternos

### 0.  Flujo alterno

0. No hay actas pendientes
1. El sistema muestra un mensaje de que no hay actas pendientes

