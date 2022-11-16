|# Requerimiento|25 |
|-|-|
| *Nombre*|Crear tabla de cobros de cuotas a los asociados
| *Descripción*| Permite que el tesorero cree una tabla de cobros de cuotas a los asociados, estos recibiran una notificacion y podran ver el valor de la cuota y los detalles que componen el valor de la cuota |
|*Actores*| - Tesorero<br> - Sistema<br> - Asociado
|*Precondiciones*| - Deben existir asociados activos con fechas de ingreso<br> - Debe existir un tesorero activo<br> - Debe existir una sede
|*Postcondiciones*| - El sistema crea una tabla de cobros de cuotas a los asociados<br> - El sistema notifica a los asociados con el valor de la cuota y los detalles que componen el valor de la cuota
|*Flujo principal*|0.  El tesorero ingresa a la vista de cuotas<br>1.  El tesorero selecciona la opción de crear tabla de cobros de cuotas<br>2.  El sistema le envia a la vista de creación de tabla de cobros de cuotas, donde estan todos los datos precargados de los asociados<br>3.  El tesorero ingresa los datos adicionales de la tabla de cobros de cuotas<br>4.  El tesorero publica la tabla de cobros de cuotas<br>5.  El sistema notifica a los asociados con el valor de la cuota y los detalles que componen el valor de la cuota
|*Flujos alternos*|0.  No hay asociados activos con fechas de ingreso<br>El sistema muestra un mensaje de que no hay asociados activos con fechas de ingreso<hr>1.  No hay una sede<br>El sistema muestra un mensaje de que no hay una sede
