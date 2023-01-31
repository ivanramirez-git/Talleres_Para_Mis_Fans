# Crear multa o batida

Permite que un grupo de 3 asociados o más cree una multa o batida

## Precondiciones

* El asociado a multar debe existir en el sistema
* El asociado a que crea la multa debe existir en el sistema
* Los 2 asociados que respaldan la multa deben existir en el sistema

## Postcondiciones

* El sistema guarda la multa y la deja pendiente de aprobación

## Actores

* Asociado
* Sistema

## Flujo principal

0. El asociado principal inicializa la creación de la multa
1. El asociado principal selecciona el asociado o asociados a multar
2. Indicar si la multa es a un invitado del asociado a multar
3. El asociado principal selecciona el tipo de multa
4. El asociado principal rellena el formulario de la multa
5. El asociado principal selecciona los asociados que respaldan la multa
6. El notificar a los asociados que respaldan la multa
7. El sistema guarda la multa y queda pendiente de hasta que los asociados respaldantes la acepten
8. Una vez la multa es aceptada por los asociados respaldantes, el sistema notifica al fiscal que hay una multa por reportar a la junta
9. Cuando la multa ha sido reportada en junta, el sistema notifica al asociado multado
10. La multa se documenta en el sistema

## Flujos alternos

### 0.  Flujo alterno

0. Uno de los asociados respaldantes no aprueba la multa
1. El sistema notifica al los asociados involucrados que la multa no ha sido aprobada

### 1.  Flujo alterno

0. La junta no aprueba la multa
1. El sistema notifica al los asociados involucrados que la multa no ha sido aprobada

