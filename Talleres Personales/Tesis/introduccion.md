



<!-- Introducción 

Propósito del SRS

En esta sección se describe la intención con la que se realiza el documento, es decir, se deben exponer las razones por las que es importante, identificando el producto de software al cual se le van a especificar los requerimientos, la audiencia que está interesada en el contenido y el alcance del documento, es decir, especificar el alcance del producto que será descrito [1]. En la ilustración 1 se resume el contenido de esta sección. 

-->
# Introducción

Aucol es una organización sin fines de lucro, que tiene como objetivo principal la prestación de servicios de alojamiento a sus asociados, para esto cuenta con una junta directiva que se encarga de administrar la organización.

## Propósito del SRS

A grandes rasgos en este SRS describiremos un vistaso general del sistema, las funcionalidades que tendra el sistema, los requerimientos funcionales y no funcionales, asi como los supuestos y restricciones que se tomaran en cuenta para el desarrollo del sistema.

Nuestra intención es que este documento sea de utilidad para los desarrolladores del sistema, para los usuarios y para los administradores del sistema, decribiremos tambien los roles que existen en el sistema y las responsabilidades de cada uno de ellos. Tambien las partes del sistema que se desarrollaran y algunas tecnologias que se usaran para el desarrollo del sistema.



<!-- 
 

Ilustración 1: Propósito 

Alcance 

Se describe el alcance del producto, es decir, la sección contiene una breve descripción del producto de software sobre el cual se realiza el SRS, indicando su nombre,  las funcionalidades que incluirá y su utilidad (objetivos, beneficios). También puede ser incluida la relación entre el producto y las metas corporativas o estrategia de negocio resaltando la importancia que tiene para la organización [1]. 

Forma 

Ilustración 2: Alcance 

 


 -->



## Alcance

Nuestro software estara dividido en 3 grandes partes, la primera es la aplicacion movil que sera utilizada por los usuarios o asociados en general, y la segunda es la aplicacion web que sera utilizada por los administradores del sistema o miembros de la junta administrativa ya sea seccional o general. La aplicacion movil sera utilizada por los usuarios para poder realizar consultas de la informacion que proveen los administradores, ademas podran pedir extras, ver sus cuentas de cobro y gestionar sus perfiles. Como segunda parte una aplicacion web sera utilizada por los administradores para facilitar la realizacion de sus tareas, podran gestionar los usuarios, los perfiles, las cuentas de cobro, los extras, las tareas que seran asignadas a los usuarios, asi como la realizacion de informes y redaccion de documentos. Estas dos primeras partes funcionaran como clientes de un servidor que sera el encargado de almacenar toda la informacion y proveerla a los clientes, este servidor sera el encargado de realizar las validaciones de los datos, asi como de realizar las consultas a la base de datos y proveer la informacion a los clientes siendo esta la tercera parte del sistema. Tambien administrara un sustema de almacenamiento de archivos que sera utilizado para almacenar los archivos que se suban a la aplicacion, como por ejemplo las imagenes de los perfiles de los usuarios, los archivos de las cuentas de cobro, los archivos de actas y demas documentos relevantes para la organizacion.

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
 
 -->
## Definiciones, Acrónimos, y Abreviaciones

| Acrónimo      | Definición                                                                                                                                                                                                              |
| :------------ | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| SRC           | Especificación de Requerimientos de Software                                                                                                                                                                            |
| SERVIDOR      | El servidor es el encargado de controlar el acceso a la informacion, asi como de realizar las validaciones de los datos, asi como de realizar las consultas a la base de datos y proveer la informacion a los clientes. |
| CLIENTE       | El cliente es el encargado de mostrar la informacion a traves de una interfaz grafica, asi como de realizar las peticiones al servidor para obtener la informacion.                                                     |
| BASE DE DATOS | La base de datos es el encargado de almacenar la informacion que sera utilizada por el servidor y los clientes.                                                                                                         |


<!-- 


Referencias 

Indique aquí todas las referencias bibliográficas utilizadas en el documento. Utilice formato IEEE o APA para definirlas. Para administrar automáticamente las referencias, se recomienda el uso de la herramienta Zotero (www.zotero.org). -->

## Referencias




<!-- 



