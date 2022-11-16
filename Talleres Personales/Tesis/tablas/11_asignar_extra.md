|# Requerimiento|11 |
|-|-|
| *Nombre*|Pedir un extra de alimentación o lavado de ropa
| *Descripción*| Permite que un asociado solicite un extra de alimentación o lavado de ropa |
|*Actores*| - Asociado<br> - Sistema<br> - Administrador
|*Precondiciones*| - El asociado debe existir en el sistema
|*Postcondiciones*| - El sistema guarda la solicitud de extra
|*Flujo principal*|0.  El asociado inicializa la solicitud de extra<br>1.  El asociado selecciona el tipo de extra<br>2.  El asociado selecciona la fecha del extra<br>3.  El administrador es notificado de la solicitud de extra<br>4.  El administrador aprueba la solicitud de extra<br>5.  El sistema guarda la solicitud de extra<br>6.  El sistema notifica al asociado que su solicitud ha sido aprobada
|*Flujos alternos*|0. <br> 0. El administrador no aprueba la solicitud de extra<br>1. El sistema notifica al asociado que su solicitud ha sido rechazada<hr>1. <br> 0. El administrador no responde a la solicitud de extra<br>1. El sistema notifica al asociado que su solicitud ha no ha sido verificada por lo tanto no ha sido aprobada
