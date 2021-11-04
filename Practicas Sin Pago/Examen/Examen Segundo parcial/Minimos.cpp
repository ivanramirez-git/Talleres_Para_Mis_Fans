#include <stdio.h>

void PideDatos(int *Dat, int *Ord, float Val[][102]);
float Potencia(int n, float Num);
void PreparaSistema(int Ord, int Dat, float Sist[][102], float Val[][102]);
void ResuelveGauss(int Dim, float Sist[][102]);
void EscribeDatos(int Dim, float Sist[][102]);


int main(void)
{
    int Datos,Orden,C;
   
    float Valores[2][102],Sistema[102][102];
    PideDatos(&Datos,&Orden,Valores);
    PreparaSistema(Orden,Datos,Sistema,Valores);
    printf("\n\n El sistema a resolver es el siguiente:");
    EscribeDatos(Orden,Sistema);
    ResuelveGauss(Orden,Sistema);
    printf("\n\n El sistema resuelto:");
    EscribeDatos(Orden,Sistema);
    printf("\n\n La Ecuacion del Polinomio ajustado por minimos Cuadrados\n\n:");
    for(C=1;C<=Orden;C++)
        printf(" + (%f)X^%d",Sistema[C][Orden+1],C-1);
    return(0);
}



void PideDatos(int *Dat, int *Ord,float Val[][102])
{
    int A,B;
   
    printf("\n\n\n METODO DE MINIMOS CUADRADOS.\n\n");
    printf("\n Introduce el numero de datos (Puntos): ");scanf("%d",&*Dat);
    printf("\n\n\n Introce los valores de cada punto\n");
   
    for(A=1;A<=*Dat;A++)
    {
        printf(" -Valores del Punto %d:\n",A);
        printf("   X%d: ",A); scanf("%f",&Val[0][A]);
        printf("   Y%d: ",A); scanf("%f",&Val[1][A]);
    }
    printf("\n\n\n Introduce el orden del polinomio: "); scanf("%d",&B);
    *Ord=B+1;
}


float Potencia(int n, float Num)
{
    int A;
    float res;
   
    res=1;
    for(A=1;A<=n;A++) res=res*Num;
    return res;
}



void PreparaSistema(int Ord, int Dat, float Sist[][102], float Val[][102])
{
    int A,B,C,Exp;
    float suma,termino;
   
    for(A=1;A<=Ord;A++)    for(B=1;B<=Ord;B++)
    {
        suma=0;
        Exp=A+B-2;
      
        for(C=1;C<=Dat;C++)
        {
            termino=Val[0][C];
            suma=suma+Potencia(Exp,termino);
        }
        Sist[A][B]=suma;
    }
    for(A=1;A<=Ord;A++)
    {
        suma=0;
        Exp=A-1;
      
        for(C=1;C<=Dat;C++)
        {
            termino=Val[0][C];
            suma=suma+Val[1][C]*Potencia(Exp,termino);
        }
        Sist[A][Ord+1]=suma;
    }
}


void ResuelveGauss(int Dim, float Sist[][102])
{
    int NoCero,Col,C1,C2,A;
    float Pivote,V1;
   
    for(Col=1;Col<=Dim;Col++){
        NoCero=0;A=Col;
        while(NoCero==0){
            if(Sist[A][Col]!=0){
                NoCero=1;}
            else A++;}
        Pivote=Sist[A][Col];
        for(C1=1;C1<=(Dim+1);C1++){
            V1=Sist[A][C1];
            Sist[A][C1]=Sist[Col][C1];
            Sist[Col][C1]=V1/Pivote;}
        for(C2=Col+1;C2<=Dim;C2++){
            V1=Sist[C2][Col];
            for(C1=Col;C1<=(Dim+1);C1++){
                Sist[C2][C1]=Sist[C2][C1]-V1*Sist[Col][C1];}
        }}
   
    for(Col=Dim;Col>=1;Col--) for(C1=(Col-1);C1>=1;C1--){
        Sist[C1][Dim+1]=Sist[C1][Dim+1]-Sist[C1][Col]*Sist[Col][Dim+1];
        Sist[C1][Col]=0;
    }
}

void EscribeDatos(int Dim, float Sist[][102])
{
    int A,B;
    printf("\n\n");
    for(A=1;A<=Dim;A++){
        for(B=1;B<=(Dim+1);B++){
            printf("%7.2f",Sist[A][B]);
            if(B==Dim) printf("   |");}
        printf("\n");
    }
    printf("\n\n");
}

