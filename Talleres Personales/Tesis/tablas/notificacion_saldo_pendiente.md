|# Requerimiento|27 |
|-|-|
| *Nombre*|Notificación de saldo pendiente
| *Descripción*| Permite que el tesorero notifique a los asociados con saldos pendientes |
|*Actores*| - Tesorero<br> - Sistema<br> - Asociado
|*Precondiciones*| - El asociado debe tener una cuota pendiente<br> - Debe existir un tesorero activo
|*Postcondiciones*| - Los asociados reciben una notificación con el saldo pendiente
|*Flujo principal*|0.  El tesorero ingresa a la vista de cuotas<br>1.  El tesorero selecciona la opción de notificación de saldo pendiente<br>2.  El sistema le envia a la vista de notificación de saldo pendiente a cada asociado correspondiente<br>3.  El sistema notifica a los asociados con el saldo pendiente
|*Flujos alternos*|0.  No hay asociados con cuotas pendientes<br>El sistema muestra un mensaje de que no hay asociados con cuotas pendientes
