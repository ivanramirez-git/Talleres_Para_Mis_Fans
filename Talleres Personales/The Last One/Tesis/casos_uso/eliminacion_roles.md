# Eliminación de roles

Permite que el administrador elimine roles

## Precondiciones

* Debe existir un administrador activo
* Debe existir un rol
* El rol no debe tener un cargo activo

## Postcondiciones

* El administrador elimina un rol

## Actores

* Administrador
* Sistema

## Flujo principal

0. El administrador ingresa a la vista de roles
1. El administrador selecciona la opción de eliminar un rol
2. El sistema le envia a la vista de eliminación de roles
3. El administrador ingresa el nombre del rol
4. El sistema elimina el rol
5. El sistema le envia a la vista de roles
6. El administrador ve el rol eliminado

## Flujos alternos

### 0.  Flujo alterno

0. El rol no existe
1. El sistema muestra un mensaje de que el rol no existe

