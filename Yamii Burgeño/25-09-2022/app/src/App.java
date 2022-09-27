public class App {
    /*
     * Crear una clase con su constructor, destructor.
     * •un Método que reciba como parametros dos variables, las asigne a las
     * variables locales.
     * •instanciar esa clase y mandar llamar al método creado en ella para mostrar
     * resultado en pantalla (mostrar su nombre completo, fecha y grupo).
     * •Documentar todo el código.
     * 
     */
    public static void main(String[] args) throws Exception { // Función principal
        System.out.println("Hello, World!"); // Imprime en pantalla un mensaje de bienvenidas
        Persona persona = new Persona(); // Instancia de la clase Persona
        persona.setNombre("Juan"); // Asigna el nombre Juan a la variable nombre
        persona.setApellido("Perez"); // Asigna el apellido Perez a la variable apellido
        persona.setFechaNacimiento("01/01/2000"); // Asigna la fecha de nacimiento 01/01/2000 a la variable fechaNacimiento
        persona.setGrupo("1CM1"); // Asigna el grupo 1CM1 a la variable grupo
        System.out.println(persona.getNombre() + " " + persona.getApellido() + " " + persona.getFechaNacimiento() + " " 
                + persona.getGrupo()); // Imprime en pantalla el nombre, apellido, fecha de nacimiento y grupo
    }

    public static class Persona { // Clase Persona
        // Atibutos privados de la clase Persona
        private String nombre; // Variable nombre
        private String apellido; // Variable apellido
        private String fechaNacimiento; // Variable fechaNacimiento
        private String grupo; // Variable grupo

        // Constructor de la clase Persona
        public Persona() {
            System.out.println("Constructor"); // Imprime en pantalla el mensaje Constructor
        }

        // Constructor de la clase Persona con parámetros
        public Persona(String nombre, String apellido, String fechaNacimiento, String grupo) {
            this.nombre = nombre; // Asigna el valor del parámetro nombre a la variable nombre
            this.apellido = apellido; // Asigna el valor del parámetro apellido a la variable apellido
            this.fechaNacimiento = fechaNacimiento; // Asigna el valor del parámetro fechaNacimiento a la variable fechaNacimiento
            this.grupo = grupo; // Asigna el valor del parámetro grupo a la variable grupo
        }

        // Metodos get y set de la clase Persona
        public String getNombre() { // Método getNombre
            return nombre; // Regresa el valor de la variable nombre
        } 

        public void setNombre(String nombre) { // Método setNombre
            this.nombre = nombre; // Asigna el valor del parámetro nombre a la variable nombre
        }

        public String getApellido() { // Método getApellido
            return apellido; // Regresa el valor de la variable apellido
        }

        public void setApellido(String apellido) { // Método setApellido
            this.apellido = apellido; // Asigna el valor del parámetro apellido a la variable apellido
        }

        public String getFechaNacimiento() { // Método getFechaNacimiento
            return fechaNacimiento; // Regresa el valor de la variable fechaNacimiento
        }

        public void setFechaNacimiento(String fechaNacimiento) { // Método setFechaNacimiento
            this.fechaNacimiento = fechaNacimiento; // Asigna el valor del parámetro fechaNacimiento a la variable fechaNacimiento
        }

        public String getGrupo() { // Método getGrupo
            return grupo; // Regresa el valor de la variable grupo
        }

        public void setGrupo(String grupo) { // Método setGrupo
            this.grupo = grupo; // Asigna el valor del parámetro grupo a la variable grupo
        }

        // Destructor de la clase Persona
        @Override
        protected void finalize() throws Throwable { // Método finalize
            System.out.println("Destructor"); // Imprime en pantalla el mensaje Destructor
            super.finalize(); // Llama al método finalize de la clase padre
        }
    }
}
