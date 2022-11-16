<!--
2.2 Funciones del producto
2.3 Características del usuario
2.4 Restricciones
2.5 Modelo de dominio
2.6 Suposiciones y dependencias
2.7 distribución de requerimientos
 -->

# 2.2 Funciones del producto
<!-- Esta sección es una descripción general de las funciones que debe cumplir el producto
de software [4]. El listado de funciones debe proveer la especificación clara de cada
una, con el fin de asegurar que cualquier persona que lo lea, ya sea el cliente o
desarrolladores puedan entender. Es aconsejable utilizar diagramas, gráficas,
entre otros medios visuales que permitan comprender la relación lógica entre las
funciones. Por ejemplo, un diagrama de casos de uso con su respectiva documentación.
Un ejemplo claro son los Casos de Uso o User Stories que seguramente deberán ser
referenciados. -->

## Funciones principales

Las funciones principales del sistema son las siguientes:

- El sistema debe permitir gestionar cuentas de usuario con distintos roles. (Caso de uso)
    - Funciones de registro
    - Funciones de login
    - Funciones de logout

- El sistema debe permitir gestionar todo el ciclo de vida de los oficios y tareas asignadas a los asociados.
    - Funciones de asignación de tareas
    - Funciones de mostrar tareas a traves de calendario y notificaciones
    - Funciones de revision de tareas asignadas
    - Funciones de documentación de tareas asignadas
    - Funciones para consultar las instrucciones de las tareas
    - Funciones para calificación y sugerencias a cerca de las tareas realizadas

- El sistema debe permitir gestionar todo el ciclo de vida de los extras de alimentación o lavado de ropa.
    - Funciones de asignación de extras
    - Funciones de aprobación de extras
    - Funciones de documentación de extras

- El sistema debe permitir gestionar todo el ciclo de vida de las multas o batidas.
    - Funciones de creación de multas o batidas
    - Funciones de asignación de multas
    - Funciones de aprobación de multas
    - Funciones de publicación de multas
    - Funciones de documentación de multas, preavisos, llamados de atención, memorandos y demás sanciones
    - Funciones de pago de multas

- El sistema debe permitir gestionar todo el ciclo de vida de las actas de reuniones.
    - Funciones de construcción de actas, (editor de texto dentro del sistema con formatos de actas predefinidos)
    - Funciones de publicación de actas

- El sistema debe permitir gestionar todo el ciclo de vida de los informes por cargos.
    - Funciones de creación de informes (manejo de facturas, editor especializado para informes)
    - Funciones de revision de informes
    - Funciones de publicación de informes

- El sistema debe permitir gestionar todo el ciclo de vida de los reglamentos por sedes y estatutos de la organización.
    - Funciones de creación y edición de reglamentos
    - Funciones de revision de reglamentos
    - Funciones de publicación de reglamentos
    - Funciones de búsqueda de artículos de reglamentos

- El sistema debe permitir gestionar todo el ciclo de vida de cuotas y cuentas de cobro a los asociados.
    - Funciones de creación de cuotas
    - Funciones de publicación de cuentas de cobro
    - Funciones de funciones de recibo de pagos
    - Funciones de notificación de saldos pendientes

- El sistema debe garantizar el acceso a toda la información relevante para cada individuo de la organización.
    - Funciones de consulta de información de usuarios
    - Funciones de consulta de información de tareas
    - Funciones de consulta de información de extras
    - Funciones de consulta de información de multas
    - Funciones de consulta de información de actas
    - Funciones de consulta de información de informes
    - Funciones de consulta de información de reglamentos
    - Funciones de consulta de información de cuotas

- El sistema debe permitir gestionar todos los roles de la organización
    - Funciones de creación de roles
    - Funciones de edición de roles
    - Funciones de eliminación de roles
    - Funciones para asignar permisos a los roles autorizaciones y restricciones, todos deben funcionar con el mismo usuario

## Quien lo va leer?

