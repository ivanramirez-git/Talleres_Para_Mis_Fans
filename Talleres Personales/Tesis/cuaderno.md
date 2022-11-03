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
desarrolladores puedan comprenderlo. Es aconsejable utilizar diagramas, gráficas,
entre otros medios visuales que permitan comprender la relación lógica entre las
funciones. Por ejemplo, un diagrama de casos de uso con su respectiva documentación.
Un ejejmplo claro son los Casos de Uso o User Stories que seguramente deberan ser
referenciados. -->

## Funciones principales

Las funciones principales del sistema son las siguientes:

- El sistema debe permitir gestionar cuentas de usuario con distintos roles.
    - Funciones de registro
    - Funciones de login
    - Funciones de logout

- El sistema debe permitir gestionar todo el ciclo de vida de los oficios y tareas asignadas a los asociados.
    - Funciones de asignacion de tareas
    - Funciones de mostrar tareas a travez de calendario y notificaciones
    - Funciones de revision de tareas asignadas
    - Funciones de documentacion de tareas asignadas
    - Funciones para consultar las instrucciones de las tareas
    - Funciones para calificacion y sugerencias a cerca de las tareas realizadas

- El sistema debe permitir gestionar todo el ciclo de vida de los extras de alimentacion o lavado de ropa.
    - Funciones de asignacion de extras
    - Funciones de aprobacion de extras
    - Funciones de documentacion de extras

- El sistema debe permitir gestionar todo el ciclo de vida de las multas o batidas.
    - Funciones de creacion de multas o batidas
    - Funciones de asignacion de multas
    - Funciones de aprobacion de multas
    - Funciones de publicacion de multas 
    - Funciones de documentacion de multas, preavisos, llamados de atencion, memorandos y demas sancciones
    - Funciones de pago de multas

- El sistema debe permitir gestionar todo el ciclo de vida de las actas de reuniones.
    - Funciones de construccion de actas, (editor de texto dentro del sistema con formatos de actas predefinidos)
    - Funciones de publicacion de actas

- El sistema debe permitir gestionar todo el ciclo de vida de los informes por cargos.
    - Funciones de creacion de informes (manejo de facturas, editor especializado para informes)
    - Funciones de revision de informes
    - Funciones de publicacion de informes

- El sistema debe permitir gestionar todo el ciclo de vida de los reglamentos por sedes y estatos de la organizacion.
    - Funciones de creacion y edicion de reglamentos
    - Funciones de revision de reglamentos
    - Funciones de publicacion de reglamentos
    - Funciones de busqueda de articulos de reglamentos

- El sistema debe permitir gestionar todo el ciclo de vida de cuotas y cuentas de cobro a los asociados.
    - Funciones de creacion de cuotas
    - Funciones de publicacion de cuentas de cobro
    - Funciones de funciones de recibo de pagos
    - Funciones de notificacion de saldos pendientes
    
- El sistema debe garantizar el acceso a toda la informacion relevante para cada individuo de la organizacion.
    - Funciones de consulta de informacion de usuarios
    - Funciones de consulta de informacion de tareas
    - Funciones de consulta de informacion de extras
    - Funciones de consulta de informacion de multas
    - Funciones de consulta de informacion de actas
    - Funciones de consulta de informacion de informes
    - Funciones de consulta de informacion de reglamentos
    - Funciones de consulta de informacion de cuotas

- El sistema debe permitir gestionar todos los roles de la organizacion
    - Funciones de creacion de roles
    - Funciones de edicion de roles
    - Funciones de eliminacion de roles
    - Funciones para asignar permisos a los roles autorizaciones y restricciones, todos deben funcionar con el mismo usuario

## Quien lo va leer?

- Cliente: Miembros de la organizacion que seran el cliente y nos daran una retroalimentacion de como se sienten con las funcionalidades  propuestas y si se sienten satisfechos con el producto final.
- Desarrolladores: Ingenieros de software que estan encargados de desarrollar el producto y que se encargaran de la implementacion de las funcionalidades propuestas.
- Stakeholders: Director del proyecto, empleados ded la organizacion, exasociados, etc.

## Medios graficos

- Diagrama de casos de uso
- Matriz de relaciones

## Especificacion clara

- Documentaicón de los diagramas y medios graficos


# 2.3 Características del usuario

<!-- Debe Identificar las diferentes clases de usuarios que usted prevea utilizaran la
aplicación. Las diferentes clases de usuarios pueden ser diferenciadas basados en la
frecuencia del uso, los diferentes roles, la experiencia técnica, los niveles de seguridad o
de privilegios, el nivel de estudios, o de experiencia.
Además en general debe describir las características pertinentes de cada clase de
usuario, las cuales se ilustran en la ilustración 8 y luego se describen en la Tabla 4 [1].
Usualemnte este elemento tambien se tienen en cuenta en los documentos de Casos de
uso, por tanto basta con referenciar al documento que lo contiene. -->

## Usuarios

