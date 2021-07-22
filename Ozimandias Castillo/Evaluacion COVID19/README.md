# Enunciado

## Considere lo siguiente.

Se contará con una Clase denominada ClienteSorter que tendrá inicialmente un atributo de tipo lista de clientes, que tendrá las siguientes funciones básicas inicialmente:

OrdenarPorApellidos(tipo) -> donde tipo. es el tipo de ordenación que se desea realizar, es decir ya sea ascendentemente o descendente, de esta forma tipo sera tendra el valor de A o D en funcion al tipo de Ordenacion
OrdenarPorCI() -> Esta funcion deberá ordenar la lista de form ascendente.
OrdenarPorTemperatura()-> Esta función deberá ordenar las tempraturas de la lista de clientes de forma descendiente (Mayor a menor)
ObtenerTemperaturasElevadas(cantidad)-> esta función deberá obtener los clientes que tienen temperaturas elevadas en funcion a la cantidad que recibe como parametro
ObtenerCantidadClientes()-> debe retornar la cantidad de clientes que tiene la lista.
VectorToListCliente(vector) -> convierte un vector de clientes a una lista, esta conversion se hace sobre la lista de clase;
Se contará con una clase denominada estatica ClienteIO que tendrá como funcionamiento inicial la lectura y escritura de clientes en un archivo denominado "clientes.txt" donde se tiene los atributos de los clientes separados con un punto y coma (;) en el siguiente orden : apellidos, nombres, ci, temperatura. Esta clase tendrá un atributo estatico denominado nombreArchivoCliente. Esta clase tnedra las siguientes funciones

leerClientes() -> retorna una lista de clientes en una estructura de tipo vector
escribirCliente(cliente) -> almacena un cliente dentro del registro de texto
clonarOrdenado(lista, nombre) -> Esta funcion debe recibir una lista y debe crear otro archivo con la misma estructura de "clientes.txt" y guardarla con el nombre dado como parametro de manera ordenada por apellido.
Debera implementar una clase denominada BancoColaControler, que tendrá la funcionalidad de ir atendiendo a los clientes que ingresarán, es decir introducirlos en una cola a aquellos clientes que no tienen ninguna sintomatología.y aquellos que no pueden ingresar, se los acomodará en otra cola siempre y cuando unicamente no cumplan con la restricción de la temperatura para ser atendidos por un personal médico.

La clase BancoColaController tendra un atributo de tipo Cola y contador de fichas acompañado las siguiente funciones:

AgregarCola(cliente) -> esta clase debe incoporar dicho cliente a la cola e incrementar el contador de atención
AtenderrCola():cliente -> Esta clase deberá sacar un cliente de la cola  e imprimir en pantalla un mensaje llamando al cliente incluyendo su número de turno y su nombre, por ejemplo (Cliente nroturno, aaaaaaaaaaa bbbbb pasar porfavor)
Debe subir unicamente los archivos de las clases BancoColaController,  ClienteIO, ClienteSorter
