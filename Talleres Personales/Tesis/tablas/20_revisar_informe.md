|# Requerimiento|20 |
|-|-|
| *Nombre*|Revisar informe
| *Descripción*| Permite que el fiscal revise un informe |
|*Actores*| - Fiscal<br> - Sistema<br> - Administrador
|*Precondiciones*| - Debe existir un fiscal<br> - Debe existir un informe disponible para revisión
|*Postcondiciones*| - El sistema actualiza el estado del informe a revisado<br> - El fiscal obtiene el informe para su revisión
|*Flujo principal*|0.  El fiscal ingresa a la vista de informes<br>1.  El fiscal selecciona la opción de revisar informe<br>2.  El sistema le envia a la vista de revisión de informes<br>3.  El fiscal revisa el informe<br>4.  El fiscal aprueba el informe<br>5.  El sistema notifica al administrador con el informe revisado
|*Flujos alternos*|0. <br> 0. El fiscal no aprueba el informe<br>1. El sistema notifica al administrador con el informe rechazado

Tabla #. Caso de uso "Revisar informe"
