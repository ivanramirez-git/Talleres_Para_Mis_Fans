|# Requerimiento|1 |
|-|-|
| *Nombre*|Login de usuario
| *Descripción*| Permite a un usuario ingresar en el sistema |
|*Actores*| - Usuario<br> - Sistema
|*Precondiciones*| - El usuario debe existir en el sistema<br> - El usuario debe estar activo<br> - El usuario debe haber introducido correctamente su contraseña<br> - El usuario debe estar aprobado por el administrador
|*Postcondiciones*| - El usuario queda logueado en el sistema<br> - El usuario queda registrado en la sesión actual
|*Flujo principal*|0.  El usuario introduce su nombre de usuario y contraseña<br>1.  El sistema valida los datos<br>2.  El sistema registra al usuario en la sesión actual<br>3.  El sistema muestra la página principal del usuario
|*Flujos alternos*|0. <br> 0. El usuario no introduce sus datos correctamente<br>1. El sistema muestra un mensaje de error<hr>1. <br> 0. El usuario no está activo<br>1. El sistema muestra un mensaje de error<hr>2. <br> 0. El usuario no está aprobado por el administrador<br>1. El sistema muestra un mensaje de error

Tabla #. Caso de uso "Login de usuario"
