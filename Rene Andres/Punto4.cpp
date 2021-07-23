// Your C++ Program

#include <iostream>

using namespace std;

int obtenerCubo(int n){
    int num=0, numeros=-1;
    bool fin=true;
    
    
    
    
    /*    
    for(int i=-1;i<n;i+=2){
        numeros=0;
        cout<<"."<<endl;
        for(int j=-1;j<i;j+=2){
            numeros+=numeros+2;
        }
    }
    cout<<numeros<<endl;



    for (int i = 1; i <= n; i++)
    {
        if((i%2)!=0){
            cout<<i<<endl;
            for(int j=1;j<=i;j++){
                if(j==i){
                    num++;
                }
            }
        }
        if(num==n){
            return num;
        }
    }
    */
    return numeros;
}

int main(){

    srand(3);
    
    obtenerCubo(5);
    
    /*for(int i = 0; i<10; i++){
        int n=rand() % 10 + 1; // Aleatorio en el intervalo [1,10]   
        //cout<<"El cubo de "<<n<<" es: "<<obtenerCubo(n)<<endl;
    }*/
    //cout << "Hello World!";
    return 0;
}
