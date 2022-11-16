|# Requerimiento|26 |
|-|-|
| *Nombre*|Recibo de pago de cuota
| *Descripción*| Permite que el tesorero apruebe el pago de una cuota y que el asociado reciba el comprobante de pago |
|*Actores*| - Tesorero<br> - Sistema<br> - Asociado
|*Precondiciones*| - El asociado debe tener una cuota pendiente<br> - Debe existir un tesorero activo
|*Postcondiciones*| - El sistema aprueba el pago de la cuota<br> - El sistema notifica al asociado con el comprobante de pago
|*Flujo principal*|0.  El tesorero ingresa a la vista de cuotas<br>1.  El tesorero selecciona la opción de recibo de pago de cuota<br>2.  El sistema le envia a la vista de recibo de pago de cuota, donde están todos los datos precargados de los asociados<br>3.  El tesorero busca a el asociado que realizo el pago<br>4.  El tesorero agrega el valor del pago<br>5.  El tesorero aprueba el pago de la cuota<br>6.  El sistema notifica al asociado con el comprobante de pago
|*Flujos alternos*|0.  0. No hay asociados con cuotas pendientes<br>1. El sistema muestra un mensaje de que no hay asociados con cuotas pendientes
