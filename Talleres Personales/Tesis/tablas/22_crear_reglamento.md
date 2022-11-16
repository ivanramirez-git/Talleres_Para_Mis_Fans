|# Requerimiento|22 |
|-|-|
| *Nombre*|Crear reglamento
| *Descripción*| Permite que el los delegatarios creen un reglamento |
|*Actores*| - Delegatario<br> - Sistema<br> - Fiscal
|*Precondiciones*| - Debe existir un delegatario<br> - Debe existir una sede<br> - El reglamento debió ser presentado ante la asamblea, votado y aprobado
|*Postcondiciones*| - El sistema crea un reglamento<br> - El fiscal obtiene el reglamento para su revisión
|*Flujo principal*|0.  El delegatario ingresa a la vista de reglamentos<br>1.  El delegatario selecciona la opción de crear reglamento<br>2.  El sistema le envia a la vista de edición de reglamentos<br>3.  El delegatario ingresa los datos del reglamento<br>4.  El delegatario publica el reglamento<br>5.  El sistema notifica al fiscal con el reglamento disponible para su revisión
|*Flujos alternos*|0.  0. No hay reglamentos pendientes aprobados en asamblea<br>1. El sistema muestra un mensaje de que no hay reglamentos pendientes