- Cliente: Miembros de la organización que serán el cliente y nos darán una retroalimentación de como se sienten con las funcionalidades  propuestas y si se sienten satisfechos con el producto final.
- Desarrolladores: Ingenieros de software que están encargados de desarrollar el producto y que se encargaran de la implementación de las funcionalidades propuestas.
- Stakeholders: Director del proyecto, empleados ded la organización, ex asociados, etc.

## Medios gráficos

- Diagrama de casos de uso
- Matriz de relaciones

## Especificación clara

- Documentación de los diagramas y medios gráficos


# 2.3 Características del usuario

<!-- Debe Identificar las diferentes clases de usuarios que usted prevea utilizaran la
aplicación. Las diferentes clases de usuarios pueden ser diferenciadas basados en la
frecuencia del uso, los diferentes roles, la experiencia técnica, los niveles de seguridad o
de privilegios, el nivel de estudios, o de experiencia.
Además en general debe describir las características pertinentes de cada clase de
usuario, las cuales se ilustran en la ilustración 8 y luego se describen en la Tabla 4 [1].
Usualmente este elemento también se tienen en cuenta en los documentos de Casos de
uso, por tanto basta con referenciar al documento que lo contiene. -->

## Usuarios

<!-- Tabla con 5 filas
Fila1: Encabezado col1: Características del Usuario, col2: Descripción
Fila2: Nivel de Seguridad o de Privilegios, Listar todos los privilegios o funcionalidades a las que tiene acceso el usuario.
Fila3: Roles, Los diferentes roles que puede desempeñar el usuario, como por ejemplo: jugador, visitante, administrador, etc. Especificando las características especificas de cada uno de los roles.
Fila4: Nivel de Estudios o Experiencia Técnica, El nivel de estudio o de experiencia técnica relacionada con el uso de la aplicación.
Fila5: Frecuencia de Uso, Periodicidad con la que el usuario utiliza la aplicación.
-->
A continuación se detallan las características de los usuarios del sistema a través de tablas que especifican las características de los usuarios.

- Asociado:

|Características del Usuario|Descripción|
|-|-|
|Nivel de Seguridad o de Privilegios|Los asociados pueden ver las tareas asignadas, los extras de alimentación y lavado de ropa, las multas y las actas de reuniones.|
|Roles|El rol de los asociados es el mas menos funcionalidades activas tendrá, solo tienen oportunidad de gestionar datos que a personales que le correspondan, todo miembro de la organización es asociado.|
|Nivel de Estudios o Experiencia Técnica|Los asociados deben ser admitidos para poder hacer uso del aplicativo por medio de entrevista, estarán en un periodo de ratificación por 3 meses y una vez ratificados su perfil pasara a ser el de un asociado ratificado, que tendrá los mismos privilegios que un asociado en via de ratificación en el sistema.|
|Frecuencia de Uso|Los asociados serán los que mas usen el aplicativo, casi a diario, para consultar el calendario, recibir notificaciones de tareas pendientes, revisar su saldo actual, pedir extras, entre otros.|

- Miembro de junta directiva:

|Características del Usuario|Descripción|
|-|-|
|Nivel de Seguridad o de Privilegios|Los miembros de la junta directiva asignar tareas, aprobar extras, aprobar multas, realizar actas de reuniones, actualizar tabla de cobro, entre otros.|
|Roles|El rol de los miembros de la junta directiva es el mas funcionalidades activas tendrá, tienen oportunidad de gestionar datos de toda la organización.|
|Nivel de Estudios o Experiencia Técnica|Los miembros de la junta directiva deben ser admitidos elegidos en asamblea seccional, una vez son miembros de la junta se les activara las funciones adicionales a su perfil de junta directiva.|
|Frecuencia de Uso|Los miembros de la junta directiva usaran el aplicativo como cualquier asociado, pero las funcionalidades adicionales serán menos frecuentes, una vez por semana o cada 15 días.|

- Administrador:

