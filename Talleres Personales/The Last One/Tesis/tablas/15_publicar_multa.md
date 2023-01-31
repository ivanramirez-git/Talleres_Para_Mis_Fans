|# Requerimiento|15 |
|-|-|
| *Nombre*|Publicar multa o batida
| *Descripción*| Permite que el sistema notifique de la multa a los asociados multados |
|*Actores*| - Asociado<br> - Sistema
|*Precondiciones*| - El asociado a multar debe existir en el sistema<br> - El asociado a que crea la multa debe existir en el sistema
|*Postcondiciones*| - El sistema notifica a los asociados multados
|*Flujo principal*|0.  El sistema identifica una multa que ha sido aprobada por los asociados respaldantes y aprobada en junta<br>1.  El sistema notifica a los asociados multados
|*Flujos alternos*|0. <br> 0. La junta no aprueba la multa<br>1. El sistema notifica al los asociados involucrados, asociado principal y respaldantes de la multa, que la multa no ha sido aprobada

Tabla #. Caso de uso "Publicar multa o batida"
