using System.ComponentModel.DataAnnotations;
namespace PracticaNetflix
{
    class Program
    {
        public static void Main(string[] args)
        {
            Servidor MiServidor = new Servidor();
            Cliente MiCliente = new Cliente(MiServidor);
            Administrador MiAdministrador = new Administrador(MiServidor);
            Login MiLogin = new Login(MiServidor, MiCliente, MiAdministrador);
            

            string [] MisOpciones = { "Login"};
            int opcion;
            Menu MiMenu = new Menu( MisOpciones, "Bienvenido");
            Console.Clear();
            do
            {
                opcion = MiMenu.MuestraMenu();
                if (opcion == 1)
                {
                     MiLogin.Entrar();
                }
            }while (opcion != 0);
        }
    }

    public class Menu
    {
        string [] opciones;
        string titulo;
        public Menu(string[] op, string titulo)
        {
            opciones = op;
            this.titulo = titulo;
        }
        public int MuestraMenu()
        {
            int opcion, numOpcion;
           
            do
            {
                numOpcion = 1;

                Console.Clear();
                Console.WriteLine(titulo);
            
                foreach(string item in opciones)
                {
                    Console.WriteLine(numOpcion+"  " +item);
                    numOpcion++;
                }
                Console.WriteLine(numOpcion+" Finalizar" );
                Console.WriteLine("¿Qué desea hacer?");
                Console.Write("Seleccione una opción: ");
                opcion = 0;
                try
                {
                    opcion = int.Parse(Console.ReadLine()); 
                }
                catch (Exception error)
                {
                    Console.WriteLine("dato erronio");
                    Console.ReadKey();
                }
                
                    Console.Clear();

                if(!(opcion >0 && opcion < opciones.Length+2))
                {
                    
                    Console.WriteLine("Oprima enter para continuar ...");
                    Console.ReadKey();
                    Console.Clear();
                }
               
            }while (!(opcion >0 && opcion < opciones.Length+2));

            if(opcion == opciones.Length+1 )
            {
                opcion =0;
            }
            
            return opcion;
        }

    }
    public class Validar
    {
        string [] opciones;
        public Validar(string[] op)
        {
            opciones = op;
        }

        public string ValidarNombre()
        {
            string nombre;
            nombre= "";
            foreach(string item in opciones)
            {
                if(item == "Nombre de usuario: ")
                {
                Console.WriteLine(item);
                } 
            }
            nombre = Console.ReadLine();
            int n;  
            double numeroDecimal;
            bool result = Int32.TryParse(nombre, out n);
            bool resultDecimal = double.TryParse(nombre, out numeroDecimal);
              
                do{
                if( nombre.Length == 0)
                {
                Console.Clear();
                Console.WriteLine("Este cambo no puede estar vacio ");
                Console.WriteLine("Ingrese nuevamente su nombre");
                nombre = Console.ReadLine();
                }
                if(result || resultDecimal)
                {
                Console.Clear();
                Console.WriteLine("Introdujo un número debe ser un nombre");
                Console.WriteLine("Ingrese nuevamente su nombre");
                nombre = Console.ReadLine();
                result = Int32.TryParse(nombre, out n);
                }
                

                } while((!(nombre.Length !=0)) || (result = Int32.TryParse(nombre, out n)) || (resultDecimal = double.TryParse(nombre, out numeroDecimal)) );
            
            return nombre;
        }
        public string ValidarCorreo()
        {
            string correo;
    
            correo= "";
            foreach(string item in opciones)
            {
                
                if(item ==  "Correo: " )
                {
                Console.WriteLine(item);
                } 
            }
            correo = Console.ReadLine();
            
           if( correo.Length == 0)
            {
               do
                {
                Console.Clear();
                Console.WriteLine("Este cambo no puede estar vacio ");
                 Console.WriteLine("Ingrese nuevamente su correo");
                correo = Console.ReadLine();
                
                }while (!(correo.Length !=0));  
            }

            bool isOk = validateEmail(correo);
            if (isOk == false)
            {
                do
                {
                Console.Clear();
                Console.WriteLine("Ingrese nuevamente su correo");
                correo = Console.ReadLine();
                isOk = validateEmail(correo);
            
                Console.ReadKey();
                }while (isOk == false);
            }

            return correo;
        }