|Características del Usuario|Descripción|
|-|-|
|Nivel de Seguridad o de Privilegios|El administrador tendrá control total del sistema, podrá crear, editar y eliminar cualquier tipo de información.|
|Roles|El rol de los administradores es exclusivo para controlar data en casos de emergencia.|
|Nivel de Estudios o Experiencia Técnica|Los administradores ya están previamente definidos por el equipo de desarrollo, solo ellos tendrán acceso a las funcionalidades y datos del sistema.|
|Frecuencia de Uso|Los administradores usaran el aplicativo solo en caso de emergencia, para corregir errores o para actualizar datos, una vez por trimestre.|

# 2.4 Restricciones

<!-- Las restricciones son las limitaciones que se deben tener en cuenta para el desarrollo del sistema, estas pueden ser de tipo tecnológico, de tiempo, de personal, de recursos, etc. -->

## Restricciones generales

<!-- Como por ejemplo, las reglas que rigen la aplicación, la tolerancia
a fallos, los idiomas -->
- El aplicativo estará restringido a los reglamentos y estatutos de la organización.
- El idioma del aplicativo sera el español ya que esta bastante claro los usuarios que lo usaran.

## Restricciones de software

- Una restricción sera el nivel de parametrization que le podamos dar al ERP.

## Restricciones de hardware

- En dispositivos con una api de Android menor a la 28 no podrá ser instalado el aplicativo.

## Otras restricciones

- Requisitos de confiabilidad:
- Tolerancia a fallos de la aplicación:
- Consideraciones de seguridad:
- Limitaciones de hardware:
- El funcionamiento paralelo:
- Las políticas corporativas o reguladoras:
- Requerimientos del lenguaje:
- Interfaces a otras aplicaciones:
- Las funciones de auditoria:
- Las funciones de control:
- Los protocolos señalados:
- Tecnologías y herramientas especificas:
- Protocolos de comunicación:
- Convenciones del diseño o estándares de programación:

# 2.5 Modelo de dominio

Definiciones mas importantes del modelo de domino:

# 2.6 Suposiciones y dependencias

<!-- Lista de factores que afectan los requerimientos:
Suposiciones:
Se deben listar todas aquellas suposiciones que puedan llegar a afectar los
requerimientos indicados en la sección 3. Estos pueden incluir componentes comerciales
o de terceras personas que usted planea utilizar. Tenga en cuenta que el proyecto
podría afectarse si estas suposiciones son incorrectas, no se comparten, o se cambian
[1] -->


# 2.7 Distribución de Requerimientos












<!-- Introducción 

Propósito del SRS

En esta sección se describe la intención con la que se realiza el documento, es decir, se deben exponer las razones por las que es importante, identificando el producto de software al cual se le van a especificar los requerimientos, la audiencia que está interesada en el contenido y el alcance del documento, es decir, especificar el alcance del producto que será descrito [1]. En la ilustración 1 se resume el contenido de esta sección. 

-->
# Introducción

El propósito de este documento es describir los requerimientos funcionales y no funcionales del sistema de información, aplicaciones web y moviles Aucol App.
Aucol es una organización sin fines de lucro, que tiene como objetivo principal la prestación de servicios de alojamiento a sus asociados, para esto cuenta con una junta directiva que se encarga de administrar la organización.

## Propósito del SRS

El proposito de este documento es dar a conocer las especificaciones de los requerimientos de software para el sistema de informacion y aplicaciones moviles Aucol App. Nuestra intención es que este documento sea de utilidad para los desarrolladores del sistema, para los usuarios y para los administradores del sistema, explicaremos las funcionalidades relevantes del sistema, las restricciones y los supuestos que se tomaron para el desarrollo del sistema, asi como los roles que existen en el sistema y las responsabilidades de cada uno de ellos.



<!-- 
 

Ilustración 1: Propósito 

Alcance 

Se describe el alcance del producto, es decir, la sección contiene una breve descripción del producto de software sobre el cual se realiza el SRS, indicando su nombre,  las funcionalidades que incluirá y su utilidad (objetivos, beneficios). También puede ser incluida la relación entre el producto y las metas corporativas o estrategia de negocio resaltando la importancia que tiene para la organización [1]. 

Forma 

Ilustración 2: Alcance 

 


 -->



## Alcance