CONTEXTO: /*
HISTORIAL DE CAMBIOS-
CONTENIDO0
USTA DE TABLAS .
UsIA DE ILUSIRACIONES
6
LI FROO
13 DEFINICIONES, ACRONIMOS, Y ABREVIACIONES . mmmmnnaaunuusaassssnnnnee ***** assssnnnnnnmm
L4 REFERENCIAS ... aanueee mnone omemmennnaaasaanannnsepme
15
APRECIACION GLO
DESCRIPCION GLOBAL
0
******
******
******
******
21 PERSPECTIVA DEL PRODUCTO.
2.1.1 Interfoces con ei sistema .
2.1.2 Interfaces con el usuario
2
2.1.3 Interfoces con el Hardware -
... 14
2.1.4 Interfaces con ei sojuwaire.
-14
2.15 Intefoces de Comunicacion
-----.
2.L.6 hestricciones de Memoia - 1
2.L./ Operdciones - -
ZL8 NEquenimientos de Aooptacion dei SiO -
rONONES DELFRODDIO o O
2.3 CARACTERISTICAS DEL USUARIO . .
4
ZuPOSidioNESYDEPENDENCIAS -
DisTRIBUcloN DE KEQDERIENTO eannaannnnnm***
--
REQUERIMIENTOS ESPECIFICOS.
27
3.1 REQUERIMIENTOS DE INTERFACES EXTERNAS
3.1.1 Intefoces con er usudrO ono
********************sassana. E
3.3 REQUERI MIENTOS DE DESEMPEÑO
7
3.4 RESTRICCIONES DE DisEÑO
35 ATRIBUTOS DEL SISTEMA DE SOFTWARE (No FUNCIONALES)
..39
5.5.1 Coniabilidad ..
3..2 DISponbiodd .
3.5.3 Segurdod-
2
.0EQOERIMIENIOS DE LA BASE DE DAIOS- *
PROCESO INGENIERIA DE REQOERIENTOS
..43
PROCESO VERIFICACIÓN .
******
***************************************************************
6. ANEXOS.
49
-..
*/




Apreciación Global  

Esta sección debe tener una descripción general del contenido del documento, especificando su organización o distribución. Es una guía para el lector que le permitirá estructurar la información que encontrará en del documento. 

 

Forma 

Ilustración 3: Apreciación Global 

 -->

## Apreciación Global

<!-- 
Cuáles son
las
principales?

A quien le
interesa
cada una?

Cuando se
van a
utilizar?

Para qué
sirven?
 -->
### Cuáles son las principales?

El contenido del documento se divide en las siguientes secciones:

1. Introducción: En esta sección se describe el contexto del proyecto, asi como el alcance del mismo.
2. Descripción General: En esta sección se describe el producto, asi como las interfaces con el usuario, el sistema, el hardware y el software.

3. Requerimientos Específicos: En esta sección se describen los requerimientos funcionales y no funcionales del sistema.

4. Proceso de Ingeniería de Requerimientos: Que consiste en la descripción de los procesos que se llevaron a cabo para la obtención de los requerimientos del sistema.

5. Proceso de Verificación: Donde se describe el proceso de verificación de los requerimientos del sistema.

6. Anexos: Aqui se encuentran los documentos que se consideren necesarios para el desarrollo del srs.

### A quien le interesa cada una?

A los desarrolladores del sistema, ya que es el documento que les permite conocer los requerimientos del sistema.

### Cuando se van a utilizar?

Cuando se inicia el desarrollo del sistema.

### Para qué sirven?

Para conocer los requerimientos y saber el alcance del proyecto.


<!-- 

Descripción Global 

En general en esta sección se describe los factores generales que afectan al producto y sus requerimientos, es importante aclarar que en esta sección NO se especifican formalmente los requerimientos, es solo información de fondo que brinda a los lectores una descripción de todo el sistema.Esta en lenguaje de Usuario. Los elementos presentados en esta sección se asociaran en la seccion 3 con Requerimientos Especificos.  -->

## Descripción Global

Los temas que se describen en esta sección son:

1. Introducción: En esta sección se describe el contexto del proyecto, asi como el alcance del mismo.
2. Descripción General: En esta sección se describe el producto, asi como las interfaces con el usuario, el sistema, el hardware y el software.
3. Requerimientos Específicos: En esta sección se describen los requerimientos funcionales y no funcionales del sistema.
4. Proceso de Ingeniería de Requerimientos: Que consiste en la descripción de los procesos que se llevaron a cabo para la obtención de los requerimientos del sistema.
5. Proceso de Verificación: Donde se describe el proceso de verificación de los requerimientos del sistema.
6. Anexos: Aqui se encuentran los documentos que se consideren necesarios para el desarrollo del srs.

Estos temas van dirigidos a los desarrolladores del sistema, ya que es el documento que les permite conocer los requerimientos del sistema.

Seran utilizados cuando se inicie el desarrollo del sistema.

Serviran para conocer los requerimientos definir los hitos y saber el alcance del proyecto.