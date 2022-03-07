
package conversion;


public class Conversion {
    private int Decimetros;
    private int Cantidad;
    private int Centimetros;
    private int Metros;
    private int Milimetros;
    
    public Conversion(){
        
    }
    public Conversion(int decimetros, int cantidad, int centimetros, int metros, int milimetros){
        this.Decimetros=decimetros;
        this.Cantidad=cantidad;
        this.Centimetros=centimetros;
        this.Metros=metros;
        this.Milimetros=milimetros;
    }
    public void setCantidad(int cantidad){
        this.Cantidad=cantidad;
    }
    
    public int getDecimetros(){
        return this.Decimetros;
    }
    
    public int getCentimetros(){
        return this.Centimetros;
    }
    
    public int getMetros(){
        return this.Metros;
    }
    
    public int getMilimetros(){
        return this.Milimetros;
    }
    
    public int getCantidad(){
        return this.Cantidad;
    }
    
    public void calcularConversion(){
        
    }
    
    public String toString(){
        return"";
    }
    
    
}//Clase Principal
