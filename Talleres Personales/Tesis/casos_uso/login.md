# Login de usuario

Permite a un usuario ingresar en el sistema

## Precondiciones

* El usuario debe existir en el sistema
* El usuario debe estar activo
* El usuario debe haber introducido correctamente su contraseña
* El usuario debe estar aprobado por el administrador

## Postcondiciones

* El usuario queda logueado en el sistema
* El usuario queda registrado en la sesión actual

## Actores

* Usuario
* Sistema

## Flujo principal

0. El usuario introduce su nombre de usuario y contraseña
1. El sistema valida los datos
2. El sistema registra al usuario en la sesión actual
3. El sistema muestra la página principal del usuario

## Flujos alternos

### 0.  Flujo alterno

0. El usuario no introduce sus datos correctamente
1. El sistema muestra un mensaje de error

### 1.  Flujo alterno

0. El usuario no está activo
1. El sistema muestra un mensaje de error

### 2.  Flujo alterno

0. El usuario no está aprobado por el administrador
1. El sistema muestra un mensaje de error

