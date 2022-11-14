# Asignación de permisos a roles

Permite que el administrador asigne permisos a roles

## Precondiciones

* Debe existir un administrador activo
* Debe existir un rol
* Deben existir permisos

## Postcondiciones

* El administrador asigna permisos a un rol

## Actores

* Administrador
* Sistema

## Flujo principal

0. El administrador ingresa a la vista de roles
1. El administrador selecciona la opción de asignar permisos a un rol
2. El sistema le envia a la vista de asignación de permisos a roles
3. El administrador ingresa el nombre del rol
4. El administrador selecciona los permisos
5. El sistema guarda los permisos
6. El sistema le envia a la vista de roles
7. El administrador ve los permisos asignados

## Flujos alternos

### 0.  Flujo alterno

0. El rol no existe
1. El sistema muestra un mensaje de que el rol no existe

