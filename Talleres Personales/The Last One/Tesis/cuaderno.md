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
- Stakeholders: Director del proyecto, empleados de la organización, ex asociados, etc.

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

| Características del Usuario             | Descripción                                                                                                                                                                                                                                                                                                         |
| --------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Nivel de Seguridad o de Privilegios     | Los asociados pueden ver las tareas asignadas, los extras de alimentación y lavado de ropa, las multas y las actas de reuniones.                                                                                                                                                                                    |
| Roles                                   | El rol de los asociados es el mas menos funcionalidades activas tendrá, solo tienen oportunidad de gestionar datos que a personales que le correspondan, todo miembro de la organización es asociado.                                                                                                               |
| Nivel de Estudios o Experiencia Técnica | Los asociados deben ser admitidos para poder hacer uso del aplicativo por medio de entrevista, estarán en un periodo de ratificación por 3 meses y una vez ratificados su perfil pasara a ser el de un asociado ratificado, que tendrá los mismos privilegios que un asociado en via de ratificación en el sistema. |
| Frecuencia de Uso                       | Los asociados serán los que mas usen el aplicativo, casi a diario, para consultar el calendario, recibir notificaciones de tareas pendientes, revisar su saldo actual, pedir extras, entre otros.                                                                                                                   |

Tabla #: Características de los asociados

- Miembro de junta directiva:

| Características del Usuario             | Descripción                                                                                                                                                                                       |
| --------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Nivel de Seguridad o de Privilegios     | Los miembros de la junta directiva asignar tareas, aprobar extras, aprobar multas, realizar actas de reuniones, actualizar tabla de cobro, entre otros.                                           |
| Roles                                   | El rol de los miembros de la junta directiva es el mas funcionalidades activas tendrá, tienen oportunidad de gestionar datos de toda la organización.                                             |
| Nivel de Estudios o Experiencia Técnica | Los miembros de la junta directiva deben ser admitidos elegidos en asamblea seccional, una vez son miembros de la junta se les activara las funciones adicionales a su perfil de junta directiva. |
| Frecuencia de Uso                       | Los miembros de la junta directiva usaran el aplicativo como cualquier asociado, pero las funcionalidades adicionales serán menos frecuentes, una vez por semana o cada 15 días.                  |

Tabla #: Características de los miembros de la junta directiva

- Administrador:

| Características del Usuario             | Descripción                                                                                                                                          |
| --------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------- |
| Nivel de Seguridad o de Privilegios     | El administrador tendrá control total del sistema, podrá crear, editar y eliminar cualquier tipo de información.                                     |
| Roles                                   | El rol de los administradores es exclusivo para controlar data en casos de emergencia.                                                               |
| Nivel de Estudios o Experiencia Técnica | Los administradores ya están previamente definidos por el equipo de desarrollo, solo ellos tendrán acceso a las funcionalidades y datos del sistema. |
| Frecuencia de Uso                       | Los administradores usaran el aplicativo solo en caso de emergencia, para corregir errores o para actualizar datos, una vez por trimestre.           |

Tabla #: Características de los administradores
# 2.4 Restricciones

<!-- Las restricciones son las limitaciones que se deben tener en cuenta para el desarrollo del sistema, estas pueden ser de tipo tecnológico, de tiempo, de personal, de recursos, etc. -->

## Restricciones generales

<!-- Como por ejemplo, las reglas que rigen la aplicación, la tolerancia
a fallos, los idiomas -->
- El aplicativo estará restringido a los reglamentos y estatutos de la organización.
- El idioma del aplicativo sera el español ya que esta bastante claro los usuarios que lo usaran.
- La tolerancia a fallos será de 0.1% de los datos ingresados, y estara disponible en el aplicativo el 99% del tiempo, tambien se tendra en cuenta el tiempo de respuesta del aplicativo, que sera de maximo 5 segundos, aunque se espera que sea menor.

## Restricciones de software

- Una restricción a nivel de software sera el nivel de parametrization que le podamos dar al ERP.

## Restricciones de hardware

- En dispositivos con iOS debemos esperar respuesta por parte de apple para poder publicar la aplicación en la tienda de aplicaciones, ya que depende de ellos la aprobación de la aplicación.
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

## Suposiciones

- Una conexión a internet es necesaria para el funcionamiento del aplicativo.
- El aplicativo solo funcionara en dispositivos con iOS, Android y Web.
- Una suposicion es que la organizacion retrase las entregas de informacion, lo que tardaria el desarrollo del aplicativo y por ende algunos requerimientos no se podrian cumplir.

## Dependencias

- Dependemos de la organizacion, cuando le llevemos una propuesta de automatizacion o cambio de algun requerimiento, la estructura de la organizacion esta sujeta a aprobar todo desde juntas que se desarrollan 1 vez por semana, si un requerimiento requiere de un cambio en la estructura de la organizacion, este requerimiento no se podria cumplir hasta que la organizacion apruebe el cambio.
- Dependencia de provedores de servicio como Google Firebase, que es el servicio que usaremos para el almacenamiento de datos, si este servicio deja de funcionar, el aplicativo no podria funcionar.



# 2.7 Distribución de Requerimientos


<!-- 
Esta sección permite realizar un mapeo de los requerimientos con respecto a las funciones del producto y a los componentes, módulos o subsistemas que se definan inicialmente. Esta distribución es muy importante porque permite localizar los requerimientos, conociendo en que módulo o parte del sistema se puede encontrar ya sea para validar, verificar o actualizar. Esto debe ser consistente con la estrutura propuesta en la seccion 3 de este documento. 

