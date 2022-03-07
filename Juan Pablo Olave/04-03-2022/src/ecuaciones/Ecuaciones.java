
package ecuaciones;


public class Ecuaciones {
    double a;
    double b;
    double w;
    double y;
    double z;
    
    public Ecuaciones(){
        
    }
    public Ecuaciones(double a, double b, double w,double y, double z){
       
}
    public void setA(double a){
        this.a=a;
        
    }
    public void setB(double b){
        this.b=b;
    }
    public double getA(){
        return a;
        
    }
    public double getB(){
        return b;
    }
    public double getW(){
        return w;
    }
    public double getY(){
        return y;
    }
    public double getZ(){
        return z;
    }
    public void calcularEcuaciones(){
        
    }
    public String toString(){
       return ("w -->"+this.w+"Y -->"+this.y+"Z -->"+this.z);
    }
    
    
}
