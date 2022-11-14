# Pedir un extra de alimentación o lavado de ropa

Permite que un asociado solicite un extra de alimentación o lavado de ropa

## Precondiciones

* El asociado debe existir en el sistema

## Postcondiciones

* El sistema guarda la solicitud de extra

## Actores

* Asociado
* Sistema
* Administrador

## Flujo principal

0. El asociado inicializa la solicitud de extra
1. El asociado selecciona el tipo de extra
2. El asociado selecciona la fecha del extra
3. El administrador es notificado de la solicitud de extra
4. El administrador aprueba la solicitud de extra
5. El sistema guarda la solicitud de extra
6. El sistema notifica al asociado que su solicitud ha sido aprobada

## Flujos alternos

### 0.  Flujo alterno

0. El administrador no aprueba la solicitud de extra
1. El sistema notifica al asociado que su solicitud ha sido rechazada

### 1.  Flujo alterno

0. El administrador no responde a la solicitud de extra
1. El sistema notifica al asociado que su solicitud ha no ha sido verificada por lo tanto no ha sido aprobada

