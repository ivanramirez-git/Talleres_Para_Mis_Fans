|# Requerimiento|38 |
|-|-|
| *Nombre*|Edición de roles
| *Descripción*| Permite que el administrador edite roles |
|*Actores*| - Administrador<br> - Sistema
|*Precondiciones*| - Debe existir un administrador activo<br> - Debe existir un rol
|*Postcondiciones*| - El administrador edita un rol
|*Flujo principal*|0.  El administrador ingresa a la vista de roles<br>1.  El administrador selecciona la opción de editar un rol<br>2.  El sistema le envia a la vista de edición de roles<br>3.  El administrador ingresa el nombre del rol<br>4.  El administrador indica las autorizaciones del rol<br>5.  El administrador indica las restricciones del rol<br>6.  El sistema guarda el rol<br>7.  El sistema le envia a la vista de roles<br>8.  El administrador ve el rol editado
|*Flujos alternos*|0. <br> 0. El rol no existe<br>1. El sistema muestra un mensaje de que el rol no existe

Tabla #. Caso de uso "Edición de roles"
