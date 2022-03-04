
package volumen;

import java.util.Scanner;


public class ControladorVolumen {
    VolumenCilindro objeto1=new VolumenCilindro();
    double h,rad;
    
    Scanner capturar=new Scanner(System.in);
    
    public void guardarDatos(double altura,double rad){
       
    }
    
    do{
    System.out.println("POR FAVOR DIGITE LA ALTURA--->");
    h=capturar.nextlnt();
    System.out.println("POR FAVOR DIGITE EL RADIO---> ");
    rad=capturar.nextlnt();
}while(h<=0 && rad<=0);
    
    public double mostrarVolumen(){
        return objeto1.calcularVolumen();
    }

}//MAIN

