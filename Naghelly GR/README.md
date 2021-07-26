Diseñar e implementar archivos binarios:
Se requiere un registro de clientes. De cada cliente se tienen datos personales entre los que incluye una clave
alfanumérica (puede ser la curp), nombre completo, correo electrónico, fecha de nacimiento, teléfono, crédito
máximo otorgado, saldo (deuda actual). Se debe incluir dos datos adicionales que no sean caracteres, además
del campo para el borrado lógico.
Se debe disponer de un menú que permita:
- Agregar un cliente con todos sus datos. No debe permitir dos clientes con la misma clave. Se debe incluir la
validación de al menos dos campos al momento de capturar.
- Eliminar un cliente de forma física (borrar el contacto físicamente del archivo) y sólo ocultarlo (borrado lógico).
- Modificar el registro de información de un cliente. Puede ser en varias opciones con sólo dato o todos excepto la
clave.
- Consultar un cliente por nombre. Cada consulta debe mostrar todos los datos del cliente y si no existe o está borrado
se debe indicar.
- Consultar un cliente por clave. Cada consulta debe mostrar todos los datos del cliente y si no existe o está borrado
se debe indicar.
- Consultar los clientes que cumplan años en el mes introducido por el usuario.
- Ver todos (clientes no eliminados lógicamente).
El archivo de clientes debe estar ordenado por la clave. No se puede tener ni arreglos, ni archivos auxiliares para
realizar el ordenamiento, ni la eliminación.
Toda la información del cliente debe validarse, al menos debe cumplir las siguientes reglas:
- No se permiten clientes repetidos.
- Las fechas de nacimiento deben ser una fecha válida. Uno de los atributos propuestos debe validarse.
