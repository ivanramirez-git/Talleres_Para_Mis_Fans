/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package estructura;

/**
 *
 * @author Oscar Perez
 */
public class Pila {
   private Nodo cabeza;
   //constructor
   public Pila(Nodo cabeza) {
        this.cabeza = cabeza;
   }
   //get
   public Nodo getCabeza() {
        return cabeza;
   }
   //set
   public void setCabeza(Nodo cabeza) {
        this.cabeza = cabeza;
   }
   //Meter datos
   public void adicionarPrincipio(Nodo n){
        if(this.cabeza == null){
            cabeza = n;
        }
        else{
            n.setSig(cabeza);
            cabeza = n;
        }
   }
   //Sacar
   public Nodo eliminarPrincipio(){
        Nodo act = this.cabeza;
        if(act == null){
           return null;
        }
        else{
           cabeza = act.getSig();
           act.setSig(null);
           return act;
        }
   }
   public void mostrar(){
       Nodo act;
       while(true){
           act = this.eliminarPrincipio();
           if(act == null){
               break;
           }
           else{
               System.out.println(act.getDato());
           }
       }
   }
   
}
