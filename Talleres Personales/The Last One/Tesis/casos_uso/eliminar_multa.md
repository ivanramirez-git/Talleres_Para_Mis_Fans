# Eliminar multa o batida

Permite que el administrador elimine una multa o batida

## Precondiciones

* Debe existir un asociado con multas o batidas pendientes

## Postcondiciones

* El sistema elimina la multa o batida
* El asociado multado no tendra esta multa o batida en su lista de multas o batidas pendientes

## Actores

* Administrador
* Sistema
* Asociado

## Flujo principal

0. El administrador ingresa a la vista de multas o batidas
1. El administrador selecciona la multa o batida a eliminar
2. El administrador confirma la eliminación de la multa o batida
3. El sistema elimina la multa o batida
4. El sistema notifica al asociado multado que su multa o batida ha sido eliminada

## Flujos alternos

### 0.  Flujo alterno

0. No hay multas o batidas pendientes
1. El sistema muestra un mensaje de que no hay multas o batidas pendientes

