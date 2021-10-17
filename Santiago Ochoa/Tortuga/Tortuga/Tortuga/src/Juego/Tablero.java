/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Juego;
import java.util.Scanner;
/**
 *
 * @author HP
 */
public class Tablero {
    Scanner sc = new Scanner(System.in);
    private String Tablero [][];
    private String Instrucciones []; 
    private String Rastro ;
    int Tortuga [];
    

     public Tablero(){
     Tablero = new String [30][30];
        Instrucciones = new String[30];
        Tortuga = new int [4];
        inicializar();
    }    

    public void inicializar(){
       Rastro="  ";
       //iniciando tortuga
        for(int i=0; i<Tortuga.length; i++){
            if(i==1 || i==2)
                Tortuga[i]=1;
            else if(i==Tortuga.length-1)
                Tortuga[i]=3;
            else
                Tortuga[i]=0;   
        }
        // iniciando tablero
        for(int i=0; i<Tablero.length; i++){
            for(int j=0; j<Tablero[i].length; j++){
                if(i==0 || j==0 || i==Tablero[i].length-1 || j==Tablero.length-1)
                    Tablero[i][j] = " ";
                else
                    Tablero[i][j] ="  ";
            }
        }
        //iniciar puntero
        puntero();
        
        //imprimir
        llenarInstrucciones();
   }
   
   public void llenarInstrucciones(){
        System.out.print(imprimir());
        System.out.println("\n*************************************************************\n"
                           + "*         Ingrese las instrucciones para la tortuga         *\n"
                           + "*************************************************************\n"
                           + "*   a= Girar a la derecha: se girara a la derecha un n°    *\n"
                           + "*   b= Girar a la izquierda: se girara a la izquierda un n°*\n"
                           + "*   c= Avanzar se avanzara en la dirección de la tortuga   *\n"
                           + "*   d= Subir Lapiz: no marcara al moverse por el tablero   *\n"
                           + "*   e= Bajar Lapiz: marcara al moverse por el tablero      *\n"
                           + "*   f= Borrador: quitara las marcas posteriores            *\n"
                           + "*   g= Limpiar Tablero: regresara a los valores iniciales  *\n"
                           + "*   h= Ejecutar: se realizaran los comandos escritos       *\n"
                           + "*************************************************************\n");
        for(int i=0; i<Instrucciones.length; i++){
            //System.out.print(imprimir());
            System.out.println("Ingrese instrucción: "+(i+1));
            Instrucciones[i]= sc.next();
            analizarInstrucciones(i);
            if(Instrucciones[i].equalsIgnoreCase("h"))
                break;
        }
   }
   
   public void analizarInstrucciones(int i){
            if(Instrucciones[i].equalsIgnoreCase("a"))
                girarDerecha();
            if(Instrucciones[i].equalsIgnoreCase("b"))
                girarIzquierda();
            if(Instrucciones[i].equalsIgnoreCase("c"))
                avanzar();
            if(Instrucciones[i].equalsIgnoreCase("d")){
                Tortuga[0]=1;
                puntero();
            }
            if(Instrucciones[i].equalsIgnoreCase("e")){
                Tortuga[0]=1;
                puntero();
            }
            if(Instrucciones[i].equalsIgnoreCase("f")){
                Tortuga[0]=-1;
                puntero();
            }
            if(Instrucciones[i].equalsIgnoreCase("g"))
                inicializar();
            if(i==Instrucciones.length-1 || Instrucciones[i].equalsIgnoreCase("h"))
                System.out.println(imprimir());
   }
   
   public void girarDerecha(){
       System.out.println("¿Desea girar 45° ó 90°");
       sc.nextLine();
       int grados= sc.nextInt();
       if(grados == 45){
           switch(Tortuga[3]){
               case 2 : Tortuga[3]=3;break;
               case 3 : Tortuga[3]=4;break;
               case 4 : Tortuga[3]=6;break;
               case 6 : Tortuga[3]=8;break;
               case 8 : Tortuga[3]=9;break;
               case 9 : Tortuga[3]=10;break;
               case 10 :Tortuga[3]=12;break;
               case 12 :Tortuga[3]=2;break;
           }
       }
       if(grados == 90){
           switch(Tortuga[3]){
               case 2 : Tortuga[3]=4;break;
               case 3 : Tortuga[3]=6;break;
               case 4 : Tortuga[3]=8;break;
               case 6 : Tortuga[3]=9;break;
               case 8 : Tortuga[3]=10;break;
               case 9 : Tortuga[3]=12;break;
               case 10 :Tortuga[3]=2;break;
               case 12 :Tortuga[3]=3;break;
           }
       }
   }
   
