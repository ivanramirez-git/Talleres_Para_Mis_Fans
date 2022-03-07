
package volumen;


public class VolumenCilindro {
        private double h;
    private double pi=3.14159265;
    private double radio;
    double volumen;
   
    public VolumenCilindro(){

    }
    public VolumenCilindro(double h, double radio, double volumen, double pi){
        
    }
    
    public void setH(double h){
        this.h=h;
        
    }
    public double getH(double h){
        return h;
    }
    public double getRadio(){
        return radio;
    }
    public void setRadio(double radio){
        this.radio=radio;
    }
    public double calcularVolumen(){
        if (radio>0 && h>0){
        this.volumen=(pi*(radio*radio))*h;
        return this.volumen;
        
        }
        else{
            System.out.println("POR FAVOR INGRESE VALORES POSITIVOS");          
        }
    return this.volumen;
  
    }
   
        @Override
    public String toString(){
        return "HOLA, EL VOLUMEN DE TU CILINDRO ES ---> "+this.volumen;
    }
    
    
}//MAIN 
    

