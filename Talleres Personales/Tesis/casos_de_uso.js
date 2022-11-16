const casos_uso = {
    // Las funciones principales del sistema son las siguientes:

    // - El sistema debe permitir gestionar cuentas de usuario con distintos roles. (Caso de uso)
    //     - Funciones de registro
    //     - Funciones de login
    //     - Funciones de logout
    registrar_usuario: {
        titulo: "Registro de usuario",
        descripcion: "Permite registrar un usuario en el sistema",
        precondiciones: [
            "El usuario no debe existir en el sistema",
        ],
        postcondiciones: [
            "El usuario debe existir en el sistema",
        ],
        actores: [
            "Usuario",
            "Administrador",
            "Sistema"
        ],
        flujo_principal: [
            "El usuario introduce sus datos",
            "El sistema valida los datos",
            "El sistema registra al usuario como pendiente de activación",
            "El sistema envía un correo electrónico al usuario con un enlace de activación",
            "El usuario activa su cuenta",
            "El sistema avisa al administrador que hay una cuenta pendiente para su aprobación",
            "El administrador aprueba la cuenta",
            "El sistema avisa al usuario que su cuenta ha sido aprobada",
            "El usuario queda registrado en el sistema"
        ],
        flujos_alternos: [
            [
                "El usuario no introduce sus datos correctamente",
                "El sistema muestra un mensaje de error"
            ],
            [
                "El usuario no activa su cuenta en el plazo establecido",
                "El sistema elimina la cuenta del usuario"
            ],
            [
                "El administrador no aprueba la cuenta del usuario",
                "El sistema avisa al usuario que su cuenta no ha sido aprobada",
                "El sistema elimina la cuenta del usuario"
            ],
            [
                "El usuario ya existe en el sistema",
                "El sistema muestra un mensaje de error en el formulario"
            ]
        ],
    },
    login: {
        titulo: "Login de usuario",
        descripcion: "Permite a un usuario ingresar en el sistema",
        precondiciones: [
            "El usuario debe existir en el sistema",
            "El usuario debe estar activo",
            "El usuario debe haber introducido correctamente su contraseña",
            "El usuario debe estar aprobado por el administrador"
        ],
        postcondiciones: [
            "El usuario queda logueado en el sistema",
            "El usuario queda registrado en la sesión actual"
        ],
        actores: [
            "Usuario",
            "Sistema"
        ],
        flujo_principal: [
            "El usuario introduce su nombre de usuario y contraseña",
            "El sistema valida los datos",
            "El sistema registra al usuario en la sesión actual",
            "El sistema muestra la página principal del usuario"
        ],
        flujos_alternos: [
            [
                "El usuario no introduce sus datos correctamente",
                "El sistema muestra un mensaje de error"
            ],
            [
                "El usuario no está activo",
                "El sistema muestra un mensaje de error"
            ],
            [
                "El usuario no está aprobado por el administrador",
                "El sistema muestra un mensaje de error"
            ]
        ],
    },
    logout: {
        titulo: "Logout de usuario",
        descripcion: "Permite a un usuario salir del sistema",
        precondiciones: [
            "El usuario debe estar logueado en el sistema"
        ],
        postcondiciones: [
            "El usuario queda deslogueado del sistema",
            "El usuario deja de estar registrado en la sesión actual"
        ],
        actores: [
            "Usuario",
            "Sistema"
        ],
        flujo_principal: [
            "El usuario pulsa el botón de logout",
            "El sistema elimina al usuario de la sesión actual",
            "El sistema muestra la página de login"
        ],
        flujos_alternos: [
            [
                "El usuario no está logueado en el sistema",
                "El sistema muestra un mensaje de error"
            ]
        ],
    },
    asignar_tarea: {
        titulo: "Asignar tarea",
        descripcion: "Permite asignar una tarea a un asociado",
        precondiciones: [
            "El asociado debe existir en el sistema",
            "La tarea debe existir en el sistema",
        ],
        postcondiciones: [
            "La tarea debe estar asignada al asociado en una fecha determinada",
        ],
        actores: [
            "Administrador",
            "Sistema"
        ],
        flujo_principal: [
            "El administrador selecciona inscribir tarea manualmente",// paso 0
            "El administrador selecciona una fecha para la asignación",  // paso 1
            "El administrador selecciona una tarea desde la lista de tareas disponibles", // paso 2
            "El administrador selecciona un asociado, o varios asociados, la lista de asociados se organiza por el indice de prioridad", // paso 3
            "El sistema asigna la tarea a los asociados seleccionados", // paso 4
            "El sistema muestra un mensaje de éxito" // paso 5
        ],
        flujos_alternos: [
            [
                "El asociado ya tiene una tarea asignada en la fecha seleccionada",
                "El sistema muestra un mensaje de recomendación para cambiar el asociado",
                "Continuar con el flujo principal, paso 3 o 4"
            ],
            [
                "El administrador selecciona inscribir tarea automáticamente",
                "El sistema asigna las tareas disponibles a los asociados disponibles por orden de prioridad",
                "El sistema muestra un mensaje de éxito"
            ],
            [
                "El administrador no encuentra la tarea en la lista de tareas",
                "El administrador entra a la vista de crear nueva tarea",
                "El administrador llena el formulario de nueva tarea",
                "El administrador pulsa el botón de crear tarea",
                "El sistema crea la tarea",
                "Continuar con el flujo principal, paso 2"
            ]
        ]
    },
    mostrar_tareas: {
        titulo: "Mostrar lista de tareas",
        descripcion: "Permite mostrar las tareas asignadas a un asociado",
        precondiciones: [
            "El asociado debe existir en el sistema",
        ],
        postcondiciones: [
            "El sistema muestra las tareas asignadas al asociado o indica que no tiene tareas asignadas",
        ],
        actores: [
            "Asociado",
            "Sistema"
        ],
        flujo_principal: [
            "El asociado ingresa a la pantalla de tareas", // paso 0
            "El sistema muestra las tareas asignadas al asociado", // paso 1
        ],
        flujos_alternos: [
            [
                "El asociado no tiene tareas asignadas",
                "El sistema muestra un mensaje que indica que no tiene tareas asignadas",
            ],
        ]
    },
    mostrar_tareas_calendario: {
        titulo: "Mostrar tareas en calendario",
        descripcion: "Permite mostrar las tareas asignadas a un asociado en un calendario",
        precondiciones: [
            "El asociado debe existir en el sistema",
        ],
        postcondiciones: [
            "El sistema muestra un calendario y en el se muestran las tareas asignadas al asociado",
        ],
        actores: [
            "Asociado",
            "Sistema"
        ],
        flujo_principal: [
            "El asociado ingresa a la pantalla de calendario", // paso 0
            "El sistema muestra un calendario", // paso 1
            "En el calendario se muestran las tareas asignadas al asociado", // paso 2
        ],
        flujos_alternos: [
            [
                "El asociado no tiene tareas asignadas",
                "El sistema muestra un calendario vacío",
            ],
        ]
    },
    mostrar_tareas_notificaciones: {
        titulo: "Notificar tareas",
        descripcion: "Envía notificaciones a un asociado cuando se acerca la fecha de una tarea asignada",
        precondiciones: [
            "El asociado debe existir en el sistema",
            "El asociado debe tener tareas asignadas",
        ],
        postcondiciones: [
            "El sistema envía notificaciones al asociado cuando se acerca la fecha de una tarea asignada",
        ],
        actores: [
            "Asociado",
            "Sistema"
        ],
        flujo_principal: [
            "El sistema verifica si hay tareas asignadas al asociado", // paso 0
            "El sistema verifica si hay tareas asignadas al asociado que se acerquen a su fecha de entrega", // paso 1
            "El sistema envía una notificación de tareas próximas", // paso 2
        ],
        flujos_alternos: [
            [
                "El asociado no tiene una sesión activa",
                "El sistema no envía notificaciones",
            ],
        ]
    },
    revisar_tarea: {
        titulo: "Revisar tarea realizada",
        descripcion: "Permite aprobar o rechazar una tarea asignada a un asociado",
        precondiciones: [
            "El asociado debe existir en el sistema",
            "El asociado debe tener tareas asignadas",
        ],
        postcondiciones: [
            "El sistema agregará la tarea a la lista de tareas realizadas",
        ],
        actores: [
            "Administrador",
            "Sistema"
        ],
        flujo_principal: [
            "El administrador ingresa a la lista de tareas, donde se muestran las tareas pendientes organizadas por fecha ascendente", // paso 0
            "El administrador selecciona una tarea", // paso 1
            "El administrador puede ver los detalles de la tarea", // paso 2
            "El administrador puede aprueba la tarea", // paso 3
            "El sistema muestra un mensaje de éxito", // paso 4
        ],
        flujos_alternos: [
            [
                "El administrador rechaza la tarea",
                "El sistema muestra un mensaje de éxito",
            ],
        ]
    },
    // - El sistema debe permitir gestionar todo el ciclo de vida de los oficios y tareas asignadas a los asociados.
    //     - Funciones de asignación de tareas
    //     - Funciones de mostrar tareas a traves de calendario, notificaciones y pantalla de tareas
    //     - Funciones de revision de tareas asignadas
    //     - Funciones de documentación de tareas asignadas
    //     - Funciones para consultar las instrucciones de las tareas
    //     - Funciones para calificación y sugerencias a cerca de las tareas realizadas
    documentar_tarea: {
        titulo: "Documentar tarea realizada",
        descripcion: "Permite documentar una tarea asignada a un asociado para su posterior revisión y toma de decisiones de prioridades para próximas asignaciones de tareas",
        precondiciones: [
            "Una tarea acaba de ser asignada a un asociado",
        ],
        postcondiciones: [
            "El sistema guarda la documentación de la tarea asignada",
            "Las prioridades de las asignaciones siguientes se actualizan",
        ],
        actores: [
            "Asociado",
            "Sistema",
            "Administrador"
        ],
        flujo_principal: [
            "El sistema asigna una tarea a un asociado", // paso 0
            "El sistema guarda la documentación de la tarea asignada", // paso 1
            "El sistema actualiza las prioridades de las asignaciones siguientes", // paso 2
        ],
        flujos_alternos: [
            [
                "No hay tareas asignadas",
                "El sistema duerme",
            ],
        ]
    },
    consultar_instrucciones_tarea: {
        titulo: "Consultar instrucciones de tarea",
        descripcion: "Permite consultar las instrucciones de una tarea asignada a un asociado",
        precondiciones: [
            "El asociado debe existir en el sistema",
            "El asociado debe tener tareas asignadas",
        ],
        postcondiciones: [
            "El sistema muestra las instrucciones de la tarea asignada",
        ],
        actores: [
            "Asociado",
            "Sistema"
        ],
        flujo_principal: [
            "El asociado ingresa a la lista de tareas, donde se muestran las tareas pendientes organizadas por fecha asendente", // paso 0
            "El asociado selecciona una tarea", // paso 1
            "El asociado puede ver los detalles de la tarea", // paso 2
            "El asociado puede ver las instrucciones de la tarea", // paso 3
        ],
        flujos_alternos: [
            [
                "El asociado no tiene tareas asignadas",
                "El sistema muestra un mensaje de que no hay tareas asignadas",
            ],
        ]
    },
    calificar_tarea: {
        titulo: "Calificar tarea realizada",
        descripcion: "Permite calificar una tarea asignada a un asociado una vez que esta ha sido revisada",
        precondiciones: [
            "El asociado debe existir en el sistema",
            "El asociado debe tener tareas asignadas",
            "La tarea debe haber sido revisada",
        ],
        postcondiciones: [
            "El sistema guarda la calificación de la tarea asignada",
        ],
        actores: [
            "Asociado",
            "Sistema",
            "Administrador"
        ],
        flujo_principal: [
            "El asociado ingresa a la lista de tareas realizadas", // paso 0
            "El asociado selecciona una tarea", // paso 1
            "El asociado puede ver los detalles de la tarea", // paso 2
            "El asociado puede calificar la tarea", // paso 3
            "El sistema guarda la calificación de la tarea asignada", // paso 4
        ],
        flujos_alternos: [
            [
                "El asociado no tiene tareas realizadas",
                "El sistema muestra un mensaje de que no hay tareas realizadas",
            ],
            [
                "El asociado quiere agregar una sugerencia",
                "El sistema guarda la sugerencia",
                "El sistema notifica al administrador acerca de la sugerencia",
            ]
        ]
    },
    // - El sistema debe permitir gestionar todo el ciclo de vida de los extras de alimentación o lavado de ropa.
    //     - Funciones de asignación de extras
    //     - Funciones de aprobación de extras
    //     - Funciones de documentación de extras

    asignar_extra: {
        titulo: "Pedir un extra de alimentación o lavado de ropa",
        descripcion: "Permite que un asociado solicite un extra de alimentación o lavado de ropa",
        precondiciones: [
            "El asociado debe existir en el sistema",
        ],
        postcondiciones: [
            "El sistema guarda la solicitud de extra",
        ],
        actores: [
            "Asociado",
            "Sistema",
            "Administrador"
        ],
        flujo_principal: [
            "El asociado inicializa la solicitud de extra", // paso 0
            "El asociado selecciona el tipo de extra", // paso 1
            "El asociado selecciona la fecha del extra", // paso 2
            "El administrador es notificado de la solicitud de extra", // paso 3
            "El administrador aprueba la solicitud de extra", // paso 4
            "El sistema guarda la solicitud de extra", // paso 5
            "El sistema notifica al asociado que su solicitud ha sido aprobada", // paso 6
        ],
        flujos_alternos: [
            [
                "El administrador no aprueba la solicitud de extra",
                "El sistema notifica al asociado que su solicitud ha sido rechazada",
            ],
            [
                "El administrador no responde a la solicitud de extra",
                "El sistema notifica al asociado que su solicitud ha no ha sido verificada por lo tanto no ha sido aprobada",
            ],
        ]
    },
    aprobar_extra: {
        titulo: "Aprobar extra de alimentación o lavado de ropa",
        descripcion: "Permite que un administrador apruebe o rechace una solicitud de extra de alimentación o lavado de ropa",
        precondiciones: [
            "El administrador debe tener una solicitud de extra pendiente",
        ],
        postcondiciones: [
            "El sistema guarda la aprobación o rechazo de la solicitud de extra",
        ],
        actores: [
            "Administrador",
            "Sistema",
            "Asociado"
        ],
        flujo_principal: [
            "El administrador ingresa a la lista de solicitudes de extras pendientes", // paso 0
            "El administrador selecciona una solicitud de extra", // paso 1
            "El administrador puede ver los detalles de la solicitud de extra", // paso 2
            "El administrador aprueba o rechaza la solicitud de extra", // paso 3
            "El sistema guarda la aprobación o rechazo de la solicitud de extra", // paso 4
            "El sistema notifica al asociado que su solicitud ha sido aprobada o rechazada", // paso 5
        ],
        flujos_alternos: [
            [
                "El administrador no aprueba o rechaza la solicitud de extra",
                "El sistema notifica al asociado que su solicitud ha no ha sido verificada por lo tanto no ha sido aprobada",
            ],
        ]
    },
    crear_multa: {
        titulo: "Crear multa o batida",
        descripcion: "Permite que un grupo de 3 asociados o más cree una multa o batida",
        precondiciones: [
            "El asociado a multar debe existir en el sistema",
            "El asociado a que crea la multa debe existir en el sistema",
            "Los 2 asociados que respaldan la multa deben existir en el sistema",
        ],
        postcondiciones: [
            "El sistema guarda la multa y la deja pendiente de aprobación",
        ],
        actores: [
            "Asociado",
            "Sistema",
        ],
        flujo_principal: [
            "El asociado principal inicializa la creación de la multa", // paso 0
            "El asociado principal selecciona el asociado o asociados a multar", // paso 1
            "Indicar si la multa es a un invitado del asociado a multar", // paso 2
            "El asociado principal selecciona el tipo de multa", // paso 2
            "El asociado principal rellena el formulario de la multa", // paso 3
            "El asociado principal selecciona los asociados que respaldan la multa", // paso 4
            "El notificar a los asociados que respaldan la multa", // paso 5
            "El sistema guarda la multa y queda pendiente de hasta que los asociados respaldantes la acepten", // paso 5
            "Una vez la multa es aceptada por los asociados respaldantes, el sistema notifica al fiscal que hay una multa por reportar a la junta", // paso 6
            "Cuando la multa ha sido reportada en junta, el sistema notifica al asociado multado", // paso 7
            "La multa se documenta en el sistema", // paso 8
        ],
        flujos_alternos: [
            [
                "Uno de los asociados respaldantes no aprueba la multa",
                "El sistema notifica al los asociados involucrados que la multa no ha sido aprobada",
            ],
            [
                "La junta no aprueba la multa",
                "El sistema notifica al los asociados involucrados que la multa no ha sido aprobada",
            ],
        ]
    },
    aprobar_multa: {
        titulo: "Aprobar multa o batida",
        descripcion: "Permite que un asociado respaldante de una multa o batida la apruebe o rechace",
        precondiciones: [
            "El asociado a multar debe existir en el sistema",
            "El asociado a que crea la multa debe existir en el sistema",
        ],
        postcondiciones: [
            "El sistema guarda la aprobación o rechazo de la multa",
        ],
        actores: [
            "Asociado",
            "Sistema",
        ],
        flujo_principal: [
            "El asociado respaldante recibe una notificación de una multa pendiente de respaldo", // paso 0
            "El asociado respaldante ingresa a la vista de la multa", // paso 1
            "El asociado respaldante aprueba la multa", // paso 2
            "El sistema guarda la aprobación de la multa", // paso 3
            "El sistema notifica al asociado principal que su multa ha sido aprobada", // paso 4   
        ],
        flujos_alternos: [
            [
                "El asociado respaldante no aprueba la multa",
                "El sistema notifica al asociado principal que su multa no ha sido aprobada",
            ],
        ]
    },
    // - El sistema debe permitir gestionar todo el ciclo de vida de las multas o batidas.
    //     - Funciones de creación de multas o batidas
    //     - Funciones de asignación de multas
    //     - Funciones de aprobación de multas
    //     - Funciones de publicación de multas
    //     - Funciones de eliminación de multas
    //     - Funciones de documentación de multas, preavisos, llamados de atención, memorandos y demás sanciones
    //     - Funciones de pago de multas
    publicar_multa: {
        titulo: "Publicar multa o batida",
        descripcion: "Permite que el sistema notifique de la multa a los asociados multados",
        precondiciones: [
            "El asociado a multar debe existir en el sistema",
            "El asociado a que crea la multa debe existir en el sistema",
        ],
        postcondiciones: [
            "El sistema notifica a los asociados multados",
        ],
        actores: [
            "Asociado",
            "Sistema",
        ],
        flujo_principal: [
            "El sistema identifica una multa que ha sido aprobada por los asociados respaldantes y aprobada en junta", // paso 0
            "El sistema notifica a los asociados multados", // paso 1
        ],
        flujos_alternos: [
            [
                "La junta no aprueba la multa",
                "El sistema notifica al los asociados involucrados, asociado principal y respaldantes de la multa, que la multa no ha sido aprobada",
            ],
        ]
    },
    eliminar_multa: {
        titulo: "Eliminar multa o batida",
        descripcion: "Permite que el administrador elimine una multa o batida",
        precondiciones: [
            "Debe existir un asociado con multas o batidas pendientes",
        ],
        postcondiciones: [
            "El sistema elimina la multa o batida",
            "El asociado multado no tendra esta multa o batida en su lista de multas o batidas pendientes",
        ],
        actores: [
            "Administrador",
            "Sistema",
            "Asociado",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de multas o batidas", // paso 0
            "El administrador selecciona la multa o batida a eliminar", // paso 1
            "El administrador confirma la eliminación de la multa o batida", // paso 2
            "El sistema elimina la multa o batida", // paso 3
            "El sistema notifica al asociado multado que su multa o batida ha sido eliminada", // paso 4
        ],
        flujos_alternos: [
            [
                "No hay multas o batidas pendientes",
                "El sistema muestra un mensaje de que no hay multas o batidas pendientes",
            ],
        ]
    },
    pagar_multa: {
        titulo: "Pagar multa o batida",
        descripcion: "Permite que el asociado pague una multa o batida",
        precondiciones: [
            "Debe existir un asociado con multas o batidas pendientes",
        ],
        postcondiciones: [
            "El sistema elimina la multa o batida",
            "El asociado multado no tendra esta multa o batida en su lista de multas o batidas pendientes  y esta pasara a su historial de multas o batidas",
        ],
        actores: [
            "Asociado",
            "Sistema",
            "Administrador",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de multas o batidas", // paso 0
            "El administrador selecciona la multa o batida a pagar", // paso 1
            "El administrador confirma el pago de la multa o batida", // paso 2
            "El sistema actualiza el estado de la multa o batida a pagada", // paso 3
            "El sistema agregara la multa o batida al historial de multas o batidas del asociado", // paso 4
            "El sistema notifica al asociado multado que su multa o batida ha sido pagada", // paso 5
        ],
        flujos_alternos: [
            [
                "No hay multas o batidas pendientes",
                "El sistema muestra un mensaje de que no hay multas o batidas pendientes",
            ],
        ]
    },
    // - El sistema debe permitir gestionar todo el ciclo de vida de las actas de reuniones.
    //     - Funciones de construcción de actas, (editor de texto dentro del sistema con formatos de actas predefinidos)
    //     - Funciones de publicación de actas

    crear_acta: {
        titulo: "Crear acta",
        descripcion: "Permite que el administrador cree una acta",
        precondiciones: [
            "Debe existir un administrador",
        ],
        postcondiciones: [
            "El sistema crea una acta",
            "Los asociados son notificados con el acta",
            "Se actualizan las tablas de calendarios y compromisos correspondientes"
        ],
        actores: [
            "Administrador",
            "Sistema",
            "Asociado",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de actas", // paso 0
            "El administrador selecciona la opción de crear acta", // paso 1
            "El administrador selecciona el tipo de reunión", // paso 2
            "El sistema le envia a la vista de edición de actas", // paso 3
            "El administrador ingresa los datos de la acta", // paso 4
            "El administrador publica la acta", // paso 5
            "El sistema notifica a los asociados con la acta", // paso 6
            "El sistema actualiza las tablas de calendarios y compromisos correspondientes", // paso 7
        ],
        flujos_alternos: [
            [
                "No hay actas pendientes",
                "El sistema muestra un mensaje de que no hay actas pendientes",
            ],
        ]
    },
    // - El sistema debe permitir gestionar todo el ciclo de vida de los informes por cargos.
    //     - Funciones de creación de informes (manejo de facturas, editor especializado para informes)
    //     - Funciones de revision de informes
    //     - Funciones de publicación de informes
    crear_informe: {
        titulo: "Crear informe",
        descripcion: "Permite que el administrador cree un informe",
        precondiciones: [
            "Debe existir un administrador",
            "Debe existir un cargo",
        ],
        postcondiciones: [
            "El sistema crea un informe",
            "El fiscal obtiene el informe para su revisión",
        ],
        actores: [
            "Administrador",
            "Sistema",
            "Fiscal",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de informes", // paso 0
            "El administrador selecciona la opción de crear informe, este sera creado segun el rol del administrador", // paso 1
            "El sistema le envia a la vista de edición de informes", // paso 2
            "El administrador ingresa los datos del informe", // paso 3
            "El administrador publica el informe", // paso 4
            "El sistema notifica al fiscal con el informe disponible para su revisión", // paso 5
        ],
        flujos_alternos: [
            [
                "No hay informes pendientes",
                "El sistema muestra un mensaje de que no hay informes pendientes",
            ],
        ]
    },
    revisar_informe: {
        titulo: "Revisar informe",
        descripcion: "Permite que el fiscal revise un informe",
        precondiciones: [
            "Debe existir un fiscal",
            "Debe existir un informe disponible para revisión",
        ],
        postcondiciones: [
            "El sistema actualiza el estado del informe a revisado",
            "El fiscal obtiene el informe para su revisión",
        ],
        actores: [
            "Fiscal",
            "Sistema",
            "Administrador",
        ],
        flujo_principal: [
            "El fiscal ingresa a la vista de informes", // paso 0
            "El fiscal selecciona la opción de revisar informe", // paso 1
            "El sistema le envia a la vista de revisión de informes", // paso 2
            "El fiscal revisa el informe", // paso 3
            "El fiscal aprueba el informe", // paso 4
            "El sistema notifica al administrador con el informe revisado", // paso 5
        ],
        flujos_alternos: [
            [
                "El fiscal no aprueba el informe",
                "El sistema notifica al administrador con el informe rechazado",
            ],
        ]
    },
    publicar_informe: {
        titulo: "Publicar informe",
        descripcion: "Permite que el sistema distribuya el informe a los asociados",
        precondiciones: [
            "Debe existir un informe revisado y aprobado",
        ],
        postcondiciones: [
            "El sistema actualiza el estado del informe a publicado",
            "El sistema notifica a los asociados con el informe",
        ],
        actores: [
            "Sistema",
            "Asociado",
        ],
        flujo_principal: [
            "El sistema descubre un informe revisado, aprobado y que aun no ha sido publicado", // paso 0
            "El sistema notifica a los asociados con el informe", // paso 1
            "El sistema actualiza el estado del informe a publicado", // paso 2
        ],
        flujos_alternos: [
            [
                "No hay informes pendientes",
                "El sistema muestra un mensaje de que no hay informes pendientes",
            ],
        ]
    },
    // - El sistema debe permitir gestionar todo el ciclo de vida de los reglamentos por sedes y estatutos de la organización.
    //     - Funciones de creación y edición de reglamentos
    //     - Funciones de revision de reglamentos
    //     - Funciones de publicación de reglamentos
    //     - Funciones de búsqueda de artículos de reglamentos
    crear_reglamento: {
        titulo: "Crear reglamento",
        descripcion: "Permite que el los delegatarios creen un reglamento",
        precondiciones: [
            "Debe existir un delegatario",
            "Debe existir una sede",
            "El reglamento debió ser presentado ante la asamblea, votado y aprobado",
        ],
        postcondiciones: [
            "El sistema crea un reglamento",
            "El fiscal obtiene el reglamento para su revisión",
        ],
        actores: [
            "Delegatario",
            "Sistema",
            "Fiscal",
        ],
        flujo_principal: [
            "El delegatario ingresa a la vista de reglamentos", // paso 0
            "El delegatario selecciona la opción de crear reglamento", // paso 1
            "El sistema le envia a la vista de edición de reglamentos", // paso 2
            "El delegatario ingresa los datos del reglamento", // paso 3
            "El delegatario publica el reglamento", // paso 4
            "El sistema notifica al fiscal con el reglamento disponible para su revisión", // paso 5
        ],
        flujos_alternos: [
            [
                "No hay reglamentos pendientes aprobados en asamblea",
                "El sistema muestra un mensaje de que no hay reglamentos pendientes",
            ],
        ]
    },
    revisar_reglamento: {
        titulo: "Revisar reglamento",
        descripcion: "Permite que el fiscal revise un reglamento",
        precondiciones: [
            "Debe existir un fiscal",
            "Debe existir un reglamento disponible para revisión",
        ],
        postcondiciones: [
            "El sistema actualiza el estado del reglamento a revisado",
            "El reglamento estara disponible para todos los asociados y sus artículos para la búsqueda",
        ],
        actores: [
            "Fiscal",
            "Sistema",
            "Delegatario",
        ],
        flujo_principal: [
            "El fiscal ingresa a la vista de reglamentos", // paso 0
            "El fiscal selecciona la opción de revisar reglamento", // paso 1
            "El sistema le envia a la vista de revisión de reglamentos", // paso 2
            "El fiscal revisa el reglamento", // paso 3
            "El fiscal aprueba el reglamento", // paso 4
            "El sistema notifica al delegatario con el reglamento revisado", // paso 5
            "El relgado estara disponible para todos los asociados y sus artículos para la búsqueda", // paso 6
        ],
        flujos_alternos: [
            [
                "El fiscal no aprueba el reglamento",
                "El sistema notifica al delegatario con el reglamento rechazado",
            ],
        ]
    },
    buscar_articulo: {
        titulo: "Buscar artículo",
        descripcion: "Permite que los asociados busquen artículos de los reglamentos",
        precondiciones: [
            "Debe existir un asociado",
            "Debe existir un reglamento",
        ],
        postcondiciones: [
            "El sistema muestra los artículos del reglamento que coincidan con la búsqueda",
        ],
        actores: [
            "Asociado",
            "Sistema",
        ],
        flujo_principal: [
            "El asociado ingresa a la vista de reglamentos", // paso 0
            "El asociado selecciona la opción de buscar artículo", // paso 1
            "El sistema le envia a la vista de búsqueda de artículos", // paso 2
            "El asociado ingresa los datos de la búsqueda", // paso 3
            "El sistema muestra los artículos del reglamento que coincidan con la búsqueda", // paso 4
        ],
        flujos_alternos: [
            [
                "No hay artículos que coincidan con la búsqueda",
                "El sistema muestra un mensaje de que no hay artículos que coincidan con la búsqueda",
            ],
        ]
    },



    // - El sistema debe permitir gestionar todo el ciclo de vida de cuotas y cuentas de cobro a los asociados.
    //     - Funciones de creación de cuotas
    //     - Funciones de publicación de cuentas de cobro
    //     - Funciones de funciones de recibo de pagos
    //     - Funciones de notificación de saldos pendientes

    crear_cuota: {
        titulo: "Crear tabla de cobros de cuotas a los asociados",
        descripcion: "Permite que el tesorero cree una tabla de cobros de cuotas a los asociados, estos recibiran una notificacion y podran ver el valor de la cuota y los detalles que componen el valor de la cuota",
        precondiciones: [
            "Deben existir asociados activos con fechas de ingreso",
            "Debe existir un tesorero activo",
            "Debe existir una sede",
        ],
        postcondiciones: [
            "El sistema crea una tabla de cobros de cuotas a los asociados",
            "El sistema notifica a los asociados con el valor de la cuota y los detalles que componen el valor de la cuota",
        ],
        actores: [
            "Tesorero",
            "Sistema",
            "Asociado",
        ],
        flujo_principal: [
            "El tesorero ingresa a la vista de cuotas", // paso 0
            "El tesorero selecciona la opción de crear tabla de cobros de cuotas", // paso 1
            "El sistema le envia a la vista de creación de tabla de cobros de cuotas, donde estan todos los datos precargados de los asociados", // paso 2
            "El tesorero ingresa los datos adicionales de la tabla de cobros de cuotas", // paso 3
            "El tesorero publica la tabla de cobros de cuotas", // paso 4
            "El sistema notifica a los asociados con el valor de la cuota y los detalles que componen el valor de la cuota", // paso 5
        ],
        flujos_alternos: [
            [
                "No hay asociados activos con fechas de ingreso",
                "El sistema muestra un mensaje de que no hay asociados activos con fechas de ingreso",
            ],
            [
                "No hay una sede",
                "El sistema muestra un mensaje de que no hay una sede",
            ],
        ]
    },
    recibo_pago: {
        titulo: "Recibo de pago de cuota",
        descripcion: "Permite que el tesorero apruebe el pago de una cuota y que el asociado reciba el comprobante de pago",
        precondiciones: [
            "El asociado debe tener una cuota pendiente",
            "Debe existir un tesorero activo",
        ],
        postcondiciones: [
            "El sistema aprueba el pago de la cuota",
            "El sistema notifica al asociado con el comprobante de pago",
        ],
        actores: [
            "Tesorero",
            "Sistema",
            "Asociado",
        ],
        flujo_principal: [
            "El tesorero ingresa a la vista de cuotas", // paso 0
            "El tesorero selecciona la opción de recibo de pago de cuota", // paso 1
            "El sistema le envia a la vista de recibo de pago de cuota, donde están todos los datos precargados de los asociados", // paso 2
            "El tesorero busca a el asociado que realizo el pago", // paso 3
            "El tesorero agrega el valor del pago", // paso 4
            "El tesorero aprueba el pago de la cuota", // paso 5
            "El sistema notifica al asociado con el comprobante de pago", // paso 6
        ],
        flujos_alternos: [
            [
                "No hay asociados con cuotas pendientes",
                "El sistema muestra un mensaje de que no hay asociados con cuotas pendientes",
            ],
        ]
    },
    notificacion_saldo_pendiente: {
        titulo: "Notificación de saldo pendiente",
        descripcion: "Permite que el tesorero notifique a los asociados con saldos pendientes",
        precondiciones: [
            "El asociado debe tener una cuota pendiente",
            "Debe existir un tesorero activo",
        ],
        postcondiciones: [
            "Los asociados reciben una notificación con el saldo pendiente",
        ],
        actores: [
            "Tesorero",
            "Sistema",
            "Asociado",
        ],
        flujo_principal: [
            "El tesorero ingresa a la vista de cuotas", // paso 0
            "El tesorero selecciona la opción de notificación de saldo pendiente", // paso 1
            "El sistema le envia a la vista de notificación de saldo pendiente a cada asociado correspondiente", // paso 2
            "El sistema notifica a los asociados con el saldo pendiente", // paso 3
        ],
        flujos_alternos: [
            [
                "No hay asociados con cuotas pendientes",
                "El sistema muestra un mensaje de que no hay asociados con cuotas pendientes",
            ],
        ]
    },
    informacion_usuarios: {
        titulo: "Información de usuarios",
        descripcion: "Permite que el administrador vea la información de los usuarios",
        precondiciones: [
            "Debe existir un administrador activo",
        ],
        postcondiciones: [
            "El administrador ve la información de los usuarios",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de usuarios", // paso 0
            "El administrador selecciona la opción de ver información de usuarios", // paso 1
            "El sistema le envia a la vista de información de usuarios", // paso 2
            "El administrador ve la información de los usuarios", // paso 3
        ],
        flujos_alternos: [
            [
                "No hay usuarios",
                "El sistema muestra un mensaje de que no hay usuarios",
            ],
        ]
    },
    informacion_tareas: {
        titulo: "Información de tareas",
        descripcion: "Permite que el administrador vea la información de las tareas",
        precondiciones: [
            "Debe existir un administrador activo",
        ],
        postcondiciones: [
            "El administrador ve la información de las tareas",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de tareas", // paso 0
            "El administrador selecciona la opción de ver información de tareas", // paso 1
            "El sistema le envia a la vista de información de tareas", // paso 2
            "El administrador ve la información de las tareas", // paso 3
        ],
        flujos_alternos: [
            [
                "No hay tareas",
                "El sistema muestra un mensaje de que no hay tareas",
            ],
        ]
    },
    informacion_extras: {
        titulo: "Información de extras",
        descripcion: "Permite que el administrador vea la información de los extras",
        precondiciones: [
            "Debe existir un administrador activo",
        ],
        postcondiciones: [
            "El administrador ve la información de los extras",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de extras", // paso 0
            "El administrador selecciona la opción de ver información de extras", // paso 1
            "El sistema le envia a la vista de información de extras", // paso 2
            "El administrador ve la información de los extras", // paso 3
        ],
        flujos_alternos: [
            [
                "No hay extras",
                "El sistema muestra un mensaje de que no hay extras",
            ],
        ]
    },
    informacion_multas: {
        titulo: "Información de multas",
        descripcion: "Permite que el administrador vea la información de las multas",
        precondiciones: [
            "Debe existir un administrador activo",
        ],
        postcondiciones: [
            "El administrador ve la información de las multas",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de multas", // paso 0
            "El administrador selecciona la opción de ver información de multas", // paso 1
            "El sistema le envia a la vista de información de multas", // paso 2
            "El administrador ve la información de las multas", // paso 3
        ],
        flujos_alternos: [
            [
                "No hay multas",
                "El sistema muestra un mensaje de que no hay multas",
            ],
        ]
    },
    informacion_actas: {
        titulo: "Información de actas",
        descripcion: "Permite que el administrador vea la información de las actas",
        precondiciones: [
            "Debe existir un administrador activo",
        ],
        postcondiciones: [
            "El administrador ve la información de las actas",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de actas", // paso 0
            "El administrador selecciona la opción de ver información de actas", // paso 1
            "El sistema le envia a la vista de información de actas", // paso 2
            "El administrador ve la información de las actas", // paso 3
        ],
        flujos_alternos: [
            [
                "No hay actas",
                "El sistema muestra un mensaje de que no hay actas",
            ],
        ]
    },
    informacion_informes: {
        titulo: "Información de informes",
        descripcion: "Permite que el administrador vea la información de los informes",
        precondiciones: [
            "Debe existir un administrador activo",
        ],
        postcondiciones: [
            "El administrador ve la información de los informes",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de informes", // paso 0
            "El administrador selecciona la opción de ver información de informes", // paso 1
            "El sistema le envia a la vista de información de informes", // paso 2
            "El administrador ve la información de los informes", // paso 3
        ],
        flujos_alternos: [
            [
                "No hay informes",
                "El sistema muestra un mensaje de que no hay informes",
            ],
        ]
    },
    // - El sistema debe garantizar el acceso a toda la información relevante para cada individuo de la organización.
    //     - Funciones de consulta de información de usuarios
    //     - Funciones de consulta de información de tareas
    //     - Funciones de consulta de información de extras
    //     - Funciones de consulta de información de multas
    //     - Funciones de consulta de información de actas
    //     - Funciones de consulta de información de informes
    //     - Funciones de consulta de información de reglamentos
    //     - Funciones de consulta de información de cuotas
    //     - Funciones de consulta de información de asociados
    informacion_reglamentos: {
        titulo: "Información de reglamentos",
        descripcion: "Permite que el administrador vea la información de los reglamentos",
        precondiciones: [
            "Debe existir un administrador activo",
        ],
        postcondiciones: [
            "El administrador ve la información de los reglamentos",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de reglamentos", // paso 0
            "El administrador selecciona la opción de ver información de reglamentos", // paso 1
            "El sistema le envia a la vista de información de reglamentos", // paso 2
            "El administrador ve la información de los reglamentos", // paso 3
        ],
        flujos_alternos: [
            [
                "No hay reglamentos",
                "El sistema muestra un mensaje de que no hay reglamentos",
            ],
        ]
    },
    informacion_cuotas: {
        titulo: "Información de cuotas",
        descripcion: "Permite que el administrador vea la información de las cuotas",
        precondiciones: [
            "Debe existir un administrador activo",
        ],
        postcondiciones: [
            "El administrador ve la información de las cuotas",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de cuotas", // paso 0
            "El administrador selecciona la opción de ver información de cuotas", // paso 1
            "El sistema le envia a la vista de información de cuotas", // paso 2
            "El administrador ve la información de las cuotas", // paso 3
        ],
        flujos_alternos: [
            [
                "No hay cuotas",
                "El sistema muestra un mensaje de que no hay cuotas",
            ],
        ]
    },
    informacion_asociados: {
        titulo: "Información de asociados",
        descripcion: "Permite que el administrador vea la información de los asociados",
        precondiciones: [
            "Debe existir un administrador activo",
        ],
        postcondiciones: [
            "El administrador ve la información de los asociados",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de asociados", // paso 0
            "El administrador selecciona la opción de ver información de asociados", // paso 1
            "El sistema le envia a la vista de información de asociados", // paso 2
            "El administrador ve la información de los asociados", // paso 3
        ],
        flujos_alternos: [
            [
                "No hay asociados",
                "El sistema muestra un mensaje de que no hay asociados",
            ],
        ]
    },
    // - El sistema debe permitir gestionar todos los roles de la organización
    //     - Funciones de creación de roles
    //     - Funciones de edición de roles
    //     - Funciones de eliminación de roles
    //     - Funciones para asignar permisos a los roles autorizaciones y restricciones, todos deben funcionar con el mismo usuario
    creacion_roles: {
        titulo: "Creación de roles",
        descripcion: "Permite que el administrador cree roles",
        precondiciones: [
            "Debe existir un administrador activo",
        ],
        postcondiciones: [
            "El administrador crea un rol",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de roles", // paso 0
            "El administrador selecciona la opción de crear un rol", // paso 1
            "El sistema le envia a la vista de creación de roles", // paso 2
            "El administrador ingresa el nombre del rol", // paso 3
            "El administrador indica las autorizaciones del rol", // paso 4
            "El administrador indica las restricciones del rol", // paso 5
            "El sistema guarda el rol", // paso 6
            "El sistema le envia a la vista de roles", // paso 7
            "El administrador ve el rol creado", // paso 8
        ],
        flujos_alternos: [
            [
                "El rol ya existe",
                "El sistema muestra un mensaje de que el rol ya existe",
            ],
        ]
    },
    edicion_roles: {
        titulo: "Edición de roles",
        descripcion: "Permite que el administrador edite roles",
        precondiciones: [
            "Debe existir un administrador activo",
            "Debe existir un rol",
        ],
        postcondiciones: [
            "El administrador edita un rol",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de roles", // paso 0
            "El administrador selecciona la opción de editar un rol", // paso 1
            "El sistema le envia a la vista de edición de roles", // paso 2
            "El administrador ingresa el nombre del rol", // paso 3
            "El administrador indica las autorizaciones del rol", // paso 4
            "El administrador indica las restricciones del rol", // paso 5
            "El sistema guarda el rol", // paso 6
            "El sistema le envia a la vista de roles", // paso 7
            "El administrador ve el rol editado", // paso 8
        ],
        flujos_alternos: [
            [
                "El rol no existe",
                "El sistema muestra un mensaje de que el rol no existe",
            ],
        ]
    },
    eliminacion_roles: {
        titulo: "Eliminación de roles",
        descripcion: "Permite que el administrador elimine roles",
        precondiciones: [
            "Debe existir un administrador activo",
            "Debe existir un rol",
            "El rol no debe tener un cargo activo",
        ],
        postcondiciones: [
            "El administrador elimina un rol",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de roles", // paso 0
            "El administrador selecciona la opción de eliminar un rol", // paso 1
            "El sistema le envia a la vista de eliminación de roles", // paso 2
            "El administrador ingresa el nombre del rol", // paso 3
            "El sistema elimina el rol", // paso 4
            "El sistema le envia a la vista de roles", // paso 5
            "El administrador ve el rol eliminado", // paso 6
        ],
        flujos_alternos: [
            [
                "El rol no existe",
                "El sistema muestra un mensaje de que el rol no existe",
            ],
        ]
    },
    asignacion_permisos_roles: {
        titulo: "Asignación de permisos a roles",
        descripcion: "Permite que el administrador asigne permisos a roles",
        precondiciones: [
            "Debe existir un administrador activo",
            "Debe existir un rol",
            "Deben existir permisos",
        ],
        postcondiciones: [
            "El administrador asigna permisos a un rol",
        ],
        actores: [
            "Administrador",
            "Sistema",
        ],
        flujo_principal: [
            "El administrador ingresa a la vista de roles", // paso 0
            "El administrador selecciona la opción de asignar permisos a un rol", // paso 1
            "El sistema le envia a la vista de asignación de permisos a roles", // paso 2
            "El administrador ingresa el nombre del rol", // paso 3
            "El administrador selecciona los permisos", // paso 4
            "El sistema guarda los permisos", // paso 5
            "El sistema le envia a la vista de roles", // paso 6
            "El administrador ve los permisos asignados", // paso 7
        ],
        flujos_alternos: [
            [
                "El rol no existe",
                "El sistema muestra un mensaje de que el rol no existe",
            ],
        ]
    },
};

