import java.util.ArrayList;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        /*
        MENU PRINCIPAL
        1.	ESTUDIANTE
        2.	PROFESOR
        3.	SALIR
        */
        int opcion = 0;
        Scanner sc = new Scanner(System.in);
        ArrayList<Estudiante> estudiantes = new ArrayList<Estudiante>();
        do {
            System.out.println("MENU PRINCIPAL");
            System.out.println("1.	ESTUDIANTE");
            System.out.println("2.	PROFESOR");
            System.out.println("3.	SALIR");
            System.out.println("Ingrese una opcion: ");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:
                    /*
                    Si se escoge la opción 1, debe desplegarse el siguiente menú:
                        1.	SOLICITAR PRUEBA
                        2.	VERIFICAR CALIFICACIONES (estas se pueden verificar después de que el profesor ingrese la información del estudiante).
                        3.	SALIR
                    */
                    int opcionEstudiante = 0;
                    do {
                        System.out.println("MENU ESTUDIANTE");
                        System.out.println("1.	SOLICITAR PRUEBA");
                        System.out.println("2.	VERIFICAR CALIFICACIONES");
                        System.out.println("3.	SALIR");
                        System.out.println("Ingrese una opcion: ");
                        opcionEstudiante = sc.nextInt();
                        switch (opcionEstudiante) {
                            case 1:
                                /*
                                Si escoge la opción 1, debe solicitar el nombre, apellido, edad, cedula del estudiante.
                                    Verificar que el estudiante tenga 17 años en adelante para poder rendir la prueba
                                    •	Si la cédula termina en 0-1, puede rendir la prueba el lunes.
                                    •	Si termina en 2-3, puede rendir la prueba el martes.
                                    •	Si termina en 4-5, puede rendir la prueba el miércoles.
                                    •	Si termina en 6-7, puede rendir la prueba el jueves.
                                    •	Si termina en 8-9, puede rendir la prueba el viernes.
                                */
                                System.out.println("Ingrese el nombre del estudiante: ");
                                String nombre = sc.next();
                                System.out.println("Ingrese el apellido del estudiante: ");
                                String apellido = sc.next();
                                System.out.println("Ingrese la edad del estudiante: ");
                                int edad = sc.nextInt();
                                System.out.println("Ingrese la cedula del estudiante: ");
                                int cedula = sc.nextInt();
                                if (edad >= 17) {
                                    switch (cedula % 10) {
                                        case 0:
                                        case 1:
                                            System.out.println("El estudiante puede rendir la prueba el lunes");
                                            break;
                                        case 2:
                                        case 3:
                                            System.out.println("El estudiante puede rendir la prueba el martes");
                                            break;
                                        case 4:
                                        case 5:
                                            System.out.println("El estudiante puede rendir la prueba el miércoles");
                                            break;
                                        case 6:
                                        case 7:
                                            System.out.println("El estudiante puede rendir la prueba el jueves");
                                            break;
                                        case 8:
                                        case 9:
                                            System.out.println("El estudiante puede rendir la prueba el viernes");
                                            break;
                                    }
                                // Agregar el estudiante a la lista de estudiantes
                                estudiantes.add(new Estudiante(nombre, apellido, edad, cedula));
                                } else {
                                    System.out.println("El estudiante no puede rendir la prueba");
                                }
                                break;
                            case 2:
                                /*
                                Si escoge la opción 2, desplegar la información de todos los estudiantes que rindieron la prueba, con su respectiva información, e informando si aprobaron o no.
                                (Solo se aprueba si la calificación es mayor a 15)
                                Ejemplo:
                                NOMBRE                   EDAD        CÉDULA          CALIFICACIÓN          RESULTADO
                                Espinoza Dennys        18        1728438464               13                USTED REPROBO 
                                Flores Viviana             19        1734324324               17                USTED APROBO
                                */
                                System.out.println("NOMBRE                   EDAD        CÉDULA          CALIFICACIÓN          RESULTADO");
                                for (Estudiante estudiante : estudiantes) {
                                    if (estudiante.isCalificacion()) {
                                        if (estudiante.getCalificacion() > 15) {
                                            System.out.println(estudiante.getNombre() + " " + estudiante.getApellido() + " " + estudiante.getEdad() + " " + estudiante.getCedula() + " " + estudiante.getCalificacion() + " " + "USTED APRUEBO");
                                        } else {
                                            System.out.println(estudiante.getNombre() + " " + estudiante.getApellido() + " " + estudiante.getEdad() + " " + estudiante.getCedula() + " " + estudiante.getCalificacion() + " " + "USTED REPROBO");
                                        }
                                    }
                                }
                                break;
                            case 3:
                                System.out.println("Saliendo...");
                                break;
                            default:
                                System.out.println("Opcion incorrecta");
                                break;
                        }
                    } while (opcionEstudiante != 3);
                    
                    break;
                case 2:
                    /*
                    Si se escoge la opción 2, debe desplegarse el siguiente menú:
                        1.	INGRESO DE INFORMACION DEL ESTUDIANTE
                        2.	PROMEDIO FINAL 
                        3.	SALIR
                    */
                    int opcionProfesor = 0;
                    do {
                        System.out.println("MENU PROFESOR");
                        System.out.println("1.	INGRESO DE INFORMACION DEL ESTUDIANTE");
                        System.out.println("2.	PROMEDIO FINAL");
                        System.out.println("3.	SALIR");
                        System.out.println("Ingrese una opcion: ");
                        opcionProfesor = sc.nextInt();
                        switch (opcionProfesor) {
                            case 1:
                                /*
                                    Si escoge la opción 1, solicitar nombre, apellido, edad, cedula y calificación del estudiante
                                */
                                System.out.println("Ingrese la ceula del estudiante: ");
                                int cedula = sc.nextInt();
                                boolean encontrado = false;
                                for (Estudiante estudiante : estudiantes) {
                                    if (estudiante.getCedula() == cedula) {
                                        // Impimir la información del estudiante
                                        System.out.println("NOMBRE: " + estudiante.getNombre());
                                        System.out.println("APELLIDO: " + estudiante.getApellido());
                                        System.out.println("EDAD: " + estudiante.getEdad());
                                        System.out.println("CÉDULA: " + estudiante.getCedula());
                                        System.out.println("");
                                        System.out.println("Ingrese la calificación del estudiante: ");
                                        int calificacion = sc.nextInt();
                                        estudiante.setCalificacionNota(calificacion);
                                        estudiante.setCalificacion(true);
                                        encontrado = true;
                                    }
                                }
                                if (!encontrado) {
                                    System.out.println("El estudiante no se encuentra registrado");
                                    // Mostrar lista de estudiantes
                                    for (Estudiante estudiante : estudiantes) {
                                        System.out.println(estudiante.getNombre() + " " + estudiante.getApellido() + " " + estudiante.getEdad() + " " + estudiante.getCedula());
                                    }
                                }
                                break;
                            case 2:
                                /*
                                    Si escoge la opción 2, se desplegará un promedio global de todas las calificaciones, e indicar la calificación más alta.
                                */
                                int suma = 0;
                                int contador = 0;
                                Estudiante indice = estudiantes.get(0);
                                for (Estudiante estudiante : estudiantes) {
                                    if (estudiante.isCalificacion()) {
                                        suma += estudiante.getCalificacionNota();
                                        contador++;
                                    }
                                }
                                double promedio = (double) suma / contador;
                                
                                System.out.println("El promedio global de todas las calificaciones es: " + promedio);
                                
                                for (Estudiante estudiante : estudiantes) {
                                    if (estudiante.isCalificacion()) {
                                        if (estudiante.getCalificacionNota() > indice.getCalificacionNota()) {
                                            indice = estudiante;
                                        }
                                    }
                                }

                                System.out.println("La calificación más alta es: " + indice.getCalificacionNota());
                                System.out.println("El estudiante con la calificación más alta es: " + indice.getNombre() + " " + indice.getApellido());

                                break;
                            case 3:
                                System.out.println("Saliendo...");
                                break;
                            default:
                                System.out.println("Opcion incorrecta");
                                break;
                        }
                    } while (opcionProfesor != 3);
                    break;
                case 3:
                    System.out.println("Saliendo...");
                    // Cerrar el Scanner
                    sc.close();
                    break;
                default:
                    System.out.println("Opcion no valida");
                    break;
            }
        } while (opcion != 3);
    }
}
