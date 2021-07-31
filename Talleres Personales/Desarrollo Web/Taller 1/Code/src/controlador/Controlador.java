package controlador;

import modelo.Libreria;
import vista.Vista;

import java.util.Scanner;

public class Controlador {

    private Libreria DesarrolloWeb=new Libreria();
    private Vista vista=new Vista();

    public Controlador() {

        Scanner entrada = new Scanner(System.in);
        boolean noSalir;

        int numero;
        String texto;

        String objetos[]={"","",""};
        int objetosNum[]={0,0,0};

        do{
            noSalir=true;
            vista.menu();
            numero=entrada.nextInt();
            switch (numero) {
                case 0:
                       noSalir=false;
                    break;
                case 1:
                    // Crear un Libro

                    vista.mensaje("Por favor ingrese el nombre del libro: ");
                    objetos[0]=entrada.next();

                    vista.mensaje("Por favor ingrese la descripcion del libro: ");
                    objetos[1]=entrada.next();

                    vista.mensajeendl("Por favor ingrese el nombre y apellido del autor del libro: ");
                    vista.mensaje("Nombre: ");
                    objetos[2]=entrada.next();
                    vista.mensaje("Apellido: ");
                    objetos[2]=(objetos[2]+" "+entrada.next());

                    vista.mensaje("Por favor ingrese el precio del libro: ");
                    objetosNum[0]=entrada.nextInt();

                    vista.mensaje("Por favor ingrese el año de publicacion del libro: ");
                    objetosNum[1]=entrada.nextInt();

                    vista.mensaje("Por favor ingrese el numero de paginas del libro: ");
                    objetosNum[2]=entrada.nextInt();

                    if(DesarrolloWeb.crearLibro(objetos[0],objetos[1],objetos[2],objetosNum[0],objetosNum[1],objetosNum[2])) {
                        vista.mensajeendl("El libro fue agregado correctamente.");
                    }else{
                        vista.mensajeendl("El libro no fue agregado");
                    }

                    break;
                case 2:
                    // Listar libros por autor
                    vista.mensajeendl("Indique el nombre y apellido del autor de los libros que desea detallar: ");
                    vista.mensaje("Nombre: ");
                    texto=entrada.next();
                    vista.mensaje("Apellido: ");
                    texto=(texto+" "+entrada.next());

                    vista.mensajeendl(DesarrolloWeb.listarLibrosAutor(texto));

                    break;
                case 3:
                    // Detallar un libro
                    vista.mensaje("Indique el nombre del libro que desea detallar: ");
                    texto=entrada.next();

                    vista.mensajeendl(DesarrolloWeb.detallarLibro(texto));

                    break;
                default:
                    // Opcion inválida
                    vista.mensajeendl("Opcion invalida.");
                    break;
            }
        }while (noSalir);

    }
}