         public string ValidarContraseña()
        {
            string contraseña;
            int contador;
            contador = 0;
            contraseña= "";
            foreach(string item in opciones)
            {
                contador++;
                if( item=="Contraseña: ")
                {
                Console.WriteLine(item);
                Console.WriteLine("Ingrese su contraseña con 8 espacios");
                } 
            }
            contraseña = Console.ReadLine();
            do{
                if(contraseña.Length ==0)
                {

                    Console.Clear();
                    Console.WriteLine("Este cambo no puede estar vacio ");
                    Console.WriteLine("Ingrese nuevamente su contraseña");
                    Console.WriteLine("Ingrese su contraseña con 8 espacios");
                    contraseña = Console.ReadLine();
                }
                if(contraseña.Length <=7)
                {

                    Console.Clear();
                    Console.WriteLine("Ingrese nuevamente su contraseña");
                    Console.WriteLine("Ingrese su contraseña con 8 caracters o mas");
                    contraseña = Console.ReadLine();
                }
            }while (!(contraseña.Length >=8));

            return contraseña;
        }
         public string ValidarAdmi()
        {
            string esAdministrador;
            
            esAdministrador= "";
            foreach(string item in opciones)
            {
                if( item=="Es admin? (S/N): " )
                {
                Console.WriteLine(item);
                } 
            }
            esAdministrador = Console.ReadLine();

           if( esAdministrador.Length == 0)
            {
               do
                {
                Console.Clear();
                Console.WriteLine("Este cambo no puede estar vacio ");
                esAdministrador = Console.ReadLine();
                
                }while (!(esAdministrador.Length !=0));  
            }
            if(!(esAdministrador== "S"|| esAdministrador=="s"|| esAdministrador== "N"|| esAdministrador=="n") )
            {
                do
                {
                     Console.WriteLine("ingrese un dato correcto ");
                     Console.WriteLine("Solo se acepta (S/N): ");
                     esAdministrador = Console.ReadLine();
                }while(!(esAdministrador== "S"|| esAdministrador=="s"|| esAdministrador== "N"|| esAdministrador=="n") );
            }

            if(esAdministrador== "S"|| esAdministrador=="s")
            {
                esAdministrador= "S";
            }

            return esAdministrador;
        }

        public string ValidarNombrePeliculaSerie()
        {
            string nombre;
            
            nombre= "";
            foreach(string item in opciones)
            {
                if( item=="Nombre: " )
                {
                Console.WriteLine(item);
                } 
            }
            nombre = Console.ReadLine();

           if( nombre.Length == 0)
            {
               do
                {
                Console.Clear();
                Console.WriteLine("Este cambo no puede estar vacio ");
                Console.WriteLine("Ingrese nuevamente el nombre");
                nombre = Console.ReadLine();
                
                }while (!(nombre.Length !=0));  
            }
           
            return nombre;
        }
        
