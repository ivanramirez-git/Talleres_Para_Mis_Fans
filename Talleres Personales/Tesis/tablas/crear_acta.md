|# Requerimiento|18 |
|-|-|
| *Nombre*|Crear acta
| *Descripción*| Permite que el administrador cree una acta |
|*Actores*| - Administrador<br> - Sistema<br> - Asociado
|*Precondiciones*| - Debe existir un administrador
|*Postcondiciones*| - El sistema crea una acta<br> - Los asociados son notificados con el acta<br> - Se actualizan las tablas de calendarios y compromisos correspondientes
|*Flujo principal*|0.  El administrador ingresa a la vista de actas<br>1.  El administrador selecciona la opción de crear acta<br>2.  El administrador selecciona el tipo de reunión<br>3.  El sistema le envia a la vista de edición de actas<br>4.  El administrador ingresa los datos de la acta<br>5.  El administrador publica la acta<br>6.  El sistema notifica a los asociados con la acta<br>7.  El sistema actualiza las tablas de calendarios y compromisos correspondientes
|*Flujos alternos*|0.  No hay actas pendientes<br>El sistema muestra un mensaje de que no hay actas pendientes
