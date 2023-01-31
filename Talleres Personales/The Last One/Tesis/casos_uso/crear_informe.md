# Crear informe

Permite que el administrador cree un informe

## Precondiciones

* Debe existir un administrador
* Debe existir un cargo

## Postcondiciones

* El sistema crea un informe
* El fiscal obtiene el informe para su revisión

## Actores

* Administrador
* Sistema
* Fiscal

## Flujo principal

0. El administrador ingresa a la vista de informes
1. El administrador selecciona la opción de crear informe, este sera creado segun el rol del administrador
2. El sistema le envia a la vista de edición de informes
3. El administrador ingresa los datos del informe
4. El administrador publica el informe
5. El sistema notifica al fiscal con el informe disponible para su revisión

## Flujos alternos

### 0.  Flujo alterno

0. No hay informes pendientes
1. El sistema muestra un mensaje de que no hay informes pendientes