        public string ValidarAño()
        {
            string año;
    
            año= "";
            foreach(string item in opciones)
            {
                
                if(item ==  "Año: " )
                {
                Console.WriteLine(item);
                } 
            }
            año = Console.ReadLine();
             if( año.Length == 0)
            {
               do
                {
                Console.Clear();
                Console.WriteLine("Este cambo no puede estar vacio ");
                Console.WriteLine("Ingrese nuevamente el año");
                año = Console.ReadLine();
                
                }while (!(año.Length !=0));  
            }
           

            int numero;  
            bool result = Int32.TryParse(año, out numero);
            if((numero >=1970 && numero <=2022))
            {
                año = numero.ToString(); 
            }
            else
            {
                do
                {
                Console.WriteLine("opcion no valida");
                Console.WriteLine("vuelva a ingresar el año");
                año = Console.ReadLine();
                result = Int32.TryParse(año, out numero);

                }while(!(numero >=1970 && numero <=2022));
            }
            año = numero.ToString(); 
            
            return año;
        }
        public string ValidarClasificacion()
        {
            string clasificacion;
    
            clasificacion= "";
            foreach(string item in opciones)
            {
                
                if(item ==  "Clasificación: " )
                {
                Console.WriteLine(item);
                } 
            }
            clasificacion = Console.ReadLine();
            
           if( clasificacion.Length == 0)
            {
               do
                {
                Console.Clear();
                Console.WriteLine("Este campo no puede estar vacio ");
                 Console.WriteLine("Ingrese nuevamentel clasificación");
                clasificacion = Console.ReadLine();
                
                }while (!(clasificacion.Length !=0));  
            }
             if(!(clasificacion== "AA"|| clasificacion=="A"|| clasificacion== "B"|| clasificacion=="B15"|| clasificacion=="C" || clasificacion== "D") )
            {
                do
                {
                     Console.WriteLine("ingrese un dato correcto ");
                     Console.WriteLine("Solo se acepta estas clasificaciones");
                     Console.WriteLine("AA, A, B, B15, C, D");
                    clasificacion= Console.ReadLine();
                }while(!(clasificacion== "AA"|| clasificacion=="A"|| clasificacion== "B"|| clasificacion=="B15"|| clasificacion=="C" || clasificacion== "D"));
            }


            return clasificacion;
        }
        public string ValidarNumcapitulos()
        {
            string capitulos;
    
            capitulos= "";
            foreach(string item in opciones)
            {
                
                if(item ==  "Número de episodios de la serie: " )
                {
                Console.WriteLine(item);
                } 
            }
            capitulos = Console.ReadLine();
            
           if( capitulos.Length == 0)
            {
               do
                {
                Console.Clear();
                Console.WriteLine("Este cambo no puede estar vacio ");
                 Console.WriteLine("Ingrese nuevamentel clasificación");
                capitulos= Console.ReadLine();
                
                }while (!(capitulos.Length !=0));  
            }

           int numero;  
            bool result = Int32.TryParse(capitulos, out numero);
            if(numero >0)
            {
                capitulos=  numero.ToString(); 
            }
            else
            {
                do
                {
                Console.WriteLine("opcion no valida");
                Console.WriteLine("vuelva a ingresar los capitulos");

                capitulos = Console.ReadLine();
                result = Int32.TryParse(capitulos, out numero);
               
                
                }while(!(numero >0));
            }
            capitulos = numero.ToString(); 

            return capitulos;
        }

        public bool validateEmail(string email)
        {
            if(email == null){
                return false;
            }
            if(new EmailAddressAttribute().IsValid(email))
            {
                return true;
            }
            else
            {

                return false;
            }
        }
    }
    public class Login
    {
        Servidor MiServidor;
        Cliente MiCliente;
        Administrador MiAdministrador;
        Persona usuario;
        public Login(Servidor s, Cliente c, Administrador a)
        {
            this.MiServidor = s;
            this.MiCliente= c;
            this.MiAdministrador =a;
        }

        public void Entrar()
        {
            List<Persona> MiLista;

            usuario = new Persona();

            string correo, contraseña;

            MiLista = MiServidor.PedirListaUsuario();

            if(MiLista.Count == 0)
            {
               MiAdministrador.nuevoUsuario(); 
            }
            else
            {
                int contador;
                contador = 0;
                do
                {
                    Console.Clear();
                    if(contador >0 )
                    {
                        Console.WriteLine("Este es su intento: "+contador);
                    }
                    Console.WriteLine("[ Bienvenidos ");
                    
                    
                     string [] MisOpciones = { "Correo: ","Contraseña: "};
                    Validar MiValidar = new Validar( MisOpciones);
                        
                        correo = MiValidar.ValidarCorreo();
                        contraseña =MiValidar.ValidarContraseña();

                    usuario = MiLista.Find (x => x.Correo == correo && x.Contraseña == contraseña);

                   if( usuario != null)
                   {
                       contador = 4;
                    if(usuario.EsAdministrador )
                    {
                         MiAdministrador.Menu();
                    }
                    else
                    {
                        MiCliente.Menu();
                    }

                   }
                    else
                    {
                    
                        Console.WriteLine ("Puede volver a intertarlo");
                        Console.WriteLine("Oprima enter para continuar ...");
                        Console.ReadKey();
                        contador++;
                    }
                } while(contador != 4);
            }   
        }
    }
   
