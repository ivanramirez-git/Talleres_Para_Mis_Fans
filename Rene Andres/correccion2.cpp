#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int opcion;
    do{
    cout<<"*********************************"<<endl;
    cout<<"Prueba 2"<<endl;
    cout<<"Elija el ejercicio que desea resolver"<<endl;
    cout<<"1. Imprimir todos los pares (x,f(x)) tales que x es entero y se encuentra entre -10 y 10"<<endl;
    cout<<"2. Norma de un vector v con dimension 20"<<endl;
    cout<<"3. Aproximacion Pi"<<endl;
    cout<<"4. Cubos"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"*********************************"<<endl;
    cout<<endl;
    cin>>opcion;
        switch(opcion)
        {
            case 1:
                {
                    double den, num,f;
                    cout<<" ( x , f(x) )"<<endl;
                    cout<<" ----------- "<<endl;
                    for(int i=-10;i<=10;i++)
                    {
                      den=i+5;
                      num=i-2;
                      if(num==0)
                       cout<<" ( "<<i<<", No definido )"<<endl;
                      else{
                       f=den/num;
                       cout<<" ( "<<i<<" , "<<f<<" )"<<endl;
                      }
                    }
                }
            break;
            case 2:
                {
                double v;
                srand(3); //semilla
                double suma=0.0;
                cout<<"Vector de dimension 20 cuyas componentes son numeros aletarios entre 5 y 18:"<<endl;
                cout<<"v =( ";
                for(unsigned int i=1;i<=20;i++)
                {
                    v = 5 + rand()%((18+1)-5); //numeros aleatorios entre 5 y 18
                    cout<<v<<" ";
                    suma =  suma +pow(v,2); // v1^2+v2^2+...+v2^2
                }
                cout<<")"<<endl;
                cout<<"||v|| = "<<sqrt(suma)<<endl; //norma de v

                }
            break;
            case 3:
                {
                    cout<<"Formula de Ramanujan para aproximar pi"<<endl;
                    double pi, suma,fac_n,fac_2n,fac_3n;
                    cout<<" N   | Aprox PI   "<<endl;
                    cout<<"---------------"<<endl;
                    for(int N=3;N<=15;N++)
                    {
                        suma=0.0;
                        for(int n=0;n<=N;n++)
                        {
                            fac_2n = 1;
                            fac_3n=1;
                            fac_n=1;
                            for(int i=1;i<=2*n;i++)
                            {
                                fac_2n=fac_2n*i;//Calculo de 2n!
                            }
                            for(int i=1;i<=3*n;i++)
                            {
                                fac_3n=fac_3n*i;//Calculo de 3n!
                            }
                            for(int i=1;i<=n;i++)
                            {
                                fac_n=fac_n*i;//Calculo de n!
                            }
                           suma += fac_2n*fac_3n*(15*n+2)/(pow(fac_n,5)*pow(1458,n));

                            }
                        pi=27/(4*suma);//aproximacion de pi
                        cout<<N<<"\t"<<pi<<endl;
                    }
                }
            break;
            case 4:
                {
                    int n= 1+rand()%(10+1-1);//numero aleatorio entre 1 y 10
                    cout<<"Los "<<n<<" primeros cubos son:"<<endl;
                    int k=0;//Auxliar para encontrar primos
                    for(unsigned int i=1;i<=n;i++)// n primeros cubos
                    {
                        int suma =0;
                        for(unsigned int j =1;j<=i;j++)//Propiedad
                        {
                            suma += 2*k+1;
                            k++;
                        }
                        cout<<"Cubo "<<i<<"\t"<<suma<<endl;//suma de los i cubos
                    }

                }
                break;
            case 0: cout<<"Fin del programa"<<endl;
            break;
            default: cout<<"No ha seleccionado una opcion correcta"<<endl;
        }
    }
    while(opcion!=0);
    return 0;
}
