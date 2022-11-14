# Publicar informe

Permite que el sistema distribuya el informe a los asociados

## Precondiciones

* Debe existir un informe revisado y aprobado

## Postcondiciones

* El sistema actualiza el estado del informe a publicado
* El sistema notifica a los asociados con el informe

## Actores

* Sistema
* Asociado

## Flujo principal

0. El sistema descubre un informe revisado, aprobado y que aun no ha sido publicado
1. El sistema notifica a los asociados con el informe
2. El sistema actualiza el estado del informe a publicado

## Flujos alternos

### 0.  Flujo alterno

0. No hay informes pendientes
1. El sistema muestra un mensaje de que no hay informes pendientes

