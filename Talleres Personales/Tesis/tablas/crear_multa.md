|# Requerimiento|13 |
|-|-|
| *Nombre*|Crear multa o batida
| *Descripción*| Permite que un grupo de 3 asociados o más cree una multa o batida |
|*Actores*| - Asociado<br> - Sistema
|*Precondiciones*| - El asociado a multar debe existir en el sistema<br> - El asociado a que crea la multa debe existir en el sistema<br> - Los 2 asociados que respaldan la multa deben existir en el sistema
|*Postcondiciones*| - El sistema guarda la multa y la deja pendiente de aprobación
|*Flujo principal*|0.  El asociado principal inicializa la creación de la multa<br>1.  El asociado principal selecciona el asociado o asociados a multar<br>2.  Indicar si la multa es a un invitado del asociado a multar<br>3.  El asociado principal selecciona el tipo de multa<br>4.  El asociado principal rellena el formulario de la multa<br>5.  El asociado principal selecciona los asociados que respaldan la multa<br>6.  El notificar a los asociados que respaldan la multa<br>7.  El sistema guarda la multa y queda pendiente de hasta que los asociados respaldantes la acepten<br>8.  Una vez la multa es aceptada por los asociados respaldantes, el sistema notifica al fiscal que hay una multa por reportar a la junta<br>9.  Cuando la multa ha sido reportada en junta, el sistema notifica al asociado multado<br>10.  La multa se documenta en el sistema
|*Flujos alternos*|0.  Uno de los asociados respaldantes no aprueba la multa<br>El sistema notifica al los asociados involucrados que la multa no ha sido aprobada<hr>1.  La junta no aprueba la multa<br>El sistema notifica al los asociados involucrados que la multa no ha sido aprobada
