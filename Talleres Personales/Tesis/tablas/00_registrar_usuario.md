|# Requerimiento|0 |
|-|-|
| *Nombre*|Registro de usuario
| *Descripción*| Permite registrar un usuario en el sistema |
|*Actores*| - Usuario<br> - Administrador<br> - Sistema
|*Precondiciones*| - El usuario no debe existir en el sistema
|*Postcondiciones*| - El usuario debe existir en el sistema
|*Flujo principal*|0.  El usuario introduce sus datos<br>1.  El sistema valida los datos<br>2.  El sistema registra al usuario como pendiente de activación<br>3.  El sistema envía un correo electrónico al usuario con un enlace de activación<br>4.  El usuario activa su cuenta<br>5.  El sistema avisa al administrador que hay una cuenta pendiente para su aprobación<br>6.  El administrador aprueba la cuenta<br>7.  El sistema avisa al usuario que su cuenta ha sido aprobada<br>8.  El usuario queda registrado en el sistema
|*Flujos alternos*|0.  0. El usuario no introduce sus datos correctamente<br>1. El sistema muestra un mensaje de error<hr>1.  0. El usuario no activa su cuenta en el plazo establecido<br>1. El sistema elimina la cuenta del usuario<hr>2.  0. El administrador no aprueba la cuenta del usuario<br>1. El sistema avisa al usuario que su cuenta no ha sido aprobada<br>2. El sistema elimina la cuenta del usuario<hr>3.  0. El usuario ya existe en el sistema<br>1. El sistema muestra un mensaje de error en el formulario
