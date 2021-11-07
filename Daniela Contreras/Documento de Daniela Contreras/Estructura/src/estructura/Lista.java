/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package estructura;

/**
 *
 * @author Oscar Perez
 */
public class Lista {
    private Nodo cabeza,fin;
    //metodo que inicializa las variables o constructor
    public Lista(Nodo cabeza, Nodo fin) {
        this.cabeza = cabeza;
        this.fin = fin;
    }
    public Lista() {
        this.cabeza = null;
        this.fin = null;
    }
    //los metodos que recibe el apuntador cadeza y final de la Lista o Set
    public void setCabeza(Nodo cabeza) {
        this.cabeza = cabeza;
    }
    public void setFin(Nodo fin) {
        this.fin = fin;
    }
    //metodos que envian el apuntador cabeza y fin de la Lista o Get
    public Nodo getCabeza() {
        return cabeza;
    }
    public Nodo getFin() {
        return fin;
    }
    //Metodo que adiciona un Nodo al final de la Lista
    public void adicionarFinal(Nodo n){
        if(cabeza == null){
            cabeza = n;
            fin = n;
        }
        else{
            fin.setSig(n);
            fin = n;
        }
    }
    //Metodo que adiciona un Nodo al principo de la Lista
    public void adicionarPrincipio(Nodo n){
        if(cabeza == null){
            cabeza = n;
            fin = n;
        }
        else{
            n.setSig(cabeza);
            cabeza = n;
        }
    }
    //Metodo que busca un dato en la Lista, y se lo encuentra envia el nodo donde esta el dato
    public Nodo buscar(Object dato){
        Nodo actual = cabeza;
        while(true){
            if(actual == null){
                return null;
            }
            else{
                if((int)dato == (int)actual.getDato()){
                    return actual;
                }
                else{
                   actual = actual.getSig();//permtir que actual tenga la direccion del siguiente nodo
                }
            }
        }
    }
    //Metodo recursivo Buscar
    public Nodo BuscarRecursivamente(Object dato){
        return BuscarRecursivamente(dato,cabeza);//llamar metodo recursivo
    }
    private Nodo BuscarRecursivamente(Object dato, Nodo actual){
       if(actual == null){
          return null;
       }
       else{
          if((int)dato == (int)actual.getDato()){
             return actual;
          }
          else{
             return BuscarRecursivamente(dato,actual.getSig()); 
          }
       }
    }
    public boolean eliminar(Object dato){
        Nodo act = cabeza,ant = null;
        while (true){
           if(act == null){
              return false; 
           }
           else{
               if((int)dato == (int)act.getDato()){
                  if(act == cabeza){
                    cabeza = act.getSig();
                    act.setSig(null);
                    return true;  
                  }
                  else{
                    ant.setSig(act.getSig());
                    if(act == fin){
                       fin = ant;
                    }
                    return true;  
                  }
               }
               else{
                  ant = act;
                  act = act.getSig();
               }
           }
        }
    }
    //Metodo recursivo eliminar
    public boolean eliminarRecursivamente(Object dato){
       return eliminarRecursivamente(dato,cabeza); 
    }
    private boolean eliminarRecursivamente(Object dato, Nodo actual){
       //aqui debes implementar el codigo recursivo basado en el metodo eliminar que esta arriba 
       return false;//se coloco esta intruccion momentaniamente para que no marcara error
    }
    public boolean modificar(Object dato_buscar,Object dato_modificar){
        Nodo actual = buscar(dato_buscar);
        if(actual == null){
            return false;
        }
        else{
            actual.setDato(dato_modificar);//aqui se modifica
            return true;
        }
    }
    public void mostrar(){
        Nodo actual = cabeza;
        while(true){
            if(actual == null){
                break;
            }
            else{
                System.out.println((int)actual.getDato());
                actual = actual.getSig();
            }
        }
    }
    public void mostrarRecursivamente(){
        mostrarRecursivamente(cabeza);
    }
    private void mostrarRecursivamente(Nodo actual){
        if(actual != null){
          System.out.println((int)actual.getDato());
          mostrarRecursivamente(actual.getSig());//llamamiento recursivo
        }
    }
}