    public class Cliente
    {
        private Servidor MiServidor;
        public Cliente(Servidor s)
        {
        this.MiServidor =s;
        }
        public void Menu()
        {
            Persona MiUsuario;
            List<Pelicula> MiLista;
            List<Series> MiListaS;
            MiLista = MiServidor.PedirListaPelicula();
            MiListaS= MiServidor.PedirListaSeries();

            Console.Clear();

            
            string [] MisOpciones = { "Ver peliculas", "Ver series"};
            
            int opcion;

            Menu MiMenu = new Menu( MisOpciones, "Menu");
            Console.Clear();
            Console.WriteLine("Menu de usuarios ");
            do
            {
                opcion = MiMenu.MuestraMenu();
                if (opcion == 1)
                {
                    int numPeli;
                    numPeli = 0;
                    MiLista = MiServidor.PedirListaPelicula();
                    foreach ( Pelicula cli in MiLista)
                    {
                    numPeli++;
                    Console.WriteLine(" Nombre : "+cli.NombreP+" Clasiicación: "+ cli.Clasificacion+" Año: "+cli.Año);
                    }

                    if(MiLista.Count == 0)
                    {
                        Console.WriteLine("La lista esta vacia");
                    }
                    Console.WriteLine("Oprima enter para continuar ...");
                    Console.ReadKey();
                }
                else
                {
                    if(opcion ==2)
                    {
                        int numSerie;
                        numSerie = 0;
                       MiListaS = MiServidor.PedirListaSeries();
                            foreach ( Series cli in MiListaS)
                            {
                            numSerie++;
                            Console.WriteLine(" Nombre : "+cli.NombreS+" Año: "+ cli.Año+" Numero de episodios: "+cli.NumEpisodios);
                            }
                            if(MiLista.Count == 0)
                            {
                                Console.WriteLine("La lista esta vacia");
                            }
                            Console.WriteLine("Oprima enter para continuar ...");
                            Console.ReadKey();
                    }
                }
            }while (opcion != 0);
            MiUsuario = null;
        }

    }

    public class Administrador
    {
        private Servidor MiServidor;
        public Administrador(Servidor s)
        {
        this.MiServidor =s;
        }
        Persona MiUsuario;
         List<Persona> MiLista;
        public void nuevoUsuario()
        {
            string nombre, contraseña, correo,esAdministrador;

            Persona p = new Persona();
            MiLista = MiServidor.PedirListaUsuario();
            Console.Clear();
            Console.WriteLine("Bienvenidos ");

            string [] MisOpciones = { "Nombre de usuario: ", "Correo: ","Contraseña: ","Es admin? (S/N): "  };
            Validar MiValidar = new Validar( MisOpciones);
            nombre= MiValidar.ValidarNombre();
            correo = MiValidar.ValidarCorreo();

            if (MiServidor.ChecarCuenta(correo))
            {
                Console.WriteLine("Esta cuenta ya exixte");
                
            }
            else
            {
            contraseña = MiValidar.ValidarContraseña();
            esAdministrador = MiValidar.ValidarAdmi();
            p.Nombre = nombre;
            p.Contraseña = contraseña;
            p.Correo = correo;

            if(esAdministrador =="S" )
            {
                p.EsAdministrador = true;
            }
            else
            {
                p.EsAdministrador= false;
            }

            MiServidor.RegistrarUsuario(p);
            }

            Console.WriteLine("Oprima enter para continuar ...");
            Console.ReadKey();
            Console.Clear();
        }
        
        public void  RegistrarPelicula()
        {
             Pelicula p = new Pelicula();

            string nombreP, año, clasificacion;
            Console.Clear();
            Console.WriteLine("Bienvenidos al alta de peliculas");


            string [] MisOpciones = { "Nombre: ", "Año: ", "Clasificación: "};
            Validar MiValidar = new Validar( MisOpciones);
            nombreP = MiValidar.ValidarNombrePeliculaSerie();
            if (MiServidor.ChecarPelicula(nombreP))
            {
                Console.WriteLine("Esta pelicula ya exixte");
            }
            else
            {
            año = MiValidar.ValidarAño();
            clasificacion = MiValidar.ValidarClasificacion();
            p.NombreP = nombreP;
            p.Año = año;
            p.Clasificacion= clasificacion;
            MiServidor.RegistrarPelicula(p);
            }

           Console.WriteLine("Oprima enter para continuar ...");
        Console.ReadKey();
        }

