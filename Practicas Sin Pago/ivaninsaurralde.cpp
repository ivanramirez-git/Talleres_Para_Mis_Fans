#include <iostream>

using namespace std;

int main(){
    
    //Generar un vector P de 5 elementos enteros
    //Generar un vector Q de 5 elementos
    //Generar un vector R de 5 elementos

    int P[5]={9,0,-5,12,-1};
    int Q[5];
    int Qordenado[5];
    int R[5];
    int temporal;

    // Buscar elemento mayor en P y guardarlo en Q[0], dividido 2
    Q[0]=P[0];
    for(int i=1;i<5;i++){
        if(Q[0]<P[i]){
            Q[0]=P[i];
        }
    }
    Q[0]=Q[0]/2;
    
    // Buscar elemento menor en P y guardarlo en Q[1]
    Q[1]=P[0];
    for(int i=1;i<5;i++){
        if(Q[1]>P[i]){
            Q[1]=P[i];
        }
    }

    // Q[2] = 16
    Q[2]=16;

    // Q[3] = promedio de P
    for(int i=0;i<5;i++){
        Q[3]=Q[3]+P[i];
    }
    Q[3]=Q[3]/5;

    // Q[4] = suma del mayor y el menor de P	
    Q[4]=Q[0]+Q[1];

    // Copiar Qordenado de Q
    for(int i=0;i<5;i++){
        Qordenado[i]=Q[i];
    }

    // Ordenar Qordenado de menor a mayor
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(Qordenado[i]<Qordenado[j]){
                temporal=Qordenado[i];
                Qordenado[i]=Qordenado[j];
                Qordenado[j]=temporal;
            }
        }
    }       

    // Copiar P+Qordenado ordenado en R
    for(int i=0;i<5;i++){
        R[i]=P[i]+Qordenado[i];
    }    
    
    // Imprimir P, Q, Q ordenado, R, de forma vertical separado con tabuladores
    cout << "|----\t lectura en proceso \t----|" << endl;
    cout << "P\tQ\tQ ordenado\tR" << endl;
    cout << "____________________________________" << endl;
    for(int i=0;i<5;i++){
        cout << P[i] << "\t" << Q[i] << "\t\t" << Qordenado[i] << "\t" << R[i] << endl;
    }

    // Imprimir informe P, Q ord. y R de forma vertical separado con tabuladores
    cout << "|----\t Informe \t----|" << endl;
    cout << "P\tQ ord.\tR" << endl;
    cout << "____________________" << endl;
    for(int i=0;i<5;i++){
        cout << P[i] << "\t" << Qordenado[i] << "\t" << R[i] << endl;
    }

    /*
    Pseudocodigo:
        1. Generar un vector P de 5 elementos enteros
        2. Generar un vector Q de 5 elementos
        3. Generar un vector R de 5 elementos
        4. Buscar elemento mayor en P y guardarlo en Q[1], dividido 2
        5. Buscar elemento menor en P y guardarlo en Q[2]
        6. Q[3] = 16
        7. Q[4] = promedio de P
        8. Q[5] = suma del mayor y el menor de P
        9. Copiar Qordenado de Q
        10. Ordenar Qordenado de menor a mayor
        11. Copiar P+Qordenado ordenado en R
        12. Imprimir P, Q, Q ordenado, R, de forma vertical separado con tabuladores
        13. Imprimir informe P, Q ord. y R de forma vertical separado con tabuladores

    Pseudocodigo formato PSeInt:
    
    Algoritmo punto1
        Dimension P[5]
        Dimension Q[5]
        Dimension R[5]
        Dimension Qordenado[5]

        P[1]<-9
        P[2]<-0
        P[3]<--5
        P[4]<-12
        P[5]<-1

        i<- 1
        mientras i<=5
            si Q[1]<P[i]
                Q[1]<-P[i]
            fin si
            i<-i+1
        fin mientras

        Q[1]<-Q[1]/2

        i<- 1
        mientras i<=5
            si Q[2]>P[i]
                Q[2]<-P[i]
            fin si
            i<-i+1
        fin mientras

        Q[3]<-16

        i<- 1
        mientras i<=5
            Q[4]<-Q[4]+P[i]
            i<-i+1
        fin mientras

        Q[4]<-Q[4]/5

        Q[5]<-Q[1]+Q[2]

        i<- 1
        mientras i<=5
            Qordenado[i]<-Q[i]
            i<-i+1
        fin mientras
        
        i<- 1
        mientras i<=5
            j<- 1
            mientras j<=5
                si Qordenado[i]<Qordenado[j]
                    temporal<-Qordenado[i]
                    Qordenado[i]<-Qordenado[j]
                    Qordenado[j]<-temporal
                fin si
                j<-j+1
            fin mientras
            i<-i+1
        fin mientras

        i<- 1
        mientras i<=5
            R[i]<-P[i]+Qordenado[i]
            i<-i+1
        fin mientras

        
        Escribir "Lectura en proceso"
        Escribir "P     Q       Qordenado       R"
        Escribir "_______________________________"

        i <- 1
        Mientras i <= 5
            Escribir P[i]  "     "  Q[i]  "     "  Qordenado[i]  "     "  R[i]
            i <- i + 1
        Fin Mientras

        Escribir ""

        Escribir "Informe"
        Escribir "P     Q ordenado       R"
        Escribir "____________________________"

        i <- 1
        Mientras i <= 5
            Escribir P[i]  "     "  Qordenado[i]  "     "  R[i]
            i <- i + 1
        Fin Mientras

    FinAlgoritmo

    */

    return 0;
}