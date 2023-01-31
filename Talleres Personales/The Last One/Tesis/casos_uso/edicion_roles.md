# Edición de roles

Permite que el administrador edite roles

## Precondiciones

* Debe existir un administrador activo
* Debe existir un rol

## Postcondiciones

* El administrador edita un rol

## Actores

* Administrador
* Sistema

## Flujo principal

0. El administrador ingresa a la vista de roles
1. El administrador selecciona la opción de editar un rol
2. El sistema le envia a la vista de edición de roles
3. El administrador ingresa el nombre del rol
4. El administrador indica las autorizaciones del rol
5. El administrador indica las restricciones del rol
6. El sistema guarda el rol
7. El sistema le envia a la vista de roles
8. El administrador ve el rol editado

## Flujos alternos

### 0.  Flujo alterno

0. El rol no existe
1. El sistema muestra un mensaje de que el rol no existe

