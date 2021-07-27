// Your C++ Program

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <math.h>

using namespace std;

double normaVector(int v[]){

    double num=0;
    for(int i=0; i<20;i++){
        num=num + pow(v[i],2);
    }
    return sqrt(num);
}


int main(){

    int v[20];
    double norma;
    srand(3);


    for(int i = 0; i<20; i++){
    	v[i]=rand() % 13 + 5; // Aleatorio en el intervalo [5,18]
    }

    norma = normaVector(v)+0.0;

    cout<<"v = (";
    for(int i = 0; i<20; i++){
    	cout<<" "<<v[i];	
    }
    cout<<" )"<<endl;

    cout<<"La norma del vector es: "<< norma <<endl;

    //cout << "Hello World!";
    return 0;
}
