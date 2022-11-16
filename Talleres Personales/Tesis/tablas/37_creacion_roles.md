|# Requerimiento|37 |
|-|-|
| *Nombre*|Creación de roles
| *Descripción*| Permite que el administrador cree roles |
|*Actores*| - Administrador<br> - Sistema
|*Precondiciones*| - Debe existir un administrador activo
|*Postcondiciones*| - El administrador crea un rol
|*Flujo principal*|0.  El administrador ingresa a la vista de roles<br>1.  El administrador selecciona la opción de crear un rol<br>2.  El sistema le envia a la vista de creación de roles<br>3.  El administrador ingresa el nombre del rol<br>4.  El administrador indica las autorizaciones del rol<br>5.  El administrador indica las restricciones del rol<br>6.  El sistema guarda el rol<br>7.  El sistema le envia a la vista de roles<br>8.  El administrador ve el rol creado
|*Flujos alternos*|0. <br> 0. El rol ya existe<br>1. El sistema muestra un mensaje de que el rol ya existe
