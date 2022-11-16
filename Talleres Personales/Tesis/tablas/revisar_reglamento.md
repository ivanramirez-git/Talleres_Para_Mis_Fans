|# Requerimiento|23 |
|-|-|
| *Nombre*|Revisar reglamento
| *Descripción*| Permite que el fiscal revise un reglamento |
|*Actores*| - Fiscal<br> - Sistema<br> - Delegatario
|*Precondiciones*| - Debe existir un fiscal<br> - Debe existir un reglamento disponible para revisión
|*Postcondiciones*| - El sistema actualiza el estado del reglamento a revisado<br> - El reglamento estara disponible para todos los asociados y sus artículos para la búsqueda
|*Flujo principal*|0.  El fiscal ingresa a la vista de reglamentos<br>1.  El fiscal selecciona la opción de revisar reglamento<br>2.  El sistema le envia a la vista de revisión de reglamentos<br>3.  El fiscal revisa el reglamento<br>4.  El fiscal aprueba el reglamento<br>5.  El sistema notifica al delegatario con el reglamento revisado<br>6.  El relgado estara disponible para todos los asociados y sus artículos para la búsqueda
|*Flujos alternos*|0.  El fiscal no aprueba el reglamento<br>El sistema notifica al delegatario con el reglamento rechazado
