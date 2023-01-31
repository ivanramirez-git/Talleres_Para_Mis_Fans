# Revisar informe

Permite que el fiscal revise un informe

## Precondiciones

* Debe existir un fiscal
* Debe existir un informe disponible para revisión

## Postcondiciones

* El sistema actualiza el estado del informe a revisado
* El fiscal obtiene el informe para su revisión

## Actores

* Fiscal
* Sistema
* Administrador

## Flujo principal

0. El fiscal ingresa a la vista de informes
1. El fiscal selecciona la opción de revisar informe
2. El sistema le envia a la vista de revisión de informes
3. El fiscal revisa el informe
4. El fiscal aprueba el informe
5. El sistema notifica al administrador con el informe revisado

## Flujos alternos

### 0.  Flujo alterno

0. El fiscal no aprueba el informe
1. El sistema notifica al administrador con el informe rechazado