<!-- Tabla con 5 filas
Fila1: Encabezado col1: Caracteristicas del Usuario, col2: Descripcion
Fila2: Nivel de Seguridad o de Privilegios, Listar todos los privilegios o funcionalidades a las que tiene acceso el usuario.
Fila3: Roles, Los diferentes roles que puede desempeñar el usuario, como por ejemplo: jugador, visitante, administrador, etc. Especificando las características especificas de cada uno de los roles.
Fila4: Nivel de Estudios o Experiencia Técnica, El nivel de estudio o de experiencia técnica relacionada con el uso de la aplicación.
Fila5: Frecuencia de Uso, Periodicidad con la que el usuario utiliza la aplicación.
-->
A continuacion se detallan las caracteristicas de los usuarios del sistema a través de tablas que especifican las caracteristicas de los usuarios.

- Asociado:

|Caracteristicas del Usuario|Descripcion|
|-|-|
|Nivel de Seguridad o de Privilegios|Los asociados pueden ver las tareas asignadas, los extras de alimentacion y lavado de ropa, las multas y las actas de reuniones.|
|Roles|El rol de los asociados es el mas menos funcionalidades activas tendra, solo tienen oportunidad de gestionar datos que a persolanes que le correspondan, todo miembro de la organizacion es asociado.|
|Nivel de Estudios o Experiencia Técnica|Los asociados deben ser admitidos para poder hacer uso del aplicativo por medio de entrevista, estaran en un periodo de ratificacion por 3 meses y una vez ratificados su perfil pasara a ser el de un asociado ratificado, que tendra los mismos privilegios que un asociado en via de ratificacion en el sistema.|
|Frecuencia de Uso|Los asociados seran los que mas usen el aplicativo, casi a diario, para consultar el calendario, recibir notificaciones de tareas pendientes, revisar su saldo actual, pedir extras, entre otros.|

- Miembro de junta directiva:

|Caracteristicas del Usuario|Descripcion|
|-|-|
|Nivel de Seguridad o de Privilegios|Los miembros de la junta directiva asignar tareas, aprobar extras, aprobar multas, realizar actas de reuniones, actualizar tabla de cobro, entre otros.|
|Roles|El rol de los miembros de la junta directiva es el mas funcionalidades activas tendra, tienen oportunidad de gestionar datos de toda la organizacion.|
|Nivel de Estudios o Experiencia Técnica|Los miembros de la junta directiva deben ser admitidos elegidos en asamblea seccional, una vez son miembros de la junta se les activara las funciones adicionales a su perfil de junta directiva.|
|Frecuencia de Uso|Los miembros de la junta directiva usaran el aplicativo como cualquier asociado, pero las funcionalidades adicionales seran menos frecuentes, una vez por semana o cada 15 dias.|

- Administrador:

|Caracteristicas del Usuario|Descripcion|
|-|-|
|Nivel de Seguridad o de Privilegios|El administrador tendra control total del sistema, podra crear, editar y eliminar cualquier tipo de informacion.|
|Roles|El rol de los administradores es exclusivo para controlar data en casos de emergencia.|
|Nivel de Estudios o Experiencia Técnica|Los administradores ya estan previamente definidos por el equipo de desarrollo, solo ellos tendran acceso a las funcionalidades y datos del sistema.|
|Frecuencia de Uso|Los administradores usaran el aplicativo solo en caso de emergencia, para corregir errores o para actualizar datos, una vez por trimestre.|

# 2.4 Restricciones

<!-- Las restricciones son las limitaciones que se deben tener en cuenta para el desarrollo del sistema, estas pueden ser de tipo tecnologico, de tiempo, de personal, de recursos, etc. -->

## Restricciones generales

<!-- Como por ejemplo, las reglas que rigen la aplicación, la tolerancia
a fallos, los idiomas -->
- El aplicativo estara restringido a los reglamentos y estatutos de la organizacion.
- El idioma del aplicativo sera el español ya que esta bastante claro los usuarios que lo usaran.

## Restricciones de software

- Una restriccion sera el nivel de parametrizacion que le podamos dar al ERP.

## Restricciones de hardware

- En dispositivos con una api de Android menor a la 28 no podra ser instalado el aplicativo.

## Otras restricciones

- Requisitos de confiabilidad:
- Tolerancia a fallos de la aplicación:
- Consideraciones de seguridad:
- Limitaciones de hardware:
- El funcionamiento paralelo:
- Las politicas corporativas o reguladoras:
- Requerimientos del lenguaje:
- Interfaces a otras aplicaciones:
- Las funciones de auditoria:
- Las funciones de control:
- Los protocolos señalados:
- Tecnoogias y herramientas especificas:
- Protocolos de comunicacion:
- Convenciones del diseño o estandares de programacion:

# 2.5 Modelo de dominio

Definiciones mas importantes del modelo de domino: 

# Suposiciones y dependencias

<!-- Lista de factores que afectan los requerimientos:
Suposiciones:
Se deben listar todas aquellas suposiciones que puedan llegar a afectar los
requerimientos indicados en la sección 3. Estos pueden incluir componentes comerciales
o de terceras personas que usted planea utilizar. Tenga en cuenta que el proyecto
podría afectarse si estas suposiciones son incorrectas, no se comparten, o se cambian
[1] -->