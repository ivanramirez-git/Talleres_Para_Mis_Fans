/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package estructura;

/**
 *
 * @author Oscar Perez
 */
public class Cola {
    private Nodo cabeza, fin;

    public Cola(Nodo cabeza, Nodo fin) {
        this.cabeza = cabeza;
        this.fin = fin;
    }

    public Nodo getCabeza() {
        return cabeza;
    }

    public void setCabeza(Nodo cabeza) {
        this.cabeza = cabeza;
    }

    public Nodo getFin() {
        return fin;
    }

    public void setFin(Nodo fin) {
        this.fin = fin;
    }
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
    public Nodo eliminarFinal(){
        Nodo ant = null,act = this.cabeza;
        while(true){
            if(act == null){
                return null;
            }
            else{
                if(act == fin){
                  ant.setSig(null);
                  fin = ant;
                  return act;
                }
                else{
                  ant = act;
                  act = act.getSig();
                }
            
            }
        }
    }
    
}
