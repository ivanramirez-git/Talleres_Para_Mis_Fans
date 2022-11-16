|# Requerimiento|2 |
|-|-|
| *Nombre*|Logout de usuario
| *Descripción*| Permite a un usuario salir del sistema |
|*Actores*| - Usuario<br> - Sistema
|*Precondiciones*| - El usuario debe estar logueado en el sistema
|*Postcondiciones*| - El usuario queda deslogueado del sistema<br> - El usuario deja de estar registrado en la sesión actual
|*Flujo principal*|0.  El usuario pulsa el botón de logout<br>1.  El sistema elimina al usuario de la sesión actual<br>2.  El sistema muestra la página de login
|*Flujos alternos*|0.  0. El usuario no está logueado en el sistema<br>1. El sistema muestra un mensaje de error
