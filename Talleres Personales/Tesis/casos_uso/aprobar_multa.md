# Aprobar multa o batida

Permite que un asociado respaldante de una multa o batida la apruebe o rechace

## Precondiciones

* El asociado a multar debe existir en el sistema
* El asociado a que crea la multa debe existir en el sistema

## Postcondiciones

* El sistema guarda la aprobación o rechazo de la multa

## Actores

* Asociado
* Sistema

## Flujo principal

0. El asociado respaldante recibe una notificación de una multa pendiente de respaldo
1. El asociado respaldante ingresa a la vista de la multa
2. El asociado respaldante aprueba la multa
3. El sistema guarda la aprobación de la multa
4. El sistema notifica al asociado principal que su multa ha sido aprobada

## Flujos alternos

### 0.  Flujo alterno

0. El asociado respaldante no aprueba la multa
1. El sistema notifica al asociado principal que su multa no ha sido aprobada