   public void girarIzquierda(){
       System.out.println("¿Desea girar 45° ó 90°");
       int grados= sc.nextInt();
       if(grados==45){
           switch(Tortuga[3]){
               case 2 : Tortuga[3]=12;break;
               case 3 : Tortuga[3]=2;break;
               case 4 : Tortuga[3]=3;break;
               case 6 : Tortuga[3]=4;break;
               case 8 : Tortuga[3]=6;break;
               case 9 : Tortuga[3]=8;break;
               case 10 :Tortuga[3]=9;break;
               case 12 :Tortuga[3]=10;break;
           }
       }
       if(grados==90){
           switch(Tortuga[3]){
               case 2 : Tortuga[3]=10;break;
               case 3 : Tortuga[3]=12;break;
               case 4 : Tortuga[3]=2;break;
               case 6 : Tortuga[3]=3;break;
               case 8 : Tortuga[3]=4;break;
               case 9 : Tortuga[3]=6;break;
               case 10 :Tortuga[3]=8;break;
               case 12 :Tortuga[3]=9;break;
           }
       }
   }
   
   public void avanzar(){
       System.out.println("¿Cuantos espacios desea avanzar?");
       int espacios = sc.nextInt();
       String posicionDePartida=Rastro;
       String camino="  ";
       
       if(Tortuga[0] == 1){
            posicionDePartida="::";
            camino="::";
       }else if(Tortuga[0] == -1){
            posicionDePartida="  ";
       }
           int celdaTortuga=0;
           int limite=0;
           int limiteDos=0;
           int comenzar=0;
           int comenzarDos=0;
           int contador=0;
           int contadorDos=0;
           
           switch(Tortuga[3]){
               case 2 : limite=1; limiteDos=30; contador=-1; contadorDos=1; break;
               case 3 : celdaTortuga=2; limite=30; comenzar=1; contador=1;break;
               case 4 : limite=30; limiteDos=30; contador=1; contadorDos=1;break;
               case 6 : celdaTortuga=1; limite=30; comenzar=1; contador=1;break;
               case 8 : limite=30; limiteDos=1; contador=1; contadorDos=-1;break;
               case 9 : celdaTortuga=2; limite=1; comenzar=30; contador=-1;break;
               case 10 : limite=1; limiteDos=1; contador=-1; contadorDos=-1;break;
               case 12 : celdaTortuga=1; limite=1; comenzar=30; contador=-1;break;
           }
           
               for(int j=0; j<=espacios; j++){
                   if(j==0 && Tortuga[0]==0){
                       puntero();
                       posicionDePartida=Rastro;
                   }
                   else if(Tortuga[0]==1){
                           Tablero[Tortuga[1]][Tortuga[2]]=camino;
                   }else if(Tortuga[0]==-1){
                           Tablero[Tortuga[1]][Tortuga[2]]=camino;
                   }
                   if(j==0){
                       Tablero[Tortuga[1]][Tortuga[2]]=posicionDePartida;
                   }else{
                       if(Tortuga[3]==3 || Tortuga[3]==6 || Tortuga[3]==9 || Tortuga[3]==12){
                            if(Tortuga[celdaTortuga]==limite){
                                espacios=espacios-j;
                                j=0;
                                Tortuga[celdaTortuga]=comenzar;
                            }else{
                                Tortuga[celdaTortuga]+=contador;
                                if(j==espacios && Tortuga[0]==0 && Tablero[Tortuga[1]][Tortuga[2]].equalsIgnoreCase("::"))
                                    puntero();
                            }
                       }
                       else if(Tortuga[3]==2 || Tortuga[3]==4 || Tortuga[3]==8 || Tortuga[3]==10){
                            if(Tortuga[1]==limite || Tortuga[2]==limiteDos){
                                espacios=espacios-j;
                                j=0;
                                switch(Tortuga[3]){
                                    case 2 : comenzar=Tortuga[2]; comenzarDos=Tortuga[1]; break;
                                    case 4 : 
                                        if(Tortuga[1]==30){
                                            comenzarDos=1;
                                            comenzar=Tortuga[1]-Tortuga[2]+1;
                                        }
                                        if(Tortuga[2]==30){
                                            comenzar=1;
                                            comenzarDos=Tortuga[2]-Tortuga[1]+1;
                                        } 
                                        break;
                                    case 8 : comenzar=Tortuga[2]; comenzarDos=Tortuga[1]; break;
                                    case 10 :
                                        if(Tortuga[1]==1){
                                            comenzarDos=30;
                                            comenzar=30-(Tortuga[2]-Tortuga[1]);
                                        }
                                        if(Tortuga[2]==1){
                                            comenzar=30;
                                            comenzarDos=30-(Tortuga[1]-Tortuga[2]);
                                        } 
                                        break;
                                }
                                Tortuga[1]=comenzar;
                                Tortuga[2]=comenzarDos;
                            }else{
                                Tortuga[1]+=contador;
                                Tortuga[2]+=contadorDos;
                            }
                       }
                   }
               } 
   }
   
