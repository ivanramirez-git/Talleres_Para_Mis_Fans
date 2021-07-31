package modelo;

import java.util.Calendar;
import java.util.Date;
import java.util.Vector;

public class Libreria {

    private Vector<Libro> libros;

    public Libreria() {
        libros = new Vector<Libro>();
    }

    public boolean crearLibro(String titulo, String descripcion, String autor, int precio, int anoPublicacion, int paginas) {
        boolean noFallo=true;
        // El título debe tener mínimo 5 caracteres y máximo 100 caracteres
        if(!(noFallo && (titulo.length()<=100 && titulo.length()>=5 ))){
            //System.out.println("Fallo el nombre");
            noFallo=false;
        }
        // La descripción no puede tener más de 200 caracteres
        if(!(noFallo && (descripcion.length()<=200))){
            //System.out.println("Fallo la descripcion");
            noFallo=false;
        }
        // El precio debe ser positivo, mayor a 10000 pesos y sin centavos
        if(!(noFallo && (precio>10000))){
            //System.out.println("Fallo el precio");
            noFallo=false;
        }
        // El autor debe tener un nombre y un apellido
        if(!(noFallo && (contarPalabras(autor)==2))){
            //System.out.println("Fallo el autor");
            noFallo=false;
        }
        // El año de publicación debe ser un valor de año valido, no superior al año actual y con 4 dígitos
        if(!(noFallo && (anoPublicacion<=anoActual() && anoPublicacion>999))){
            //System.out.println("Fallo el año");
            noFallo=false;
        }
        // Las páginas deben ser numéricas positivas, y no pueden superar las 1500 páginas
        if(!(noFallo && (paginas<=1500 && paginas>0))){
            //System.out.println("Fallo las paginas");
            noFallo=false;
        }

        if(noFallo){
            Libro temporal=new Libro(titulo,descripcion,autor,precio,anoPublicacion,paginas);
            libros.add(temporal);
        }

        return noFallo;
    }

    public String listarLibrosAutor(String nombre){
        String texto="Titulo        Autor";

        for (int i=0; i<libros.size(); i++){
            if(libros.get(i).getAutor().equals(nombre)) {
                texto = texto + "\n" + libros.get(i).getTitulo() +"         "+ libros.get(i).getAutor();
            }
        }
        if(texto.equals("Titulo        Autor"))
            return "No existen el libros";
        return texto;
    }

    public String detallarLibro(String nombre) {

        for (int i=0; i<libros.size(); i++){
            if(libros.get(i).getTitulo().equals(nombre)) {
                return libros.get(i).toString();
            }
        }
        return "No existe el libro";
    }

    // Método que devuelve el año actual
    private int anoActual(){
        Date date = new Date();
        Calendar calendar = Calendar.getInstance();

        calendar.setTime(date);
        int dateYear = calendar.get(Calendar.YEAR);
        //System.out.println(dateYear);
        return dateYear;
    }

    // Método que recibe un String y devuelve el número de palabras que contiene
    private int contarPalabras(String s) {
        int contador = 1, pos;
        s = s.trim(); //eliminar los posibles espacios en blanco al principio y al final
        if (s.isEmpty()) { //si la cadena está vacía
            contador = 0;
        } else {
            pos = s.indexOf(" "); //se busca el primer espacio en blanco
            while (pos != -1) {   //mientras que se encuentre un espacio en blanco
                contador++;    //se cuenta una palabra
                pos = s.indexOf(" ", pos + 1); //se busca el siguiente espacio en blanco
            }                                     //a continuación del actual
        }
        return contador;

        /*
         * Tomado de: http://puntocomnoesunlenguaje.blogspot.com/2015/01/contar-palabras-frase-java.html#:~:text=%C3%9Altima%20entrada-,Contar%20el%20n%C3%BAmero%20de%20palabras%20de%20una%20frase%20en%20Java,es%20utilizando%20la%20clase%20StringTokenizer.
         *
         * */
    }
}
