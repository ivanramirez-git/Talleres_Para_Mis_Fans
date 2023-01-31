# Crear reglamento

Permite que el los delegatarios creen un reglamento

## Precondiciones

* Debe existir un delegatario
* Debe existir una sede
* El reglamento debió ser presentado ante la asamblea, votado y aprobado

## Postcondiciones

* El sistema crea un reglamento
* El fiscal obtiene el reglamento para su revisión

## Actores

* Delegatario
* Sistema
* Fiscal

## Flujo principal

0. El delegatario ingresa a la vista de reglamentos
1. El delegatario selecciona la opción de crear reglamento
2. El sistema le envia a la vista de edición de reglamentos
3. El delegatario ingresa los datos del reglamento
4. El delegatario publica el reglamento
5. El sistema notifica al fiscal con el reglamento disponible para su revisión

## Flujos alternos

### 0.  Flujo alterno

0. No hay reglamentos pendientes aprobados en asamblea
1. El sistema muestra un mensaje de que no hay reglamentos pendientes

