/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package estructura;

import java.util.Scanner;

/**
 *
 * @author Oscar Perez
 */
public class Estructura {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        // Crear dos listas donden se guarde datos de nuneros enteros, y luego 
        // crear otra lista donde se guarde los datos comunes de las dos listas
        // anteriores.
        Scanner entrada = new Scanner(System.in);
        Lista a = new Lista(null,null);
        Lista b = new Lista(null,null);
        Lista c;
        int dato;
        while(true){
            System.out.print("Ingrese un dato entero (0 - termina):");
            dato = entrada.nextInt();
            if(dato == 0){
                break;// termina el ciclo
            }
            else{
               Nodo n = new Nodo(null,null);
               n.setDato(dato);
               a.adicionarFinal(n);
            }
        }
        while(true){
            System.out.print("Ingrese un dato entero (0 - termina):");
            dato = entrada.nextInt();
            if(dato == 0){
                break;// termina el ciclo
            }
            else{
               Nodo n = new Nodo(null,null);
               n.setDato(dato);
               b.adicionarFinal(n);
            }
        }
        
        System.out.println("Mostrando los datos de la lista");
        b.mostrar();
    }
}
