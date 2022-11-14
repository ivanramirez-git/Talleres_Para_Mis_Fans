# Crear tabla de cobros de cuotas a los asociados

Permite que el tesorero cree una tabla de cobros de cuotas a los asociados, estos recibiran una notificacion y podran ver el valor de la cuota y los detalles que componen el valor de la cuota

## Precondiciones

* Deben existir asociados activos con fechas de ingreso
* Debe existir un tesorero activo
* Debe existir una sede

## Postcondiciones

* El sistema crea una tabla de cobros de cuotas a los asociados
* El sistema notifica a los asociados con el valor de la cuota y los detalles que componen el valor de la cuota

## Actores

* Tesorero
* Sistema
* Asociado

## Flujo principal

0. El tesorero ingresa a la vista de cuotas
1. El tesorero selecciona la opción de crear tabla de cobros de cuotas
2. El sistema le envia a la vista de creación de tabla de cobros de cuotas, donde estan todos los datos precargados de los asociados
3. El tesorero ingresa los datos adicionales de la tabla de cobros de cuotas
4. El tesorero publica la tabla de cobros de cuotas
5. El sistema notifica a los asociados con el valor de la cuota y los detalles que componen el valor de la cuota

## Flujos alternos

### 0.  Flujo alterno

0. No hay asociados activos con fechas de ingreso
1. El sistema muestra un mensaje de que no hay asociados activos con fechas de ingreso

### 1.  Flujo alterno

0. No hay una sede
1. El sistema muestra un mensaje de que no hay una sede