Nuestro software estara dividido en 3 grandes partes, la primera es la aplicacion movil que sera utilizada por los usuarios o asociados en general, y la segunda es la aplicacion web que sera utilizada por los administradores del sistema o miembros de la junta administrativa ya sea seccional o general. La aplicacion movil sera utilizada por los usuarios para poder realizar consultas de la informacion que proveen los administradores, ademas podran pedir extras, ver sus cuentas de cobro y gestionar sus perfiles. Como segunda parte una aplicacion web sera utilizada por los administradores para facilitar la realizacion de sus tareas, podran gestionar los usuarios, los perfiles, las cuentas de cobro, los extras, las tareas que seran asignadas a los usuarios, asi como la realizacion de informes y redaccion de documentos. Estas dos primeras partes funcionaran como clientes de un servidor que sera el encargado de almacenar toda la informacion y proveerla a los clientes, este servidor sera el encargado de realizar las validaciones de los datos, asi como de realizar las consultas a la base de datos y proveer la informacion a los clientes siendo esta la tercera parte del sistema. Tambien administrara un sustema de almacenamiento de archivos que sera utilizado para almacenar los archivos que se suban a la aplicacion, como por ejemplo las imagenes de los perfiles de los usuarios, los archivos de las cuentas de cobro, los archivos de actas y demas documentos relevantes para la organizacion.

El alcance del sistema se puede resumir en las siguientes caracteristicas:

- El sistema debe permitir a los usuarios consultar la informacion que provean los administradores.
- El sistema debe permitir a los usuarios gestionar sus perfiles.
- El sistema debe permitir a los usuarios gestionar sus cuentas de cobro.
- El sistema debe permitir a los usuarios gestionar sus extras.
- El sistema debe permitir a los administradores gestionar los usuarios.


<!-- 
Definiciones, Acrónimos, y Abreviaciones 

Se deben especificar los términos clave que serán utilizados en el documento con el fin de aclarar el contenido y asegurar su óptimo entendimiento. Se recomienda reutilizar los especificados en el documento SPMP y formar un glosario general de términos. En la tabla 2 se presentan algunos ejemplos de acrónimos para el documento SRS. 

API 

Aplication  Programming Interface 

CRUD 

Create, Retrieve, Update, Delete 

DBMS 

Data Base Management System 

GNU 

Es un acrónimo recursivo que significa "GNU No es Unix" 

GNU GPL 

General Public License o licencia pública general 

JDBC 

Java DataBase Connectivity 

JVM 

Java Virtual Machine 

LAN 

Local Area Network 

PHP 

Es un acrónimo recursivo “Hypertext Preprocessor” 

RFC 

Request For Comments 

SDD 

Software Design Description 

SQL 

Structured Query Language 

SRS 

Software Requirement Specification 

WLAN 

Wireless Local Area Network 

WPA 

World Poker Association 

Tabla 2: Acrónimos 

Referencias 

Indique aquí todas las referencias bibliográficas utilizadas en el documento. Utilice formato IEEE o APA para definirlas. Para administrar automáticamente las referencias, se recomienda el uso de la herramienta Zotero (www.zotero.org). 
 -->
## Definiciones, Acrónimos, y Abreviaciones

| Acrónimo | Definición |
| :--- | :--- |
| API | Interface de programación de aplicaciones |
| CRUD | Crear, Recuperar, Actualizar, Eliminar |
| SRC | Especificación de Requerimientos de Software |



<!-- 

Apreciación Global  

Esta sección debe tener una descripción general del contenido del documento, especificando su organización o distribución. Es una guía para el lector que le permitirá estructurar la información que encontrará en del documento. 

 

Forma 

Ilustración 3: Apreciación Global 






Descripción Global 

En general en esta sección se describe los factores generales que afectan al producto y sus requerimientos, es importante aclarar que en esta sección NO se especifican formalmente los requerimientos, es solo información de fondo que brinda a los lectores una descripción de todo el sistema.Esta en lenguaje de Usuario. Los elementos presentados en esta sección se asociaran en la seccion 3 con Requerimientos Especificos.  -->