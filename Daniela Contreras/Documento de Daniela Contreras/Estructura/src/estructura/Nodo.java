/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package estructura;

/**
 *
 * @author Oscar Perez
 */
public class Nodo {
    private Object dato;
    private Nodo sig;
    // metodo que inicializa las varibles o constructor
    public Nodo(Object dato, Nodo sig) {
        this.dato = dato;
        this.sig = sig;
    }
    public Nodo() {
        this.dato = null;
        this.sig = null;
    }
    //metodo que recibe la informacion de las variables Set
    public void setDato(Object dato) {
        this.dato = dato;
    }
    public void setSig(Nodo sig) {
        this.sig = sig;
    }
    //metodo que envia la informacion de las variables o Get
    public Object getDato() {
        return dato;
    }
    public Nodo getSig() {
        return sig;
    }

    //metodo que cambia el valor de la variable sig
    public void setSiguiente(Nodo cabeza){
        this.sig = cabeza;
    }
}
