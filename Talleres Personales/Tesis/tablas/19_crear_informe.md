|# Requerimiento|19 |
|-|-|
| *Nombre*|Crear informe
| *Descripción*| Permite que el administrador cree un informe |
|*Actores*| - Administrador<br> - Sistema<br> - Fiscal
|*Precondiciones*| - Debe existir un administrador<br> - Debe existir un cargo
|*Postcondiciones*| - El sistema crea un informe<br> - El fiscal obtiene el informe para su revisión
|*Flujo principal*|0.  El administrador ingresa a la vista de informes<br>1.  El administrador selecciona la opción de crear informe, este sera creado segun el rol del administrador<br>2.  El sistema le envia a la vista de edición de informes<br>3.  El administrador ingresa los datos del informe<br>4.  El administrador publica el informe<br>5.  El sistema notifica al fiscal con el informe disponible para su revisión
|*Flujos alternos*|0. <br> 0. No hay informes pendientes<br>1. El sistema muestra un mensaje de que no hay informes pendientes
