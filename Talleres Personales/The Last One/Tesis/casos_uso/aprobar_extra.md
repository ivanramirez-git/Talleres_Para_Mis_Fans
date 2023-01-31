# Aprobar extra de alimentación o lavado de ropa

Permite que un administrador apruebe o rechace una solicitud de extra de alimentación o lavado de ropa

## Precondiciones

* El administrador debe tener una solicitud de extra pendiente

## Postcondiciones

* El sistema guarda la aprobación o rechazo de la solicitud de extra

## Actores

* Administrador
* Sistema
* Asociado

## Flujo principal

0. El administrador ingresa a la lista de solicitudes de extras pendientes
1. El administrador selecciona una solicitud de extra
2. El administrador puede ver los detalles de la solicitud de extra
3. El administrador aprueba o rechaza la solicitud de extra
4. El sistema guarda la aprobación o rechazo de la solicitud de extra
5. El sistema notifica al asociado que su solicitud ha sido aprobada o rechazada

## Flujos alternos

### 0.  Flujo alterno

0. El administrador no aprueba o rechaza la solicitud de extra
1. El sistema notifica al asociado que su solicitud ha no ha sido verificada por lo tanto no ha sido aprobada

