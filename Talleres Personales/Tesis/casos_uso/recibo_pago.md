# Recibo de pago de cuota

Permite que el tesorero apruebe el pago de una cuota y que el asociado reciba el comprobante de pago

## Precondiciones

* El asociado debe tener una cuota pendiente
* Debe existir un tesorero activo

## Postcondiciones

* El sistema aprueba el pago de la cuota
* El sistema notifica al asociado con el comprobante de pago

## Actores

* Tesorero
* Sistema
* Asociado

## Flujo principal

0. El tesorero ingresa a la vista de cuotas
1. El tesorero selecciona la opción de recibo de pago de cuota
2. El sistema le envia a la vista de recibo de pago de cuota, donde están todos los datos precargados de los asociados
3. El tesorero busca a el asociado que realizo el pago
4. El tesorero agrega el valor del pago
5. El tesorero aprueba el pago de la cuota
6. El sistema notifica al asociado con el comprobante de pago

## Flujos alternos

### 0.  Flujo alterno

0. No hay asociados con cuotas pendientes
1. El sistema muestra un mensaje de que no hay asociados con cuotas pendientes