        public void RegistrarSerie()
        {
            Series s = new Series();
            string nombreS, año, numEpisodio;
            Console.Clear();
            Console.WriteLine(" Bienvenidos ");


            string [] MisOpciones = { "Nombre: ", "Año: ","Número de episodios de la serie: "};
            Validar MiValidar = new Validar( MisOpciones);
            nombreS = MiValidar.ValidarNombrePeliculaSerie();
            if (MiServidor.ChecarSerie(nombreS))
            {
                Console.WriteLine("Esta serie ya exixte");
            }
            else
            {
            año = MiValidar.ValidarAño();
            numEpisodio = MiValidar.ValidarNumcapitulos();
            s.NombreS = nombreS;
            s.Año =año;
            s.NumEpisodios = numEpisodio;

            MiServidor.RegistrarSerie(s);
            }
            Console.WriteLine("Oprima enter para continuar ...");
            Console.ReadKey();
        }
        public void BorrarUsuario()
        {
            List<Persona> MiListaUsuario;
            MiListaUsuario = MiServidor.PedirListaUsuario();
            int numUsuario;
            numUsuario = 0;
             if(MiListaUsuario.Count <= 0 )
             {

              Console.WriteLine("Lista vacia");    
            } 
            else
            {
                if( MiListaUsuario.Count == 1 )
                {
                    Console.WriteLine("Advertencia");
                    Console.WriteLine("Solo cuenta con un usuario el cual no puede eliminarse"); 
                }
                else
                {
                    Console.WriteLine("Esta es la lista de Usuarios");
                    Console.WriteLine("-------------------------------");
                    
                    foreach ( Persona cli in MiListaUsuario)
                    {
                    numUsuario++;
                    Console.WriteLine(numUsuario+ " Nombre : "+cli.Nombre+" Correo : "+ cli.Correo+" Contraseña: "+cli.Contraseña);
                    }

                    Console.WriteLine("¿Qué elemento desea borrar?");
                    try
                    {
                        numUsuario = int.Parse (Console.ReadLine());
                    }
                    catch (FormatException error)
                    {
                         Console.WriteLine("dato erronio");
                    }
                    
                    if(numUsuario >0 && numUsuario <= MiListaUsuario.Count )
                    {
                        numUsuario -= 1;
                        MiServidor.BorrarUsuario(numUsuario);
                    }
                    else
                    {
                        Console.WriteLine("opcion no valida");
                    }
                }
                Console.WriteLine("Oprima enter para continuar ...");
                Console.ReadKey(); 
            }  

        }
        public void BorrarSerie()
        {
             List<Series> MiListaSeries;
            MiListaSeries = MiServidor.PedirListaSeries();
            int numSerie;
            numSerie = 0;
            if(MiListaSeries.Count <= 0)
            {
              Console.WriteLine("Lista vacia");    
            } 
            else
            {
             Console.WriteLine("lista de series");
            
            
            foreach ( Series cli in MiListaSeries)
            {
            numSerie++;
            Console.WriteLine(numSerie+ " Nombre : "+cli.NombreS+" Número de episodios : "+ cli.NumEpisodios+" Año: "+cli.Año);
            }

            Console.WriteLine("¿Qué elemento desea borrar?");
            try
            {
            numSerie = int.Parse (Console.ReadLine());
            }
            catch (FormatException error)
            {
             Console.WriteLine("dato erronio");
            }
                    
            if(numSerie >0 && numSerie <= MiListaSeries.Count )
             {
            numSerie -= 1;
            MiServidor.BorrarSerie(numSerie);
            }
            else
            {
            Console.WriteLine("opcion no valida");
            }
            } 
            Console.WriteLine("Oprima enter para continuar ...");
            Console.ReadKey(); 
        }
        public void BorraPelicula()
        {
            List<Pelicula> MiListaPelis;
            MiListaPelis = MiServidor.PedirListaPelicula();
            int numPeli;
             numPeli = 0;
             if(MiListaPelis.Count <= 0)
             {

              Console.WriteLine("Lista vacia");    
            } 
            else
            {
             Console.WriteLine("lista de peliculas");
            
            
            foreach ( Pelicula cli in MiListaPelis)
            {
            numPeli++;
            Console.WriteLine(numPeli+ " Nombre : "+cli.NombreP+" Clasiicación: "+ cli.Clasificacion+" Año: "+cli.Año);
            }

            Console.WriteLine("¿Qué elemento desea borrar?");
            try
            {
            numPeli = int.Parse (Console.ReadLine());
            }
            catch (Exception error)
            {
             Console.WriteLine("dato erronio");
            }
                    
            if(numPeli >0 && numPeli <= MiListaPelis.Count )
             {
            numPeli -= 1;
            MiServidor.BorrarPelicula(numPeli);
            }
            else
            {
            Console.WriteLine("opcion no valida");
            }
            }  
            Console.WriteLine("Oprima enter para continuar ...");
            Console.ReadKey(); 
        }
        public void Menu()
        {
            List<Pelicula> MiLista;
            List<Series> MiListaS;
            MiLista = MiServidor.PedirListaPelicula();
            MiListaS= MiServidor.PedirListaSeries();
            List<Persona> MiListaUsuario;
            MiListaUsuario = MiServidor.PedirListaUsuario();

            string [] MisOpciones = { "Ingresar Nuevo Usuario","Ingresar a dar alta Peliculas","Ingresar a dar alta Series", "Ingresar a ver pelis subidas", "Ingresar a ver series subidas", "Ingresar a ver usuarios", "Ingresar a borrar usuarios", "Ingresar a borrar peliculas", "Ingresar a borrar series"};
            int opcion;

            Menu MiMenu = new Menu( MisOpciones, " Menu de administrador");
            Console.Clear();
            Console.WriteLine(" Menu de administrador");
            do
            {
                opcion = MiMenu.MuestraMenu();
                if (opcion == 1)
                {
                    nuevoUsuario();
                }
                else
                {
                    if(opcion == 2)
                    {
                        RegistrarPelicula();
                    }
                    else
                    {
                        if(opcion ==3)
                        {
                            RegistrarSerie();
                        }
                        else
                        {
                            if(opcion == 4)
                            {
                                 int numPeli;
                                 numPeli = 0;
                                 MiLista = MiServidor.PedirListaPelicula();
                                foreach ( Pelicula cli in MiLista)
                                {
                                  numPeli= MiLista.IndexOf(cli) +1;
                                Console.WriteLine(numPeli+" Nombre : "+cli.NombreP+" Clasiicación: "+ cli.Clasificacion+" Año: "+cli.Año);
                                }
                                if(MiLista.Count == 0)
                                {
                                    Console.WriteLine("La lista esta vacia");
                                }
                                Console.WriteLine("Oprima enter para continuar ...");
                                Console.ReadKey();
                            }
                            else
                            {
                                if(opcion == 5)
                                {
                                    int numSerie;
                                    numSerie = 0;
                                    MiListaS = MiServidor.PedirListaSeries();
                                    foreach ( Series cli in MiListaS)
                                    {
                                        numSerie++;
                                    Console.WriteLine(numSerie+" Nombre : "+cli.NombreS+" Año: "+ cli.Año+" Numero de episodios: "+cli.NumEpisodios);
                                    }
                                    if(MiListaS.Count == 0)
                                    {
                                        Console.WriteLine("La lista esta vacia");
                                    }
                                    Console.WriteLine("Oprima enter para continuar ...");
                                    Console.ReadKey();
                                }
                                else
                                {
                                    if(opcion ==6)
                                    {
                                        foreach ( Persona cli in MiListaUsuario)
                                        {
                                        string admin;
                                        admin = "No";
                                        if(cli.EsAdministrador)
                                        {
                                            admin ="Si";
                                        }
                                        Console.WriteLine(" Nombre : "+cli.Nombre+" Correo: "+cli.Correo+" Contraseña : "+ cli.Contraseña+" Es administrador: "+admin);
                                        }
                                        Console.WriteLine("Oprima enter para continuar ...");
                                        Console.ReadKey();
                                    }
                                    else
                                    {
                                        if(opcion == 7)
                                        {
                                            BorrarUsuario();
                                        }
                                        else
                                        {
                                            if(opcion == 8)
                                            {
                                                BorraPelicula();
                                            }
                                            else
                                            {
                                                if(opcion ==9)
                                                {
                                                    BorrarSerie();
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }while (opcion != 0);
            MiUsuario = null;
        }
    }
    
     public class Servidor
    {
        public Servidor()
        {

        }

        private List<Persona> ListaUsuarios = new List<Persona>();
        private List<Pelicula> ListaPelicula = new List<Pelicula>();
        private List<Series> ListaSeries = new List<Series>();

        public void BorrarPelicula(int numPeli)
        {
            ListaPelicula.RemoveAt(numPeli);
        }

        public void BorrarSerie(int numSerie)
        {
            ListaSeries.RemoveAt(numSerie);
        }
        
        public void BorrarUsuario(int numUsuario)
        {
            ListaUsuarios.RemoveAt(numUsuario);
        }
        public void RegistrarUsuario(Persona u)
        {
            ListaUsuarios.Add(u);
        }

        public List<Persona> PedirListaUsuario()
        {
            return ListaUsuarios;
        }

    
         public void RegistrarPelicula(Pelicula p)
        {
            ListaPelicula.Add(p);
        }

        public List<Pelicula> PedirListaPelicula()
        {
            return ListaPelicula;
        }

        public void RegistrarSerie(Series s)
        {
            
            ListaSeries.Add(s);
        }

        public List<Series> PedirListaSeries()
        {
            return ListaSeries;
        }

        public Boolean ChecarCuenta(string correo)
        {
            Boolean existe = false;
                if(ListaUsuarios.Exists(x => x.Correo== correo)) 
                {
                   existe = true;
                }
            return existe;
        }

        public Boolean ChecarPelicula(string nombreP)
        {
            Boolean existe = false;
                if(ListaPelicula.Exists(x => x.NombreP== nombreP)) 
                {
                   existe = true;
                }
            return existe;
        }
        public Boolean ChecarSerie(string nombreS)
        {
            Boolean existe = false;
                if(ListaSeries.Exists(x => x.NombreS== nombreS)) 
                {
                   existe = true;
                }
            return existe;
        }

    }

    public class Pelicula
    {
        private string nombreP;
        public string NombreP
        {
            get
            {
                return nombreP;

            }
            set
            {
                nombreP = value;
            }

        }

        private string año;
        public string Año
        {
            get
            {
                return año;

            }
            set
            {
                año = value;
            }

        }

        private string clasificacion;
        public string Clasificacion
        {
            get
            {
                return clasificacion;

            }
            set
            {
                clasificacion = value;
            }

        }
    }
    public class Series
    {
         private string nombreS;
        public string NombreS
        {
            get
            {
                return nombreS;

            }
            set
            {
                nombreS = value;
            }

        }
        private string año;
        public string Año
        {
            get
            {
                return año;

            }
            set
            {
                año = value;
            }

        }

        private string numEpisodios;
        public string NumEpisodios
        {
            get
            {
                return numEpisodios;

            }
            set
            {
                numEpisodios = value;
            }

        }

    }

    public class Persona
    {

        private string nombre;
        public string Nombre
        {
            get
            {
                return nombre;

            }
            set
            {
                nombre = value;
            }

        }

        private string contraseña;
        public string Contraseña
        {
            get
            {
                return contraseña;

            }
            set
            {
                contraseña = value;
            }

        }

        private string correo;
        public string Correo
        {
            get
            {
                return correo;

            }
            set
            {
                correo = value;
            }

        }

        private bool esAdministrador;
        public bool EsAdministrador
        {
             get
            {
                return esAdministrador;

            }
            set
            {
                esAdministrador = value;
            }
        }

    }
}