   public void puntero(){
    if(Tortuga[0] == 0){
        if(Tablero[Tortuga[1]][Tortuga[2]].equalsIgnoreCase("::")){
            Rastro=Tablero[Tortuga[1]][Tortuga[2]];
        }else if(Tablero[Tortuga[1]][Tortuga[2]].equalsIgnoreCase("  ")){
            Rastro="  ";
        }
        switch(Tortuga[3]){
               case 2 : Tablero[Tortuga[1]][Tortuga[2]]="↗ ";break;
               case 3 : Tablero[Tortuga[1]][Tortuga[2]]="→ ";break;
               case 4 : Tablero[Tortuga[1]][Tortuga[2]]="↘ ";break;
               case 6 : Tablero[Tortuga[1]][Tortuga[2]]="↓ ";break;
               case 8 : Tablero[Tortuga[1]][Tortuga[2]]="↙ ";break;
               case 9 : Tablero[Tortuga[1]][Tortuga[2]]="← ";break;
               case 10 :Tablero[Tortuga[1]][Tortuga[2]]="↖ ";break;
               case 12 :Tablero[Tortuga[1]][Tortuga[2]]="↑ ";break;
           }
    }
    else if(Tortuga[0] == 1){
         switch(Tortuga[3]){
               case 2 : Tablero[Tortuga[1]][Tortuga[2]]="⇗ ";break;
               case 3 : Tablero[Tortuga[1]][Tortuga[2]]="⇒ ";break;
               case 4 : Tablero[Tortuga[1]][Tortuga[2]]="⇘ ";break;
               case 6 : Tablero[Tortuga[1]][Tortuga[2]]="⇓ ";break;
               case 8 : Tablero[Tortuga[1]][Tortuga[2]]="⇙ ";break;
               case 9 : Tablero[Tortuga[1]][Tortuga[2]]="⇐ ";break;
               case 10 :Tablero[Tortuga[1]][Tortuga[2]]="⇖ ";break;
               case 12 :Tablero[Tortuga[1]][Tortuga[2]]="⇑ ";break;
           }
    }
    else if(Tortuga[0] == -1){
         switch(Tortuga[3]){
               case 2 : Tablero[Tortuga[1]][Tortuga[2]]="◹ ";break;
               case 3 : Tablero[Tortuga[1]][Tortuga[2]]="▷ ";break;
               case 4 : Tablero[Tortuga[1]][Tortuga[2]]="◿ ";break;
               case 6 : Tablero[Tortuga[1]][Tortuga[2]]="▽ ";break;
               case 8 : Tablero[Tortuga[1]][Tortuga[2]]="◺ ";break;
               case 9 : Tablero[Tortuga[1]][Tortuga[2]]="◁ ";break;
               case 10 :Tablero[Tortuga[1]][Tortuga[2]]="◸ ";break;
               case 12 :Tablero[Tortuga[1]][Tortuga[2]]="△ ";break;
           }
    }
   }
   
   public String imprimir(){
       puntero();
       String salida="\n***************************************************************\n"
                     + "*                    Juego de la tortuga                      *\n"
                     + "***************************************************************\n";
       //concatenar tablero
       for(int i=0; i<Tablero.length; i++){
            for(int j=0; j<Tablero[i].length; j++){
                salida += Tablero[i][j];
            }
        salida += "\n";
       }    
       //concatenar tortuga
       salida +="\n**************************\n"
                + "*   Valores de tortuga   *\n"
                + "**************************\n";
       for(int i=0; i<Tortuga.length; i++)
           salida += Tortuga[i] + "\t";
       salida += "\n";
       return salida;
   }

    public String[][] getTablero() {
        return Tablero;
    }

    public void setTablero(String[][] Tablero) {
        this.Tablero = Tablero;
    }

    public String[] getInstrucciones() {
        return Instrucciones;
    }

    public void setInstrucciones(String[] Instrucciones) {
        this.Instrucciones = Instrucciones;
    }

    public String getRastro() {
        return Rastro;
    }

    public void setRastro(String Rastro) {
        this.Rastro = Rastro;
    }

    public int[] getTortuga() {
        return Tortuga;
    }

    public void setTortuga(int[] Tortuga) {
        this.Tortuga = Tortuga;
    }
}
     
 
               
   
