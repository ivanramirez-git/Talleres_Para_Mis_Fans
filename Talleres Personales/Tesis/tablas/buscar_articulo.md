|# Requerimiento|24 |
|-|-|
| *Nombre*|Buscar artículo
| *Descripción*| Permite que los asociados busquen artículos de los reglamentos |
|*Actores*| - Asociado<br> - Sistema
|*Precondiciones*| - Debe existir un asociado<br> - Debe existir un reglamento
|*Postcondiciones*| - El sistema muestra los artículos del reglamento que coincidan con la búsqueda
|*Flujo principal*|0.  El asociado ingresa a la vista de reglamentos<br>1.  El asociado selecciona la opción de buscar artículo<br>2.  El sistema le envia a la vista de búsqueda de artículos<br>3.  El asociado ingresa los datos de la búsqueda<br>4.  El sistema muestra los artículos del reglamento que coincidan con la búsqueda
|*Flujos alternos*|0.  No hay artículos que coincidan con la búsqueda<br>El sistema muestra un mensaje de que no hay artículos que coincidan con la búsqueda
