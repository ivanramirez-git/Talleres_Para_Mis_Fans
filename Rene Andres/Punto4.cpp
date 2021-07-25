// Your C++ Program

#include <iostream>

using namespace std;

int obtenerCubo(int n){
    int num=0, numeros=-1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            
            numeros+=2;
            if(i==n){
                num=num+numeros;
            }
        }
    }
        return num;
}

int main(){

    srand(3);
    
    //obtenerCubo(5);
    int n=rand() % 10 + 1; // Aleatorio en el intervalo [1,10]   
    
    for(int i = 1; i<=n; i++){
        cout<<"El cubo de "<<n<<" es: "<<obtenerCubo(i)<<endl;
    }
    //cout << "Hello World!";
    return 0;
}
