namespace Name
{
    class Program
    {
        static void Main(string[] args)
        {
            Servidor servidor = new Servidor();
            servidor.Iniciar();

        }
    }

    public class Validacion
    {
        public bool validarCadena(string? nombreUsuario)
        {
            if (nombreUsuario != null && nombreUsuario.Length > 0)
            {
                return true;
            }
            return false;
        }
        public bool validarCorreo(string? correo)
        {
            if (correo != null && correo.Length > 0)
            {
                // verificar que el contrnga un @ y termine en .com
                string extension = correo.Substring(correo.Length - 4);
                string server = correo.Substring(correo.IndexOf("@") + 1, correo.Length - correo.IndexOf("@") - 5);
                string user = correo.Substring(0, correo.IndexOf("@"));
                if (extension == ".com" && server.Length > 0 && user.Length > 0)
                {
                    return true;
                }
            }
            return false;
        }
        public bool validarContrasena(string? contrasena)
        {
            if (contrasena != null && contrasena.Length > 0)
            {
                return true;
            }
            return false;
        }
    }

    public class Servidor
    {
        // Clase Usuario
        private class Usuario
        {
            // Tipo Administrador
            public bool esAdministrador { get; set; }
            // Datos de Usuario Comunes
            public string nombre { get; set; }
            public string apellido { get; set; }
            public string correo { get; set; }
            public string contraseña { get; set; }
            // Datos de Usuario Administrador
            public string? nombreUsuario { get; set; }
            public string? contraseñaUsuario { get; set; }

            // Constructor administrador
            public Usuario(bool esAdministrador, string nombre, string apellido, string correo, string contraseña, string nombreUsuario, string contraseñaUsuario)
            {
                this.esAdministrador = esAdministrador;
                this.nombre = nombre;
                this.apellido = apellido;
                this.correo = correo;
                this.contraseña = contraseña;
                this.nombreUsuario = nombreUsuario;
                this.contraseñaUsuario = contraseñaUsuario;
            }
            // Constructor comun
            public Usuario(string nombre, string apellido, string correo, string contraseña)
            {
                this.nombre = nombre;
                this.apellido = apellido;
                this.correo = correo;
                this.contraseña = contraseña;
            }
        }

        // Clase Pelicula
        private class Pelicula
        {
            public string nombre { get; set; }
            public string genero { get; set; }
            public int año { get; set; }
            public int calificacion { get; set; }
            // Constructor
            public Pelicula(string nombre, string genero, int año, int calificacion)
            {
                this.nombre = nombre;
                this.genero = genero;
                this.año = año;
                this.calificacion = calificacion;
            }
        }

        // Clase Almacenamiento
        private class Almacenamiento
        {
            private List<Usuario> usuarios = new List<Usuario>();
            private List<Pelicula> peliculas = new List<Pelicula>();
            // Constructor
            public Almacenamiento()
            {
                // Datos iniciales de usuarios
                usuarios.Add(new Usuario(true, "admin", "admin", "admin@sitio.com", "admin", "admin", "admin"));
                usuarios.Add(new Usuario("juan", "perez", "juanperez@sitio.com", "juan"));
                usuarios.Add(new Usuario("pedro", "lopez", "pedrolopez@sitio.com", "pedro"));

                // Datos iniciales de peliculas
                peliculas.Add(new Pelicula("El Padrino", "Drama", 1972, 9));
                peliculas.Add(new Pelicula("La era de hielo", "Infantil", 2003, 7));
                peliculas.Add(new Pelicula("El efecto mariposa", "Ciencia Ficcion", 2004, 6));
                peliculas.Add(new Pelicula("Cantinflas", "Comedia", 2005, 5));
            }
            // Metodo para agregar usuario
            public void agregarUsuario(Usuario usuario)
            {
                usuarios.Add(usuario);
            }
            // Metodo para agregar pelicula
            public void agregarPelicula(Pelicula pelicula)
            {
                peliculas.Add(pelicula);
            }
            // Metodo para validar que unos datos pertenezcan a un usuario
            public bool validarUsuario(string nombre, string contraseña)
            {
                foreach (Usuario usuario in usuarios)
                {
                    if (usuario.nombre == nombre && usuario.contraseña == contraseña)
                    {
                        return true;
                    }
                }
                return false;
            }
            // Eliminar usuario
            public void eliminarUsuario(string nombre, int index)
            {
                if (usuarios[index].nombre == nombre)
                {
                    usuarios.RemoveAt(index);
                }
                else
                {
                    Console.WriteLine("No se puede eliminar el usuario");
                }
            }
        }

        private Validacion v = new Validacion();
        private Almacenamiento almacenamiento = new Almacenamiento();
        // Metodos para usuarios
        public void autenticacion(string usuario, string contraseña)
        {
            if (almacenamiento.validarUsuario(usuario, contraseña))
            {
                Console.WriteLine("Bienvenido " + usuario);
                menuUsuario(usuario);
            }
            else
            {
                // El usuario no existe
                Console.WriteLine("Usuario no existe, ahora sera registrado");
                almacenamiento.agregarUsuario(registroUsuario());
            }
        }

        // Menu administrador
        public void menuAdministrador(string usuario)
        {
            Console.WriteLine("Bienvenido administrador " + usuario);
            Console.WriteLine("1. Agregar pelicula");
            Console.WriteLine("2. Eliminar pelicula");
            Console.WriteLine("0. Salir");
            int opcion = int.Parse(Console.ReadLine());
            switch (opcion)
            {
                case 1:
                    agregarPelicula();
                    break;
                case 2:
                    eliminarPelicula();
                    break;
                case 0:
                    Console.WriteLine("Hasta luego");
                    break;
                default:
                    Console.WriteLine("Opcion no valida");
                    break;
            }
        }
    }
}