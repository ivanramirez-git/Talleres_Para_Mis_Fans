|# Requerimiento|14 |
|-|-|
| *Nombre*|Aprobar multa o batida
| *Descripción*| Permite que un asociado respaldante de una multa o batida la apruebe o rechace |
|*Actores*| - Asociado<br> - Sistema
|*Precondiciones*| - El asociado a multar debe existir en el sistema<br> - El asociado a que crea la multa debe existir en el sistema
|*Postcondiciones*| - El sistema guarda la aprobación o rechazo de la multa
|*Flujo principal*|0.  El asociado respaldante recibe una notificación de una multa pendiente de respaldo<br>1.  El asociado respaldante ingresa a la vista de la multa<br>2.  El asociado respaldante aprueba la multa<br>3.  El sistema guarda la aprobación de la multa<br>4.  El sistema notifica al asociado principal que su multa ha sido aprobada
|*Flujos alternos*|0.  0. El asociado respaldante no aprueba la multa<br>1. El sistema notifica al asociado principal que su multa no ha sido aprobada