En la ilustración 14 se propone un formato sencillo para el mapeo y la distribución de los requerimientos, es un ejemplo de la realización de un proyecto de Póker en donde se manejaron diferentes módulos y se utilizaron casos de uso para identificar los requerimientos. 

Es  importante tener en cuenta que cuando se realizan diagramas con imágenes, manejo de colores y demás herramientas gráficas se debe dejar explícito el significado de cada uno para que el lector se familiarice y comprenda con facilidad todo lo que se quiere expresar. 

Por último, en esta sección se deben listar los requerimientos planeados para futuras versiones del sistema con una breve descripción de cada uno.  -->


<!--  
 
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
    - Funciones para asignar permisos a los roles autorizaciones y restricciones, todos deben funcionar con el mismo usuario -->
    
<!-- ✅ : Pertenece al modulo
    ❌: No pertenece al modulo
    🚧: No esta definido
     -->
| **Modulos** <hr> **Funcionalidades**               | Servidor | App Movil | App Web | Casos de uso<hr>Nombre     | ID  |
| -------------------------------------------------- | -------- | --------- | ------- | -------------------------- | --- |
| Gestionar cuentas de usuario con distintos roles   | ✅        | ✅         | ✅       | Registrar usuario          | 0   |
|                                                    | ✅        | ✅         | ✅       | Login                      | 1   |
|                                                    | ✅        | ✅         | ✅       | Logout                     | 2   |
| Gestionar todo el ciclo de vida de los oficios     | ✅        | ❌         | ✅       | Asignar tareas             | 3   |
|                                                    | ✅        | ✅         | ✅       | Mostrar tareas             | 4   |
|                                                    | ✅        | ✅         | ✅       | Revision de tareas         | 5   |
|                                                    | ✅        | ❌         | ❌       | Documentación de tareas    | 6   |
|                                                    | ✅        | ✅         | 🚧       | Consultar instrucciones    | 7   |
|                                                    | ✅        | ✅         | ❌       | Calificación y sugerencias | 8   |
| Gestionar todo el ciclo de vida de los extras      | ✅        | ✅         | ✅       | Asignar extras             | 9   |
|                                                    | ✅        | 🚧         | ✅       | Aprobación de extras       | 10  |
|                                                    | ✅        | ❌         | ❌       | Documentación de extras    | 11  |
| Gestionar todo el ciclo de vida de las multas      | ✅        | ✅         | ✅       | Creación de multas         | 12  |
|                                                    | ✅        | ✅         | ✅       | Asignación de multas       | 13  |
|                                                    | ✅        | ❌         | ✅       | Aprobación de multas       | 14  |
|                                                    | ✅        | ✅         | ✅       | Publicación de multas      | 15  |
|                                                    | ✅        | ❌         | ❌       | Documentación de multas    | 16  |
|                                                    | ✅        | ❌         | ✅       | Pago de multas             | 17  |
| Gestionar todo el ciclo de vida de las actas       | ✅        | ❌         | ✅       | Construcción de actas      | 18  |
|                                                    | ✅        | ❌         | 🚧       | Publicación de actas       | 19  |
| Gestionar todo el ciclo de vida de los informes    | ✅        | ❌         | ✅       | Creación de informes       | 20  |
|                                                    | ✅        | 🚧         | ✅       | Revision de informes       | 21  |
|                                                    | ✅        | ❌         | 🚧       | Publicación de informes    | 22  |
| Gestionar todo el ciclo de vida de los reglamentos | ✅        | ❌         | ✅       | Creación de reglamentos    | 23  |
|                                                    | ✅        | 🚧         | ✅       | Revision de reglamentos    | 24  |
|                                                    | ✅        | ❌         | 🚧       | Publicación de reglamentos | 25  |
|                                                    | ✅        | ✅         | ✅       | Búsqueda de reglamentos    | 26  |
| Gestionar todo el ciclo de vida de las cuotas      | ✅        | ❌         | ✅       | Creación de cuotas         | 27  |
|                                                    | ✅        | ❌         | ✅       | Publicación de cuentas     | 28  |
|                                                    | ✅        | 🚧         | ✅       | Recibo de pagos            | 29  |
|                                                    | ✅        | ❌         | 🚧       | Notificación de saldos     | 30  |
| Gestionar el acceso a toda la información          | ✅        | ❌         | ✅       | Consulta de usuarios       | 31  |
|                                                    | ✅        | ✅         | ✅       | Consulta de tareas         | 32  |
|                                                    | ✅        | ✅         | ✅       | Consulta de extras         | 33  |
|                                                    | ✅        | ✅         | ✅       | Consulta de multas         | 34  |
|                                                    | ✅        | ✅         | ✅       | Consulta de actas          | 35  |
|                                                    | ✅        | ✅         | ✅       | Consulta de informes       | 36  |
|                                                    | ✅        | ✅         | ✅       | Consulta de reglamentos    | 37  |
|                                                    | ✅        | ✅         | ✅       | Consulta de cuotas         | 38  |
| Gestionar los roles de la organización             | ✅        | ❌         | ✅       | Creación de roles          | 39  |
|                                                    | ✅        | ❌         | ✅       | Edición de roles           | 40  |
|                                                    | ✅        | ❌         | ✅       | Eliminación de roles       | 41  |
|                                                    | ✅        | ❌         | ✅       | Asignación de permisos     | 42  |

Tabla #: Matriz de casos de uso



