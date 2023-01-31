# Publicar multa o batida

Permite que el sistema notifique de la multa a los asociados multados

## Precondiciones

* El asociado a multar debe existir en el sistema
* El asociado a que crea la multa debe existir en el sistema

## Postcondiciones

* El sistema notifica a los asociados multados

## Actores

* Asociado
* Sistema

## Flujo principal

0. El sistema identifica una multa que ha sido aprobada por los asociados respaldantes y aprobada en junta
1. El sistema notifica a los asociados multados

## Flujos alternos

### 0.  Flujo alterno

0. La junta no aprueba la multa
1. El sistema notifica al los asociados involucrados, asociado principal y respaldantes de la multa, que la multa no ha sido aprobada

