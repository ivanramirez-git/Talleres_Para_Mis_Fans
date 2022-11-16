|# Requerimiento|39 |
|-|-|
| *Nombre*|Eliminación de roles
| *Descripción*| Permite que el administrador elimine roles |
|*Actores*| - Administrador<br> - Sistema
|*Precondiciones*| - Debe existir un administrador activo<br> - Debe existir un rol<br> - El rol no debe tener un cargo activo
|*Postcondiciones*| - El administrador elimina un rol
|*Flujo principal*|0.  El administrador ingresa a la vista de roles<br>1.  El administrador selecciona la opción de eliminar un rol<br>2.  El sistema le envia a la vista de eliminación de roles<br>3.  El administrador ingresa el nombre del rol<br>4.  El sistema elimina el rol<br>5.  El sistema le envia a la vista de roles<br>6.  El administrador ve el rol eliminado
|*Flujos alternos*|0. <br> 0. El rol no existe<br>1. El sistema muestra un mensaje de que el rol no existe
