// Your C++ Program

#include <iostream>

using namespace std;

void fdex(float x){
    float numerador=(x+5);
    float denominador=(x-2);

    if(denominador!=0){
        cout<<"( "<<x<<" , "<<numerador/denominador<<" )"<<endl;
    }else{
        cout<<"No se puede dividir por cero."<<endl;
    }
}

int main(){

    for(float i = -10.0; i<=10; i++){
        fdex(i);
    }
    
    //cout << "Hello World!";
    return 0;
}
