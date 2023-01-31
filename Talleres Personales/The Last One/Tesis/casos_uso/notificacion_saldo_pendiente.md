# Notificación de saldo pendiente

Permite que el tesorero notifique a los asociados con saldos pendientes

## Precondiciones

* El asociado debe tener una cuota pendiente
* Debe existir un tesorero activo

## Postcondiciones

* Los asociados reciben una notificación con el saldo pendiente

## Actores

* Tesorero
* Sistema
* Asociado

## Flujo principal

0. El tesorero ingresa a la vista de cuotas
1. El tesorero selecciona la opción de notificación de saldo pendiente
2. El sistema le envia a la vista de notificación de saldo pendiente a cada asociado correspondiente
3. El sistema notifica a los asociados con el saldo pendiente

## Flujos alternos

### 0.  Flujo alterno

0. No hay asociados con cuotas pendientes
1. El sistema muestra un mensaje de que no hay asociados con cuotas pendientes

