# Registro de usuario

Permite registrar un usuario en el sistema

## Precondiciones

* El usuario no debe existir en el sistema

## Postcondiciones

* El usuario debe existir en el sistema

## Actores

* Usuario
* Administrador
* Sistema

## Flujo principal

0. El usuario introduce sus datos
1. El sistema valida los datos
2. El sistema registra al usuario como pendiente de activación
3. El sistema envía un correo electrónico al usuario con un enlace de activación
4. El usuario activa su cuenta
5. El sistema avisa al administrador que hay una cuenta pendiente para su aprobación
6. El administrador aprueba la cuenta
7. El sistema avisa al usuario que su cuenta ha sido aprobada
8. El usuario queda registrado en el sistema

## Flujos alternos

### 0.  Flujo alterno

0. El usuario no introduce sus datos correctamente
1. El sistema muestra un mensaje de error

### 1.  Flujo alterno

0. El usuario no activa su cuenta en el plazo establecido
1. El sistema elimina la cuenta del usuario

### 2.  Flujo alterno

0. El administrador no aprueba la cuenta del usuario
1. El sistema avisa al usuario que su cuenta no ha sido aprobada
2. El sistema elimina la cuenta del usuario

### 3.  Flujo alterno

0. El usuario ya existe en el sistema
1. El sistema muestra un mensaje de error en el formulario

