
package hipoteca;


public class CuotaMensual {
    
    private int years;
    private double capital;
    private double interes;
    private double mensualidad;
    private double n;
    
    public CuotaMensual(){
        
    }
    public CuotaMensual(int years, double capital, double interes, double mensualidad, double n){
        
        
    }
    public void setYears(int years){
        this.years=years;
    }
    public void setCapital(double capital){
        this.capital=capital;
    }
    public void setInteres(double interes){
        this.interes=interes;  
    }
    public double getCapital(){
        return capital;
    }
    public double getInteres(){
        return interes;
    }
    public int getYears(){
        return years;
    }
    public double getMensualidad(){
        return mensualidad;
    }
    public double calculoMensualidad(){
        
        return this.mensualidad;
    }
    public String toString(){
        return "HOLA, LA MENSUALIDAD ES --> "+this.mensualidad;
    }
    
}//MAIN