const fs = require("fs");

// Construir un archivo .md para cada caso de uso
let indice = 0;
for (const [nombre, caso] of Object.entries(casos_uso)) {


    const documento = `# ${caso.titulo}

${caso.descripcion}

## Precondiciones

${caso.precondiciones.map((p) => `* ${p}`).join("\n")}

## Postcondiciones

${caso.postcondiciones.map((p) => `* ${p}`).join("\n")}

## Actores

${caso.actores.map((p) => `* ${p}`).join("\n")}

## Flujo principal

${caso.flujo_principal.map((p, i) => `${i}. ${p}`).join("\n")}

## Flujos alternos

${caso.flujos_alternos.map((p, i) => `### ${i}. ${` Flujo alterno\n\n${p.map((p, i) => `${i}. ${p}`).join("\n")}`}`).join("\n\n")}

`;
    // Construir un archivo .md para cada tabla
    /*
    Ejemplo:
    
    |# Requerimiento|1 |
    |-|-|
    | *Nombre*|Login de usuario
    | *Descripción*| Permite a un usuario ingresar en el sistema |
    |*Actores*|-   Usuario <br>   Sistema
    |*Precondiciones*| -El usuario debe existir en el sistema <br> -El usuario debe estar activo <br> -El usuario debe haber introducido correctamente su contraseña <br> -El usuario debe estar aprobado por el administrador
    |*Postcondiciones*|-   El usuario queda logueado en el sistema <br>-   El usuario queda registrado en la sesión actual
    |*Flujo principal*|0.  El usuario introduce su nombre de usuario y contraseña<br> 1.  El sistema valida los datos<br> 2.  El sistema registra al usuario en la sesión actual<br> 3.  El sistema muestra la página principal del usuario.   
    |*Flujos alternos*|0.  El usuario no introduce sus datos correctamente <br>1.  El sistema muestra un mensaje de error<hr>0.  El usuario no está activo <br>1.  El sistema muestra un mensaje de error<hr> 0.  El usuario no está aprobado por el administrador<br>1.  El sistema muestra un mensaje de error
    */

    const tabla = `|# Requerimiento|${indice} |
|-|-|
| *Nombre*|${caso.titulo}
| *Descripción*| ${caso.descripcion} |
|*Actores*| - ${caso.actores.join("<br> - ")}
|*Precondiciones*| - ${caso.precondiciones.join("<br> - ")}
|*Postcondiciones*| - ${caso.postcondiciones.join("<br> - ")}
|*Flujo principal*|${caso.flujo_principal.map((p, i) => `${i}.  ${p}`).join("<br>")}
|*Flujos alternos*|${caso.flujos_alternos.map((p, i) => `${i}.  ${p.map((p, i) => `${i}. ${p}`).join("<br>")}`).join("<hr>")}
`;
    indice++;

    try {
        fs.writeFileSync(`./casos_uso/${nombre}.md`, documento);
    } catch (error) {
        // crear la carpeta
        fs.mkdirSync("./casos_uso")
        fs.writeFileSync(`./casos_uso/${nombre}.md`, documento);
    }

    try {
        fs.writeFileSync(`./tablas/${indice}_${nombre}.md`, tabla);
    } catch (error) {
        // crear la carpeta
        fs.mkdirSync("./tablas")
        fs.writeFileSync(`./tablas/${indice}_${nombre}.md`, tabla);
    }
}

