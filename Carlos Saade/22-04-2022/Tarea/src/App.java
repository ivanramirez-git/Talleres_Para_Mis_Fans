import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {

        // Scanner
        Scanner sc = new Scanner(System.in);
        
        // Nombre, Materia, Calificaciones1, Calificaciones2, Calificaciones3
        String nombres[];
        String materias[];
        float calificaciones1[];
        float calificaciones2[];
        float calificaciones3[];
        int numAlumnos;

        // Lectura de datos
        System.out.println("Ingrese el numero de alumnos: ");
        numAlumnos = sc.nextInt();
        nombres = new String[numAlumnos];
        materias = new String[numAlumnos];
        calificaciones1 = new float[numAlumnos];
        calificaciones2 = new float[numAlumnos];
        calificaciones3 = new float[numAlumnos];

        for (int i = 0; i < numAlumnos; i++) {
            System.out.println("Ingrese el nombre del alumno: ");
            nombres[i] = sc.next();
            System.out.println("Ingrese la materia del alumno: ");
            materias[i] = sc.next();
            do{
                
                System.out.println("Ingrese la calificacion 1 del alumno: ");
                calificaciones1[i] = sc.nextFloat();
            }while(calificaciones1[i] < 0 || calificaciones1[i] > 10);
            do{
                System.out.println("Ingrese la calificacion 2 del alumno: ");
                calificaciones2[i] = sc.nextFloat();
            }while(calificaciones2[i] < 0 || calificaciones2[i] > 10);
            do{
                System.out.println("Ingrese la calificacion 3 del alumno: ");
                calificaciones3[i] = sc.nextFloat();
            }while(calificaciones3[i] < 0 || calificaciones3[i] > 10);

        }

        // Obtener la suma de las actividades
        float sumaActividades = 0;
        for (int i = 0; i < numAlumnos; i++) {
            sumaActividades += calificaciones1[i] + calificaciones2[i] + calificaciones3[i];
        }
        System.out.println("La suma de las actividades es: " + sumaActividades);

        // Conocer el promedio de las actividades
        float promedioActividades = sumaActividades / numAlumnos;
        System.out.println("El promedio de las actividades es: " + promedioActividades);

        // Conocer el porcentaje de cada calificacion de cada alumno
        float porcentajeCalificaciones[] = new float[numAlumnos];
        for (int i = 0; i < numAlumnos; i++) {
            System.out.println("El porcentaje de la calificaciones del alumno " + nombres[i] + " es: ");
            // Solo tiene el 100% si saca 10 en las tres actividades
            porcentajeCalificaciones[i] = (calificaciones1[i] + calificaciones2[i] + calificaciones3[i]) / 30 * 100;
            System.out.println(porcentajeCalificaciones[i] + "%");
        }

        // Conocer el promedio de cada alumno
        float promedioAlumnos[] = new float[numAlumnos];
        for (int i = 0; i < numAlumnos; i++) {
            promedioAlumnos[i] = (calificaciones1[i] + calificaciones2[i] + calificaciones3[i]) / 3;
            System.out.println("El promedio del alumno " + nombres[i] + " es: " + promedioAlumnos[i]);
        }
        
        // Imprimir todos los datos
        System.out.println("Nombre\tMateria\tCalificacion1\tCalificacion2\tCalificacion3\tPromedio\tPorcentaje");
        for (int i = 0; i < numAlumnos; i++) {
            System.out.println(nombres[i] + "\t" + materias[i] + "\t" + calificaciones1[i] + "\t" + calificaciones2[i] + "\t" + calificaciones3[i] + "\t" + promedioAlumnos[i] + "\t" + porcentajeCalificaciones[i]);
        }
        
    }
}
