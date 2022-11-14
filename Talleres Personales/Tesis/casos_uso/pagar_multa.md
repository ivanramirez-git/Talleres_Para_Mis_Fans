# Pagar multa o batida

Permite que el asociado pague una multa o batida

## Precondiciones

* Debe existir un asociado con multas o batidas pendientes

## Postcondiciones

* El sistema elimina la multa o batida
* El asociado multado no tendra esta multa o batida en su lista de multas o batidas pendientes  y esta pasara a su historial de multas o batidas

## Actores

* Asociado
* Sistema
* Administrador

## Flujo principal

0. El administrador ingresa a la vista de multas o batidas
1. El administrador selecciona la multa o batida a pagar
2. El administrador confirma el pago de la multa o batida
3. El sistema actualiza el estado de la multa o batida a pagada
4. El sistema agregara la multa o batida al historial de multas o batidas del asociado
5. El sistema notifica al asociado multado que su multa o batida ha sido pagada

## Flujos alternos

### 0.  Flujo alterno

0. No hay multas o batidas pendientes
1. El sistema muestra un mensaje de que no hay multas o batidas pendientes

