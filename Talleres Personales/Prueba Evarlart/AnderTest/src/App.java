public class App {
    public static void main(String[] args) throws Exception {
        /*
         Tienes un arreglo (llamado myArray) con 5 elementos (enteros en el rango de 1 a 100). Escribe un programa en Java que imprima el número más alto del arreglo (Si se repite, solo imprimir una vez). El programa solo debe imprimir el número, sin ningún texto.

        El código que llena el arreglo ya está escrito, pero puedes editarlo para probar con otros valores. Con el botón de refrescar puedes recuperar el valor original que será utilizado para evaluar la pregunta como correcta o incorrecta durante la ejecución.

        Nota: Asumir que esta escribiendo el codigo dentro de una clase Main, por lo que no debe declarar la clase Main, pero si el metodo public static void main para ejecutar su código. Java util ya está importado, no requiere importar esta ni ninguna otra librería.
         */
        final int[] myArray = {13,2,4,35,55,1};
        int max = myArray[0];
        for (int i = 0; i < myArray.length; i++) {
            if (myArray[i] > max) {
                max = myArray[i];
            }
        }
        System.out.println(max);

    }
}
