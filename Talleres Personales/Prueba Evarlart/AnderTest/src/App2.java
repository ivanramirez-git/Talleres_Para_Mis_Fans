import java.util.ArrayList;
import java.util.List;

public class App2 {
    public static void main(String[] args) throws Exception {
        /*
        Tiene un arreglo (llamado myArray) con 10 elementos (enteros en el rango de 1 a 9). Escriba un programa en Java que imprima el número que tiene más ocurrencias seguidas en el arreglo y también imprimir la cantidad de veces que aparece en la secuencia.

        El código que llena el arreglo ya está escrito, pero puede editarlo para probar con otros valores. Con el botón de refrescar puede recuperar el valor original que será utilizado para evaluar la pregunta como correcta o incorrecta durante la ejecución.

        Su programa debe analizar el arreglo de izquierda a derecha para que en caso de que dos números cumplan la condición, el que aparece por primera vez de izquierda a derecha será el que se imprima. La salida de los datos para el arreglo en el ejemplo (1,2,2,5,4,6,7,8,8,8) sería la siguiente:
        Longest: 3
        Number: 8

        En el ejemplo, la secuencia más larga la tiene el número 8 con una secuencia de tres ochos seguidos. Tenga en cuenta que el código que escriba debe imprimir los resultados exactamente como se muestra con el fin de que la pregunta sea considerada válida.

        El código para declarar y poblar myArray ya está ahí, puede editarlo para probar con otros valores y puede hacer clic en el botón de actualizar junto a él para volver al valor original que se utilizará para validar su código durante la prueba.

        Nota: Asumir que esta escribiendo el codigo dentro de una clase Main, por lo que no debe declarar la clase Main, pero si el metodo public static void main para ejecutar su código. Java util ya está importado, no requiere importar esta ni ninguna otra librería.
        */
        final int[] myArray =  {1,2,2,2,2,4,5,6,6,6,6,6,7,8,8,8};
        int[] longests = new int[myArray.length];
        int[] numbers = new int[myArray.length];
        int tam = 0;
        for (int i = 0; i < myArray.length; i++) {
            int count = 1;
            for (int j = i + 1; j < myArray.length; j++) {
                if (myArray[i] == myArray[j]) {
                    count++;
                } else {
                    break;
                }
            }
            if (count > tam) {
                tam = count;
                longests[0] = count;
                numbers[0] = myArray[i];
            } else if (count == tam) {
                longests[tam] = count;
                numbers[tam] = myArray[i];
            }
        }
        System.out.println("Longest: " + tam);
        System.out.println("Number: " + numbers[0]);

    }
}
