# Amazon DynamoDB

## Introducción

Amazon DynamoDB es un servicio de base de datos NoSQL de Amazon Web Services (AWS) que proporciona una alta disponibilidad y escalabilidad. DynamoDB es un servicio de base de datos de almacenamiento de clave-valor y de documentos. DynamoDB se puede utilizar para almacenar y consultar datos de forma rápida y flexible.

## Características

Amazon DynamoDB es una base de datos de clave-valor y documentos que admite tablas de prácticamente cualquier tamaño con escalado horizontal. Esto permite a DynamoDB escalarse a más de 10 billones de solicitudes al día, con picos de más de 20 millones de solicitudes por segundo, a través de petabytes de almacenamiento.


## Cuestiones a tratar
<!-- 
### Relacional/No Relacional?
### Si es NoSql, tipo de modelo de datos:Columnar, claveValor, etc?
### Soporta Transacciones ACID?
### Read Replicas?
### Write Replicas?
### Modelo de consistencia?
### Servicio Fully Managed?
### Escalabilidad?
### Disponibilidad Almacenamiento (terabytes, petabytes, exabytes)?
### Tipos de carga de trabajo que soporta o casos de uso?
### Latencia, Througput? -->

## Relacional/No Relacional?

Es un servicio de base de datos NoSQL, por lo que no es relacional. Sin embargo, es compatible con las consultas de SQL, por lo que se puede utilizar para realizar consultas de SQL a través de PartiQL (PartiQL es un lenguaje de consulta de datos de código abierto que se puede utilizar para consultar datos en DynamoDB).

## Si es NoSql, tipo de modelo de datos:Columnar, claveValor, etc?

DynamoDB admite modelos de datos de clave-valor y de documentos, gracias a lo cual dispone de un esquema flexible que permite que cada fila tenga cualquier número de columnas en un momento dado. Esto le permite adaptar fácilmente las tablas cuando cambien sus requisitos de negocio, sin tener que volver a definir el esquema de tabla como ocurre con las bases de datos relacionales.

## Soporta Transacciones ACID?

DynamoDB soporta transacciones ACID. Las transacciones ACID son una serie de operaciones que se ejecutan como una sola unidad. Las transacciones ACID se pueden utilizar para garantizar que las operaciones se ejecuten de forma segura y sin errores. Las transacciones ACID se pueden utilizar para realizar operaciones de lectura y escritura en una tabla de DynamoDB.

## Read and Write Replicas?

Las tablas globales de DynamoDB replican automáticamente sus datos en las regiones de AWS de su elección y escalan automáticamente la capacidad para acomodar sus cargas de trabajo. Con las tablas globales, las aplicaciones distribuidas de manera global pueden obtener acceso a los datos localmente en las regiones seleccionadas para disfrutar de un rendimiento de lectura y escritura de milisegundos de un solo dígito.

## Modelo de consistencia?

Cualquier cambio realizado en cualquier elemento de una réplica de tabla es replicado en todas las réplicas contenidas en la misma tabla global. En una tabla global, un elemento que acaba de ser escrito se propaga a todas las réplicas de tabla en un segundo. Además, en una tabla global cada réplica de tabla almacena el mismo grupo de elementos de datos. DynamoDB no admite la replicación parcial de únicamente algunos elementos. Si las aplicaciones actualizan el mismo elemento en diferentes regiones al mismo tiempo, pueden producirse conflictos. Para ayudar a asegurar la consistencia final, las tablas globales de DynamoDB utilizan una reconciliación “last-writer-wins” (el último en escribir gana) entre actualizaciones simultáneas, en el que DynamoDB intenta determinar la escritura más reciente. Gracias a este mecanismo de resolución de conflictos, todas las réplicas coinciden en la actualización más reciente y convergen hacia un estado en el que todas tienen datos idénticos.

## Servicio Fully Managed?

DynamoDB es un servicio totalmente administrado.

## Escalabilidad?

Para las tablas que utilizan la capacidad aprovisionada, DynamoDB ofrece escalado automático de la velocidad y el rendimiento en función de la capacidad definida previamente monitorizando el rendimiento de su aplicación. Si el tráfico de su aplicación aumenta, DynamoDB aumenta la velocidad para acomodar la carga. Si el tráfico de su aplicación disminuye, DynamoDB reduce la capacidad para que pague menos por la capacidad no utilizada.

## Disponibilidad Almacenamiento (terabytes, petabytes, exabytes)?

DynamoDB admite petabytes de almacenamiento, al ser un servicio totalmente administrado, no es necesario preocuparse por la gestión de la infraestructura ya que todo el almacenamiento se gestiona de forma automática y transparente.

## Tipos de carga de trabajo que soporta o casos de uso?

Las cargas de trabajo que soporta son las siguientes:

* Aplicaciones web y móviles
* Aplicaciones de IoT
* Aplicaciones de juegos
* Aplicaciones de análisis de datos
* Aplicaciones de procesamiento de datos en tiempo real
* Aplicaciones de procesamiento de datos de streaming
* Aplicaciones de procesamiento de datos de batch
* Aplicaciones de procesamiento de datos de machine learning

## Latencia, Througput?

Rendimiento
Las tablas globales le permiten que lea y escriba sus datos localmente al ofrecer una latencia de milisegundos de un solo dígito para su aplicación distribuida globalmente a cualquier escala.