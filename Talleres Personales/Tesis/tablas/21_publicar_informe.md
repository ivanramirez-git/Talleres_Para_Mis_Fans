|# Requerimiento|21 |
|-|-|
| *Nombre*|Publicar informe
| *Descripción*| Permite que el sistema distribuya el informe a los asociados |
|*Actores*| - Sistema<br> - Asociado
|*Precondiciones*| - Debe existir un informe revisado y aprobado
|*Postcondiciones*| - El sistema actualiza el estado del informe a publicado<br> - El sistema notifica a los asociados con el informe
|*Flujo principal*|0.  El sistema descubre un informe revisado, aprobado y que aun no ha sido publicado<br>1.  El sistema notifica a los asociados con el informe<br>2.  El sistema actualiza el estado del informe a publicado
|*Flujos alternos*|0. <br> 0. No hay informes pendientes<br>1. El sistema muestra un mensaje de que no hay informes pendientes
