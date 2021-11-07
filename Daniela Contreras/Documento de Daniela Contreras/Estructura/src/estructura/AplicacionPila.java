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
public class AplicacionPila {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Pila p = new Pila(null);
        int dato;
        //ingresar datos a la Lista
        while(true){
            System.out.print("Digte un dato (0-termina):");
            dato = entrada.nextInt();
            if(dato == 0){
                break;
            }
            else{
                Nodo n = new Nodo(null,null);
                n.setDato(dato);
                p.adicionarPrincipio(n);                
            }
        }
        System.out.println("Mostrar datos de la pila");
        p.mostrar();
    }
}
