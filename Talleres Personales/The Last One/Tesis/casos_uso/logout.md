# Logout de usuario

Permite a un usuario salir del sistema

## Precondiciones

* El usuario debe estar logueado en el sistema

## Postcondiciones

* El usuario queda deslogueado del sistema
* El usuario deja de estar registrado en la sesión actual

## Actores

* Usuario
* Sistema

## Flujo principal

0. El usuario pulsa el botón de logout
1. El sistema elimina al usuario de la sesión actual
2. El sistema muestra la página de login

## Flujos alternos

### 0.  Flujo alterno

0. El usuario no está logueado en el sistema
1. El sistema muestra un mensaje de error

