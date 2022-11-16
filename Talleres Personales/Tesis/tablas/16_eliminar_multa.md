|# Requerimiento|16 |
|-|-|
| *Nombre*|Eliminar multa o batida
| *Descripción*| Permite que el administrador elimine una multa o batida |
|*Actores*| - Administrador<br> - Sistema<br> - Asociado
|*Precondiciones*| - Debe existir un asociado con multas o batidas pendientes
|*Postcondiciones*| - El sistema elimina la multa o batida<br> - El asociado multado no tendra esta multa o batida en su lista de multas o batidas pendientes
|*Flujo principal*|0.  El administrador ingresa a la vista de multas o batidas<br>1.  El administrador selecciona la multa o batida a eliminar<br>2.  El administrador confirma la eliminación de la multa o batida<br>3.  El sistema elimina la multa o batida<br>4.  El sistema notifica al asociado multado que su multa o batida ha sido eliminada
|*Flujos alternos*|0. <br> 0. No hay multas o batidas pendientes<br>1. El sistema muestra un mensaje de que no hay multas o batidas pendientes

Tabla #. Caso de uso "Eliminar multa o batida"
