# Revisar reglamento

Permite que el fiscal revise un reglamento

## Precondiciones

* Debe existir un fiscal
* Debe existir un reglamento disponible para revisión

## Postcondiciones

* El sistema actualiza el estado del reglamento a revisado
* El reglamento estara disponible para todos los asociados y sus artículos para la búsqueda

## Actores

* Fiscal
* Sistema
* Delegatario

## Flujo principal

0. El fiscal ingresa a la vista de reglamentos
1. El fiscal selecciona la opción de revisar reglamento
2. El sistema le envia a la vista de revisión de reglamentos
3. El fiscal revisa el reglamento
4. El fiscal aprueba el reglamento
5. El sistema notifica al delegatario con el reglamento revisado
6. El relgado estara disponible para todos los asociados y sus artículos para la búsqueda

## Flujos alternos

### 0.  Flujo alterno

0. El fiscal no aprueba el reglamento
1. El sistema notifica al delegatario con el reglamento rechazado

