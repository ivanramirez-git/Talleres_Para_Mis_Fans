|# Requerimiento|40 |
|-|-|
| *Nombre*|Asignación de permisos a roles
| *Descripción*| Permite que el administrador asigne permisos a roles |
|*Actores*| - Administrador<br> - Sistema
|*Precondiciones*| - Debe existir un administrador activo<br> - Debe existir un rol<br> - Deben existir permisos
|*Postcondiciones*| - El administrador asigna permisos a un rol
|*Flujo principal*|0.  El administrador ingresa a la vista de roles<br>1.  El administrador selecciona la opción de asignar permisos a un rol<br>2.  El sistema le envia a la vista de asignación de permisos a roles<br>3.  El administrador ingresa el nombre del rol<br>4.  El administrador selecciona los permisos<br>5.  El sistema guarda los permisos<br>6.  El sistema le envia a la vista de roles<br>7.  El administrador ve los permisos asignados
|*Flujos alternos*|0.  0. El rol no existe<br>1. El sistema muestra un mensaje de que el rol no existe
