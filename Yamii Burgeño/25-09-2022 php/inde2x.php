<html>

<head>
    <meta charset="UTF-8">
    <title>Practica 1</title>
</head>

<body>
    <!-- 
    /*
     * Crear una clase con su constructor, destructor.
     * •un Método que reciba como parametros dos variables, las asigne a las
     * variables locales.
     * •instanciar esa clase y mandar llamar al método creado en ella para mostrar
     * resultado en pantalla (mostrar su nombre completo, fecha y grupo).
     * •Documentar todo el código.
     * 
     */ -->
    <?php
     class Persona {
                private $nombre;
                private $apellido;
                private $fecha;
                private $grupo;
                
                public function __construct($nombre, $apellido, $fecha, $grupo) {
                    $this->nombre = $nombre;
                    $this->apellido = $apellido;
                    $this->fecha = $fecha;
                    $this->grupo = $grupo;
                }
                
                public function __destruct() {
                    echo "Objeto destruido";
                }
                
                public function getNombre() {
                    return $this->nombre;
                }
                
                public function getApellido() {
                    return $this->apellido;
                }
                
                public function getFecha() {
                    return $this->fecha;
                }
                
                public function getGrupo() {
                    return $this->grupo;
                }
            }
        ?>

</body>

</html>